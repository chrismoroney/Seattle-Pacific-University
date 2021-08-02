LIBRARY ieee;
USE ieee.std_logic_1164.all;

-- this VHDL code represents a 3 bit counter that switches betwen 8 different states. The counters can be between 0 to 7 in 
-- binary code
-- The transition pattern is 000 - 111 - 001 - 110 - 010 - 101 - 011 - 100 - 000 ...
-- States given corresponding to the number above in description (A is 000, B is 111 etc).

Entity CustomCnt IS
  port( Clock : IN STD_LOGIC;
        Reset : IN STD_LOGIC;
        Output : OUT STD_LOGIC_VECTOR(2 downto 0));
END CustomCnt;

Architecture func OF CustomCnt IS
TYPE state_type IS (A, B, C, D, E, F, G, H); -- states initialized here
SIGNAL state : state_type;
BEGIN 
  Process(Reset, Clock)
  BEGIN
    IF(Reset = '1') THEN
      State <= A;
      Output <= 000;
    ELSIF(RISING_EDGE(Clock)) THEN
      CASE state IS 
        WHEN A => state <= B; Output <= 111; -- all output states transition to the next (A to B, B to C etc), and the output
        WHEN B => state <= C; Output <= 001; -- changes to the next state's output (000 to 111 etc). 
        WHEN C => state <= D; Output <= 110; 
        WHEN D => state <= E; Output <= 010; 
        WHEN E => state <= F; Output <= 101; 
        WHEN F => state <= G; Output <= 011; 
        WHEN G => state <= H; Output <= 100; 
        WHEN H => state <= A; Output <= 000; 
      END CASE;
    END IF;
  END Process;
END func;
