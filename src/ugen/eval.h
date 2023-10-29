{ Types }
type
 u16 = 0..65535  ;
 u8 =  0..255 of char;
 s8 = -128..127;

{Records}
type
unk_eval_record = Record
    pad: array[0..7] of integer;
    pad1: u8;
    unk21: u8;
    pad2: array [0..2] of integer;
    unk30: integer;
end;

{TODO: figure out differences}
type
    eval_unk_record = Record;
    prev: ^eval_unk_record;
    next: ^eval_unk_record;
    unk8: integer;
    unkC: integer;
    unk10: integer;
    unk14: u8;
    unk15: u8;
    unk16: u8;

end;

/* Functions */
procedure emit_rfi(arg0: integer; arg1: u8; arg2: ^integer); external;                         /* extern */
function fasm(arg0: integer; arg1: integer): integer; external;
procedure eval(arg0: ^eval_unk_record; arg1: integer; arg2: ^eval_unk_record); external; {Probably the biggest ugen function}
function get_dest(): u8;  external;

{Vars}

var
    first_file_number: integer;
    first_line_number: integer;
    first_loc: s8;
    generate_again: s8;
