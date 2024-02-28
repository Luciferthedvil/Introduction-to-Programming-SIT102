#include <cstdint>
#include "splashkit.h"

using namespace std;

#define CHERRY 0
#define GOOSEBERRY 1
#define BLUEBERRY 2
#define POMEGRANATE 3
#define APRICOT 4
#define RASPBERRY 5
#define BLACKBERRY 6
#define STRAWBERRY 7
#define CURRANT 8
#define NUM_FRUIT 9

void load_resources()
{
    load_bitmap("Cherry", "Cherry.png");
    load_bitmap("Gooseberry", "Gooseberry.png");
    load_bitmap("Blueberry", "Blueberry.png");
    load_bitmap("Pomegranate", "Pomegranate.png");
    load_bitmap("Apricot", "Apricot.png");
    load_bitmap("Raspberry", "Raspberry.png");
    load_bitmap("Blackberry", "Blackberry.png");
    load_bitmap("Strawberry", "Strawberry.png");
    load_bitmap("Currant", "Currant.png");
    load_sound_effect("Splat", "Splat-SoundBible.com-1826190667.wav");
}

bitmap fruit_bitmap(int id)
{
    switch (id)
    {
    case CHERRY:
        return bitmap_named("Cherry");

    case GOOSEBERRY:
        return bitmap_named("Gooseberry");

    case BLUEBERRY:
        return bitmap_named("Blueberry");

    case POMEGRANATE:
        return bitmap_named("Pomegranate");

    case APRICOT:
        return bitmap_named("Apricot");

    case RASPBERRY:
        return bitmap_named("Raspberry");

    case BLACKBERRY:
        return bitmap_named("Blackberry");

    case STRAWBERRY:
        return bitmap_named("Strawberry");

    case CURRANT:
        return bitmap_named("Currant");

    default:
        return bitmap_named("Currant");
    }
}

int main()
{
    int score_counter = 0;
    bitmap fruits;
    double VARIABLE_1, VARIABLE_2;

    open_window("Fruit Punch", 800, 600);

    load_resources();

    fruits = fruit_bitmap(rnd(NUM_FRUIT));
    VARIABLE_1 = rnd(screen_width() - bitmap_width(fruits));
    VARIABLE_2 = rnd(screen_height() - bitmap_height(fruits));

    while (not quit_requested())
    {
        process_events();
        clear_screen(COLOR_WHITE);
        draw_text("Score: " + to_string(score_counter), COLOR_BLACK, 50, 50);
        draw_bitmap(fruits, VARIABLE_1, VARIABLE_2);
        refresh_screen(60);

        if (mouse_clicked(LEFT_BUTTON) and bitmap_point_collision(fruits, VARIABLE_1, VARIABLE_2, mouse_x(), mouse_y()))
        {
            score_counter = score_counter + 1;
            play_sound_effect("Splat");
            fruits = fruit_bitmap(rnd(NUM_FRUIT));
            VARIABLE_1 = rnd(screen_width()) - bitmap_width(fruits);
            VARIABLE_2 = rnd(screen_height()) - bitmap_height(fruits);
        }
    }
    return 0;
}