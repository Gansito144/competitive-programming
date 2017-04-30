/*
 * Problem: OmegaUp Acomoda el número
 */

#include <stdio.h>

int main() {
    int n, a0, x, cnt = 0;
    scanf("%d %d",&n,&a0);
    for(int i=1; i<n; ++i){
        scanf("%d",&x);
        cnt += (x < a0);
    }
    printf("%d\n",cnt);
    return 0;
}

