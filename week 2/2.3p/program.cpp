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
    result = convert_to_integer(line);

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

int main()
{
    string name;
    int age;
    double bmi, weight, height;

    name = read_string("\n"
                       "Enter your name: ");
    write_line("Welcome " + name + "\n");

    age = read_age("Enter your age: ");
    write_line("Great you are " + to_string(age) + "\n");

    height = read_double("Enter Height in Meter");
    weight = read_double("Enter Weight in kg");

    bmi = weight / (height * height);
    write_line("Your BMI is " + to_string(bmi) + "\n");

    return 0;
}