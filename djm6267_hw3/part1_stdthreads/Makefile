CC=g++
CFLAGS= -O3 -mavx -pthread -std=c++0x
DEPS =
OBJ = hw3_part1_thread_djm6267.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

part1: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJ) hw3_part1_thread_djm6267
                        