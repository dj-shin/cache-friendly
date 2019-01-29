STAT_FLAGS=
CC=gcc
CXXFLAGS=-O2 -DSIZE=512

all: run

OBJS=ijk ikj jki

$(OBJS): $(patsubst %,matmul_%.c,$@)
	$(CC) matmul_$@.c -o $@ $(CXXFLAGS)

run: $(OBJS)
	$(foreach obj,$(OBJS),./$(obj);)

stat: $(OBJS)
	$(foreach obj,$(OBJS),sudo perf stat -a -d $(STAT_FLAGS) ./$(obj);)

.PHONY: clean

clean:
	rm -rf $(OBJS)
