#include "lit_mgr.h"

procedure reset_pool();
begin
    small_strings := 0;
    large_strings := 0;
    floats := 0;
    doubles := 0;
    sets := 0;
end;

procedure select_data_section(arg0: integer);
begin
    if (sdata_max >= arg0) then begin
        demit_dir0(25, 0);
        return;
    end;
    demit_dir0(10, 0);
end;

procedure emit_list(list: ^Pool_list;  chr: char); {Not a subtype}
begin
    while (list <> nil) do begin {Most likely?}
            emit_val(create_local_label(list^.unk0), chr, integer(list) + 8, 1);
            list := list^.unk10;
           end;
end;

procedure output_pool();
begin
    if (floats <> 0) then begin
        select_data_section(4);
        demit_dir1(4, 0, 2);
        emit_list(pointer(floats), chr(5));
    end;
    if (doubles <> 0) then begin
        select_data_section(8);
        demit_dir1(4, 0, 3);
        emit_list(pointer(doubles), chr(6));
    end;
    if (sets <> 0) then begin
        select_data_section(8);
        demit_dir1(4, 0, 2);
        emit_list(pointer(sets), chr(9));
    end;
    if (small_strings <> 0) then begin
        demit_dir0(16#19, 0);
        emit_list(pointer(small_strings), chr(7));
    end;
    if (large_strings <> 0) then begin
        demit_dir0(16#1A, 0);
        emit_list(pointer(large_strings), chr(7));
    end;
end;
