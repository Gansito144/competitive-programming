#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main ()
{
  const long double two = 2.0;
  int tcs;
  cin >> tcs;
  for (int tc=1; tc<=tcs; ++tc)
  {
    cout << "Case #" << tc << ": ";
    long double C, F, X, ANS = 0.0, T = 0.0, S = two;
    cin >> C >> F >> X;
    while ( T < X )
    {
      long double tc = (C-T) / S;
      long double tx = (X-T) / S;
      long double txc = tc + (X / (S + F));
      if ( txc < tx)
      {
        ANS += tc;
        S += F;
        T = 0.0;
      }
      else
      {
        ANS += tx;
        T = X;
      }
    }
    cout << setprecision(20) << ANS << endl;
  }
  return 0;
}


