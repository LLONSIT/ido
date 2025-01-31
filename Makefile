default: all

SRC_DIRS := . src src/libmld src/libp src/libu src/libxmalloc
UOPT_DIR := src/uopt
UGEN_DIR := src/ugen
AS0_DIR := src/

AVOID_UB ?= 1

UGEN_DEBUG = 1

CC := mips-linux-gnu-gcc
CFLAGS := -fPIC -I src -mips2 -mfp32 -ggdb3

ifeq ($(AVOID_UB),1)
    CFLAGS := $(CFLAGS) -DAVOID_UB
endif

BUILD_DIR := build
ALL_DIRS := $(addprefix $(BUILD_DIR)/,$(SRC_DIRS) $(UOPT_DIR) $(UGEN_DIR))

C_FILES := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
P_FILES := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.p))
UOPT_C_FILES := $(C_FILES) $(foreach dir,$(UOPT_DIR),$(wildcard $(dir)/*.c))

AS0_C_FILES := $(C_FILES) $(foreach dir,$(AS0_DIR),$(wildcard $(dir)/*.c))

UGEN_C_FILES := $(C_FILES) $(foreach dir,$(UGEN_DIR),$(wildcard $(dir)/*.c))

UOPT_O_FILES := $(addprefix $(BUILD_DIR)/,$(UOPT_C_FILES:.c=.o))

AS0_O_FILES := $(addprefix $(BUILD_DIR)/,$(AS0_C_FILES:.c=.o))

UGEN_O_FILES := $(addprefix $(BUILD_DIR)/,$(UGEN_C_FILES:.c=.o))

DEP_FILES := $(O_FILES:.o=.d)

# Ensure build directories exist before compiling anything
DUMMY != mkdir -p $(ALL_DIRS)

TARGETS := $(BUILD_DIR)/uopt $(BUILD_DIR)/ugen 

all: $(TARGETS)

$(BUILD_DIR)/uopt: $(UOPT_O_FILES)
	$(CC) -o $@ $^ $(LDFLAGS)

$(BUILD_DIR)/as0: $(AS0_O_FILES)
	$(CC) -o $@ $^ $(LDFLAGS)

$(BUILD_DIR)/ugen: $(UGEN_O_FILES)
	tools/compile_pascal_files.sh
	$(CC) -o $@ $^ build/src/ugen/build.p.o build/src/ugen/frame_offset.o build/src/ugen/reg_mgr.p.o build/src/ugen/eval.p.o build/src/ugen/tmp_mgr.p.o build/src/ugen/symbol.p.o build/src/ugen/tree_utils.p.o build/src/ugen/loop_header.p.o build/src/ugen/lit_mgr.p.o $(LDFLAGS)

$(BUILD_DIR)/%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

#Check if ugen is broken
check_binasm:
	tools/generate_and_check_binasm.sh

clean:
	$(RM) -r $(BUILD_DIR)

.PHONY: all clean default

-include $(DEP_FILES)
