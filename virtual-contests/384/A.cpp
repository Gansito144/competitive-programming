#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main ()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, cnt = 0;

  cin >> n;

  vector <vector<char>> G(n, vector <char> (n, '.'));

  for (int r=0; r<n; ++r)
    for (int c=(r&1); c<n; c+=2)
    {
      ++cnt;
      G[r][c] = 'C';
    }

  cout << cnt << endl;
  for (const auto & gi : G)
  {
    for (const char & c : gi)
      cout << c;
    cout << endl;
  }

  return 0;
}


