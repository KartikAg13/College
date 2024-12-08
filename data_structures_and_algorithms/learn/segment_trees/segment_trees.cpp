#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class SegmentTree {
private:
    vector<int> tree; // Segment Tree storage
    vector<int> arr;  // Input array
    int n;            // Size of the array

    // Helper function to calculate the middle index
    int mid(int l, int r) { 
        return l + (r - l) / 2; 
    }

    // Build the Segment Tree
    void build(int node, int start, int end) {
        if (start == end) { // Leaf node
            tree[node] = arr[start];
        } 
        else {
            int m = mid(start, end);
            build(2 * node + 1, start, m); // Left child
            build(2 * node + 2, m + 1, end); // Right child
            tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    // Update the Segment Tree
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) { // Leaf node
            arr[idx] = val;
            tree[node] = val;
        } 
        else {
            int m = mid(start, end);
            if (idx <= m) { // Update in the left subtree
                update(2 * node + 1, start, m, idx, val);
            } 
            else { // Update in the right subtree
                update(2 * node + 2, m + 1, end, idx, val);
            }
            tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    // Query the minimum value in a range
    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) { // Out of range
            return INT_MAX;
        }
        if (l <= start && end <= r) { // Fully within range
            return tree[node];
        }
        int m = mid(start, end);
        int left_min = query(2 * node + 1, start, m, l, r);
        int right_min = query(2 * node + 2, m + 1, end, l, r);
        return min(left_min, right_min);
    }

public:
    // Constructor
    SegmentTree(const vector<int>& a) : arr(a), n(a.size()) {
        tree.resize(4 * n);
        build(0, 0, n - 1);
    }

    // Update the value at a specific index
    void update(int idx, int val) {
        update(0, 0, n - 1, idx, val);
    }

    // Query the minimum value in a range
    int query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};

int main() {
    // Input array
    vector<int> arr = {1, 3, 2, 7, 9, 11};

    // Create the Segment Tree
    SegmentTree st(arr);

    // Perform some queries
    cout << "Minimum in range [1, 4]: " << st.query(1, 4) << endl;
    cout << "Minimum in range [0, 5]: " << st.query(0, 5) << endl;

    // Update an element
    st.update(2, 1);
    cout << "After updating index 2 to 1:" << endl;
    cout << "Minimum in range [1, 4]: " << st.query(1, 4) << endl;
    cout << "Minimum in range [0, 5]: " << st.query(0, 5) << endl;

    return 0;
}
