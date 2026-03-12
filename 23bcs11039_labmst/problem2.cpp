#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxSum(vector<int>& nums, int k) {
        
        vector<long long> bitCount(32, 0);

        // Count set bits at each position
        for (int x : nums) {
            for (int b = 0; b < 32; b++) {
                if (x & (1 << b))
                    bitCount[b]++;
            }
        }

        long long ans = 0;

        for (int i = 0; i < k; i++) {
            
            long long val = 0;

            for (int b = 0; b < 32; b++) {
                if (bitCount[b] > 0) {
                    val |= (1LL << b);
                    bitCount[b]--;
                }
            }

            ans += val * val;
        }

        return ans;
    }
};

int main() {

    int n, k;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter k: ";
    cin >> k;

    Solution obj;
    long long result = obj.maxSum(nums, k);

    cout << "Maximum Sum of Squares = " << result << endl;

    return 0;
}
