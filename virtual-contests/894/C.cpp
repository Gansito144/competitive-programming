#include <iostream>
#include <algorithm>
#include <vector> 

using namespace std;

int main ()
{
  int m, n, g = 0;

  cin >> m;
  vector <int> gcds(m);

  for (int &gcd : gcds)
  {
    cin >> gcd;
    g = ( g ) ? __gcd(g, gcd) : gcd;
  }

  if ( g != gcds[0] )
  {
    cout << -1 << endl;
  }
  else
  {
    cout << (m<<1) + 1 << endl << g;
    for (const int &gcd : gcds)
      cout << " " << g << " " << gcd;
    cout << endl;
  }
  return 0;
}

