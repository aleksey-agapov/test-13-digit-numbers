# ---------------------------------------------------------------

DISTRIB := .

C_SRCS := \
 numbers/ThirteenTetradClass.cpp \
 numbers/ThirteenNumberClass.cpp \
 test-13-digit-main.cpp

OBJS := \
 $(DISTRIB)/numbers/ThirteenTetradClass.o \
 $(DISTRIB)/numbers/ThirteenNumberClass.o \
 $(DISTRIB)/test-13-digit-main.o

EXECUTABLE := test-13-digit

LIBS := 

.PHONY: prepare build all clean test

all: build test

build: $(OBJS) 
	@echo 'Building target: $@'
	g++ -o $(EXECUTABLE) $(OBJS) $(LIBS)

%.o: %.cpp
	@echo 'Building file: $<'
	g++ -std=c++1z -O3 -c -o "$@" "$<"

clean:
	rm -rf $(OBJS) $(EXECUTABLE)

test:
	./$(EXECUTABLE)

