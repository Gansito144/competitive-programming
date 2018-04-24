#include <iostream>

using namespace std;

int main ()
{
  int n, m, a, b, ra, rb, ca, cb;

  cin >> n >> m >> a >> b;
  --a; --b;
  ra = a / m;
  rb = b / m;
  ca = a % m;
  cb = b % m;

  int ans = 1;
  const int ST = 0;
  const int EN = m-1;
  if (ra != rb)
  {
    if (!(ca==ST && (b==n-1 || cb==EN)))
    {
      ++ans;
      if (!(ca==ST || (b==n-1 || cb==EN) || ((b-a+1)%m == 0)))
      {
        ++ans;
        if (rb-ra <= 1)
          --ans;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
