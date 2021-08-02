LIBRARY ieee;
USE ieee.std_logic_1164.all;

-- VHDL code replicates an 8 bit Priority Encoder, which exactly one value of the 8 bit input is 1, and 
-- the output matches that input. If all are zeros or there is special case in input, then we add extra output that equals 1. 

Entity PriorityEncoder8 IS 
  port( priorityVal : INSTD_LOGIC_VECTOR(7 downto 0);
        output : OUTSTD_LOGIC_VECTOR(2 downto 0);    
        worstCaseOut: OUTSTD_LOGIC);
END PriorityEncoder8;

Architecture func OF PriorityEncoder8 IS 
Begin
  Process(priorityVal)
  Begin
    IF (priorityVal(0) = '1') THEN output <= "000"; worstCaseOut = 0;
    ELSIF (priorityVal(1) = '1') THEN output <= "001"; worstCaseOut = 0;
    ELSIF (priorityVal(2) = '1') THEN output <= "010"; worstCaseOut = 0;
    ELSIF (priorityVal(3) = '1') THEN output <= "011"; worstCaseOut = 0;
    ELSIF (priorityVal(4) = '1') THEN output <= "100"; worstCaseOut = 0;
    ELSIF (priorityVal(5) = '1') THEN output <= "101"; worstCaseOut = 0;
    ELSIF (priorityVal(6) = '1') THEN output <= "110"; worstCaseOut = 0;
    ELSIF (priorityVal(7) = '1') THEN output <= "111"; worstCaseOut = 0;
    ELSE output <= "000"; worstCaseOut = 1;
    END IF;
  END Process;
END func;
