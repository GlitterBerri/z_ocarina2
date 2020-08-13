/* ******************************************************************
			    ZELDA64 SOUND FILES
			    AUDIO INCLUDERS
		    Created By Yoji Inagaki (NCL, EAD)
			    1998.10.16(FRI) 
   ****************************************************************** */
#include "gfxprint.h"
#include "audio_enemyflag.h"

/* ********************************************
	    sudio structures
   ******************************************** */

typedef struct
{
    u8 button;
    u8 status;
    u8 locate;
}
NA_OCARINA_PLAY_INFO;

typedef struct
{
    u8 max;
    u8 key[8];
}
NA_OCARINA_MELODY_DATA;



/* ********************************************
	    external labels & functions
   ******************************************** */

/* extern void	Nas_InitAudio(void); */
extern void	Na_AudioInit(void);
extern void	Nas_SetRomHandler( s32 (*dmaproc)(OSPiHandle *,OSIoMesg *,s32));
extern void	Na_ResetAudio(void);

#ifndef _NO_RSP_TASK_EXT_
extern void *Nas_AudioMain(void);
#endif
extern void Nas_AudioInput(void);
extern void Na_EntryMesVoice(u32);
extern void Na_StartSe(u8 *, u8 );
extern void Nai_InitInterface(void);
/* extern void Na_StopSeq(u8, u8); */
extern void Nai_SeqFlagEntry(u32);
extern u16 Nai_GetPlayingSeqFlag(u8);

#ifndef _AUDIO_GAME_PRINT_
extern void Na_AudioPrint(gfxprint_t *);
#endif

/* **** SE function **** */

extern void Nai_FxSetLockFlag(u16 _flag);
extern void Nai_FxFlagEntry(u16 , f32 * , u8 , f32 *, f32 *, s8 *);

extern void Nai_StopAllHandleFx(u8);
extern void Nai_StopAllObjHandleFx(u8, f32 *);
extern void Nai_StopAllObjHandleFx2(u8, f32 *);
extern void Nai_StopAllObjFx(f32 *);
extern void Nai_StopFx(u16);
extern void Nai_StopObjFlagFx(f32 *,u16 );
extern s8 Nai_FxFlagCheck(u16);

extern void Nai_SetSeqLineVolMove(u8, u8, u8, u8);


/* **** game sound function **** */

extern void Na_StartDemoSe(u8 );
extern void Na_StopAllSound(u16);
extern void Na_StartLinkWalkSe(f32 *, u16, f32);
extern void Na_SetLinkSliplevelSe(f32 *, u16, f32);
extern void Na_SetRiverSe(f32 *, f32);
extern void Na_SetWaterfallSe(f32 *, f32);
extern void Na_CheckRiverMovePitch(void);
extern void Na_InitPicthUpSe(void);
extern void Na_StartPicthUpSe(f32 *, u16, u8 *);
extern void Na_StartTransposeSe(f32 *, u16 , s8 );
extern void Na_CheckLevelMuteFlag(void);
extern void Na_SetLevelMuteFlag(u8);
extern void Na_SetMotorSe(f32 *, u16, f32);
extern void Na_StartInputPortSe(f32 *, u16 , u8 );
extern void Na_SetSwordChargeSe(f32 *, u8 );
extern void Na_SetMuteBgm(u8);
extern void Na_CheckContinueBgm(void);
extern s8 Na_SetTriggerMuteFlag(u8);
extern void Na_SetVolumeDistanceBgm(u8);
extern void Na_DemoOffFxFlagEntry(u16 , f32 * , u8 , f32 *, f32 *, s8 *);
extern void Na_SetMessageStatusFlag(s8);
extern void Na_SwapSeFlagOnDemo(u16 );
extern void Na_SetAutoTriggerSe(f32 *, u16 , f32 );
extern void Na_InitAutoTriggerSe(s8, s8);
extern void Na_SetForceBgmVol(u8 , u8 );
extern void Na_SetFishingRealSe(f32 );
extern void Na_CheckSariaMelodyTag(void);
extern void Na_SetRandomSeFlag(f32 *, u16 , u8 );
extern void Na_SetBlackLinkVoice(f32 *, u16 );


extern void Na_SetWindowSound(u8 );
extern void Na_StartFanfare(u16 );
extern void Na_StopAllBgm(u16);
/* extern void Na_StartNarration(u16); */
extern void Na_StartDemoBgm(u16);
extern void Na_StopDemoBgm(u16);
extern s8 Na_CheckPlayingBgm(u16);
extern void Na_StartBgmWithPortWrite(s8 , u16 , u8 , s8 , s8 );
extern void Na_StartMiddleBossBgm(u16 flag);
extern void Na_StopMiddleBossBgm(void);
extern void Na_StartContinueBgm(u16);
extern void Na_SetLinkDownSound(void);
extern void Na_ClearLinkDownSound(void);
extern void Na_StartForceNatureSound(u8 );
extern void Na_StopForceNatureSound(void);

extern s8 Na_CheckOcarina(u8 );
extern void Na_PlayOcarina(u8);
extern void Na_SetOcarinaModeFlag(u8);
/* extern void Na_SetOcarinaPlayCheckFlag(u8 ); */
extern void Na_SetOcarinaPlayCheckFlag2(u16 );

extern void Na_SetOcarinaSeq(s8, s8);
extern void Na_SetOcarinaRecModeFlag(u8 );
extern void Na_SetOcarinaKeyInputFlag(u8 );
extern u8 Na_GetOcarinaCheckStatus(void);
extern NA_OCARINA_PLAY_INFO *Na_GetOcarinaInfoWork(void);
extern NA_OCARINA_PLAY_INFO *Na_GetOcarinaSeqInfoWork(void);
extern NA_OCARINA_PLAY_INFO *Na_GetOcarinaRecInfoWork(void);
extern void Na_InitOcarinaGameWork(u8);
extern u8 Na_MakeOcarinaGameData(void);
extern void Na_AutoPlayUserOcarinaMelody(void);

extern void Na_ControlNaturalSound(u8, u8, u8 );
extern void Na_StartNaturalSound(u16, u16);

extern void Na_NscInitStart(u8 );

extern void Na_SetBgmPattern(u8 );
extern void Na_SetEnemyBgmDistance(f32 );
extern void Na_SetObjectBgmDistance(f32, u16);
extern void Na_SetBgmPitch(f32 , u8 );
extern void Na_StartWindmillBgm(void);
extern void Na_SetSariaMelodyTag(f32 *);
extern void Na_SetCrossBgmTag(f32 *, u16 , u16 );
extern void Na_ClearCrossBgmTag(void);
extern void Na_SetSariaMelodyTag2(f32 *, f32);
extern void Na_ClearSariaMelodyTag2(f32 *);
extern void Na_SetMiniGameBgmTempoUp(void);
extern void Na_StartMorinigBgm(u16);

extern void Na_SetEnvEcho(s8 );
extern void Na_SetAddEcho(s8 );
extern void Na_SetSoundOutputMode(s8 );
/* extern void Na_StopAllSound(s8 ); */
extern void Na_SetDirectFir(u8 );
extern void Na_SetWaterSeModeFlag(u8 );
extern void Na_StartFxmixSe(f32 *, u16 , s8 );
extern void Na_StartVolumeSetSe(f32 *, u16 , f32 );

extern void Na_ForceStopSound(void);
extern void Na_StopAllSound2(void);
extern void Na_RecoverSe(void);
s8 Na_CheckAllChannels(void);


/* ********************************************
	    external work
   ******************************************** */
/* **** SE work **** */

extern f32 _dummy_zero_f[3];
extern f32 _dummy_one;
extern u8 _dummy_zero_u8;
extern s8 _dummy_zero_s8;

extern NA_OCARINA_MELODY_DATA na_oca_note[];
extern u8 na_mofer_picth_up_table[];

extern u8 *na_oca_rec_buf_ptr;
extern u8 *na_oca_rec_buf2_ptr;
extern u8 *na_frog_tbl_ptr;


/* ********************************************
	    define se macro 
   ******************************************** */
/* #define Na_StartSystemSe(f)	Na_StartSe( (u8)(f>>28), (u8)(f & 0xff) ) */
#define Na_StartPlayerSe(p, f)	Nai_FxFlagEntry( f, p, 4, &_dummy_one, &_dummy_one, &_dummy_zero_s8)
#define Na_StartObjectSe(p, f)	Nai_FxFlagEntry( f, p, 4, &_dummy_one, &_dummy_one, &_dummy_zero_s8)
#define Na_StartSystemSe(f)	Nai_FxFlagEntry( f, _dummy_zero_f, 4, &_dummy_one, &_dummy_one, &_dummy_zero_s8)
#define Na_StartFixSe(f)	Nai_FxFlagEntry( f, _dummy_zero_f, 4, &_dummy_one, &_dummy_one, &_dummy_zero_s8)
/* #define Na_StartFixse(f)	Nai_FxFlagEntry( (u16)(f>>16)+(u16)(f & 0xff) , _dummy_zero_f, 4, &_dummy_one, &_dummy_one, &_dummy_zero_s8) */
#define Na_StartDemoOffSystemSe(f)	Na_DemoOffFxFlagEntry( f, _dummy_zero_f, 4, &_dummy_one, &_dummy_one, &_dummy_zero_s8)

#define Na_StopAllHandleSe(h)	Nai_StopAllHandleFx(h)
#define Na_StopAllObjHandleSe(h, p)	Nai_StopAllObjHandleFx(h, p)
#define Na_StopAllObjSe(p)	Nai_StopAllObjFx(p)
#define Na_StopObjFlagSe(p, f)	Nai_StopObjFlagFx(p, f)
#define Na_StopFlagSe(f)	Nai_StopFx(f)
#define Na_CheckPlayingSeFlag(f)	Nai_FxFlagCheck(f)

#define Na_StartOcarinaMode()	Na_SetOcarinaModeFlag(1)
#define Na_SetOcarinaInst(f)	Na_SetOcarinaModeFlag(f)
#define Na_StopOcarinaMode()	Na_SetOcarinaModeFlag(0)
#define Na_StartOcarinaFreePlay()	Na_SetOcarinaKeyInputFlag(1)
#define Na_StopOcarinaFreePlay()	Na_SetOcarinaKeyInputFlag(0)
/* #define	Na_StartOcarinaPlayCheck()  Na_SetOcarinaPlayCheckFlag(0xff) */
/* #define	Na_StartOcarinaSinglePlayCheck(n)  Na_SetOcarinaPlayCheckFlag((n)+1) */

#define	Na_StartOcarinaPlayCheck(f)  Na_SetOcarinaPlayCheckFlag2(f)
#define	Na_StartOcarinaSinglePlayCheck(n)  Na_SetOcarinaPlayCheckFlag2((0x01<<n)+0x8000)
#define	Na_StartOcarinaFreePlayCheck(f)  Na_SetOcarinaPlayCheckFlag2(f+0xc000)
#define	Na_StartOcarinaPlayCheck2(f)  Na_SetOcarinaPlayCheckFlag2(f)
#define	Na_StartOcarinaSinglePlayCheck2(n)  Na_SetOcarinaPlayCheckFlag2((0x01<<n)+0x8000)
#define	Na_StartOcarinaFreePlayCheck2(n)  Na_SetOcarinaPlayCheckFlag2((0x01<<n)+0xc000)
#define	Na_StartOcarinaSingleFreePlayCheck(n)  Na_SetOcarinaPlayCheckFlag2((0x01<<n)+0xc000)
#define	Na_StartOcarinaRecMode()    Na_SetOcarinaRecModeFlag(1)
#define	Na_StopOcarinaRecMode()	Na_SetOcarinaRecModeFlag(0)
#define	Na_StartOcarinaRecEightMode()    Na_SetOcarinaRecModeFlag(2)

#define	Na_StopOcarinaPlayCheck()   Na_SetOcarinaPlayCheckFlag2(NA_OCA_CHK_MODE_STOP)
#define Na_StartOcarinaSeq(n, t)    Na_SetOcarinaSeq((n)+1, t)
#define Na_StopOcarinaSeq()	    Na_SetOcarinaSeq(0, 1)

/* #define Na_SetWaterSeModeFlag(f)    Na_SetDirectFir(f)   */
#define Na_SetLinkInWaterFlag(f)    Na_SetDirectFir(f)
#define Na_InitMoferSwingSe()	    Na_InitPicthUpSe()
#define Na_StartMoferSwingSe(p)	    Na_StartPicthUpSe(p, NA_SE_EN_MOFER_WAVE, na_mofer_picth_up_table)
#define Na_StartFlySe(p, f, s)	    Na_SetMotorSe(p, f, 0.6f+(0.4f*s))
#define Na_StartBaliLevelSe(p, f, s)	    Na_SetMotorSe(p, f, 1.0f+(1.0f*s))
#define Na_SetTimerSe(s)	    Na_StartInputPortSe(_dummy_zero_f, NA_SE_SY_TIMER, s)
/* #define Na_SetShieldChargeSe(s)	    Na_StartInputPortSe(_dummy_zero_f, NA_SE_IT_SHIELD_CHARGE, s) */
#define Na_StartRodSe(p, f, s)	    Na_SetMotorSe(p, f, 0.75f+(0.25f*(s)))
#define Na_StartHeightSe(p, f, h)	    Na_SetMotorSe(p, f, (1.0f+h))

#define Na_SetDemoSceneFlag()	    Na_SetMessageStatusFlag(1)
#define Na_ClearDemoSceneFlag()	    Na_SetMessageStatusFlag(0)
#define Na_StartMessageWindowSe()   Na_SwapSeFlagOnDemo(NA_SE_SY_MESSAGE_WIN_OPEN)
#define Na_SetOcarinaMute()	    Nai_FxSetLockFlag(NA_SEHD_OCARINA_BIT)
#define Na_ClearOcarinaMute()	    Nai_FxSetLockFlag(0x0000)
#define Na_SetSeCancelFlagDemo()	    Nai_FxSetLockFlag(NA_SEHD_NOT_SYSTEM_BIT)
#define Na_SetSeCancelFlagFull()	    Nai_FxSetLockFlag(NA_SEHD_FULL_BIT)
#define Na_SetSystemSeCancelFlag()	    Nai_FxSetLockFlag(NA_SEHD_SYSTEM_BIT)
#define Na_ClearSeCancelFlagDemo()	    Nai_FxSetLockFlag(0x0000)
#define Na_InitFrogOcarinaGame()    Na_InitOcarinaGameWork(6);

