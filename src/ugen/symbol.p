#include "symbol.h"

function get_sym_type(arg0: ^u8): integer;
var
    temp_v0: u8;
begin
    temp_v0 := arg0^;
    if (temp_v0 = 83) or (temp_v0 = 39) then begin
        return 4;
    end;
    if temp_v0 = 42 then begin
        return 2;
    end;
    if temp_v0 = 152 then begin
        return 3;
    end;
    if temp_v0 = 153 then begin
        return 6;
    end;
    if temp_v0 = 150 then begin
        return 5;
    end;
    if temp_v0 = 36 then begin
        return 1;
    end;
    if temp_v0 = 6 then begin
        return 8;
    end;
    if temp_v0 = 20 then begin
        return 7;
    end;
    if temp_v0 = 33 then begin
        return 9;
    end;
    return 0;
end;

function change_sym_type(arg0: s8; arg1: s8): integer;
begin
    if ((arg0 = 1) or ((arg0 = 4) and (arg1 = 7))) then begin
        return arg1;
    end;
    return arg0;
end;

procedure clear_sym_tab();
var
    i : integer;
begin
    for i := 0 to 255 do begin
        sym_hash_tab[i] := 0;
    end;

end;

function get_mtag(arg0: integer): integer;
var
    var_v1: integer;
    temp_v0: ^sym_1;
begin
    temp_v0 := lookup_sym(arg0);
    if (temp_v0 <> nil) then begin
        var_v1 := temp_v0^.unk14;
    end else begin
        var_v1 := non_local_mtag;
    end;
    return var_v1;
end;

procedure add_init(arg0: ^sym_1);
begin
    append_init(lookup_sym(arg0^.unk4), arg0);
end;

{Lol}
{#line 725 symbol.p }
procedure choose_area(arg0: u8; arg1: integer);
var
    val: integer;
begin
    val := arg0 & 255;
    case val of
    0:
        if (sdata_max < arg1) then begin
            demit_dir0(16#A, 0);
        end else begin
            demit_dir0(16#19, 0);
        end;
    1:
        demit_dir0(16#1A, 0);
    2:
        demit_dir0(16#19, 0);
    3:
        demit_dir0(16#A, 0);
    4:
        demit_dir0(16#15, 0);
    5:
        if (excpt) then begin
            demit_edata(0, 0, 0);
        end;
    end;
end;

{TODO}

procedure force_alignment(arg0: u8);
begin
    if (arg0 <> 0) then begin
        demit_dir1(4, 0, arg0);
    end;
    demit_dir1(4, 0, 0);
end;


function get_sym_kind(arg0: integer): u8;
var
    var_v1: u8;
    temp_v0: ^sym_1;
begin
    temp_v0 := lookup_sym(arg0);
    if (temp_v0 <> nil) then begin
        var_v1 := temp_v0^.unkC;
    end else begin
        var_v1 := 0;
    end;
    return var_v1;
end;


procedure change_label_number(arg0: integer ; arg1: integer);
var
    temp_v0: ^sym_1;
begin
    temp_v0 := lookup_sym(arg0);
    if (temp_v0 = nil) then begin
        report_error(4, 1018, "symbol.p", "label not found in symbol table");
        return;
    end;
    temp_v0^.unk4 := -arg1;
end;


procedure output_entry_point(arg0: integer);
var
    temp_v0: ^sym_1;
    var_s0: ^sym_1;
begin

    temp_v0 := lookup_sym(arg0);
    if (temp_v0 = nil) then begin
        report_error(4, 999, "symbol.p", "symbol not found");
        return;
    end;

    demit_dir0(0, arg0);
    var_s0 := temp_v0^.unk28;
    while (var_s0 <> nil) do begin
            if (temp_v0^.unkC = 10) then begin
                demit_dir0(2, var_s0^.unk0);
            end;
            demit_dir0(0, var_s0^.unk0);
            var_s0 := var_s0^.unk8;
        end;
end;
