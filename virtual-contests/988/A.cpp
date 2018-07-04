#include <iostream>
#include <map>

using namespace std;

int main ()
{
  int n, k, ai;
  map <int,int> id;
  cin >> n >> k;
  for (int i=0; i<n; ++i)
  {
    cin >> ai;
    id[ai] = i+1;
  }
  if (id.size() < k) cout << "NO\n";
  else
  {
    ai = 0;
    cout << "YES\n";
    for (const auto &idx : id)
    {
      if (ai == k) break;
      ++ai;
      cout << idx.second << " ";
    }
    cout << "\n";
  }
  return 0;
}

