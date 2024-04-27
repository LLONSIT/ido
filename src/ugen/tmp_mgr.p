#include "tmp_mgr.h"

procedure init_temps();
begin
    temps := nil; {lol}
    current_temp_index := 1;
end;

function lookup_temp(arg0: s8): pointer; {SGI Pascal s8 subtype}
var
    i: ^temp;
begin
    i := temps;
    while (i <> nil) do begin
        if ((arg0 = i^.unk0) and (i^.flg = false)) then begin
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
        if ((i^.flg) and (arg0 = i^.unk8)) then begin
            i^.flg := false;
            return i;
        end;
        i := i^.unk10
    end;
    return nil;
end;

procedure free_temp(t: s8); {Guess}
var
     tP: ^temp;
begin
    tP := lookup_temp(t);
    if (tP = nil) then begin
        report_error(4, 192, 'tmp_mgr.p', 'temporary not found');
        return;
    end;
    tP^.flg := true;
end;

function temp_offset(arg0: s8): integer;
var
    temp_v0: ^temp;
begin
    temp_v0 := lookup_temp(arg0);
    if (temp_v0 = nil) then begin
        report_error(4, 204, 'tmp_mgr.p', 'temporary not found');
    end else begin
        return temp_v0^.unkC;
    end;
end;

function temp_usage_count(arg0: s8): u16;
var
    temp_v0: ^temp;
begin
    temp_v0 := lookup_temp(arg0);
    if (temp_v0 = nil) then begin
        report_error(4, 216, 'tmp_mgr.p', 'temporary not found');
    end else begin
    return temp_v0^.unk2;
    end;
end;
