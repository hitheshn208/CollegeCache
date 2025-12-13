library ieee;
use ieee.std_logic_1164.all;

entity D_ff is 
Port (
	D : in std_logic;
	Clk : in std_logic;
	Rst : in std_logic;
	Q : out std_logic

);
end D_ff;

architecture Dff_logic of D_ff is
begin 
	process(Clk,Rst)
	begin
	if Rst = '1' then
		Q <= '0';
	elsif rising_edge(Clk) then
		Q <= D;
	end if;
	end process;
end Dff_logic;