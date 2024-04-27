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
            emit_val(create_local_label(integer(list^.unk0)), chr, integer(list) + 8, 1);
            list := pointer(list^.unk10);
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

function add_to_pool(arg0: ^Pool_list; arg1: integer): integer;
var
    temp_v1_2: integer;
    bool: integer;
    temp_v1: u8;
begin
    bool := integer(arg0^.unk0 = 'I'); {This is probably using some enum here}
    if (bool = 0) then begin
        bool := integer(arg0^.unk0 = 'F');
    end;
    Assert(boolean(bool));
    case arg0^.unk1 & 16#1F & 255 of
    9:
        begin
        if (sdata_max <  arg0^.unk10) then begin
            add_to_list_no_check(addr(large_strings), integer(arg0) + 16, arg1);
        end else 
        add_to_list_no_check(addr(small_strings), integer(arg0) + 16, arg1);
            return arg1;
        end;
    12:
        return add_to_list(addr(doubles), integer(arg0) + 16, arg1);
    13:
        return add_to_list(addr(floats), integer(arg0) + 16, arg1);
    14:
        return add_to_list(addr(sets), integer(arg0) + 16, arg1);
    otherwise:
        begin
        report_error(4, 186, "lit_mgr.p", "illegal data type");
        return 0;
        end;
    end;
end;
