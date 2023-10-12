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
	int X, Y, Z;
	cin >> X >> Y >> Z;
	string S;
	cin >> S;

	vector<vector<int>> dp(S.size()+1,vector<int>(2,0));
	repp(i,S.size(),1) {
		if(S[i] == 'a') {
			int tmp;
			if (dp[i-1][0] + X < dp[i-1][1] + X + Z) tmp = dp[i-1][0] + X;
			else tmp = dp[i-1][1] + X + Z; 
			if (dp[i-1][1] + Y < tmp)
			dp[i][0] = tmp;
		} else if (S[i] == 'A') {
			int tmp;
			if (dp[i-1][0] + X + Z < ) tmp = dp[i-1][0] + X + Z ;
			else tmp = 

			dp[i][1] = tmp;
		}
	}

	//動的計画法らしい。。

	/*

	long int ans = 0;
	int capslock = 0;
	rep(i,S.size()){
		if (S[i] == 'a' && capslock == 0) {
			ans += X;
		} else if (S[i] == 'A' && capslock == 1) {
			ans += X;
		} else {//if (S[i] == 'A' && capslock == 0) {
			int zero = 0, one = 0;
			int tmp = -1;
			repp(j,S.size(),i+1) {
				if (i == j - 1) zero += Z + X;
				else zero += X;
				one += Y;
				if (S[j] != S[i]) {
					tmp = j - 1;
					break;
				}
			}
			if (zero < one) {
				ans += zero;
				capslock = 1 - capslock;
			}
			else ans += one;
			if (tmp == -1) i = S.size() - 1;
			else i = tmp;
		//} else if (S[i] == 'a' && capslock == 1) {
			
		//}
		}
	}
	cout << ans << endl;*/

	return 0;
}