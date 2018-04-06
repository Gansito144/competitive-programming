#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main ()
{
  string s;
  int n;
  cin >> n >> s;
  vector <int> B;
  int cnt = 0;
  for (const char &si : s)
  {
    if (si == 'B')
    {
      ++cnt;
    }
    else
    {
      if (cnt) B.push_back(cnt);
      cnt = 0;
    }
  }
  if (cnt) B.push_back(cnt);
  cout << B.size() << endl;
  if (B.size())
  {
    for(const int &bi : B) cout << bi << " ";
    cout << endl;
  }
  return 0;
}


