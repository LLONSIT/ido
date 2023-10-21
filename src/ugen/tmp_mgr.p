#include "tmp_mgr.h"

procedure init_temps();
begin
    temps := pointer(0); {lol}
    current_temp_index := 1;
end;

function lookup_temp(arg0: s8): pointer; {SGI Pascal s8 subtype}
var
    i: ^temp;
begin
    i := temps;
    while (i <> nil) do begin
        if ((arg0 = i^.unk0) and (i^.unk4 = false)) then begin
            return i;
        end;
            i := i^.unk10;
    end;
    return nil;
end;

function get_temp_area_size(): integer;
var
    var_v1: integer;
    i: ^temp;
begin
    var_v1 := 0;
    i := temps;

    while (i <> nil) do begin
        var_v1 := var_v1 + i^.unk8;
        i := i^.unk10; {Could use a cast too}
    end;
    return var_v1;
end;

procedure set_temps_offset(arg0: integer);
begin
    temps_offset := arg0;
end;

function find_free_temp(arg0: integer): pointer;
var
    i: ^temp;
begin
    i := temps;
    while (i <> nil) do begin
        if ((i^.unk4) and (arg0 = i^.unk8)) then begin
            i^.unk4 := false;
            return i;
        end;
        i := i^.unk10
    end;
    return nil;
end;
