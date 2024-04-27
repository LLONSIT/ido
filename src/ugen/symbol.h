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
    unk8: pointer;
    unkC: u8;
    unk14: integer;
    unk18: integer;
    unk20: integer;
    unk24: integer;
    unk28: pointer;
end;


function lookup_sym(arg0: integer): pointer;   external; { TODO }
procedure report_error(arg0: cardinal; arg1: cardinal; arg2: String; arg3: String); external;
procedure demit_dir0(arg0: cardinal; arg1: integer);  external;
procedure demit_dir1(arg0: cardinal; arg1: integer; arg2: integer);  external;
procedure demit_edata(arg0: integer; arg1: integer; arg2: integer); external;
procedure append_init(arg0: pointer; arg1: pointer); external;


{Source language macros}
#define LANGAUGE_FORTRAN 2

var
    sym_hash_tab: array [0..400] of integer;
    non_local_mtag: integer;
    sdata_max: integer;
    excpt: boolean;



#endif /* SYMBOL_H */
