#ifndef TMP_MGR_H
#define TMP_MGR_H

type

 u16 = 0..65535  ;
 u8 =  0..255 of char;
 s8 = -128..127;

type
    temp = Record
  unk0: u8;
  pad1: u16;
  unk4: boolean;
  unk8: integer;
  pad: integer;
  unk10: ^temp;
end;


var
    temps: ^temp;
    current_temp_index: s8;
    temps_offset: integer;

#endif /* TMP_MGR_H */
