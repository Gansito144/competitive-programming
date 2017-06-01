#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> VI;
typedef long long int i64;

/* Fenwick Tree update function */
void update(VI &BIT, int idx, int val) {
  while(idx < BIT.size()) {
    BIT[idx] += val;
    idx += (idx & -idx);
  }
}

/* Fenwick Tree read function */
int read(VI &BIT, int idx) {
  int ret = 0;
  while(idx > 0) {
    ret += BIT[idx];
    idx -= (idx & -idx);
  }
  return ret;
}

i64 dfs(int node, int &dist, vector<VI> &Tree, VI &BIT) {
  i64 ret = read(BIT, node);
  int left  = max(1, node-dist);
  int right = min((int)BIT.size()-1, node+dist);
  // Add to BIT
  update(BIT,    left, +1);
  update(BIT, right+1, -1);
  // recursively calculate the solution
  for(int idx=0; idx<Tree[node].size(); ++idx) {
    int child = Tree[node][idx];
    ret += dfs(child, dist, Tree, BIT);
  }
  // Remove from BIT
  update(BIT,    left, -1);
  update(BIT, right+1, +1);
  return ret;
}

int main() {
  int nodes, dist, root;
    
  scanf("%d %d",&nodes,&dist);
  ++nodes;                  // to avoid problems with 0-index
  VI inDegree(nodes+1, 0);  // to find the root of our tree
  vector<VI> Tree(nodes+1); // Our little happy tree 
  VI BIT(nodes+1, 0);       // Fenwick Tree (FTW)
  // Construct the tree
  for(int edge=2; edge<nodes; ++edge) {
    int parent, child;
    scanf("%d %d",&parent,&child);
    Tree[parent].push_back(child);
    inDegree[child]++;
  }
  i64 ans = 0LL;
  // Find root of the tree
  for(int node=1; node <= nodes; ++node) {
    if(inDegree[node] == 0) {
      root = node;
      break;
    }
  }
  ans = dfs(root, dist, Tree, BIT);
  printf("%lld\n",ans);
  return 0;
}
