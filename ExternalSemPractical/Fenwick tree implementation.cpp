#include<bits/stdc++.h>
using namespace std;
class FenwickTree{
    vector<int>bit;
    int n;
    public:
    FenwickTree(int size){
        n=size;
        bit.assign(n+1,0);
    }
    void update(int i,int val){
        while(i<=n){
            bit[i]+=val;
            i+= (i & -i);
        }
    }
     int query(int i) {
        int sum = 0;
        while (i > 0) {
            sum += bit[i];
            i -= (i & -i);
        }
        return sum;
    }
    int rangeSum(int l, int r) {
        return query(r) - query(l - 1);
    }
};
int main() {
    int n = 5;
    FenwickTree ft(n);

    ft.update(1, 5);
    ft.update(2, 3);
    ft.update(4, 7);

    cout << "Sum(1,2) = " << ft.rangeSum(1,2) << endl;
    cout << "Sum(1,5) = " << ft.rangeSum(1,5) << endl;

    return 0;
}
