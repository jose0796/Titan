
module testbench(
		 input clk, 
		 input [31:0] data_rs1,
		 input [31:0] data_rs2,
		 output reg [4:0] read_addr_rs1, 
		 output reg [4:0] read_addr_rs2,
		 output reg [4:0] write_addr_rd,
		 output reg we, 
		 output reg [31:0] write_data_rd ); 

	 initial begin 
		//test for register x0 
		//testing read
		read_addr_rs1 <= 5'd0; 
		#1 if (data_rs1 == 0) begin 
			$display("testing x0: passed"); 
		end else begin 
			$display("testing x0: failed, data_rs1 = %h", data_rs1); 
		end 
		//test for register x1 
		//

		write_addr_rd <= 5'd1;
		write_data_rd <= 32'd7; 
		we <= 1;
	       @(posedge clk) #1;	
		read_addr_rs2 <= 5'd1; 
		#1 if( data_rs2 == 7) begin
			$display("testing x1: passed, data_rs2 = %h", data_rs2); 
		end else begin 
			$display("testing x1: failed, data_rs2 = %h", data_rs2); 
		end
	       $finish;	
	end 
endmodule

