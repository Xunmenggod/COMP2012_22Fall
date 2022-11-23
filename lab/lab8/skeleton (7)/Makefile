CXX := g++
CXXFLAGS := -std=c++11

lab8.exe: main.o BinarySearchTree.o
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

.PHONY:

clean:
	del *.o *.exe
	# rm -f *.o *.exe