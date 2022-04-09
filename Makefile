CXX := clang++
CFLAGS := -O3 -std=c++20 -g
INCLUDE := -Iinclude -Isrc/example.hpp
PYINCLUDE := -I/usr/include/python3.10
BOOST := -lpython3.10 -lboost_python3

LIB_SRC := src/example.cpp
WRAPPER := src/py_wrapper.cpp
LIB := lib/libexample.so
PYLIB := lib/pyexample.so


.PHONY: all clean pyexample

all: pyexample

pyexample: $(PYLIB)

$(PYLIB): $(LIB) $(LIB_SRC) $(WRAPPER)
	$(CXX) $(CFLAGS) -shared $(INCLUDE) $(PYINCLUDE) -fPIC $(WRAPPER) $(LIB) -o $(PYLIB) $(BOOST)

$(LIB): $(LIB_SRC)
	$(CXX) $(CFLAGS) -shared $(INCLUDE) -fPIC $(LIB_SRC) -o $(LIB)