#include <cstdint>
#include "splashkit.h"

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

void draw_player(ship_kind kind, double x, double y)
{
    bitmap to_draw;
    to_draw = ship_bitmap(kind);
    draw_bitmap(to_draw, x, y);
}

void draw_planet(planet_kind kind2, double x2, double y2)
{
    bitmap to_draw2;
    to_draw2 = planet_bitmap(kind2);
    draw_bitmap(to_draw2, x2, y2);
}

int main()
{
    open_window("Planet Play", 800, 500);
    load_resources();

    ship_kind player_ship;
    planet_kind planet;
    planet_kind planet2;

    player_ship = AQUARII;
    planet = VENUS;
    planet2 = EARTH;

    while (not quit_requested())
    {
        process_events();

        if (key_typed(NUM_1_KEY))
            player_ship = AQUARII;
        if (key_typed(NUM_2_KEY))
            player_ship = GLIESE;
        if (key_typed(NUM_3_KEY))
            player_ship = PEGASI;
        if (key_typed(E_KEY))
            planet2 = EARTH;
        if (key_typed(J_KEY))
            planet = JUPITER;
        if (key_typed(M_KEY))
            planet = MARS;
        if (key_typed(I_KEY))
            planet = MERCURY;
        if (key_typed(N_KEY))
            planet2 = NEPTUNE;
        if (key_typed(P_KEY))
            planet = PLUTO;
        if (key_typed(S_KEY))
            planet2 = SATURN;
        if (key_typed(U_KEY))
            planet2 = URANUS;
        if (key_typed(V_KEY))
            planet = VENUS;

        clear_screen(COLOR_BLACK);
        draw_player(player_ship, 10, 200);
        draw_planet(planet, 60, 250);
        draw_planet(planet2, 500, 100);
        refresh_screen();
    }

    return 0;
}