#define Na_StartFrogSe(p, t)	    Na_StartTransposeSe(p, NA_SE_EV_FROG_JUMP, t)
#define Na_StartFiveLupySe(t)	    Na_StartTransposeSe(_dummy_zero_f, NA_SE_EV_FIVE_COUNT_LUPY, t)
#define Na_InitOwlFlutterSe()	    Na_InitAutoTriggerSe(20, 10)
#define Na_SetOwlFlutterSe(p, s)    Na_SetAutoTriggerSe(p, NA_SE_EN_OWL_FLUTTER, s)
#define Na_SetOwlFlySe(p, f, s)	    Na_SetMotorSe(p, f, s)
#define Na_SetFallDownSe(p, s)	    Na_SetMotorSe(p, NA_SE_EV_FLYING_AIR, s)
#define Na_InitFinshingReelSe()	    Na_InitAutoTriggerSe(8, 2);
#define Na_StartRandomSe2(p, f)	    Na_SetRandomSeFlag(p, f, 2);
#define Na_StartRandomSe3(p, f)	    Na_SetRandomSeFlag(p, f, 3);
#define Na_StartRandomSe4(p, f)	    Na_SetRandomSeFlag(p, f, 4);
#define Na_StartBigGoronSe(f)	    Na_StartFxmixSe(_dummy_zero_f, f, 60);
#define Na_StartNavyVoiceSingle(f)  Na_StartFxmixSe(_dummy_zero_f, f, 32);

/* ********************************************
	define sequence interface macro
   ******************************************** */

#define Na_SeqStart(h, f, t)		Nai_SeqFlagEntry(0x00000000 | ((u8)h << 24) | ((u8)(t) << 16) | (u16)f )
#define Na_SeqStop(h, t)		Nai_SeqFlagEntry(0x100000ff | ((u8)h << 24) | ((u8)(t) << 16) )
#define Na_SeqEntry(h, f, t)		Nai_SeqFlagEntry(0x20000000 | ((u8)h << 24) | ((u8)(t) << 16) | (u16)f )
#define Na_SeqFree(h, f)		Nai_SeqFlagEntry(0x30000000 | ((u8)h << 24) | (u16)f )
#define Na_SeqVolMove(h, v, t)		Nai_SeqFlagEntry(0x40000000 | ((u8)h << 24) | ((u8)(t) << 16) | (u8)v )
#define Na_SeqVolRecover(h, t)		Nai_SeqFlagEntry(0x4000007f | ((u8)h << 24) | ((u8)(t) << 16) )
#define Na_SeqTuneMove(h, p, t)		Nai_SeqFlagEntry(0x50000000 | ((u8)h << 24) | ((u8)(t) << 16) | (u16)p )
#define Na_SeqTuneRecover(h, t)		Nai_SeqFlagEntry(0x50000000 | ((u8)h << 24) | ((u8)(t) << 16) | 1000 )

#define Na_SeqSubEVolMove(h, s, v, t)	Nai_SeqFlagEntry(0x60000000 | ((u8)h << 24) | ((u8)(t) << 16) | ((u8)s << 8) | (u8)v )
#define Na_SeqPortWrite(h, p, d)	Nai_SeqFlagEntry(0x70000000 | ((u8)h << 24) | ((u8)p << 16) | (u8)d )
#define Na_SeqSubPortWrite(h, s, p, d)	Nai_SeqFlagEntry(0x80000000 | ((u8)h << 24) | ((u8)p << 16) | ((u8)s << 8) | (u8)d )
#define Na_SeqPortLockSet(h, b)		Nai_SeqFlagEntry(0x90000000 | ((u8)h << 24) | (u16)b )
#define Na_SeqSubMuteSet(h, b)		Nai_SeqFlagEntry(0xA0000000 | ((u8)h << 24) | (u16)b )
#define Na_SeqTempoChangeDirect(h, tp, t)	Nai_SeqFlagEntry(0xB0000000 | ((u8)h << 24) | ((u8)(t) << 16) | (u16)tp )
#define Na_SeqTempoChangeAdd(h, tp, t)	Nai_SeqFlagEntry(0xB0001000 | ((u8)h << 24) | ((u8)(t) << 16) | (u16)tp )
#define Na_SeqTempoChangeSub(h, tp, t)	Nai_SeqFlagEntry(0xB0002000 | ((u8)h << 24) | ((u8)(t) << 16) | (u16)tp )
#define Na_SeqTempoChangeMul(h, tp, t)	Nai_SeqFlagEntry(0xB0003000 | ((u8)h << 24) | ((u8)(t) << 16) | (u16)tp )
#define Na_SeqTempoChangeRecover(h, t)	Nai_SeqFlagEntry(0xB0004000 | ((u8)h << 24) | ((u8)(t) << 16) )

#define Na_SeqEndCheckSet(h, f)		Nai_SeqFlagEntry(0xC0000000 | ((u8)h << 24) | (u32) f )
#define Na_SeqSubTuneMove(h, s, p, t)		Nai_SeqFlagEntry(0xD0000000 | ((u8)h << 24) | ((u8)(t) << 16) | ((u8)s << 12) | (u16)p )
#define Na_SeqSubTuneRecover(h, s, t)		Nai_SeqFlagEntry(0xD0000000 | ((u8)h << 24) | ((u8)(t) << 16) | ((u8)s << 12) | 1000 )

#define Na_SeqECheck_SeqStart(h1, h2, f)	Nai_SeqFlagEntry(0xC0500000 | ((u8)h1 << 24) | ((u8)h2 << 16) | (u16) f )
#define Na_SeqECheck_TempoChangeMul(h1, h2, tpr, t)	Nai_SeqFlagEntry(0xC0300000 | ((u8)h1 << 24) | ((u8)h2 << 16) | ((u8)(t) << 8) | (u8) tpr )
#define Na_SeqECheck_MuteOff(h1, h2, t)	Nai_SeqFlagEntry(0xC0000000 | ((u8)h1 << 24) | ((u8)h2 << 16) | ((u8)(t) << 8))
#define Na_SeqECheck_RestSeqMuteOff(h1, h2, t, s)	Nai_SeqFlagEntry(0xC0700000 | ((u8)h1 << 24) | ((u8)h2 << 16) | ((u8)(t) << 8)| (u8)s)
#define Na_SeqECheck_SeqFree(h1)	Nai_SeqFlagEntry(0xC0100000 | ((u8)h1 << 24))
#define Na_SeqECheck_SeqRestart(h1, h2)	Nai_SeqFlagEntry(0xC0200000 | ((u8)h1 << 24) | ((u8)h2 << 16))
#define Na_SeqECheck_TempoChangeRecover(h1, h2, t)	Nai_SeqFlagEntry(0xC0400000 | ((u8)h1 << 24) | ((u8)h2 << 16) | ((u8)(t) << 8))
#define Na_SeqECheck_SeqTimerSet(h1, t)	Nai_SeqFlagEntry(0xC0600000 | ((u8)h1 << 24) | ((u8)(t) << 8) )
#define Na_SeqECheck_LineVolRecover(h1, h2, l, t)	Nai_SeqFlagEntry(0xC0800000 | ((u8)h1 << 24) | ((u8)h2 << 16) | ((u8)l << 8)| (u8)(t))
#define Na_SeqECheck_SubMuteSet(h1, h2, b)	Nai_SeqFlagEntry(0xC0900000 | ((u8)h1 << 24) | ((u8)h2 << 16) | (u16)b)
#define Na_SeqECheck_TuneMove(h1, h2, p, t)	Nai_SeqFlagEntry(0xC0a00000 | ((u8)h1 << 24) | ((u8)h2 << 16) | ((u8)t << 8) | (u8)p)
#define Na_SeqECheck_DeleteStay(h1, tp)	Nai_SeqFlagEntry(0xC0E00000 | ((u8)h1 << 24) | (u8)tp)
#define Na_SeqECheck_BufClear(h1)	Nai_SeqFlagEntry(0xC0F00000 | ((u8)h1 << 24))

#define Na_SetOutputMode(m)		Nai_SeqFlagEntry(0xe0000000 | (u8)m )
#define Na_BgmNonEntrySet(f)		Nai_SeqFlagEntry(0xe0000100 | (u16)f )
#define Na_SpecChange(s, n)		Nai_SeqFlagEntry(0xf0000000 | ((u8)s << 8)  | (u8)n )



/* ********************************************
	    define sequence game macro
   ******************************************** */

#define Na_StartBgm(n)		Na_SeqStart(BGM_GROUP_TRACK, n, 0)
#define Na_StartMixBgm(n)	Na_SeqStart(FAN_GROUP_TRACK, n, 0)
#define Na_StartExtraBgm(n)	Na_SeqStart(EXTRA_GROUP_TRACK, n, 0)
#define Na_StartSeq(s, n)	Na_SeqStart(s, n, 0)
#define Na_StopBgm(t)		Na_SeqStop(BGM_GROUP_TRACK, t)
#define Na_StopFanfare(t)	Na_SeqStop(FAN_GROUP_TRACK, t)
#define Na_StopExtraBgm(t)	Na_SeqStop(EXTRA_GROUP_TRACK, t)
#define Na_StopNarration()	Na_SeqStop(EXTRA_GROUP_TRACK, 0)
/* #define Na_StartMorinigBgm(n)	Na_StartBgmWithPortWrite(BGM_GROUP_TRACK, n, 0, 0, 1) */
#define Na_StartMapInitBgm(n)	Na_StartContinueBgm(n)
#define Na_StartIntroCutBgm(n)	Na_StartBgmWithPortWrite(BGM_GROUP_TRACK, n, 0, 7, 1)

/* #define Na_StartMiddleBossBgm(n)	Na_SeqEntry(BGM_GROUP_TRACK, NA_BGM_MIDDLE_BOSS, 0) */
/* #define Na_StopMiddleBossBgm(n)	Na_SeqFree(BGM_GROUP_TRACK, NA_BGM_MIDDLE_BOSS)	*/


#define Na_SetOutputMode(m)	Nai_SeqFlagEntry(0xe0000000 | (u8)m )
#define Na_SeqSubMuteSet(h, b)	Nai_SeqFlagEntry(0xA0000000 | ((u8)h << 24) | (u16)b )
#define	Na_ChangeSoundMode(m)	Na_SpecChange(0, m)
/* #define	Na_SetBgmPattern(f)	Na_SeqPortWrite(BGM_GROUP_TRACK, 2, f) */
#define	Na_ControlBgmVolume(v)	Nai_SetSeqLineVolMove(BGM_GROUP_TRACK, 0, v, 10)
#define	Na_SetMuteTag()		Na_SetLevelMuteFlag(NA_LV_MUTE_VOL)
#define	Na_SetMaronDistance(d)		Na_SetObjectBgmDistance(d, NA_BGM_RONRON)
#define	Na_SetMessageBgmMute()	    Na_SetMuteBgm(1);
#define	Na_ClearMessageBgmMute()    Na_SetMuteBgm(0);
#define Na_CheckPlayingBgmFlag()    Nai_GetPlayingSeqFlag(BGM_GROUP_TRACK)
#define Na_CheckPlayingFanfareFlag()    Nai_GetPlayingSeqFlag(FAN_GROUP_TRACK)
#define Na_SetSpeedUpBgm()	    Na_SetBgmPitch(1.18921f, 90)
#define Na_RecoverSpeedUpBgm()	    Na_SetBgmPitch(1.00f, 20)
#define Na_SetSariaBgmTag(p)	Na_SetCrossBgmTag(p, NA_BGM_MAYOIMORI, 1000)
#define Na_ClearSariaBgmTag()	Na_ClearCrossBgmTag()
#define Na_SetFairyBgmTag(p)	Na_SetCrossBgmTag(p, NA_BGM_GODESS, 800)

#define Na_StopDemoSe()		Na_SeqStop(DEMO_SE_GROUP_TRACK, 1)
#define Na_SetBgmVolumeZero()	Na_StartForceNatureSound(4)	/* Na_SetForceBgmVol(0, 5)  */
#define Na_ReturnBgmVolume()	Na_StopForceNatureSound()	/* Na_SetForceBgmVol(127, 5)	*/
#define Na_SetBgmVolumeDown(v)	Na_SetForceBgmVol(v, 5)
#define Na_RecoverBgmVolume()	Na_SetForceBgmVol(127, 5)
#define Na_StartMiniGameBgm(f)	Na_StartMiddleBossBgm(f)
#define Na_StopMiniGameBgm()	Na_StopMiddleBossBgm()
/*
#define Na_SetMiniGameBgmTempoUp()	Na_SeqTempoChangeDirect(BGM_GROUP_TRACK, 210, 5)
*/

/* ********************************************
	    natural sound control macro
   ******************************************** */
/* #define Na_NscInitStart(f)	    Na_StartNaturalSound((u16)(f>>16), (u16)(f & 0xffff)) */
#define Na_NscAllStop(t)	    Na_SeqStop(0, t)
#define Na_NscSetCtrlFlag(h, p)	    Na_ControlNaturalSound((u8)(h>>8), (u8)(h & 0xff), p)

#if 0
/* ********************************************
	    Groop Track Handle
   ******************************************** */

#define BGM_GROUP_TRACK		0
#define FAN_GROUP_TRACK		1
#define SE_GROUP_TRACK		2
#define VO_GROUP_TRACK		3
#endif

/* ********************************************
	    SE Handle
   ******************************************** */
#define SEHD_PLAYER	    0
#define SEHD_ITEM	    1
#define SEHD_ENVIRO	    2
#define SEHD_ENEMY	    3
#define SEHD_SYSTEM	    4
#define SEHD_OCARINA	    5
#define SEHD_VOICE	    6

#define NA_SEHD_PLAYER	    SEHD_PLAYER
#define NA_SEHD_ITEM	    SEHD_ITEM
#define NA_SEHD_ENVIRO	    SEHD_ENVIRO
#define NA_SEHD_ENEMY	    SEHD_ENEMY
#define NA_SEHD_SYSTEM	    SEHD_SYSTEM
#define NA_SEHD_OCARINA	    SEHD_OCARINA
#define NA_SEHD_VOICE	    SEHD_VOICE

#define NA_SEHD_PLAYER_BIT  0x0001
#define NA_SEHD_ITEM_BIT    0x0002
#define NA_SEHD_ENVIRO_BIT  0x0004
#define NA_SEHD_ENEMY_BIT   0x0008
#define NA_SEHD_SYSTEM_BIT  0x0010
#define NA_SEHD_OCARINA_BIT 0x0020
#define NA_SEHD_VOICE_BIT   0x0040

