#include <cstdint>
#include <string>
#include "planet_play.h"
#include "splashkit.h"

using namespace std;
space_game_data new_game()
{
    space_game_data result;
    result.player = new_player();
    result.planet2 = new_planet();
    result.the_coin = new_coin();

    return result;
}
void draw_game(const space_game_data &game)
{
    clear_screen(COLOR_BLACK);
    draw_player(game.player);
    draw_planet(game.planet2);
    draw_coin(game.the_coin);
    draw_text("Score: " + to_string(game.score_counter), COLOR_WHITE, 50, 50);

    refresh_screen(60);
}

void update_game(space_game_data &game)
{
    update_coin(game.the_coin);
    update_planet2(game.planet2);

    if (player_hit_coin(game.player, game.the_coin))
    {
        game.score_counter += 1;

        game.the_coin.x = rnd(screen_width());
        game.the_coin.y = rnd(screen_height());
    }
}
