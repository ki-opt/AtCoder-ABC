#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int N;
	cin >> N;
	vector<int> a(N), b(N);
	rep(i,N) { cin >> a[i]; b[i] = a[i]; }
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());

	int total = 0;
	rep(i,N) total += a[i];

	int ans = INT_MAX;
	repp(x,-100,101) {
		int tmp = 0;
		rep(i,N) {
			tmp += (a[i] - x) * (a[i] - x);
		}
		ans = min(ans,tmp);
	}
	cout << ans << endl;

	/*
	if (total % 2 == 0) {
		int ans = 0;
		rep(i,N) ans += (int)pow(a[i]-total/N,2);
		cout << ans << endl;
	} else {
		int ans1 = 0, ans2 = 0, ans3 = 0, ans = 0;
		rep(i,N) ans1 += (int)pow(a[i]-(total/N),2);
		rep(i,N) ans2 += (int)pow(a[i]-(total/N-1),2);
		rep(i,N) ans3 += (int)pow(a[i]-(total/N+1),2);
		ans = min({ans1,ans2,ans3});
		cout << ans << endl;
	}
	*/
}