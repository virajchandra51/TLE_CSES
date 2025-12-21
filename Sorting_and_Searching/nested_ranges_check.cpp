#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem: Interval Containment Checker
 *
 * Given n intervals, determine for each interval:
 * 1. Does it contain at least one other interval? (parent check)
 * 2. Is it contained within at least one other interval? (child check)
 *
 * Interval [a,b] contains interval [c,d] if a <= c and d <= b
 */

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
    vector<int> is_contained_by_another(n, 0);  // Is this interval inside another?
    vector<int> contains_another(n, 0);         // Does this interval contain another?

    /**
     * Check if each interval is contained by another
     * Strategy: For each interval, 
     * - check if any previous interval (with smaller or equal start)
     * - has an end point that covers this interval's end point
     */
    int max_end_so_far = INT_MIN;
    for (int i = 0; i < n; i++) {
        const auto& current = intervals[i];

        // If we've seen an interval that ends at or after current's end,
        // and it must have started before or at current's start (due to sorting),
        // then current is contained by that interval
        if (max_end_so_far != INT_MIN && max_end_so_far >= current.end) {
            is_contained_by_another[current.original_index] = 1;
        }

        max_end_so_far = max(max_end_so_far, current.end);
    }

    /**
     * Check if each interval contains another
     * Strategy: Process intervals from right to left (reverse order)
     * For each interval, check if any interval to its right has both:
     * - start >= current.start (guaranteed by sorting)
     * - end <= current.end (we track minimum end seen)
     */
    int min_end_seen = INT_MAX;
    for (int i = n - 1; i >= 0; i--) {
        const auto& current = intervals[i];

        // If we've seen an interval with end <= current.end,
        // and it must have start >= current.start (due to sorting and processing order),
        // then current contains that interval
        if (min_end_seen != INT_MAX && min_end_seen <= current.end) {
            contains_another[current.original_index] = 1;
        }

        min_end_seen = min(min_end_seen, current.end);
    }

    
    // First line: Does each interval contain another?
    for (int i = 0; i < n; i++) {
        cout << contains_another[i];
        if (i < n - 1) cout << " ";
    }
    cout << "\n";

    // Second line: Is each interval contained by another?
    for (int i = 0; i < n; i++) {
        cout << is_contained_by_another[i];
        if (i < n - 1) cout << " ";
    }
    cout << "\n";
}//* T:O(n*logn), S: O(n)

int main() {
    ios_base::sync_with_stdio(false);  // Speed up input/output
    cin.tie(nullptr);

    solve();

    return 0;
}