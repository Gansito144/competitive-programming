#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int main ()
{
  int n, p, k;
  cin >> n >> p >> k;
  vector <string> ans;

  if (1 < (p-k))
    ans.push_back("<<");

  for (int x = max(p-k, 1); x <= min(n, p+k); ++x)
  {
    char tmp[20];
    if (x == p)
      sprintf(tmp,"(%d)",x);
    else
      sprintf(tmp,"%d",x);
    ans.push_back(tmp);
  }

  if(n > (p+k))
    ans.push_back(">>");

  for (const string & s : ans)
    cout << s << " ";
  cout << endl;
  return 0;
}