#define NA_SEHD_NOT_SYSTEM_BIT   0x006f
#define NA_SEHD_FULL_BIT    0x006f


/* ********************************************
	    Groop Track Handle
   ******************************************** */

#define BGM_GROUP_TRACK		0
#define FAN_GROUP_TRACK		1
#define SE_GROUP_TRACK		2
#define EXTRA_GROUP_TRACK	3
#define DEMO_SE_GROUP_TRACK	EXTRA_GROUP_TRACK

/* ********************************************
	    Sound Output Mode Label
   ******************************************** */
#define NA_SOUT_STEREO		0
#define NA_SOUT_MONO		3
#define NA_SOUT_HEADPHONE	1
#define NA_SOUT_3DWIDE		2


/* ********************************************
	    SE FLAG
   ******************************************** */


/*** PLAYER ***/

#define NA_CODE_GROUND		    0x0000
#define NA_CODE_SAND		    0x0001
#define NA_CODE_CONCRETE	    0x0002
#define NA_CODE_DIRT		    0x0003
#define NA_CODE_WATER0		    0x0004
#define NA_CODE_WATER1		    0x0005
#define NA_CODE_WATER2		    0x0006
#define NA_CODE_WEED		    0x0006
#define NA_CODE_MAGMA		    0x0007
#define NA_CODE_GRASS		    0x0008
#define NA_CODE_IRON		    0x0009
#define NA_CODE_CARPET		    0x0009
#define NA_CODE_GLASS		    0x000b
#define NA_CODE_BOARD		    0x000b
#define NA_CODE_WOOD		    0x000a
#define NA_CODE_HEAVYBOOTS	    0x000d
#define NA_CODE_ICE		    0x000f

#define NA_OFS_PL_ADULT		    0x80
#define NA_OFS_PL_KID		    0x00
#define NA_MASK_SE_PL		    0x7f

#define NA_SE_PL_TOSS		    0x0800
#define NA_SE_PL_HANG		    0x0800
#define NA_SE_PL_WALK		    0x0800
#define NA_SE_PL_WALK_GROUND	    0x0800
#define NA_SE_PL_WALK_SAND	    0x0801
#define NA_SE_PL_WALK_CONCRETE	    0x0802
#define NA_SE_PL_WALK_DIRT	    0x0803
#define NA_SE_PL_WALK_WATER0	    0x0804
#define NA_SE_PL_WALK_WATER1	    0x0805
#define NA_SE_PL_WALK_WATER2	    0x0806
#define NA_SE_PL_WALK_MAGMA	    0x0807
#define NA_SE_PL_WALK_GRASS	    0x0808
#define NA_SE_PL_WALK_IRON	    0x0809
#define NA_SE_PL_WALK_GLASS	    0x080b
#define NA_SE_PL_WALK_LADDER	    0x080a
#define NA_SE_PL_WALK_WOOD	    0x080b
#define NA_SE_PL_WALK_WALL	    0x080c
#define NA_SE_PL_WALK_HEAVYBOOTS    0x080d
#define NA_SE_PL_WALK_ICE	    0x080f

#define NA_SE_PL_JUMP		    0x0810
#define NA_SE_PL_JUMP_GROUND	    0x0810
#define NA_SE_PL_JUMP_SAND	    0x0811
#define NA_SE_PL_JUMP_CONCRETE	    0x0812
#define NA_SE_PL_JUMP_DIRT	    0x0813
#define NA_SE_PL_JUMP_WATER0	    0x0814
#define NA_SE_PL_JUMP_WATER1	    0x0815
#define NA_SE_PL_JUMP_WATER2	    0x0816
#define NA_SE_PL_JUMP_MAGMA	    0x0817
#define NA_SE_PL_JUMP_GRASS	    0x0818
#define NA_SE_PL_JUMP_IRON	    0x0819
#define NA_SE_PL_JUMP_GLASS	    0x081b
#define NA_SE_PL_JUMP_LADDER	    0x081a
#define NA_SE_PL_JUMP_WOOD	    0x081b
#define NA_SE_PL_JUMP_HEAVYBOOTS    0x081d
#define NA_SE_PL_JUMP_ICE	    0x081f

#define NA_SE_PL_LAND		    0x0820
#define NA_SE_PL_LAND_GROUND	    0x0820
#define NA_SE_PL_LAND_SAND	    0x0821
#define NA_SE_PL_LAND_CONCRETE	    0x0822
#define NA_SE_PL_LAND_DIRT	    0x0823
#define NA_SE_PL_LAND_WATER0	    0x0824
#define NA_SE_PL_LAND_WATER1	    0x0825
#define NA_SE_PL_LAND_WATER2	    0x0826
#define NA_SE_PL_LAND_MAGMA	    0x0827
#define NA_SE_PL_LAND_GRASS	    0x0828
#define NA_SE_PL_LAND_IRON	    0x0829
#define NA_SE_PL_LAND_GLASS	    0x082b
#define NA_SE_PL_LAND_LADDER	    0x082a
#define NA_SE_PL_LAND_WOOD	    0x082b
#define NA_SE_PL_LAND_HEAVYBOOTS    0x082d
#define NA_SE_PL_LAND_ICE	    0x082f

#define NA_SE_PL_SLIPDOWN	    0x0830
#define NA_SE_PL_SIT_ON_BED	    0x0830
#define NA_SE_PL_CLIMB_CLIFF	    0x0831
#define NA_SE_PL_RIDE_ON_HORSE	    0x0831
#define NA_SE_PL_SIT_ON_HORSE	    0x0832
#define NA_SE_PL_GET_OFF_HORSE	    0x0833
#define NA_SE_PL_TAKE_OUT_SHIELD    0x0834
#define NA_SE_PL_TAKE_OUT_BOW	    0x0834
#define NA_SE_PL_TAKE_OUT_BOMB	    0x0834
#define NA_SE_PL_TAKE_OUT_BOOMERANG 0x0834
#define NA_SE_PL_TAKE_OUT_HAMMER    0x0834
#define NA_SE_PL_TAKE_OUT_HOOKSHOT  0x0834

#define NA_SE_PL_CHANGE_ARMS	    0x0835
#define NA_SE_PL_PUT_BACK_SHIELD    0x0835
#define NA_SE_PL_PUT_BACK_BOW	    0x0835
#define NA_SE_PL_PUT_BACK_BOOMERANG 0x0835
#define NA_SE_PL_PUT_BACK_HAMMER    0x0835
#define NA_SE_PL_PUT_BACK_HOOKSHOT  0x0835
#define NA_SE_PL_CATCH_BOOMERANG    0x0836
#define NA_SE_PL_DIVE_INTO_WATER    NA_SE_EV_DIVE_INTO_WATER	/* 0x0837 */
#define NA_SE_PL_JUMP_OUT_WATER	    NA_SE_EV_JUMP_OUT_WATER	/* 0x0838 */
#define NA_SE_PL_SWIM		    0x0839
#define NA_SE_EV_SWIM		    0x0839
#define NA_SE_PL_THROW		    0x083a
#define NA_SE_PL_BODY_BOUND	    0x083b
#define NA_SE_PL_ROLL		    0x083c
#define NA_SE_PL_GROUND_ROLL	    0x083c
#define NA_SE_PL_SKIP		    0x083d
#define NA_SE_PL_MAGIC_MOTION_S	    0x083d
#define NA_SE_PL_JUMP_CUT	    0x083d
#define NA_SE_EN_FALL		    0x083d
#define NA_SE_PL_BODY_HIT	    0x083e
#define NA_SE_PL_ROLL_ATTACK_HIT    0x083e  /* 0x08c2 */
#define NA_SE_EV_GANON_BOUND_2	    NA_SE_PL_BODY_HIT
#define NA_SE_PL_DAMAGE		    0x083f

#define NA_SE_PL_SLIP		    0x0840
#define NA_SE_PL_SLIP_PP	    0x0840
#define NA_SE_PL_SLIP_GROUND	    0x0840
#define NA_SE_PL_SLIP_SAND	    0x0841
#define NA_SE_PL_SLIP_CONCRETE	    0x0842
#define NA_SE_PL_SLIP_DIRT	    0x0843
#define NA_SE_PL_SLIP_WATER0	    0x0844
#define NA_SE_PL_SLIP_WATER1	    0x0845
#define NA_SE_PL_SLIP_WATER2	    0x0846
#define NA_SE_PL_SLIP_MAGMA	    0x0847
#define NA_SE_PL_SLIP_GRASS	    0x0848
#define NA_SE_PL_SLIP_IRON	    0x0849
#define NA_SE_PL_SLIP_GLASS	    0x084b
#define NA_SE_PL_SLIP_LADDER	    0x084a
#define NA_SE_PL_SLIP_WOOD	    0x084b
#define NA_SE_PL_SLIP_HEAVYBOOTS    0x084d
#define NA_SE_PL_SLIP_ICE	    0x084f

#define NA_SE_PL_BOUND		    0x0850
#define NA_SE_PL_BOUND_GROUND	    0x0850
#define NA_SE_PL_BOUND_SAND	    0x0851
#define NA_SE_PL_BOUND_CONCRETE	    0x0852
#define NA_SE_PL_BOUND_DIRT	    0x0853
#define NA_SE_PL_BOUND_WATER0	    0x0854
#define NA_SE_PL_BOUND_WATER1	    0x0855
#define NA_SE_PL_BOUND_WATER2	    0x0856
#define NA_SE_PL_BOUND_MAGMA	    0x0857
#define NA_SE_PL_BOUND_GRASS	    0x0858
#define NA_SE_EV_BOUND_GRASS	    0x0858
#define NA_SE_PL_BOUND_IRON	    0x0859
#define NA_SE_PL_BOUND_GLASS	    0x085b
#define NA_SE_PL_BOUND_LADDER	    0x085a
#define NA_SE_PL_BOUND_WOOD	    0x085b
#define NA_SE_PL_BOUND_HEAVYBOOTS   0x085d
#define NA_SE_PL_BOUND_ICE	    0x085f

/* #define NA_SE_PL_MEATL_BOOTS_WALK   0x0860 */
/* #define NA_SE_PL_MEATL_BOOTS_JUMP   0x0861 */
/* #define NA_SE_PL_MEATL_BOOTS_LAND   0x0862 */

#define NA_SE_PL_FACE_UP	    0x0863
#define NA_SE_EV_FACE_UP	    NA_SE_PL_FACE_UP
#define NA_SE_PL_DIVE_BUBBLE	    0x0864
#define NA_SE_PL_MOVE_BUBBLE	    0x0865
#define NA_SE_PL_METALEFFECT_KID    0x0866
#define NA_SE_PL_METALEFFECT_ADULT  0x0867
#define NA_SE_PL_SPARK		    0x0068
#define NA_SE_PL_PULL_UP_PLANT	    0x0869
#define NA_SE_PL_PULL_UP_ROCK	    0x086a
#define NA_SE_PL_IN_BUBBLE	    0x086b
#define NA_SE_PL_PULL_UP_BIGROCK    0x086c

/* #define NA_SE_EV_OBJECT_BOUND	    0x086c  */
#define NA_SE_PL_SWORD_CHARGE	    0x086d
#define NA_SE_PL_FREEZE		    0x086e
#define NA_SE_PL_PULL_UP_POT	    0x086f
#define NA_SE_PL_KNOCK		    0x0870
#define NA_SE_PL_CALM_HIT	    0x0871
#define NA_SE_PL_BRUSH_OFF	    0x0871
#define NA_SE_PL_TROUSERS	    0x0871
#define NA_SE_PL_CALM_PAT	    0x0872
#define NA_SE_PL_SUBMERGE	    0x0873
#define NA_SE_EV_SUBMERGE	    0x0873
#define NA_SE_PL_FREEZE_S	    0x0874
#define NA_SE_EN_FREEZE_S	    0x0874
#define NA_SE_PL_ICE_BROKEN	    0x0875
#define NA_SE_EV_ICE_BROKEN_L	    0x0875
#define NA_SE_PL_SLIP_ICE_LELEL	    0x0076
#define NA_SE_PL_PUT_OUT_ITEM	    0x0877
#define NA_SE_PL_PULL_UP_WOODBOX    0x0878
#define NA_SE_PL_MAGIC_FIRE	    0x0879
#define NA_SE_PL_MAGIC_WIND_NORMAL  0x087a
#define NA_SE_PL_MAGIC_WIND_WARP    0x087b
#define NA_SE_PL_MAGIC_SOUL_NORMAL  0x007c
#define NA_SE_PL_ARROW_CHARGE_FIRE  0x007d
#define NA_SE_PL_ARROW_CHARGE_ICE   0x007e
#define NA_SE_PL_ARROW_CHARGE_LIGHT 0x007f

#define NA_SE_PL_PULL_UP_RUTO	    0x0883

#define NA_SE_PL_CRAWL		    0x08b0
#define NA_SE_PL_CRAWL_GROUND	    0x08b0
#define NA_SE_PL_CRAWL_SAND	    0x08b1
#define NA_SE_PL_CRAWL_CONCRETE	    0x08b2
#define NA_SE_PL_CRAWL_DIRT	    0x08b3
#define NA_SE_PL_CRAWL_WATER0	    0x08b4
#define NA_SE_PL_CRAWL_WOOD	    0x08bb
#define NA_SE_PL_CRAWL_ICE	    0x08bf

#define NA_SE_PL_MAGIC_SOUL_FLASH   0x00c0
#define NA_SE_PL_ROLL_DUST	    0x00c1

#define NA_SE_PL_MAGIC_SOUL_BALL    0x00c3
#define NA_SE_PL_SPIRAL_HEAL_BEAM   0x00c4
#define NA_SE_EV_SPIRAL_HEAL_BEAM   NA_SE_PL_SPIRAL_HEAL_BEAM
#define NA_SE_PL_BOUND_NOWEAPON	    0x08c5
#define NA_SE_EV_GANON_BOUND_1	    NA_SE_PL_BOUND_NOWEAPON
#define NA_SE_PL_PLANT_GROW_UP	    0x00c6
#define NA_SE_PL_PLANT_TALLER	    0x00c7
#define NA_SE_PL_PLANT_RISING	    0x00c7
#define NA_SE_PL_MAGIC_WIND_VANISH  0x08c8
#define NA_SE_PL_HOBBERBOOTS_LV     0x00c9
#define NA_SE_PL_PLANT_MOVE	    0x00ca
#define NA_SE_EV_WALL_MOVE_SP	    0x00cb
#define NA_SE_EV_BIG_POT_MOVE_SP    0x00cb

