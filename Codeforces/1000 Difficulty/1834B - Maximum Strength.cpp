#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int res = 0;
        vector<int> first, second;
        string l, r;
        cin >> l >> r;

        for (auto c : l) { first.push_back(c - '0'); };
        for (auto c : r) { second.push_back(c - '0'); };

        int smaller = (first.size() == second.size() ? -1 : first.size() > second.size() ? 1 : 0);
        if (smaller != -1) {
            vector<int>& new_vector =(smaller == 1 ? second : first);
            new_vector.insert(new_vector.begin(), abs((int)first.size() - (int)second.size()), 0);
        }

        int j = 0;
        for (; j < first.size(); j++) {
            if (first[j] != second[j]) {
                res += abs(first[j] - second[j]);
                break;
            }
        }

        res += 9 * (first.size() - j - 1);

        cout << max(0, res) << endl;
    }

    return 0;
}

/*
Thought Process:
1. Convert the input from string into a vector of integers
2. Pad the shorter vector with leading 0's
3. Loop through each number in the vectors
4. Once a discrepancy is found between the numbers, determine the smaller vector in terms of value
5. The max difference of the first number that is different is simply the absolute value of the difference of the two numbers
6. Any numbers following will simply get the max value of 9, as the larger number can take any value from 0 to n, while the smaller n to 9, giving the max of 9 - 0 = 9
7. With this logic, calculate the max difference of the first number added by 9 * remaining number count

Results:
ACCEPTED
Time - 31 ms
Memory - 200 KB
*/
