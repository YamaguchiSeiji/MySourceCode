library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity compare is
	port(
		A, B: in std_logic_vector(1 downto 0);
		W, X, Y: out std_logic);
end compare;

architecture rtl of compare is 
begin
	process(A, B)
	begin
		if(A > B) then
			W <= '1';
			X <= '0';
			X <= '0';
		elsif(A = B) then
			X <= '1';
			W <= '0';
			Y <= '0';
		else
			Y <= '1';
			X <= '0';
			W <= '0';
		end if;
	end process;
end rtl;	
