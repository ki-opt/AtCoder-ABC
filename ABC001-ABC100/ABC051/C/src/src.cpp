#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>

using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

class Node {
public:
	int score;
	pair<int,int> pairs;
	string str;
};

bool operator> (const Node &node1, const Node &node2) {
	if (node1.score == node2.score) {
		return node1.str.size() > node2.str.size();
	} else {
		return node1.score > node2.score;
	}
}

int main() {
	int sx, sy, tx, ty;
	cin >> sx >> sy >> tx >> ty;	
	map<pair<int,int>,int> mp;

	for (int index = 0; index < 4; index++) {
		int start_x, start_y;
		int goal_x, goal_y;
		if (index % 2 == 0) {
			start_x = sx; goal_x = tx;
			start_y = sy; goal_y = ty;
		} else if (index % 2 == 1) {
			start_x = tx; goal_x = sx;
			start_y = ty; goal_y = sy;
		}
		priority_queue<Node, vector<Node>, greater<Node>> pque;	
		pque.push({abs(goal_x-start_x)+abs(goal_y-(start_y+1)),{start_x,(start_y+1)},"U"});// mp[{start_x,(start_y+1)}] = 1;
		pque.push({abs(goal_x-start_x)+abs(goal_y-(start_y-1)),{start_x,(start_y-1)},"D"});// mp[{start_x,(start_y-1)}] = 1;
		pque.push({abs(goal_x-(start_x+1))+abs(goal_y-start_y),{(start_x+1),start_y},"R"});// mp[{(start_x+1),start_y}] = 1;
		pque.push({abs(goal_x-(start_x-1))+abs(goal_y-start_y),{(start_x-1),start_y},"L"});// mp[{(start_x-1),start_y}] = 1;
		while(pque.empty() == false) {
			Node node = pque.top(); pque.pop();
			if (node.score == 0) {
				int pos_x = start_x, pos_y = start_y;
				for (int i = 0; i < node.str.size(); i++) {
					if (node.str[i] == 'U') { pos_y++; }
					else if (node.str[i] == 'D') { pos_y--; }
					else if (node.str[i] == 'R') { pos_x++; }
					else if (node.str[i] == 'L') { pos_x--; }
					else cerr << "???" << endl;
					if (i + 1 != node.str.size()) {
						cerr << pos_x << " " << pos_y << endl;
						mp[{pos_x,pos_y}] = 1;
					}
				}
				cout << node.str;// << " ";
				break;
			}
			int x = node.pairs.first, y = node.pairs.second;
			if (mp.count({x,y}) > 0) continue;
			string str = node.str;
			if (mp.count({x,y+1}) == 0) pque.push({abs(goal_x-x)+abs(goal_y-(y+1)),{x,y+1},str+'U'});
			if (mp.count({x,y-1}) == 0) pque.push({abs(goal_x-x)+abs(goal_y-(y-1)),{x,y-1},str+'D'});
			if (mp.count({x+1,y}) == 0) pque.push({abs(goal_x-(x+1))+abs(goal_y-y),{x+1,y},str+'R'});
			if (mp.count({x-1,y}) == 0) pque.push({abs(goal_x-(x-1))+abs(goal_y-y),{x-1,y},str+'L'});
		}
	}	
	return 0;
}