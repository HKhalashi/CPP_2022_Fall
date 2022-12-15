#include <iostream>
long long  f(long long a, long long b, long long c)
{
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    else if (a > 20 || b > 20 || c > 20) return f(20, 20, 20);
    else if (a < b && b < c) return f(a, b - 1, c) + f(a, b, c - 1) - f(a, b - 1, c - 1);
    else
    {
        a--;
        return f(a, b - 1, c) + f(a, b, c - 1) - f(a, b - 1, c - 1) + f(a, b, c);
    }
}
int main() {
    long long a , b , c;
    std::cin>> a>> b >>c;
    std::cout << f(a , b , c);
    return 0;
}
