/*
 * $Id: z_sram.c,v 1.1.1.1 2003/03/10 22:42:45 tong Exp $
 *
 *	£Ó£Ò£Á£Í¤Ë¤Ä¤¤¤Æ
 *
 * $Log: z_sram.c,v $
 * Revision 1.1.1.1  2003/03/10 22:42:45  tong
 * new OBJ tree for ocarina from Nintendo
 *
 * Revision 2.7  1999/01/07  04:28:35  soejima
 * £Ç£Á£Ô£Å£×£Á£Ù»ÅÍÍ
 *
 * Revision 2.6  1998-11-09 14:06:24+09  soejima
 * *** empty log message ***
 *
 * Revision 2.5  1998-11-02 17:59:48+09  soejima
 * *** empty log message ***
 *
 * Revision 2.4  1998-10-28 18:36:32+09  soejima
 * £Ð£Á£Ì»ÅÍÍ
 *
 * Revision 2.3  1998-10-28 16:04:03+09  soejima
 * *** empty log message ***
 *
 * Revision 2.2  1998-10-23 19:27:57+09  soejima
 * ¥¬¥Î¥óÀï¸å¡¢£Â¥Ü¥¿¥ó¤Ë¡Ø¥Þ¥¹¥¿¡¼¥½¡¼¥É¡Ù¤òÌµ¾ò·ï¥»¥Ã¥È
 *
 * Revision 2.1  1998-10-22 20:51:48+09  zelda
 * £Ò£Ï£Í½Ð¤·¥Ð¡¼¥¸¥ç¥ó(NTSC)
 *
 * Revision 1.138  1998/10/15 10:55:25  soejima
 * *** empty log message ***
 *
 * Revision 1.137  1998-10-15 14:04:26+09  soejima
 * *** empty log message ***
 *
 * Revision 1.136  1998-10-13 21:04:07+09  soejima
 * *** empty log message ***
 *
 * Revision 1.135  1998-10-09 23:01:45+09  soejima
 * *** empty log message ***
 *
 * Revision 1.1  1998/01/12  10:42:56  soejima
 * Initial revision
 * $LogÄÉ²Ã
 *
 */

/************************************************************************
 *
 *	£Ó£Ò£Á£Í¤Ë¤Ä¤¤¤Æ
 *
 ************************************************************************/
#include "os.h"
#include "os_internal.h"
#include "z_basic.h"
#include "sleep.h"             /* sleep */
#if 0
#include "z_play.h"
#include "assert64.h"		/* assert */

#include "z_common_data.h"	/* z_common_data_t */
#include "z_scene_table.h"
#endif
#include "z_parameter_h.h"
#include "z_kaleido_moji.h"
#include "z_file_choose.h"
#include "z_sram_h.h"
#include "sys_leoemu.h"		/* osEPiStartDma(Emu) */
#include "z_scene_table.h"

#define  USE_OTSUKI

#ifdef USE_OTSUKI
/*nclude "ssSRAMrdwt.c"*/
#include "ssSRAMrdwt.h"
#endif
#define BBPLAYER
#ifdef BBPLAYER
#undef ssSRAMRead
#undef ssSRAMWrite
#define ssSRAMRead(p,s,sz)    __osBbSramRW(s,p,sz,DOMAIN_READ)
#define ssSRAMWrite(s,p,sz)   __osBbSramRW(s,p,sz,DOMAIN_WRITE)
void __osBbSramRW(void* sramAddr, void* dramAddr, size_t size, int dir) {
    extern u8* __osBbSramAddress;
    u8 *addr = __osBbSramAddress + (sramAddr - SRAM_START_ADDR);
    if (dir == OS_READ) {
	bcopy(addr, dramAddr, size);
    } else if (dir == OS_WRITE) {
	bcopy(dramAddr, addr, size);
    }
}
#endif


#ifndef USE_OTSUKI // OLD : 1998/3/20 otsuki.
/*************************************************************************
 * External device info
 */
#define DEVICE_TYPE_CART 0 /* ROM cartridge */
#define DEVICE_TYPE_BULK 1 /* ROM bulk */
#define DEVICE_TYPE_64DD 2 /* 64 Disk Drive */
#define DEVICE_TYPE_SRAM 3 /* SRAM */


/*************************************************************************
 * £Ó£Ò£Á£ÍÍÑ ³Æ¥Ñ¥é¥á¡¼¥¿¤ÎÄêµÁ ¡ÚSRAM¤ÏÍÆÎÌ256Kbits¡Û
 */
#define SRAM_START_ADDR  0x08000000 	/* ³«»Ï¥¢¥É¥ì¥¹ */
#define SRAM_SIZE        0x8000 	/* ÍÆÎÌ */
#define SRAM_latency     0x5 
#define SRAM_pulse       0x0c 
#define SRAM_pageSize    0xd 
#define SRAM_relDuration 0x2
#endif

unshort sram_save_address[] = {
    SRAM_Point00, SRAM_Point01, SRAM_Point02,
    SRAM_Point10, SRAM_Point11, SRAM_Point12,
};
static unchar sram_check_data[] = {
    0x00,			/* £Ó£Ï£Õ£Î£Ä */
    0x00,			/* £ÚÃíÌÜ¥¿¥¤¥× */
    0x00,			/* ¸À¸ì */
    0x98, 0x09, 0x10, 0x21,
    'Z', 'E', 'L', 'D', 'A',
};

#ifndef USE_OTSUKI // OLD : 1998/3/20 otsuki.
OSMesgQueue 	dmaMessageQ;
OSPiHandle 	SramHandle;
/************************************************************************
 *	SRAMÍÑ¤Î¥Ï¥ó¥É¥é¼èÆÀ´Ø¿ôosSramInit				*
 ************************************************************************/
OSPiHandle *
osSramInit( u32 sram_start_address )
{
    u32 saveMask;

    if ( SramHandle.baseAddress == (int)OS_PHYSICAL_TO_K1(sram_start_address) )
	return(&SramHandle);
    
    /* Fill basic information */
    SramHandle.type = DEVICE_TYPE_SRAM;
    SramHandle.baseAddress = (int)OS_PHYSICAL_TO_K1(sram_start_address);
    
    /* Get Domain parameters */
    SramHandle.latency = (u8)SRAM_latency;
    SramHandle.pulse = (u8)SRAM_pulse;
    SramHandle.pageSize = (u8)SRAM_pageSize;
    SramHandle.relDuration = (u8)SRAM_relDuration;
    SramHandle.domain = PI_DOMAIN2;
    
    /* TODO SramHandle.speed = */
    bzero( &(SramHandle.transferInfo), sizeof(SramHandle.transferInfo) );
    
    /*
     * Put the SramHandle onto PiTable
     */
    saveMask = __osDisableInt();
    SramHandle.next = __osPiTable;
    __osPiTable = &SramHandle;
    __osRestoreInt(saveMask);
    return(&SramHandle);
    
} /* osSramInit */
#endif










/************************************************************************
 *	¥×¥ì¥¤¥ä¡¼¸Ä¿Í¿§¡¹¾ðÊóÀßÄê					*
 ************************************************************************/
static void
save_initialize( void )
{
    static Privatef_t zelda_save_Privatef = {
	/*-------------------- private --------------------*/
        {0, 0, 0, 0, 0, 0},			/* newf[6] */
	0x0000,					/* savect */
	SSS, SSS, SSS, SSS, SSS, SSS, SSS, SSS,	/* player_name[8] */
	0,					/* f_64dd */
	LIFE_CT*3, LIFE_CT*3,			/* max_life, now_life */
	0, MAGIC_VALUE,				/* magic_max, magic_now */
	0x0000,					/* lupy_count */
	0,					/* long_sword_hp */
	0,					/* navi_timer */
	0,					/* magic_mode */
	0,					/* sword_ability */
	0,					/* magic_ability */
	0,					/* life_ability */
	0,					/* last_sword */
	0,					/* ocarina_round */
	/* »Ò¶¡»þÁõÈ÷ */
	0xff, 0xff, 0xff, 0xff,			/* child_register_item[4] */
	0xff, 0xff, 0xff,			/* child_register_item_pt[3] */
	0x0000,					/* child_equip_item */
	/* Âç¿Í»þÁõÈ÷ */
	0xff, 0xff, 0xff, 0xff,			/* adult_register_item[4] */
	0xff, 0xff, 0xff,			/* adult_register_item_pt[3] */
	0x0000,					/* adult_equip_item */

	/*  ¥ï¡¼¥×¥Ý¥¤¥ó¥È */
	{0.0f, 0.0f, 0.0f},			/* position */
	0,					/* angle_y */
	0,					/* scene */
	0,					/* room_ID */
	0,					/* flag */
	LINK_HOME,				/* scene_data_ID */
    };
    static Used_t zelda_save_Used = {
	/*-------------------- used --------------------*/
        {0xff, 0xff, 0xff, 0xff},			/* register_item[4] */
	0xff, 0xff, 0xff,			/* register_item_pt[3] */
	0x1100,					/* equip_item */
    };
    static Table_t zelda_save_Table = {
	/*-------------------- table --------------------*/
	/*---------- £É£Ô£Å£Í ----------*/
        {0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff},	/* item_register[6*4] */

	0,  0,  0,  0,  0,  0,			/* item_count[16] */
	0,  0,  0,  0,  0,  0,
	0,  0,  0,  0,

	/*---------- £Å£Ñ£Õ£É£Ð£Í£Å£Î£Ô ----------*/
	0x1100,					/* equip_register */

	0x00000000,				/* non_equip_register */

	/*---------- £Ã£Ï£Ì£Ì£Å£Ã£Ô ----------*/
	0x00000000,				/* collect_register */

	/*---------- £Í£Á£Ð ----------*/
	0, 0, 0, 0, 0,
	0, 0, 0, 0, 0,
	0, 0, 0, 0, 0,
	0, 0, 0, 0,
	            0,			/* key_compass_map[20] */

	-1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1,
	-1, -1, -1, -1,
	                 0,		/* key_register[20] */
    };
    static Save_t zelda_save_Save = {
	0x0000,					/* check_sum */
    };


    

    bzero(&z_common_data.memory, sizeof(z_common_data.memory));
    ZCommonSet( totalday, 0 );
    ZCommonSet( eventday, 0 );
    

    S_Private = zelda_save_Privatef;
    S_Used    = zelda_save_Used;
    S_Table   = zelda_save_Table;
    S_Save    = zelda_save_Save;

    /* ÇÏ¾ðÊó */
    H_Spot_No = SPOT00;
    H_Horse_X = -1840;
    H_Horse_Y = 72;
    H_Horse_Z = 5497;
    H_Horse_A = -27353;
    
    MAGIC_MAX = 0;

    HOLD_SWORD = 1;

    Room_Inf[MIZUSIN][Inf_Switch] = 0x40000000;
}

