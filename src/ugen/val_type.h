#ifndef REPORT_ERROR_H
#define REPORT_ERROR_H


type
u16 = 0..65535  ;
u8 =  0..255 of char;
s8 = -128..127;


procedure report_error(arg0: Cardinal; arg1: Cardinal; arg2: String; arg3: String); external;
#endif /* REPORT_ERROR_H */
