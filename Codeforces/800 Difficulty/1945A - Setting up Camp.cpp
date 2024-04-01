#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int res = 0;
        int a, b, c;
        cin >> a >> b >> c;

        res += a;

        auto ext = div(b, 3);
        c -= (ext.rem > 0 ? 3 - ext.rem : 0);
        res += ext.quot + (ext.rem > 0);

        if (c < 0) {
            cout << -1 << endl;
            continue;
        }

        res += ceil((double)c / 3);

        cout << res << endl;
    }

    return 0;
}

/*
Thought Process:
1. Introverts can be ignored as they each take up 1 tent
2. Divide the extroverts by 3
3. If a remainder exists, subtract from universals to get to 3
4. Add them all up

Results:
ACCEPTED
Time - 93 ms
Memory - 0 KB
*/
