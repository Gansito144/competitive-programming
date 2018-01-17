#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main ()
{
  int tcs;
  map <int, int> mxS;
  map <int, int> mxNS;
  int mc = 2;
  for (int A=0; A<=8; ++A)
  {
    for (int k=0; k<3; ++k)
    {
      mxS[A*3 + 2 + k] = mc;
    }
    ++mc;
  }
  int key = 0;
  mxNS[key] = key;
  for (int v=1; v<=30; v+=3)
  {
    ++key;
    for (int j=0; j<3; ++j)
    {
      mxNS[v+j] = key;
    }
  }
  cin >> tcs;
  for (int tc=1; tc<=tcs; ++tc)
  {
    int ans=0, score, p, n, s;
    cin >> n >> s >> p;
    while (n--)
    {
      cin >> score;
      if (mxNS[score] >= p)
      {
        ++ans;
      } else if (s && mxS[score] >= p)
      {
        --s;
        ++ans;
      }
    }

    cout << "Case #" << tc << ": " << ans << endl;
  }
  return 0;
}

