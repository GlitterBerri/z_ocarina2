/*
 * $Id: padmgr.h,v 2.1 1998-10-22 20:41:56+09 zelda Exp $
 *
 * パッドマネージャ
 *
 * $Log: padmgr.h,v $
 * Revision 2.1  1998-10-22 20:41:56+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.21  1998/07/17 12:29:03  hayakawa
 * padmgr_AddClient, padmgr_RemoveClient追加
 *
 * Revision 1.20  1998-04-09 18:34:19+09  hayakawa
 * スタックサイズ２５％増量（当社比）
 *
 * Revision 1.19  1998/04/01  02:47:07  hayakawa
 * 汎用性を考え __cplusplus を _LANGUAGE_C_PLUS_PLUS に変更
 *
 * Revision 1.18  1997/11/21  08:42:14  hayakawa
 * USE_IRQMGRを標準導入した
 *
 * Revision 1.17  1997/11/18  05:07:18  hayakawa
 * *** empty log message ***
 *
 * Revision 1.16  1997/11/16  13:39:07  hayakawa
 * STACKSIZE調整
 *
 * Revision 1.15  1997/11/10  13:52:20  hayakawa
 * MotorLifeTime
 *
 * Revision 1.14  1997/11/06  07:06:33  hayakawa
 * USE_IRQMGRで条件コンパイルするようにした
 *
 * Revision 1.13  1997/11/05  14:10:23  hayakawa
 * 振動パックタイミング修正
 * バグ修正その他
 *
 * Revision 1.12  1997/10/09  12:45:33  hayakawa
 * *** empty log message ***
 *
 * Revision 1.11  1997/10/09  10:14:05  hayakawa
 * いろいろ修正
 *
 * Revision 1.10  1997/10/09  07:22:59  hayakawa
 * *** empty log message ***
 *
 * Revision 1.9  1997/10/09  05:22:06  hayakawa
 * 振動パック対応
 *
 * Revision 1.8  1997/10/08  14:23:08  hayakawa
 * 振動パック対応
 * スタックを外に出した
 *
 * Revision 1.7  1997/08/21  02:57:01  hayakawa
 * 複数スレッドからキーを読めるようにした（暫定？）
 *
 * Revision 1.6  1997/03/17  00:58:50  hayakawa
 * 構造体からnow_readingメンバを削除
 *
 * Revision 1.5  1997/03/14  00:25:53  hayakawa
 * ヘッダ追加
 *
 * Revision 1.4  1997/03/13  11:54:18  hayakawa
 * 構造体のメンバをソートした
 * シリアルメッセージを独立（使い回し）
 *
 * Revision 1.3  1997/02/12  01:14:14  hayakawa
 * Ｃ＋＋コンパイラ対応
 *
 * Revision 1.2  1996/11/27  05:32:07  hayakawa
 * コメントの追加
 * デストラクタの作成（未使用）
 *
 */

#ifndef __PADMGR_H_
#define __PADMGR_H_

#include "pad.h"
#include "irqmgr.h"

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#define PADMGR_STACKSIZE 0x500	/* 実績 0x304 */

