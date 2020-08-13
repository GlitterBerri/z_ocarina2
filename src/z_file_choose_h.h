/* $Id: z_file_choose_h.h,v 1.1.1.1 2003/03/10 22:42:56 tong Exp $ */	
/* $Log: z_file_choose_h.h,v $
 * Revision 1.1.1.1  2003/03/10 22:42:56  tong
 * new OBJ tree for ocarina from Nintendo
 *
 * Revision 2.3  1999-01-07 17:15:36+09  soejima
 * ＧＡＴＥＷＡＹ仕様
 *
 * Revision 2.2  1999-01-07 13:29:09+09  soejima
 * ＧＡＴＥＷＡＹ仕様
 *
 * Revision 2.1  1998-10-22 21:17:25+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.18  1998/07/04 07:06:16  soejima
 * *** empty log message ***
 *
 * Revision 1.17  1998-04-21 22:50:30+09  soejima
 * *** empty log message ***
 *
 * Revision 1.16  1998-04-15 21:47:48+09  soejima
 * *** empty log message ***
 *
 * Revision 1.15  1998-04-10 23:55:30+10  soejima
 * （仮）
 *
 * Revision 1.11  1998/01/30  12:27:38  soejima
 * Revision 1.8  1998/01/19  11:54:03  soejima
 * タイトル ポインタ
 * Revision 1.7  1998/01/16  12:26:57  soejima
 * メニュー ポインタ 変更
 * Revision 1.1  1997/05/29  07:52:54  soejima
 * Initial revision
 * $Log追加
 * */


#ifndef INCLUDE_Z_FILE_CHOOSE_H_H
#define INCLUDE_Z_FILE_CHOOSE_H_H



/************************************************************************
 *
 *	ゼルダタイトル
 *
 ************************************************************************/
/* ＭＡＩＮポインタ */
enum {
    File_choose_Title,		/* ０：タイトル表示 */
    File_choose_Select,		/* １：メイン メニュー */
    File_choose_Decision,	/* ２：選択決定 */
    File_choose_Point
};


/* タイトル ポインタ */
enum {
    Title_Fillin,		/* ０：ＦＩＬＬ フェードイン */
    Title_Wait,			/* １：ＷＡＩＴ */
    Title_Effectin,		/* ２：タイトル＆エフェクト フェードイン */
    Title_Fadein,		/* ３：タイトル フェードイン */
    Title_Effectout,		/* ４：エフェクト フェードアウト */
    Title_Logoin,		/* ５："１９９７Ｎｉｎｔｅｎｄｏ" フェードイン */
    Title_Timewait,		/* ６：時間待ち */
    Title_Fillout,		/* ７：ＦＩＬＬ フェードアウト */
    Title_Goto,			/* ８：ＧＯＴＯ選択面 */
    Title_Point
};


/* メニュー ポインタ */
enum {
    Menu_Fadein,		/* ０：フェードイン（＆スクロール）*/
    Menu_Fadein1,		/* １：フェードイン */
    Menu_Select,		/* ２：ファイル選択 */
    Menu_Copy_0,		/* ３：Ｃｏｐｙ（イニシャル ＆ 移動） */
    Menu_Copy_1,		/* ４：        （どれをコピーしますか？）*/
    Menu_Copy_2,		/* ５：        （移動１） */
    Menu_Copy_4,		/* ６：        （フェードイン１） */
    Menu_Copy_5,		/* ７：        （どこにコピーしますか？）*/
    Menu_Copy_6,		/* ８：        （フェードアウト１） */
    Menu_Copy_7,		/* ９：        （キャンセル１） */
    Menu_Copy_8,		/*１０：       （移動２） */
    Menu_Copy_9,		/*１１：       （フェードイン２） */
    Menu_Copy_A,		/*１２：       （本当にコピーしますか？）*/
    Menu_Copy_B,		/*１３：       （フェードアウト２） */
    Menu_Copy_D,		/*１４：       （移動３） */
    Menu_Copy_E,		/*１５：       （フェードイン３） */
    Menu_Copy_F,		/*１６：       （コピーが終了しました）*/
    Menu_Copy_G,		/*１７：       （コピーが終了しました）*/
    Menu_Copy_H,		/*１８：       （コピーが終了しました）*/
    Menu_Copy_R,		/*１９：       （ＲＥＴＵＲＮ）*/
    Menu_Delt_0,		/*２０：Ｄｅｌ（イニシャル ＆ 移動） */
    Menu_Delt_1,		/*２１：      （どれを消しますか？） */
    Menu_Delt_2,		/*２２：      （移動） */
    Menu_Delt_3,		/*２３：      （フェードイン） */
    Menu_Delt_4,		/*２４：      （本当に消しますか？） */
    Menu_Delt_5,		/*２５：      （フェードアウト） */
    Menu_Delt_6,		/*２６：      （キャンセル） */
    Menu_Delt_7,		/*２７：      （消去しました） */
    Menu_Delt_8,		/*２８：      （消去しました） */
    Menu_Delt_9,		/*２９：      （消去しました） */
    Menu_Delt_R,		/*３０：      （ＲＥＴＵＲＮ） */
    Menu_kettei,		/*３１：ファイル決定 */
    Menu_Go_Nameset,		/*３２：ファイル選択から名前登録へ */
    Menu_Nameset,		/*３３：名前登録 */
    Menu_Nameset_Fdin,		/*３４：名前登録フェードイン */
    Menu_Go_Select,		/*３５：名前登録からファイル選択へ */
    Menu_Go_Option,		/*３６：ファイル選択から名前登録へ */
    Menu_Option,		/*３７：ＯＰＴＩＯＮ */
    Menu_Option_Fdin,		/*３８：ＯＰＴＩＯＮフェードイン */
    Menu_Option_Select,		/*３９：ＯＰＴＩＯＮからファイル選択へ */
    Menu_Next,			/*４０：次のメニューへ */
    Menu_Point
};


