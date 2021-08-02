LIBRARY ieee;
USE ieee.std_logic_1164.all;

-- VHDL code represents a D-latch, which the output (Q) will become whatever D is whenever the enable (or clock) 
-- is 1. If the Enable is 0, then the output will maintain whatever value it was currently at until the next rising edge 
-- of the clock

-- This is a D-latch with an enable, not a clock (rising edge is not consistent with a clock)
Entity MyDLatch IS
  port( D : IN STD_LOGIC;
        Enable : IN STD_LOGIC;
        Qout : INOUT STD_LOGIC);
END MyDLatch;

Architecture func OF MyDLatch IS
BEGIN 
  Process(D, Enable)
  BEGIN
    IF (Enable = '1') THEN
      Qout <= D;
    ELSE 
      Qout <= Qout;
    END IF;
  END Process;
END func;
