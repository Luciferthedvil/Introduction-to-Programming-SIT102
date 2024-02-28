#include<stdint.h>
#include<cstdint>
#include "splashkit.h"

int main()
{
    open_window("shapes by Nirosh", 800, 600);

    clear_screen(COLOR_WHITE);
    fill_ellipse(COLOR_BRIGHT_GREEN, 0, 400, 800, 400); // grass area
    fill_rectangle(COLOR_GRAY, 300,300,200,200); //house
    fill_triangle(COLOR_RED, 250,300, 400,150, 550,300); //roof
    refresh_screen(60);

    delay(5000);

    clear_screen(COLOR_WHITE);

    fill_rectangle(COLOR_LIGHT_YELLOW, 0,0,800,200); //sky

    fill_ellipse(COLOR_YELLOW, 400,125,100,75); //sun

    fill_triangle(COLOR_SANDY_BROWN, 100,200, 150,100, 200,200); //mountains
    fill_triangle(COLOR_SANDY_BROWN, 300,200, 350,100, 400,200);
    fill_triangle(COLOR_SANDY_BROWN, 500,200, 550,100, 600,200);
    fill_triangle(COLOR_SANDY_BROWN, 700,200, 750,100, 800,200);

    fill_ellipse(COLOR_GRAY, 200, 75, 100, 25); //clouds
    fill_ellipse(COLOR_GRAY, 400, 75, 100, 25);
    fill_ellipse(COLOR_GRAY, 600, 75, 100, 25);
    fill_ellipse(COLOR_GRAY, 200, 125, 100, -25);
    fill_ellipse(COLOR_GRAY, 400, 125, 100, -25);
    fill_ellipse(COLOR_GRAY, 600, 125, 100, -25);

    fill_rectangle(COLOR_LIGHT_BLUE, 0, 200, 800, 200); //water

    fill_rectangle(COLOR_LIGHT_GREEN, 0,400,800,100); // grass area

    fill_rectangle(COLOR_BLACK, 0, 500, 800, 100); //road

    fill_rectangle(COLOR_WHITE, 75, 525, 50, 25); //white lines in the middle of the road
    fill_rectangle(COLOR_WHITE, 300, 525, 50, 25);
    fill_rectangle(COLOR_WHITE, 400, 525, 50, 25);
    fill_rectangle(COLOR_WHITE, 750, 525, 50, 25);

    fill_rectangle(COLOR_BROWN, 450, 350, 50, 150); // tree trunks
    fill_rectangle(COLOR_BROWN, 750, 350, 50, 150);
    
    fill_circle(COLOR_GREEN, 475, 325, 75); // tree tops
    fill_circle(COLOR_GREEN, 775, 325, 75);

    fill_rectangle(COLOR_BLACK, 100,250,150,125); // front truck part
    fill_rectangle(COLOR_GRAY, 250,250,150,125); 
    fill_rectangle(COLOR_RED, 100,375,300,100); // main truck body
    fill_rectangle(COLOR_RED, 400,400,370,75);

    fill_rectangle(COLOR_YELLOW, 100,400,25,50); //head light

    fill_rectangle(COLOR_BLACK, 200,400,25,25); // door handles
    fill_rectangle(COLOR_BLACK, 350,400,25,25);

    fill_rectangle(COLOR_BLACK, 400,375,375,25); // truck load

    fill_circle(COLOR_WHITE, 225,525, 50); // outer tires
    fill_circle(COLOR_WHITE, 550,525, 50);
    fill_circle(COLOR_WHITE, 675,525, 50);

    fill_circle(COLOR_BLACK, 225,525, 25); // inner tires
    fill_circle(COLOR_BLACK, 550,525, 25);
    fill_circle(COLOR_BLACK, 675,525, 25);

    
    refresh_screen(360);
    delay(20000);

    return 0;
}