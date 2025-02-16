library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity fulladder is
	port(
		A, B, Cin : in std_logic;
		Cout, S : out std_logic
	);
end fulladder;

architecture rtl of fulladder is
	
	signal C1, C2, S1 : std_logic;
	
component halfadder
	port(
		A, B: in std_logic;
		C, S: out std_logic
	);
end component;



begin
	
	half1: halfadder port map(A => A, B => B, C => C1, S => S1);
	half2: halfadder port map(A => S1, B => Cin, C => C2, S => S);
	Cout <= C1 or C2;
end rtl;