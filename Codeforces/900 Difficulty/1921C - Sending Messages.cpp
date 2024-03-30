#include <bits/stdc++.h>
#define lli long long int

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        lli f, a, b;
        lli last = 0;

        cin >> n >> f >> a >> b;

        for (int j = 0; j < n; j++) {
            lli current;
            cin >> current;

            f -= min((current - last) * a, b);
            last = current;
        }

        cout << (f > 0 ? "YES" : "NO") << endl;
    }

    return 0;
}

/*
Thought Process:
1. There's only 2 possible actions that can be done in between any two moments
2. Each action, which is to: wait and send / to turn off and turn on then send, can be taken every moment
3. Subtract the minimum time between these two actions from the total charge
4. Evaluate if the charge is 0 or less by the end

Results:
ACCEPTED
Time - 389 ms
Memory - 0 KB
*/
