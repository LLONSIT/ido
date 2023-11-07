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


var
    temps: ^temp;
    current_temp_index: s8;
    temps_offset: integer;

procedure report_error(t: cardinal; arg1: cardinal; arg2: String; arg3: String); external;                  /* extern */

#endif /* TMP_MGR_H */
