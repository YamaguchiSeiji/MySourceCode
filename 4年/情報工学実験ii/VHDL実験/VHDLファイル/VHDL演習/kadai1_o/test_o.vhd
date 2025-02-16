library ieee;
use ieee.std_logic_1164.all;

entity test_o is
port(
	sw_in1, sw_in2 : in std_logic;
	led_out1, led_out2 : out std_logic);
end test_o;

architecture rtl of test_o is
begin
	led_out1 <= sw_in1;
	led_out2 <= sw_in2;
end rtl;