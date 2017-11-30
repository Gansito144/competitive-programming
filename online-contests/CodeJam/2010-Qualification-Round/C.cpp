#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

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
    unordered_map <int, int> pos;
    i64 cnt = 0;
    int Len = 0;
    int lam = 0;
    int start = 0;
    while(true)
    {
      if(pos.count(start))
      {
        lam = pos[start];
        Len = cnt - lam;
        break;
      }
      pos[start] = cnt;
      i64 win = 0LL;
      int begin = start;
      while( (win + G[start]) <= k )
      {
        win += G[start];
        start = (start + 1LL) % N;
        if(start == begin)
          break;
      }
      ++cnt;
      SA[cnt] = win;
      SA[cnt] += SA[cnt-1];
    }
    i64 ans = 0;
    if(R >= lam) {
      ans += SA[lam];
      R -= lam;
      ans += (R/Len) * (SA[cnt] - SA[lam]);
      ans += SA[(R % Len)+lam] - SA[lam];
      
    } else ans = SA[R];
    cout << "Case #" << tc << ": " << ans << endl;
  }

  return 0;
}

