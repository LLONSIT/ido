#include "ugen.h"

procedure func_0044B384(chr: char; regs: integer);
begin
    case chr of                                 /* irregular */

    'a':
    begin
        n_parm_regs := regs;
    end;

    'g':
    begin
        if (regs < 4) then begin
            report_error(4, 16#8A, "insufficient code generator registers", "ugen.p");
            n_cg_regs := 4;
        end else begin
             n_cg_regs := regs; 
        end;
    end;

    'r':
    begin
        n_unsaved_regs := regs;
    end;

   'e':
    begin
        n_saved_regs := regs;
    end;

   ' ':
    otherwise:
    begin
        report_error(4, 16#9A, "illegal register type", "ugen.p");

    end;

    end;
end;
