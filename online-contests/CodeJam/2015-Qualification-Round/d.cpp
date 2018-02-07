#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int cases , NoCase;
	int X , R , C , L;
	string ans;
	scanf("%d\n",&cases);
	for( NoCase = 1; NoCase <= cases; NoCase++ )
	{
		scanf("%d %d %d",&X,&R,&C);
		L = ( R * C ) - X;
		if( (L < 0) || ( (L % X) != 0 ) ) ans = "RICHARD";
		else
		{
			if( R > C ) swap( R , C );
			if( (R + 1) < X ) ans = "RICHARD";
			else
			{
				ans = "GABRIEL";
			}
		}
		printf("Case #%d: %s\n",NoCase,ans.c_str());
	}
	return 0;
}