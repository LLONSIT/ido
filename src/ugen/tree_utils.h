#ifndef TREE_UTILS_H
#define TREE_UTILS_H
{Types and records}

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
function is_constant(arg0: ^tree): boolean; external;
function ivalue(arg0: Datatype; arg1: integer; arg2: integer): pointer; external;
procedure report_error(chr: cardinal; regs: cardinal; arg2: String; arg3: string); external;
#endif /* TREE_UTILS_H */
