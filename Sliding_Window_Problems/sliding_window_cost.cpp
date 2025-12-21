#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define len(x) int(x.size())

void solve() {
    int n, k;
    cin >> n >> k;

    vector<ll> arr(n);
    for (auto& a : arr) cin >> a;

    multiset<ll> left, right;
    ll ls = 0, rs = 0;

    //> ensure right set's length is either exactly equal to left or just one more
    auto rebalance = [&] {
        if (len(left) > len(right)) {
            ll v = *rbegin(left);
            ls -= v;
            rs += v;
            left.erase(left.find(v));
            right.insert(v);
        }

        if (len(right) > len(left) + 1) {
            ll v = *begin(right);
            rs -= v;
            ls += v;

            right.erase(right.find(v));
            left.insert(v);
        }
    };

    //> add a value to appropriate set (>= right's first in right else in left)
    auto add = [&](ll v) {
        if (!right.empty() && v >= *begin(right)) {
            rs += v;
            right.insert(v);
        } else {
            ls += v;
            left.insert(v);
        }
        rebalance();
    };

    //> remove a value from appropriate set (>= right's first in right else from left)
    auto rem = [&](ll v) {
        if (v >= *begin(right)) {
            rs -= v;
            right.erase(right.find(v));
        } else {
            ls -= v;
            left.erase(left.find(v));
        }

        rebalance();
    };

    //> cost of current window
    auto cost = [&] {
        ll med = *begin(right);
        return len(left) * med - ls + rs - len(right) * med;
    };

    //> slide and compute answers
    int i = 0;
    for (int j = 0; j < n; j++) {
        //> element enters
        add(arr[j]);

        if (j - i + 1 < k) continue;

        cout << cost() << ' ';

        //> element leaves
        rem(arr[i]);
        i++;
    }
}  //* T:O(n*logk), S:O(k)

int main() {
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
}
