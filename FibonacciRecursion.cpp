#include <iostream>
using namespace std;
int fibonacci(int n)
{
    if (n<=0)
    {
        return 0;
    }
    else if (n==1)
    {
        return 1;
    }
    else
    {
        return (fibonacci(n-1)+fibonacci(n-2));
    }
}
int main()
{
    int n;
    cout << "What factorial would you like to compute?" << endl;
    cin>>n;
    for (int x = 0; x < n; x++)
    cout << fibonacci(x) << " ";

  return 0;
}
