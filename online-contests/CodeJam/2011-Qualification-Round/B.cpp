#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <queue>
#include <map>

using namespace std;

int main ()
{
  int cases;
  const unordered_set <char> base = {'Q','W','E','R','A','S','D','F'};
  cin >> cases;
  for (int tc=1; tc<=cases; ++tc)
  {
    int C;
    string e;
    map < pair<char, char>, char> com;
    cin >> C;
    while ( C-- )
    {
      cin >> e;
      com[{e[0], e[1]}] = e[2];
      com[{e[1], e[0]}] = e[2];
    }
    unordered_map <char, unordered_set<char> > op;
    cin >> C;
    while ( C-- )
    {
      cin >> e;
      op[e[0]].insert(e[1]);
      op[e[1]].insert(e[0]);
    }
    unordered_map <char, int> cnt;
    string ans;
    cin >> C;
    cin >> e;
    for (const char &c : e)
    {
      if ( ans.size() )
      {
        char &lst = ans.back();
        char rp = com[{lst, c}];
        if ( rp )
        {
          --cnt[lst];
          lst = rp;
          ++cnt[lst];
          continue;
        }
        else
        {
          bool ops = false;
          for (auto &cc : op[c])
          {
            if (cnt[cc])
            {
              ans = "";
              cnt.clear();
              ops = true;
              break;
            }
          }
          if (ops) continue;
        }
      }
      if (base.find(c) != base.end())
      {
        ++cnt[c];
        ans += c;
      }
    }
    cout<< "Case #"<< tc<< ": [";
    for (int i=0; i<ans.size(); ++i)
    {
      if( i ) cout << ", ";
      cout << ans[i];
    }
    cout << "]" << endl;
  }
  return 0;
}

