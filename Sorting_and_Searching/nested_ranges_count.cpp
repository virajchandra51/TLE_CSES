#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define len(x) int((x).size())
using namespace std;
using namespace __gnu_pbds;

// find_by_order, order_of_key: 0 indexed
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// allows duplicate values
template <class T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct Interval {
    int start;
    int end;
    int original_index;  // To track original position after sorting

    Interval(int s, int e, int idx) : start(s), end(e), original_index(idx) {}
};

/**
 * Custom comparator for sorting intervals
 * Sort by start time ascending, then by end time descending
 * This ensures that if two intervals start at the same point,
 * the longer one comes first (making containment checking easier)
 */
bool compareIntervals(const Interval& a, const Interval& b) {
    if (a.start == b.start) {
        return a.end > b.end;  // Longer intervals first when starts are equal
    }
    return a.start < b.start;  // Earlier start times first
}

void solve() {
    int n;
    cin >> n;

    // Read all intervals and store with their original indices
    vector<Interval> intervals;
    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        intervals.emplace_back(start, end, i);
    }

    // Sort intervals for efficient containment checking
    sort(intervals.begin(), intervals.end(), compareIntervals);

    // Arrays to store results (indexed by original position)
    vector<int> is_contained_by_another(n, 0);  // this interval inside how many
    vector<int> contains_another(n, 0);         // this interval contain how many

    /** This interval inside how many ?
     * Strategy: For each interval,
     * - check how many previous interval (with smaller or equal start)
     * - has an end point that covers this interval's end point
     */
    ordered_multiset<int> ets;
    for (int i = 0; i < n; i++) {
        const auto& current = intervals[i];

        // index of the first end_time in [0,...,i-1] whose end_time == cur.end_time
        int lb = ets.order_of_key(current.end);
        //> all intervals in our set, from 'lb' index till len(ets) till contain 'current'
        is_contained_by_another[current.original_index] = len(ets) - lb;
        ets.insert(current.end);
    }

    /** each interval contains how many in it?
     * Strategy: Process intervals from right to left (reverse order)
     * For each interval, check how many interval to its right has
     * - start >= current.start (guaranteed by sorting)
     * - end <= current.end
     */
    ets.clear();
    for (int i = n - 1; i >= 0; i--) {
        const auto& current = intervals[i];

        // index of current.end_time + 1 in [i+1,...n-1] if it exists Or would have existed
        int ub = ets.order_of_key(current.end + 1);
        //> all intervals in our set, from [0...ub) are contained by current
        contains_another[current.original_index] = ub;
        ets.insert(current.end);
    }

    // First line: How many interval(s) does this  interval contain ?
    for (int i = 0; i < n; i++) {
        cout << contains_another[i];
        if (i < n - 1) cout << " ";
    }
    cout << "\n";

    // Second line: this interval is contained by how many other?
    for (int i = 0; i < n; i++) {
        cout << is_contained_by_another[i];
        if (i < n - 1) cout << " ";
    }
    cout << "\n";
}  //* T:O(n*logn), S: O(n)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}