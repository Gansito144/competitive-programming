#include <iostream>
#include <set>

using namespace std;

int main ()
{
  const int MaxTries = 100;
  int tcs, n, last;
  cin >> tcs;
  for (int tc=1; tc<=tcs; ++tc)
  {
    cin >> n;
    set < int > digits;
    for (int i=1; i<MaxTries && digits.size() < 10; ++i)
    {
      int nn = n*i;
      last = nn;
      while (nn)
      {
        digits.insert(nn%10);
        nn /= 10;
      }
    }
    cout << "Case #" << tc << ": ";
    if (digits.size() < 10)
      cout << "INSOMNIA" << endl;
    else 
      cout << last << endl;
  }
  return 0;
}

