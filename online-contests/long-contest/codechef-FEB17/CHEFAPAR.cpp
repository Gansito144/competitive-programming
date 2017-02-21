#include <stdio.h>

int main() {
    int T, n, ans, p, x;

    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        p = ans = 0;
        for(int i=1; i<=n; ++i) {
            scanf("%d",&x);
            p += x;
            if(p != i) ans += 100; 
        }
        ans += (n-p) * 1000;
        printf("%d\n",ans);
    }
    return 0;
}
