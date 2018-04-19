#include <iostream>
#include <algorithm>

using namespace std;
using i64 = long long int;

inline i64 gauss(i64 n)
{
  return (n&1LL) ? n*((n+1LL)>>1) : (n>>1)*(n+1LL);
} 

int main ()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int T, n;
  cin >> T;
  while (T--)
  {
    cin >> n;
    cout << gauss(max(0LL, n-2LL)) << endl;
  }
  return 0;
}
