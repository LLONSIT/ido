#include  "ucode.h"
#ifndef UGENDATA_H
#define UGENDATA_H
type
 u16 = 0..65535  ;
 u8 =  0..255 of char;
 s8 = -128..127;


#ifndef CSTRUCT
struct tree {
	struct tree* next;
	struct tree* prev;
	struct tree* unk8;
	int pad;
	int pad1;
	u16 ref_count;
	int pad3;
	union {
	struct Bcrec u;
	}Uopc;
	union {
	struct Bcrec d;
	}Dtype;
	union {
	int unk20;
	int unk24;
	int unk28;
	int unk2C;
	int fill;
	int unk30;
	int unk34;
	};
};
#endif


type tree  = Record
/* 0x0 */  next: ^tree;
/* 0x4 */   prev: ^tree;
/* 0x8 */   unk8: ^tree; /*Node?*/
/* 0xC */   pad: integer;
/* 0x10 */  pad1: integer;
/* 0x14 */  ref_count: u16;
/* 0x18 */ pad3: integer;
case integer of
0 : /* 0x20 */ ( u: Bcrec);
1: /* 0x21 */ (d: Bcrec);
2: /* 0x28 */  (
unk20: integer;
unk24: integer;
unk28: integer;
unk2C: integer;
fill: integer;
unk30: integer;
unk34: integer;);
end;
#endif /* UGENDATA_H */
