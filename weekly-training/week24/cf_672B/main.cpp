#include <iostream>
#include <set>

using namespace std;

int main ()
{
  int n;
  string w;
  set <char> s;
  cin >> n;
  if(n > 26)
  {
    cout << -1 << endl;
    return 0;
  }
  cin >> w;
  for(const char &c : w) s.insert(c);
  cout << (n - s.size()) << endl; 
  return 0;
}

