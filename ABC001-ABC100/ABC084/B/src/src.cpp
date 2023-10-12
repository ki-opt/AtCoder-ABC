#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, limit, init) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int A, B;
	string S;
	cin >> A >> B >> S;

	if (S[A] != '-') {
		cout << "No" << endl;
		return 0;
	}
	int sum = 0;
	rep(i,A+B+1) {
		if (S[i] == '-') sum++;
	}
	if (sum == 1) {
		cout << "Yes" << endl;
		return 0;
	}
	cout << "No" << endl;

	return 0;
}