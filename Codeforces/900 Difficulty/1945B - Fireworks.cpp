#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		long long int a, b, m;
		cin >> a >> b >> m;

		long long int res = m / a + m / b + 2;

		cout << res << endl;
	}

	return 0;
}

/*
Thought process:
1. Find a pattern hidden among these 3 numbers and try to come up with a general formula
2. Notice the first test case, where m is smaller than a and b, but still gives the answer of 2
3. Notice the last test case, where the answer has a 2 in the ones place
4. Conclude that +2 must be part of the formula
5. Try doing some division and addition mentally for some test cases with the 3 given numbers
6. Find out that m/a + m/b + 2 seems to be correct
*/