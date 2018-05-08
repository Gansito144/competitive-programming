#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using i64 = long long int;

int main ()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;

  vector <int> A(N+2);

  int L = 0, R = N+1;
  int zeros = 0, ones = 0, tot = 0;
  for (int i=1; i<=N; ++i)
  {
    cin >> A[i];
    if (A[i] == 0)
    {
      if (i > L)
      {
        L = i;
        ones = 0;
      }
      if (R < i) ++zeros;
    }
    if (A[i] == 1)
    { 
      if (i < R)
      {
        R = i;
        zeros = 0;
      }
      ++tot;
      ++ones;
    }
  }
  ones = tot - ones;
  //cout << L << " " << ones << endl;
  //cout << R << " " << zeros << endl;

  i64 ans = 0LL;
  for (int k=0; k<N; ++k)
  {
    if (L == 0 || R == N+1)
      break;
    if (zeros < ones)
    {
      ans += (i64) zeros;
      ++R;
      for (; R<=N && A[R]==0; ++R) --zeros;
    }
    else
    {
      ans += (i64) ones;
      --L;
      for (; L>0 && A[L]==1; --L) --ones;
    }
  }
  cout << ans << endl;
  return 0;
}


