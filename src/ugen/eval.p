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
{
procedure test_rperror();
begin
    report_error("AN ERROR HAS BEEN REPORTED", "eval.p", 60);
end;
}

procedure eval_2ops(arg0: ^eval_unk_record);
begin
    if (arg0^.prev^.unk16 >= arg0^.next^.unk16) then begin
        eval(arg0^.prev, 16#48, arg0);
        eval(arg0^.next, 16#48, arg0);
        return;
    end;
    eval(arg0^.next, 16#48, arg0);
    eval(arg0^.prev, 16#48, arg0);
end;

