#include <stdio.h>
#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

#define mp make_pair
#define pb push_back
#define F first
#define S second

using namespace std;

typedef pair<int,int> ii;

const int kMaxN = 1000006;
const int kMaxM = 200005;

int L[kMaxN], R[kMaxN], da, db;
vector <ii> edges;

bool cmp(ii &a, ii &b) {
  da = (a.S - a.F);
  db = (b.S - b.F);
  if(da == db) return a.F < b.F;
  return da < db;
}

int main() {
  int N, M, u, v;

  scanf("%d %d",&N, &M);
  // Initialize
  for(int i=0; i<N; ++i) {
    L[i] = R[i] = i;
  }
  // Read input
  for(int i=0; i<M; ++i) {
    scanf("%d %d",&u,&v);
    if(u>v) swap(u, v);
    edges.pb(mp(u,v));
  }
  
  // Process 
  sort(edges.begin(), edges.end(), cmp);
  for(int i=0; i<edges.size(); ++i) {
    u = edges[i].F;
    v = edges[i].S;
    // printf("-- Edge(u:%d, v:%d) -- \n",u,v);
    // printf("U:%d L:%d R:%d\n",u,L[u],R[u]);
    // printf("V:%d L:%d R:%d\n",v,L[v],R[v]);
    if(R[u]+1 == v) R[u] = v;
    if(L[v]-1 == u) L[v] = u;
    // printf("U:%d L:%d R:%d\n",u,L[u],R[u]);
    // printf("V:%d L:%d R:%d\n",v,L[v],R[v]);
  }

  int ans = 0;
  // Adjustment
  for(int i=1, j=N-2; i<N; ++i, --j) {
    L[i] = max(L[i], L[i-1]);
    R[j] = min(R[j], R[j+1]);
  }
  // Calculate answer
  int upb, lob;
  for(int node=0; node<N; ++node) {
    upb = min(R[node], R[L[node]]);
    lob = max(L[node], L[R[node]]);
    ans = max(ans, upb-lob+1);
  }
  printf("%d\n",ans);
  return 0;
}

