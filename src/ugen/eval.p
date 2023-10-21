#include "eval.h"

procedure init_eval();
begin
    first_loc := 1;
    first_file_number := 0;
    first_line_number := 0;
    generate_again := 0;
end;

procedure load_fp_literal(arg0: ^unk_eval_record; arg1: u8);
begin
    arg1 := get_dest();
    emit_rfi(fasm(16#FC, arg0^.unk21 & 16#1F), arg1, addr(arg0^.unk30));
end;

