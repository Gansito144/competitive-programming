#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main ()
{
  int R, C;

  cin >> R >> C;
  vector <string> G(R);

  for (string &g : G)
  {
    cin >> g;
  }

  vector <string> B = G;

  vector <int> sr(R, 0), sc(C, 0);
  queue <int> Q;

  bool can = true;
  int shot = 1;
  for (int r=0; r<R && can; ++r)
    for (int c=0; c<C; ++c)
    {
      if (G[r][c] == '#')
      {
        ++shot;
        if (sr[r] || sc[c])
        {
          can = false;
          break;
        }
        sr[r] = shot;
        sc[c] = shot;
        G[r][c] = '.';
        Q.push (r*2);
        Q.push (c*2 + 1);
        while (!Q.empty())
        {
          int v = Q.front(); Q.pop();
          if (v & 1)
          {
            int cc = v >> 1;
            for (int rr=0; rr<R; ++rr)
            {
              if (G[rr][cc] == '#')
              {
                if (sr[rr] && sr[rr] != shot)
                {
                  can = false;
                  break;
                }
                if (sr[rr] == 0) Q.push(rr*2);
                sr[rr] = shot;
                G[rr][cc] = '.';
              }
            }
          }
          else
          {
            int rr = v >> 1;
            for (int cc=0; cc<C; ++cc)
            {
              if (G[rr][cc] == '#')
              {
                if (sc[cc] && sc[cc] != shot)
                {
                  can = false;
                  break;
                }
                if (sc[cc] == 0) Q.push(cc*2+1);
                sc[cc] = shot;
                G[rr][cc] = '.';
              }
            }
          }
        }
      }
      for (int rr=0; rr<R && can; ++rr)
        for (int cc=0; cc<C; ++cc)
          if (sr[rr] && sr[rr] == sc[cc] && B[rr][cc] != '#')
          {
            can = false;
            break;
          }
    }

  cout << (can ? "Yes" : "No") << endl;

  return 0;
}
