#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main ()
{
  const int rows=4;
  int tcs;
  cin >> tcs;

  for (int tc=1; tc<=tcs; ++tc)
  {
    int one, two, matches = 0, match;
    set <int> keep;
    int a, b, c, d; // elements in a row;
    cin >> one;
    for (int row=1; row<=4; ++row)
    {
      cin >> a >> b >> c >> d;
      if (row == one)
      {
        keep.insert(a); keep.insert(b);
        keep.insert(c); keep.insert(d);
      }
    }
    cin >> two;
    for (int row=1; row<=4; ++row)
    {
      cin >> a >> b >> c >> d;
      if (row == two)
      {
        if (keep.find(a) != keep.end()) match = a, ++matches;
        if (keep.find(b) != keep.end()) match = b, ++matches;
        if (keep.find(c) != keep.end()) match = c, ++matches;
        if (keep.find(d) != keep.end()) match = d, ++matches;
      }
    }
    cout << "Case #" << tc << ": ";
    if (matches > 1)
      cout << "Bad magician!" << endl;
    else if (matches == 1)
      cout << match << endl;
    else
      cout << "Volunteer cheated!" << endl;
  }

  return 0;
}


