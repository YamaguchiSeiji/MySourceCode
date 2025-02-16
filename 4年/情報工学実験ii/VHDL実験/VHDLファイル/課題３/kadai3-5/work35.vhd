library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity work35 is 
	port(
		sw_in: in std_logic_vector (3 downto 0);
		led_out: out std_logic_vector(3 downto 0)
	);
end work35;

architecture rtl of work35 is
begin
	led_out <= not sw_in + 1;
end rtl;