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
  int result;
  write_line(prompt);
  result = convert_to_integer(read_line());

  return result;
}

void output_crazy_age(int age)
{
  write(to_string(age) + " is a super");
  int i = 0;
  while (i < 5)
  {
    write(" crazy");
    i++;
  }
  write_line(" age!");
}

void output_silly_name(string name)
{
  write("whoa..." + name + " is a");
  int i = 0;
  while (i < 5)
  {
    write(" silly");
    i++;
  }
  write_line(" name!..hahahaha!!\n");
}

int main()
{
  int choice;
  do
  {
    int age;
    string name;

    write_line("\nENTER 1 TO CONTINUE");
    write_line("ENTER 0 TO EXIT");
    choice = convert_to_integer(read_line());

    switch (choice)
    {
    case 1:
      name = read_string("\nEnter your name: ");
      if (name == "Lucifer")
      {
        write_line("That's an Awesome name " + name + "\n");
      }
      else if (name == "John")
      {
        output_silly_name(name);
      }
      else if (name == "Jack")
      {
        output_silly_name(name);
      }
      else
      {
        write_line("Welcome " + name + "\n");
      }

      age = read_age("Enter your age: ");
      if (age == 30)
      {
        write_line("interesting age! ");
      }
      else if (age < 0 or age > 120)
      {
        write_line("Seriously!, come on man, for real huh??\n");
      }
      else if (age > 0 and age < 22)
      {
        output_crazy_age(age);
      }
      else
      {
        write_line("Great you are " + to_string(age) + "\n");
      }
      break;

    case 0:
      write_line("Bye bye...");
      break;

    default:
      write_line("Enter either 1 or 0");
      break;
    }

  } while (choice != 0);
  return 0;
}
