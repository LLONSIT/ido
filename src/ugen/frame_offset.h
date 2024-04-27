#ifndef FRAME_H
#define FRAME_H
type
 u16 = 0..65535  ;
 u8 =  0..255 of char;
 s8 = -128..127;

type
frame = Record
    pad: array [0..40] of u8;
    unk2C: integer;
end;

var
frame_size: integer;
reversed_stack: boolean;
#endif /* FRAME_H */
