
module titan_exception_unit(
				input 		clk_i,
				input 		rst_i,
				input 		inst_addr_misaligned_i,
				input 		inst_access_fault_i,
				input 		xbreak_i,
				input 		load_addr_misaligned_i,
				input 		load_access_fault_i,
				input 		store_addr_misaligned_i,
				input 		store_access_fault_i,		
				input 		xcall_i,
				output 	[ 3:0]	exception_code_o,
				output 		trap_valid_o,
				
