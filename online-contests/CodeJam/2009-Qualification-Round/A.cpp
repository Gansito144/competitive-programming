#include <iostream>
#include <string>
#include <algorithm>
#include <regex>
#include <vector>

using namespace std;

int main ()
{
  int len, words, cases;
  cin >> len >> words >> cases;

  vector <string> dict (words);
  for (string & word : dict)
    cin >> word;

  for(int tc=1; tc<=cases; ++tc)
  {
    string reg;
    cin >> reg;
    replace(reg.begin(), reg.end(), '(', '[');
    replace(reg.begin(), reg.end(), ')', ']');
    const regex r (reg);
    int ans = 0;
    for(const string &word : dict)
      ans += regex_match(word, r);
    cout << "Case #" << tc << ": " << ans << endl;
  } 
  return 0;
}

