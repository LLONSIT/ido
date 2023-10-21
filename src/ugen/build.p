#include "build.h"

{Vars}
var
    strp: pointer;
    domtag: s8;
    label_hash_table: array [0..4] of ^a;

procedure set_domtag(arg0: s8);
begin
    domtag := arg0;
end;

procedure init_build();
begin
    strp := new(16#400, 0);
end;

{
function search_label(arg0: integer): pointer;
var
    var_t6: integer;
    var_v1: ^a;
begin
    unk(arg0);
     var_v1 := label_hash_table[(arg0 & 255)];
    while (var_v1 <> nil)  do begin

        if (arg0 = var_v1^.unk24) then begin
            break;
        end;
     var_v1 := var_v1^.next;
    end;
    return var_v1;
end;
}
