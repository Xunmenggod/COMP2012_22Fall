CPPFLAGS = -std=c++11
OBJS = battle.o helper.o main.o monster_map.o monster.o player.o shop.o skill.o
DEPS = battle.d helper.d main.d monster_map.d monster.d player.d shop.d skill.d

all: Game.exe

Game.exe: $(OBJS)
	g++ -o $@ $(CPPFLAGS) $^

%.o: %.cpp
	g++ $(CPPFLAGS) -MMD -MP -c $< -o $@

-include $(DEPS)

clean:
	rm -f *.o *.exe *.d
# On Windows, use: del *.o *.exe *.d
# On Linux or MacOS, use: rm -f *.o *.exe *.d

.PRECIOUS: $(OBJS) helper_easy.o helper_difficult.o helper_impossible.o