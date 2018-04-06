#include <iostream>
#include <algorithm>
#include <string>
#include <climits>

using namespace std;

int main ()
{
  int n;
  string row;

  cin >> n;

  int C[4][2] = {};

  for (int b=0; b<4; ++b)
  {
    for (int r=0; r<n; ++r)
    {
      cin >> row;
      for (int c=0; c<n; ++c)
      {
        char color = '0' + ((r&1) ^ (c&1));
        //cout << r << " " << c << " " << color << endl;
        C[b][0] += row[c] != color;
        C[b][1] += row[c] == color;
      } 
    }
    //cout<<"C["<<b<<"][0] = " << C[b][0] << endl;
    //cout<<"C["<<b<<"][1] = " << C[b][1] << endl;
  }
  int ans = INT_MAX;
  ans = min(ans,C[0][0]+C[1][0] + C[2][1]+C[3][1]);
  ans = min(ans,C[0][0]+C[2][0] + C[1][1]+C[3][1]);
  ans = min(ans,C[0][0]+C[3][0] + C[1][1]+C[2][1]);
  ans = min(ans,C[1][0]+C[2][0] + C[0][1]+C[3][1]);
  ans = min(ans,C[1][0]+C[3][0] + C[0][1]+C[2][1]);
  ans = min(ans,C[2][0]+C[3][0] + C[0][1]+C[1][1]);

  cout << ans << endl;
  return 0;
}

