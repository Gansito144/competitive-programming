#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>

#define F first
#define S second

using namespace std;
using i64 = long long int;
using ii = pair <i64, int>;

int main ()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);


  int n, m;

  set <i64> seen;

  cin >> n;
  vector <ii> A(n);
  for (ii &ai : A) cin >> ai.S >> ai.F;
  cin >> m;
  vector <ii> B(m);
  for (ii &bi : B) cin >> bi.S >> bi.F;
  A.insert(A.end(), B.begin(), B.end());
  sort(A.begin(), A.end(), greater<ii>());

  i64 ans = 0LL;
  for (int i=0; i<A.size(); ++i)
  {
    if (seen.find(A[i].S) == seen.end())
    {
      ans += A[i].F;
      seen.insert(A[i].S);
    }
  }
  cout << ans << endl;
  return 0;
}


