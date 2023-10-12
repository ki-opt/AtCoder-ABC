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
	int N, P, Q;
	cin >> N >> P >> Q;
	vector<int> D(N);
	rep(i,N) cin >> D[i];

	int min_val = *min_element(D.begin(),D.end());
	if (P > min_val + Q) cout << min_val + Q << endl;
	else cout << P << endl;

	return 0;
}