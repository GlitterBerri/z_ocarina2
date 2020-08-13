/*
 *  NINTENDO64 JPEG LIBRARY
 *
 *  FILE : jpg.h
 *
 *  Copyright (C) 1998, NINTENDO Co,Ltd.
 */


/* エラー */
#define JPG_ERROR_NOERROR                  0
#define JPG_ERROR_CANNOT_MAKE_HUFFMANTABLE 1
#define JPG_ERROR_CANNOT_HUFFMANDECODE     2
#define JPG_ERROR_CANNOT_HUFFMANENCODE     3

/* サブサンプリングタイプ */
#define JPG_SUBSAMPLING_422 0
#define JPG_SUBSAMPLING_420 2

/* 出力フォーマット */
#define JPG_FORMAT_YUV    0
#define JPG_FORMAT_RGBA32 1
#define JPG_FORMAT_RGBA16 2

/* ハフマンデコードフラグ */
#define JPG_LOAD_INIT 0
#define JPG_LOAD_CONT 1

/* ハフマンエンコードフラグ */
#define JPG_SAVE_INIT 0
#define JPG_SAVE_CONT 1

/* マイクロコードフラグ */
#define M_NJPEGTASK 4


/* #######################################################
 *  量子化テーブル関係
 * ####################################################### */

/* 量子化テーブルサイズ */
#define JPG_QUANTTABLE_SIZE 128

/* 量子化テーブル構造体 */
typedef struct {
  u16 element[64];
} JPGQuantTable;

/* 量子化テーブル作成 */
void jpgMakeQuantTable(u8 *, JPGQuantTable *, u8);


/* #######################################################
 *  ハフマンテーブル関係
 * ####################################################### */

/*
 * 共通
 */

/* ハフマンテーブル作成用テンポラリ領域 */
#define JPG_HSIZETABLE_SIZE 272
#define JPG_HCODETABLE_SIZE 528


/*
 * デコード
 */

/* ハフマンデコードテーブル構造体 */
#define JPG_DHUFFTABLE_SIZE 84

typedef struct {
  u8  ptrList[16];
  u16 minList[16];
  u16 maxList[16];
  u8  *huffVal;
} JPGDHuffTable;

/* ハフマンデコードテーブルの作成 */
u8 jpgMakeDHuffTable(u8 *, JPGDHuffTable *, u8 *, u16 *, u8);


/*
 * エンコード
 */

/* ハフマンエンコードテーブル構造体 (DC) */
#define JPG_EDHUFFTABLE_SIZE 48

typedef struct {
  u8  size[16];
  u16 code[16];
} JPGEDcHuffTable;

/* ハフマンエンコードテーブル構造体 (AC) */
#define JPG_EAHUFFTABLE_SIZE 768

typedef struct {
  u8  size[256];
  u16 code[256];
} JPGEAcHuffTable;

/* ハフマンエンコードテーブル構造体 */
typedef union {
  JPGEDcHuffTable dc;
  JPGEAcHuffTable ac;
} JPGEHuffTable;

/* ハフマンエンコードテーブルの作成 */
u8 jpgMakeEHuffTable(u8 *, JPGEHuffTable *, u8 *, u16 *);


/* #######################################################
 *  ハフマンデコード
 * ####################################################### */

/* ハフマンデコードパラメータ構造体 */
typedef struct {
  u8            *input;
  u8            subsampType;
  u8            format;
  JPGDHuffTable *yDcTable;
  JPGDHuffTable *yAcTable;
  JPGDHuffTable *cDcTable;
  JPGDHuffTable *cAcTable;
  u8            restart;
} JPGHuffDecParam;

/* ハフマンデコードステート構造体 */
typedef struct {
  u32 current;
  u8  pointer;
  u8  through;
  u32 buffer;
  s16 yDc;
  s16 cbDc;
  s16 crDc;
} JPGHuffDecState;

/* ハフマンデコード */
u8 jpgLoad(JPGHuffDecParam *, s16 *, u32, u8, JPGHuffDecState *);


/* #######################################################
 *  ハフマンエンコード
 * ####################################################### */

/* ハフマンエンコードパラメータ構造体 */
typedef struct {
  u8            *output;
  u8            subsampType;
  JPGEHuffTable *yDcTable;
  JPGEHuffTable *yAcTable;
  JPGEHuffTable *cDcTable;
  JPGEHuffTable *cAcTable;
  u8            restart;
} JPGHuffEncParam;

/* ハフマンエンコードステート構造体 */
typedef struct {
  u32 current;
  u8  pointer;
  u32 buffer;
  s16 yDc;
  s16 cbDc;
  s16 crDc;
} JPGHuffEncState;

/* ハフマンエンコード */
u8 jpgSave(JPGHuffEncParam *, s16 *, u32, u8, u32 *, JPGHuffEncState *);


/* #######################################################
 *  デコード用マイクロコード
 * ####################################################### */

/* JPEG デコードマイクロコード パラメータ構造体 */
#define JPG_DUCODE_PARAMSIZE 32

typedef struct {
  s16 *data;
  u32 mbs;
  u32 subsampType;
  u16 *tableY;
  u16 *tableCb;
  u16 *tableCr;
  u32 dummy1;
  u32 dummy2;
} JPGDUcodeParam;

/* JPEG デコードマイクロコードの extern 宣言 */
extern u8 jpgDYUVTextStart[], jpgDYUVTextEnd[];
extern u8 jpgDYUVDataStart[], jpgDYUVDataEnd[];

extern u8 jpgDRGBATextStart[], jpgDRGBATextEnd[];
extern u8 jpgDRGBADataStart[], jpgDRGBADataEnd[];

extern u8 jpgDRGBA16TextStart[], jpgDRGBA16TextEnd[];
extern u8 jpgDRGBA16DataStart[], jpgDRGBA16DataEnd[];

/* JPEG デコードマイクロコード yield 領域 */
#define JPG_DUCODE_YIELDSIZE  512


/* #######################################################
 *  エンコード用マイクロコード
 * ####################################################### */

/* JPEG エンコードマイクロコード パラメータ構造体 */
#define JPG_EUCODE_PARAMSIZE 32

typedef struct {
  u8  *input;
  s16 *output;
  u16 *tableY;
  u16 *tableCb;
  u16 *tableCr;
  u32 subsampType;
  u32 mbs_x;
  u32 mbs_y;
} JPGEUcodeParam;

/* JPEG エンコードマイクロコードの extern 宣言 */
extern u8 jpgERGBATextStart[], jpgERGBATextEnd[];
extern u8 jpgERGBADataStart[], jpgERGBADataEnd[];

extern u8 jpgERGBA16TextStart[], jpgERGBA16TextEnd[];
extern u8 jpgERGBA16DataStart[], jpgERGBA16DataEnd[];

/* JPEG エンコードマイクロコード yield 領域 */
#define JPG_EUCODE_YIELDSIZE  512
