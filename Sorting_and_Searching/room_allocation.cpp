#include <bits/stdc++.h>

using namespace std;

#define nl '\n'
#define sp ' '
#define ll long long
#define triplet tuple<int, int, int>
#define pii pair<int, int>
#define vi vector<int>
#define len(x) int(x.size())

void solve() {
    int n;
    cin >> n;

    vector<triplet> intervals;
    for (int i = 0; i < n; i++) {
        int st, et;
        cin >> st >> et;
        intervals.push_back({st, et, i});
    }

    sort(intervals.begin(), intervals.end());

    auto [st, et, idx] = intervals[0];
    vi assigned_room_no(n);
    multiset<pii> et_rid;

    // > assign a room no. 1 to earliest arriving customer
    assigned_room_no[idx] = 1;
    et_rid.emplace(et, 1);//insert({et,1})

    for (int i = 1; i < n; i++) {
        auto [st, et, idx] = intervals[i];

        //> find the smallest end_time among allocated rooms
        auto [smallest_et, rid] = *begin(et_rid);
        if (smallest_et < st) {
            et_rid.erase(et_rid.begin());
            assigned_room_no[idx] = rid;
            et_rid.emplace(et, rid);

        } else {
            //- all end_times are greater than equal to current_start
            //> allocate new room
            assigned_room_no[idx] = len(et_rid) + 1;
            et_rid.emplace(et, assigned_room_no[idx]);
        }
    }
    cout << *max_element(assigned_room_no.begin(), assigned_room_no.end()) << nl;
    for (auto room : assigned_room_no)
        cout << room << sp;
}  //* T:O(n*logn), S:O(n)

int main() {
    int t = 1;
    // cin>>t;

    while (t--)
        solve();
}