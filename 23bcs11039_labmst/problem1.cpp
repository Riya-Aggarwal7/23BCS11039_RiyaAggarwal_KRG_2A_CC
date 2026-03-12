#include<bits/stdc++.h>
using namespace std;
bool check(vector<int>nums,int maxop,int penalty){
    int op=0;
    for(int x:nums){
        op=op+(x-1)/penalty;
    }
    if(op<=maxop) return true;
    else
    return false;
}
int min_of_penalty(vector<int>nums,int maxop){
    int low=1;
    int high=*max_element(nums.begin(),nums.end());
    int answer=high;
    while(low<=high){
        int mid=(low+high)/2;
        if(check(nums,maxop,mid)){
            answer=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return answer;
}
int main(){
    int n, maxOperations;
    cout << "Enter number of bags: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter balls in each bag:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << "Enter max operations: ";
    cin >> maxOperations;
    int result = min_of_penalty(nums, maxOperations);
    cout << "Minimum Penalty: " << result << endl;
    return 0;
}
