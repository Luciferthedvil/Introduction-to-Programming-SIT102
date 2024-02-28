#include <cstdint>
#include "splashkit.h"

void print_values(double values[], int size)
{
    write_line("\nValues are: ");
    for (int i = 0; i < size; i++)
    {
        write_line(values[i]);
    }
}

void read_values(double values[], int size)
{
    for (int i = 0; i < size; i++)
    {
        write("Enter temperature values: ");
        values[i] = convert_to_integer(read_line());
    }
}

int sum(double values[], int size)
{
    write("\nSum is: ");
    int result = 0;
    for (int i = 0; i < size; i++)
    {
        result += values[i];
    }

    return result;
}

int count_negative(const double data[], int size)
{
    write("\nThe number of negative values are: ");
    int result = 0;
    for (int i = 0; i < size; i++)
    {
        if (data[i] < 0)
        {
            result++;
        }
    }
    return result;
}

double maximum(const double data[], int size)
{
    write("\nThe maximum value in the array is: ");
    double maxVal = data[0];
    for (int i = 0; i < size; i++)
    {
        if (data[i] > maxVal)
        {
            maxVal = data[i];
        }
    }
    return maxVal;
}

int main()
{
    write_line("How many values do you need: ");
    int count = convert_to_integer(read_line());
    double temp[count];

    read_values(temp, count);

    print_values(temp, count);

    write_line(sum(temp, count));

    write_line(count_negative(temp, count));

    write_line(maximum(temp, count));

    return 0;
}