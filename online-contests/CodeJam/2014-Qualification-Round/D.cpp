#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main ()
{
  int tcs;
  cin >> tcs;
  for (int tc=1; tc<=tcs; ++tc)
  {
    int n;
    cin >> n;
    vector <double> A(n), B(n);
    for (double &a : A) cin >> a;
    for (double &b : B) cin >> b;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int L=0, R=n-1;
    int LL=0, RR=n-1;
    int warc=0 , dwar=0;
    for (int i=n-1; i>=0; --i)
    {
      if (B[i] > A[R])
        ++L;
      else
        ++dwar,--R;
      if (A[i] > B[RR])
        ++LL;
      else
        ++warc, --RR;
    }
    cout << "Case #" << tc << ": " << dwar << " " << (n-warc)<< endl;
  }
  return 0;
}

