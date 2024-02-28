#include <cstdint>
#include <string>
#include <cmath>
#include "planet_play.h"
#include "splashkit.h"

using namespace std;
space_game_data new_game()
{
    space_game_data result;
    result.player = new_player();
    add_random_coin(result);
    add_random_planet(result);

    return result;
}
void draw_game(const space_game_data &game)//
{
    clear_screen(COLOR_BLACK);
    draw_player(game.player);

    for (int i = 0; i < game.coins.size(); i++)
    {
        draw_coin(game.coins[i]);
    }

    for (int i = 0; i < game.planets.size(); i++)
    {
        draw_planet(game.planets[i]);
    }

    draw_text("Score: " + to_string(game.score_counter), COLOR_WHITE, 50, 50);

    refresh_screen(60);
}

void remove_coin(vector<coin_data> &coins, int idx)//
{
    free_animation(coins[idx].coin_animation);

    coins[idx] = coins[coins.size() - 1];
    coins.pop_back();
}

void update_coins(vector<coin_data> &coins, const player_data &player, space_game_data &game)//
{
    vector<int> to_remove;

    for (int i = 0; i < coins.size(); i++)
    {
        update_coin(coins[i]);

        if (player_hit_coin(player, coins[i]))
        {
            game.score_counter += 1;
            to_remove.push_back(i);
        }
    }

    for (int i = to_remove.size() - 1; i >= 0; i--)
    {
        remove_coin(coins, to_remove[i]);
    }
}

bool is_sound_effect_playing(const string &sound_effect_name)
{
    return sound_effect_playing("crash.wav");
}

void update_planets(vector<planet_data> &planets, const player_data &player, space_game_data &game)
{
    vector<int> to_remove;

    for (int i = 0; i < planets.size(); i++)
    {
        update_planet(planets[i]);

        if (player_hit_planet(player, planets[i]))
        {
            if (!is_sound_effect_playing("crash.wav"))
            {
                play_sound_effect("crash.wav");
            }
            game.score_counter -= 1;
        }

        for (int j = 0; j < game.coins.size(); j++)
        {
            if (planet_hit_coin(planets[i], game.coins[j]))
            {
                to_remove.push_back(j);
            }
        }
    }

    for (int i = to_remove.size() - 1; i >= 0; i--)
    {
        remove_coin(game.coins, to_remove[i]);
    }
}

bool player_hit_planet(const player_data &player, const planet_data &planet)
{
    double player_radius = 20;
    double planet_radius = 40;

    double dx = player.x - planet.x;
    double dy = player.y - planet.y;
    double distance = sqrt(dx * dx + dy * dy);

    return distance < player_radius + planet_radius;
}

bool planet_hit_coin(const planet_data &planet, const coin_data &coin)
{
    double planet_radius = 40;
    double coin_radius = 10;

    double dx = planet.x - coin.x;
    double dy = planet.y - coin.y;
    double distance = sqrt(dx * dx + dy * dy);

    return distance < planet_radius + coin_radius;
}

void update_game(space_game_data &game)//
{
    update_coins(game.coins, game.player, game);

    if (rnd() < 0.03)
    {
        add_random_coin(game);
    }
    update_planets(game.planets, game.player, game);

    bool all_planets_off_screen = true;
    for (const auto &planet : game.planets)
    {
        if (planet.x + bitmap_width(planet_bitmap(planet.kind)) > 0)
        {
            all_planets_off_screen = false;
            break;
        }
    }

    if (all_planets_off_screen)
    {
        int num_new_planets = rnd(3) + 1;
        for (int i = 0; i < num_new_planets; ++i)
        {
            add_random_planet(game);
            game.planets.back().x = PLANET_SPACE + i * 200;
        }
    }
}

void add_random_coin(space_game_data &game)//
{
    game.coins.push_back(new_coin());
}

void add_random_planet(space_game_data &game)
{
    game.planets.push_back(new_planet());
}
