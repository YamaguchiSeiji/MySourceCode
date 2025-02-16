library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity segment is
	port(
		A: in std_logic_vector(3 downto 0);
		Z: out std_logic_vector(6 downto 0)
	);
end segment;

architecture rtl of segment is
begin
	process(A)
	begin
		case A is
			when "0000" => Z <= "1000000";
			when "0001" => Z <= "1111001";
			when "0010" => Z <= "0100100";
			when "0011" => Z <= "0110000";
			when "0100" => Z <= "0011001";
			when "0101" => Z <= "0010010";
			when "0110" => Z <= "0000010";
			when "0111" => Z <= "1011000";
			when "1000" => Z <= "0000000";
			when "1001" => Z <= "0010000";
			when "1010" => Z <= "0001000";
			when "1011" => Z <= "0000011";
			when "1100" => Z <= "1000110";
			when "1101" => Z <= "0100001";
			when "1110" => Z <= "0000110";
			when "1111" => Z <= "0001110";
		end case;
	end process;
end rtl;