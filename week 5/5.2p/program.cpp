#include <cstdint>
#include "splashkit.h"

#define PLAYER_SPEED 1
enum ship_kind
{
    AQUARII,
    GLIESE,
    PEGASI
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

struct player_data
{
    ship_kind kind;
    double x, y;
};

struct planet_data
{
    planet_kind kind;
    double x, y;
};

void load_resources()
{
    load_resource_bundle("game_bundle", "planet_play.txt");
}

bitmap ship_bitmap(ship_kind kind)
{
    switch (kind)
    {
    case AQUARII:
        return bitmap_named("aquarii");
    case GLIESE:
        return bitmap_named("gliese");
    default:
        return bitmap_named("pegasi");
    }
}

bitmap planet_bitmap(planet_kind kind)
{
    switch (kind)
    {
    case EARTH:
        return bitmap_named("earth");
    case JUPITER:
        return bitmap_named("jupiter");
    case MARS:
        return bitmap_named("mars");
    case MERCURY:
        return bitmap_named("mercury");
    case NEPTUNE:
        return bitmap_named("neptune");
    case PLUTO:
        return bitmap_named("pluto");
    case SATURN:
        return bitmap_named("saturn");
    case URANUS:
        return bitmap_named("uranus");
    default:
        return bitmap_named("venus");
    }
}

void draw_player(const player_data &player_to_draw)
{
    bitmap to_draw;
    to_draw = ship_bitmap(player_to_draw.kind);
    draw_bitmap(to_draw, player_to_draw.x, player_to_draw.y);
}

void handle_input(player_data &player)
{
    if (key_typed(NUM_1_KEY))
        player.kind = AQUARII;

    if (key_typed(NUM_2_KEY))
        player.kind = GLIESE;

    if (key_typed(NUM_3_KEY))
        player.kind = PEGASI;

    if (key_down(RIGHT_KEY))
        player.x += PLAYER_SPEED;
    if (key_down(LEFT_KEY))
        player.x -= PLAYER_SPEED;
    if (key_down(UP_KEY))
        player.y -= PLAYER_SPEED;
    if (key_down(DOWN_KEY))
        player.y += PLAYER_SPEED;
}

void handle_planet_input(planet_data &planet)
{

    if (key_typed(J_KEY))
        planet.kind = JUPITER;

    if (key_typed(M_KEY))
        planet.kind = MARS;

    if (key_typed(I_KEY))
        planet.kind = MERCURY;

    if (key_typed(P_KEY))
        planet.kind = PLUTO;

    if (key_typed(V_KEY))
        planet.kind = VENUS;
}

void handle_planet2_input(planet_data &planet2)
{
    if (key_typed(E_KEY))
        planet2.kind = EARTH;
    if (key_typed(N_KEY))
        planet2.kind = NEPTUNE;
    if (key_typed(S_KEY))
        planet2.kind = SATURN;
    if (key_typed(U_KEY))
        planet2.kind = URANUS;
}

player_data new_player()
{
    player_data result;
    result.kind = AQUARII;
    result.x = 10;
    result.y = 200;

    return result;
}

planet_kind random_planet_kind()
{
    return static_cast<planet_kind>(rnd(8));
}

planet_data new_planet()
{
    planet_data result;
    result.kind = planet_kind(rnd(8));
    result.x = rnd(screen_width()) - 50;
    result.y = rnd(screen_height()) - 50;

    return result;
}

void draw_planet(const planet_data &planet_to_draw)
{
    bitmap to_draw2;
    to_draw2 = planet_bitmap(planet_to_draw.kind);
    draw_bitmap(to_draw2, planet_to_draw.x, planet_to_draw.y);
}

int main()
{
    open_window("Planet Play", 800, 500);
    load_resources();

    player_data player;
    planet_data planet, planet2;

    player = new_player();
    planet = new_planet();
    planet2 = new_planet();

    while (!quit_requested())
    {
        process_events();

        handle_input(player);
        handle_planet_input(planet);
        handle_planet2_input(planet2);

        clear_screen(COLOR_BLACK);
        draw_player(player);
        draw_planet(planet);
        draw_planet(planet2);
        refresh_screen();
    }

    return 0;
}