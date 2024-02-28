#include<cstdint>
#include<stdint.h>
#include "splashkit.h"

#define RADIUS 150;
int main()
{
    double x,y;
    color circle_color = COLOR_BLACK;
     
    open_window("Circle mover by Lucifer", 800, 600);

   x = screen_width()/2;
    y = 300;

    while ( !quit_requested())
    {
        process_events();
    
        if (key_typed(C_KEY))
        {
            circle_color = random_color();
        }
        if(key_down(RIGHT_KEY))
        {
           x=x+5;
        }
        if(key_down(LEFT_KEY))
        {
          x-=5;
        }
        if(key_down(UP_KEY))
        {
          y= y-3;
        }
        if(key_down(DOWN_KEY))
        {
          y=y+3;
        }
        
        double m =x+RADIUS; 
        if(m >  screen_width())
        {
            x = screen_width() - RADIUS;
        }

        double p = x-RADIUS;
        if(p < 0)
        {
            x = RADIUS;
        }

        double z = y+RADIUS;
        if(z > screen_height())
        {
            y = screen_height() - RADIUS;
        }

        double w = y-RADIUS;
        if(w < 0)
        {
            y = RADIUS;
        }
        
        clear_screen(COLOR_WHITE);
        fill_circle(circle_color, x,y,150 );
        refresh_screen(60);
    }
    
    return 0;
}