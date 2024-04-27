#include "val_type.h"

function find_val_type(arg0: u8; arg1: integer): u8;
var
    temp_v0: cardinal;
begin
    temp_v0 := arg0 & 255;
    case temp_v0 of
    5..8:
    begin
        if (arg1 = 1) then begin
            return 1;
        end;
        if (arg1 < 3) then begin
            return 2;
        end;
        if (arg1 < 5) then begin
            return 3;
        end;
        return 4;
    end;
     0..4:
        return 3;
    15:
        return 4;
    13:
        return 5;
    12:
        return 6;
    9:
        return 7;
    10:
        return 8;
    14:
        return 9;
    16:
        report_error(4, 16#F2, "val_util.p", "extended floating point not yet supported");
    otherwise:
        report_error(4, 16#F8, "val_util.p", "unknown data type");
    end;
end;
