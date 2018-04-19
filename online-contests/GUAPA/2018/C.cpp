#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>

#define F first
#define S second
#define mp make_pair

using namespace std;
using i64 = long long int;
using ii  = pair <int, int>;
using edge = pair <i64, ii>;

int main ()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  int R, C;

  cin >> R >> C;
  vector <vector<i64>> G(R, vector <i64> (C,0LL));
  vector <vector<i64>> D(R, vector <i64> (C,-1LL));

  for (int r=0; r<R; ++r)
    for (int c=0; c<C; ++c)
      cin >> G[r][c];

  int r, c;
  cin >> r >> c;
  --r; --c; 

  priority_queue <edge> PQ;
  i64 ans = 0LL;

  if (G[r][c] > 0LL)
  {
    PQ.push(mp(G[r][c], mp(r,c)));
    D[r][c] = G[r][c];
    while (!PQ.empty())
    {
      int pr = PQ.top().S.F;
      int pc = PQ.top().S.S;
      i64 v = PQ.top().F; PQ.pop();
      //cout <<"G["<<pr<<", "<<pc<<"] = " << v << endl;
      for (int dr=-1; dr<=1; ++dr)
        for (int dc=-1; dc<=1; ++dc)
        {
          if(dr==0 && dc==0) continue;
          int nr = pr + dr;
          int nc = pc + dc;
          if (nr<0||nr>=R||nc<0||nc>=C||G[nr][nc] == 0LL)
            continue;
          i64 nv = min(D[pr][pc], G[nr][nc]);
          //cout <<nr<<","<<nc<<" comming from "<<pr<<","<<pc<<endl;
          //cout << D[nr][nc] << " -- " << G[pr][pc] << " " << G[nr][nc] << endl;
          if (D[nr][nc] < 0LL || D[nr][nc] < nv)
          {
            PQ.push(mp(nv, mp(nr,nc)));
            D[nr][nc] = nv;
          }
        }
    }
  }

  for (const auto &X : D)
    for (const auto &Y : X)
      if(Y > 0LL) ans += Y;

  cout << ans << endl;
  return 0;
}

