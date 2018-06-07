
include $(OBJ)/Makefrag

src_dir    = ../software
.build_rtl = $(addsuffix _test.cpp, $(OBJ))
build_dir  = $(addprefix ./, $(addsuffix _test/, $(OBJ)))

incs       = $(addprefix -I $(src_dir)/, $(dependence))

$(.build_rtl): %_test.cpp : $(addprefix $(src_dir)/, $(addsuffix .v, %))
	@ verilator -Wall -Wno-UNOPTFLAT -Wno-BLKANDNBLK --trace -Wno-lint --cc $< --exe $(addprefix ../tests/, $@) --Mdir $(build_dir) $(incs)
	@ mv $(build_dir) ../


