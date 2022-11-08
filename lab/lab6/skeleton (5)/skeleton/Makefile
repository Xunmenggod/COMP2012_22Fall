CPPFLAGS = -std=c++11 -Wall -g
CPPFLAGS_leak = -std=c++11 -fsanitize=address,leak,undefined -Wall -g

OBJ_DIR = obj
OBJ_DIR_leak = obj_leak

SRCS	= main.cpp computer.cpp electronics.cpp technician.cpp util.cpp
OBJS	= $(SRCS:.cpp=.o)
DEPS	= $(OBJS:.o=.d)

OBJECTS = $(addprefix $(OBJ_DIR)/,$(OBJS))
OBJECTS_leak = $(addprefix $(OBJ_DIR_leak)/,$(OBJS))

all: lab6.exe # lab6_leak.exe

lab6.exe: $(OBJECTS) 
	g++ $(CPPFLAGS) -o $@ $^

lab6_leak.exe: $(OBJECTS_leak)
	g++ -o $@ $(CPPFLAGS_leak) $^

# To include the .d dependency files
-include $(DEPS)

$(OBJ_DIR)/%.o: %.cpp
	g++ $(CPPFLAGS) -MMD -MP -c $< -o $@

$(OBJ_DIR_leak)/%.o: %.cpp
	g++ $(CPPFLAGS_leak) -MMD -MP -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)/* $(OBJ_DIR_leak)/* *.exe