#define NA_SE_PL_SLIP_LEVEL	    0x00d0
#define NA_SE_PL_SLIP_PP_LEVEL	    0x00d0
#define NA_SE_PL_SLIP_GROUND_LEVEL  0x00d0
#define NA_SE_PL_SLIP_SAND_LEVEL    0x00d1
#define NA_SE_PL_SLIP_CONCRETE_LEVEL	0x00d2
#define NA_SE_PL_SLIP_DIRT_LEVEL    0x00d3
#define NA_SE_PL_SLIP_WATER0_LEVEL  0x00d4
#define NA_SE_PL_SLIP_WATER1_LEVEL  0x00d5
#define NA_SE_PL_SLIP_WATER2_LEVEL  0x00d6
#define NA_SE_PL_SLIP_MAGMA_LEVEL   0x00d7
#define NA_SE_PL_SLIP_GRASS_LEVEL   0x00d8
#define NA_SE_PL_SLIP_IRON_LEVEL    0x00d9
#define NA_SE_PL_SLIP_GLASS_LEVEL   0x00db
#define NA_SE_PL_SLIP_LADDER_LEVEL  0x00da
#define NA_SE_PL_SLIP_WOOD_LEVEL    0x00db
#define NA_SE_PL_SLIP_HEAVYBOOTS_LEVEL	0x00dd
#define NA_SE_PL_SLIP_ICE_LEVEL	    0x00df
#define NA_SE_EV_SLIP_ICE_LEVEL	    NA_SE_PL_SLIP_ICE_LEVEL


#define NA_SE_EV_PUT		    0x0800
#define NA_SE_EV_BOUND		    0x0800
#define NA_SE_EV_WALK		    0x0800
#define NA_SE_EV_LAND		    0x0800
#define NA_SE_EV_WALK_GROUND	    0x0800
#define NA_SE_EV_WALK_SAND	    0x0801
#define NA_SE_EV_WALK_CONCRETE	    0x0802
#define NA_SE_EV_WALK_DIRT	    0x0803
#define NA_SE_EV_WALK_WATER0	    0x0804
#define NA_SE_EV_WALK_WATER1	    0x0805
#define NA_SE_EV_WALK_WATER2	    0x0806
#define NA_SE_EV_WALK_MAGMA	    0x0807
#define NA_SE_EV_WALK_GRASS	    0x0808
#define NA_SE_EV_LAND_GRASS	    0x0808
#define NA_SE_EV_WALK_IRON	    0x0809
#define NA_SE_EV_WALK_GLASS	    0x080b
#define NA_SE_EV_WALK_LADDER	    0x080a
#define NA_SE_EV_WALK_WOOD	    0x080b
#define NA_SE_EV_WALK_WALL	    0x080c
#define NA_SE_EV_WALK_HEAVYBOOTS    0x080d
#define NA_SE_EV_WALK_ICE	    0x080f

/*** ITEM ***/

#define NA_SE_IT_SWORD_IMPACT	    0x1800
#define NA_SE_IT_SWORD_SWING	    0x1801
#define NA_SE_IT_BOTTLE_SWING	    0x1801
#define NA_SE_IT_SWORD_PUTAWAY	    0x1802
#define NA_SE_IT_SWORD_PICKOUT	    0x1803
#define NA_SE_IT_ARROW_SHOT	    0x1804
#define NA_SE_IT_BOOMERANG_THROW    0x1805
#define NA_SE_IT_SHIELD_BOUND	    0x1806
#define NA_SE_IT_SHIELD_REFLECT_EN  0x1806
#define NA_SE_IT_REFLECTION_STONE   0x1806
#define NA_SE_IT_BOW_DRAW	    0x1807
#define NA_SE_IT_SHIELD_REFLECT_SW  0x1808
#define NA_SE_IT_REFLECTION_STEEL   0x1808
#define NA_SE_IT_ARROW_STICK_HRAD   0x1809
#define NA_SE_IT_HAMMER_HIT	    0x180a
#define NA_SE_IT_HOOKSHOT_CHAIN	    0x100b
#define NA_SE_IT_SHIELD_REFLECT_MG  0x180c
#define NA_SE_IT_BOMB_IGNIT	    0x100d
#define NA_SE_IT_BOMB_EXPLOSION	    0x180e
#define NA_SE_EV_EXPLOSION_DEMO_S   0x180e
#define NA_SE_IT_BOMB_UNEXPLOSION   0x180f

#define NA_SE_IT_BOOMERANG_FLY	    0x1010
#define NA_SE_IT_SWORD_STRIKE	    0x1811
#define NA_SE_IT_HAMMER_SWING	    0x1812
#define NA_SE_EV_MEDAL_ROLLING	    0x1812
#define NA_SE_IT_SWORD_SWING_W	    0x1812
#define NA_SE_IT_HOOKSHOT_REFLECT   0x1813
#define NA_SE_IT_HOOKSHOT_STICK_CRE 0x1814
#define NA_SE_IT_ARROW_STICK_CRE    0x1814
/* #define NA_SE_IT_HOOKSHOT_STICK_OBJ 0x1815	*/
#define NA_SE_IT_ARROW_STICK_OBJ    0x1815
#define NA_SE_IT_SWORD_SLASH	    0x0000  /*0x1816 */
#define NA_SE_IT_SWORD_SLASH_HARD   0x0000  /*0x1817 */
#define NA_SE_IT_SWORD_SWING_HARD   0x1818
#define NA_SE_IT_JUMP_CUT_SWING	    0x1818
#define NA_SE_PL_MAGIC_MOTION_L	    NA_SE_IT_SWORD_SWING_HARD
/* #define NA_SE_IT_BOMB_BOUND	    0x1819  */
#define NA_SE_IT_WALL_HIT_HARD	    0x181a
#define NA_SE_IT_WALL_HIT_SOFT	    0x181b
#define NA_SE_IT_WALL_HIT_FRAGILE   0x181b
#define NA_SE_IT_STONE_HIT	    0x181c
#define NA_SE_IT_WOODSTICK_BROKEN   0x181d
#define NA_SE_IT_LASH		    0x181e
#define NA_SE_IT_SHIELD_POSTURE	    0x181f
#define NA_SE_IT_SHIELD_SWING	    0x181f

#define NA_SE_IT_SLING_SHOT	    0x1820
#define NA_SE_IT_SLING_DRAW	    0x1821
#define NA_SE_IT_SWORD_CHARGE	    0x1022
#define NA_SE_IT_ROLLING_CUT	    0x1823
#define NA_SE_IT_ROLLING_CUT_LV0    0x1823
#define NA_SE_IT_SWORD_STRIKE_HARD  0x1824
#define NA_SE_IT_SLING_REFLECT	    0x1825
#define NA_SE_IT_SHIELD_REMOVE	    0x1826
#define NA_SE_IT_HOOKSHOT_READY	    0x1827
#define NA_SE_IT_HOOKSHOT_RECEIVE   0x1828
#define NA_SE_IT_HOOKSHOT_STICK_OBJ 0x1829
#define NA_SE_IT_SWORD_REFLECT_MG   0x182a
#define NA_SE_IT_DEKU		    0x182b
#define NA_SE_IT_WALL_HIT_BUYO	    0x182c
#define NA_SE_IT_SWORD_PUTAWAY_STN  0x182d
#define NA_SE_IT_ROLLING_CUT_LV1    0x182e
#define NA_SE_IT_CHARGE_SHOT_LV1    0x182e
#define NA_SE_IT_ROLLING_CUT_LV2    0x182f
#define NA_SE_IT_CHARGE_SHOT_LV2    0x182f

#define NA_SE_IT_BOW_FLICK	    0x1830
#define NA_SE_IT_BOMBCHU_MOVE	    0x1031
#define NA_SE_IT_SHIELD_CHARGE_LV1  0x1032
#define NA_SE_IT_SHIELD_CHARGE_LV2  0x1033
#define NA_SE_IT_SHIELD_CHARGE_LV3  0x1034
#define NA_SE_IT_SLING_FLICK	    0x1835
#define NA_SE_IT_SWORD_STICK_STN    0x1836
#define NA_SE_IT_REFLECTION_WOOD    0x1837
#define NA_SE_IT_SHIELD_REFLECT_MG2 0x1838
#define NA_SE_IT_MAGIC_ARROW_SHOT   0x1839
#define NA_SE_IT_EXPLOSION_FRAME    0x183a
#define NA_SE_IT_EXPLOSION_ICE	    0x183b
#define NA_SE_EV_LIGHTNING_EXPLOSION 0x183b
#define NA_SE_IT_EXPLOSION_LIGHT    0x183c
#define NA_SE_IT_FISHING_REEL_SLOW  0x103d
#define NA_SE_IT_FISHING_REEL	    0x103d
#define NA_SE_IT_FISHING_REEL_HIGH  0x103e
#define NA_SE_IT_PULL_FISHING_ROD   0x183f



#define NA_SE_IT_WALL_HIT	    0x1830

#define NA_SE_IT_WALL_HIT	    0x1830
#define NA_SE_IT_WALL_HIT_GROUND    0x1830
#define NA_SE_IT_WALL_HIT_SAND	    0x1831
#define NA_SE_IT_WALL_HIT_CONCRETE  0x1832
#define NA_SE_IT_WALL_HIT_DIRT	    0x1833
#define NA_SE_IT_WALL_HIT_WATER0    0x1834
#define NA_SE_IT_WALL_HIT_WATER1    0x1835
#define NA_SE_IT_WALL_HIT_WATER2    0x1836
#define NA_SE_IT_WALL_HIT_MAGMA	    0x1837
#define NA_SE_IT_WALL_HIT_GRASS	    0x1838
#define NA_SE_IT_WALL_HIT_GLASS	    0x1839
#define NA_SE_IT_WALL_HIT_LADDER    0x183a
#define NA_SE_IT_WALL_HIT_WOOD	    0x183b


#define NA_SE_IT_DM_FLYING_GOD_PASS 0x1840
#define NA_SE_IT_DM_FLYING_GOD_DASH 0x1841
#define NA_SE_IT_DM_RING_EXPLOSION  0x1842
#define NA_SE_IT_DM_RING_GATHER	    0x1843
#define NA_SE_IT_INGO_HORSE_NEIGH   0x1844
#define NA_SE_IT_EARTHQUAKE	    0x1845
#define NA_SE_IT_ERUPTION	    0x1845

#define NA_SE_EV_FLYING_GOD_PASS    NA_SE_IT_DM_FLYING_GOD_PASS
#define NA_SE_EV_FLYING_GOD_DASH    NA_SE_IT_DM_FLYING_GOD_DASH
#define NA_SE_EV_RING_EXPLOSION	    NA_SE_IT_DM_RING_EXPLOSION
#define NA_SE_EV_GOD_UNION	    NA_SE_IT_DM_RING_EXPLOSION
#define NA_SE_EV_ENERGY_EXPLSION    NA_SE_IT_DM_RING_EXPLOSION
#define NA_SE_EV_RING_GATHER	    NA_SE_IT_DM_RING_GATHER
#define NA_SE_EV_INGO_HORSE_NEIGH   NA_SE_IT_INGO_HORSE_NEIGH
#define NA_SE_EV_EARTHQUAKE_S	    NA_SE_IT_EARTHQUAKE
#define NA_SE_EV_ERUPTION	    NA_SE_IT_ERUPTION

#define NA_SE_IT_KAKASHI_JUMP	    0x1847
#define NA_SE_EV_KAKASHI_JUMP	    NA_SE_IT_KAKASHI_JUMP
#define NA_SE_IT_FLAME		    0x1048
#define NA_SE_IT_SHIELD_BEAM	    0x1049
#define NA_SE_IT_FISHING_HIT	    0x184a
#define NA_SE_IT_GOODS_APPEAR	    0x184b
#define NA_SE_EV_GOODS_APPEAR	    NA_SE_IT_GOODS_APPEAR
#define NA_SE_IT_MAJIN_SWORD_BROKEN 0x184c
#define NA_SE_IT_HAND_CLAP	    0x184d
#define NA_SE_EV_HAND_CLAP	    NA_SE_IT_HAND_CLAP
#define NA_SE_IT_MASTER_SWORD_SWING 0x184e

#define NA_SE_IT_OCARINA_MELO_0	    0x1050
#define NA_SE_IT_OCARINA_MELO_1	    0x1051



/*** ENVIRONMENT ***/

