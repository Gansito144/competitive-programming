#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

const int  MaxN  = 200002;
const int offset = 100000;

int arr[MaxN], pos[MaxN];
int fr [MaxN], ini[MaxN], fin[MaxN];

typedef struct intervalTree *ptrIntervalTree;

struct intervalTree {
  int D, L, R, bg;
  ptrIntervalTree izq, der;
  intervalTree() {}
  intervalTree(int L, int R):L(L), R(R) {
    izq = der = NULL;
    if(L == R) D = fr[L];
    else {
      int mid = (L+R)>>1;
      izq = new intervalTree(L, mid);
      der = new intervalTree(mid+1, R);
      D = max(izq->D, der->D);
    }
  }
  int query(int l, int r) {
    if(R<l || r<L) return 0;
    if(l<=L && R<=r) return D;
    return max(izq->query(l, r), der->query(l, r));
  }
  ~intervalTree() {
    delete izq;
    izq = NULL;
    delete der;
    der = NULL;
  }
};

ptrIntervalTree it;

int main() {
  int n, q, id, prv, l, r, ans, idL, idR;

  while(scanf("%d",&n), n) {
    scanf("%d",&q);
    prv = -(2e8);
    id  = 0;
    for(int i=1; i<=n; ++i) {
      scanf("%d",&arr[i]);
      arr[i] += offset;
      if(arr[i] != prv) {
        ++id;
        fr [ id ] = 0;
        ini[ id ] = i;
        fin[id-1] = i-1;
      }
      pos[arr[i]] = id;
      ++fr [ id ];
      prv = arr[i];
    }
    fin[id] = n;
    it = new intervalTree(1, id);
    while(q--) {
      scanf("%d %d",&l, &r);
      ans = 0;
      if(arr[l] == arr[r]) {
        ans = r-l+1;
      } else {
        idL = pos[arr[l]];
        idR = pos[arr[r]];
        ans = max(ans, fin[idL] - l + 1);
        ans = max(ans, r - ini[idR] + 1);
        ans = max(ans, it->query(idL+1, idR-1));
      }
      printf("%d\n",ans);
    }
    delete it;
  }
  return 0;
}

