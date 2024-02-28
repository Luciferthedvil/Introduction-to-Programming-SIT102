#include <cstdint>
#include "splashkit.h"

using namespace std;
void number_guesser()
{
   int rand_num, my_num;

   rand_num = rnd(100) + 1;

   write_line("\nTry and guess the number that I'm guessing between 1 and 100");

   while (my_num != rand_num)
   {
      write("Enter your guess: ");
      my_num = convert_to_integer(read_line());
      if (my_num == rand_num)
      {
         break;
      }
      if (my_num < rand_num)
      {
         write_line("Ahhh...My guess is more than " + to_string(my_num));
      }
      else if (my_num > rand_num)
      {
         write_line("oops...My guess is less than " + to_string(my_num));
      }
   }
   write_line("Congrats...you guessed it right. it was " + to_string(my_num));
}
int main()
{
   int choice;
   do
   {
      write_line("\nLet's play Guess My Number!");
      write_line("Enter 1 to play");
      write_line("Enter 2 to exit\n");

      choice = convert_to_integer(read_line());
      switch (choice)
      {
      case 1:
         number_guesser();
         break;

      case 2:
         write_line("Ok.. bye bye");
         break;

      default:
         write_line("Enter either 1 0r 2");
         break;
      }
   } while (choice != 2);
   return 0;
}