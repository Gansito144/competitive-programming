#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main () 
{
  int cnt = 0;
  string s;
  cin >> s;
  unordered_map <char, int> fr;
  for( const char c : s)
  {
    if(c == 'Q')
      cnt += fr['A'];
    if(c == 'A')
      fr[c] += fr['Q'];
    else
      ++fr[c];
  }
  cout << cnt << endl;
  return 0;
}

