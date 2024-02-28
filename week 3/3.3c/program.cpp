#include<stdint.h>
#include<cstdint>
#include "splashkit.h"
#include "Terminal_user_input.h"

using namespace std;

int main()
{
    string name;
    int age, test;
    double bmi,weight,height,test2;
    
    name = read_string("\n""Enter your name: ");   
    write_line("Welcome "+ name + "\n");
    
    age = read_age("Enter your age: ");
    write_line("Great you are "+ to_string(age)+ "\n");

    test = read_integer("Enter test value",1,10);
    write_line(to_string(test)+"\n");

    height = read_double("Enter Height in Meter");
    weight = read_double("Enter Weight in kg");

    bmi = weight / (height * height);
    write_line("Your BMI is " + to_string(bmi) + "\n");

    test2 = read_double_range("Enter test value in double: ",0.0,1.0);
    write_line(to_string(test2)+"\n");

    bool answer = read_boolean();
    if (answer)
    {
        write_line("You have selected YES!!");
    }
    else
    {
        write_line("You have selected NO!!");
    }

   
    return 0;
}