#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using i64 = long long int;

int main ()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tcs;
  cin >> tcs;
  while (tcs--)
  {
    int e, s;
    cin >> e >> s;
    vector <i64> E(e), S(s);
    for (i64 &ei : E) cin >> ei;
    for (i64 &si : S) cin >> si;
    bool can = true;
    int i = 0;
    for (int j=0; j<s; ++j)
    {
      bool found = false;
      for (; i<e; ++i)
      {
        if (E[i] == S[j])
        {
          found = true;
          break;
          ++i;
        }
      }
      if (!found)
      {
        can = false;
        break;
      }
    }  
    cout << (can ? "Estan entre nosotros" : "You always knew") << endl;
  } 
  return 0;
}

