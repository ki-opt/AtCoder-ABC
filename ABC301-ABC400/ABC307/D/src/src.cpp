#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>

using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, limit, init) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int N;
	string S;
	cin >> N >> S;

	vector<pair<char,int>> kakko;
	vector<pair<int,int>> erased_index;
	rep(i,N) {
		if (S[i] == '(') {
			kakko.push_back({'(',i});
		} else if (S[i] == ')') {
			kakko.push_back({')',i});
			if (kakko[kakko.size()-2].first == '(') {
				erased_index.push_back({kakko[kakko.size()-2].second,
					kakko[kakko.size()-1].second});
				kakko.pop_back();
				kakko.pop_back();
			}
		}	
	}
	//rep(i,erased_index.size()) 
	//	cerr << erased_index[i].first << " " << erased_index[i].second << endl;
	
	int index = 0;
	//cerr << erased_index.size() << endl;
	if (erased_index.size() > 0) {
		sort(erased_index.begin(),erased_index.end());
		rep(i,N) {
			if (i == erased_index[index].first) {
				i = erased_index[index].second;
				repp(j,erased_index.size(),index+1) {
					if (erased_index[j].first > i) {
						index = j;
						break;
					}
				}
			} else {
				cout << S[i];
			}
			if (index == erased_index.size()) {
				repp(j,N,i+1) {
					cout << S[j];
				}
				return 0;
			}
		}
	} else { 
		rep(i,N) cout << S[i];
	}
	
	return 0;
}