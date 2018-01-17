#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ans;
vector <int> T[12345];
vector <int> src;
vector <int> tgt;

void dfs(int node, int pred)
{
  if (tgt[node] != src[pred])
    ++ans;
  src[node] = tgt[node];
  for (const int & son : T[node])
  {
    if (son != pred)
      dfs(son, node);
  }
}

int main ()
{
  int N;
  cin >> N;
  src.assign(N+1,  0);
  tgt.assign(N+1, -1);
  for (int parent=2; parent<=N; ++parent)
  {
    int son;
    cin >> son;
    T[son].push_back(parent);
    T[parent].push_back(son);
    //cout << "Linked: " << parent << " - " << son << endl;
  }
  for (int node=1; node<=N; ++node)
  {
    cin >> tgt[node];
  }
  dfs(1, 0);
  cout << ans << endl;
  return 0;
}

