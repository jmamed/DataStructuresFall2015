//Problem 4
//Calculates the number of items in a queue
// queue::size
#include <iostream>       // std::cout
#include <queue>          // std::queue
using namespace std;
int main ()
{
  queue<int> myints;
  for (int i=0; i<50; i++) myints.push(i);
  cout << "1. size: " << myints.size() << '\n';

  return 0;
}
