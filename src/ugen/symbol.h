#ifndef SYMBOL_H
#define SYMBOL_H
{Types and records}
type
 u16 = 0..65535  ;
 u8 =  0..255 of char;
 s8 = -128..127;

type
sym_1 = Record
    unk0: integer;
    unk4: integer;
    unk8: integer;
    unkC: boolean;
    unk14: integer;
end;


function lookup_sym(): pointer;   external;

{Source language macros}
#define LANGAUGE_FORTRAN 2

var
    sym_hash_tab: array [0..400] of integer;
    non_local_mtag: integer;



#endif /* SYMBOL_H */
