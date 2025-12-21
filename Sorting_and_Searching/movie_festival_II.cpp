#include <bits/stdc++.h>

using namespace std;

#define nl '\n'
#define ll long long
#define vii vector<pair<int, int>>
#define len(x) int(x.size())

void solve() {
    int n, k;
    cin >> n >> k;

    vii intervals;
    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        // - store end_time first
        intervals.push_back({end, start});
    }

    //> sort by end time
    sort(intervals.begin(), intervals.end());

    int total = 1;
    multiset<int> ets;
    ets.insert(intervals[0].first);

    for (int i = 1; i < n; i++) {
        auto [cur_et, cur_st] = intervals[i];

        //? find smallest end_time greater than cur_st
        auto it = ets.upper_bound(cur_st);
        if (it == ets.begin()) {
            //- all are greater; try to assign a new member
            if (ets.size() < k) {
                ets.insert(cur_et);
                total++;
            }
        } else {
            //- remove largest end time <= cur_st
            it--;
            ets.erase(it);
            //> add cur_et
            ets.insert(cur_et);
            total++;
        }
    }
    cout << total << nl;
}  //* T: O(n*logn), S:O(n)

int main() {
    int t = 1;
    // cin>>t;

    while (t--)
        solve();
}