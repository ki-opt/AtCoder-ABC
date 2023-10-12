#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>

using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, limit, init) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	string S;
	cin >> S;

	int ans = 0;
	int zero = 0, one = 0;
	rep(i,S.size()) {
		if (S[i] == '0') zero++;
		else one++;
	}
	int min_val = min(zero,one);
	cout << min_val * 2 << endl;

	return 0;
}