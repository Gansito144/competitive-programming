#include <iostream>

using namespace std;

int main ()
{
  int cases, n, k;
  cin >> cases;
  for (int tc=1; tc<=cases; ++tc)
  {
    cin >> n >> k;
    ++k;
    n = 1 << n;
    cout << "Case #" << tc << ": " << ((k%n)?"OFF":"ON") << endl;
  }
  return 0;
}


