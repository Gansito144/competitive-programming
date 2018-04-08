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
    int A, x, y;
    cin >> A;
    vector <int> F(A + 3, 0);
    bool error = false;
    bool success = false;
    for (int i=1; i<=A && !error && !success; ++i)
    {
      while (F[i] != 7)
      {
        x = (i+1 > A) ? i : i + 1;
        y = 2;
        cout << x << " " << y << endl;
        cin >> x >> y;
        if (x < 0 && y < 0) 
        {
          error = true;
          break;
        }
        if (x==0 && y==0)
        {
          success = true;
          break;
        }
        cerr << i << " " << x << " " << y << " " << F[x-1] << endl;
        F[x] |= 1 << (y-1);  
      }
    } 
    if (error) break;
  }

  return 0;
}


