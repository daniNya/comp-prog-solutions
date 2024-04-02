#include <bits/stdc++.h>

using namespace std;

int divide(int dividend, int a, int b, vector<int>& done) {
    int res = 0;

    auto ans1 = div(dividend, a);
    auto ans2 = div(dividend, b);

    if (ans1.rem == 0) {
        if (count(done.begin(), done.end(), ans1.quot) == 0){
            done.push_back(ans1.quot);
            res++;
            if (ans1.quot != 1) res += divide(ans1.quot, a, b, done);
        }
    }

    if (ans2.rem == 0) {
        if (count(done.begin(), done.end(), ans2.quot) == 0){
            done.push_back(ans2.quot);
            res++;
            if (ans2.quot != 1) res += divide(ans2.quot, a, b, done);
        }
    }

    return res;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int res = 1;

        int a, b, l;
        cin >> a >> b >> l;

        if (a == b) {
            while (l % a == 0) {
                res++;
                l /= a;
            }
        }
        else {
            vector<int> done = { };
            res += divide(l, a, b, done);
        }

        cout << res << endl;
    }

    return 0;
}

/*
Thought Process:
1. Divide the number by the two numbers, and divide each factor by the two numbers
2. Considering the max number of layers of division is log2(10^6) approx. 19, brute force solution may be accepted

Status:
ACCEPTED
Time - 124 ms
Memory - 100 KB
*/
