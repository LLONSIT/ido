#include "common.h"
#include "ucode.h"
#include "libu.h"

__asm__(R""(
.macro glabel label
    .global \label
    .balign 4
    \label:
.endm

.data
D_100118A0:
    # 00486E88 ubittobyte
    .byte 0x00,0x00,0x00,0x18,0x04,0x03,0x8c,0xb0,0x02,0x40,0x00,0x84,0x00,0x00,0x60,0x00,0x00,0x20,0x00,0x00

D_100118B4:
    # 00486E88 ubittobyte
    .byte 0x00,0x04,0x00,0x00,0x40,0x00,0x00,0x00

D_100118BC:
    # 00486E88 ubittobyte
    .byte 0x00,0x00,0x20,0x00,0x01,0x00,0x00,0x00,0x00,0x04,0x80,0x00

D_100118C8:
    # 00486E88 ubittobyte
    .byte 0x00,0x00,0x12,0x01,0x80,0x00,0x00,0x00,0x00,0x08,0x00,0x00

D_100118D4:
    # 00486E88 ubittobyte
    .byte 0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x00,0x00,0x20,0x20,0x0e,0x91,0x00,0x10,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00

.text
)"");

/*
00486690 inituwrite
00486880 uwrite
00486E88 ubittobyte
*/
bool noerrorsyet;

/*
00486690 inituwrite
*/
int u_indent;

/*
00486690 inituwrite
00486AD4 getmtyname
*/
char mtyname[8];

/*
00486690 inituwrite
00486AB4 getdtyname
*/
char dtyname[18];

/*
004808D0 func_004808D0
00480920 func_00480920
00480964 uini
00486608 getutabrec
00486880 uwrite
00487B7C readuinstr
*/
struct utabrec utab[0x9C];

/*
00434720 processargs
*/
void inituwrite(const char *path) {
    noerrorsyet = true;

    uputinit(path);

    dtyname[Cdt] = 'C';
    dtyname[Fdt] = 'F';
    dtyname[Gdt] = 'G';
    dtyname[Hdt] = 'H';

    dtyname[Cdt] = 'C';
    dtyname[Fdt] = 'F';
    dtyname[Gdt] = 'G';
    dtyname[Hdt] = 'H';
    dtyname[Zdt] = 'Z';
    dtyname[Adt] = 'A';
    dtyname[Jdt] = 'J';
    dtyname[Ldt] = 'L';
    dtyname[Mdt] = 'M';
    dtyname[Ndt] = 'N';
    dtyname[Pdt] = 'P';
    dtyname[Qdt] = 'Q';
    dtyname[Rdt] = 'R';
    dtyname[Sdt] = 'S';
    dtyname[Xdt] = 'X';
    dtyname[Idt] = 'I';
    dtyname[Kdt] = 'K';
    dtyname[Wdt] = 'W';

    mtyname[Zmt] = 'Z';
    mtyname[Mmt] = 'M';
    mtyname[Rmt] = 'R';
    mtyname[Smt] = 'S';
    mtyname[Pmt] = 'P';
    mtyname[Amt] = 'A';

    u_indent = 0;
}

// unused
int idlen(const char id[32]) {
    int len = 32;
    while (len != 0 && id[len - 1] == ' ') {
        len--;
    }
    return len;
}


