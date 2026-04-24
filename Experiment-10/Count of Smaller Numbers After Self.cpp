#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
    vector<int> tree;
    int size;

public:
    SegmentTree(int n) {
        size = n;
        tree.resize(4 * n, 0);
    }

    void update(int node, int start, int end, int idx) {
        if(start == end) {
            tree[node]++;
            return;
        }

        int mid = (start + end) / 2;

        if(idx <= mid)
            update(2 * node + 1, start, mid, idx);
        else
            update(2 * node + 2, mid + 1, end, idx);

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    int query(int node, int start, int end, int l, int r) {
        if(r < start || end < l)
            return 0;

        if(l <= start && end <= r)
            return tree[node];

        int mid = (start + end) / 2;

        return query(2 * node + 1, start, mid, l, r) +
               query(2 * node + 2, mid + 1, end, l, r);
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int offset = 10000;
        int maxVal = 20000;

        SegmentTree st(20001);
        int n = nums.size();
        vector<int> ans(n);

        for(int i = n - 1; i >= 0; i--) {
            int index = nums[i] + offset;

            if(index > 0)
                ans[i] = st.query(0, 0, maxVal, 0, index - 1);
            else
                ans[i] = 0;

            st.update(0, 0, maxVal, index);
        }

        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {5,2,6,1};

    vector<int> ans = obj.countSmaller(nums);

    for(int x : ans)
        cout << x << " ";

    return 0;
}
