#include <cstdint>
#include "splashkit.h"
#define MAX_ITERATION 1000.0

color mandelbrot_color(double, double);
color iteration_color(int);

void draw_mandelbrot(double start_x, double start_y, double width, double height)
{
    double scale_width, scale_height;
    int x, y;
    double mbx, mby;

    color color;

    scale_width = width / screen_width();
    scale_height = height / screen_height();
    x = 0;

    while (x < screen_width())
    {
        y = 0;

        while (y < screen_height())
        {

            mbx = start_x + (x * scale_width);
            mby = start_y + (y * scale_height);
            color = mandelbrot_color(mbx, mby);
            draw_pixel(color, x, y);

            y++;
        }

        x++;
    }
}
color mandelbrot_color(double mandelbrot_x, double mandelbrot_y)
{
    double xtemp, x, y;
    int z;
    x = mandelbrot_x;
    y = mandelbrot_y;
    z = 0;

    while (x * x + y * y <= 4 and z < MAX_ITERATION)
    {
        xtemp = x * x - y * y + mandelbrot_x;
        y = 2 * x * y + mandelbrot_y;
        x = xtemp;
        z++;
    }

    return iteration_color(z);
}

color iteration_color(int prompt)

{
    color output_color;
    double hue;

    if (prompt >= MAX_ITERATION)
    {
        output_color = COLOR_RED;
    }
    else
    {
        hue = 0.5 + (prompt / MAX_ITERATION);
        if (hue > 1)
        {
            hue = hue - 1;
        }
        output_color = hsb_color(hue, 0.8, 0.2);
    }

    return output_color;
}

int main()
{
    double start_x, start_y;
    double width, height;
    double new_width, new_height;

    start_x = -2.5;
    start_y = -1.5;
    width = 4;
    height = 3;

    open_window("Mandlebrot", 800, 600);

    while (not quit_requested())
    {
        process_events();
        draw_mandelbrot(start_x, start_y, width, height);

        if (mouse_clicked(LEFT_BUTTON))
        {
            new_width = width / 2;
            start_x = (start_x + mouse_x() / screen_width() * width) - new_width / 2;
            width = new_width;

            new_height = width / 2;
            start_y = (start_y + mouse_y() / screen_height() - new_height / 2);
            height = new_height;
        }
        if (mouse_clicked(RIGHT_BUTTON))
        {
            new_width = width * 2;
            start_x = (start_x + mouse_x() / screen_width() * width) - new_width / 2;
            width = new_width;

            new_height = height * 2;
            start_y = (start_y + mouse_y() / screen_height() - new_height / 2);
            height = new_height;
        }

        refresh_screen();
    }

    return 0;
}