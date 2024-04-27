#include "ugendata.h"
#include "tree_utils.h"

procedure initialize_tree();
begin
    tree_mark := 0;
    tree_counter := 0;
    label_id_counter := 31;
end;

procedure build_op(arg0: u8);
var
    tmp:  ^o;
begin
    tmp := new_tree;
    tmp^.unk20 := arg0;
end;

procedure free_node(arg0: integer);
begin
    arg0 := 0;
end;

function is_ivalue(arg0: ^tree; arg1: integer; arg2: integer): boolean;
begin
    return is_constant(arg0) and (arg0^.unk30 >= arg1) and  (arg2  >= arg0^.unk30);
end;

function dup_tree(arg0 : ^tree): pointer;
var ret : pointer;
begin
    if(is_constant(arg0) <> false) then begin
        if(arg0^.d.Dtype in [Idt, Kdt, Wdt]) then begin
            ret := ivalue(arg0^.d.Dtype, arg0^.unk30, arg0^.unk34);
        end else begin
            ret := ivalue(arg0^.d.Dtype, 0, arg0^.unk30)
        end;
    end else begin

    {Sanity check}
    if(arg0^.ref_count = 16#FFFF) then begin
            report_error(4, 16#12C, 'tree_utils.p', 'ref_count overflow');
        end else begin
            arg0^.ref_count := arg0^.ref_count + 1;
        end;
        ret := arg0;
    end;
    return ret;
end;