extern void
save_initialize999( void )
{
    static Privatef_t zelda_save_Privatef999 = {
	/*-------------------- private --------------------*/
        {REG0, REG1, REG2, REG3, REG4, REG5},	/* newf[6] */
	0x0000,					/* savect */
# if 0
	HDA, HII, HSI, HXE, HNN, HSI, HXE, HII,	/* name */
# else
	AAL, AAI, AAN, AAK, SSS, SSS, SSS, SSS,	/* player_name[8] */
# endif
	0,					/* f_64dd */
	LIFE_CT*14, LIFE_CT*14,			/* max_life, now_life */
	0, MAGIC_VALUE,				/* magic_max, magic_now */
	150,					/* lupy_count */
	8,					/* long_sword_hp */
	0,					/* navi_timer */
	1,					/* magic_mode */
	0,					/* sword_ability */
	0,					/* magic_ability */
	0,					/* life_ability */
	0,					/* last_sword */
	0,					/* ocarina_round */
	/* »Ò¶¡»þÁõÈ÷ */
	0xff, 0xff, 0xff, 0xff,			/* child_register_item[4] */
	0xff, 0xff, 0xff,			/* child_register_item_pt[3] */
	0x0000,					/* child_equip_item */
	/* Âç¿Í»þÁõÈ÷ */
	0xff, 0xff, 0xff, 0xff,			/* adult_register_item[4] */
	0xff, 0xff, 0xff,			/* adult_register_item_pt[3] */
	0x0000,					/* adult_equip_item */

	/*  ¥ï¡¼¥×¥Ý¥¤¥ó¥È */
	{0.0f, 0.0f, 0.0f},			/* position */
	0,					/* angle_y */
	0,					/* scene */
	0,					/* room_ID */
	0,					/* flag */
	SPOT00,					/* scene_data_ID */
    };
    static Used_t zelda_save_Used999 = {
	/*-------------------- used --------------------*/
        {H_sword_1, H_bow, H_bomb_1, H_ocarina_1},	/* register_item[4] */
	 3,  2, 7,				/* register_item_pt[3] */
	0x1122,					/* equip_item */
    };
    static Table_t zelda_save_Table999 = {
	/*-------------------- table --------------------*/
	/*---------- £É£Ô£Å£Í ----------*/
	/* item_register[6*4] */
        {H_stick,     H_deku_nut,   H_bomb_1,   H_bow,        H_arrow_1,    H_goddess_1,
	H_pachinko,  H_ocarina_1,  H_bomb_2,   H_S_hookshot, H_arrow_2,    H_goddess_2,
	H_boomerang, H_magicglass, H_bean,     H_hammer,     H_arrow_3,    H_goddess_3,
	H_bottle,    H_bottle_1,   H_bottle_2, H_bottle_3,   H_reserve_20, H_reserve_00},
	
	50,  50,  10,  30,  1,  1,		/* item_count[16] */
	30,   1,  50,   1,  1,  1, 
	 1,   1,   1,   1,
	
	/*---------- £Å£Ñ£Õ£É£Ð£Í£Å£Î£Ô ----------*/
	0x7777,					/* equip_register */
	
	0x00125249,				/* non_equip_register */
	
	/*---------- £Ã£Ï£Ì£Ì£Å£Ã£Ô ----------*/
	0x01e3ffff,				/* collect_register */

	/*---------- £Í£Á£Ð ----------*/
	7, 7, 7, 7, 7,
	7, 7, 7, 7, 7,
	0, 0, 0, 0, 0,
	0, 0, 0, 0,
	            0,			/* key_compass_map[20] */

	8, 8, 8, 8, 8,
	8, 8, 8, 8, 8,
	8, 8, 8, 8, 8,
	8, 8, 8, 8,
	            0,		/* key_register[20] */
    };
    static Save_t zelda_save_Save999 = {
	0x0000,					/* check_sum */
    };

/*    unshort	i, j, k; */

    bzero(&z_common_data.memory, sizeof(z_common_data.memory));
    ZCommonSet( totalday, 0 );
    ZCommonSet( eventday, 0 );
    S_Private = zelda_save_Privatef999;
    S_Used    = zelda_save_Used999;
    S_Table   = zelda_save_Table999;
    S_Save   = zelda_save_Save999;
    
    /* ÇÏ¾ðÊó */
    H_Spot_No = SPOT00;
    H_Horse_X = -1840;
    H_Horse_Y = 72;
    H_Horse_Z = 5497;
    H_Horse_A = -27353;
    
    Set_Inf_Table( 0, 0x5009 );		/* ¥µ¥ê¥¢ËÁÆ¬¥Ç¥â */
    Set_Event_Chk_Inf( 0, 0x123F );		/* ¥Ç¥¯¤Î¼ùÍÍËÁÆ¬¥Ç¥â */
    Set_Event_Chk_Inf( 8, 0x0001 );		/* ¥ª¥«¥ê¥ÊÅê¤²¥Ç¥â */
    Set_Event_Chk_Inf( 12, 0x0010 );		/* ¥·¡¼¥¯¢ª¥¼¥ë¥ÀÀµÂÎÌÀ¤«¤·¥Ç¥â */

    if ( ZCommon_LinkAgeIsChild() ) {
	/* »Ò¶¡ */
	Register_Item(0) = H_sword_0;
	SetEquip_Item( E_Sword, 1 );
	if ( z_common_data.file_no == 0xff ) {
	    Register_Item(1) = H_pachinko;
	    Register_Item_Pt(1) = 6;
	    /* S_Used.equip_item[0] = 0; */
	    SetEquip_Item( E_Shield, 1 );
	}
    }

    /* ¥ê¥ó¥¯£Ó£Ô£Á£Ò£Ô¾ì½ê¡Ú£Ì£É£Î£Ë¨¡£È£Ï£Í£Å¡Û */
    ZCommon_SceneNoSet( SPOT00_0 );
    
    MAGIC_MAX = 0;

    Room_Inf[MIZUSIN][Inf_Switch] = 0x40000000;
}



/************************************************************************
 *	£Ó£Ò£Á£Í £Ì£Ï£Á£Ä¡õ£Ã£È£Å£Ã£Ë¡Ê¥²¡¼¥à³«»Ï¡Ë			*
 ************************************************************************/
