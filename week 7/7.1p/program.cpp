#include "splashkit.h"
#include <vector>

using namespace std;

struct person
{
    string name;
    int age;
};

struct car
{
    string description;
    person driver;

    vector<person> passengers;
};

string read_string(string prompt)
{
    string result;

    write(prompt);
    result = read_line();

    return result;
}

int read_integer(string prompt)
{
    string line;
    int result;

    line = read_string(prompt);
    result = convert_to_integer(line);

    return result;
}

person read_person()
{
    person result;

    result.name = read_string("Enter the person's name: ");
    result.age = read_integer("Enter the person's age: ");

    return result;
}

void print_person(const person &to_print)
{
    write_line(to_print.name + " " + to_string(to_print.age));
}

car read_car()
{
    int count;
    car result;

    result.description = read_string("\nEnter the car's description: ");
    write_line("\nProvide the driver's details");
    result.driver = read_person();

    count = read_integer("\nHow many passengers: ");

    for (int i = 0; i < count; i++)
    {
        person passenger;
        passenger = read_person();

        result.passengers.push_back(passenger);
    }

    return result;
}

void print_car(const car &to_print)
{
    write_line("\n---------");
    write_line(to_print.description);
    write_line("---------");
    write_line("Driver:");
    print_person(to_print.driver);
    write_line("---------");
    write_line("Passengers");

    for (person p : to_print.passengers)
    {
        print_person(p);
    }

    write_line("---------");
}

void populate_cars(vector<car> &cars)
{
    int count;
    count = read_integer("\nHow many cars do you want to add: ");

    for (int i = 0; i < count; i++)
    {

        car temp;
        temp = read_car();

        cars.push_back(temp);
    }
}

void print_all_cars(const vector<car> &cars)
{
    for (car c : cars)
    {
        print_car(c);
        write_line();
    }
}

void print_cars_by_driver(const vector<car> &cars, const string &driver_name)
{
    bool found = false;

    for (const car &c : cars)
    {
        if (c.driver.name == driver_name)
        {
            print_car(c);
            found = true;
        }
    }

    if (!found)
    {
        write_line("No cars found for driver: " + driver_name);
    }
}
int main()
{
    vector<car> cars;

    populate_cars(cars);

    print_all_cars(cars);

    string driver_name_to_check = read_string("\nEnter a driver's name to check for cars: ");
    print_cars_by_driver(cars, driver_name_to_check);

    return 0;
}