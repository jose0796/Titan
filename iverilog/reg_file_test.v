`include "./software/clk_gen.v"
`include "./tests/reg_file_tb.v"
`include "./software/reg_file.v"

module tb;

	wire clk;
	wire [4:0]  raddr_rs1; 
	wire [4:0]  raddr_rs2;
        wire [31:0] rdata_rs1;
	wire [31:0] rdata_rs2;	
	wire [4:0]  waddr_rd;
	wire [31:0] wdata_rd;
	wire we;

	clkgen        CLK      (  .clk(clk)); 
	register_file REG_FILE (
				.clk(clk),
				.raddr_rs1(raddr_rs1),
				.raddr_rs2(raddr_rs2),
				.waddr_rd (waddr_rd),
				.wdata_rd (wdata_rd), 
				.we(we),
				.rdata_rs1(rdata_rs1),
				.rdata_rs2(rdata_rs2));
	testbench     TEST    (
				.clk(clk),
				.data_rs1(rdata_rs1),
				.data_rs2(rdata_rs2),			
				.read_addr_rs1(raddr_rs1),
				.read_addr_rs2(raddr_rs2),
				.write_addr_rd(waddr_rd),
				.we(we),
				.write_data_rd(wdata_rd));				
endmodule 