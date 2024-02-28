#include <cstdint>
#include <vector>
#include "splashkit.h"

using namespace std;

#define PLAYER_SPEED 7
#define PLANET_SPEED 1
#define PLANET_SPACE screen_width()

enum ship_kind
{
    AQUARII,
    GLIESE,
    PEGASI
};

struct player_data
{
    ship_kind kind;
    double x, y;
};

struct coin_data
{
    animation coin_animation;
    double x, y;
};

enum planet_kind
{
    EARTH,
    JUPITER,
    MARS,
    MERCURY,
    NEPTUNE,
    PLUTO,
    SATURN,
    URANUS,
    VENUS
};

struct planet_data
{
    planet_kind kind;
    double x, y;
};

struct space_game_data
{
    player_data player;
    vector<planet_data> planets;
    vector<coin_data> coins;

    int score_counter = 0;
};

player_data new_player();
void draw_player(const player_data &player_to_draw);
bool player_hit_coin(const player_data &player, const coin_data &coin);
bool player_hit_planet(const player_data &player, const planet_data &planet);
bool planet_hit_coin(const planet_data &planet, const coin_data &coin);

void handle_input(player_data &player);
void handle_planet_input(planet_data &planet);
void handle_planet2_input(planet_data &planet2);
bitmap planet_bitmap(planet_kind kind);

coin_data new_coin(double x, double y);
coin_data new_coin();
void draw_coin(const coin_data &coin);
void update_coin(coin_data &coin);
void update_coins(vector<coin_data> &coins, const player_data &player, space_game_data &game);

space_game_data new_game();
planet_data new_planet();

void draw_game(const space_game_data &game);
void draw_planet(const planet_data &planet_to_draw);
void update_planet(planet_data &planet);
void update_planet2(planet_data &planet2);
void update_game(space_game_data &game);
void add_random_coin(space_game_data &game);
void add_random_planet(space_game_data &game);
