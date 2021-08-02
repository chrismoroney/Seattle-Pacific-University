-- This VHDL code represents full addition in binary, which now includes a carry in number, differing from the half adder
-- (10 + 10 now equals 100)

Entity FullAdder IS
  port(X, Y, Cin: in bit; Sum, Cout: out bit);
End Entity FullAdder;

Architecture behavior OF FullAdder IS
Begin
  Sum <= (X xor Y xor Cin);
  Cout <= (X and Y) or (X and Cin) or (Y and Cin);
End Architecture behavior;
