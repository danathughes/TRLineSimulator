CC=g++

DEPS = CoaxXSection.h MicrostripXSection.h StriplineXSection.h TRLine.h TRLineXSect.h

OBJ = CoaxXSection.o MicrostripXSection.o StriplineXSection.o TRLine.o TRLineXSect.o

XSectTest: $(OBJ) XSectTest.o
	$(CC) -o $@ $^

TRTest: $(OBJ) TRTest.o
	$(CC) -o $@ $^ 

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $<

.PHONY: clean

clean:
	rm -f *.o *~ TRTest
