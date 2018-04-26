#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main ()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, k;

  cin >> n >> k;

  vector< string > G(n);
  vector<vector<int>> cnt(n, vector<int> (n,0));

  for (string &g : G) 
  {
    cin >> g;
    //cout << g << endl;
  }

  for (int r=0; r<n; ++r)
    for (int c=0; c<n; ++c)
    {
      bool can;
      // horizontal
      if ((c+k) <= n)
      {
        can = true;
        for (int j=0; j<k && can; ++j)
          if (G[r][c+j] != '.') can = false;
        if (can) 
        {
          //cout << r << " -H- " << c << endl;
          for (int j=0; j<k; ++j) ++cnt[r][c+j];
        }
      }
      // vertical
      if ((r+k) <= n)
      {
        can = true;
        for (int i=0; i<k && can; ++i)
          if (G[r+i][c] != '.') can = false;
        if (can)
        {
          //cout << r << " -V- " << c << endl;
          for (int i=0; i<k; ++i) ++cnt[r+i][c];
        }
      }
    }

  int ans = 0;
  int x = 1, y = 1;

  for (int r=0; r<n; ++r)
    for (int c=0; c<n; ++c)
      if (cnt[r][c] > ans)
      {
        ans = cnt[r][c];
        x = r+1;
        y = c+1;
      }

  cout << x << " " << y << endl;

  return 0;
}

