#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <regex>

using namespace std;

int main ()
{
  int no_cases;
  cin >> no_cases;
  cin.ignore();

  for (int test_case = 1; test_case <= no_cases; ++test_case)
  {
    int no_engines;
    cin >> no_engines;
    cin.ignore();

    vector <string> engines (no_engines);
    for (string &engine : engines)
    {
      getline(cin, engine);
    }

    int queries;
    cin >> queries;
    cin.ignore();

    unordered_set < string > seen;
    string word_search;

    int ans = 0;
    while (queries--) 
    {
      getline(cin, word_search);
      seen.insert(word_search);
      if(seen.size() == no_engines)
      {
        ++ans;
        seen.clear();
        seen.insert(word_search);
      }
    }
    
    cout << "Case #" << test_case << ": " << ans << endl;
  }
  return 0;
}



