#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>
#include <stack>
#include "atcoder/all"

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int N;
	cin >> N;
	vector<int> x(N), y(N);
	rep(i,N) cin >> x[i] >> y[i];

	double ans = 0;
	rep(i,N) {
		repp(j,1,N) {
			double dist = pow((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]),0.5);
			ans = max(dist, ans);
		}
	}
	printf("%.10f",ans);


	return 0;
}