#include <iostream>
#include <vector>

using namespace std;

class FenwickTree {
private:
    vector<long long> tree;
    int size;

public:
    FenwickTree(int n) {
        size = n;
        tree.assign(n + 1, 0);
    }

    void update(int idx, long long delta) {
        for (; idx <= size; idx += idx & -idx) {
            tree[idx] += delta;
        }
    }

    void rangeUpdate(int left, int right, long long delta) {
        update(left, delta);
        update(right + 1, -delta);
    }

    long long query(int idx) {
        long long result = 0;
        for (; idx > 0; idx -= idx & -idx) {
            result += tree[idx];
        }
        return result;
    }

    long long rangeQuery(int left, int right) {
        return query(right) - query(left - 1);
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    FenwickTree fenwick(n);

    while (q--) {
        int left, right;
        cin >> left >> right;
        fenwick.rangeUpdate(left, right, 1);

        // Finding the maximum and minimum
        long long maxVal = fenwick.query(1);
        long long minVal = fenwick.query(1);

        cout << "Max Value: " << maxVal << " Min Value: " << minVal << endl;
    }

    return 0;
}

