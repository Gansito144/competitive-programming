#include<iostream>
#include<algorithm>

using namespace std;
using i64 = long long int;

int main ()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int T, N;
  i64 K;

  cin >> T;

  while (T--)
  {
    cin >> N  >> K;
    if (N == 1)
      cout << K << endl;
    else
    {
      i64 X = 0, MB = 0;
      int b;
      for (b=0; b<32; ++b)
      {
        if ( (1LL<<b) > K) break;
      }
      MB = 1LL << (b-1);
      X = max(1LL, MB - 1LL);
      if (N & 1) 
      {
        if ( (MB|1LL) <= K)
        {
          MB |= 1LL;
          cout << MB << " " << X << " 1";
        }
        else if ( X > 1LL)
        {
          cout << MB << " " << (X-1LL) << " 1";
        }
        else
        {
          cout << MB << " " << X << " 1";
        }
        --N;
      } else cout << MB << " " << X;
      for (int i=2; i<N; ++i)
        cout << " " << 1;
      cout << endl;
    }
  }
  return 0;
}
