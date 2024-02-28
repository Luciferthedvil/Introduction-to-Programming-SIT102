#include <stdint.h>
#include <cstdint>
#include "splashkit.h"
#include "Terminal_user_input.h"

using namespace std;

int main()
{
    string name;
    int age;
    double bmi, weight, height;

    name = read_string("\nEnter your name: ");
    write_line("Welcome " + name + "\n");

    age = read_age("Enter your age: ");
    write_line("Great you are " + to_string(age) + "\n");

    height = read_double("Enter Height in Meter");
    weight = read_double("Enter Weight in kg");

    bmi = weight / (height * height);
    write_line("Your BMI is " + to_string(bmi) + "\n");

    return 0;
}