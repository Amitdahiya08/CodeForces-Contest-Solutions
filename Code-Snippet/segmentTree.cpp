#include <vector>
#include <iostream>
using namespace std;

class SegmentTree {
public:
    vector<int> seg;
    int n;

    SegmentTree(int size) {
        n = size;
        seg.resize(4 * n); 
    }

    // Builds the segment tree
    // use build(nums,0,0,n-1) f
    void build(vector<int>& arr, int ind, int low, int high) {
        if (low == high) {
            seg[ind] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(arr, 2 * ind + 1, low, mid);
        build(arr, 2 * ind + 2, mid + 1, high);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    // Queries the sum in the range [l, r]
    // use search(0,0,n-1,l,r) for first time 
    int search(int ind, int low, int high, int l, int r) {
        if (l <= low && high <= r) return seg[ind];
        if (l > high || r < low) return 0;
        int mid = (low + high) / 2;
        int left = search(2 * ind + 1, low, mid, l, r);
        int right = search(2 * ind + 2, mid + 1, high, l, r);
        return left + right;
    }

    // Updates the value at index i in the input array to val
    // use  update(0,0,n-1,index,val) for first time
    void update(int ind, int low, int high, int i, int val) {
        if (low == high) {
            if (low == i) seg[ind] = val;
            return;
        }
        if (i < low || high < i) return;
        int mid = (low + high) / 2;
        update(2 * ind + 1, low, mid, i, val);
        update(2 * ind + 2, mid + 1, high, i, val);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
};