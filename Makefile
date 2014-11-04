
# nemo Makefile

SH=/bin/sh
BP=~/boost_1_54_0
CC=g++
CFL=-I $(BP) -O3
LFL=-L $(BP)/stage/lib \
	-lrt -lpthread \
    -lboost_chrono -lboost_regex -lboost_system -lboost_thread 
#    -lreadline -lcurses \
#    -lssl -lcrypto
HDR=$(wildcard *.h)
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
EXE=nemo

all: $(EXE)

$(EXE): $(OBJ)
	@$(CC) -o $@ $^ $(LFL)

%.o: %.cpp
	@$(CC) -o $@ -c $< $(CFL)

.PHONY: clean cleanall

clean:
	@-/bin/rm -f $(OBJ) *.log

cleanall: clean
	@-/bin/rm -f $(EXE)

# EOF
