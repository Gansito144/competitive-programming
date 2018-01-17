#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

int main ()
{
  string A = "ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv";
  string B = "our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up";

  const int sz = A.size();
  unordered_map <char, char> v;

  v['q'] = 'z';
  v['z'] = 'q';
  v['a'] = 'y';
  v['y'] = 'a';
  v['o'] = 'e';
  v['e'] = 'o';
  for (int i=0; i<sz; ++i)
  {
    v[A[i]] = B[i];
  }

  int cases;
  cin >> cases;
  cin.ignore();
  for (int tc=1; tc<=cases; ++tc)
  {
    string s;
    getline(cin, s);
    cout << "Case #" << tc << ": " ;
    for (const char &c : s) cout << v[c];
    cout << endl;
  }
  return 0;
}

