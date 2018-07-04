#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main ()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  const int N = 2000006;
  int n, k, ai;
  cin >> n >> k;

  vector <int> c(N, 0), s(N, 0);
  while (n--)
  {
    cin >> ai;
    ++c[ai];
    int L = max(0, ai - k);
    int R = ai;
    ++s[L];
    --s[R];
  }

  int ans = 0;
  for (int i=1; i<N; ++i)
  {
    s[i] += s[i-1];
    if (!s[i])
      ans += c[i];
  }
  
  cout << ans << endl;

  return 0;
}