#define NA_SE_EV_DOOR_OPEN	    0x5802	     /* 0x2800 */
#define NA_SE_EV_DOOR_CLOSE	    0x2801
#define NA_SE_EV_EXPLOSION	    0x2802
#define NA_SE_EV_FLOOR_EXPLOSION    0x2802
#define NA_SE_EV_VOLCNO_ROCK_BROKEN 0x2802
#define NA_SE_EV_HORSE_WALK	    0x2803
#define NA_SE_EV_HORSE_RUN	    0x2804
#define NA_SE_EV_HORSE_NEIGH	    0x2805
#define NA_SE_EV_RIVER_STREAM	    0x2006
#define NA_SE_EV_WATER_WALL_BIG	    0x2007
#define NA_SE_EV_OUT_OF_WATER	    0x2808
#define NA_SE_EV_OUT_OF_WATER_M	    0x2808
#define NA_SE_EV_DIVE_WATER	    0x2809
#define NA_SE_EV_ROCK_SLIDE	    0x200a
#define NA_SE_EV_STATUE_SLIDE	    0x200a
#define NA_SE_EV_MAGMA_LEVEL	    0x200b
#define NA_SE_EV_MAGMA_LEVEL_S	    0x200b
#define NA_SE_EV_BRIDGE_OPEN	    0x200c
#define NA_SE_EV_CHAINLIFT_DOWN	    0x200c
#define NA_SE_EV_BRIDGE_CLOSE	    0x200d
#define NA_SE_EV_CHINETRAP_UP	    0x200d
#define NA_SE_EV_BRIDGE_OPEN_STOP   0x280e
#define NA_SE_EV_BRIDGE_CLOSE_STOP  0x280f
#define NA_SE_EV_WALL_BROKEN	    0x2810
#define NA_SE_EV_ROCK_EXPLOSION	    0x2810
#define NA_SE_EV_BIG_ROCK_BROKEN    0x2810
#define NA_SE_EV_CHICKEN_CRY_N	    0x2811
#define NA_SE_EV_CHICKEN_CRY_A	    0x2812
#define NA_SE_EV_CHICKEN_CRY_M	    0x2813
#define NA_SE_EV_SLIDE_DOOR_OPEN    0x2814
#define NA_SE_EV_FOOT_SWITCH	    0x2815
#define NA_SE_EV_HORSE_GROAN	    0x2816
#define NA_SE_EV_BOMB_DROP_WATER    0x2817
#define NA_SE_EV_RUPY_DROP_WATER    0x2817
#define NA_SE_EV_DROP_WATER	    0x2817
#define NA_SE_EV_DIVE_INTO_WATER_M  0x2817
#define NA_SE_EV_WATER_BOUND	    0x2817
#define NA_SE_EV_FROG_INTO_WATER    0x2817
#define NA_SE_EV_HORSE_JUMP	    0x2818
#define NA_SE_EV_HORSE_LAND	    0x2819
#define NA_SE_EV_HORSE_SLIP	    0x281a
#define NA_SE_EV_FAIRY_DASH	    0x281b
#define NA_SE_EV_NAVY_DASH	    0x281b
#define NA_SE_EV_NAVY_DASH_L	    0x281b
#define NA_SE_EV_SLIDE_DOOR_CLOSE   0x281c
#define NA_SE_EV_STONE_BOUND	    0x281d
#define NA_SE_EV_STONE_STATUE_OPEN  0x201e
#define NA_SE_EV_STONEDOOR_MOVE	    0x201e
#define NA_SE_EV_TBOX_UNLOCK	    0x281f
#define NA_SE_EV_TBOX_OPEN	    0x2820
#define NA_SE_SY_TIMER		    0x2021
#define NA_SE_EV_FLAME_IGNITION     0x2822
#define NA_SE_EN_FLAME_IGNITION     0x2822
#define NA_SE_EV_SPEAR_HIT	    0x2823
#define NA_SE_EV_ELEVATOR_MOVE	    0x2024
#define NA_SE_EV_OBJECT_MOVE	    0x2024
#define NA_SE_EV_WALL_MOVE	    0x2024
#define NA_SE_EV_BIG_POT_MOVE	    0x2024
#define NA_SE_EV_PILLAR_MOVE	    0x2024

#define NA_SE_EV_WARP_HOLE	    0x2025
#define NA_SE_EV_LINK_WARP	    0x2826
#define NA_SE_EV_PILLAR_SINK	    0x2027
#define NA_SE_EV_WATER_WALL	    0x2028
#define NA_SE_EV_RIVER_STREAM_S	    0x2029
#define NA_SE_EV_RIVER_STREAM_F     0x202a
#define NA_SE_EV_HORSE_LAND2	    0x282b
#define NA_SE_EV_HORSE_SANDDUST	    0x282c
#define NA_SE_EV_LIGHTNING	    0x282e

#define NA_SE_EV_BOMB_BOUND	    0x282f
#define NA_SE_IT_BOMB_BOUND	    0x282f
#define NA_SE_EV_OBJECT_BOUND	    0x282f

#define NA_SE_EV_WATERDROP	    0x2030
#define NA_SE_EV_TORCH		    0x2031
#define NA_SE_EV_MAGMA_LEVEL_M	    0x2032
#define NA_SE_EV_FIRE_PILLAR	    0x2033
#define NA_SE_EV_STONE_CHARGE	    0x2033
#define NA_SE_EV_FIRE_PLATE	    0x2034

#define NA_SE_EV_BLOCK_BOUND	    0x2835
#define NA_SE_EV_STATUE_BOUND	    0x2835
#define NA_SE_EV_BLOCK_CLING	    0x2835
#define NA_SE_EV_ICE_BLOCK_BOUND    0x2835
#define NA_SE_EV_BIGBALL_BOUND	    0x2835
#define NA_SE_EV_METALDOOR_SLIDE    0x2036
#define NA_SE_EV_METALDOOR_STOP	    0x2837
#define NA_SE_EV_METALDOOR_BOUND    0x2837
#define NA_SE_EV_BLOCK_SHAKE	    0x2838
#define NA_SE_EV_BOX_BREAK	    0x2839
#define NA_SE_EV_OBJECT_BROKEN	    0x2839
#define NA_SE_EV_WOOD_LAUNCH	    0x2839
#define NA_SE_EV_HAMMER_SWITCH	    0x283a
#define NA_SE_EV_MAGMA_LEVEL_L	    0x203b
#define NA_SE_EV_SPEAR_FENCE	    0x283c
#define NA_SE_EV_GANON_HORSE_NEIGH  0x283d
#define NA_SE_EV_GANON_HORSE_GROAN  0x283e
#define NA_SE_EV_FANTOM_WARP_S	    0x283f
#define NA_SE_EV_FANTOM_WARP_L	    0x2040
#define NA_SE_EV_DESERT_WARPHOLE    0x2040
#define NA_SE_EV_FOUNTAIN	    0x2041
#define NA_SE_EV_WATER_PILLAR	    0x2041
#define NA_SE_EV_KID_HORSE_WALK	    0x2842
#define NA_SE_EV_KID_HORSE_RUN	    0x2843
#define NA_SE_EV_KID_HORSE_NEIGH    0x2844
#define NA_SE_EV_KID_HORSE_GROAN    0x2845
#define NA_SE_EV_WHITE_OUT	    0x2846
#define NA_SE_EV_S_STONE_FLASH	    0x2846
#define NA_SE_EV_LIGHT_GATHER	    0x2047
#define NA_SE_EV_GOD_LIGHTBALL_1    0x2047
#define NA_SE_EV_TREE_CUT	    0x2848
#define NA_SE_EV_VOLCANO	    0x2049
#define NA_SE_EV_GUILLOTINE_UP	    0x284a
/* #define NA_SE_EV_SPINE_TRAP_MOVE    0x284a	*/
#define NA_SE_EV_GUILLOTINE_BOUND   0x284b
#define NA_SE_EV_SPINE_TRAP_BOUND   0x284b
#define NA_SE_EV_ROLLCUTTER_MOTOR   0x204c
#define NA_SE_EV_CHINETRAP_DOWN	    0x204d
#define NA_SE_EV_PLANT_BROKEN	    0x284e
#define NA_SE_EV_SHIP_BELL	    0x204f
#define NA_SE_EV_FLUTTER_FLAG	    0x2050
#define NA_SE_EV_TRAP_BOUND	    0x2851
#define NA_SE_EV_ROCK_BROKEN	    0x2852
#define NA_SE_EV_ROCK_BOUND	    0x2852
#define NA_SE_EV_FANTOM_WARP_S2	    0x2853
#define NA_SE_EV_FANTOM_WARP_L2	    0x2054
#define NA_SE_EV_COFFIN_CAP_OPEN    0x2855
#define NA_SE_EV_COFFIN_CAP_BOUND   0x2856
#define NA_SE_EV_TRE_BOX_BOUND	    0x2856
#define NA_SE_EV_WIND_TRAP	    0x2057
#define NA_SE_EV_TRAP_OBJ_SLIDE	    0x2058
#define NA_SE_EV_LADDER_CLATTER	    0x2058
#define NA_SE_EV_METALDOOR_OPEN	    0x2859
#define NA_SE_EV_METALDOOR_CLOSE    0x285a
#define NA_SE_EV_BURN_OUT	    0x205b
#define NA_SE_EV_FIREBALL	    0x205b
#define NA_SE_EV_BLOCKSINK	    0x205c
#define NA_SE_EV_SHIPDOWN	    0x205c
#define NA_SE_EV_PLATE_SWING	    0x205c
#define NA_SE_EV_CROWD		    0x205d
#define NA_SE_EV_WATER_LEVEL_DOWN   0x205e
#define NA_SE_EV_WATER_LEVEL_UP     0x205e
#define NA_SE_EV_NAVY_VANISH	    0x285f
#define NA_SE_EV_LADDER_DOUND	    0x2860
#define NA_SE_EV_WEB_VIBRATION	    0x2861
#define NA_SE_EV_WEB_BROKEN	    0x2862
#define NA_SE_EV_ROLL_STAND	    0x2063
#define NA_SE_EV_BUYODOOR_OPEN	    0x2864
#define NA_SE_EV_BUYODOOR_CLOSE	    0x2865
#define NA_SE_EV_WOODDOOR_OPEN	    0x2866
#define NA_SE_EV_METALGATE_OPEN	    0x2067
#define NA_SE_IT_SCOOP_UP_WATER	    0x2868
#define NA_SE_EV_FISH_LEAP	    0x2869
/*#define NA_SE_EV_TARON_SLEEP	    0x286a  */
/*#define NA_SE_EV_TARON_SURPRISE	    0x286b */
#define NA_SE_EV_KAKASHI_SWING	    0x286a
#define NA_SE_EV_KAKASHI_ROLL	    0x286b
#define NA_SE_EV_BOTTLE_CAP_OPEN    0x286c
#define NA_SE_EV_JABJAB_BREATHE	    0x206d
#define NA_SE_EV_SPIRIT_STONE	    0x206e
#define NA_SE_EV_TRIFORCE_FLASH	    0x286f
#define NA_SE_EV_SUN_MARK_FLASH	    0x286f
#define NA_SE_EV_SWORD_SPARK	    0x286f
#define NA_SE_EV_FALL_DOWN_DIRT	    0x2870
#define NA_SE_EV_NAVY_FLY	    0x2071
#define NA_SE_EV_NAVY_CRASH	    0x2072
/* #define NA_SE_EV_NABALL_CRY	    0x2873  */
#define NA_SE_EV_WOOD_HIT	    0x2873
#define NA_SE_EV_SCOOPUP_WATER	    0x2074
#define NA_SE_EV_DROP_FALL	    0x2075
#define NA_SE_EV_WOOD_GEAR	    0x2076
#define NA_SE_EV_TREE_SWING	    0x2877
#define NA_SE_EV_HORSE_RUN_LEVEL    0x2078
#define NA_SE_EV_ELEVATOR_MOVE2	    0x2079
#define NA_SE_EV_ELEVATOR_STOP	    0x287a
#define NA_SE_EV_CHAINLIFT_STOP	    0x287a
#define NA_SE_EV_TRE_BOX_APPEAR	    0x287b
#define NA_SE_EV_CHAIN_KEY_UNLOCK   0x287c
#define NA_SE_EV_SPINE_TRAP_MOVE    0x287d
#define NA_SE_EV_HEALING	    0x207e
#define NA_SE_EV_GREAT_FAIRY_APPEAR 0x287f
#define NA_SE_EV_GREAT_FAIRY_VANISH 0x2880
#define NA_SE_EV_RED_EYE	    0x2881
#define NA_SE_EV_STAND_APPEAR	    0x2881
#define NA_SE_EV_ROLL_STAND_2	    0x2082
#define NA_SE_EV_LIFT_MOTOR	    0x2082
#define NA_SE_EV_STAND_SINK	    0x2082
#define NA_SE_EV_WALL_SLIDE	    0x2083
#define NA_SE_EV_TRE_BOX_FLASH	    0x2884
#define NA_SE_EV_WINDMILL_LEVEL	    0x2085
#define NA_SE_EV_GOTO_HEAVEN	    0x2086
#define NA_SE_EV_POT_BROKEN	    0x2887
#define NA_SE_PL_PUT_DOWN_POT	    0x2888
#define NA_SE_EV_DIVE_INTO_WATER    0x2889
#define NA_SE_EV_DIVE_INTO_WATER_H  0x2889
#define NA_SE_EV_JUMP_OUT_WATER	    0x288a
#define NA_SE_EV_OUT_OF_WATER_H	    0x288a
#define NA_SE_EV_GOD_FLYING	    0x208b
#define NA_SE_EV_TRIFORCE	    0x208c
#define NA_SE_EV_AURORA		    0x208d
#define NA_SE_EV_DEKU_DEATH	    0x288e
#define NA_SE_EV_BUYOSTAND_RISING   0x208f
#define NA_SE_EV_BUYOSTAND_FALL	    0x2090
#define NA_SE_EV_BUYOFLOOR_FALL	    0x2090
#define NA_SE_EV_BUYOSHUTTER_OPEN   0x2891
#define NA_SE_EV_BUYOSHUTTER_CLOSE  0x2892
#define NA_SE_EV_STONEDOOR_STOP	    0x2893
#define NA_SE_EV_WALL_STOP	    0x2893
#define NA_SE_EV_S_STONE_REVIVAL    0x2894
#define NA_SE_EV_MEDAL_APPEAR_S	    0x2095
#define NA_SE_EV_HUMAN_BOUND	    0x2896
#define NA_SE_EV_MEDAL_APPEAR_L	    0x2097
#define NA_SE_EV_EARTHQUAKE	    0x2098
#define NA_SE_EV_BREAKDOWN	    0x2098
#define NA_SE_EV_SHUT_BY_CRYSTAL    0x2899
#define NA_SE_EV_GOD_LIGHTBALL_2    0x209a
#define NA_SE_EV_ZELDA_LIGHTBALL    0x209a

#define NA_SE_EV_RUN_AROUND	    0x289b

#define NA_SE_EV_CONSENTRATION	    0x289c
#define NA_SE_EV_ERUPTION_CLOUD	    0x209c

#define NA_SE_EV_TIMETRIP_LIGHT	    0x209d
#define NA_SE_EV_ZELDA_BEAM	    0x209d

