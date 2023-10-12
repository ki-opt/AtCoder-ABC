#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>

using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int A, B;
	cin >> A >> B;

	if (B - A == 1 && A != 3 && A != 6) {
		cout << "Yes" << endl;
		return 0;
	} else {
		cout << "No" << endl;
	}

	/*
	rep(i,3) {
		rep(j,2) {
			if ()
		}
	}*/

	return 0;
}