#ifndef UGEN_H
#define UGEN_H


type

 u16 = 0..65535  ;
 u8 =  0..255 of char;
 s8 = -128..127;


var
    n_parm_regs: integer;
    n_cg_regs: integer;
    n_unsaved_regs: integer;
    n_saved_regs: integer;

procedure report_error(chr: cardinal; regs: cardinal; arg2: String; arg3: string); external;

#endif /* UGEN_H */
