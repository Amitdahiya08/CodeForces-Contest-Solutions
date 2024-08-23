#include<bits/stdc++.h>
using namespace std;
// 
class fenwickTree {
public:
    vector<int> tree;

    // Constructor to initialize the tree with given size
    fenwickTree(int n) {
        tree.resize(n + 1, 0);
    }

    // Update function to add 'value' at index 'index'
    void update(int index, int value) {
        while (index < tree.size()) {
            tree[index] += value;
            index += index & -index;
        }
    }

    // Query function to get prefix sum up to and including index 'index'
    int query(int index)  {
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= index & -index;
        }
        return sum;
    }

    // Function to get the sum of elements in the range [left, right]
    int sumRange(int left, int right) {
        return query(right) - query(left - 1);
    }

    // Function to find the largest index with prefix sum less than 'k'
    int lower_bound(int k) {
        int curr = 0, prevSum = 0, ans = 0;
        for (int i = log2(tree.size()); i >= 0; i--) {
            if (curr + (1 << i) < tree.size() && tree[curr + (1 << i)] + prevSum < k) {
                curr = curr + (1 << i);
                prevSum += tree[curr];
            }
        }
        return curr + 1;
    }
};
