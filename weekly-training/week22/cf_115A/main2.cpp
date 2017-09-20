#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

class Graph
{
public:
  // Members
  const int kNull = -1;
  int Nodes;
  vector < vector<int> > edgeList;
  vector <int> roots;
  // Constructor
  explicit Graph (int Nodes)
    : Nodes (Nodes)
  {
     edgeList.assign(Nodes, vector<int> (0));
  }
  // Add Edges
  void add_edge (int parent, int child)
  {
    if(parent == kNull) roots.push_back(child);
    else edgeList[parent-1].push_back(child);
  }
  // Get maximum level
  int get_max_depth()
  {
    queue < pair<int,int> > Queue;
    
    for( int &node : roots)
      Queue.push({ node, 1 });

    int maxDepth = 1;

    while(!Queue.empty()) {
      int node  = Queue.front().first;
      int level = Queue.front().second;
      //cout << node << " " << level << endl;
      Queue.pop();
      for(int & child : edgeList[node]) {
        Queue.push({ child, level+1 });
        maxDepth = max(maxDepth, level+1); 
      }
    }

    return maxDepth;
  }
};

int main() {
  int nodes, parent;
  scanf("%d",&nodes);
  Graph graph(nodes);
  for (int child=0; child<nodes; ++child)
  {
    scanf("%d",&parent);
    graph.add_edge(parent, child);
  }
  printf("%d\n",graph.get_max_depth()); 
  return 0;
}