/* 選択決定 ポインタ */
enum {
    Decision_Init,		/* ０：選択決定イニシャル ＆ 移動 */
    Decision_Move,		/* １：選択決定フェードイン */
    Decision_Fdin,		/* ２：選択決定フェードイン */
    Decision_Decision,		/* ３：選択決定 */
    Decision_Fdout,		/* ４：選択決定フェードアウト */
    Decision_Back,		/* ５：選択決定バック＆ リターン */
    Decision_GotoFdout,		/* ６：ＧＯＴＯＧＡＭＥ フェードアウト */
    Decision_GotoGame,		/* ７：ＧＯＴＯ ＧＡＭ */
    Decision_Point
};


/* 名前登録入替ポインタ */
enum {
    Hira_hira,			/* ひらがな */
    Kata_kata,			/* カタカナ */
    Eisu_eisu,			/* 英数     */
    Hira_kata,			/* ひらがな→カタカナ */
    Kata_hira,			/* カタカナ→ひらがな */
    Hira_eisu,			/* ひらがな→英数 */
    Eisu_hira,			/* 英数→ひらがな */
    Kata_eisu,			/* カタカナ→英数 */
    Eisu_kata,			/* 英数→カタカナ */
    Name_Point
};





#define FRAME_CT	8
#define FRAME_ALPHA	255
#define F_A_CT		FRAME_ALPHA/FRAME_CT
#define BASE_ALPHA	200
#define B_A_CT		BASE_ALPHA/FRAME_CT



/* TITLE+(拡張ﾌﾟﾚｰﾄ＊3)+((FILEﾌﾟﾚｰﾄ+名前ﾌﾟﾚｰﾄ+ｺﾈｸﾀ+64DDﾌﾟﾚｰﾄ+ｺﾈｸﾀ)＊3)+((名前+ｾｰﾌﾞ+ﾊｰﾄ+ｱｲﾃﾑ)＊3)+(ｺﾋﾟｰ+消ｽ)+ｵﾌﾟｼｮﾝ+ｶｰｿﾙ+注意書き */
#define F_INDEX1	((1+(5*3)+(5*0))*4)
#define F_INDEX2	((1+(5*3)+(5*1))*4)
#define F_INDEX3	((1+(5*3)+(5*2))*4)
#define N0_INDEX	((1+(5*3)+(5*3)+((8+4+20+10)*0))*4)
#define N1_INDEX	((1+(5*3)+(5*3)+((8+4+20+10)*1))*4)
#define N2_INDEX	((1+(5*3)+(5*3)+((8+4+20+10)*2))*4)
#define CD_INDEX	((1+(5*3)+(5*3)+((8+4+20+10)*3))*4)
#define	SELECTVTX	((1+(5*3)+(5*3)+((8+4+20+10)*3)+(1+1)+1+1+1)*4)
#define SaveVtx		8*4
#define	LifeVtx		(8+4)*4
#define ItemVtx		(8+4+20)*4






#if defined(GATEWAY_VERSION)
extern unsigned char h_file_ab_1_gate_txt[];
extern unsigned char h_file_ab_2_gate_txt[];
extern unsigned char h_mes_file_gate_txt[];
extern unsigned short h_file_start_gate_txt[];
#endif	/* GATEWAY_VERSION */




#endif

/*** z_file_choose_h.h end ***/

