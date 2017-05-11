#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100001;

int A[N], L[N], R[N];

int main() {
    int n, m, k, l, r, h, ans;
    int lf, rg;

    // Read
    scanf("%d %d",&n,&m);
    for(int i=1; i<=n; ++i) {
        scanf("%d",&A[i]);
    } A[n+1] = -1;
    // Scan to left
    for(int i=1; i<=n; ++i) {
        L[i]=(A[i]==A[i-1])?L[i-1]+1:1;
    }
    // Scan to right
    for(int i=n; i>0; --i) {
        R[i]=(A[i]==A[i+1])?R[i+1]+1:1;
    }

    // Queries
    for(int i=0; i<m; i++) {
        scanf("%d %d %d",&l,&r,&k);
        ans = -1;
        h = (l+r) >> 1;
        lf = min(L[h], h-l+1);
        rg = min(R[h+1], r-h);
        if(lf >= k) ans = A[h];
        if(rg >= k) ans = A[h];
        if((A[h]==A[h+1]) && (lf+rg >= k)) ans = A[h];
        printf("%d\n",ans);

    }
    return 0;
}