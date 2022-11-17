CPPFLAGS = -std=c++11
CPPFLAGS_leak = -std=c++11 -fsanitize=address,leak,undefined -g

OBJ_DIR = obj
OBJ_DIR_leak = obj_leak

OBJECTS = $(addprefix $(OBJ_DIR)/,main.o system.o)
OBJECTS_leak = $(addprefix $(OBJ_DIR_leak)/,main.o system.o)

all: create_directory lab2.exe lab2_leak.exe

create_directory:
	mkdir -p $(OBJ_DIR) $(OBJ_DIR_leak)

lab2.exe: $(OBJECTS)
	g++ -o $@ $(CPPFLAGS) $^

lab2_leak.exe: $(OBJECTS_leak)
	g++ -o $@ $(CPPFLAGS_leak) $^

$(OBJ_DIR)/%.o: %.cpp
	g++ $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR_leak)/%.o: %.cpp
	g++ $(CPPFLAGS_leak) -c $< -o $@

clean:
	rm  -rf  $(OBJ_DIR) $(OBJ_DIR_leak) *.exe