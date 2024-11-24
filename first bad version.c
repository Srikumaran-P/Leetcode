// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    int lo = 1, hi = n, mid;
    while (lo <= hi) {
        mid = (lo%2+hi%2)/2+lo/2+hi/2;
        if (isBadVersion(mid)) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}
