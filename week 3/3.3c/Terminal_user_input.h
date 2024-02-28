#include <string>
using namespace std;

string read_string(string prompt);
int read_age(string prompt);
int read_integer(string prompt, int min, int max);
double read_double(string prompt);
double read_double_range(string prompt, int min, int max);
bool read_boolean();