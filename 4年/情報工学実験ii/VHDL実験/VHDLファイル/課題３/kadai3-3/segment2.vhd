library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity segment2 is
	port(
		A1, A2 : in std_logic_vector(3 downto 0);
		Z1, Z2 : out std_logic_vector(6 downto 0)
	);
end segment2;

architecture rtl of segment2 is
	component segment
		port(
			A: in std_logic_vector(3 downto 0);
			Z: out std_logic_vector(6 downto 0)
		);
	end component;

	begin
		seg1: segment port map(A => A1, Z => Z1);
		seg2: segment port map(A => A2, Z => Z2);
end rtl;