extern void
sram_load_check( Sram *sram )
{
#ifndef USE_OTSUKI // OLD : 1998/3/20 otsuki.
    OSIoMesg 	dmaIoMesgBuf;
    OSMesg 	dummyMesg;
#endif
    unshort	i, j;
    //unshort	*k, m, mmm;
    unchar	*nnn;

    static short scene_table[] = {
	YDAN_0,		/* ÍÅÀº¤ÎÌÚ¤Î¥À¥ó¥¸¥ç¥ó		*/
	DDAN_0,		/* ¥É¥É¥ó¥´¥À¥ó¥¸¥ç¥ó		*/
	BDAN_0,		/* µû¥À¥ó¥¸¥ç¥ó			*/
	MORI1_0,	/* ¿¹¤Î¿ÀÅÂ			*/
	HIDAN_0,	/* ±ê¤Î¿ÀÅÂ			*/
	MIZUSIN_0,	/* ¿å¤Î¿ÀÅÂ			*/
	JYASINZOU_0,	/* µðÂç¼Ù¿ÀÁü¥À¥ó¥¸¥ç¥ó         */
	HAKADAN_0,	/* Êè²¼¥À¥ó¥¸¥ç¥ó       	*/
	HAKADAN_CH_0,	/* Êè²¼¥À¥ó¥¸¥ç¥ó ¤³¤É¤â      	*/
	ICE_DOUKUTU_0,	/* É¹¤ÎÆ¶·¢                     */
	GANON_0,	/* ¥¬¥Î¥ó¤ÎÅã			*/
	MEN_0,		/* ÌÌ¥¯¥ê¥À¥ó¥¸¥ç¥ó		*/
	GERUDOWAY_0,	/* ¥²¥ë¥ÉÄÌÏ©			*/
	GANONTIKA_0,	/* ¥¬¥Î¥óÃÏ²¼		        */
	GANON_SONOGO_0,	/* ¥¬¥Î¥ó¤ÎÅã¤½¤Î¸å		*/
	GANONTIKA_SONOGO_0,/* ¥¬¥Î¥óÃÏ²¼¤½¤Î¸å		*/
    };
    
    
    
    PRINTF("¸Ä¿Í£Æ£é£ì£åºîÀ®\n");
    /* ¸Ä¿Í£Æ£é£ì£åºîÀ® */
# if 0
    PRINTF("SRAMÍÑ¤Î¥Ï¥ó¥É¥é¼èÆÀ\n");
    /* SRAMÍÑ¤Î¥Ï¥ó¥É¥é¼èÆÀ */
    osSramInit( (u32)SRAM_START_ADDR );
    
    bzero( sram->read_buff, SRAM_SIZE );
    osInvalDCache((void *)sram->read_buff, SRAM_SIZE );
    osCreateMesgQueue( &dmaMessageQ, &dummyMesg, 1 );
    dmaIoMesgBuf.hdr.pri = OS_MESG_PRI_NORMAL;
    dmaIoMesgBuf.hdr.retQueue = &dmaMessageQ;
    dmaIoMesgBuf.dramAddr = sram->read_buff;
    dmaIoMesgBuf.devAddr = (u32)SRAM_START_ADDR;
    dmaIoMesgBuf.size = SRAM_SIZE;
    osEPiStartDma( &SramHandle, &dmaIoMesgBuf, OS_READ );
    (void) osRecvMesg(&dmaMessageQ, &dummyMesg, OS_MESG_BLOCK);
# endif
    i = sram_save_address[z_common_data.file_no];
    PRINTF("¤Ý¤¤¤ó¤È¡á%x(%d)\n",i,z_common_data.file_no );
    Memcpy( &z_common_data.scene_no, sram->read_buff+i, SAVE_MAX );
# if 0	
	PRINTF("£Ó£Á£Ö£Å¥Á¥§¥Ã¥¯¥µ¥à·×»»\n");
	mmm = Check_Sum;
	Check_Sum = 0;
	k = (unshort *)&z_common_data.scene_no;
	for ( i = j = m = 0; i < (SAVE_MAX)/2; i++ ) {
	    j += *k++;
	}
	if ( !(j == mmm) ) {
	    PRINTF("\n ¥¨¥é¡¼¡ª¥¨¥é¡¼¡ª¥¨¥é¡¼¡ª  %x    %x\n",j, mmm ); 
	} else {
	    PRINTF("\n£Ó£Á£Ö£Å¥Ç¡¼¥¿ £Ï£Ë¡ª¡ª¡ª¡ª\n");
	}
	Check_Sum = j;
//    }
//# else
    i = sram_save_address[z_common_data.file_no];
    PRINTF("¤Ý¤¤¤ó¤È¡á%x(%d)\n",i,z_common_data.file_no );
    Memcpy( &z_common_data.scene_no, sram->read_buff+i, SAVE_MAX );
    
    PRINTF("£Ó£Á£Ö£Å¥Á¥§¥Ã¥¯¥µ¥à·×»»\n");
    mmm = Check_Sum;
    Check_Sum = 0;
    k = (unshort *)&z_common_data.scene_no;
    for ( i = j = m = 0; i < (SAVE_MAX)/2; i++ ) {
	PRINTF("%x ",*k);
	j += *k++;
	if ( (++m) == 0x20 ) {
	    PRINTF("\n");
	    m = 0;
	}
    }
    if ( j != mmm ) {
	PRINTF(" ¥¨¥é¡¼¡ª¥¨¥é¡¼¡ª¥¨¥é¡¼¡ª  %x  %x\n",j, Check_Sum ); 
    } else {
	PRINTF("£Ó£Á£Ö£Å¥Ç¡¼¥¿ £Ï£Ë¡ª¡ª¡ª¡ª\n");
	Check_Sum = j;
    }
# endif
    COLOR_YELLOW();
    PRINTF("SCENE_DATA_ID = %d   SceneNo = %d\n",SCENE_DATA_ID, ZCommon_SceneNoGet() );
    switch( SCENE_DATA_ID ) {
    case YDAN:		/* ÍÅÀº¤ÎÌÚ¤Î¥À¥ó¥¸¥ç¥ó		*/
    case DDAN:		/* ¥É¥É¥ó¥´¥À¥ó¥¸¥ç¥ó		*/
    case BDAN:		/* µû¥À¥ó¥¸¥ç¥ó			*/
    case MORI1:		/* ¿¹¤Î¿ÀÅÂ			*/
    case HIDAN:		/* ±ê¤Î¿ÀÅÂ			*/
    case MIZUSIN:	/* ¿å¤Î¿ÀÅÂ			*/
    case JYASINZOU:	/* µðÂç¼Ù¿ÀÁü¥À¥ó¥¸¥ç¥ó         */
    case HAKADAN:	/* Êè²¼¥À¥ó¥¸¥ç¥ó       	*/
    case HAKADAN_CH:	/* Êè²¼¥À¥ó¥¸¥ç¥ó ¤³¤É¤â      	*/
    case ICE_DOUKUTU:	/* É¹¤ÎÆ¶·¢                     */
    case GANON:		/* ¥¬¥Î¥ó¤ÎÅã			*/
    case MEN:		/* ÌÌ¥¯¥ê¥À¥ó¥¸¥ç¥ó		*/
    case GERUDOWAY:	/* ¥²¥ë¥ÉÄÌÏ©			*/
    case GANONTIKA:	/* ¥¬¥Î¥óÃÏ²¼		        */
////////	z_common_data.scene_no = scene_table[SCENE_DATA_ID];
	ZCommon_SceneNoSet( scene_table[SCENE_DATA_ID] );
	break;
	
    case YDAN_BOSS:
	ZCommon_SceneNoSet( YDAN_0 );
	break;
	
    case DDAN_BOSS:
	ZCommon_SceneNoSet( DDAN_0 );
	break;
	
    case BDAN_BOSS:
	ZCommon_SceneNoSet( BDAN_0 );
	break;
	
    case MORIBOSS:
	ZCommon_SceneNoSet( MORI1_0 );
	break;
	
    case FIRE_BOSS:
	ZCommon_SceneNoSet( HIDAN_0 );
	break;
	
    case MIZUSIN_BOSS:
	ZCommon_SceneNoSet( MIZUSIN_0 );
	break;
	
    case JYASINZOU_BOSS:
	ZCommon_SceneNoSet( JYASINZOU_0 );
	break;
	
    case HAKADAN_BOSS:
	ZCommon_SceneNoSet( HAKADAN_0 );
	break;
	
    case GANON_BOSS:
    case GANON_SONOGO:
    case GANON_FINAL:
    case GANONTIKA_SONOGO:
    case GANON_DEMO:
	ZCommon_SceneNoSet( GANON_0 );
	break;

    default:
	if ( SCENE_DATA_ID != LINK_HOME ) {
	    if ( ZCommon_LinkAgeIsChild() ) {
		/* »Ò¶¡ */
		ZCommon_SceneNoSet( LINK_HOME_0 );
	    } else {
		/* Âç¿Í */
		ZCommon_SceneNoSet( TOKINOMA_7 );
	    }
	} else {
	    /* ¿·µ¬¥Õ¥¡¥¤¥ë */
	    ZCommon_SceneNoSet( LINK_HOME_0 );
	}
	break;
    }
    PRINTF("scene_no = %d\n",ZCommon_SceneNoGet());
    COLOR_NORMAL();
    if ( S_Private.now_life < (LIFE_CT*3) ) S_Private.now_life = (LIFE_CT*3);

    if ( OCA_REC_FLAG ) {
	/* Ï¿²» */
	COLOR_BLUE();
	PRINTF("\n====================================================================\n");
	/* Ï¿²» */
	Memcpy( na_oca_rec_buf_ptr, &S_Information.oca_rec_buff, NA_OCA_REC_MEMORY_SIZE );
	nnn = na_oca_rec_buf_ptr;
	for ( i = 0; i < NA_OCA_REC_MEMORY_SIZE; i++,nnn++ ) {
	    PRINTF("%d, ",*nnn);
	}
	PRINTF("\n====================================================================\n");
	COLOR_NORMAL();
    }
    if ( OCA_REC_FLAG8 ) {
	/* Ï¿²» */
	COLOR_GREEN();
	PRINTF("\n====================================================================\n");
	/* Ï¿²» */
	Memcpy( na_oca_rec_buf2_ptr, &S_Information.oca_rec_buff8, NA_OCA_REC_MEMORY_SIZE2 );
	nnn = na_oca_rec_buf2_ptr;
	for ( i = 0; i < NA_OCA_REC_MEMORY_SIZE2; i++,nnn++ ) {
	    PRINTF("%d, ",*nnn);
	}
	PRINTF("\n====================================================================\n");
	COLOR_NORMAL();
    }
    /* ¤¼¥ë¥ÀÉ±¤Î¼ê»æ¤ò¤â¤Ã¤Æ¤¤¤ë¤¬¡¢¡Ø¤¼¥ë¥À¤Î»Ò¼é¤ê±´¡Ù¤ò¤Ê¤é¤Ã¤Æ¤¤¤Ê¤¤¾ì¹ç */
    if ( Get_Event_Chk_Inf( 4, 0x0001 ) ) {
	if ( !GetCollect_MELODY( H_melody_9 ) ) {
	    i = Event_Chk_Inf( 4 );
	    i &= 0xfffe;
	    Event_Chk_Inf( 4 ) = i;
	    S_Table.item_register[number_pt[H_reserve_02]] = H_reserve_01;
	    for ( j = 1; j < 4; j++ ) {
		if ( Register_Item(j) == H_reserve_02 ) {
		    Register_Item(j) = H_reserve_01;
		}
	    }
	}
    }
    /* Âç¿Í¤Ê¤Î¤Ë¡Ø¥Þ¥¹¥¿¡¼¥½¡¼¥É¡Ù¤ò»ý¤Ã¤Æ¤¤¤Ê¤¤¾ì¹ç */
    if ( ZCommon_LinkAgeIsAdult() ) {
	if ( !Equip_Sword_CK( H_sword_1 ) ) {
	    SetEquip_Register( E_Sword, check_bit[H_sword_1-H_sword_0] );
	    Register_Item(0) = H_sword_1;
	    Equip_Item &= 0xFFF0;
	    Equip_Item |= 0x0002;
	}
    }

    /* ¤ï¤é¤·¤Ù¥¢¥¤¥Æ¥à¥Á¥§¥Ã¥¯ */
    for ( i = 0; i < 3; i++ ) {
	if ( Get_Item_Register(H_reserve_20) == Warashibe_item[i] ) {
	    Item_Register_Set( Warashibe_before_item[i] );
	    for ( j = 1; j < 4; j++ ) {
		if ( Register_Item(j) == Warashibe_item[i] ) {
		    Register_Item(j) = Warashibe_before_item[i];
		}
	    }
	}
    }
    
    MAGIC_MAX = 0;

//# endif
}


/************************************************************************
 *	£Ó£Ò£Á£Í £Ó£Á£Ö£Å						*
 ************************************************************************/
extern void
sram_save( Sram *sram )
{
#ifndef USE_OTSUKI // OLD : 1998/3/20 otsuki.
    OSIoMesg 	dmaIoMesgBuf;
    OSMesg 	dummyMesg;
#endif

    unshort	i, j, m;
    unshort	*k;

    //sram;
    
# if 0
#ifndef USE_OTSUKI // OLD : 1998/3/20 otsuki.
    /* SRAMÍÑ¤Î¥Ï¥ó¥É¥é¼èÆÀ */
    osSramInit( (u32)SRAM_START_ADDR );
    
    bzero( sram->read_buff, SRAM_SIZE );
    osInvalDCache((void *)sram->read_buff, SRAM_SIZE );
    osCreateMesgQueue( &dmaMessageQ, &dummyMesg, 1 );
    dmaIoMesgBuf.hdr.pri = OS_MESG_PRI_NORMAL;
    dmaIoMesgBuf.hdr.retQueue = &dmaMessageQ;
    dmaIoMesgBuf.dramAddr = sram->read_buff;
    dmaIoMesgBuf.devAddr = (u32)SRAM_START_ADDR;
    dmaIoMesgBuf.size = SRAM_SIZE;
    osEPiStartDma( &SramHandle, &dmaIoMesgBuf, OS_READ );
    (void) osRecvMesg(&dmaMessageQ, &dummyMesg, OS_MESG_BLOCK);
#endif
#ifdef USE_OTSUKI  // NEW : 1998/3/20 otsuki.
    ssSRAMRead(sram->read_buff, (void *)SRAM_START_ADDR, SRAM_SIZE);
#endif
#endif
    Check_Sum = 0;
    k = (unshort *)&z_common_data.scene_no;
    /* ¥Á¥§¥Ã¥¯¥µ¥à·×»» */
    for ( i = j = m = 0; i < (SAVE_MAX)/2; i++ ) {
////////	PRINTF("%x ",*k);
       	if ( (++m) == 0x20 ) {
////////	    PRINTF("\n");
	    m = 0;
	}
	j += *k++;
    }
    Check_Sum = j;
////////    PRINTF("\n¥Á¥§¥Ã¥¯¥µ¥à¡á%x)\n", Check_Sum );
    k = (unshort *)&z_common_data.scene_no;
    /* ¥Á¥§¥Ã¥¯¥µ¥à·×»» */
    for ( i = j = 0; i < (SAVE_MAX)/2; i++ ) {
////////	PRINTF("%x ",*k);
       	if ( (++m) == 0x20 ) {
////////	    PRINTF("\n");
	    m = 0;
	}
	j += *k++;
    }
# if 0
    i = sram_save_address[z_common_data.file_no];
    PRINTF("I=%x no=%d\n",i, z_common_data.file_no);
    Memcpy( sram->read_buff+i, &z_common_data.scene_no, SAVE_MAX );
    i = sram_save_address[z_common_data.file_no+3];
    PRINTF("I=%x no=%d\n",i, z_common_data.file_no+3);
    Memcpy( sram->read_buff+i, &z_common_data.scene_no, SAVE_MAX );

#ifndef USE_OTSUKI // OLD : 1998/3/20 otsuki.
    osCreateMesgQueue( &dmaMessageQ, &dummyMesg, 1 );
    osInvalDCache((void *)sram->read_buff, SRAM_SIZE ); 
    dmaIoMesgBuf.hdr.pri = OS_MESG_PRI_NORMAL;
    dmaIoMesgBuf.hdr.retQueue = &dmaMessageQ;
    dmaIoMesgBuf.dramAddr = sram->read_buff;
    dmaIoMesgBuf.devAddr = (u32)SRAM_START_ADDR;
    dmaIoMesgBuf.size = SRAM_SIZE;
    osEPiStartDma( &SramHandle, &dmaIoMesgBuf, OS_WRITE );
    osRecvMesg( &dmaMessageQ, &dummyMesg, OS_MESG_BLOCK );
#endif
#ifdef USE_OTSUKI  // NEW : 1998/3/20 otsuki.
    ssSRAMWrite((void *)SRAM_START_ADDR, sram->read_buff, SRAM_SIZE);
#endif
#endif
    i = sram_save_address[z_common_data.file_no];
////////    PRINTF("\n°ì²óÌÜ i=%x (ÈÖ¹æ¡á%d)  ",i, z_common_data.file_no );
/*  ssSRAMWrite((void *)((int)SRAM_START_ADDR+i), &z_common_data.scene_no, SAVE_MAX);*/
    ssSRAMWrite((void *)((int)SRAM_START_ADDR+i), &z_common_data.scene_no, SAVE_SIZE);
////////    PRINTF("¥Á¥§¥Ã¥¯¥µ¥à¡á%x)\n", Check_Sum );
    k = (unshort *)&z_common_data.scene_no;
    /* ¥Á¥§¥Ã¥¯¥µ¥à·×»» */
    for ( i = j = 0; i < (SAVE_MAX)/2; i++ ) {
////////	PRINTF("%x ",*k);
	if ( (++m) == 0x20 ) {
////////	    PRINTF("\n");
	    m = 0;
	}
	j += *k++;
    }
    i = sram_save_address[z_common_data.file_no+3];
////////    PRINTF("£²²óÌÜ i=%x  ",i);
/*  ssSRAMWrite((void *)((int)SRAM_START_ADDR+i), &z_common_data.scene_no, SAVE_MAX);*/
    ssSRAMWrite((void *)((int)SRAM_START_ADDR+i), &z_common_data.scene_no, SAVE_SIZE);
////////    PRINTF("¥Á¥§¥Ã¥¯¥µ¥à¡á%x)\n", Check_Sum );
////////    PRINTF("£Ó£Á£Ö£Å½ªÎ»\n");


}
/************************************************************************
 *	£Ó£Ò£Á£Í £Ó£Ô£Á£Ò£Ô¨¡£Ì£Ï£Á£Ä					*
 ************************************************************************/
