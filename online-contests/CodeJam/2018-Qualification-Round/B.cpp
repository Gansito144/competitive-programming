#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int tcs;
  cin >> tcs;

  for (int tc=1; tc<=tcs; ++tc)
  {
    cout << "Case #" << tc << ": ";
    int N;
    cin >> N;
    vector <int> A((N+1)/2), B(N/2);
    for (int i=0; i<N; ++i)
    {
      if (i%2) cin >> B[i/2];
      else cin >> A[i/2];
    }
    if (A.size() == B.size())
      A.push_back(1000000002);
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int err = -1;
    for (int i=0; i<B.size(); ++i)
    {
      if (B[i] > A[i+1])
      {
        err = (i+1) * 2 - 1;
        break;
      }
      if (B[i] < A[i])
      {
        err = (i) * 2;
        break;
      }
    }
    if (err == -1) cout << "OK\n";
    else cout << err << "\n"; 
  }

  return 0;
}


