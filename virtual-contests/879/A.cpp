#include <iostream>

using namespace std;

int main ()
{
  int s, d, t = 0, n, w;
  cin >> n;
  while(n--) 
  {
    cin >> s >> d;
    while(s <= t) s += d;
    t = s; 
  }
  cout << t << endl;
  return 0;
}

