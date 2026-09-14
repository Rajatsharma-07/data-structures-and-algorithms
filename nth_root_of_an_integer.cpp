int nthRoot (int n, int m) {
    int low = 1;
    int high = m;
    while(low <= high) {
        int mid = (low + high) / 2;
        int ans = 1;
        for(int i = 0; i < n; i++) {
            ans *= mid;
            if (ans > m) {
                break;
            }
        }

        if (ans == m) return midl
        else if (ans < m) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}