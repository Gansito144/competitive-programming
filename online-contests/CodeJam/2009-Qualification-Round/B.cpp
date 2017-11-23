#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;
using vi = vector <int>;

inline int find (vi &p, int x)
{
  return p[x] = (x == p[x]) ? x : find(p, p[x]);
}

int main ()
{
  int cases;
  // Matrix of movements N, W, E, S 
  int mv[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};
  
  cin >> cases;
  for (int tc=1; tc<=cases; ++tc)
  {
    cout << "Case #" << tc << ":" << endl;
    int H, W;
    cin >> H >> W;
    vi p  (H * W);
    vector <vi> G (H, vi(W));

    for (int h=0; h<H; ++h)
    {
      for (int w=0; w<W; ++w)
      {
        cin >> G[h][w];
        p[h*W + w] = h*W + w;
      }
    }

    for (int h=0; h<H; ++h)
    {
      for (int w=0; w<W; ++w)
      {
        int fat = h*W + w;
        int best = G[h][w], son = -1;
        for (int k=0; k<4; ++k)
        {
          int nh = h + mv[k][0];
          int nw = w + mv[k][1];
          if (nh<0 || nh>=H || nw<0 || nw >= W)
            continue;
          if (G[nh][nw] < best)
          {
            best = G[nh][nw];
            son = nh * W + nw;
          }
        }
        
        if(son != -1 && (find(p, fat) != find(p, son)))
        {
          // cout << fat << " -join- " << son << endl;
          p[find(p, son)] = find(p, fat);
        }
      }
    }
    char curr = 'a';
    unordered_map <int, char> let;
    for (int h=0; h<H; ++h)
    {
      for (int w=0; w<W; ++w)
      {
        if(w) cout << " ";
        int root = find(p, h*W + w);
        if(let.count(root) == 0)
        {
          let[root] = curr ++;
        }
        cout << let[root];
      }
      cout << endl;
    }
  }
  return 0;
}

