#include <iostream>
#include <iomanip>

using namespace std;

constexpr size_t F(size_t n)
{
    return (n == 0 || n == 1) ? 1 : F(n - 1) + F(n - 2);
}

constexpr size_t gcd(size_t a, size_t b)
{
    return (a != 0 && b != 0) ? ((a > b) ? gcd(a % b, b) : gcd(b % a, a)) : (a + b);
}

constexpr bool prime(size_t N, size_t t)
{
    return (t == 1) ? 1 : (N % t == 0 ? 0 : prime(N, --t));
}

constexpr bool isPrime(size_t N)
{
    return N == 1 ? 0 : prime(N, sqrt(N));
}

constexpr size_t primeNum(size_t k, size_t t, size_t count)
{
    return (isPrime(t)) ? (k == count ? t : primeNum(k, ++t, ++count)) : primeNum(k, ++t, count);
}

constexpr size_t kPrimeNum(size_t k)
{
    return primeNum(k, 1, 1);
}

constexpr double exp(size_t iterNum, double expTerm, size_t currIter)
{
    return (iterNum == 1) ? expTerm : exp(iterNum - 1, expTerm / currIter, currIter + 1) + expTerm;
}

constexpr double calcExp(size_t iterNum)
{
    return exp(iterNum, 1, 1);
}

int main()
{
    const size_t n = 5;
    // cout << gcd(30, 18) << endl;
    //  cout << F(9) << endl;
    //  cout << isPrime(8537) << endl;
    //  cout << kPrimeNum(40) << endl;
    cout << setprecision(15) << calcExp(18) << endl;
}