#include <iostream>
#include <vector>

void lastDigits(std::vector<int>& vec) 
{
    for (size_t i = 0; i < vec.size(); i++) 
    {
        vec[i] = std::abs(vec[i] % 10);
    }
}

int main() 
{
    std::vector<int> numbers = {123, -456, 7890, -12, 0, 5};

    lastDigits(numbers);

    for (int num : numbers) 
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
