library ieee;
use ieee.std_logic_1164.all;

entity NOTgg is 
Port (
	A : in std_logic;
	B : out std_logic
);
end NOTgg;

architecture Behavioral of NOTgg is
begin 
	B <= NOT A;
end Behavioral;