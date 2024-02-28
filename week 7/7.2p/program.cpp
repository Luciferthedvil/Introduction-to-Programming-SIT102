#include <cstdint>
#include "splashkit.h"

using namespace std;

struct Player
{
    string name;
    int jersey_number;
    int high_score;
};

struct Team
{
    string name;
    Player captain;
    vector<Player> sportspersons;
};

enum Menu_Options
{
    PRINT_TEAM,
    CHANGE_TEAM_NAME,
    CHANGE_CAPTAIN,
    ADD_PLAYER,
    REMOVE_PLAYER,
    QUIT
};

string read_string(string prompt)
{
    string result;
    write_line(prompt);
    result = read_line();
    return result;
}

int read_integer(string prompt)
{
    int result;
    write_line(prompt);
    result = convert_to_integer(read_line());
    return result;
}

int read_interger_range(const string &prompt, int min, int max)
{
    int result;
    do
    {
        write_line(prompt);
        result = convert_to_integer(read_line());

        if (result < min || result > max)
        {
            write_line("Please enter a value between " + to_string(min) + " to " + to_string(max));
        }
    } while (result < min || result > max);
    return result;
}

Player read_player_details()
{
    Player sportsperson;

    sportsperson.name = read_string("\nEnter player name");
    sportsperson.jersey_number = read_integer("Enter player Jersey Number");
    sportsperson.high_score = read_integer("Enter player's highest no of kills");

    return sportsperson;
}

void print_player_details(const Player &sportsperson)
{
    write("\nPlayer Name: " + sportsperson.name + " || ");
    write("Player Jersey Number: " + to_string(sportsperson.jersey_number) + " || ");
    write("Player High Score: " + to_string(sportsperson.high_score) + " \n");
    write_line("-------------------------------------------------------------------------------");
}

Team read_team_details()
{
    Team team;

    team.name = read_string("\nEnter your PUBG team Name:");
    write_line("\nEnter the team's Captain Name: ");
    team.captain = read_player_details();

    int Num_players = read_integer("\nEnter the number of players in the team: ");
    for (int i = 0; i < Num_players; i++)
    {
        Player sportsperson = read_player_details();
        team.sportspersons.push_back(sportsperson);
    }
    return team;
}

void print_team_details(Team &to_print)
{
    write_line("\n-------------------------------------------------------------------------------");
    write_line("Team Name: " + to_print.name);
    write_line("TEAM CAPTAIN: ");
    print_player_details(to_print.captain);

    write_line("\nPLAYERS IN THE TEAM: ");
    for (const Player &players : to_print.sportspersons)
    {
        print_player_details(players);
    }
}

Menu_Options read_menu_options()
{
    int options;
    do
    {
        write_line("Menu Options: ");
        write_line("1. Print Team");
        write_line("2. Change Team Name");
        write_line("3. Change Captain");
        write_line("4. Add Player");
        write_line("5. Remove Player");
        write_line("6. Quit");

        options = read_interger_range("Enter Menu Options: ", 1, 6);

    } while (options < 1 || options > 6);

    return static_cast<Menu_Options>(options - 1);
}

void change_team_name(Team &team)
{
    team.name = read_string("Enter a new team name: ");
}

void change_captain(Team &team)
{
    team.captain = read_player_details();
}

void add_player(Team &team)
{
    Player sportsperson = read_player_details();
    team.sportspersons.push_back(sportsperson);
}

void remove_player(Team &team)
{
    write_line("Players in the team: ");
    for (int i = 0; i < team.sportspersons.size(); i++)
    {
        write_line(i + 1 + "." + team.sportspersons[i].name);
    }

    int index = read_interger_range("Enter the index of players to remove (0 to cancel): ", 0, team.sportspersons.size());
    if (index > 0)
    {
        team.sportspersons.erase(team.sportspersons.begin() + index - 1);
    }
}

int main()
{
    Player sportsperson;
    Team team;

    team = read_team_details();
    print_team_details(team);

    bool quit = false;
    while (!quit)
    {
        Menu_Options option = read_menu_options();

        switch (option)
        {
        case PRINT_TEAM:
            print_team_details(team);
            break;

        case CHANGE_TEAM_NAME:
            change_team_name(team);
            print_team_details(team);
            break;

        case CHANGE_CAPTAIN:
            change_captain(team);
            print_team_details(team);
            break;

        case ADD_PLAYER:
            add_player(team);
            print_team_details(team);
            break;

        case REMOVE_PLAYER:
            remove_player(team);
            print_team_details(team);
            break;

        case QUIT:
            quit = true;
            break;
        default:
            write_line("Enter a valid choice");
            break;
        }
    }

    return 0;
}