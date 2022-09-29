CPPFLAGS = -std=c++11
OBJECTS = main.o system.o

all: lab2.exe

lab2.exe: $(OBJECTS)
	g++ -o $@ $(CPPFLAGS) $^

%.o: %.cpp
	g++ $(CPPFLAGS) -c $< -o $@

clean:
	rm  -f  *.o *.exe
