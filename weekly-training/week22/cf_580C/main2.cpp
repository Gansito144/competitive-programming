#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <deque>

using namespace std;

class Graph
{
public:
  // Constructor
  explicit Graph (int Nodes, int maxCats)
    : Nodes(Nodes)
    , leaves(0)
    , maxCats(maxCats)
  {
    hasCat.assign (Nodes+1, false);
    nodesList.assign(Nodes+1, vector<int>(0));
  }
  // Place a cat in node 
  void place_cat (int node)
  {
    hasCat[node] = true;
  }
  // Add edge
  void add_edge (int node_u, int node_v)
  {
    nodesList[node_u].push_back(node_v);
    nodesList[node_v].push_back(node_u);
  }
  // Get total safe Leaves
  int get_safe_leaves ()
  {
    hasSeen.assign(Nodes+1, false);
    leaves = 0;
    count_safe_leaves(1, (int)hasCat[1]);
    return leaves;
  }
private:
  int Nodes;
  int leaves;
  int maxCats;
  vector < bool > hasCat;
  vector < bool > hasSeen;
  vector < vector<int> > nodesList;
  void count_safe_leaves (int node, int cCats)
  {
    hasSeen[node] = true;
    bool isLeaf = true;
    for (int child : nodesList[node])
    {
      if(hasSeen[child]) continue;
      isLeaf = false;
      if(!hasCat[child])
        count_safe_leaves(child, 0);
      else
      {
        if(cCats+1 <= maxCats)
          count_safe_leaves(child, cCats+1);
      }
    }
    if(isLeaf && (cCats <= maxCats)) ++leaves;
  }
};

int main() {
  int Nodes, Cats, hasCat;

  scanf("%d %d",&Nodes,&Cats);
  Graph graph(Nodes, Cats);

  for (int node=1; node<=Nodes; ++node) 
  {
    scanf("%d",&hasCat);
    if (hasCat) graph.place_cat(node);
  }

  for (int i=1; i<Nodes; i++)
  {
    int u, v;
    scanf("%d %d",&u,&v);
    graph.add_edge(u,v);
  }
  
  printf("%d\n",graph.get_safe_leaves());
  
  return 0;
}
