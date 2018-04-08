#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;

  char nxt = 'a';
  int n = s.size();
  map <char, int> cnt;
  int i = 0;
  if (s[i] != 'a')
  {
    cout << "NO" << endl;
    return 0;
  }
  while (i<n && s[i] == 'a')
  {
    ++i;
    ++cnt['a'];
  }
  if (i==n || s[i] != 'b')
  {
    cout << "NO" << endl;
    return 0;
  }
  while (i<n && s[i]=='b')
  {
    ++i;
    ++cnt['b'];
  }
  if (i==n || s[i]!='c')
  {
    cout << "NO" << endl;
    return 0;
  }
  while (i<n && s[i]=='c')
  {
    ++i;
    ++cnt['c'];
  }
  if (i != n || (cnt['c']!=cnt['a']&&cnt['c']!=cnt['b']))
  {
    cout << "NO" << endl;
  }
  else 
  {
    cout << "YES" << endl;
  }
  return 0;
}

