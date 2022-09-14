CPPFLAGS = -std=c++11
#SCRS = battle.cpp helper.cpp main.cpp monster_map.cpp monster.cpp player.cpp shop.cpp skill.cpp
OBJS = battle.o main.o monster_map.o monster.o player.o shop.o skill.o
DEPS = battle.d helper_easy.d helper_difficult.d helper_impossible.d main.d monster_map.d monster.d player.d shop.d skill.d

all: Game_easy.exe Game_difficult.exe Game_impossible.exe 

Game_%.exe: $(OBJS) helper_%.o
	g++ -o $@ $(CPPFLAGS) $^

# Game.exe: $(OBJS)
# 	g++ -o $@ $(CPPFLAGS) $^

%.o: %.cpp
	g++ $(CPPFLAGS) -MMD -MP -c $< -o $@

-include $(DEPS)

clean:
	del *.o *.exe *.d
# On Windows, use: del *.o *.exe *.d
# On Linux or MacOS, use: rm -f *.o *.exe *.d

.PRECIOUS: $(OBJS) helper_easy.o helper_difficult.o helper_impossible.o