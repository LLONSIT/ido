procedure func_0044B384(u8 arg0, s32 arg1);
begin
    case arg0 of                                 /* irregular */
    'a:
        n_parm_regs = arg1;
        return;
    'g:
        if (arg1 < 4) then begin
            report_error("insufficient code generator registers                                           ", "ugen.p                                                                          ");
            n_cg_regs = 4;
            return;
        end;
        n_cg_regs = arg1;
        return;
    'r':
        n_unsaved_regs = arg1;
        return;
    'e':
        n_saved_regs = arg1;
        return;
    otherwise:
        report_error(""illegal register type                                                           ", "ugen.p                                                                          ");
        return;
        return;
    end
end;
