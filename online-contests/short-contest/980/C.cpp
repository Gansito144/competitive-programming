#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;
using i64 = long long int;

int main ()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, k, p;
  cin >> n >> k;
  vector <int> key(256, -1);

  while (n--)
  {
    cin >> p;
    if (key[p] == -1)
    {
      int L = max(0, p-k+1);
      //cout << L  << " " << key[L] << endl; //
      if (key[L] != -1)
      {
        int ky = key[L];
        int pp = p;
        if ((p-ky) < k)
          while (key[pp] == -1) key[pp--] = ky;
        else
          while (key[L] == ky) ++L;
      }
      int R = p;
      if (key[p] == -1)
      {
        //cout << L << " , " << R << endl; //
        int ky = L;
        for (int i=L; i<=R; ++i)
          key[i] = ky;
      }
    }
    cout << key[p] << " ";
  }
  cout << endl;

  return 0;
}


