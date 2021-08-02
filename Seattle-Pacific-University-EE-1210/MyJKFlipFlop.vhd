LIBRARY ieee;
USE ieee.std_logic_1164.all;

-- this VHDL code represents a JK-FlipFlop, which means that depending on what the enable or clock is, the output will either be
-- set, reset, held, or toggled, all determined by whether or not J or K are 0 or 1.

Entity MyJKFlipFlop IS
  port( J : IN STD_LOGIC;
        K : IN STD_LOGIC;
        Clock : IN STD_LOGIC;
        Output : INOUT STD_LOGIC;
        NotOutput : OUT STD_LOGIC);
END MyJKFlipFlop;

Architecure func OF MyJKFlipFlop IS
BEGIN
  Process(Clock)
  BEGIN
    IF (RISING_EDGE(Clock)) THEN
      IF(J = '0' AND K = '0') -- output is held to what it currently is on rising edge
        THEN Output <= Output;
      ELSIF(J = '0' AND K = '1')
        THEN Output <= '0'; -- output is reset (set to 0 on rising edge clock)
      ELSIF(J = '1' AND K = '0')
        THEN Output <= '1'; -- output is set (set to 1 on rising edge clock)
      ELSIF(J = '1' AND K = '1')
        THEN Output <= NOT(Output); -- output is toggled (opposite of current output state on rising edge)
      END IF;
    NotOutput <= NOT(Output); -- this is showing right now the not of output (or not(q) in models), just to complete the FlipFlop
    END IF;
  END Process;
END func;
