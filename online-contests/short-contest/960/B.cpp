#include <iostream>
#include <set>
#include <tuple>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
using i64 = long long int;
using edge = pair <int,int>;

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k1, k2;
  cin >> n >> k1 >> k2;

  vector <int> a(n), b(n);

  for (int &ai : a) cin >> ai;
  for (int &bi : b) cin >> bi;

  priority_queue <edge> PQ; 
  for (int i=0; i<n; ++i)
  {
    PQ.push( make_pair(abs(a[i]-b[i]),i) );
  }

  while (k1 > 0 || k2 > 0)
  {
    int d, i;
    tie(d, i) = PQ.top();
    PQ.pop();
    if (k1)
    {
      --k1;
      if (a[i] > b[i]) --a[i];
      else ++a[i];
    }
    else
    {
      --k2;
      if (a[i] > b[i]) ++b[i];
      else --b[i];
    }
    PQ.push(make_pair(abs(a[i]-b[i]), i));
  }
  i64 ans = 0, s;

  for (int i=0; i<n; ++i)
  {
    s = a[i]-b[i];
    ans += s*s;
  }

  cout << ans << endl;
  return 0;
}

