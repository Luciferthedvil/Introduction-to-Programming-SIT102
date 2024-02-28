#include <stdint.h>
#include <cstdint>
#include "splashkit.h"

using namespace std;

int main()
{
    string name;
    int age, year, year_born;

    write_line("what is your name: ");
    name = read_line();
    write_line("Welcome " + name + "\n");

    write_line("How old are you: ");
    age = convert_to_integer(read_line());
    write_line("great you are " + to_string(age) + "\n");

    write_line("what is the current year: ");
    year = convert_to_integer(read_line());
    year_born = year - age;
    write_line("the year you were born was " + to_string(year_born));

    return 0;
}