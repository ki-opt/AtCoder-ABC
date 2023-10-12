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
	int N, M;
	cin >> N >> M;
	vector<int> p(M);
	vector<string> S(M);
	rep(i,M) cin >> p[i] >> S[i];

	vector<int> check(N,0), wrong(N,0);
	vector<int> ans(2,0);
	rep(i,M) {
		if (S[i] == "AC") {
			if (check[p[i]-1] == 0) {
				ans[0]++;
				ans[1] += wrong[p[i]-1];
				check[p[i]-1] = 1;
			}
		} else if (S[i] == "WA") {
			wrong[p[i]-1]++;
		}
	}
	cout << ans[0] << " " << ans[1] << endl;
	
	return 0;

}