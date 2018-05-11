#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main ()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, k;

  cin >> n >> k;

  vector <int> a(n);

  for (int &ai : a) cin >> ai;
  sort(a.begin(), a.end());

  int ans = -1;
  
  if (k == n || k == 0)
  {
    if (k == n) ans = a[n-1];
    if (k == 0 && a[0] > 1) ans = a[0] - 1;
  } 
  else
  {
    if (a[k-1] != a[k]) ans = a[k-1];
  }

  cout << ans << endl; 

  return 0;
}

