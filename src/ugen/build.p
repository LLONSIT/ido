#include "build.h"



procedure set_domtag(arg0: s8);
begin
    domtag := arg0;
end;

procedure init_build();
begin
    strp := new(16#400, 0);
end;

function search_label(index: cardinal): pointer;
var
    label_hash_iterator: ^util;
begin
{ To note:
    Why does SGI Pascal generate this strange patern
        if index mod 253 then
            index := 253;   //then we have some cardinal vs integer issues
    }
    label_hash_iterator := label_hash_table[(index mod 253) & 255];
    while (label_hash_iterator <> nil) do begin
        if (index = label_hash_iterator^.unk24) then begin
            break;
        end;
     label_hash_iterator := label_hash_iterator^.next;
    end;
    return label_hash_iterator;
end;


procedure func_0040E280(arg0: ^rec_0040E280; arg1: ^rec_0040E280); internal;
var
    iterator: ^rec_0040E280;
    rec_temp:  ^rec_0040E280; {Record temporary var}
begin
    rec_temp := arg0^.unk8;
    arg0^.unk8 := arg1;
    iterator := arg1^.unk8;

    while(iterator <> nil) do begin
            arg1 := iterator;
            iterator := iterator^.unk8;
        end;
        arg1^.unk8 := rec_temp;

end;
