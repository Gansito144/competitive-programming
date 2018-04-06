#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


const int kM = 202;
int cnt[kM], sa[kM];

int main ()
{
  int n, d, x;

  cin >> n >> d;

  int nn = n;
  while (nn--)
  {
    cin >> x;
    ++cnt[x];
  }

  int ans = n;
  for (int i=1; i<kM; ++i)
    sa[i] = sa[i-1] + cnt[i];
  for (int i=1; i<102; ++i)
  {
    int in = sa[i+d] - sa[i-1];
    ans = min(ans, n-in);
  }
  cout << ans << endl;  
  return 0;
}

