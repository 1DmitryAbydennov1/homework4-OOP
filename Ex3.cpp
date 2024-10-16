#include <iostream>
#include <vector>
#include <cmath>

std::vector<std::pair<int, int>> factorization(int n) 
{
    std::vector<std::pair<int, int>> factors;
    
    int count = 0;
    while (n % 2 == 0) 
    {
        n /= 2;
        count++;
    }
    if (count > 0) 
    {
        factors.push_back({2, count});
    }
    
    for (int i = 3; i <= std::sqrt(n); i += 2) 
    {
        count = 0;
        while (n % i == 0) 
        {
            n /= i;
            count++;
        }
        if (count > 0) 
        {
            factors.push_back({i, count});
        }
    }
    
    if (n > 2) 
    {
        factors.push_back({n, 1});
    }
    
    return factors;
}

int main() 
{
    int number = 626215995;
    std::vector<std::pair<int, int>> factors = factorization(number);
    std::cout << "{";
    for (const auto& factor : factors)
       std::cout << "{" << factor.first << "," << factor.second << "}";
    std::cout << "}" << std::endl;

    return 0;
}