typedef struct padmgr_s padmgr_t;
struct padmgr_s {
    OSContStatus pad_status[MAXCONTROLLERS]; /* ステータス */
    OSMesg	serialLockMsgBuf; /* OS_EVENT_SIロック用バッファ */
    OSMesg	contLockMsgBuf; /* コントローラロック用バッファ */
    OSMesg 	recvMsgBufs[4];	/* スケジューライベント受信用バッファ */
    OSMesgQueue	serialLockMsgQ;	/* OS_EVENT_SIロック用キュー */
    OSMesgQueue	contLockMsgQ;	/* コントローラロック用キュー */
    OSMesgQueue recvMsgQ;	/* スケジューライベント受信用キュー */
    irqmgr_client_t 	client;	/* ＩＲＱマネージャのクライアント構造体 */
    irqmgr_t 	*sc;		/* 初期化されたＩＲＱマネージャ */
    OSThread	thread;		/* スレッド構造体 */
    volatile pad_t pads[MAXCONTROLLERS]; /* コントローラデータの内容 */
    OSContPad   last_pad[MAXCONTROLLERS]; /* 最新のコントローラ情報 */
    volatile u8 pad_pattern;	/* パッドの接続状況 */
    u8 		pad_ch;		/* 使用するパッド数 */
    u8		Key_switch[MAXCONTROLLERS];	/* !0:パッド接続有効 */
    u8		Motor_switch[MAXCONTROLLERS]; /* 0:None 1:振動パック 2:不明パック */
    volatile u8 Motor_newflags[MAXCONTROLLERS]; /* Motor 0:Off 1:On */
    u8      	Motor_oldflags[MAXCONTROLLERS]; /* Motor 0:Off 1:On -1:? */
    OSPfs	Motor_Pfs[MAXCONTROLLERS]; /* 振動パック制御用 */
    volatile u8 Motor_stop_frame; /* 振動パック強制停止フレーム */
    volatile u8 MotorLifeTime;	/* 振動パック活動可能フレーム */
    u8 		recieved_prenmi; /* !0:PRE_NMIを受け取った */
    void 	(*callback)(padmgr_t *, void *); /* コールバック関数 */
    void	*callback_param; /* コールバック関数パラメータ */
};


/* パッドマネージャ生成 */
void
padmgr_Create(
    padmgr_t *this,		/* パッドマネージャ管理構造体 */
    OSMesgQueue *serialMsgQ,	/* OS_EVENT_SIに関連づけられたメッセージキュー */
    irqmgr_t *sc,		/* 初期化されたＩＲＱマネージャ */
    OSId id,			/* パッドマネージャのＩＤ */
    OSPri pri,			/* パッドマネージャの優先度 */
    void *stacktail		/* パッドマネージャのスタック最後尾 */
);

/* ＰＡＤデータを取得する */
void
padmgr_RequestPadData(
    padmgr_t *this,		/* パッドマネージャ管理構造体 */
    pad_t *padp,		/* ＰＡＤデータを格納するバッファ */
    int flag			/* !0:トリガ制御をする(メインのみ) */
);

/*
 * シリアルメッセージの権利を取得する
 */
void
padmgr_UnlockSerialMesgQ(
    padmgr_t *this,		/* パッドマネージャ管理構造体 */
    OSMesgQueue *serialMsgQ	/* シリアルメッセージキュー */
);

/*
 * シリアルメッセージの権利を解放する
 */
OSMesgQueue *
padmgr_LockSerialMesgQ(
    padmgr_t *this		/* パッドマネージャ管理構造体 */
);

/*
 * 振動パックをリセットする
 */
void
padmgr_RumbleReset(padmgr_t *this);

/*
 * 指定したコントローラの振動パックをＯＮ／ＯＦＦする
 */
void
padmgr_RumbleSet(
    padmgr_t *this,		/* パッドマネージャ管理構造体 */
    int padno,			/* パッド番号 */
    int flag			/* 0:OFF 1:ON */
);

/*
 * テーブルでコントローラの振動パックをＯＮ／ＯＦＦする
 */
void
padmgr_RumbleSetTbl(
    padmgr_t *this,		/* パッドマネージャ管理構造体 */
    u8 *flags			/* (0:OFF 1:ON)MAXCONTROLLERS個の配列 */
);

/*
 * コントローラの接続状態を取得する
 * ０〜３ビットが１〜４コンに対応している
 */
#define padmgr_GetPadPattern(padmgr) (u8)((padmgr)->pad_pattern)

/*
 * パッドデータ読み込み待ちの間に呼ばれる関数を登録
 */
#define padmgr_AddClient(padmgr, func, data) \
do { \
    padmgr_t *this = (padmgr); \
    this->callback = func; \
    this->callback_param = data; \
} while (0)

/*
 * パッドデータ読み込み待ちの間に呼ばれる関数を抹消
 */
#define padmgr_RemoveClient(padmgr, func, data) \
do { \
    padmgr_t *this = (padmgr); \
    if (this->callback == (func) && this->callback_param == (data)) { \
        this->callback = NULL;      this->callback_param = NULL; \
    } \
} while (0)

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif /* __PADMGR_H_ */
