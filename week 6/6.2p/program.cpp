#include <cstdint>
#include "splashkit.h"

#include <vector>
using namespace std;

void print_values(const vector<int> &values)
{
    write_line("\nValues are: ");
    for (int i = 0; i < values.size(); i++)
    {
        write_line(values[i]);
    }
}

void read_values(vector<int> &values, int size)
{
    int data;
    for (int i = 0; i < size; i++)
    {
        write("Enter temperature values: ");
        data = convert_to_integer(read_line());
        values.push_back(data);
    }
}

int sum(const vector<int> &values)
{
    write("\nSum is: ");
    int result = 0;
    for (int i = 0; i < values.size(); i++)
    {
        result += values[i];
    }

    return result;
}

int count_negative(vector<int> data)
{
    write("\nThe number of negative values are: ");
    int result = 0;
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i] < 0)
        {
            result++;
        }
    }
    return result;
}

int maximum(vector<int> data)
{
    write("\nThe largest value in the array is: ");
    int maxVal = data[0];
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i] > maxVal)
        {
            maxVal = data[i];
        }
    }
    return maxVal;
}

vector<int> double_all(const vector<int> &input)
{
    vector<int> result;

    for (int i = 0; i < input.size(); i++)
    {
        result.push_back(input[i]*2);
    }
    return result; 
}
int main()
{
    write_line("How many values do you need: ");
    int count = convert_to_integer(read_line());

    vector<int> temp;
    vector<int> copy;
    

    read_values(temp, count);
    copy = double_all(temp);

    print_values(temp);
    write_line(sum(temp));
    write_line(count_negative(temp));
    write_line(maximum(temp));

    write_line("\nAll doubled is...");
    print_values(copy);
    write_line(sum(copy));
    write_line(count_negative(copy));
    write_line(maximum(copy));

    return 0;
}