#define NA_SE_EV_BUYOSTAND_STOP_A   0x289e
#define NA_SE_EV_BUYOSTAND_STOP_U   0x289f
#define NA_SE_EV_BUYOFLOOR_STOP	    0x289f
#define NA_SE_EV_BOUND_ON_MAGMA	    0x289f
#define NA_SE_EV_OBJECT_FALL	    0x28a0
#define NA_SE_EV_JUMP_CONC	    0x28a1
#define NA_SE_EV_ICE_MELT	    0x28a2
#define NA_SE_EV_ICE_WALL_MELT	    0x28a2
#define NA_SE_EV_FIRE_PILLAR_S	    0x20a3
#define NA_SE_EV_BLOCK_RISING	    0x28a4
#define NA_SE_EV_NABALL_VANISH	    0x28a5
#define NA_SE_EV_SARIA_MELODY	    0x20a6
#define NA_SE_EV_LINK_WARP_IN	    0x28a6
#define NA_SE_EV_LINK_WARP_OUT	    0x28a7
#define NA_SE_EV_LINK_WARP_OUT_LV   0x20a7
#define NA_SE_EV_FROL_MAGIC	    0x28a7
#define NA_SE_EV_FIATY_HEAL	    0x20a8
#define NA_SE_EV_CHAIN_KEY_UNLOCK_B 0x28a9
#define NA_SE_EV_WOODBOX_BREAK	    0x28aa
#define NA_SE_EV_PUT_DOWN_WOODBOX   0x28ab
#define NA_SE_EV_LAND_DIRT	    0x28ac
#define NA_SE_EV_FLOOR_ROLLING	    0x20ad
#define NA_SE_EV_DOG_CRY_EVENING    0x28ae
#define NA_SE_EV_JABJAB_HICCUP	    0x28af
#define NA_SE_EV_NALE_MAGIC	    0x28b0
#define NA_SE_EV_STICK_SWING	    0x28b0
#define NA_SE_EV_FROG_JUMP	    0x28b1
#define NA_SE_EV_ICE_FREEZE	    0x20b2
#define NA_SE_EN_TWINROBA_GND_FREEZE	NA_SE_EV_ICE_FREEZE
#define NA_SE_EV_BURNING	    0x20b3
#define NA_SE_EV_FLAME_WALL	    0x20b3
#define NA_SE_EV_WOODPLATE_BOUND    0x28b4
#define NA_SE_EV_GORON_WATER_DROP   0x28b5
#define NA_SE_EV_JABJAB_GROAN	    0x28b6
#define NA_SE_EV_DARUMA_VANISH	    0x28b7
#define NA_SE_EV_BIGBALL_ROLL	    0x20b8
#define NA_SE_EV_GORON_ROLL	    0x20b8
#define NA_SE_EV_ELEVATOR_MOVE3	    0x20b9
#define NA_SE_EV_DIAMOND_SWITCH	    0x28ba
#define NA_SE_EV_FLAME_OF_FIRE	    0x20bb
#define NA_SE_EV_RAINBOW_SHOWER	    0x20bc
#define NA_SE_EV_RUPY_FALL	    0x20bc
#define NA_SE_EV_FLYING_AIR	    0x20bd
#define NA_SE_EV_PASS_AIR	    0x28be
#define NA_SE_EV_COME_UP_DEKU_JR    0x28bf
#define NA_SE_EV_COME_UP_KAKASHI    0x28bf
#define NA_SE_EV_SAND_STORM	    0x20c0
#define NA_SE_EV_TRIFORCE_MARK	    0x28c1
#define NA_SE_EV_GRAVE_EXPLOSION    0x28c2
#define NA_SE_EV_STAND_BROKEN	    0x28c2
#define NA_SE_EV_EXPLOSION_DEMO_L   0x28c2
#define NA_SE_EV_LURE_MOVE_W	    0x28c3
#define NA_SE_EV_LURE_MOVE	    0x28c3
#define NA_SE_EV_LURE_MOVE_S	    0x28c3
#define NA_SE_EV_POT_MOVE_START	    0x28c4
#define NA_SE_EV_DIVE_INTO_WATER_L  0x28c5
#define NA_SE_EV_FROG_OUT_WATER	    0x28c5
#define NA_SE_EV_OUT_OF_WATER_L	    0x28c6
#define NA_SE_EV_GANON_MANTLE	    0x28c7
#define NA_SE_EV_DIG_UP		    0x28c8
#define NA_SE_EV_WOOD_BOUND	    0x28c9
#define NA_SE_EV_WATER_BUBBLE	    0x20ca
#define NA_SE_EV_ICE_BROKEN	    0x28cb
#define NA_SE_EV_ICE_BROKEN_S	    0x28cb
#define NA_SE_EV_FROG_GROW_UP	    0x28cc

#define NA_SE_EV_WATER_CONVECTION   0x20cd
#define NA_SE_EV_GROUND_GATE_OPEN   0x28ce
#define NA_SE_EV_FACE_BREAKDOWN	    0x28cf

#define NA_SE_EV_FACE_EXPLOSION	    0x28d0
#define NA_SE_EV_FACE_CRUMBLE_SLOW  0x20d1
#define NA_SE_EV_ROUND_TRAP_MOVE    0x28d2
#define NA_SE_EV_HIT_SOUND	    0x28d3
#define NA_SE_EV_ICE_SWING	    0x28d4
#define NA_SE_EV_DOWN_TO_GROUND	    0x20d5
#define NA_SE_EV_KENJA_ENVIROMENT_0 0x20d6
#define NA_SE_EV_KENJA_ENVIROMENT_1 0x20d7
#define NA_SE_EV_SMALL_DOG_BARK	    0x28d8
#define NA_SE_EV_ZELDA_POWER	    0x28d9
#define NA_SE_EV_RAIN		    0x20da
#define NA_SE_EV_IRON_DOOR_OPEN	    0x28db
#define NA_SE_EV_IRON_DOOR_CLOSE    0x28dc
#define NA_SE_EV_WHIRLPOOL	    0x20dd
#define NA_SE_EV_TOWER_PARTS_BROKEN 0x20de
#define NA_SE_EV_COW_CRY	    0x28df
#define NA_SE_EV_METAL_BOX_BOUND    0x28e0
#define NA_SE_EV_ELECTRIC_EXPLOSION 0x28e1
#define NA_SE_EV_HEAVY_THROW	    0x28e2
#define NA_SE_PL_HEAVY_THROW	    NA_SE_EV_HEAVY_THROW
#define NA_SE_EV_FROG_CRY_0	    0x28e3
#define NA_SE_EV_FROG_CRY_1	    0x28e4
#define NA_SE_EV_COW_CRY_LV	    0x20e5
#define NA_SE_EV_RONRON_DOOR_CLOSE  0x28e6
#define NA_SE_EV_BUTTERFRY_TO_FAIRY 0x28e7
#define NA_SE_EV_FAIRY_APPEAR	    0x28e7
#define NA_SE_EV_FIVE_COUNT_LUPY    0x28e8
#define NA_SE_EV_STONE_GROW_UP	    0x28e9
#define NA_SE_EV_STONE_LAUNCH	    0x20ea
#define NA_SE_EV_STONE_ROLLING	    0x28eb
#define NA_SE_EV_TOGE_STICK_ROLLING 0x20ec
#define NA_SE_EV_TOWER_ENERGY	    0x20ed
#define NA_SE_EV_TOWER_BARRIER	    0x20ee
#define NA_SE_EV_CHIBI_WALK	    0x28ef
#define NA_SE_EV_KNIGHT_WALK	    0x28f0
#define NA_SE_EV_PILLAR_MOVE_STOP   0x28f1


#define NA_SE_EV_GRAVE_SPARK	    NA_SE_EN_BIRI_SPARK
#define NA_SE_EV_OCARINA_BMELO_0    0x2830
#define NA_SE_EV_OCARINA_BMELO_1    0x2831
#define NA_SE_EV_FROG_EAT	    NA_SE_EN_DODO_M_EAT
#define NA_SE_EV_CARPENTER_WALK	    NA_SE_EN_GOLON_WALK
#define NA_SE_EV_VOLCNO_ROCK_BOUND  NA_SE_EN_VALVAISA_ROCK


/*** SYSTEM ***/

#define NA_SE_SY_WIN_OPEN	    0x4800
#define NA_SE_SY_LANGUAGE_CHANGE    0x4800
#define NA_SE_SY_WIN_CLOSE	    0x4801
#define NA_SE_SY_CORRECT_CHIME	    0x4802
#define NA_SE_SY_GET_RUPY	    0x4803
#define NA_SE_SY_MESSAGE_WOMAN	    0x4804
#define NA_SE_SY_MESSAGE_MAN	    0x4805
#define NA_SE_SY_ERROR		    0x4806
#define NA_SE_SY_TRE_BOX_APPEAR	    0x4807
#define NA_SE_SY_HINT_CHIME	    0x4807
#define NA_SE_SY_CLEAR_CHIME	    0x4807
#define NA_SE_SY_DECIDE		    0x4808
#define NA_SE_SY_MESSAGE_DECIDE	    0x4808
#define NA_SE_SY_PUT_LETTER	    0x4808
#define NA_SE_SY_CURSOR		    0x4809
#define NA_SE_SY_CANCEL		    0x480a
#define NA_SE_SY_HP_RECOVER	    0x480b

#define NA_SE_SY_ATTENTION_ON	    0x480c
#define NA_SE_SY_ATTENTION_NORMAL   0x480c
#define NA_SE_SY_ATTENTION_OFF	    0x0000	/*0x480d */
#define NA_SE_SY_LOCK_ON	    0x4830	/*0x480e */
#define NA_SE_SY_LOCK_ON_ENEMY	    0x4830	/*0x480e */
#define NA_SE_SY_LOCK_OFF	    0x480f
#define NA_SE_SY_LOCK_ON_HUMAN	    0x4810

#define NA_SE_SY_CAMERA_ZOOM_UP	    0x4813
#define NA_SE_SY_MAP_DISPLAY_OFF    0x4813
#define NA_SE_SY_CAMERA_ZOOM_DOWN   0x4814
#define NA_SE_SY_MAP_DISPLAY_ON	    0x4814

#define NA_SE_SY_MESSAGE_PAUSE	    0x0000	/* 0x4817 */
#define NA_SE_SY_MESSAGE_PASS	    0x4818
#define NA_SE_SY_WARNING_COUNT_N    0x4819
#define NA_SE_SY_COUNT_DOWN_1	    0x4819
#define NA_SE_SY_WARNING_COUNT_E    0x481a
#define NA_SE_SY_COUNT_DOWN_0	    0x481a
#define NA_SE_SY_HITPOINT_ALARM	    0x481b
#define NA_SE_SY_DEMO_CUT	    0x481d
#define NA_SE_SY_NAVY_CALL	    0x481e
#define NA_SE_SY_GAUGE_UP	    0x401f

#define NA_SE_SY_ATTENTION_ON_OLD   0x4817
#define NA_SE_SY_ATTENTION_URGENCY  0x4837	/* 0x4817 */
#define NA_SE_SY_ATTENTION_ON_TIMP  0x4818

#define NA_SE_SY_MESSAGE_WIN_OPEN   0x0000	/* 0x4820 */
#define NA_SE_SY_MESSAGE_WIN_CLOSE  0x0000	/* 0x4821 */
#define NA_SE_SY_MESSAGE_NEUTRAL    0x0000	/* 0x4822 */
#define NA_SE_SY_PIECE_OF_HEART	    0x4823
#define NA_SE_SY_GET_ITEM	    0x4824
#define NA_SE_SY_WIN_SCROLL_LEFT    0x4825
#define NA_SE_SY_WIN_SCROLL_RIGHT   0x4826
#define NA_SE_SY_OCARINA_ERROR	    0x4827
#define NA_SE_SY_CAMERA_ZOOM_UP_2   0x4828
#define NA_SE_SY_CAMERA_ZOOM_DOWN_2 0x4829
#define NA_SE_SY_GLASSMODE_ON	    0x482a
#define NA_SE_SY_GLASSMODE_OFF	    0x482b
#define NA_SE_SY_FOUND		    0x482c
#define NA_SE_SY_ALARM		    0x482c
#define NA_SE_SY_HIT_SOUND	    0x482d

#define NA_SE_SY_MESSAGE_END 	    0x482e
#define NA_SE_SY_RUPY_COUNT	    0x482f
#define NA_SE_SY_GET_BOXITEM	    0x4831

#define NA_SE_SY_WHITE_OUT_L	    0x4832
#define NA_SE_SY_WHITE_OUT_S	    0x4833
#define NA_SE_SY_WHITE_OUT_T	    0x4834
#define NA_SE_SY_KENJA_APPEAR	    0x4834
#define NA_SE_SY_START_SHOT	    0x4835
#define NA_SE_SY_GOAL_SHOT	    0x4835
#define NA_SE_SY_METRONOME	    0x4836
#define NA_SE_SY_METRONOME_LV	    0x4038

#define NA_SE_SY_ATTENTION_BASIC    0x480c
#define NA_SE_SY_ATTENTION_DUNGEON  0x4837
#define NA_SE_SY_FSEL_CURSOR	    0x4839
#define NA_SE_SY_FSEL_DECIDE_S	    0x483a
#define NA_SE_SY_FSEL_DECIDE_L	    0x483b
#define NA_SE_SY_FSEL_CLOSE	    0x483c
#define NA_SE_SY_FSEL_CANCEL	    0x483c
#define NA_SE_SY_FSEL_ERROR	    0x483d
#define NA_SE_SY_SET_FIRE_ARROW	    0x483e
#define NA_SE_SY_SET_ICE_ARROW	    0x483f
#define NA_SE_SY_SET_LIGHT_ARROW    0x4840
#define NA_SE_SY_SYNTH_MAGIC_ARROW  0x4841
#define NA_SE_SY_METRONOME_2	    0x4842
#define NA_SE_SY_KINSTA_MARK_APPEAR 0x4843
#define NA_SE_SY_FIVE_COUNT_LUPY    0x4844
#define NA_SE_SY_CARROT_RECOVER     0x4845
#define NA_SE_EV_FAIVE_LUPY_COUNT	    0x4846

/*** OCARINA ***/

#define NA_SE_OC_OCARINA	    0x5800
#define NA_SE_OC_ABYSS		    0x5801
#define NA_SE_SY_ABYSS		    NA_SE_OC_ABYSS
#define NA_SE_SY_FSEL_ERASE	    NA_SE_OC_ABYSS
#define NA_SE_OC_DOOR_OPEN	    0x5802
#define NA_SE_OC_SECRET_WARP_IN	    0x5803
#define NA_SE_EV_SECRET_WARP_IN	    NA_SE_OC_SECRET_WARP_IN
#define NA_SE_OC_SECRET_WARP_OUT    0x5804
#define NA_SE_EV_SECRET_WARP_OUT    NA_SE_OC_SECRET_WARP_OUT
#define NA_SE_OC_SECRET_HOLE_OUT    0x5805
#define NA_SE_EV_SECRET_HOLE_OUT    NA_SE_OC_SECRET_HOLE_OUT
#define NA_SE_OC_REVENGE	    0x5806
#define NA_SE_SY_REVENGE	    NA_SE_OC_REVENGE

/*** VOICE ***/