extern void
sram_start_load( Game_file_choose *this, Sram *sram )
{
#ifndef USE_OTSUKI // OLD : 1998/3/20 otsuki.
    OSIoMesg 	dmaIoMesgBuf;
    OSMesg 	dummyMesg;
#endif
    unshort	i, j, s, t, m, mmm;
    unshort	*k;
    unshort	keep_time;


    PRINTF("£Ó£Ò£Á£Í £Ó£Ô£Á£Ò£Ô¨¡£Ì£Ï£Á£Ä\n");
#ifndef USE_OTSUKI // OLD : 1998/3/20 otsuki.
    /* SRAMÍÑ¤Î¥Ï¥ó¥É¥é¼èÆÀ */
    osSramInit( (u32)SRAM_START_ADDR );

    bzero( sram->read_buff, SRAM_SIZE );
    osInvalDCache((void *)sram->read_buff, SRAM_SIZE );
    osCreateMesgQueue( &dmaMessageQ, &dummyMesg, 1 );
    dmaIoMesgBuf.hdr.pri = OS_MESG_PRI_NORMAL;
    dmaIoMesgBuf.hdr.retQueue = &dmaMessageQ;
    dmaIoMesgBuf.dramAddr = sram->read_buff;
    dmaIoMesgBuf.devAddr = (u32)SRAM_START_ADDR;
    dmaIoMesgBuf.size = SRAM_SIZE;
    osEPiStartDma( &SramHandle, &dmaIoMesgBuf, OS_READ );
    (void) osRecvMesg(&dmaMessageQ, &dummyMesg, OS_MESG_BLOCK);
#endif
#ifdef USE_OTSUKI  // NEW : 1998/3/20 otsuki.
    bzero( sram->read_buff, SRAM_SIZE );
    ssSRAMRead(sram->read_buff, (void *)SRAM_START_ADDR, SRAM_SIZE);
#endif
    keep_time = ZCommonGet(zelda_time);
    for ( s = 0; s < 3; s++ ) {
	t = sram_save_address[s];
	PRINTF("¤Ý¤¤¤ó¤È¡á%x(%d)    SAVE_MAX=%d\n",t,z_common_data.file_no, SAVE_MAX );
	Memcpy( &z_common_data.scene_no, sram->read_buff+t, SAVE_MAX );
	
	mmm = Check_Sum;
	Check_Sum = 0;
	k = (unshort *)&z_common_data.scene_no;
	PRINTF("\n¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á  £Ó¡Ê%d¡Ë ¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á\n",s);
	for ( i = j = m = 0; i < (SAVE_MAX)/2; i++, t+=2 ) {
////////#ifdef U_soejima_U
#if 0
	    if ( !m ) {
		PRINTF("¡Ú%04x¡Û¢ª ",t);
	    }
	    PRINTF("%04x ",*k);
	    if ( (m+=2) == 0x20 ) {
		PRINTF("\n");
		m = 0;
	    }
# endif
	    j += *k++;
	}
	PRINTF("\n£Ó£Á£Ö£Å¥Á¥§¥Ã¥¯¥µ¥à·×»»  j=%x  mmm=%x  ", j, mmm);
	if ( j != mmm ) {
	    PRINTF("£Å£Ò£Ò£Ï£Ò¡ª¡ª¡ª ¡á %x(%d)\n",sram_save_address[s],s );
	    t = sram_save_address[s+3];
	    Memcpy( &z_common_data.scene_no, sram->read_buff+t, SAVE_MAX );
	    
	    mmm = Check_Sum;
	    Check_Sum = 0;
	    k = (unshort *)&z_common_data.scene_no;
	    PRINTF("================= £Â£Á£Ã£Ë¨¡£Õ£Ð ========================\n");
	    for ( i = j = m = 0; i < (SAVE_MAX)/2; i++, t+=2 ) {
////////#ifdef U_soejima_U
#if 0
		if ( !m ) {
		    PRINTF("¡Ø%04x¡Ù¢ª ",t);
		}
		PRINTF("%04x ",*k);
		if ( (m+=2) == 0x20 ) {
		    PRINTF("\n");
		    m = 0;
		}
# endif
		j += *k++;
	    }
	    PRINTF("\n¡Ê£Â¡Ë£Ó£Á£Ö£Å¥Á¥§¥Ã¥¯¥µ¥à·×»»  j=%x  mmm=%x  ", j, mmm );
	    if ( j != mmm ) {
		PRINTF("£Å£Ò£Ò£Ï£Ò¡ª¡ª¡ª ¡á %x(%d+3)\n",sram_save_address[s+3],s );

		bzero( &z_common_data.scene_no, sizeof(int) );
		bzero( &z_common_data.link_age, sizeof(int) );
		bzero( &z_common_data.day_time, sizeof(int) );
		bzero( &z_common_data.zelda_time, sizeof(int) );
		bzero( &z_common_data.asahiru_fg, sizeof(int) );
		bzero( &z_common_data.totalday, sizeof(int) );
		bzero( &z_common_data.eventday, sizeof(int) );
#if !defined(ROM_F)
		if ( !s ) {
		    save_initialize999( );
		    /* ¥ê¥ó¥¯£Ó£Ô£Á£Ò£Ô¾ì½ê¡Ú£Ì£É£Î£Ë¨¡£È£Ï£Í£Å¡Û */
/////////		    ZCommon_SceneNoSet( SPOT00_0 );
		    /* ¥ê¥ó¥¯Ç¯Îð¡Ú»Ò¶¡¡Û */
/////////		    ZCommon_LinkAgeBeChild( );
		    /* ¥¼¥ë¥À»þ´ÖÀßÄê¡Ú£Á£Í£±£°¡§£°£°¡Û */
/////////		    ZCommonSet( zelda_time, 0x6aab );
/////////		    ZCommonSet( day_time, 0xFFF0 );
		    S_Private.newf[0] = REG0;
		    S_Private.newf[1] = REG1;
		    S_Private.newf[2] = REG2;
		    S_Private.newf[3] = REG3;
		    S_Private.newf[4] = REG4;
		    S_Private.newf[5] = REG5;	/* ÅÐÏ¿ */
		    PRINTF("newf=%x,%x,%x,%x,%x,%x\n",S_Private.newf[0],S_Private.newf[1],S_Private.newf[2],S_Private.newf[3],S_Private.newf[4],S_Private.newf[5]);
		} else {
		    save_initialize();
		}
# else
		save_initialize();
# endif
		k = (unshort *)&z_common_data.scene_no;
		/* ¥Á¥§¥Ã¥¯¥µ¥à·×»» */
		PRINTF("\n--------------------------------------------------------------\n");
		for ( i = j = m = 0; i < (SAVE_MAX)/2; i++ ) {
# if 1
		    PRINTF("%x ",*k);
		    if ( (++m) == 0x20 ) {
			PRINTF("\n");
			m = 0;
		    }
# endif
		    j += *k++;
		}
		Check_Sum = j;
		PRINTF("\nCheck_Sum=%x(%x)\n", Check_Sum, j); 
		i = sram_save_address[s+3];
/*		ssSRAMWrite((void *)((int)SRAM_START_ADDR+i), &z_common_data.scene_no, SAVE_MAX);*/
		ssSRAMWrite((void *)((int)SRAM_START_ADDR+i), &z_common_data.scene_no, SAVE_SIZE);
		PRINTF("??????=%x,%x,%x,%x,%x,%x\n",S_Private.newf[0],S_Private.newf[1],S_Private.newf[2],S_Private.newf[3],S_Private.newf[4],S_Private.newf[5]);
		PRINTF("\n¤Ý¤¤¤ó¤È¡á%x(%d+3)  check_sum=%x(%x)\n",i,s,Check_Sum,j );
	    }
	    i = sram_save_address[s];
/*	    ssSRAMWrite((void *)((int)SRAM_START_ADDR+i), &z_common_data.scene_no, SAVE_MAX);*/
	    ssSRAMWrite((void *)((int)SRAM_START_ADDR+i), &z_common_data.scene_no, SAVE_SIZE);
	    PRINTF("¤Ý¤¤¤ó¤È¡á%x(%d)  check_sum=%x(%x)\n",i,s,Check_Sum,j );
	} else {
	    PRINTF("\n£Ó£Á£Ö£Å¥Ç¡¼¥¿ £Ï£Ë¡ª¡ª¡ª¡ª\n");
	}
    }
    bzero( sram->read_buff, SRAM_SIZE );
    ssSRAMRead(sram->read_buff, (void *)SRAM_START_ADDR, SRAM_SIZE);
    ZCommonSet( zelda_time, keep_time );

# if 0
    for ( i = j = 0; i < 3; i++ ) {
	m = sram_save_address[i];
	PRINTF("\n============  SAVE_MAX=%x  PLAYER=%x  ================================================\n",SAVE_MAX,sizeof(Memory)/sizeof(unchar));
	if ( j ) {
	    PRINTF("[%04x]",m);
	    j = m & 0x1f;
	}
	for ( k = 0; k < SAVE_MAX; k++, m++ ) {
	    if ( !j ) PRINTF("[%04x]",m);
	    PRINTF("%x, ",sram->read_buff[m] );
	    if ( (++j) == 0x20 ) {
		j = 0;
		PRINTF("\n");
	    }
	}
    }
# endif
    PRINTF("SAVECT=%x, NAME=%x, LIFE=%x, ITEM=%x,  64DD=%x,  HEART=%x\n",SAVE_SAVECT,SAVE_NAME,SAVE_LIFE,SAVE_ITEM,SAVE_64DD,SAVE_HEART+19);
    Memcpy( &this->save[0], sram->read_buff+SRAM_Point00+SAVE_SAVECT, 2 );
    Memcpy( &this->save[1], sram->read_buff+SRAM_Point01+SAVE_SAVECT, 2 );
    Memcpy( &this->save[2], sram->read_buff+SRAM_Point02+SAVE_SAVECT, 2 );

    Memcpy( &this->name[0], sram->read_buff+SRAM_Point00+SAVE_NAME, 8 );
    Memcpy( &this->name[1], sram->read_buff+SRAM_Point01+SAVE_NAME, 8 );
    Memcpy( &this->name[2], sram->read_buff+SRAM_Point02+SAVE_NAME, 8 );

    Memcpy( &this->life[0], sram->read_buff+SRAM_Point00+SAVE_LIFE, 2 );
    Memcpy( &this->life[1], sram->read_buff+SRAM_Point01+SAVE_LIFE, 2 );
    Memcpy( &this->life[2], sram->read_buff+SRAM_Point02+SAVE_LIFE, 2 );

    Memcpy( &this->item[0], sram->read_buff+SRAM_Point00+SAVE_ITEM, 4 );
    Memcpy( &this->item[1], sram->read_buff+SRAM_Point01+SAVE_ITEM, 4 );
    Memcpy( &this->item[2], sram->read_buff+SRAM_Point02+SAVE_ITEM, 4 );

    Memcpy( &this->f_64dd[0], sram->read_buff+SRAM_Point00+SAVE_64DD, 2 );
    Memcpy( &this->f_64dd[1], sram->read_buff+SRAM_Point01+SAVE_64DD, 2 );
    Memcpy( &this->f_64dd[2], sram->read_buff+SRAM_Point02+SAVE_64DD, 2 );

    Memcpy( &this->heart_status[0], sram->read_buff+SRAM_Point00+SAVE_HEART+19, 1 );
    Memcpy( &this->heart_status[1], sram->read_buff+SRAM_Point01+SAVE_HEART+19, 1 );
    Memcpy( &this->heart_status[2], sram->read_buff+SRAM_Point02+SAVE_HEART+19, 1 );

#if defined(PAL_VERSION)
    Memcpy( &this->now_life[0], sram->read_buff+SRAM_Point00+SAVE_LIFE_NOW, 2 );
    Memcpy( &this->now_life[1], sram->read_buff+SRAM_Point01+SAVE_LIFE_NOW, 2 );
    Memcpy( &this->now_life[2], sram->read_buff+SRAM_Point02+SAVE_LIFE_NOW, 2 );
#endif
    
    PRINTF("f_64dd=%d, %d, %d\n",this->f_64dd[0],this->f_64dd[1],this->f_64dd[2]);
    PRINTF("heart_status=%d, %d, %d\n",this->heart_status[0],this->heart_status[1],this->heart_status[2]);
#if defined(PAL_VERSION)
    PRINTF("now_life=%d, %d, %d\n",this->now_life[0],this->now_life[1],this->now_life[2]);
#endif

}
/************************************************************************
 *	£Ó£Ò£Á£Í £Ó£Ô£Á£Ò£Ô¨¡£Ó£Á£Ö£Å					*
 ************************************************************************/
