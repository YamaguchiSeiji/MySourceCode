library IEEE;
use IEEE.std_logic_1164.all;

entity kadai42 is 
    port (
        J, K, CLK : in std_logic;
        Q : out std_logic
    );
end kadai42;

architecture rtl of kadai42 is
    signal A : std_logic := '0';

begin
    process(CLK)
    begin
        if(CLK'event and CLK = '1') then
            if (j = '1' and k = '0') then
                A <= '1';
            elsif (j = '0' and k = '1') then
                A <= '0';
            elsif (j = '1' and k = '1') then
                A <= not A;
            end if;
        end if;
        Q <= A;
    end process;
end rtl;
