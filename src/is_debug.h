/* $Id: is_debug.h,v 2.1 1998/10/22 11:41:56 zelda Exp $ */	
/* $Log: is_debug.h,v $
 * Revision 2.1  1998/10/22  11:41:56  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.4  1998/09/24 14:03:47  hayakawa
 * _is_printf_s を extern にした
 *
 * Revision 1.3  1997-08-21 11:59:08+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.2  1997/05/21  01:23:25  soejima
 * n
 *
 * Revision 1.1  1997/05/13  05:35:36  soejima
 * Initial revision
 *
 * Revision 1.1  1997/05/13  05:35:05  soejima
 * Initial revision
 *
 * $Log追加
 * */

/************************************************************************
 *
 *	ＩＳ−Ｄｅｂｇｅｒ
 *
 ************************************************************************/


#ifndef __IS_DEBUG_H__
#define __IS_DEBUG_H__

#ifdef _LANGUAGE_C_PLUS_PLUS   /* for c++ */
extern "C" {
#endif

/* ====================================================================
 * is_debug.h
 *
 * Copyright 1997, Intelligent Systems Co.,Ltd.
 * All Rights Reserved.
 *
 * このヘッダは、IS-Viewer64用のプリントデバッグ機能を利用する為に必要
 * です。プリントデバッグを行う方法は次の通りです。
 *
 * 1.デバッグを行いたいプログラムのbootスレッドで(osInitialize();の呼び
 *   出し後あたり）にisPrintInit();にを呼び出しデバッグ機能を初期化しま
 *   す。
 *
 * 2.isPrintf関数でデバッグしたい情報をprintf関数と同じ形式で呼び出しま
 *   す。このライブラリは、osSyncPrintf,rmonPrintfもisPrintfを呼び出す
 *   ように関数をオーバーライドしています。この為、libultra_d.aなど、
 *   osSyncPrintfを含むライブラリと一緒にリンクしてはいけません。
 *
 * 3.デバッグ機能を利用するソースには、is_debug.hをインクルードします。
 *
 * 4.makefileに、is_debug.cがともに、コンパイルリンクされるように追加
 *   します。
 * 6.nload filename を行います。nloadは自動的にデバッグプリントループに
 *   はいり、NUS側のプリント情報を画面に表示することが出来ます。
 * 7.デバッグプリントに使用するデフォルトアドレスは、0xb1ff0000からですが
 *   都合が悪い場合には、このアドレスを変更することが可能です。詳細は
 *   is_debug.cを参照してください。
 *==================================================================== */

extern void isPrintfInit(void);
extern void isPrintf(const char *fmt, ...);
extern void *_is_printf_s(void *str, register const char *buf, register int n);

#ifdef _LANGUAGE_C_PLUS_PLUS   /* for c++ */  
}
#endif

#endif

