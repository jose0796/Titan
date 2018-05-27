


include verilator/pprint.mk

.obj = $(obj)
NO_PRIN := --no-print-directory

default: build_rtl

build_rtl: 
	@printf "%b" "$(MSJ_COLOR) BUILDING RTL MODULES $(NO_COLOR)\n"
	@ make $(NO_PRINT) -C verilator OBJ=$(.obj) -f build_rtl.mk
	@ make $(NO_PRINT) -C verilator OBJ=$(.obj) -f build_verilated.mk
clean: 
	rm -r *_test *.vcd
	


