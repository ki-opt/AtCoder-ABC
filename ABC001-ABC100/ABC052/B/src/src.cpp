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
	int N;
	string S;
	cin >> N >> S;

	int x = 0;
	int max_val = 0;
	rep(i,N) {
		if (S[i] == 'I') x++;
		else x--;
		if (x > max_val) max_val = x;
	}
	cout << max_val << endl;

	return 0;
}