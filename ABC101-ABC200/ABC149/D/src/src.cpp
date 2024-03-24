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
	int N, K, R, S, P;
	string T;
	cin >> N >> K >> R >> S >> P >> T;

	int total = 0;
	vector<char> hist;
	unordered_map<char,char> umap = {{'r','p'},{'s','r'},{'p','s'}};
	unordered_map<char,int> tokuten = {{'r',P},{'s',R},{'p',S}};
	rep(i,N) {
		if (i < K || hist[i-K] != umap[T[i]]) {
			hist.push_back(umap[T[i]]);
			total += tokuten[T[i]];
		} else {
			if (i + K >= N) hist.push_back('a');
			else hist.push_back('a');
		}
		/*
		if (T[i] == 'r') {
			if (i < K || hist[i-K] != 'p') {
				hist.push_back('p');
				total += P;
			} else {
				if (i + K >= N) hist.push_back('r');
				else hist.push_back
			}
		} else if (T[i] == 's') {
			if (i < K || hist[i-K] != 'r') {
				hist.push_back('r');
				total += R;
			} else {
				hist.push_back('s');
			}
		} else if (T[i] == 'p') {
			if (i < K || hist[i-K] != 's') {
				hist.push_back('s');
				total += S;
			} else {
				hist.push_back('p');
			}
		}
		*/
	}
	cout << total << endl;

	return 0;
}