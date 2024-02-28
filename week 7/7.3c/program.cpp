#include <cstdint>
#include <string>
#include "splashkit.h"
#include "planet_play.h"

using namespace std;
void load_resources()
{
    load_resource_bundle("game_bundle", "planet_play.txt");
}

int main()
{
    open_window("Planet Play", 800, 500);
    load_resources();

    space_game_data game;

    while (!quit_requested())
    {
        process_events();

        handle_input(game.player);
        for (int i = 0; i < game.planets.size(); i++)
        {
            handle_planet_input(game.planets[i]);
            handle_planet2_input(game.planets[i]);
        }

        draw_game(game);
        update_game(game);
    }

    return 0;
}