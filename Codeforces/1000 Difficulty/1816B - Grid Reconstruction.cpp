#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        deque<int> nums;
        deque<int> row1, row2;

        for (int j = 1; j <= n * 2; j++) {
            nums.push_back(j);
        }

        row1.push_back(nums.back());
        nums.pop_back();
        int temp = nums.back();
        nums.pop_back();

        for (int j = 1; j < n; j++) {
            if (j % 2) {
                row1.push_back(nums.front());
                nums.pop_front();
                row2.push_back(nums.front());
                nums.pop_front();
            }
            else {
                row2.push_back(nums.back());
                nums.pop_back();
                row1.push_back(nums.back());
                nums.pop_back();
            }
        }
        row2.push_back(temp);

        for (int j = 0; j < 2; j++) {
            deque<int>& temp = (j == 0 ? row1 : row2);
            for (int k : temp) {
                cout << k << " ";
            }
            cout << endl;
        }
    }

    return 0;
}

/*
Thought Process:
1. Grid should look like this:
   12  2  9  4  7  6
    1 10  3  8  5 11
2. This is because any odd-indexed item is attached with a plus sign, and even-indexed with a minus sign
3. The operation should look something like: largest - smallest + next largest - next smallest ...

Status:
ACCEPTED
Time - 93 ms
Memory - 100 KB
*/
