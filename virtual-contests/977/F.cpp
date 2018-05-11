#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main ()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, ans = 0, km = 0;

  cin >> n;
  vector <int> a(n);
  map <int, int> mx;
  for (int &ai : a)
  {
    cin >> ai;
    mx[ai] = mx[ai-1] + 1;
    if (mx[ai] > ans)
    {
      ans = mx[ai];
      km = ai;
    }
  }

  vector <int> sol(ans);
  cout << ans << endl;
  for (int i=n-1; i>=0; --i)
  {
    if (a[i] == km)
    {
      sol[--ans] = i+1;
      --km;
    }
  }

  for (const int &si : sol)
    cout << si << " ";
  cout << endl;

  return 0;
}


