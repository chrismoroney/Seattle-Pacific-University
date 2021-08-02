LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_unsigned.all; -- to be able to do math

-- This VHDL code shows a Counter with 3 bits, which should be toggling between all binary numbers between 000 and 111

Entity SimpleCounter3Bit IS 
  port( Clock : IN STD_LOGIC;
        Enable : IN STD_LOGIC;
        Output : OUT STD_LOGIC_VECTOR(7 downto 0)); -- max output can be is 7, least is 0
END SimpleCounter3Bit;

Architecture func of SimpleCounter3Bit IS     -- given this is an 3 bit counter, we are simulating the counts from 0 to 7
Signal Counter : STD_LOGIC_VECTOR(7 downto 0) -- we use this signal so that we can actively change this before setting it 
BEGIN                                         -- so that we can then send a "snapshot" of the output to output.
  Process(Clock)
  BEGIN
    IF (RISING_EDGE(Clock)) THEN
      IF (Enable = '1') THEN 
        Counter <= Counter + 1; -- if we are on the rising edge and our enable is on, then we are showing that all the previous
      ELSE                      -- bits are 1, which means that we should toggle the next bit...
        Counter <= Counter;     -- ... Otherwise we maintain our current bit count
      END IF;
    END IF;
  END Process;
  Output <= Counter;
END func;
