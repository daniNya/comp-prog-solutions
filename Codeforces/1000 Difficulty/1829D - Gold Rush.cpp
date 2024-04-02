#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        string res = "NO";
        int m, n;
        cin >> m >> n;

        queue<int> factors;
        factors.push(m);

        while (!factors.empty()) {
            int curr = factors.front();
            factors.pop();
            if (curr == n) {
                res = "YES";
                break;
            }
            if (!(curr % 3)) {
                int quot = curr / 3;
                factors.push(quot);
                factors.push(quot * 2);
            }
        }

        cout << res << endl;
    }

    return 0;
}

/*
Thought Process:
1. To distribute a pile into two piles as specified in the question, the number must be divisible by 3
2. Keep dividing each factor that is divisible by 3 by 3
3. Once the number is found, exit the loop

Status:
ACCEPTED
Time - 186 ms
Memory - 100 KB
*/
