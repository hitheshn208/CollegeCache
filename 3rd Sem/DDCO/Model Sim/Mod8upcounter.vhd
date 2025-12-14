library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity mod8c is 
Port(
	Clk, Rst, En : in std_logic;
	count : out std_logic_vector(2 downto 0)
);
end mod8c;

architecture mod8_logic of mod8c is
signal count_reg : unsigned (2 downto 0) := (others => '0');
begin
	process(Clk, Rst)
	begin
		if Rst = '1' then
			count_reg <= (others => '0');
		elsif rising_edge(Clk) then
			if En = '1' then
				count_reg <= count_reg + 1;
			end if;
		end if;
	end process;
	count <= std_logic_vector(count_reg);
end mod8_logic;