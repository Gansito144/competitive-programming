#include <iostream>
#include <string>
#include <map>

using namespace std;

int main ()
{
  string n, d;
  map <string, int> D;
  cin >> n;

  for (int i=0; i<10; ++i)
  {
    cin >> d;
    D[d] = i;
  }
  while (n.size())
  {
    d = n.substr(0, 10);
    cout << D[d];
    n = n.substr(10);
  }
  cout << endl;
  return 0;
}
