library ieee;
use ieee.std_logic_1164.all;

entity kadai46 is
	port (
        CLK1 : in std_logic;
        Z1 : out std_logic_vector(6 downto 0)
    );
end kadai46;

architecture rtl of kadai46 is 
signal A0, A1, A2, A3 : std_logic := '0';
signal tmp0, tmp1 : std_logic := '0';

component kadai42
	port (
        J, K, CLK : in std_logic;
        Q : out std_logic
    );
end component;

component segment
	port (
		A: in std_logic_vector(3 downto 0);
		Z: out std_logic_vector(6 downto 0)
	);
end component;

begin
    jkff1: kadai42 port map(J => '1', K => '1', CLK => CLK1, Q => A0);
    jkff2: kadai42 port map(J => A0, K => A0, CLK => CLK1, Q => A1);
    tmp0 <= A1 and A0;
    jkff3: kadai42 port map(J => tmp0, K => tmp0, CLK => CLK1, Q => A2);
    tmp1 <= tmp0 and A2;
    jkff4: kadai42 port map(J => tmp1, K=> tmp1, CLK => CLK1, Q => A3);
    
    seg1: segment port map(A(0) => A0, A(1) => A1, A(2) => A2, A(3) => A3, Z => Z1);
    
end rtl;

