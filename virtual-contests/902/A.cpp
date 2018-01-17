#include <iostream>

using namespace std;

bool visited[123];

int main () 
{
  int n, m;
  cin >> n >> m;
  while (n--)
  {
    int a, b;
    cin >> a >> b;
    while (a < b)
    {
      visited[a] = true;
      a++;
    }
  }
  bool can = true;
  for (int i=0; i<m; ++i)
  {
    can = can && visited[i];
  }
  cout << (can ? "YES" : "NO") << endl;
  return 0;
}


