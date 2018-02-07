#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <utility>
#include <map>

#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair < char , char > cc;
typedef pair < char ,  int > ci;

map < cc , ci > val;

void sieve(  )
{
	val[ mp( '1' , '1' ) ] = mp( '1', 1 ); val[ mp( '1' , 'i' ) ] = mp( 'i', 1 );
	val[ mp( '1' , 'j' ) ] = mp( 'j', 1 ); val[ mp( '1' , 'k' ) ] = mp( 'k', 1 );

	val[ mp( 'i' , '1' ) ] = mp( 'i', 1 ); val[ mp( 'i' , 'i' ) ] = mp( '1', -1 );
	val[ mp( 'i' , 'j' ) ] = mp( 'k', 1 ); val[ mp( 'i' , 'k' ) ] = mp( 'j', -1 );

	val[ mp( 'j' , '1' ) ] = mp( 'j', 1 ); val[ mp( 'j' , 'i' ) ] = mp( 'k', -1 );
	val[ mp( 'j' , 'j' ) ] = mp( '1',-1 ); val[ mp( 'j' , 'k' ) ] = mp( 'i', 1 );

	val[ mp( 'k' , '1' ) ] = mp( 'k', 1 ); val[ mp( 'k' , 'i' ) ] = mp( 'j', 1 );
	val[ mp( 'k' , 'j' ) ] = mp( 'i',-1 ); val[ mp( 'k' , 'k' ) ] = mp( '1', -1 );
}

int main()
{
	sieve();
	int cases , NoCase;
	int N , L  , X , ans , d , sgn;

	string S;
	ci  last , now ; 

	scanf("%d\n",&cases);
	for( NoCase = 1; NoCase <= cases; NoCase++ )
	{
		scanf("%d %d\n",&L , &X);
		ans = 0;
		N = L * X;
		cin >> S;
		last = mp( '1' , 1 );
		for( int i = 0; i < N; i++ )
		{
			now = val[ mp( last.F , S[ i % L ] ) ];
			now.S *= last.S; 
			last = now;
			if( ans == 0 && now == mp( 'i' , 1 ) ) ans++;
			if( ans == 1 && now == mp( 'k' , 1 ) ) ans++;
		}
		if( ans == 2 && last == mp( '1' , -1 ) ) ans++;
		printf("Case #%d: %s\n",NoCase,( ans == 3 ) ? "YES" : "NO" );
	}
	return 0;
}