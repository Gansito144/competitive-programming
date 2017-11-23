#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>

using namespace std;

int main () 
{
  int cases;
  const string msg = "welcome to code jam";
  const int M = msg.size();
  const int mod = 10000;
  cin >> cases;
  cin.ignore ();
  for (int tc=1; tc<=cases; ++tc)
  {
    string line;
    getline (cin, line);
    int N = line.size();
    vector < vector<int> > sa(2, vector<int> (N, 1));
    int nxt = 1, now = 0; 
    for (int i=0; i< M; ++i)
    {
      // Clean
      sa[nxt].assign(N, 0);
      int cnt = 0;
      for (int j=0; j<N; ++j)
      {
        if (line[j] == msg[i])
        {
          sa[nxt][j] = sa[now][j];
        }
        if ( j ) {
          sa[nxt][j] += sa[nxt][j-1];
          if(sa[nxt][j] >= mod)
            sa[nxt][j] -= mod;
        }
      }
      swap(nxt, now);
    }
    int ans = sa[now][N-1];
    cout << "Case #" << tc << ": ";
    cout << setfill('0') << setw(4) << ans << endl;
  }

  return 0;
}


