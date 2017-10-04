#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph
{
  public:
    explicit Graph (int nodes = 0)
      : nodes (nodes)
    {
      edge_list.assign (nodes+1, vector<int> (0));
      degree.   assign (nodes+1, 0);
    }
    void addEdge (int nodeU, int nodeV)
    {
      edge_list[nodeU].push_back(nodeV);
      edge_list[nodeV].push_back(nodeU);
      ++degree[nodeU];
      ++degree[nodeV];
    }
    bool removeLeaves()
    {
      // cout << "Removing Leaves" << endl;
      bool ret = false;
      queue <int> leaves;
      for (int node=1; node<=nodes; ++node)
      {
        if(degree[node] == 1)
          leaves.push(node);
      }
      while(!leaves.empty())
      {
        ret = true;
        int node = leaves.front();
        leaves.pop();
        // cout << "Removing... " << node << endl;
        --degree[node];
        for (int &child : edge_list[node])
        {
          --degree[child];
        }
      }
      return ret;
    }
  private:
    int nodes;
    vector< vector<int> > edge_list;
    vector< int > degree;
};

int main ()
{
  int test_cases;
  scanf("%d",&test_cases);
  while(test_cases--)
  {
    int nodes, edges, nodeA, nodeB, ans=0;
    scanf("%d %d",&nodes,&edges);
    Graph graph(nodes);
    while(edges--)
    {
      scanf("%d %d",&nodeA,&nodeB);
      graph.addEdge(nodeA, nodeB);
    }
    while(graph.removeLeaves()) ++ans;
    printf("%d\n",ans);
  }
  return 0;
}

