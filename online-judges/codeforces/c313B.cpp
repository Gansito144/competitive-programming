#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>

#define N 100005

using namespace std;

char s[N];
int sa[N];

int main(){
    int t;
    
    gets( s );
    t = strlen( s );
    for(int i=0; i<t; ++i) {
        if(s[i] == s[i+1]) sa[i+1]=1;
        sa[i+1] += sa[i];
    }
    
    int l , u , q;
    scanf("%d",&q);
    while( q-- )
    {   
        scanf("%d",&l);
        scanf("%d",&u);
        cout << sa[u-1] - sa[l-1] << endl;
    }
    return 0;
}