/*
0041EC10 igen3
0041EE30 outparlod
0041EF64 gen_cvtl
0041EFD4 gen_cvt
0041F048 genrop
0041F6F0 base_in_reg
0041FB20 spilltemplodstr
0041FC80 genloadaddr
0041FD3C genloadnum
0042018C genloadrnum
0042020C gen_static_link
004205F8 genrlodrstr
00420A3C prolog
00421C00 epilog
00422AF0 func_00422AF0
00422D04 func_00422D04
004230F0 func_004230F0
00426FA4 func_00426FA4
0042933C func_0042933C
0042A1C8 func_0042A1C8
0042A4CC func_0042A4CC
0042A7D0 func_0042A7D0
0042AADC func_0042AADC
0042B2C0 func_0042B2C0
0042B890 func_0042B890
0042BB4C func_0042BB4C
0042BF08 reemit
0043A0CC copyline
00456A2C oneproc
0045806C main
004584D0 init_mtagtab
0045877C searchmtag_parm
0045889C func_0045889C
00458998 func_00458998
00458B88 assign_mtag
0047FF7C skipproc
00486AF4 ucoid
00486C78 ucofname
*/
void uwrite(union Bcode *bcode) {
    struct Bcrec *uinstr = &bcode->Ucode;
    int i;
    int strlength;
    char *str;

    if (!noerrorsyet) {
        return;
    }

    struct utabrec urec = utab[uinstr->Opc];
    for (i = 0; i < urec.instlength; i += 2) {
        uputint(bcode->intarray[i]);
        uputint(bcode->intarray[i + 1]);
    }
    if (urec.hasconst) {
        uputint(bcode->intarray[urec.instlength]);
        uputint(bcode->intarray[urec.instlength + 1]);
        if (((1 << uinstr->Dtype) & ((1 << Mdt) | (1 << Qdt) | (1 << Rdt) | (1 << Sdt) | (1 << Xdt))) || uinstr->Opc == Ucomm) {
            if (uinstr->Opc == Uinit) {
                strlength = (uinstr->Uopcde.uiequ1.uop2.uinit.initval.swpart.Ival + 3) / 4;
            } else {
                strlength = (uinstr->Uopcde.uiequ1.uop2.Constval.swpart.Ival + 3) / 4;
            }
            if (strlength & 1) {
                strlength++;
            }
            if (uinstr->Opc == Uinit) {
                str = uinstr->Uopcde.uiequ1.uop2.uinit.initval.swpart.Chars;
            } else {
                str = uinstr->Uopcde.uiequ1.uop2.Constval.swpart.Chars;
            }
            for (i = 0; i < strlength; i += 2) {
                uputint(((int *)str)[i]);
                uputint(((int *)str)[i + 1]);
            }
        }
    }
}

// unused
char getdtyname(enum Datatype type) {
    return dtyname[type];
}

// unused
char getmtyname(enum Memtype type) {
    return mtyname[type];
}

// unused
void stopucode(void) {
    uputkill();
    noerrorsyet = false;
}

