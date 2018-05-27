

.run 		: $(OBJ)
	
build : build_verilog

build_verilog:
	@make -C ../$(OBJ)_test -j -f $(addprefix V, $(addsuffix .mk,$(OBJ))) $(addprefix V, $(OBJ))
	@../$(OBJ)_test/V$(OBJ)
	@mv $(OBJ)_test.vcd ../
	@gtkwave ../$(OBJ)_test.vcd &


