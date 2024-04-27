#include "reg_mgr.h"

var
    kind_tab:  array [0..4] of u8;
    restricted_regs: array [0..16#49] of integer; {These should be "Static"}
    restricted_fp_regs : array [0..16#49] of integer;

procedure clear_restricted_regs();
var
i: integer;
begin
    for i:= 0 to 72 do begin
        restricted_regs[i] := 0;
        restricted_fp_regs[i] := 0;
    end;
end;

procedure restricted_reg(arg0: u8);
begin
    restricted_regs[arg0] := restricted_regs[arg0]  + 1;
end;

procedure restricted_fp_reg(arg0: u8);
begin
    restricted_fp_regs[arg0] := restricted_fp_regs[arg0]  + 1;
end;

function get_reg_kind(arg0: u8): u8;
begin
    return kind_tab[arg0];
end;

function list_is_empty(arg0: ^u8): boolean;
begin
    return arg0^ = 16#48;
end;
