#include <iostream>

using namespace std;

int main ()
{
  int cases;

  cin >> cases;
  for (int tc=1; tc<=cases; ++tc)
  {
    int n, candy, xors=0, mn=123456789, sum=0;
    cin >> n;
    while (n--)
    {
      cin >> candy;
      if (candy < mn)
        mn  = candy;
      xors ^= candy;
      sum  += candy;
    }
    cout << "Case #" << tc << ": ";
    if (xors)
      cout << "NO" << endl;
    else
      cout << (sum-mn) << endl;
  }
  return 0;
}

