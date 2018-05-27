#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main ()
{
  int R, C;
  
  cin >> R >> C;

  vector <string> G(R);
  vector <vector<int>> cnt(R, vector<int> (C, 0));

  for (string &si : G) cin >> si;

  bool can  = true;
  for (int r=0; r<R; ++r)
    for (int c=0; c<C; ++c)
      if (G[r][c] == '*')
      {
        for (int dx=-1; dx<=1; ++dx)
          for (int dy=-1; dy<=1; ++dy)
          {
            if (!dx && !dy)
              continue;
            int nr = r + dx;
            int nc = c + dy;
            if (nr<0||nr>=R||nc<0||nc>=C)
              continue;
            if (G[nr][nc] == '.')
            {
              can = false;
              break;
            }
            ++cnt[nr][nc];
          }
      }

  if (!can) cout << "NO" << endl;
  else
  {
    for (int r=0; r<R; ++r)
      for (int c=0; c<C; ++c)
        if (G[r][c]>'0' && G[r][c]<'9' 
           && (cnt[r][c] != (G[r][c]-'0')))
        {
          can = false;
          break;
        }
    cout << (can ? "YES" : "NO") << endl;
  }

  return 0;
}

