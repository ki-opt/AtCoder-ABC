#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <numeric>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int N;
	cin >> N;
	vector<int> P(N),Q(N);
	rep(i,N) { cin >> P[i]; }
	rep(i,N) { cin >> Q[i]; }

	vector<int> perm(N);
	iota(perm.begin(),perm.end(),1);
	int cnt = 1;
	int a = 0, b = 0;
	do {
		int i = 0;
		for (int val : perm) {
			if (P[i] != val) break;
			i++;
		}
		if (i == N) a = cnt;
		i = 0;
		for (int val : perm) {
			if (Q[i] != val) break;
			i++;
		}
		if (i == N) b = cnt;
		if (a != 0 && b != 0) break;
		cnt++;		
	} while (next_permutation(perm.begin(),perm.end()));
	cout << abs(a - b) << endl;

	return 0;
}