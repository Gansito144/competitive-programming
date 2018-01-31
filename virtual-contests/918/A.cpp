#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main ()
{
  int N;
  cin >> N;
  string s(N,'o');
  int a = 1, b=2;
  s[a-1] = 'O';
  while (b <= N)
  {
    s[b-1] = 'O';
    a = a + b;
    swap(a,b);
  }
  cout << s << endl;
  return 0;
}