extern void
sram_start_save( Game_file_choose *this, Sram *sram  )
{
#ifndef USE_OTSUKI // OLD : 1998/3/20 otsuki.
    OSIoMesg 	dmaIoMesgBuf;
    OSMesg 	dummyMesg;
#endif

    unshort	i, j, m;
    unshort	*k;

# if 0
    unshort m = sram_save_address[z_common_data.file_no];
    PRINTF("\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
    PRINTF("\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
    PRINTF("[%04x]",m);
    unshort *z = (unchar *)&sram->read_buff+i;
    for ( i = j = 0; j < SAVE_MAX; j++, m++ ) {
	if ( !i ) PRINTF("[%04x]",m);
	PRINTF("%x, ", *z++ );
	if ( (++i) == 0x20 ) {
	    i = 0;
	    PRINTF("\n");
	}
    }
# endif
/*    i = sram_save_address[z_common_data.file_no];
    PRINTF("¤Ý¤¤¤ó¤È¡á%x(%d)\n",i,z_common_data.file_no );
    Memcpy( &z_common_data.scene_no, (sram->read_buff+i), SAVE_MAX );*/

#if !defined(ROM_F)
    if ( this->no ) {
	save_initialize( );
    } else {
	save_initialize999( );
    }
# else
    save_initialize( );
# endif
    /* ¥ê¥ó¥¯£Ó£Ô£Á£Ò£Ô¾ì½ê¡Ú£Ì£É£Î£Ë¨¡£È£Ï£Í£Å¡Û */
/////////////    ZCommon_SceneNoSet( SPOT00_0 );
    ZCommon_SceneNoSet( LINK_HOME_0 );
    /* ¥ê¥ó¥¯Ç¯Îð¡Ú»Ò¶¡¡Û */
    ZCommon_LinkAgeBeChild( );
    /* ¥¼¥ë¥À»þ´ÖÀßÄê¡Ú£Á£Í£±£°¡§£°£°¡Û */
    ZCommonSet( zelda_time, 0x6aab );
    ZCommonSet( day_time, 0xFFF1 );
#if !defined(ROM_F)
    if ( !this->no ) ZCommonSet( day_time, 0x0000 );
# endif
    for ( i = 0; i < 8; i++ ) {
        unchar *n;
        n = this->name[this->no];
	Player_Name[i] = n[i];
    }
    S_Private.newf[0] = REG0;
    S_Private.newf[1] = REG1;
    S_Private.newf[2] = REG2;
    S_Private.newf[3] = REG3;
    S_Private.newf[4] = REG4;
    S_Private.newf[5] = REG5;	/* ÅÐÏ¿ */
    F_64DD = this->flag_64dd;	/* £¶£´£Ä£Ä¥Õ¥é¥° */
    PRINTF("£¶£´£Ä£Ä¥Õ¥é¥°=%d\n",this->flag_64dd);
    PRINTF("newf=%x,%x,%x,%x,%x,%x\n",S_Private.newf[0],S_Private.newf[1],S_Private.newf[2],S_Private.newf[3],S_Private.newf[4],S_Private.newf[5]);

    PRINTF("\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
    k = (unshort *)&z_common_data.scene_no;
    /* ¥Á¥§¥Ã¥¯¥µ¥à·×»» */
    for ( i = j = m = 0; i < (SAVE_MAX)/2; i++ ) {
	PRINTF("%x ",*k);
	j += *k++;
	if ( (++m) == 0x20 ) {
	    PRINTF("\n");
	    m = 0;
	}
    }
    Check_Sum = j;
    PRINTF("\n¥Á¥§¥Ã¥¯¥µ¥à¡á%x\n", Check_Sum );



    i = sram_save_address[z_common_data.file_no];
    PRINTF("I=%x no=%d\n",i, z_common_data.file_no);
    Memcpy( sram->read_buff+i, &z_common_data.scene_no, SAVE_MAX );
# if 0
    m = sram_save_address[z_common_data.file_no];
    PRINTF("\n¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö\n");
    PRINTF("[%04x]",m);
    for ( i = j = 0; j < SAVE_MAX; j++, m++ ) {
	if ( !i ) PRINTF("[%04x]",m);
	PRINTF("%x, ",sram->read_buff[m] );
	if ( (++i) == 0x20 ) {
	    i = 0;
	    PRINTF("\n");
	}
    }
# endif
    i = sram_save_address[z_common_data.file_no+3];
    PRINTF("I=%x no=%d\n",i, z_common_data.file_no+3);
    Memcpy( sram->read_buff+i, &z_common_data.scene_no, SAVE_MAX );
# if 1
#ifndef USE_OTSUKI // OLD : 1998/3/20 otsuki.
    /* SRAMÍÑ¤Î¥Ï¥ó¥É¥é¼èÆÀ */
    i = sram_save_address[z_common_data.file_no];
    osSramInit( (u32)SRAM_START_ADDR + i );
    osCreateMesgQueue( &dmaMessageQ, &dummyMesg, 1 );
    osInvalDCache((void *)(sram->read_buff + i), SRAM_SIZE ); 
    dmaIoMesgBuf.hdr.pri = OS_MESG_PRI_NORMAL;
    dmaIoMesgBuf.hdr.retQueue = &dmaMessageQ;
    dmaIoMesgBuf.dramAddr = sram->read_buff + i;
    dmaIoMesgBuf.devAddr = (u32)SRAM_START_ADDR + i;
    dmaIoMesgBuf.size = SAVE_SIZE;
    osEPiStartDma( &SramHandle, &dmaIoMesgBuf, OS_WRITE );
    osRecvMesg( &dmaMessageQ, &dummyMesg, OS_MESG_BLOCK );
    PRINTF("£Ó£Á£Ö£Å½ªÎ»\n");

    /* SRAMÍÑ¤Î¥Ï¥ó¥É¥é¼èÆÀ */
    i = sram_save_address[z_common_data.file_no+3];
    osSramInit( (u32)SRAM_START_ADDR + i );
    osCreateMesgQueue( &dmaMessageQ, &dummyMesg, 1 );
    osInvalDCache((void *)(sram->read_buff + i), SRAM_SIZE ); 
    dmaIoMesgBuf.hdr.pri = OS_MESG_PRI_NORMAL;
    dmaIoMesgBuf.hdr.retQueue = &dmaMessageQ;
    dmaIoMesgBuf.dramAddr = sram->read_buff + i;
    dmaIoMesgBuf.devAddr = (u32)SRAM_START_ADDR + i;
    dmaIoMesgBuf.size = SAVE_SIZE;
    osEPiStartDma( &SramHandle, &dmaIoMesgBuf, OS_WRITE );
    osRecvMesg( &dmaMessageQ, &dummyMesg, OS_MESG_BLOCK );
    PRINTF("£Ó£Á£Ö£Å½ªÎ»\n");
#endif
#ifdef USE_OTSUKI  // NEW : 1998/3/20 otsuki.
# if 0
    i = sram_save_address[z_common_data.file_no];
    ssSRAMWrite((void *)(sram->read_buff + i), (void *)(SRAM_START_ADDR + i), SAVE_SIZE);
    PRINTF("£Ó£Á£Ö£Å½ªÎ»\n");
    i = sram_save_address[z_common_data.file_no + 3];
    ssSRAMWrite((void *)(sram->read_buff + i), (void *)(SRAM_START_ADDR + i), SAVE_SIZE);
    PRINTF("£Ó£Á£Ö£Å½ªÎ»\n");
# endif
    ssSRAMWrite((void *)SRAM_START_ADDR, sram->read_buff, SRAM_SIZE);
    PRINTF("£Ó£Á£Ö£Å½ªÎ»\n");
#endif
# else
    /* SRAMÍÑ¤Î¥Ï¥ó¥É¥é¼èÆÀ */
    osSramInit( (u32)SRAM_START_ADDR );
    osCreateMesgQueue( &dmaMessageQ, &dummyMesg, 1 );
    osInvalDCache((void *)sram->read_buff, SRAM_SIZE ); 
    dmaIoMesgBuf.hdr.pri = OS_MESG_PRI_NORMAL;
    dmaIoMesgBuf.hdr.retQueue = &dmaMessageQ;
    dmaIoMesgBuf.dramAddr = sram->read_buff;
    dmaIoMesgBuf.devAddr = (u32)SRAM_START_ADDR;
    dmaIoMesgBuf.size = SRAM_SIZE;
    osEPiStartDma( &SramHandle, &dmaIoMesgBuf, OS_WRITE );
    osRecvMesg( &dmaMessageQ, &dummyMesg, OS_MESG_BLOCK );
    PRINTF("£Ó£Á£Ö£Å½ªÎ»\n");
# endif
    PRINTF("z_common_data.file_no = %d\n",z_common_data.file_no);
    PRINTF("SAVECT=%x, NAME=%x, LIFE=%x, ITEM=%x,  SAVE_64DD=%x\n",SAVE_SAVECT,SAVE_NAME,SAVE_LIFE,SAVE_ITEM,SAVE_64DD);
    m = sram_save_address[z_common_data.file_no];
    Memcpy( &this->save[z_common_data.file_no], sram->read_buff+m+SAVE_SAVECT, 2 );
    Memcpy( &this->name[z_common_data.file_no], sram->read_buff+m+SAVE_NAME, 8 );
    Memcpy( &this->life[z_common_data.file_no], sram->read_buff+m+SAVE_LIFE, 2 );
    Memcpy( &this->item[z_common_data.file_no], sram->read_buff+m+SAVE_ITEM, 4 );
    Memcpy( &this->f_64dd[z_common_data.file_no], sram->read_buff+m+SAVE_64DD, 2 );
    Memcpy( &this->heart_status[z_common_data.file_no], sram->read_buff+m+SAVE_HEART+19, 1 );
#if defined(PAL_VERSION)
    Memcpy( &this->now_life[z_common_data.file_no], sram->read_buff+m+SAVE_LIFE_NOW, 2 );
#endif
    PRINTF("f_64dd[%d]=%d\n",z_common_data.file_no,this->f_64dd[z_common_data.file_no]);
    PRINTF("heart_status[%d]=%d\n",z_common_data.file_no,this->heart_status[z_common_data.file_no]);
#if defined(PAL_VERSION)
    PRINTF("now_life[%d]=%d\n",z_common_data.file_no,this->now_life[z_common_data.file_no]);
#endif
}


/************************************************************************
 *	£Ó£Ò£Á£Í £Ó£Ô£Á£Ò£Ô¨¡£Ã£Ì£Å£Á£Ò					*
 ************************************************************************/
extern void
sram_start_clear( Game_file_choose *this, Sram *sram )
{
    unshort	i;

    save_initialize( );
# if 0
    i = sram_save_address[this->decision_no];
    Memcpy( sram->read_buff+i, &z_common_data.scene_no, SAVE_MAX );
////////    ssSRAMWrite((void *)SRAM_START_ADDR, sram->read_buff, SRAM_SIZE);
    i = sram_save_address[this->decision_no+3];
    Memcpy( sram->read_buff+i, &z_common_data.scene_no, SAVE_MAX );
    ssSRAMWrite((void *)SRAM_START_ADDR, sram->read_buff, SRAM_SIZE);
# else
    i = sram_save_address[this->decision_no];
    Memcpy( sram->read_buff+i, &z_common_data.scene_no, SAVE_MAX );
/*  ssSRAMWrite((void *)((int)SRAM_START_ADDR+i), &z_common_data.scene_no, SAVE_MAX);*/
    ssSRAMWrite((void *)((int)SRAM_START_ADDR+i), &z_common_data.scene_no, SAVE_SIZE);
    Memcpy( &this->f_64dd[this->decision_no], sram->read_buff+i+SAVE_64DD, 2 );

    i = sram_save_address[this->decision_no+3];
    Memcpy( sram->read_buff+i, &z_common_data.scene_no, SAVE_MAX );
/*  ssSRAMWrite((void *)((int)SRAM_START_ADDR+i), &z_common_data.scene_no, SAVE_MAX);*/
    ssSRAMWrite((void *)((int)SRAM_START_ADDR+i), &z_common_data.scene_no, SAVE_SIZE);
# endif
    PRINTF("£Ã£Ì£Å£Á£Ò½ªÎ»\n");
}
/************************************************************************
 *	£Ó£Ò£Á£Í £Ó£Ô£Á£Ò£Ô¨¡£Ã£Ï£Ð£Ù					*
 ************************************************************************/
extern void
sram_start_copy( Game_file_choose *this, Sram *sram )
{
    unshort	i;
    

    PRINTF("£Ò£Å£Á£Ä=%d(%x)  £Ã£Ï£Ð£Ù=%d(%x)\n",this->decision_no,sram_save_address[this->decision_no], this->copy_no,sram_save_address[this->copy_no]);
    /* £Ò£Å£Á£Ä */
    i = sram_save_address[this->decision_no];
    Memcpy( &z_common_data.scene_no, sram->read_buff+i, SAVE_MAX );
    /* £Ã£Ï£Ð£Ù */
    i = sram_save_address[this->copy_no];
    Memcpy( sram->read_buff+i, &z_common_data.scene_no, SAVE_MAX );
    i = sram_save_address[this->copy_no+3];
    Memcpy( sram->read_buff+i, &z_common_data.scene_no, SAVE_MAX );
    ssSRAMWrite((void *)SRAM_START_ADDR, sram->read_buff, SRAM_SIZE);

    i = sram_save_address[this->copy_no];
    Memcpy( &this->save[this->copy_no], sram->read_buff+i+SAVE_SAVECT, 2 );
    Memcpy( &this->name[this->copy_no], sram->read_buff+i+SAVE_NAME, 8 );
    Memcpy( &this->life[this->copy_no], sram->read_buff+i+SAVE_LIFE, 2 );
    Memcpy( &this->item[this->copy_no], sram->read_buff+i+SAVE_ITEM, 4 );
    Memcpy( &this->f_64dd[this->copy_no], sram->read_buff+i+SAVE_64DD, 2 );
    Memcpy( &this->heart_status[this->copy_no], sram->read_buff+i+SAVE_HEART+19, 1 );
#if defined(PAL_VERSION)
    Memcpy( &this->now_life[this->copy_no], sram->read_buff+i+SAVE_LIFE_NOW, 2 );
#endif
    PRINTF("f_64dd[%d]=%d\n",z_common_data.file_no,this->f_64dd[z_common_data.file_no]);
    PRINTF("heart_status[%d]=%d\n",z_common_data.file_no,this->heart_status[z_common_data.file_no]);
    PRINTF("£Ã£Ï£Ð£Ù½ªÎ»\n");
}




# if 0
/************************************************************************
 *	£Ó£Ò£Á£Í¥¤¥Ë¥·¥ã¥é¥¤¥º¥Á¥§¥Ã¥¯					*
 *									*
 *	£Ó£Ò£Á£Í¥µ¥¤¥º¡Ú256£Ë£â£é£ô ¡á 32£Ë£â£ù£ô£å ¡á 32768£â£ù£ô£å¡Û	*
 ************************************************************************/
extern void
sram_initialize( Game *game, Sram *sram )
{
#ifndef USE_OTSUKI // OLD : 1998/3/20 otsuki.
    OSIoMesg 	dmaIoMesgBuf;
    OSMesg 	dummyMesg;
#endif

    pad_t	*pad = &game->pads[2];

    static unchar sram_check_data[] = {
	0x1408, 0x0814,
	'N', '6', '4', 'L', 'E', 'G', 'E', 'N', 'D', 'O', 'F', 'Z', 'E', 'L', 'D', 'A',
    };
    static unchar sram_check_data99[] = {
	0xD94E, 0xA75B,
	'L', 'E', 'G', 'E', 'N', 'D', 'O', 'F', 'Z', 'E', 'L', 'D', 'A', 'N', '6', '4',
    };

    unshort	i, j;
    unshort	*k;

    /* ÂçÄÐ£Ô£Å£Ó£Ô */
    SRAMAccessTest();
    
#ifndef USE_OTSUKI // OLD : 1998/3/20 otsuki.
    /* SRAMÍÑ¤Î¥Ï¥ó¥É¥é¼èÆÀ */
    osSramInit( (u32)SRAM_START_ADDR );

    /* CPU¥Ç¡¼¥¿¥­¥ã¥Ã¥·¥å¥é¥¤¥ó¤ÎÌµ¸ú²½ */
    osInvalDCache((void *)sram->read_buff, sizeof(sram_check_data)/sizeof(unchar) );
    /* Í¿¤¨¤é¤ì¤¿OSMesgQueue¤ò¹½À®¤¹¤ëmq¤ò¶õ¤Î¾õÂÖ¤Ë½é´ü²½ */
    osCreateMesgQueue( &dmaMessageQ, &dummyMesg, 1 );
    /* Í¥ÀèÍ×µá */
    dmaIoMesgBuf.hdr.pri = OS_MESG_PRI_NORMAL;
    /* PI¥Þ¥Í¡¼¥¸¥ã¤«¤éI/O½èÍý¤Î½ªÎ»ÄÌÃÎ¤ò¼õ¤±¼è¤ë°Ù¤Î¥á¥Ã¥»¡¼¥¸¥­¥å¡¼ */
    dmaIoMesgBuf.hdr.retQueue = &dmaMessageQ;
    /* RDRAM¤Î²¾ÁÛ¥¢¥É¥ì¥¹¡Ê8¥Ð¥¤¥È¤Î¥¢¥é¥¤¥ó¥á¥ó¥È¡Ë */
    dmaIoMesgBuf.dramAddr = sram->read_buff;
    /* PI¥Ç¥Ð¥¤¥¹¤Î¥¢¥É¥ì¥¹¡Ê2¥Ð¥¤¥È¤Î¥¢¥é¥¤¥ó¥á¥ó¥È¡Ë */
    dmaIoMesgBuf.devAddr = (u32)SRAM_START_ADDR;
    /* Å¾Á÷ÎÌ */
    dmaIoMesgBuf.size = sizeof(sram_check_data)/sizeof(unchar);
    /* RDRAM¤ÈPI¥Ç¥Ð¥¤¥¹¥¢¥É¥ì¥¹¶õ´Ö¤È¤Î´Ö¤ÎDMAÅ¾Á÷¤ò¥»¥Ã¥È¥¢¥Ã¥× */
    osEPiStartDma( &SramHandle, &dmaIoMesgBuf, OS_READ );
    /* ¥á¥Ã¥»¡¼¥¸ÂÔ¤Á¹ÔÎómqÃæ¤ÎºÇ½é¤Î¥á¥Ã¥»¡¼¥¸¤òmsg¤Ë¤è¤Ã¤Æ»ØÄê¤µ¤ì¤¿¥¢¥É¥ì¥¹Æâ¤Ë¥³¥Ô¡¼ */ 
    (void) osRecvMesg(&dmaMessageQ, &dummyMesg, OS_MESG_BLOCK);
#endif
#ifdef USE_OTSUKI  // NEW : 1998/3/20 otsuki.
    ssSRAMRead(sram->read_buff,
	       (void *)SRAM_START_ADDR,
	       sizeof(sram_check_data) / sizeof(unchar));
#endif

    if ( Pad_button() & L_JPAD ) sram->read_buff[0] = 0xff;
    
    /* £Ó£Ò£Á£Í½é´ü²½¥Á¥§¥Ã¥¯ */
    for ( i = j = 0; i < sizeof(sram_check_data)/sizeof(unchar); i++ ) {
	if ( sram_check_data[i] != sram->read_buff[i] ) {
	    /*
	     *  £Ó£Ò£Á£Í½é´ü²½
	     */
	    PRINTF("[%d] = %x (%x)  ", i, sram_check_data[i], sram->read_buff[i] );
	    /* £Ó£Ò£Á£Í½é´ü²½ÍÑ¥Ð¥Ã¥Õ¥¡£Ú£Å£Ò£Ï¥¯¥ê¥¢¡¼ */
	    bzero( sram->read_buff, SRAM_SIZE );
	    /* ¥á¥â¥ê¡¼Å¾Á÷ */
	    Memcpy( sram->read_buff, &sram_check_data, sizeof(sram_check_data)/sizeof(unchar) );


	    /*
	     * ¥Õ¥¡¥¤¥ë£±ÍÑ ¨¡ ´ðËÜ¥Ç¡¼¥¿¥»¥Ã¥È¡Ê¥Ç¥Ð¥Ã¥¯ÍÑ¡Ë
	     */
#if !defined(ROM_F)
	    save_initialize999( );
# else
	    save_initialize( );
# endif
	    /* ¥ê¥ó¥¯£Ó£Ô£Á£Ò£Ô¾ì½ê¡Ú£Ì£É£Î£Ë¨¡£È£Ï£Í£Å¡Û */
	    ZCommon_SceneNoSet( SPOT00_0 );
	    /* ¥ê¥ó¥¯Ç¯Îð¡Ú»Ò¶¡¡Û */
	    ZCommon_LinkAgeBeChild( );
	    /* ¥¼¥ë¥À»þ´ÖÀßÄê¡Ú£Á£Í£±£°¡§£°£°¡Û */
	    ZCommonSet( zelda_time, 0x6aab );
	    ZCommonSet( day_time, 0xFFF0 );
	    k = (unshort *)&z_common_data.scene_no;
	    /* ¥Á¥§¥Ã¥¯¥µ¥à·×»» */
	    for ( i = j = 0; i < (SAVE_MAX)/2; i++ ) {
////////		PRINTF("%x ",*k);
		j += *k++;
	    }
	    Check_Sum = j;
	    PRINTF("\n¥Á¥§¥Ã¥¯¥µ¥à¡á%x\n", Check_Sum );
	    i = sram_save_address[0];
	    Memcpy( sram->read_buff+i, &z_common_data.scene_no, SAVE_MAX );
	    i = sram_save_address[3];
	    Memcpy( sram->read_buff+i, &z_common_data.scene_no, SAVE_MAX );

	    /*
	     * ´ðËÜ¥Ç¡¼¥¿¥»¥Ã¥È
	     */
	    save_initialize( );
	    /* ¥ê¥ó¥¯£Ó£Ô£Á£Ò£Ô¾ì½ê¡Ú£Ì£É£Î£Ë¨¡£È£Ï£Í£Å¡Û */
	    ZCommon_SceneNoSet( SPOT00_0/*LINK_HOME_0*/ );
	    /* ¥ê¥ó¥¯Ç¯Îð¡Ú»Ò¶¡¡Û */
	    ZCommon_LinkAgeBeChild( );
	    /* ¥¼¥ë¥À»þ´ÖÀßÄê¡Ú£Á£Í£±£°¡§£°£°¡Û */
	    ZCommonSet( zelda_time, 0x6aab );
	    ZCommonSet( day_time, 0xFFF0 );
	    k = (unshort *)&z_common_data.scene_no;
	    /* ¥Á¥§¥Ã¥¯¥µ¥à·×»» */
	    for ( i = j = 0; i < (SAVE_MAX)/2; i++ ) {
////////		PRINTF("%x ",*k);
		j += *k++;
	    }
	    Check_Sum = j;
	    PRINTF("\n¥Á¥§¥Ã¥¯¥µ¥à¡á%x\n", Check_Sum );
	    i = sram_save_address[1];
	    Memcpy( sram->read_buff+i, &z_common_data.scene_no, SAVE_MAX );
	    i = sram_save_address[2];
	    Memcpy( sram->read_buff+i, &z_common_data.scene_no, SAVE_MAX );
	    i = sram_save_address[4];
	    Memcpy( sram->read_buff+i, &z_common_data.scene_no, SAVE_MAX );
	    i = sram_save_address[5];
	    Memcpy( sram->read_buff+i, &z_common_data.scene_no, SAVE_MAX );
	    sram->read_buff[SRAM_SIZE/2-1] = 0xABCD;

#ifndef USE_OTSUKI // OLD : 1998/3/20 otsuki.
	    /* £Ó£Ò£Á£Í½é´ü²½¥Ç¡¼¥¿¥»¥Ã¥È */
	    osCreateMesgQueue( &dmaMessageQ, &dummyMesg, 1 );
	    osInvalDCache((void *)sram->read_buff, SRAM_SIZE ); 
	    dmaIoMesgBuf.hdr.pri = OS_MESG_PRI_NORMAL;
	    dmaIoMesgBuf.hdr.retQueue = &dmaMessageQ;
	    dmaIoMesgBuf.dramAddr = sram->read_buff;
	    dmaIoMesgBuf.devAddr = (u32)SRAM_START_ADDR;
	    dmaIoMesgBuf.size = SRAM_SIZE;
	    osEPiStartDma( &SramHandle, &dmaIoMesgBuf, OS_WRITE );
	    osRecvMesg( &dmaMessageQ, &dummyMesg, OS_MESG_BLOCK );
#endif
#ifdef USE_OTSUKI  // NEW : 1998/3/20 otsuki.
	    ssSRAMWrite((void *)SRAM_START_ADDR, sram->read_buff, SRAM_SIZE);
#endif
	    PRINTF("£Ó£Ò£Á£Í½é´ü²½½ªÎ»\n");
# ifndef U_hayakawa_U		/* ¤Á¤ç¤Ã¤È½Ð²á¤®¤Ê¤Î¤Ç¾Ã¤µ¤·¤Æ¤â¤é¤¤¤Þ¤¹ */
# if 1
	    for ( i = j = 0; i < SRAM_SIZE; i++ ) {
		if ( !j ) PRINTF("[%04x]",i);
		PRINTF("%x, ",sram->read_buff[i] );
		if ( (++j) == 0x40 ) {
		    j = 0;
		    PRINTF("\n");
		}
	    }
# endif
# endif/* U_hayakawa_U */

	    bzero( sram->read_buff, SRAM_SIZE );
#ifndef USE_OTSUKI // OLD : 1998/3/20 otsuki.
	    osInvalDCache((void *)sram->read_buff, SRAM_SIZE );
	    osCreateMesgQueue( &dmaMessageQ, &dummyMesg, 1 );
	    dmaIoMesgBuf.hdr.pri = OS_MESG_PRI_NORMAL;
	    dmaIoMesgBuf.hdr.retQueue = &dmaMessageQ;
	    dmaIoMesgBuf.dramAddr = sram->read_buff;
	    dmaIoMesgBuf.devAddr = (u32)SRAM_START_ADDR;
	    dmaIoMesgBuf.size = SRAM_SIZE;
	    osEPiStartDma( &SramHandle, &dmaIoMesgBuf, OS_READ );
	    (void) osRecvMesg(&dmaMessageQ, &dummyMesg, OS_MESG_BLOCK);
#endif
#ifdef USE_OTSUKI  // NEW : 1998/3/20 otsuki.
	    ssSRAMRead(sram->read_buff, (void *)SRAM_START_ADDR, SRAM_SIZE);
#endif
# if 0
	    for ( i = j = 0; i < SRAM_SIZE/2; i++ ) {
		if ( !j ) PRINTF("¡Ú%04x¡Û",i);
		PRINTF("%x, ",sram->read_buff[i] );
		if ( (++j) == 0x20 ) {
		    j = 0;
		    PRINTF("\n");
		}
	    }
# endif
	}
    }
# if 0
    osCreateMesgQueue( &dmaMessageQ, &dummyMesg, 1 );
    osInvalDCache((void *)sram_check_data99, sizeof(sram_check_data99)/sizeof(unchar) ); 
    dmaIoMesgBuf.hdr.pri = OS_MESG_PRI_NORMAL;
    dmaIoMesgBuf.hdr.retQueue = &dmaMessageQ;
    dmaIoMesgBuf.dramAddr = sram_check_data99;
    dmaIoMesgBuf.devAddr = (u32)SRAM_START_ADDR;
    dmaIoMesgBuf.size = sizeof(sram_check_data99)/sizeof(unchar);
    osEPiStartDma( &SramHandle, &dmaIoMesgBuf, OS_WRITE );
    (void) osRecvMesg(&dmaMessageQ, &dummyMesg, OS_MESG_BLOCK);
# endif
    PRINTF("£Ç£Ï£Ï£Ä¡ª£Ç£Ï£Ï£Ä¡ª(%d)\n",i);
    PRINTF("¥µ¥¤¥º¡á%d\n",sizeof(Memory));
}
# endif
/************************************************************************
 *									*
 *	£Ó£Ò£Á£Í¥¨¥ê¥¢ ¥³¥ó¥¹¥È¥é¥¯¥È					*
 *									*
 ************************************************************************/
extern void
sram_sound_save( Sram *sram )
{
    ssSRAMWrite((void *)SRAM_START_ADDR, sram->read_buff, 0x10);
}
/************************************************************************
 *	£Ó£Ò£Á£Í¥¤¥Ë¥·¥ã¥é¥¤¥º¥Á¥§¥Ã¥¯					*
 *									*
 *	£Ó£Ò£Á£Í¥µ¥¤¥º¡Ú256£Ë£â£é£ô ¡á 32£Ë£â£ù£ô£å ¡á 32768£â£ù£ô£å¡Û	*
 ************************************************************************/
extern void
sram_initialize( Game *game, Sram *sram )
{
    //pad_t	*pad = &game->pads[2];

    unshort	i/*, j*/;
    //unshort	*k;

    PRINTF("sram_initialize( Game *game, Sram *sram )\n");

    /* ÂçÄÐ£Ô£Å£Ó£Ô
    SRAMAccessTest();*/
    
#ifndef USE_OTSUKI // OLD : 1998/3/20 otsuki.
    /* SRAMÍÑ¤Î¥Ï¥ó¥É¥é¼èÆÀ */
    osSramInit( (u32)SRAM_START_ADDR );

    /* CPU¥Ç¡¼¥¿¥­¥ã¥Ã¥·¥å¥é¥¤¥ó¤ÎÌµ¸ú²½ */
    osInvalDCache((void *)sram->read_buff, sizeof(sram_check_data)/sizeof(unchar) );
    /* Í¿¤¨¤é¤ì¤¿OSMesgQueue¤ò¹½À®¤¹¤ëmq¤ò¶õ¤Î¾õÂÖ¤Ë½é´ü²½ */
    osCreateMesgQueue( &dmaMessageQ, &dummyMesg, 1 );
    /* Í¥ÀèÍ×µá */
    dmaIoMesgBuf.hdr.pri = OS_MESG_PRI_NORMAL;
    /* PI¥Þ¥Í¡¼¥¸¥ã¤«¤éI/O½èÍý¤Î½ªÎ»ÄÌÃÎ¤ò¼õ¤±¼è¤ë°Ù¤Î¥á¥Ã¥»¡¼¥¸¥­¥å¡¼ */
    dmaIoMesgBuf.hdr.retQueue = &dmaMessageQ;
    /* RDRAM¤Î²¾ÁÛ¥¢¥É¥ì¥¹¡Ê8¥Ð¥¤¥È¤Î¥¢¥é¥¤¥ó¥á¥ó¥È¡Ë */
    dmaIoMesgBuf.dramAddr = sram->read_buff;
    /* PI¥Ç¥Ð¥¤¥¹¤Î¥¢¥É¥ì¥¹¡Ê2¥Ð¥¤¥È¤Î¥¢¥é¥¤¥ó¥á¥ó¥È¡Ë */
    dmaIoMesgBuf.devAddr = (u32)SRAM_START_ADDR;
    /* Å¾Á÷ÎÌ */
    dmaIoMesgBuf.size = sizeof(sram_check_data)/sizeof(unchar);
    /* RDRAM¤ÈPI¥Ç¥Ð¥¤¥¹¥¢¥É¥ì¥¹¶õ´Ö¤È¤Î´Ö¤ÎDMAÅ¾Á÷¤ò¥»¥Ã¥È¥¢¥Ã¥× */
    osEPiStartDma( &SramHandle, &dmaIoMesgBuf, OS_READ );
    /* ¥á¥Ã¥»¡¼¥¸ÂÔ¤Á¹ÔÎómqÃæ¤ÎºÇ½é¤Î¥á¥Ã¥»¡¼¥¸¤òmsg¤Ë¤è¤Ã¤Æ»ØÄê¤µ¤ì¤¿¥¢¥É¥ì¥¹Æâ¤Ë¥³¥Ô¡¼ */ 
    (void) osRecvMesg(&dmaMessageQ, &dummyMesg, OS_MESG_BLOCK);
#endif
#ifdef USE_OTSUKI  // NEW : 1998/3/20 otsuki.
    ssSRAMRead(sram->read_buff,
	       (void *)SRAM_START_ADDR,
	       SRAM_SIZE );
    for ( i = 0; i < (sizeof(sram_check_data)/sizeof(unchar)-3); i++ ) {
	if ( sram_check_data[i+3] != sram->read_buff[i+3]) {
# if 0
	    bzero( sram->read_buff, SRAM_SIZE );
	    for ( i = 0;  i < (SAVE_MAX)/2; i++ ) {
		sram->read_buff[i] = i;
	    }
# endif
# if 0
	    /* ¥á¥â¥ê¡¼Å¾Á÷ */
	    Memcpy( sram->read_buff, &sram_check_data, sizeof(sram_check_data)/sizeof(unchar) );
	    ssSRAMWrite((void *)SRAM_START_ADDR, sram->read_buff, SRAM_SIZE);
	    PRINTF("£Ó£Ò£Á£ÍÇË²õ¡ª¡ª¡ª¡ª¡ª¡ª\n");
	    break;
# endif
	    /* ¥á¥â¥ê¡¼Å¾Á÷ */
	    PRINTF("£Ó£Ò£Á£ÍÇË²õ¡ª¡ª¡ª¡ª¡ª¡ª\n");
	    Memcpy( sram->read_buff, &sram_check_data, sizeof(sram_check_data)/sizeof(unchar) );
	    sram_sound_save( sram );
	}
    }
    S_SOUND = sram->read_buff[0] & 0x3;		/* £Ó£Ï£Õ£Î£Ä ¥¹¥Æ¥ì¥ª¡¿¥â¥Î¥é¥ë¡¿¥Ø¥Ã¥É¥Û¥ó¡¿£³£Ä */
    Z_ATTENTION = sram->read_buff[1] & 0x1;	/* £ÚÃíÌÜÊýË¡ £°¡§¥¹¥¤¥Ã¥Á¡¿£±¡§¥Û¡¼¥ë¥É */
#if defined(PAL_VERSION)
    J_N = sram->read_buff[2];			/* £°¡§±Ñ¸ì ¡¿ £±¡§¥É¥¤¥Ä¸ì ¡¿ £²¡§¥Õ¥é¥ó¥¹¸ì */
    if ( J_N > 2 ) {
	J_N = 0;
	sram->read_buff[2] = J_N;
	sram_sound_save( sram );
    }
#endif
#endif

# if 0
////////    if ( Pad_button() & (A_BUTTON | B_BUTTON | START_BUTTON | R_JPAD) ) {
    if ( ZCommonGet( sram_init_flag ) == 98 ) {
	/*
	 *  £Ó£Ò£Á£Í½é´ü²½
	 */
	PRINTF("\n\n\n¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á\n  £Ó£Ò£Á£Í½é´ü²½\n\n¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á\n\n\n");
	/* £Ó£Ò£Á£Í½é´ü²½ÍÑ¥Ð¥Ã¥Õ¥¡£Ú£Å£Ò£Ï¥¯¥ê¥¢¡¼ */
	bzero( sram->read_buff, SRAM_SIZE );

#if !defined(ROM_F)
	/*
	 * ¥Õ¥¡¥¤¥ë£±ÍÑ ¨¡ ´ðËÜ¥Ç¡¼¥¿¥»¥Ã¥È¡Ê¥Ç¥Ð¥Ã¥¯ÍÑ¡Ë
	 */
	save_initialize999( );
	S_Private.newf[0] = REG0;
	S_Private.newf[1] = REG1;
	S_Private.newf[2] = REG2;
	S_Private.newf[3] = REG3;
	S_Private.newf[4] = REG4;
	S_Private.newf[5] = REG5;	/* ÅÐÏ¿ */
	k = (unshort *)&z_common_data.scene_no;
	/* ¥Á¥§¥Ã¥¯¥µ¥à·×»» */
	PRINTF("\n--------------------------------------------------------------\n");
	for ( i = j = 0; i < (SAVE_MAX)/2; i++ ) {
	    j += *k++;
	}
	Check_Sum = j;
# if 0
	/* ¥á¥â¥ê¡¼Å¾Á÷ */
	Memcpy( sram->read_buff, &sram_check_data, sizeof(sram_check_data)/sizeof(unchar) );
	/*
	 * ¥Õ¥¡¥¤¥ë£±ÍÑ ¨¡ ´ðËÜ¥Ç¡¼¥¿¥»¥Ã¥È¡Ê¥Ç¥Ð¥Ã¥¯ÍÑ¡Ë
	 */
	save_initialize999( );
	/* ¥ê¥ó¥¯£Ó£Ô£Á£Ò£Ô¾ì½ê¡Ú£Ì£É£Î£Ë¨¡£È£Ï£Í£Å¡Û */
	ZCommon_SceneNoSet( SPOT00_0 );
	/* ¥ê¥ó¥¯Ç¯Îð¡Ú»Ò¶¡¡Û */
	ZCommon_LinkAgeBeChild( );
	/* ¥¼¥ë¥À»þ´ÖÀßÄê¡Ú£Á£Í£±£°¡§£°£°¡Û */
	ZCommonSet( zelda_time, 0x6aab );
	ZCommonSet( day_time, 0xFFF0 );
	k = (unshort *)&z_common_data.scene_no;
	/* ¥Á¥§¥Ã¥¯¥µ¥à·×»» */
	for ( i = j = 0; i < (SAVE_MAX)/2; i++ ) {
////////		PRINTF("%x ",*k);
	    j += *k++;
	}
	Check_Sum = j;
	PRINTF("\n¥Á¥§¥Ã¥¯¥µ¥à¡á%x\n", Check_Sum );
	i = sram_save_address[0];
	Memcpy( sram->read_buff+i, &z_common_data.scene_no, SAVE_MAX );
	i = sram_save_address[3];
	Memcpy( sram->read_buff+i, &z_common_data.scene_no, SAVE_MAX );
# endif	
# endif	
	ssSRAMWrite((void *)SRAM_START_ADDR, sram->read_buff, SRAM_SIZE);

    }
# endif
#if !defined(ROM_F)
    if ( Pad_button() & R_JPAD ) {
	bzero( sram->read_buff, SRAM_SIZE );
	for ( i = 0;  i < (SAVE_MAX)/2; i++ ) {
	    sram->read_buff[i] = i;
	}
	ssSRAMWrite((void *)SRAM_START_ADDR, sram->read_buff, SRAM_SIZE);
	PRINTF("£Ó£Ò£Á£ÍÇË²õ¡ª¡ª¡ª¡ª¡ª¡ª\n");
    }
# endif
    PRINTF("£Ç£Ï£Ï£Ä¡ª£Ç£Ï£Ï£Ä¡ª ¥µ¥¤¥º¡á%d + %d ¡á %d\n",sizeof(Memory),sizeof(SAVE_BASE),sizeof(Memory)+sizeof(SAVE_BASE));
/*    osSyncPrintf("£Ç£Ï£Ï£Ä¡ª£Ç£Ï£Ï£Ä¡ª ¥µ¥¤¥º¡á%d\n",sizeof(Memory));*/
    COLOR_BLUE();
    PRINTF("Na_SetSoundOutputMode = %d\n",NA_SOUT_STEREO + S_SOUND);
    PRINTF("Na_SetSoundOutputMode = %d\n",NA_SOUT_STEREO + S_SOUND);
    PRINTF("Na_SetSoundOutputMode = %d\n",NA_SOUT_STEREO + S_SOUND);
    COLOR_NORMAL();
    Na_SetSoundOutputMode( NA_SOUT_STEREO + S_SOUND );	/* ¥µ¥¦¥ó¥É½ÐÎÏ¥»¥Ã¥È */
}


/************************************************************************
 *									*
 *	£Ó£Ò£Á£Í¥¨¥ê¥¢ ¥³¥ó¥¹¥È¥é¥¯¥È					*
 *									*
 ************************************************************************/
extern void
sram_title_ct( Game *game, Sram *sram )
{
    sram->read_buff = (unchar *)Game_alloc( SRAM_SIZE );
    //assert(sram->read_buff != NULL);

}

extern void
sram_ct( Game *game, Sram *sram )
{
    //game;
    //sram;
    
////////    sram->read_buff = (unchar *)Game_alloc( SAVE_SIZE );
////////    assert(sram->read_buff != NULL);

}
    



