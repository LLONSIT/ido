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

function get_mtag(): integer;
var
    var_v1: integer;
    temp_v0: ^sym_1;
begin
    temp_v0 := lookup_sym();
    if (temp_v0 <> nil) then begin
        var_v1 := temp_v0^.unk14;
    end else begin
        var_v1 := non_local_mtag;
    end;
    return var_v1;
end;

function get_sym_kind(): boolean;
var
    var_v1: boolean;
    temp_v0: ^sym_1;
begin
    temp_v0 := lookup_sym();
    if (temp_v0 <> nil) then begin
        var_v1 := temp_v0^.unkC;
    end else begin
        var_v1 := false;
    end;
    return var_v1;
end;
