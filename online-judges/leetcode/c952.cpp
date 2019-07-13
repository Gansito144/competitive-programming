class Solution {
public:
    // Find
    int find(int x, vector<int> &p) {
        if (x != p[x]) {
            p[x] = find(p[x], p);
        }
        return p[x];
    }
    int largestComponentSize(vector<int>& A) {
        // Eratosthenes Sieve
        const int MAX_ROOT = 318; // sqrt(10^5)
        bitset <MAX_ROOT> is_prime;
        vector <int> primes;
        is_prime.set();
        for (int candidate=2; candidate<MAX_ROOT; ++candidate) {
            if (is_prime.test(candidate)) {
                primes.push_back(candidate);
                for (int no_prime = candidate<<1; no_prime<MAX_ROOT; no_prime+=candidate)
                    is_prime.reset(no_prime);
            }
        }
        // Create the components by primes.
        int x, y, last;
        map <int, vector<int>> presence;
        for (int i=0; i<A.size(); ++i) {
            // reduce with each prime
            for (const int &p : primes) {
                if (p > A[i] || A[i] == 1) break;
                if (A[i] % p) continue;
                while (A[i] % p == 0) A[i] /= p;
                presence[p].push_back(i);
            }
            // Prime itself
            if (A[i] > 1) {
                presence[A[i]].push_back(i);
            }
        }
        // Union Find
        vector <int> id(A.size());
        vector <int> rk(A.size());
        // Init
        for (int n=0; n<A.size(); ++n) id[n] = n;
        
        // Join the numbers in each prime.
        for (const auto &factors : presence) {
            const vector <int> &f = factors.second;
            for (int i=1; i<f.size(); ++i) {
                x = find(f[i], id);
                y = find(f[i-1], id);
                if (rk[x] > rk[y])
                    id[y] = id[x];
                else {
                    id[x] = id[y];
                    if (rk[x] == rk[y]) ++rk[y];
                }
            }
        }
        
        // Count the components
        vector <int> cnt(A.size());
        int mx = 0;
        for (int i=0; i<A.size(); ++i) find(i, id); 
        for (const int &p : id) {
            ++cnt[p];
            if (cnt[p] > mx) {
                mx = cnt[p];
            }
        }
        return mx;
    }
};
