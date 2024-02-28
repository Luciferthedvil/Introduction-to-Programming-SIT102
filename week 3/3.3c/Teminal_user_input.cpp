#include <stdint.h>
#include <cstdint>
#include "splashkit.h"

using namespace std;
string read_string(string prompt)
{
    string result;
    write_line(prompt);
    result = read_line();

    return result;
}

int read_age(string prompt)
{
    string line;
    int result;

    line = read_string(prompt);

    while (not is_integer(line))
    {
        write_line("Please enter a whole number");
        line = read_string(prompt);
    }

    result = convert_to_integer(line);
    return result;
}

int read_integer(string prompt, int min, int max)
{
    int result;
    result = read_age(prompt);

    while (result < min || result > max)
    {
        write_line("Please enter a number between" + to_string(min) + " and " + to_string(max));
        result = read_integer(prompt, 1, 10);
    }
    return result;
}

double read_double(string prompt)
{
    string line;
    double result2;

    line = read_string(prompt);

    while (not is_double(line))
    {
        write_line("Please enter a number");
        line = read_string(prompt);
    }

    result2 = convert_to_double(line);
    return result2;
}

double read_double_range(string prompt, int min, int max)
{
    double result2;
    result2 = read_double(prompt);

    while (result2 < min || result2 > max)
    {
        write_line("Please enter a number between " + to_string(min) + " and " + to_string(max));
        result2 = read_double_range(prompt, 0, 1);
    }
    return result2;
}

bool read_boolean()
{

    while (true)
    {
        string choice;
        write_line("enter Yes/No Y/N");
        choice = to_lowercase(read_line());

        if (choice == "no" || choice == "n")
        {
            return false;
        }
        if (choice == "yes" || choice == "y")
        {
            return true;
        }
        else
        {
            write_line("Please enter either yes/no y/n");
        }
    }
}
