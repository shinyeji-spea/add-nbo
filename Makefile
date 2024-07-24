TARGET=ad-nbo
CXXFLAGS=-g

all:$(TARGET)

$(TARGET): ad-nbo.o
	$(LINK.cpp) $^ $(LOADLIBES) $(LDLIBS) -o $@

clean:
	rm -f $(TARGET)
	rm -f *.o
