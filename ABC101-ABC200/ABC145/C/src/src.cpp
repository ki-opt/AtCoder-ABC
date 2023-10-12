#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>

using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, limit, init) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int N;
	cin >> N;
	vector<int> x(N), y(N);
	rep(i,N) cin >> x[i] >> y[i];
	vector<int> nums(N);
	rep(i,N) nums[i] = i;

	int cnt = 0;
	double ans = 0;
	do {
		rep(i,N-1) {
			ans += pow(pow((x[nums[i]]-x[nums[i+1]]),2)+pow(y[nums[i]]-y[nums[i+1]],2),0.5);
		}
		cnt++;
	} while (next_permutation(nums.begin(), nums.end()));
	printf("%lf\n", ans / (double)cnt);
	return 0;
}