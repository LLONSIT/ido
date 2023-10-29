#ifndef LOOP_HEADER_H
#define LOOP_HEADER_H

type
 u16 = 0..65535  ;
 u8 =  0..255 of char;
 s8 = -128..127;

 type
 b = Record;
    unk0: integer; {0x0}
    unk4: integer; {0x4}
    node: ^b; {0x8}
    node1: ^b; {0xC}
end;

procedure build_2op(arg0: u8; arg1: pointer; arg2: integer);  external;

#endif /* LOOP_HEADER_H */