__asm__(R""(
.set noat
.set noreorder
glabel ubittobyte
    .ent ubittobyte
/* 00486E88 90820000 */  lbu   $v0, ($a0)
/* 00486E8C 2C4E00A0 */  sltiu $t6, $v0, 0xa0
/* 00486E90 11C00009 */  beqz  $t6, .L00486EB8
/* 00486E94 2443FFE0 */   addiu $v1, $v0, -0x20
/* 00486E98 8F998044 */  lw    $t9, %got(D_100118D4)($gp)
/* 00486E9C 00027943 */  sra   $t7, $v0, 5
/* 00486EA0 000FC080 */  sll   $t8, $t7, 2
/* 00486EA4 273918D4 */  addiu $t9, %lo(D_100118D4) # addiu $t9, $t9, 0x18d4
/* 00486EA8 03384021 */  addu  $t0, $t9, $t8
/* 00486EAC 8D090000 */  lw    $t1, ($t0)
/* 00486EB0 00495004 */  sllv  $t2, $t1, $v0
/* 00486EB4 294E0000 */  slti  $t6, $t2, 0
.L00486EB8:
/* 00486EB8 11C0000E */  beqz  $t6, .L00486EF4
/* 00486EBC 2C780060 */   sltiu $t8, $v1, 0x60
/* 00486EC0 8C8C000C */  lw    $t4, 0xc($a0)
/* 00486EC4 8C8F0008 */  lw    $t7, 8($a0)
/* 00486EC8 05810003 */  bgez  $t4, .L00486ED8
/* 00486ECC 000C68C3 */   sra   $t5, $t4, 3
/* 00486ED0 25810007 */  addiu $at, $t4, 7
/* 00486ED4 000168C3 */  sra   $t5, $at, 3
.L00486ED8:
/* 00486ED8 AC8D000C */  sw    $t5, 0xc($a0)
/* 00486EDC 05E10003 */  bgez  $t7, .L00486EEC
/* 00486EE0 000FC8C3 */   sra   $t9, $t7, 3
/* 00486EE4 25E10007 */  addiu $at, $t7, 7
/* 00486EE8 0001C8C3 */  sra   $t9, $at, 3
.L00486EEC:
/* 00486EEC 03E00008 */  jr    $ra
/* 00486EF0 AC990008 */   sw    $t9, 8($a0)

.L00486EF4:
/* 00486EF4 13000009 */  beqz  $t8, .L00486F1C
/* 00486EF8 00000000 */   nop   
/* 00486EFC 8F8A8044 */  lw    $t2, %got(D_100118C8)($gp)
/* 00486F00 00034143 */  sra   $t0, $v1, 5
/* 00486F04 00084880 */  sll   $t1, $t0, 2
/* 00486F08 254A18C8 */  addiu $t2, %lo(D_100118C8) # addiu $t2, $t2, 0x18c8
/* 00486F0C 01495821 */  addu  $t3, $t2, $t1
/* 00486F10 8D6E0000 */  lw    $t6, ($t3)
/* 00486F14 006E6004 */  sllv  $t4, $t6, $v1
/* 00486F18 29980000 */  slti  $t8, $t4, 0
.L00486F1C:
/* 00486F1C 1300000E */  beqz  $t8, .L00486F58
/* 00486F20 2C690060 */   sltiu $t1, $v1, 0x60
/* 00486F24 8C8F0004 */  lw    $t7, 4($a0)
/* 00486F28 8C880008 */  lw    $t0, 8($a0)
/* 00486F2C 05E10003 */  bgez  $t7, .L00486F3C
/* 00486F30 000FC8C3 */   sra   $t9, $t7, 3
/* 00486F34 25E10007 */  addiu $at, $t7, 7
/* 00486F38 0001C8C3 */  sra   $t9, $at, 3
.L00486F3C:
/* 00486F3C AC990004 */  sw    $t9, 4($a0)
/* 00486F40 05010003 */  bgez  $t0, .L00486F50
/* 00486F44 000850C3 */   sra   $t2, $t0, 3
/* 00486F48 25010007 */  addiu $at, $t0, 7
/* 00486F4C 000150C3 */  sra   $t2, $at, 3
.L00486F50:
/* 00486F50 03E00008 */  jr    $ra
/* 00486F54 AC8A0008 */   sw    $t2, 8($a0)

.L00486F58:
/* 00486F58 1120000A */  beqz  $t1, .L00486F84
/* 00486F5C 00000000 */   nop   
/* 00486F60 8F8C8044 */  lw    $t4, %got(D_100118BC)($gp)
/* 00486F64 00035943 */  sra   $t3, $v1, 5
/* 00486F68 000B7080 */  sll   $t6, $t3, 2
/* 00486F6C 258C18BC */  addiu $t4, %lo(D_100118BC) # addiu $t4, $t4, 0x18bc
/* 00486F70 018E6821 */  addu  $t5, $t4, $t6
/* 00486F74 8DB80000 */  lw    $t8, ($t5)
/* 00486F78 00787804 */  sllv  $t7, $t8, $v1
/* 00486F7C 29F90000 */  slti  $t9, $t7, 0
/* 00486F80 03204825 */  move  $t1, $t9
.L00486F84:
/* 00486F84 11200014 */  beqz  $t1, .L00486FD8
/* 00486F88 2C780040 */   sltiu $t8, $v1, 0x40
/* 00486F8C 8C88000C */  lw    $t0, 0xc($a0)
/* 00486F90 8C8B0008 */  lw    $t3, 8($a0)
/* 00486F94 8C8E0010 */  lw    $t6, 0x10($a0)
/* 00486F98 05010003 */  bgez  $t0, .L00486FA8
/* 00486F9C 000850C3 */   sra   $t2, $t0, 3
/* 00486FA0 25010007 */  addiu $at, $t0, 7
/* 00486FA4 000150C3 */  sra   $t2, $at, 3
.L00486FA8:
/* 00486FA8 AC8A000C */  sw    $t2, 0xc($a0)
/* 00486FAC 05610003 */  bgez  $t3, .L00486FBC
/* 00486FB0 000B60C3 */   sra   $t4, $t3, 3
/* 00486FB4 25610007 */  addiu $at, $t3, 7
/* 00486FB8 000160C3 */  sra   $t4, $at, 3
.L00486FBC:
/* 00486FBC AC8C0008 */  sw    $t4, 8($a0)
/* 00486FC0 05C10003 */  bgez  $t6, .L00486FD0
/* 00486FC4 000E68C3 */   sra   $t5, $t6, 3
/* 00486FC8 25C10007 */  addiu $at, $t6, 7
/* 00486FCC 000168C3 */  sra   $t5, $at, 3
.L00486FD0:
/* 00486FD0 03E00008 */  jr    $ra
/* 00486FD4 AC8D0010 */   sw    $t5, 0x10($a0)

.L00486FD8:
/* 00486FD8 13000009 */  beqz  $t8, .L00487000
/* 00486FDC 00000000 */   nop   
/* 00486FE0 8F898044 */  lw    $t1, %got(D_100118B4)($gp)
/* 00486FE4 00037943 */  sra   $t7, $v1, 5
/* 00486FE8 000FC880 */  sll   $t9, $t7, 2
/* 00486FEC 252918B4 */  addiu $t1, %lo(D_100118B4) # addiu $t1, $t1, 0x18b4
/* 00486FF0 01394021 */  addu  $t0, $t1, $t9
/* 00486FF4 8D0A0000 */  lw    $t2, ($t0)
/* 00486FF8 006A5804 */  sllv  $t3, $t2, $v1
/* 00486FFC 29780000 */  slti  $t8, $t3, 0
.L00487000:
/* 00487000 13000008 */  beqz  $t8, .L00487024
/* 00487004 2C4F00A0 */   sltiu $t7, $v0, 0xa0
/* 00487008 8C8E0004 */  lw    $t6, 4($a0)
/* 0048700C 05C10003 */  bgez  $t6, .L0048701C
/* 00487010 000E68C3 */   sra   $t5, $t6, 3
/* 00487014 25C10007 */  addiu $at, $t6, 7
/* 00487018 000168C3 */  sra   $t5, $at, 3
.L0048701C:
/* 0048701C 03E00008 */  jr    $ra
/* 00487020 AC8D0004 */   sw    $t5, 4($a0)

.L00487024:
/* 00487024 11E00009 */  beqz  $t7, .L0048704C
/* 00487028 24010039 */   li    $at, 57
/* 0048702C 8F888044 */  lw    $t0, %got(D_100118A0)($gp)
/* 00487030 00024943 */  sra   $t1, $v0, 5
/* 00487034 0009C880 */  sll   $t9, $t1, 2
/* 00487038 250818A0 */  addiu $t0, %lo(D_100118A0) # addiu $t0, $t0, 0x18a0
/* 0048703C 01195021 */  addu  $t2, $t0, $t9
/* 00487040 8D4B0000 */  lw    $t3, ($t2)
/* 00487044 004B6004 */  sllv  $t4, $t3, $v0
/* 00487048 298F0000 */  slti  $t7, $t4, 0
.L0048704C:
/* 0048704C 11E00008 */  beqz  $t7, .L00487070
/* 00487050 00000000 */   nop   
/* 00487054 8C8E0008 */  lw    $t6, 8($a0)
/* 00487058 05C10003 */  bgez  $t6, .L00487068
/* 0048705C 000E68C3 */   sra   $t5, $t6, 3
/* 00487060 25C10007 */  addiu $at, $t6, 7
/* 00487064 000168C3 */  sra   $t5, $at, 3
.L00487068:
/* 00487068 03E00008 */  jr    $ra
/* 0048706C AC8D0008 */   sw    $t5, 8($a0)

.L00487070:
/* 00487070 5441001B */  bnel  $v0, $at, .L004870E0
/* 00487074 24010063 */   li    $at, 99
/* 00487078 8C89000C */  lw    $t1, 0xc($a0)
/* 0048707C 8C990008 */  lw    $t9, 8($a0)
/* 00487080 8C8B0010 */  lw    $t3, 0x10($a0)
/* 00487084 05210003 */  bgez  $t1, .L00487094
/* 00487088 000940C3 */   sra   $t0, $t1, 3
/* 0048708C 25210007 */  addiu $at, $t1, 7
/* 00487090 000140C3 */  sra   $t0, $at, 3
.L00487094:
/* 00487094 8C980014 */  lw    $t8, 0x14($a0)
/* 00487098 AC88000C */  sw    $t0, 0xc($a0)
/* 0048709C 07210003 */  bgez  $t9, .L004870AC
/* 004870A0 001950C3 */   sra   $t2, $t9, 3
/* 004870A4 27210007 */  addiu $at, $t9, 7
/* 004870A8 000150C3 */  sra   $t2, $at, 3
.L004870AC:
/* 004870AC AC8A0008 */  sw    $t2, 8($a0)
/* 004870B0 05610003 */  bgez  $t3, .L004870C0
/* 004870B4 000B60C3 */   sra   $t4, $t3, 3
/* 004870B8 25610007 */  addiu $at, $t3, 7
/* 004870BC 000160C3 */  sra   $t4, $at, 3
.L004870C0:
/* 004870C0 AC8C0010 */  sw    $t4, 0x10($a0)
/* 004870C4 07010003 */  bgez  $t8, .L004870D4
/* 004870C8 001878C3 */   sra   $t7, $t8, 3
/* 004870CC 27010007 */  addiu $at, $t8, 7
/* 004870D0 000178C3 */  sra   $t7, $at, 3
.L004870D4:
/* 004870D4 03E00008 */  jr    $ra
/* 004870D8 AC8F0014 */   sw    $t7, 0x14($a0)

/* 004870DC 24010063 */  li    $at, 99
.L004870E0:
/* 004870E0 1441000B */  bne   $v0, $at, .L00487110
/* 004870E4 00000000 */   nop   
/* 004870E8 8C8E0004 */  lw    $t6, 4($a0)
/* 004870EC 24010001 */  li    $at, 1
/* 004870F0 15C10007 */  bne   $t6, $at, .L00487110
/* 004870F4 00000000 */   nop   
/* 004870F8 8C8D0008 */  lw    $t5, 8($a0)
/* 004870FC 05A10003 */  bgez  $t5, .L0048710C
/* 00487100 000D48C3 */   sra   $t1, $t5, 3
/* 00487104 25A10007 */  addiu $at, $t5, 7
/* 00487108 000148C3 */  sra   $t1, $at, 3
.L0048710C:
/* 0048710C AC890008 */  sw    $t1, 8($a0)
.L00487110:
/* 00487110 03E00008 */  jr    $ra
/* 00487114 00000000 */   nop   
    .type ubittobyte, @function
    .size ubittobyte, .-ubittobyte
    .end ubittobyte

glabel set_u_indent
    .ent set_u_indent
/* 00487118 03E00008 */  jr    $ra
/* 0048711C AFA40000 */   sw    $a0, ($sp)
    .type set_u_indent, @function
    .size set_u_indent, .-set_u_indent
    .end set_u_indent
)"");
