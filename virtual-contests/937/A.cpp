#include <iostream>
#include <set>

using namespace std;

int main ()
{
  int n, sc;
  set <int> s;
  cin >> n;
  while (n--)
  {
    cin >> sc;
    if (sc)
      s.insert(sc);
  }
  cout << s.size() << endl;
  return 0;
}

