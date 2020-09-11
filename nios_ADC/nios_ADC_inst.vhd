	component nios_ADC is
		port (
			adc0_sclk         : out std_logic;                                       -- sclk
			adc0_cs_n         : out std_logic;                                       -- cs_n
			adc0_dout         : in  std_logic                    := 'X';             -- dout
			adc0_din          : out std_logic;                                       -- din
			clk_clk           : in  std_logic                    := 'X';             -- clk
			key_export        : in  std_logic_vector(2 downto 0) := (others => 'X'); -- export
			ledr_export       : out std_logic_vector(9 downto 0);                    -- export
			reset_reset_n     : in  std_logic                    := 'X';             -- reset_n
			signal_out_export : out std_logic                                        -- export
		);
	end component nios_ADC;

	u0 : component nios_ADC
		port map (
			adc0_sclk         => CONNECTED_TO_adc0_sclk,         --       adc0.sclk
			adc0_cs_n         => CONNECTED_TO_adc0_cs_n,         --           .cs_n
			adc0_dout         => CONNECTED_TO_adc0_dout,         --           .dout
			adc0_din          => CONNECTED_TO_adc0_din,          --           .din
			clk_clk           => CONNECTED_TO_clk_clk,           --        clk.clk
			key_export        => CONNECTED_TO_key_export,        --        key.export
			ledr_export       => CONNECTED_TO_ledr_export,       --       ledr.export
			reset_reset_n     => CONNECTED_TO_reset_reset_n,     --      reset.reset_n
			signal_out_export => CONNECTED_TO_signal_out_export  -- signal_out.export
		);

