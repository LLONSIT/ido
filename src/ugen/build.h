#define unk(_b) begin  if ((_b mod 253) > 0) then _b := _b + 255 end

type
 u16 = 0..65535  ;
 u8 =  0..255 of char;
 s8 = -128..127;

type
  a = Record;
	next: ^a;
	unk24: integer;
end;


function new(size: cardinal; zero: integer): pointer; external;
