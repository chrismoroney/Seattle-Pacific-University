LIBRARY ieee;
USE ieee.std_logic_1164.all;

-- this VHDL code is just like the other D-latch, but using a clock as the enable, which means that the output changes based on 
-- the rising edge of the clock, otherwise maintaining what the current output was.

Entity MyClockDLatch IS
  port( D : IN STD_LOGIC;
        Clock : IN STD_LOGIC;
        Qout : INOUT STD_LOGIC);
END MyClockDLatch;

Architecture func OF MyClockDLatch IS
BEGIN 
  Process(Clock)
  BEGIN
    IF (RISING_EDGE(Clock)) THEN
      Qout <= D;
    END IF;
  END Process;
END func;
