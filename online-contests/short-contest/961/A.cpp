#include <iostream>
#include <vector>

using namespace std;

int main ()
{
  int n, m, ans=0, cnt=0, ci;
  cin >> n >> m;
  vector <int> col(n, 0);
  while (m--)
  {
    cin >> ci;
    --ci;
    ++col[ci];
    if (col[ci] > 1)
      continue;    
    ++cnt;
    if (cnt == n)
    {
      ++ans;
      for (int &c : col)
      {
        --c;
        if (!c) --cnt;
      }
    }
  }
  cout << ans << endl;
  return 0;
}

