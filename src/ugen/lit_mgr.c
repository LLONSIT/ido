__asm__(R""(
.macro glabel label
    .global \label
    .balign 4
    \label:
.endm

.rdata
RO_1000B170:
    # 0043698C new_lit
    .ascii "Insufficiant memory                                                             "

RO_1000B1C0:
    # 0043698C new_lit
    .ascii "lit_mgr.p                                                                       "

RO_1000B210:
    # 00436D00 add_to_pool
    .ascii "illegal data type                                                               "

RO_1000B260:
    # 00436D00 add_to_pool
    .ascii "lit_mgr.p                                                                       "

    .balign 4
.bss
    .balign 4
# 100213B4
glabel small_strings
    # 004366B0 reset_pool
    # 004367DC output_pool
    # 00436D00 add_to_pool
    .space 4
    .size small_strings, 4
    .type small_strings, @object

    .balign 4
# 100213B8
glabel large_strings
    # 004366B0 reset_pool
    # 004367DC output_pool
    # 00436D00 add_to_pool
    .space 4
    .size large_strings, 4
    .type large_strings, @object

    .balign 4
# 100213BC
glabel floats
    # 004366B0 reset_pool
    # 004367DC output_pool
    # 00436D00 add_to_pool
    .space 4
    .size floats, 4
    .type floats, @object

    .balign 4
# 100213C0
glabel doubles
    # 004366B0 reset_pool
    # 004367DC output_pool
    # 00436D00 add_to_pool
    .space 4
    .size doubles, 4
    .type doubles, @object

    .balign 4
# 100213C4
glabel sets
    # 004366B0 reset_pool
    # 004367DC output_pool
    # 00436D00 add_to_pool
    .space 4
    .size sets, 4
    .type sets, @object


.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.text
glabel new_lit
    .ent new_lit
    # 00436AF8 add_to_list_no_check
    # 00436C4C add_to_list
/* 0043698C 3C1C0FBF */  .cpload $t9
/* 00436990 279C90C4 */  
/* 00436994 0399E021 */  
/* 00436998 27BDFF40 */  addiu $sp, $sp, -0xc0
/* 0043699C 8F9987E8 */  lw    $t9, %call16(new)($gp)
/* 004369A0 AFBF00B4 */  sw    $ra, 0xb4($sp)
/* 004369A4 AFA400C0 */  sw    $a0, 0xc0($sp)
/* 004369A8 AFA500C4 */  sw    $a1, 0xc4($sp)
/* 004369AC AFBC00B0 */  sw    $gp, 0xb0($sp)
/* 004369B0 24050001 */  li    $a1, 1
/* 004369B4 0320F809 */  jalr  $t9
/* 004369B8 24040018 */   li    $a0, 24
/* 004369BC 8FBC00B0 */  lw    $gp, 0xb0($sp)
/* 004369C0 14400041 */  bnez  $v0, .L00436AC8
/* 004369C4 00401825 */   move  $v1, $v0
/* 004369C8 8F8E8038 */  lw    $t6, %got(RO_1000B1C0)($gp)
/* 004369CC 24040004 */  li    $a0, 4
/* 004369D0 2405006A */  li    $a1, 106
/* 004369D4 25CEB1C0 */  addiu $t6, %lo(RO_1000B1C0) # addiu $t6, $t6, -0x4e40
/* 004369D8 25C80048 */  addiu $t0, $t6, 0x48
/* 004369DC 03A0C825 */  move  $t9, $sp
.L004369E0:
/* 004369E0 89D80000 */  lwl   $t8, ($t6)
/* 004369E4 99D80003 */  lwr   $t8, 3($t6)
/* 004369E8 25CE000C */  addiu $t6, $t6, 0xc
/* 004369EC 2739000C */  addiu $t9, $t9, 0xc
/* 004369F0 AB38FFFC */  swl   $t8, -4($t9)
/* 004369F4 BB38FFFF */  swr   $t8, -1($t9)
/* 004369F8 89CFFFF8 */  lwl   $t7, -8($t6)
/* 004369FC 99CFFFFB */  lwr   $t7, -5($t6)
/* 00436A00 AB2F0000 */  swl   $t7, ($t9)
/* 00436A04 BB2F0003 */  swr   $t7, 3($t9)
/* 00436A08 89D8FFFC */  lwl   $t8, -4($t6)
/* 00436A0C 99D8FFFF */  lwr   $t8, -1($t6)
/* 00436A10 AB380004 */  swl   $t8, 4($t9)
/* 00436A14 15C8FFF2 */  bne   $t6, $t0, .L004369E0
/* 00436A18 BB380007 */   swr   $t8, 7($t9)
/* 00436A1C 89D80000 */  lwl   $t8, ($t6)
/* 00436A20 99D80003 */  lwr   $t8, 3($t6)
/* 00436A24 8F898038 */  lw    $t1, %got(RO_1000B170)($gp)
/* 00436A28 03A06025 */  move  $t4, $sp
/* 00436A2C AB380008 */  swl   $t8, 8($t9)
/* 00436A30 BB38000B */  swr   $t8, 0xb($t9)
/* 00436A34 89CF0004 */  lwl   $t7, 4($t6)
/* 00436A38 99CF0007 */  lwr   $t7, 7($t6)
/* 00436A3C 2529B170 */  addiu $t1, %lo(RO_1000B170) # addiu $t1, $t1, -0x4e90
/* 00436A40 252D0048 */  addiu $t5, $t1, 0x48
/* 00436A44 AB2F000C */  swl   $t7, 0xc($t9)
/* 00436A48 BB2F000F */  swr   $t7, 0xf($t9)
.L00436A4C:
/* 00436A4C 892B0000 */  lwl   $t3, ($t1)
/* 00436A50 992B0003 */  lwr   $t3, 3($t1)
/* 00436A54 2529000C */  addiu $t1, $t1, 0xc
/* 00436A58 258C000C */  addiu $t4, $t4, 0xc
/* 00436A5C A98B004C */  swl   $t3, 0x4c($t4)
/* 00436A60 B98B004F */  swr   $t3, 0x4f($t4)
/* 00436A64 892AFFF8 */  lwl   $t2, -8($t1)
/* 00436A68 992AFFFB */  lwr   $t2, -5($t1)
/* 00436A6C A98A0050 */  swl   $t2, 0x50($t4)
/* 00436A70 B98A0053 */  swr   $t2, 0x53($t4)
/* 00436A74 892BFFFC */  lwl   $t3, -4($t1)
/* 00436A78 992BFFFF */  lwr   $t3, -1($t1)
/* 00436A7C A98B0054 */  swl   $t3, 0x54($t4)
/* 00436A80 152DFFF2 */  bne   $t1, $t5, .L00436A4C
/* 00436A84 B98B0057 */   swr   $t3, 0x57($t4)
/* 00436A88 892B0000 */  lwl   $t3, ($t1)
/* 00436A8C 992B0003 */  lwr   $t3, 3($t1)
/* 00436A90 A98B0058 */  swl   $t3, 0x58($t4)
/* 00436A94 B98B005B */  swr   $t3, 0x5b($t4)
/* 00436A98 892A0004 */  lwl   $t2, 4($t1)
/* 00436A9C 992A0007 */  lwr   $t2, 7($t1)
/* 00436AA0 A98A005C */  swl   $t2, 0x5c($t4)
/* 00436AA4 B98A005F */  swr   $t2, 0x5f($t4)
/* 00436AA8 8F998540 */  lw    $t9, %call16(report_error)($gp)
/* 00436AAC 8FA7000C */  lw    $a3, 0xc($sp)
/* 00436AB0 8FA60008 */  lw    $a2, 8($sp)
/* 00436AB4 0320F809 */  jalr  $t9
/* 00436AB8 AFA300B8 */   sw    $v1, 0xb8($sp)
/* 00436ABC 8FBC00B0 */  lw    $gp, 0xb0($sp)
/* 00436AC0 10000009 */  b     .L00436AE8
/* 00436AC4 8FA200B8 */   lw    $v0, 0xb8($sp)
.L00436AC8:
/* 00436AC8 8FA800C4 */  lw    $t0, 0xc4($sp)
/* 00436ACC 8FAE00C0 */  lw    $t6, 0xc0($sp)
/* 00436AD0 00601025 */  move  $v0, $v1
/* 00436AD4 AC680000 */  sw    $t0, ($v1)
/* 00436AD8 8DCF0000 */  lw    $t7, ($t6)
/* 00436ADC AC6F0008 */  sw    $t7, 8($v1)
/* 00436AE0 8DD90004 */  lw    $t9, 4($t6)
/* 00436AE4 AC79000C */  sw    $t9, 0xc($v1)
.L00436AE8:
/* 00436AE8 8FBF00B4 */  lw    $ra, 0xb4($sp)
/* 00436AEC 27BD00C0 */  addiu $sp, $sp, 0xc0
/* 00436AF0 03E00008 */  jr    $ra
/* 00436AF4 00000000 */   nop   
    .type new_lit, @function
    .size new_lit, .-new_lit
    .end new_lit

glabel add_to_list_no_check
    .ent add_to_list_no_check
    # 00436D00 add_to_pool
/* 00436AF8 3C1C0FBF */  .cpload $t9
/* 00436AFC 279C8F58 */  
/* 00436B00 0399E021 */  
/* 00436B04 8F99842C */  lw    $t9, %call16(new_lit)($gp)
/* 00436B08 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 00436B0C AFA40020 */  sw    $a0, 0x20($sp)
/* 00436B10 AFBF001C */  sw    $ra, 0x1c($sp)
/* 00436B14 00A02025 */  move  $a0, $a1
/* 00436B18 AFBC0018 */  sw    $gp, 0x18($sp)
/* 00436B1C 0320F809 */  jalr  $t9
/* 00436B20 00C02825 */   move  $a1, $a2
/* 00436B24 8FA30020 */  lw    $v1, 0x20($sp)
/* 00436B28 8FBC0018 */  lw    $gp, 0x18($sp)
/* 00436B2C 8C6E0000 */  lw    $t6, ($v1)
/* 00436B30 AC4E0010 */  sw    $t6, 0x10($v0)
/* 00436B34 AC620000 */  sw    $v0, ($v1)
/* 00436B38 8FBF001C */  lw    $ra, 0x1c($sp)
/* 00436B3C 27BD0020 */  addiu $sp, $sp, 0x20
/* 00436B40 03E00008 */  jr    $ra
/* 00436B44 00000000 */   nop   
    .type add_to_list_no_check, @function
    .size add_to_list_no_check, .-add_to_list_no_check
    .end add_to_list_no_check

glabel valu_equ
    .ent valu_equ
    # 00436C4C add_to_list
/* 00436B48 8C820000 */  lw    $v0, ($a0)
/* 00436B4C 8CAE0000 */  lw    $t6, ($a1)
/* 00436B50 11C20003 */  beq   $t6, $v0, .L00436B60
/* 00436B54 00000000 */   nop   
/* 00436B58 03E00008 */  jr    $ra
/* 00436B5C 00001025 */   move  $v0, $zero

.L00436B60:
/* 00436B60 10400037 */  beqz  $v0, .L00436C40
/* 00436B64 00401825 */   move  $v1, $v0
/* 00436B68 24630001 */  addiu $v1, $v1, 1
/* 00436B6C 2469FFFF */  addiu $t1, $v1, -1
/* 00436B70 31290003 */  andi  $t1, $t1, 3
/* 00436B74 11200012 */  beqz  $t1, .L00436BC0
/* 00436B78 24020001 */   li    $v0, 1
/* 00436B7C 8CAF0004 */  lw    $t7, 4($a1)
/* 00436B80 8C980004 */  lw    $t8, 4($a0)
/* 00436B84 25280001 */  addiu $t0, $t1, 1
/* 00436B88 01E23021 */  addu  $a2, $t7, $v0
/* 00436B8C 03023821 */  addu  $a3, $t8, $v0
.L00436B90:
/* 00436B90 90D9FFFF */  lbu   $t9, -1($a2)
/* 00436B94 90EAFFFF */  lbu   $t2, -1($a3)
/* 00436B98 24420001 */  addiu $v0, $v0, 1
/* 00436B9C 24C60001 */  addiu $a2, $a2, 1
/* 00436BA0 132A0003 */  beq   $t9, $t2, .L00436BB0
/* 00436BA4 00000000 */   nop   
/* 00436BA8 03E00008 */  jr    $ra
/* 00436BAC 00001025 */   move  $v0, $zero

.L00436BB0:
/* 00436BB0 1502FFF7 */  bne   $t0, $v0, .L00436B90
/* 00436BB4 24E70001 */   addiu $a3, $a3, 1
/* 00436BB8 50430022 */  beql  $v0, $v1, .L00436C44
/* 00436BBC 24020001 */   li    $v0, 1
.L00436BC0:
/* 00436BC0 8CAB0004 */  lw    $t3, 4($a1)
/* 00436BC4 8C8C0004 */  lw    $t4, 4($a0)
/* 00436BC8 01623021 */  addu  $a2, $t3, $v0
/* 00436BCC 01823821 */  addu  $a3, $t4, $v0
.L00436BD0:
/* 00436BD0 90CDFFFF */  lbu   $t5, -1($a2)
/* 00436BD4 90EEFFFF */  lbu   $t6, -1($a3)
/* 00436BD8 24420004 */  addiu $v0, $v0, 4
/* 00436BDC 51AE0004 */  beql  $t5, $t6, .L00436BF0
/* 00436BE0 90CF0000 */   lbu   $t7, ($a2)
/* 00436BE4 03E00008 */  jr    $ra
/* 00436BE8 00001025 */   move  $v0, $zero

/* 00436BEC 90CF0000 */  lbu   $t7, ($a2)
.L00436BF0:
/* 00436BF0 90F80000 */  lbu   $t8, ($a3)
/* 00436BF4 51F80004 */  beql  $t7, $t8, .L00436C08
/* 00436BF8 90D90001 */   lbu   $t9, 1($a2)
/* 00436BFC 03E00008 */  jr    $ra
/* 00436C00 00001025 */   move  $v0, $zero

/* 00436C04 90D90001 */  lbu   $t9, 1($a2)
.L00436C08:
/* 00436C08 90EA0001 */  lbu   $t2, 1($a3)
/* 00436C0C 532A0004 */  beql  $t9, $t2, .L00436C20
/* 00436C10 90CB0002 */   lbu   $t3, 2($a2)
/* 00436C14 03E00008 */  jr    $ra
/* 00436C18 00001025 */   move  $v0, $zero

/* 00436C1C 90CB0002 */  lbu   $t3, 2($a2)
.L00436C20:
/* 00436C20 90EC0002 */  lbu   $t4, 2($a3)
/* 00436C24 24C60004 */  addiu $a2, $a2, 4
/* 00436C28 116C0003 */  beq   $t3, $t4, .L00436C38
/* 00436C2C 00000000 */   nop   
/* 00436C30 03E00008 */  jr    $ra
/* 00436C34 00001025 */   move  $v0, $zero

.L00436C38:
/* 00436C38 1443FFE5 */  bne   $v0, $v1, .L00436BD0
/* 00436C3C 24E70004 */   addiu $a3, $a3, 4
.L00436C40:
/* 00436C40 24020001 */  li    $v0, 1
.L00436C44:
/* 00436C44 03E00008 */  jr    $ra
/* 00436C48 00000000 */   nop   
    .type valu_equ, @function
    .size valu_equ, .-valu_equ
    .end valu_equ

glabel add_to_list
    .ent add_to_list
    # 00436D00 add_to_pool
/* 00436C4C 3C1C0FBF */  .cpload $t9
/* 00436C50 279C8E04 */  
/* 00436C54 0399E021 */  
/* 00436C58 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 00436C5C AFBF0024 */  sw    $ra, 0x24($sp)
/* 00436C60 AFBC0020 */  sw    $gp, 0x20($sp)
/* 00436C64 AFB1001C */  sw    $s1, 0x1c($sp)
/* 00436C68 AFB00018 */  sw    $s0, 0x18($sp)
/* 00436C6C AFA40028 */  sw    $a0, 0x28($sp)
/* 00436C70 AFA60030 */  sw    $a2, 0x30($sp)
/* 00436C74 8C820000 */  lw    $v0, ($a0)
/* 00436C78 00A08825 */  move  $s1, $a1
/* 00436C7C 1040000F */  beqz  $v0, .L00436CBC
/* 00436C80 00000000 */   nop   
/* 00436C84 1040000D */  beqz  $v0, .L00436CBC
/* 00436C88 00408025 */   move  $s0, $v0
.L00436C8C:
/* 00436C8C 8F998434 */  lw    $t9, %call16(valu_equ)($gp)
/* 00436C90 02202025 */  move  $a0, $s1
/* 00436C94 26050008 */  addiu $a1, $s0, 8
/* 00436C98 0320F809 */  jalr  $t9
/* 00436C9C 00000000 */   nop   
/* 00436CA0 10400003 */  beqz  $v0, .L00436CB0
/* 00436CA4 8FBC0020 */   lw    $gp, 0x20($sp)
/* 00436CA8 10000010 */  b     .L00436CEC
/* 00436CAC 8E020000 */   lw    $v0, ($s0)
.L00436CB0:
/* 00436CB0 8E100010 */  lw    $s0, 0x10($s0)
/* 00436CB4 1600FFF5 */  bnez  $s0, .L00436C8C
/* 00436CB8 00000000 */   nop   
.L00436CBC:
/* 00436CBC 8F99842C */  lw    $t9, %call16(new_lit)($gp)
/* 00436CC0 02202025 */  move  $a0, $s1
/* 00436CC4 8FA50030 */  lw    $a1, 0x30($sp)
/* 00436CC8 0320F809 */  jalr  $t9
/* 00436CCC 00000000 */   nop   
/* 00436CD0 8FAF0028 */  lw    $t7, 0x28($sp)
/* 00436CD4 8FBC0020 */  lw    $gp, 0x20($sp)
/* 00436CD8 8DF80000 */  lw    $t8, ($t7)
/* 00436CDC AC580010 */  sw    $t8, 0x10($v0)
/* 00436CE0 8FB90028 */  lw    $t9, 0x28($sp)
/* 00436CE4 AF220000 */  sw    $v0, ($t9)
/* 00436CE8 8FA20030 */  lw    $v0, 0x30($sp)
.L00436CEC:
/* 00436CEC 8FBF0024 */  lw    $ra, 0x24($sp)
/* 00436CF0 8FB00018 */  lw    $s0, 0x18($sp)
/* 00436CF4 8FB1001C */  lw    $s1, 0x1c($sp)
/* 00436CF8 03E00008 */  jr    $ra
/* 00436CFC 27BD0028 */   addiu $sp, $sp, 0x28
    .type add_to_list, @function
    .size add_to_list, .-add_to_list
    .end add_to_list
)"");
