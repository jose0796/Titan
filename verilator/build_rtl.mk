src_dir    = ../software/
.build_rtl = $(addsuffix _test.cpp, $(OBJ))
build_dir  = $(addprefix ./, $(addsuffix _test/, $(OBJ)))
$(.build_rtl): %_test.cpp : $(addprefix $(src_dir), $(addsuffix .v, %))
	@ verilator -Wall --trace -Wno-lint --cc $< --exe $(addprefix ../tests/, $@) --Mdir $(build_dir)
	@ mv $(build_dir) ../


