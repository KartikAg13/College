#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> prevsmaller(vector<int> v, int size) {
    stack<int> s;
    s.push(-1);
    vector<int> ans(size);
    for (int i = 0; i < size; i++) {
        while (v[s.top()] >= v[i]) {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> nextsmaller(vector<int> v, int size) {
    stack<int> s;
    s.push(size);
    vector<int> ans(size);
    for (int i = size - 1; i >= 0; i--) {
        while (v[s.top()] > v[i]) {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int largestarea(vector<int> v, int size) {
    int maxans = 0;
    vector<int> ps = prevsmaller(v, size);
    vector<int> ns = nextsmaller(v, size);
    for (int i = 0; i < size; i++) {
        int breadth = ns[i] - ps[i] - 1;
        int area = v[i] * breadth;
        maxans = max(maxans, area);
    }
    return maxans;
}

int main() {
    vector<int> v;
    v.push_back(4);
    v.push_back(2);
    v.push_back(1);
    v.push_back(5);
    v.push_back(6);
    v.push_back(3);
    v.push_back(2);
    v.push_back(4);
    v.push_back(2);
    int ans = largestarea(v, v.size());
    cout << endl << ans << endl;
    return 0;
}