CC = g++
CFLAGS = -O2 -std=c++11 -pthread -march=native
LIBS = -lntl -lgmp -lm
TARGET = RSA

all: $(TARGET)

RSA: src/main.cpp src/User.hpp
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

clean:
	$(RM) $(TARGET)

new:
	$(MAKE) clean
	$(MAKE)