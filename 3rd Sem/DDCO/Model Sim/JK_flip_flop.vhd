library ieee;
use ieee.std_logic_1164.all;

entity jkff is
port(j, k, clk, rst: in std_logic;
	q: out std_logic);

end jkff;

architecture djkff of jkff is
signal q_int : std_logic := '0';
begin 
	process(clk, rst)
	begin
	if rst = '1' then
		q_int <= '0';
	elsif rising_edge(clk) then
		if j = '0' and k = '0' then
			q_int <= q_int;
		elsif j = '0' and k = '1' then
			q_int <= '0';
		elsif j = '1' and k = '0' then
			q_int <= '1';
		else
			q_int <= not q_int;
		end if;
	end if;
	end process;
end djkff;	