#include<bits/stdc++.h>

using namespace std;
void solve() {
    unsigned long long n;
    cin >> n;

    for (int i = 1; i < 1e6; i++) {
        cout << n << " ";

        if (n == 1) break;

        if (n % 2 == 0)
            n /= 2;
        else
            n = 3 * n + 1;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin>>t;
    while (t--) solve();
}