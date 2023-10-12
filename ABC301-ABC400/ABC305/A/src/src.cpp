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
	int N;
	cin >> N;

	int ans = 0;
	while((N+ans) % 5 != 0 && (N-ans) % 5 != 0) ans++;
	if ((N+ans)%5==0) cout << N+ans << endl;
	else cout << N-ans << endl;

	return 0;
}