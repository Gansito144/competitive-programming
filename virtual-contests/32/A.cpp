#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main ()
{
  int n, d, ans=0;
  cin >> n >> d;
  vector <int> so (n);
  for (int &s : so) cin >> s;
  sort(so.begin(), so.end());
  int L=0, R=1;
  while (R<n)
  {
    while(L<R && (so[R]-so[L]) > d) ++L;
    ans += (R-L)<<1; 
    ++R;
  }
  cout << ans << endl;
  return 0;
}

