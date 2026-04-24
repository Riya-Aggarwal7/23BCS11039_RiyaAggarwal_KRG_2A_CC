#include <iostream>
using namespace std;

class SegmentTree {
    int tree[1000];
    int arr[1000];
    int n;

public:
    SegmentTree(int input[], int size) {
        n = size;
        for(int i = 0; i < n; i++)
            arr[i] = input[i];

        build(0, 0, n - 1);
    }

    // Build tree
    void build(int node, int start, int end) {
        if(start == end) {
            tree[node] = arr[start];
            return;
        }

        int mid = (start + end) / 2;

        build(2 * node + 1, start, mid);
        build(2 * node + 2, mid + 1, end);

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    // Query sum in range [l, r]
    int query(int node, int start, int end, int l, int r) {
        if(r < start || end < l)
            return 0;

        if(l <= start && end <= r)
            return tree[node];

        int mid = (start + end) / 2;

        int leftSum = query(2 * node + 1, start, mid, l, r);
        int rightSum = query(2 * node + 2, mid + 1, end, l, r);

        return leftSum + rightSum;
    }

    // Update index idx with value val
    void update(int node, int start, int end, int idx, int val) {
        if(start == end) {
            arr[idx] = val;
            tree[node] = val;
            return;
        }

        int mid = (start + end) / 2;

        if(idx <= mid)
            update(2 * node + 1, start, mid, idx, val);
        else
            update(2 * node + 2, mid + 1, end, idx, val);

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    void displayQuery(int l, int r) {
        cout << "Sum = " << query(0, 0, n - 1, l, r) << endl;
    }

    void changeValue(int idx, int val) {
        update(0, 0, n - 1, idx, val);
    }
};

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = 6;

    SegmentTree st(arr, n);

    st.displayQuery(1, 3); // sum = 15

    st.changeValue(1, 10);

    st.displayQuery(1, 3); // sum = 22

    return 0;
}
