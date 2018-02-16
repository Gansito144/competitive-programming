#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

class Graph {
  const int MAXN = 26;
  int num_scc;
  vector <int> scc;
  vector <int> active;
  vector < vector<int> > g, gt;
  stack<int> s;

public:

  Graph () {
    scc.assign(MAXN, -1);
    active.assign(MAXN, 0);
    g.assign (MAXN, vector<int> (0));
    gt.assign(MAXN, vector<int> (0));
  }

  void kosaraju () {
    num_scc = 0;
    fill(scc.begin(), scc.end(), -1);

    // First DFS construct stack
    for (int u=0; u<MAXN; ++u) {
      if (active[u] && scc[u] == -1) {
        DFS( g, u, true );
      }
    }
    // Second DFS build SCC's
    fill(scc.begin(), scc.end(), -1);
    while (!s.empty()) {
      if (scc[ s.top() ] == -1 ) {
        DFS( gt, s.top(), false );
        ++num_scc;
      }
      s.pop();
    }
  }
  
  // Create graph and its transpouse 
  void add_edge (int u, int v) {
    g[u].push_back(v);
    gt[v].push_back(u);
    active[u] = active[v] = true;
  }

  // Print in order 
  void print_sccs() {
    for (int u=0; u<MAXN; ++u) {
      if (active[u] && scc[u] != -1 ) {
        printf("%c",'A'+u);
        active[u] = 0;
        for (int v=u+1; v<MAXN; ++v) {
          if (active[v] && scc[v] == scc[u])
          {
            printf(" %c",'A'+v);
            active[v] = 0; 
          }
        }
        printf("\n");
      }
    }
  }

private:
  // DFS Util
  void DFS (vector <vector<int>> &G, int u, int flag) {
    scc[u] = num_scc;
    for (const int &v : G[u])
      if ( scc[v] == -1 )
        DFS( G, v, flag );
    if (flag)
      s.push(u);
  }
};

int main ()
{
  int n, b=0;
  while (scanf("%d\n",&n), n)
  {
    if (b++)
      printf("\n");
    Graph G;
    while (n--)
    {
      char a,b,c,d,e,f,op;
      scanf("%c %c %c %c %c %c\n",&a,&b,&c,&d,&e,&op);
      if (a != op)
        G.add_edge(op-'A', a-'A');
      if (b != op)
        G.add_edge(op-'A', b-'A');
      if (c != op)
        G.add_edge(op-'A', c-'A');
      if (d != op)
        G.add_edge(op-'A', d-'A');
      if (e != op)
        G.add_edge(op-'A', e-'A');
    }
    G.kosaraju();
    G.print_sccs();
  }
  return 0;
}

