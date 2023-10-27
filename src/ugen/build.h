#ifndef BUILD_H
#define BUILD_H
type
 u16 = 0..65535  ;
 u8 =  0..255 of char;
 s8 = -128..127;

type
rec_0040E280 = Record;

    unk0: integer;
    unk4: integer;
    unk8: ^rec_0040E280;

end;

type
util = Record;
    next: ^util; /* 0x0 */
    pad: array [0..7] of integer; /* pad */
    unk24: integer; /* 0x24*/
end;

var
    strp: pointer;
    domtag: s8;
    label_hash_table: array [0..4] of ^util;



function new(size: cardinal; zero: integer): pointer; external;
#endif /* BUILD_H */
