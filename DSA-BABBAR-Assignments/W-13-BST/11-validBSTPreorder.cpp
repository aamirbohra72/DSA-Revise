//interview Bit 


void build(int* i, int min, int max, int* A, int n) {
    if (*i >= n)
        return;

    if (A[*i] > min && A[*i] < max) {
        int rootData = A[(*i)++];
        build(i, min, rootData, A, n);
        build(i, rootData, max, A, n);
    }
}

int solve(int* A, int n) {
    int min = INT_MIN, max = INT_MAX;
    int i = 0;
    build(&i, min, max, A, n);
    return i == n;
}
