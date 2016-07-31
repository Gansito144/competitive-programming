#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>

#define N 1000006
#define bit_test(x,b) (((x)>>(b))&1)
#define bit_on(x,b)  ( (x) |   (1<<(b))  )
#define bit_off(x,b) ( (x) & (~(1<<(b))) )

using namespace std;

char A[N], B[N], C[N];

// Fill with 0's the missing spaces
inline void align(char *s, int n, int t){
    for(; n>=0; --n, --t ) {
        if(t >= 0) s[n] = s[t];
        else s[n] = '0';
    }
}

inline int getDec(char c){
    if(c>='0' && c<='9') return c-'0';
    return c-'A'+10;
}

inline void print(char *s, int n) {
    int i=0;
    for(; i<n && s[i]=='0'; ++i);
    for(; i<=n; ++i) putchar(s[i]);
    putchar('\n');
}

int main() {
    int q, k, szA, szB, szC, sz;
    int va, vb, vc;
    char hex[] = "0123456789ABCDEF";
    // Casos de prueba
    scanf("%d\n",&q);
    while(q--) {
        bool ans = true;
        // bits a modificar
        scanf("%d\n",&k);
        scanf("%s",A);
        scanf("%s",B);
        scanf("%s",C);
        // Get string sizes & global
        szA = strlen(A);
        szB = strlen(B);
        szC = strlen(C);
        sz = max(szA, max(szB, szC));
        // Align strings to the global
        align(A, sz-1, szA-1);
        align(B, sz-1, szB-1);
        align(C, sz-1, szC-1);
        // There are change that must be done 
        // 1 when 1 is in C but not in A nor B
        // 2 when 0 is in C but A or B has 1's
        for(int i=0; i<sz && ans ; ++i) {
            // Process each nibble
            va = getDec(A[i]);
            vb = getDec(B[i]);
            vc = getDec(C[i]);
            for(int b=3; b>=0; --b) {
                // k-bit in Ci is set
                if(bit_test(vc, b)) {
                    if(bit_test(vb, b) || bit_test(va, b))
                        continue;
                    if(k <= 0) {
                        ans=false;
                        break;
                    }
                    --k;
                    vb = bit_on(vb, b);
                } else {
                    // We need to turn off bits in a and b
                    if(bit_test(va, b)) {
                       if(k <= 0) {
                           ans=false;
                           break;
                       }
                       --k;
                       va = bit_off(va, b);
                    }
                    if(bit_test(vb, b)) {
                       if(k <= 0) {
                           ans=false;
                           break;
                       }
                       --k;
                       vb = bit_off(vb, b);
                    }
                }
            }
            A[i] = hex[va];
            B[i] = hex[vb];
        }
        if(ans) {
            // But we can improve A'
            for(int i=0; i<sz && k>0 ; ++i) {
                va = getDec(A[i]);
                vb = getDec(B[i]);
                for(int b=3; b>=0 && k>0; --b) {
                    if( bit_test(va, b) && bit_test(vb, b)) {
                        va = bit_off(va,b);
                        k--;
                        continue;
                    }
                    if( bit_test(va, b) && !bit_test(vb, b) && k > 1) {
                        va = bit_off(va,b);
                        vb = bit_on(vb,b);
                        k -= 2;
                    }
                }
                A[i] = hex[va];
                B[i] = hex[vb];
            }
            print(A, sz-1);
            print(B, sz-1);
        } else puts("-1");
    }
    return 0;
}

