
module nios_ADC (
	adc0_sclk,
	adc0_cs_n,
	adc0_dout,
	adc0_din,
	clk_clk,
	key_export,
	ledr_export,
	reset_reset_n,
	signal_out_export);	

	output		adc0_sclk;
	output		adc0_cs_n;
	input		adc0_dout;
	output		adc0_din;
	input		clk_clk;
	input	[2:0]	key_export;
	output	[9:0]	ledr_export;
	input		reset_reset_n;
	output		signal_out_export;
endmodule
