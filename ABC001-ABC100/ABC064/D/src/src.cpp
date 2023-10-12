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
	string S;
	cin >> S;

	vector<char> ans;
	rep(i,N) {
		int left = 0, right = 0;
		while (S[i] == '(') {
			left++;
			i++;
		}		
		while (S[i] == ')') {
			right++;
			i++;
		}

		if (left < right) {
			rep(i,right+right-left-1) {
				ans.push_back('(');
			}
			rep(i,right) {
				ans.push_back(')');
			}
		} else if (left > right) {
			rep(i,left) {
				ans.push_back('(');
			}
			rep(i,left) {
				ans.push_back(')');
			}
		}
		i--;
	}
	
			/*while (left < right) {
				right--;
			}*/

	/*
	int index = 0;
	while(index < N) {
		left = 0; right = 0;
		while(S[index] != ')' && index < N) {
			left++;
			index++;
		}

		while(right != left && index < N) {
			right++;
			index++;
		}

		/*
		if (left < right) {
			rep(i,right) {
				ans.push_back('(');
			}
			rep(i,right) {
				ans.push_back(')');
			}
		} else if (left > right) {
			rep(i,left) {
				ans.push_back('(');
			}
			rep(i,left) {
				ans.push_back(')');
			}
		}//
		//getchar();
	}*/

	rep(i,ans.size()) {
		cout << ans[i];
	}
	cout << endl;
	
	/*rep(i,N) {
		if (S[i] == '(') left++;
		else if (S[i] == ')') right++;
	}*/



	return 0;
}