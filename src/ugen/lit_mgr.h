#ifndef LIT_MGR_H
#define LIT_MGR_H
type
 u16 = 0..65535  ;
 u8 =  0..255 of char;
 s8 = -128..127;

type
    Pool_list = Record
    unk0: integer;
    pad: integer;
    pad1: integer16;
    unk8: integer ;
    unk10: ^Pool_list;

end;

var
      doubles: integer;
      floats: integer;
      large_strings: integer;
      sets: integer;
      small_strings: integer;
      sdata_max: integer;

function create_local_label(list: integer): integer; external;                        /* extern */
procedure emit_val(list: integer; chr: char; arg2: integer; arg3: integer); external;                     /* extern */
procedure demit_dir0(arg0: integer; arg1: integer); external;
procedure demit_dir1(arg0: integer; arg1: integer; arg2: integer);  external;


#endif /*LIT_MGR_H */
