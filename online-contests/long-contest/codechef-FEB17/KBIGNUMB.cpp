#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

typedef long long int i64;

int digits(i64 n) {
	int r = 0;
	while(n) n /= 10LL, ++r;
	return r;
}

i64 mul(i64 &a, i64 b, i64 &m) {
	i64 r = 0LL;
	while(b) {
		if(b & 1LL) {
			r += a;
			if(r >= m) r -= m;
		}
		b >>= 1;
		a <<= 1;
		if(a >= m) a -= m;
	}
	return r;
}

i64 pot(i64 &a, i64 b, i64 m) {
	i64 r = 1LL;
	while(b) {
		if(b & 1LL) {
			r = mul(r, a, m);
		}
		b >>= 1;
		a = mul(a, a, m);
	}
	return r;
}

int main() {
	int T, e;
	i64 A, N, M, p, q, r, mod, ten[12];

	// Precompute 10^k
	ten[0] = 1LL;
	for(int k=1; k<12; ++k) ten[k] = ten[k-1]*10LL;

	scanf("%d",&T);
	while(T--){
		scanf("%lld %lld %lld",&A, &N, &M);
		if(A == 0) puts("0");
		else {
			e = digits(A);
			r = ten[e];
			q = r - 1LL;
			mod = M * q;
			r %= mod;
			p = pot(r, N, mod);
			p = (p-1LL+mod) % mod;
			p /= q;
			mod = ((A%M) * p)%M;
			printf("%lld\n",mod);
		}
	}
	return 0;
}