#ifndef TREE_UTILS_H
#define TREE_UTILS_H
{Types and records}
type
 u16 = 0..65535  ;
 u8 =  0..255 of char;
 s8 = -128..127;

 type
o = Record
    pad: array [0..7] of integer;
    unk20: s8;
end;

var
    label_id_counter: integer;
    tree_counter: integer;
    tree_mark: integer;


function new_tree(): pointer; external;
#endif /* TREE_UTILS_H */
