#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;
using i64 = long long int;

int main ()
{
  int cases;

  cin >> cases;
  for (int tc=1; tc<=cases; ++tc)
  {
    i64 R, k, N;
    cin >> R >> k >> N;

    vector <i64> G (N);
    vector <i64> SA(N+1, 0LL);

    for (i64 &gi : G) cin >> gi;

    int start = 0;
    i64 ans = 0LL;
    while(R--)
    {
      i64 win = 0LL;
      int begin = start;
      while( (win + G[start]) <= k )
      {
        win += G[start];
        start = (start + 1LL) % N;
        if(start == begin)
          break;
      }
      ans += win;
    }
    cout << "Case #" << tc << ": " << ans << endl;
  }

  return 0;
}

