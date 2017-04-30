/*
 * Problem: Uva 10054 - The Necklace
 */

#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

const int N = 51;

int g[N][N], d[N];

list< int > cyc;
list<int> ::iterator it;

void euler(list<int> ::iterator i, int u) {
    for(int v=0; v<N; ++v) if( g[u][v] > 0) {
        g[u][v]--;
        g[v][u]--;
        euler(cyc.insert(i, u), v);
    }
}

int main() {
    int n, u, v, T, r, ans;
    bool can;
    
    scanf("%d",&T);
    for(int b = 0; b<T; ++b)
    {
        scanf("%d",&n);
        memset(g, 0 , sizeof g);
        memset(d, 0 , sizeof d);
        r = N;
        for(int i=0; i<n; ++i) {
            scanf("%d %d",&u,&v);
            u--; v--;
            g[u][v]++;
            g[v][u]++;
            d[u]++;
            d[v]++;
            r = min(r, min(u,v));
        }
        can = true;

        for(int i=0; i<N; ++i) can = can && (d[i]%2==0);
        printf("%sCase #%d\n",(b?"\n":""),b+1);
        if( !can ) puts("some beads may be lost");
        else {
            cyc.clear();
            euler(cyc.begin(), r);
            int fr = *cyc.begin() + 1;
            for( it = cyc.begin(); it !=cyc.end();) {
                ans = *it + 1;
                printf("%d",ans);
                it++;
                if( it == cyc.end()) break;
                ans = *it + 1;
                printf(" %d\n",ans);
            }
            printf(" %d\n",fr);
        }
    }

    return 0;
}
