library ieee;
use ieee.std_logic_1164.all;

entity Half_Adder is 
Port (
	A,B : in std_logic;
	CARRY, SUM : out std_logic
);
end Half_Adder;

architecture HA_logic of Half_Adder is
begin
	SUM <= A XOR B;
	CARRY <= A AND B;
end HA_logic;