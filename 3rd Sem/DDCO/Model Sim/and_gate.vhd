library ieee;
use ieee.std_logic_1164.all;

entity AND_Gate is
Port (
	A : in std_logic;
	B : in std_logic;
	C : out std_logic
);
end AND_Gate;

architecture AND_Logic of AND_Gate is
begin 
	C <= A AND B;
end AND_Logic;