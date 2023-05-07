#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

bool check(string S, int i) {
	return S[i] == 'A' || S[i] == 'C' || S[i] == 'G' || S[i] == 'T';
}

int main() {
	string S;
	cin >> S;

	vector<int> ans;
	ans.push_back(0);
	rep(i,S.length()) {
		if(check(S,i)) {
			int cnt = 1;
			int j = i + 1;
			if (j == S.length()) {
				ans.push_back(cnt);
				continue;
			}
			while(check(S,j)) {
				cnt++;
				j++;
				if (j == S.length()) break;
			}
			ans.push_back(cnt);
		}
	}

	cout << *max_element(ans.begin(), ans.end()) << endl;	

	return 0;
}