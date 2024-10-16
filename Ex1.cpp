#include <iostream>
#include <vector>

int sumEven(const std::vector<int>& v) 
{
    int sum = 0;
    for (const int& num : v) 
    {
        if (num % 2 == 0) 
        {
            sum += num;
        }
    }
    return sum;
}

int main() 
{
    std::vector<int> numbers = {3, 3, 4, 5, 6};

    int result = sumEven(numbers);

    std::cout << result << std::endl;

    return 0;
}
