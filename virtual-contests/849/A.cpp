#include <iostream>

using namespace std;

int main ()
{
  int x[102], n, cnt, sa;
  bool pos = true;

  cin >> n;
  for(int i=0; i<n; ++i) cin >> x[i];

  if( (x[0]%2==0) || (x[n-1]%2==0) || (n%2==0))
    pos = false;

  cout << (pos ? "Yes" : "No" ) << endl;

  return 0;
}

