library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity add is
	port ( 
		A, B: in std_logic_vector(1 downto 0);
		Z : out std_logic_vector(2 downto 0)
	);
end add;

architecture rtl of add is
begin
	Z <= ('0' & A) + ('0' & B);
end architecture rtl;