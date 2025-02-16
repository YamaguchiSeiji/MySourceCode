library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity halfadder is
	port(
		A, B: in std_logic;
		C, S: out std_logic
	);
end halfadder;

architecture rtl of halfadder is
begin
	C <= A and B;
	S <= A xor B;
end rtl;