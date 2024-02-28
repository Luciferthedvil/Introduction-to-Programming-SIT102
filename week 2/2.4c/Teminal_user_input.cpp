#include <stdint.h>
#include <cstdint>
#include "splashkit.h"

string read_string(string prompt)
{
    string result;
    write_line(prompt);
    result = read_line();

    return result;
}

int read_age(string prompt)
{
    int result;
    write_line(prompt);
    result = convert_to_integer(read_line());

    return result;
}

double read_double(string prompt)
{

    string line;
    double result;

    line = read_string(prompt);
    result = convert_to_double(line);

    return result;
}