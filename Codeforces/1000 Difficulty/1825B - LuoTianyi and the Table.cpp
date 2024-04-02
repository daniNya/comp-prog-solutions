#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int m, n;
        cin >> m >> n;

        vector<int> nums;
        for (int j = 0; j < m * n; j++) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int ans1 = 0;
        sort(nums.begin(), nums.end());

        int mult1 = (max(m, n) - 1) * min(m, n);    // Larger
        int mult2 = min(m, n) - 1;                  // Smaller

        ans1 += abs(nums.front() - nums.back()) * mult1;
        int temp = nums.back();
        nums.pop_back();
        ans1 += abs(nums.front() - nums.back()) * mult2;
        nums.push_back(temp);

        int ans2 = 0;
        reverse(nums.begin(), nums.end());

        ans2 += abs(nums.front() - nums.back()) * mult1;
        nums.pop_back();
        ans2 += abs(nums.front() - nums.back()) * mult2;

        cout << max(ans1, ans2) << endl;
    }

    return 0;
}


/*
Thought Process:
1. The first number in the table has to have the most impact
2. If there is a negative number, first number is the lowest negative number (lowest defined as abs(n) is largest)
3. Otherwise, first number is the largest number
4. The cells neighboring the first ( (0,1) and (1,0) ) must have the biggest impact when computing difference with first object
5. If there are more rows than columns, (1,0) must have the biggest impact followed by (0,1)
6. The reverse is true when columns are more than rows
7. The rest of the numbers do not matter
8. Use math to simplify instead of creating a table

-- Problem: Wrong answer
1. Suspicion of wrong logic when choosing number for first cell
2. Instead of setting the first cell preemptively, simply calculate both cases where the vector is sorted ascending/descending, then compare the two values

Status:
ACCEPTED
Time - 234 ms
Memory - 100 KB
*/
