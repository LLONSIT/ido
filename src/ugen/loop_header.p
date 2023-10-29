#include "loop_header.h"

procedure insert(arg0: ^b; arg1: ^b);
begin
    arg0^.node := arg1;
    arg0^.node1 := arg1^.node1;
    arg0^.node1^.node := arg0;
    arg1^.node1 := arg0;
end;

procedure append(arg0 : ^b; arg1: ^b);
begin
    arg0^.node1 := arg1;
    arg0^.node := arg1^.node;
    arg1^.node := arg0;
    arg0^.node^.node1 := arg0;
end;

procedure move_label(arg0: ^b; arg1: ^b);
begin
    arg0^.node1^.node := arg0^.node;
    arg0^.node^.node1 := arg0^.node1;
    insert(arg0, arg1); {Just filling...}
end;

{
procedure make_new_jump(arg0: integer);
begin
    build_2op(16#88, nil, arg0);
end;
}
