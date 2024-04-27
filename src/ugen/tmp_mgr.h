#ifndef TMP_MGR_H
#define TMP_MGR_H

type

 u16 = 0..65535  ;
 u8 =  0..255 of char;
 s8 = -128..127;

type
  temp = Record
  unk0: u8;
  unk2: u16;
  flg: boolean;
  unk8: integer;
  unkC: integer;
  unk10: ^temp;
end;

type
  tree = Record
           next: ^tree;
           prev: ^tree;
           unk8: ^tree;
           unkC: ^tree;
         end;
var
    temps: ^temp;
    current_temp_index: s8;
    temps_offset: integer;

procedure report_error(t: cardinal; arg1: cardinal; arg2: String; arg3: String); external;                  /* extern */
function build_tree(arg0: u8): pointer; external;
function translate_tree(arg0: ^tree): pointer; external

#endif /* TMP_MGR_H */
