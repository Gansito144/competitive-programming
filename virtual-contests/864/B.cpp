#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

int main() 
{
  int n, ans = 0;
  unordered_set <char> low;
  string s;
  cin >> n >> s;
  for(char c : s)
  {
    if(c >= 'A' && c <= 'Z')
    {
      low.clear();
    }
    else
    {
      low.insert(c);
      ans = max(ans, (int) low.size());
    }
  }
  cout << ans << endl;
  return 0;
}


