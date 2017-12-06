#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
  int cases;
  cin >> cases;

  for (int tc=1; tc<=cases; ++tc)
  {
    int n, ans=0, v;
    cin >> n;
    for (int i=0; i<n; ++i)
    {
      cin >> v;
      --v;
      ans += (i != v);
    }
    cout<< "Case #"<< tc << ": " << (ans) << endl;
  }
  return 0;
}

