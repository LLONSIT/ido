#include "reg_mgr.h"

var
    kind_tab:  array [0..4] of u8;

function get_reg_kind(arg0: u8): u8;
begin
    return kind_tab[arg0];
end;

function list_is_empty(arg0: ^u8): boolean;
begin
    return arg0^ = 16#48;
end;
