LIBRARY ieee;
USE ieee.std_logic_1164.all;

-- VHDL code represents an 8 to 1 multiplexor, which enters in any 3 bit value (from 0 to 7), and will output
-- the value corresponding to the data connected to whatever is inputted into the multiplexor. The data value should match
-- with the 3 bit value if it is being decoded.

Entity mux8to1 IS
  port(data : INSTD_LOGIC_VECTOR(7 downto 0);
       sel : INSTD_LOGIC_VECTOR(1 downto 0);
       output : OUTSTD_LOGIC);
 END mux8to1;
 
Architecture behavior OF mux8to1 IS
Begin
  Process(data, sel)
  Begin
    Case sel IS 
      WHEN "000" => output <= data(0);
      WHEN "001" => output <= data(1);
      WHEN "010" => output <= data(2);
      WHEN "011" => output <= data(3);
      WHEN "100" => output <= data(4);
      WHEN "101" => output <= data(5);
      WHEN "110" => output <= data(6);
      WHEN "111" => output <= data(7);
      WHEN others => output <= 0;
    END Case;
  End Process;
End behavior;
