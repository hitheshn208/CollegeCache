library ieee;
use ieee.std_logic_1164.all;

entity Full_Adder is
Port (
	A, B, Cin : in std_logic;
	SUM, Cout : out std_logic
);
end Full_Adder;

architecture FA_Logic of Full_Adder is
begin 
	SUM <= A XOR B XOR Cin;
	Cout <= (A AND B) OR (B AND Cin) OR (A AND Cin);
end FA_Logic;