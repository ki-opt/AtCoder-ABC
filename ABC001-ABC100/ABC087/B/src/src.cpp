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
	int A, B, C, X;
	cin >> A >> B >> C >> X;

	unordered_map<string,int> tmp;
	int ans = 0;
	rep(i,C+1) {
		int sum_c = i * 50;
		rep(j,B+1) {
			int sum_b = sum_c + j * 100;
			rep(k,A+1) {
				int sum_a = sum_b + k * 500;
				if (sum_a == X) {
					char s[1000];
					sprintf(s,"%d_%d_%d",k,j,i); 
					string str = s;
					tmp[str] = 1;
				}
			}
		}
	}
	for (auto const &pair: tmp) {
		ans++;
	}
	cout << ans << endl;

	return 0;
}