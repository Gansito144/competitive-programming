#include <iostream>
#include <iomanip>

using namespace std;
using i64 = long long int;

const int MX = 65;
i64 C[MX][MX+2];

void sieve()
{
  for (int r=1; r<MX; ++r)
  {
    for (int c=0; c<=r; ++c)
    {
      if (c==0 || c==r)
        C[r][c] = 1LL;
      else
        C[r][c] = C[r-1][c-1] + C[r-1][c];
    }
  }
}

int main ()
{
  sieve();
  int tcs;
  cin >> tcs;
  while (tcs--)
  {
    int n, k;
    cin >> n >> k;
    double ans = 1000000000000000LL;
    ans *= (double) k;
    i64 pos = 0;
    for (int j=2; j<n-1; ++j)
      pos += C[n][j];
    ans = ans / pos;
    cout << setprecision(20) << ans << endl;
  }
  return 0;
}

