#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
using i64 = long long int;

int main ()
{
  int n;
  cin >> n;

  vector <int> a(n), ans;
  set <int> s;

  for (int &ai: a) cin >> ai;

  for (int i=n-1; i>=0; --i)
    if (s.find(a[i]) == s.end())
    {
      ans.push_back(a[i]);
      s.insert(a[i]);
    }

  reverse(ans.begin(), ans.end());

  cout << ans.size() << endl;
  for (const int &ai: ans) cout << ai << " ";
  cout << endl;

  return 0;
}

