#include <bits/stdc++.h>
using namespace std;

void sorting_based_approach() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    // clubs all the unique elements on left side,
    // return iterator pointing to one past the last element
    auto pos = unique(v.begin(), v.end());
    cout << pos - v.begin() << "\n";
}// * T: O(n*log(n)), S: O(1)

int main() {
    int n;
    cin >> n;
    set<int> st;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        st.insert(x);
    }
    cout << st.size() << "\n";
}  //* T: O(n*log(n)), Space: O(n)