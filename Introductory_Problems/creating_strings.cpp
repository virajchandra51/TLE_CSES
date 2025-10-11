#include <bits/stdc++.h>

using namespace std;

#define len(x) int((x).size())
#define nl '\n'
#define sp ' '
#define ll long long

void solve_using_stl(string& s) {
    sort(s.begin(), s.end());
    vector<string> v;

    do {
        v.push_back(s);

    } while (next_permutation(s.begin(), s.end()));
    // next_permutation attempts to generate next lexicographically larger permutation in O(n)

    cout << v.size() << nl;
    for (auto perm : v)
        cout << perm << nl;
}  //* Time: O(n*n!), Space : O(n!)

void generate_permutations(string& s, vector<int>& flag, string& aux, set<string>& results) {
    // Base Condition
    if (len(aux) == len(s)) {
        results.insert(aux);
        return;
    }

    // Add not yet considered char to the 'aux'
    for (int i = 0; i < len(flag); i++) {
        if (flag[i]) continue;  // already considered element

        aux.push_back(s[i]);
        flag[i] = 1;

        generate_permutations(s, flag, aux, results);

        // Backtrack
        aux.pop_back();
        flag[i] = 0;
    }
}

void solve_using_flag_array(string& s) {
    int n = len(s);
    string aux = "";
    vector<int> flag(n, 0);  // initially mark all unused
    set<string> unq_perms;   // to store all the unique permutations

    generate_permutations(s, flag, aux, unq_perms);

    cout << len(unq_perms) << nl;  // count
    for (auto perm : unq_perms)
        cout << perm << nl;
}  //* Time: (n*n!*log(n!)) Space: O(n! + n)

void print_permutation(map<char, int>& fm, string& aux, int n) {
    // Base Case: all elements are considered
    if (len(aux) == n) {
        cout << aux << nl;
        return;
    }

    for (int i = 0; i < 26; i++) {
        char ch = 'a' + i;
        // check if 'ch' can be added to 'aux'
        if (fm.find(ch) != fm.end()) {
            aux.push_back(ch);
            if (fm[ch] == 1)  //! all instances of 'ch' consumed
                fm.erase(ch);
            else
                fm[ch]--;

            print_permutation(fm, aux, n);

            // backtrack
            fm[ch]++;
            aux.pop_back();
        }
    }
}

int fact(int n) {
    int res = 1;
    for (int i = 1; i <= n; i++) res *= i;
    return res;
}
void optimal_solve_using_fm(string& s) {
    int n = len(s);
    // create frequency map
    map<char, int> fm;
    for (auto ch : s)
        fm[ch]++;

    // Output count of unique permutations : (n!)/(a!*b!*...)
    int divisor = 1;
    for (auto& [ch, f] : fm)
        divisor *= fact(f);
    cout << (fact(n) / divisor) << nl;

    // Print Unique Permutations
    string aux = "";  // temporary storage
    print_permutation(fm, aux, n);
}  //* Time : O(n!), Space : O(n)

void solve() {
    string s;
    cin >> s;

    // Using STL
    // solve_using_stl(s);

    // Using flag array
    // solve_using_flag_array(s);

    // Optimal Way
    optimal_solve_using_fm(s);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}