#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        if (n < 2 || n % 2) {
            cout << "NO" << endl;
            continue;
        }

        string res = "";
        for (int j = 0; j < (n / 2); j++) {
            res += (j % 2 ? "AA" : "BB");
        }

        cout << "YES\n" << res << endl;
    }

    return 0;
}

/*
Thought Process:
1. An odd numbered amount of "special characters" cannot exist
2. The string formed can simply be a string of double characters (each containing 2 special characters)

Results:
ACCEPTED
Time - 0 ms
Memory - 0 KB
*/
