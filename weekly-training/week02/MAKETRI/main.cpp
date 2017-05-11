#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int i64;
i64 x[2000002];

int main() {
    int N;
    i64 L, R, a, b, ans = 0LL, l, u;
    scanf("%d %lld %lld",&N,&L,&R);
    for(int i=0; i<N; ++i) {
        scanf("%lld",&x[i]);
    }
    sort(x, x+N);
    // b-a+1 < [L,R] < b+a-1
    for(int i=N-1; i>0; --i) {
        if(R < L) break;
        b = x[i];
        a = x[i-1];
        l = b - a + 1LL;
        u = b + a - 1LL;
        if(L > l) l = L;
        if(R < u) u = R;
        if(u < l) continue;
        ans += (u-l + 1LL);
        R = l-1LL;
    }
    printf("%lld\n",ans);
    return 0;
}