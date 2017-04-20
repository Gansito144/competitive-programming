long long coolSubsets(std::vector<int> a) {
    long long ans = 0LL;
    int maximum = -1, nz = 0;
    for(int i=0; i<a.size(); ++i) {
        if(a[i] > maximum) maximum = a[i], ans = 0LL;
        if(a[i] == maximum) ++ans;
    }
    return (maximum != 0) ? ans : (1LL<<ans) - 1LL;
}
