#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main ()
{
  int n;
  double a, b, m, p = 1000000000.0;
  cin >> n >> m;
  while (n--)
  {
    cin >> a >> b;
    p = min(p, a/b);
  }
  cout << setprecision(20) << p*m << endl;
  return 0;
}