#define NA_OFS_VO_LI_ADULT	    0x00	    
#define NA_OFS_VO_LI_KID	    0x20

#define NA_SE_VO_LI_SWORD_N	    0x6800
#define NA_SE_VO_LI_BACKROLLING	    0x6800
#define NA_SE_VO_LI_JUMP	    0x6800
#define NA_SE_VO_LI_JUMP_CUT	    0x6800
#define NA_SE_VO_LI_SHOT	    0x6800
#define NA_SE_VO_LI_THROW	    0x6800
#define NA_SE_VO_LI_CATCH	    0x6800
#define NA_SE_VO_LI_SWORD_W2	    0x6800
#define NA_SE_VO_LI_GROUND_ROLL	    0x6800

#define NA_SE_VO_LI_SWORD_L	    0x6801
#define NA_SE_VO_LI_ROLLING_CUT	    0x6801
#define NA_SE_VO_LI_LIFT_UP	    0x6801

#define NA_SE_VO_LI_LASH	    0x6802
#define NA_SE_VO_LI_HOOKSHOT_JUMP   0x6802
#define NA_SE_VO_LI_HANG	    0x6803
#define NA_SE_VO_LI_CLIMB_END	    0x6804
#define NA_SE_VO_LI_LOOK_TRE	    0x6804
#define NA_SE_VO_LI_PULL_OUT_SWORD  0x6804
#define NA_SE_VO_LI_DIVE_WATER	    0x6804
#define NA_SE_VO_LI_ROLL_ATTACK_HIT 0x6804
#define NA_SE_VO_LI_CLIMB_UP	    0x6804	    /*0x6814  /* 0x6815  0x6803	*/
#define NA_SE_VO_LI_LAND_NO_DAMAGE  0x6804

#define NA_SE_VO_LI_DAMAGE_S	    0x6805
#define NA_SE_VO_LI_CAUGHT	    0x6805
#define NA_SE_VO_LI_UNABLE_TO_LIFT  0x6805
#define NA_SE_VO_LI_FREEZE	    0x6806
#define NA_SE_VO_LI_BOUND_DAMAGE    0x6806
#define NA_SE_VO_LI_MOFER_SWING	    0x6806
#define NA_SE_VO_LI_FALL_S	    0x6807
#define NA_SE_VO_LI_FALL_INTO_HOLE  0x6807
#define NA_SE_VO_LI_FALL_L	    0x6808
#define NA_SE_VO_LI_DAMAGE_L	    0x6808  /* 0x6806 */
#define NA_SE_VO_LI_TAKE_AWAY	    0x6808
#define NA_SE_VO_LI_BURN	    0x6808
#define NA_SE_VO_LI_BREATH_REST	    0x6809
#define NA_SE_VO_LI_BREATH_WILD	    0x6809
#define NA_SE_VO_LI_BREATH_DRINK    0x680a
#define NA_SE_VO_LI_FACE_UP	    0x680a
#define NA_SE_VO_LI_DOWN	    0x680b
#define NA_SE_VO_LI_TAKEN_AWAY	    0x680c
#define NA_SE_VO_LI_ELECTRIC_SHOCK  0x680c
#define NA_SE_VO_LI_ELECTRIC_SHOCK_LV  0x600c
#define NA_SE_VO_LI_CRY		    0x680c
#define NA_SE_VO_LI_NIGHTMARE	    0x680c
#define NA_SE_VO_LI_HELD	    0x680d
#define NA_SE_VO_LI_SNEEZE	    0x680e
#define NA_SE_VO_LI_SWEAT	    0x680f
#define NA_SE_VO_LI_DRINK	    0x6010
#define NA_SE_VO_LI_RELAX	    0x6811
#define NA_SE_VO_LI_WAKEUP	    0x6811
#define NA_SE_VO_LI_SWORD_PUTAWAY   0x6812
#define NA_SE_VO_LI_SWORD_PICKOUT   0x6812
#define NA_SE_VO_LI_GROAN	    0x6813
#define NA_SE_VO_LI_AUTO_JUMP	    0x6814
#define NA_SE_VO_LI_LADDER_JUMP	    0x6814
#define NA_SE_VO_LI_SCOOP_UP	    0x6814
#define NA_SE_VO_LI_OPEN_TRE	    0x6814
#define NA_SE_VO_LI_BOTTLE_CAP_OPEN 0x6814
#define NA_SE_VO_LI_FOOTHOLD_JUMP   0x6814
#define NA_SE_VO_LI_SWORD_W1	    0x6814
#define NA_SE_VO_LI_MAGIC_NALE	    0x6815
#define NA_SE_VO_LI_SURPRISE	    0x6816
#define NA_SE_VO_LI_MAGIC_FROL	    0x6817
#define NA_SE_VO_LI_PUSH	    0x6818
#define NA_SE_VO_LI_PULL	    0x6818
#define NA_SE_VO_LI_HOOKSHOT_HANG   0x6819

#define NA_SE_VO_LI_LAND_DAMAGE_S   0x681a	/*  0x6805  */
#define NA_SE_VO_LI_LAND_DAMAGE_L   0x681a	/*  0x6806  */
#define NA_SE_VO_LI_MAGIC_START	    0x6800	/*  0x681b  */
#define NA_SE_VO_LI_MAGIC_ATTACK    0x681c	/*  0x6801  */
#define NA_SE_VO_LI_MAGIC_DIN	    0x681c	/*  0x6815  */
#define NA_SE_VO_BL_DOWN	    0x681d	/*  0x6808  */
#define NA_SE_VO_LI_DEMO_DAMAGE	    0x681e
#define NA_SE_VO_LI_DURN_S	    0x681e

#define NA_SE_VO_TA_SLEEP	    0x6850
#define NA_SE_EV_TARON_SLEEP	    NA_SE_VO_TA_SLEEP
#define NA_SE_VO_TA_SURPRISE	    0x6851
#define NA_SE_EV_TARON_SURPRISE	    NA_SE_VO_TA_SURPRISE
#define NA_SE_VO_TA_CRY_0	    0x6852
#define NA_SE_VO_TA_CRY_1	    0x6853

#define NA_SE_VO_IN_CRY_0	    0x6854
#define NA_SE_VO_IN_LOST	    0x6855
#define NA_SE_VO_IN_LASH_0	    0x6856
#define NA_SE_VO_IN_LASH_1	    0x6857
#define NA_SE_VO_IN_LAUGH	    0x687c
#define NA_SE_VO_NP_MAN_LAUGH_0	    0x687c

#define NA_SE_VO_FR_LAUGH_0	    0x6858
#define NA_SE_VO_FR_SMILE_0	    0x6859

#define NA_SE_VO_NB_AGONY	    0x685a
#define NA_SE_VO_NB_CRY_0	    0x685b
#define NA_SE_EV_NABALL_CRY	    0x685b
#define NA_SE_VO_NB_NOTICE	    0x685c
#define NA_SE_VO_NB_LAUGH	    0x687b
#define NA_SE_VO_NP_WOMAN_LAUGH_0   0x687b

#define NA_SE_VO_NA_HELLO_0	    0x685d
#define NA_SE_VO_NA_HELLO_1	    0x685e
#define NA_SE_VO_NA_HELLO_2	    0x685f
#define NA_SE_VO_NA_HELLO_3	    0x6844  /* 0x687b */

#define NA_SE_VO_RT_CRASH	    0x6860
#define NA_SE_VO_RT_DISCOVER	    0x6861
#define NA_SE_VO_RT_FALL	    0x6862
#define NA_SE_VO_RT_LAUGH_0	    0x6863
#define NA_SE_VO_RT_LIFT	    0x6864
#define NA_SE_VO_RT_THROW	    0x6865
#define NA_SE_VO_RT_UNBALLANCE	    0x6866

#define NA_SE_VO_ST_DAMAGE	    0x6867
#define NA_SE_VO_ST_ATTACK	    0x6868

#define NA_SE_VO_Z0_HURRY	    0x6869
#define NA_SE_VO_Z0_MEET	    0x686a
#define NA_SE_VO_Z0_QUESTION	    0x686b
#define NA_SE_VO_Z0_SIGH_0	    0x686c
#define NA_SE_VO_Z0_SMILE_0	    0x686d
#define NA_SE_VO_Z0_SURPRISE	    0x686e
#define NA_SE_VO_Z0_THROW	    0x686f

#define NA_SE_VO_SK_CRY_0	    0x6870
#define NA_SE_VO_SK_CRY_1	    0x6871
#define NA_SE_VO_SK_CRASH	    0x6872
#define NA_SE_VO_SK_LAUGH	    0x6873
#define NA_SE_VO_NA_LISTEN	    0x6873

#define NA_SE_VO_SK_SHOUT	    0x6874

#define NA_SE_VO_Z1_CRY_0	    0x6875
#define NA_SE_VO_Z1_CRY_LINK_DAMAGE 0x6875
#define NA_SE_VO_Z1_CRY_1	    0x6876
#define NA_SE_VO_Z1_OPENDOOR	    0x6877
#define NA_SE_VO_Z1_SURPRISE	    0x6878
#define NA_SE_VO_Z1_PAIN	    0x6879

#define NA_SE_VO_KZ_MOVE	    0x687a


#define NA_SE_VO_FAIRY_HELLO	    0x6841
#define NA_SE_VO_FAIRY_HEAR	    0x6842
#define NA_SE_VO_FAIRY_ENEMY	    0x6840

#define NA_SE_VO_NAVY_HELLO	    0x6841
#define NA_SE_VO_NAVY_HEAR	    0x6842
#define NA_SE_VO_NAVY_ENEMY	    0x6840

#define NA_SE_VO_NAVY_CALL	    0x6843

#define NA_SE_VO_NARRATION_0	    0x6850

/* ********************************************
	    DEMO SPECIAL SEQUENCE SE
   ******************************************** */

#define NA_DEMO_SE_TIMETRIP	    0x00
#define NA_DEMO_SE_SEEK_TRANSFORM   0x01
#define NA_DEMO_SE_RUN_AROUND	    0x02
#define NA_DEMO_SE_FROL_MAGIC	    0x03
#define NA_DEMO_SE_NALE_MAGIC	    0x04
#define NA_DEMO_SE_RING_GATHER	    0x05
#define NA_DEMO_SE_DARK_CLOWD	    0x06
#define NA_DEMO_SE_KNOCK_DOWN	    0x07
#define NA_DEMO_SE_SHADEST_MOVE	    0x08
#define NA_DEMO_SE_SHADEST_APPEAR   0x09
#define NA_DEMO_SE_HIGH_SPEED_CAMERA   0x0a
#define NA_DEMO_SE_ENERGY_LINE_VANISH   0x0b
#define NA_DEMO_SE_BARRIER_BROKEN   0x0c
#define NA_DEMO_SE_TOWER_SINK	    0x0d
#define NA_DEMO_SE_LINK_NIGHTMARE   0x0e
#define NA_DEMO_SE_FUSHADEMO	    0x0f


/* ********************************************
	    NATURAL SOUND INIT FLAG
   ******************************************** */

#define NA_NS_INIT_SPOT00	    0x00
#define NA_NS_INIT_SPOT01	    0x01
#define NA_NS_INIT_SPOT02	    0x02
#define NA_NS_INIT_SPOT03	    0x03
#define NA_NS_INIT_SPOT04	    0x04
#define NA_NS_INIT_SPOT05	    0x05
#define NA_NS_INIT_SPOT06	    0x06
#define NA_NS_INIT_SPOT07	    0x07
#define NA_NS_INIT_SPOT08	    0x08
#define NA_NS_INIT_SPOT09	    0x09
#define NA_NS_INIT_SPOT10	    0x0a
#define NA_NS_INIT_SPOT11	    0x0b
#define NA_NS_INIT_SPOT12	    0x0c
#define NA_NS_INIT_SPOT13	    0x0d
#define NA_NS_INIT_SPOT14	    0x0e
#define NA_NS_INIT_SPOT15	    0x0f
#define NA_NS_INIT_SPOT16	    0x10
#define NA_NS_INIT_SPOT17	    0x11
#define NA_NS_INIT_SPOT18	    0x12
#define NA_NS_INIT_SPOT19	    0x13


#define NA_NS_INIT_FIELD	    0x00
#define NA_NS_INIT_GERUDO	    0x0a
#define NA_NS_INIT_SAND		    0x0b
#define NA_NS_INIT_MOUNTAIN	    0x0c
#define NA_NS_INIT_TOWN		    0x01
#define NA_NS_INIT_GRAVEYARD	    0x02
#define NA_NS_INIT_FOREST	    0x04
#define NA_NS_INIT_RAINHOUSE	    0x05
#define NA_NS_INIT_FISHING_SPOT	    0x06
#define NA_NS_INIT_LAST_GANON	    0x07

#define NA_NS_INIT_DEMO00	    0x02    /* THUNDER & RAIN */
#define NA_NS_INIT_DEMO01	    0x03    /* THUNDER & RAIN & STORM */


/* ********************************************
	    NATURAL SOUND CONTROL FLAG
   ******************************************** */
#define NA_NS_TRIG_THUNDER	    0x0f01
#define NA_NS_TRIG_LIGHTNING	    0x0f00
#define NA_NS_TRIG_RAIN		    0x0e01
#define NA_NS_TRIG_WIND		    0x0c01
#define NA_NS_TRIG_EVENINGBIRD	    0x0101
#define NA_NS_TRIG_NIGHTCREATURE    0x2401
#define NA_NS_TRIG_MORNINGBIRD	    0x5601

#define NA_NS_TRIG_EVENING	    0x0101
#define NA_NS_TRIG_NIGHTE	    0x2401
#define NA_NS_TRIG_NIGHT	    0x2401
#define NA_NS_TRIG_MORNING	    0x5601




#define NA_NS_VARI_WIND		    0x0c02

#define NA_NS_DIST_THUNDER	    0x0f05

#define NA_NS_POWR_RAIN		    0x0e04
#define NA_NS_POWR_WIND		    0x0c04

#define NA_NS_CTRL_START	    0x01
#define NA_NS_CTRL_STOP		    0x00
#define NA_NS_CTRL_TRIGGER	    0x00

#define NA_NS_CTRL_BREAZE	    0x00
#define NA_NS_CTRL_STORM	    0x01
#define NA_NS_CTRL_SANDSTORM	    0x01

#define NA_NS_CTRL_DIST_NEAR	    0x00
#define NA_NS_CTRL_DIST_MIDDLE	    0x24
#define NA_NS_CTRL_DIST_FAR	    0x38


