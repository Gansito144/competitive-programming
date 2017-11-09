#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<memory.h>
#include<limits.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<utility>
#include<sstream>
#include<vector>
#include<bitset>
#include<queue>
#include<stack>
#include<set>
#include<map>

#define forit(i,v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define fori(i,a,b) for( int i = (int)(a); i < (int)(b); i++ )
#define forn(i,n) fori(i,0,n)
#define zeros(a) memset(a,0,sizeof(a))
#define null(a) memset(a,-1,sizeof(a))
#define all(a) (a).begin() , (a).end()
#define sqr(a) ((a)*(a))
#define sz(a) (a).size()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define N 100005
#define pii 2*acos(0.0)

#if ( WIN32 || __WIN32_ )
   #define lld I64d
#endif

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

typedef long long int i64;
typedef pair<int,int> ii;
typedef vector <int> vi;


int main()
{
    int a , b , c , d , p , q;
    
    cin >> a >> b >> c >> d;
    
    p = a * d;
    q = b * c;
    
    int g = __gcd( p , q );
    
    p /= g;
    q /= g;
    
    if( p > q ) swap( p , q );
    
    p = (q - p);
    
    cout << p << "/" << q << endl;
    
    return 0;
}

