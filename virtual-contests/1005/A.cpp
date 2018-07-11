#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
  int n;
  cin >> n;
  vector <int> a(n+1, 1), ans;
  for (int i=0; i<n; ++i) cin >> a[i];
  for (int i=1; i<=n; ++i) 
    if (a[i] <= a[i-1]) 
      ans.push_back(a[i-1]);
  cout << ans.size() << endl;
  for (const int &ai : ans)
   cout << ai << " ";
  cout << endl; 
  return 0;
}