/* ********************************************
	    BGM PATTERN DEFINE 
   ******************************************** */
#define NA_BGM_PTN_NORMAL	    0x00
#define NA_BGM_PTN_FIGHT	    0x01
#define NA_BGM_PTN_REST		    0x02
#define NA_BGM_PTN_FORCE_NORMAL	    0x03

#define NA_ENM_BGM_DIST_MAX	    500.0f
#define NA_ENM_BGM_DIST_MIN	    150.0f
#define NA_ENM_BGM_DIST_WIDTH	    (NA_ENM_BGM_DIST_MAX-NA_ENM_BGM_DIST_MIN)

#define NA_ENM_BGM_MUTE_VOL	    80
#define NA_ENM_BGM_MUTE_VOL1	    60
#define NA_ENM_BGM_MUTE_VOL2	    40
#define NA_ENM_BGM_MUTE_VOL3	    20
#define NA_ENM_BGM_MUTE_VOL4	    5


/* ********************************************
	    BGM FLAG
   ******************************************** */
   
#define NA_BGM_NO_ENTRY		    0xffff
#define NA_BGM_SE_SEQUENCE	    0x0000
#define NA_BGM_NA_SEQUENCE	    0x0001
#define NA_BGM_FIELD		    0x0002
#define NA_BGM_DUNGEON		    0x0018
#define NA_BGM_KAKARIKO_ADULT	    0x0019
#define NA_BGM_BGM00		    0x0002
#define NA_BGM_BGM01		    0x0019
#define NA_BGM_BGM02		    0x001a
#define NA_BGM_BGM03		    0x001a
#define NA_BGM_ENEMY		    0x081a

#define NA_BGM_BOSS00		    0x001b
#define NA_BGM_FAIRY_DUNGEON	    0x001c
#define NA_BGM_MARKET		    0x001d
#define NA_BGM_TITLE		    0x001e
#define NA_BGM_LINK_HOUSE	    0x001f
#define NA_BGM_GAME_OVER	    0x0020
#define NA_BGM_BOSS_CLEAR	    0x0021
#define NA_BGM_ITEM_GET		    0x0922
#define NA_BGM_OPENING_GANON	    0x0023
#define NA_BGM_HEART_GET	    0x0924
#define NA_BGM_OCA_LIGHT	    0x0025
#define NA_BGM_BUYO_DANGEON 	    0x0026
#define NA_BGM_BUYO_DUNGEON 	    0x0026
#define NA_BGM_KAKARIKO_KID 	    0x0027
#define NA_BGM_GODESS 		    0x0028
#define NA_BGM_HIME 		    0x0029
#define NA_BGM_FIRE_DUNGEON	    0x002a
#define NA_BGM_OPEN_TRE_BOX	    0x092b
#define NA_BGM_FORST_DUNGEON	    0x002c
#define NA_BGM_HIRAL_GARDEN	    0x002d

#define NA_BGM_GANON_TOWER	    0x002e
#define NA_BGM_NARRATION_0	    0x002e

#define NA_BGM_RONRON		    0x002f
#define NA_BGM_GORON		    0x0030
#define NA_BGM_SPIRIT_STONE	    0x0032
#define NA_BGM_OCA_FLAME	    0x0033
#define NA_BGM_OCA_WIND		    0x0034
#define NA_BGM_OCA_WATER	    0x0035
#define NA_BGM_OCA_SOUL		    0x0036
#define NA_BGM_OCA_DARKNESS	    0x0037
#define NA_BGM_MIDDLE_BOSS	    0x0038
#define NA_BGM_S_ITEM_GET	    0x0039
#define NA_BGM_SHRINE_OF_TIME	    0x003a
#define NA_BGM_EVENT_CLEAR	    0x003b
#define NA_BGM_KOKIRI		    0x003c
#define NA_BGM_OCA_YOUSEI	    0x003d
#define NA_BGM_MAYOIMORI	    0x003e
#define NA_BGM_SOUL_DUNGEON	    0x003f
#define NA_BGM_HORSE		    0x0040
#define NA_BGM_HORSE_GOAL	    0x0041
#define NA_BGM_INGO		    0x0042
#define NA_BGM_MEDAL_GET	    0x0043

#define NA_BGM_OCA_SARIA	    0x0044
#define NA_BGM_OCA_EPONA	    0x0045
#define NA_BGM_OCA_ZELDA	    0x0046
#define NA_BGM_OCA_SUNMOON	    0x0047
#define NA_BGM_OCA_TIME		    0x0048
#define NA_BGM_OCA_STORM	    0x0049

#define NA_BGM_NAVI		    0x004a
#define NA_BGM_DEKUNOKI		    0x004b
#define NA_BGM_FUSHA		    0x004c
#define NA_BGM_HIRAL_DEMO	    0x004d
#define NA_BGM_MINI_GAME	    0x004e
#define NA_BGM_SEAK		    0x004f
#define NA_BGM_ZORA		    0x0050
#define NA_BGM_APPEAR		    0x0051
#define NA_BGM_ADULT_LINK	    0x0052
#define NA_BGM_MASTER_SWORD	    0x0053
#define NA_BGM_INTRO_GANON	    0x0054
#define NA_BGM_SHOP		    0x0055
#define NA_BGM_KENJA		    0x0056
#define NA_BGM_FILE_SELECT	    0x0057
#define NA_BGM_ICE_DUNGEON	    0x0058
#define NA_BGM_GATE_OPEN	    0x0059
#define NA_BGM_OWL		    0x005a
#define NA_BGM_DARKNESS_DUNGEON	    0x005b
#define NA_BGM_AQUA_DUNGEON	    0x005c
#define NA_BGM_BRIDGE		    0x005d
#define NA_BGM_SARIA		    0x005e
#define NA_BGM_BYEBYE_SARIA	    0x005e
#define NA_BGM_SHEALED_CEREMONY	    0x005e
#define NA_BGM_GERUDO		    0x005f
#define NA_BGM_DRUGSTORE	    0x0060
#define NA_BGM_KOTAKE_KOUME	    0x0061
#define NA_BGM_ESCAPE		    0x0062
#define NA_BGM_UNDERGROUND	    0x0063
#define NA_BGM_GANON_BATTLE_1	    0x0064
#define NA_BGM_GANON_BATTLE_2	    0x0065
#define NA_BGM_END_DEMO		    0x0066
#define NA_BGM_STAFF_1		    0x0067
#define NA_BGM_STAFF_2		    0x0068
#define NA_BGM_STAFF_3		    0x0069
#define NA_BGM_STAFF_4		    0x006a
#define NA_BGM_BOSS01		    0x006b
#define NA_BGM_MINI_GAME_2	    0x006c
#define NA_BGM_DEMO_SE_SEQ	    0x006d

#if 0
//#define NA_BGM_OCA_LIGHT	    0x0925
//#define NA_BGM_OCA_WATER	    0x0025
//#define NA_BGM_OCA_WIND		    0x0025
//#define NA_BGM_OCA_FLAME	    0x0025
//#define NA_BGM_OCA_SOUL		    0x0025
//#define NA_BGM_OCA_DARKNESS	    0x0025
#endif

/* ********************************************
	    CHECK PLAYING BGM
   ******************************************** */

#define NA_BGM_CHK_NOW_PLAYING	    1
#define NA_BGM_CHK_NOT_ENTRY	    0


/* ********************************************
	    SOUND SPEC MODE
   ******************************************** */
   
#define NA_MODE_GROUND_SMALL	    0x00
#define NA_MODE_GROUND_MIDDLE	    0x01
#define NA_MODE_GROUND_LARGE	    0x02
#define NA_MODE_DUNGEON_SMALL	    0x03
#define NA_MODE_DUNGEON_LARGE	    0x04
#define NA_MODE_HOUSE_SMALL	    0x05
#define NA_MODE_HOUSE_LARGE	    0x06
#define NA_MODE_FOREST		    0x07
#define NA_MODE_DESERT		    0x08
#define NA_MODE_GROUND_CANYON	    0x09
#define NA_MODE_TITLE		    0x0a
#define NA_MODE_ENDINGDEMO	    0x0b
#define NA_MODE_STAFFROLL	    0x0c


/* ********************************************
	    NARRATION SEQ DEFINE 
   ******************************************** */
#define NA_BGM_NARRATION_MUTE_VOL   64
#define NA_BGM_NARRATION_MUTE_TIME   25
#define NA_NAR_HIRAL		NA_BGM_NARRATION_0


/* ********************************************
	    OCARINA DEFINE
   ******************************************** */
   
#define NA_OCA_NOT_CHECK	    0xff
#define NA_OCA_NOW_CHECK	    0xfe

#define NA_OCA_MELODY_MAX	    14	/* 12 */
#define NA_OCA_REC_BUF_SIZE	108	/* 250 */
#define NA_OCA_REC_BUF_STC	8	/* 6 */
#define NA_OCA_REC_MEMORY_SIZE	(NA_OCA_REC_BUF_SIZE*NA_OCA_REC_BUF_STC)
#define NA_OCA_REC_BUF_SIZE2	16
#define NA_OCA_REC_MEMORY_SIZE2	(NA_OCA_REC_BUF_SIZE2*NA_OCA_REC_BUF_STC)

#define NA_OCA_BTN_A	    0
#define NA_OCA_BTN_CD	    1
#define NA_OCA_BTN_CR	    2
#define NA_OCA_BTN_CL	    3
#define NA_OCA_BTN_CU	    4

#define NA_OCA_CHK_STOP		0xff
#define NA_OCA_CHK_CHECK	0xfe
#define NA_OCA_CHK_MELO_0	0x00
#define NA_OCA_CHK_MELO_1	0x01

#define NA_OCA_CHK_WIND		0x00
#define NA_OCA_CHK_FLAME	0x01
#define NA_OCA_CHK_WATER	0x02
#define NA_OCA_CHK_SOUL		0x03
#define NA_OCA_CHK_DARKNESS	0x04
#define NA_OCA_CHK_LIGHT	0x05
#define NA_OCA_CHK_SPIRIT	0x06
#define NA_OCA_CHK_EPONA	0x07
#define NA_OCA_CHK_ZELDA	0x08
#define NA_OCA_CHK_SUNMOON	0x09
#define NA_OCA_CHK_TIME		0x0a
#define NA_OCA_CHK_STORM	0x0b

#define NA_OCA_CHK_IMPA		0x09
#define NA_OCA_CHK_MYSTERY	0x0b
#define	NA_OCA_CHK_RECMELODY2	0x0c
#define NA_OCA_CHK_GAME		0x0d
#define	NA_OCA_CHK_RECMELODY	NA_OCA_MELODY_MAX

#define NA_OCA_CHK_LEGEND	0x08


#define NA_OCA_CHK_ZELDA_WARP	NA_OCA_CHK_IMPA

#define NA_OCA_CHK_GRP_EVERY	0x3fff
#define NA_OCA_CHK_GRP_ALL2	0x1fff
#define NA_OCA_CHK_GRP_ALL	0x0fff
#define NA_OCA_CHK_GRP_WARP	0x003f
#define NA_OCA_CHK_GRP_GROUND	0x8480
#define NA_OCA_CHK_GRP_ZELDA	0x0040
#define NA_OCA_CHK_MODE_STOP	0xffff

#define NA_OCA_INST_OCARINA	0x01
#define NA_OCA_INST_MALON	0x02
#define NA_OCA_INST_IMPA	0x03
#define NA_OCA_INST_HARP	0x04
#define NA_OCA_INST_WINDMILL	0x05
#define NA_OCA_INST_PICCOLO	0x06

#define NA_OCA_INST_ORGAN	0x05

#define NA_OCA_SEQ_PLAY		0x01
#define NA_OCA_SEQ_STOP		0x00

#define NA_OCA_REC_RUNNING	0x01
#define NA_OCA_REC_STOP		0x00
#define NA_OCA_REC_BAD		0xff

#define NA_OCA_GAME_MAX		0x01
#define NA_OCA_GAME_SHORTAGE	0x00

#define NA_OCA_FROG_NOTES	14


/* ********************************************
	    CHECK FLAG
   ******************************************** */
   
#define NA_FLAG_NO_ENTRY	    0
#define NA_FLAG_NOW_PLAYING	    1


/* ********************************************
	    SE WATER FLAG
   ******************************************** */
   
#define NA_WATER_MODE_ON	0x20
#define NA_WATER_MODE_OFF	0x00


/* ********************************************
	    SE TIMER LEVEL
   ******************************************** */
   
#define NA_TIMER_COUNT_LOW	0
#define NA_TIMER_COUNT_MIDDLE	1
#define NA_TIMER_COUNT_HIGH	2

#define NA_TIMER_TERM_WARNING	40
#define NA_TIMER_TERM_CAUTION	100


/* ********************************************
	    RIVER STREAM SPEED MACRO
   ******************************************** */
#define NA_RIVER_SPEED_SLOW	0.7f
#define NA_RIVER_SPEED_MIDDLE	1.0f
#define NA_RIVER_SPEED_FAST	1.4f

/* ********************************************
	    WATERFALL SPEED MACRO
   ******************************************** */
#define NA_WATERFALL_SPEED_SLOW	    0.5f
#define NA_WATERFALL_SPEED_NORMAL   1.0f


/* ********************************************
	    FROG SOUND
   ******************************************** */
#define NA_FROG_SOUND_A		2
#define NA_FROG_SOUND_CD	5
#define NA_FROG_SOUND_CR	9
#define NA_FROG_SOUND_CL	11
#define NA_FROG_SOUND_CU	14

#define NA_FROG_BIG_SOUND_A	-10
#define NA_FROG_BIG_SOUND_CD	-7
#define NA_FROG_BIG_SOUND_CR	-3
#define NA_FROG_BIG_SOUND_CL	-1
#define NA_FROG_BIG_SOUND_CU	2

/* ********************************************
	    FIVE LUPY SOUND
   ******************************************** */
#define NA_LUPY_COUNT_1		0
#define NA_LUPY_SOUND_2		2
#define NA_LUPY_SOUND_3		4
#define NA_LUPY_SOUND_4		5
#define NA_LUPY_SOUND_5		7

/* ********************************************
	    LEVEL MUTE VOLUME
   ******************************************** */
#define NA_LV_MUTE_VOL		90


/* ********************************************
	    patch header
   ******************************************** */

/* extern void Na_MusicStart(u16 ); */
