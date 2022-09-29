#ifndef __SYSTEM_H__
#define __SYSTEM_H__

enum Event_Type {SCORE_FIRST = 0, SCORE_SECOND, YELLOW_CARD, RED_CARD};
enum Team_Type {FIRST = 0, SECOND};

class Event{
    public:
    Event_Type event_type;
    Team_Type team_type;
    char* name;
    int minute;

    Event(Event_Type event_type, Team_Type team_type, const char* name, int minute);
    Event(const Event& event);
    ~Event();

    void print_info(const char* first_country_name, const char* second_country_name) const;
};

class Match{
    public:
    Event* events[30];
    int num_event = 0;

    char* first_country_name;
    char** first_players;
    int num_first_players;

    char* second_country_name;
    char** second_players;
    int num_second_players;

    Match(const char* first_country_name, const char* second_country_name, const char** first_players, int num_first_players, const char** second_players, int num_second_players);
    Match(const Match& match);
    ~Match();

    void create_event(Event_Type event_type, Team_Type team_type, const char* name, int minute);
    void print_info() const;
};

class System{
    public:
    Match* matches[10];
    int num_matches = 0;

    System();
    System(const System& system);
    ~System();

    void add_match(Match* match);
    void print_info() const;
};

#endif