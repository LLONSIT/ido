#include "frame_offset.h"

function frame_offset(arg0: ^frame): integer;
begin
    if (frame_size = 0) then begin
        return arg0^.unk2C;
    end;
    if (reversed_stack) then begin
        return -(frame_size - arg0^.unk2C);
    end;
    return arg0^.unk2C + frame_size;
end;

function frame_offset1(arg0: integer): integer;
begin
    if (frame_size = 0) then begin
        return arg0;
    end;
    if (reversed_stack) then begin
        return -(frame_size - arg0);
    end;
    return arg0 + frame_size;
end;

