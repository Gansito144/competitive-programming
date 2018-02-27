#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using II  = pair<int,int>; 
using VI  = vector <int>;
using VII = vector <II>; 

int main ()
{
  int tcs;
  const int MaxN = 2003;
  cin >> tcs;
  for (int tc=1; tc<=tcs; ++tc)
  {
    cout << "Case #" << tc << ":";
    int N, M, T;
    cin >> N >> M;
    VI seen(N, 0), flavor(N, 0);
    vector <VII> wish (M);
    for (VII &wi : wish )
    {
      cin >> T;
      wi.assign(T, II(0,0));
      for (II &c : wi)
      {
        cin >> c.second >> c.first;
        --c.second;
      }
      sort(wi.begin(), wi.end());
    }
    sort(wish.begin(), wish.end(),
      [ ] (VII &a, VII &b) {
        return (a.size() != b.size())
        ? a.size() < b.size()
        : a[0] > b[0];
    });

    bool answer = true;
    int k, n, f;
    for (VII &wi : wish)
    { 
      for (k=1; k<wi.size(); ++k)
      {
        tie(f, n) = wi[k-1];
        if (!seen[n] || (seen[n] && !flavor[n]))
        {
          seen [n]  = 1;
          flavor[n] = 0;
          break;
        }
      }
      if (k < wi.size())
        continue;
      tie(f, n) = wi[k-1];
      if (!seen[n])
      {
        seen [n]  = 1;
        flavor[n] = f;
        continue;
      }
      if (flavor[n] != f)
      {
        answer = false;
        break;
      }
    }

    if (!answer) cout << " IMPOSSIBLE" << endl;
    else
    {
      for (int i=0; i<N; ++i)
      {
        cout << " " << flavor[i];
      }
      cout << endl;
    }
  }
  return 0;
}

