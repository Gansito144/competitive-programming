#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
using i64 = long long int;

int main ()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, k, x, ans = 0;
  cin >> n >> k;
  
  deque <int> Q;

  while (n--)
  {
    cin >> x;
    Q.push_front(x);
  }

  while (!Q.empty())
  {
    if (Q.front() <= k)
    {
      ++ans;
      Q.pop_front();
    }
    else if (Q.back() <= k)
    {
      ++ans;
      Q.pop_back();
    }
    else break;
  }
  cout << ans << endl;
  return 0;
}

