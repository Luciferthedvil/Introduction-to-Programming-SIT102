#include <cstdint>
#include "splashkit.h"
#include "planet_play.h"

planet_kind random_planet_kind()
{
    return static_cast<planet_kind>(rnd(8));
}

planet_data new_planet()
{
    planet_data result;
    result.kind = EARTH;
    result.x = PLANET_SPACE;
    result.y = 100;

    return result;
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

void update_planet(planet_data &planet)
{
    planet.x -= PLANET_SPEED;
    
    if (planet.x + bitmap_width(planet_bitmap(planet.kind)) <= 0)
    {
        planet.kind = random_planet_kind();
        planet.x = PLANET_SPACE;
    }
}

void update_planet2(planet_data &planet2)
{
    planet2.x -= PLANET_SPEED;

    if (planet2.x + bitmap_width(planet_bitmap(planet2.kind)) <= 0)
    {
        planet2.kind = random_planet_kind();
        planet2.x = PLANET_SPACE;
    }
}

void draw_planet(const planet_data &planet_to_draw)
{
    bitmap to_draw2;
    to_draw2 = planet_bitmap(planet_to_draw.kind);
    draw_bitmap(to_draw2, planet_to_draw.x, 100);
}
