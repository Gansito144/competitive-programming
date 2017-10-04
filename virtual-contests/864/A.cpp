#include <iostream>
#include <unordered_map>
#include <utility>

using namespace std;

int main() 
{
  int n, petya = 0, vasya = 0, sP = 0, sV = 0;
  unordered_map<int,int> fr;

  cin >> n;
  for (int i=0; i<n; ++i)
  {
    int x;
    cin >> x;
    ++fr[x];
  }
  if(fr.size() == 2 && fr.begin()->second == n/2)
  {
    cout << "YES" << endl;
    auto it = fr.begin();
    cout << it->first << " ";
    ++it;
    cout << it->first << endl;
  } 
  else
  {
    cout << "NO" << endl;
  }
  return 0;
}

