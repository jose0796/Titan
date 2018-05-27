src_dir    = ../software
.build_rtl = $(addsuffix _test.cpp, $(OBJ))
build_dir  = $(addprefix ./, $(addsuffix _test/, $(OBJ)))
dependence = \
	     pc_source.v\
	     ls_unit.v\
	     pc_reg.v\
	     pc_add.v\
	     ifid_reg.v\
	     bram.v

incs       = $(addprefix -I $(src_dir)/, $(dependence))

$(.build_rtl): %_test.cpp : $(addprefix $(src_dir)/, $(addsuffix .v, %))
	@ verilator -Wall -Wno-UNOPTFLAT -Wno-BLKANDNBLK --trace -Wno-lint --cc $< --exe $(addprefix ../tests/, $@) --Mdir $(build_dir) $(incs)
	@ mv $(build_dir) ../


