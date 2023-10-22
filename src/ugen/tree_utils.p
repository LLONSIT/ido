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

