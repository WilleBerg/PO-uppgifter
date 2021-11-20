#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
	int x, y, ln, k;
	Node();
};
Node::Node() {

}

bool vis[100][100];
char mp[100][100];
int ae[100][100];
int main() {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			mp[i][j] = false;
			ae[i][j] = 201;
		}
	}
	Node p;
	p.x = 0;
	p.y = 0;
	p.ln = 0;
	p.k = 0;
	int y = 0;
	int x = 0;
	int e = 0;
	int tot = 0;
	cin >> y >> x >> e;
	for (int i = 0; i < y; i++) {
		string tmp = "";
		cin >> tmp;
		for (int j = 0; j < x; j++) {
			mp[i][j] = tmp[j];
		}
	}
	
	queue<Node> q;
	q.push(p);
	while (!q.empty() && vis[y - 1][x - 1] == false) {
		Node curr = q.front();
		q.pop();
		if (curr.x + 1 < x && (curr.k < ae[curr.y][curr.x + 1])) {
			if (mp[curr.y][curr.x + 1] == '#') {
				if (curr.k < e && curr.k + 1 < ae[curr.y][curr.x + 1]) {
					Node next;
					next.x = curr.x + 1;
					next.y = curr.y;
					next.ln = curr.ln + 1;
					next.k = curr.k + 1;
					tot = curr.ln + 1;
					q.push(next);
					vis[curr.y][curr.x + 1] = true;
					ae[curr.y][curr.x + 1] = curr.k + 1;
				}
			} else {
				Node next;
				next.x = curr.x + 1;
				next.y = curr.y;
				next.k = curr.k;
				next.ln = curr.ln + 1;
				tot = curr.ln + 1;
				q.push(next);
				vis[curr.y][curr.x + 1] = true;
				ae[curr.y][curr.x + 1] = curr.k;
			}
		}
		if (curr.y + 1 < y && (curr.k < ae[curr.y + 1][curr.x])) {
			if (mp[curr.y + 1][curr.x] == '#') {
				if (curr.k < e && curr.k + 1 < ae[curr.y + 1][curr.x]) {
					Node next;
					next.x = curr.x;
					next.y = curr.y + 1;
					next.ln = curr.ln + 1;
					next.k = curr.k + 1;
					tot = curr.ln + 1;
					q.push(next);
					vis[curr.y + 1][curr.x] = true;
					ae[curr.y + 1][curr.x] = curr.k + 1;
				}
			} else {
				Node next;
				next.x = curr.x;
				next.y = curr.y + 1;
				next.ln = curr.ln + 1;
				next.k = curr.k;
				tot = curr.ln + 1;
				q.push(next);
				vis[curr.y + 1][curr.x] = true;
				ae[curr.y + 1][curr.x] = curr.k;
			}
		}
		if (curr.x - 1 >= 0 && (curr.k < ae[curr.y][curr.x - 1])) {
			if (mp[curr.y][curr.x - 1] == '#') {
				if (curr.k < e && curr.k + 1 < ae[curr.y][curr.x - 1]) {
					Node next;
					next.x = curr.x - 1;
					next.y = curr.y;
					next.ln = curr.ln + 1;
					next.k = curr.k + 1;
					tot = curr.ln + 1;
					q.push(next);
					vis[curr.y][curr.x - 1] = true;
					ae[curr.y][curr.x - 1] = curr.k + 1;
				}
			} else {
				Node next;
				next.x = curr.x - 1;
				next.y = curr.y;
				next.ln = curr.ln + 1;
				next.k = curr.k;
				tot = curr.ln + 1;
				q.push(next);
				vis[curr.y][curr.x - 1] = true;
				ae[curr.y][curr.x - 1] = curr.k;
			}
		}
		if (curr.y - 1 >= 0 && (curr.k < ae[curr.y - 1][curr.x])) {
			if (mp[curr.y - 1][curr.x] == '#') {
				if (curr.k < e && curr.k + 1 < ae[curr.y - 1][curr.x]) {
					Node next;
					next.x = curr.x;
					next.y = curr.y - 1;
					next.ln = curr.ln + 1;
					next.k = curr.k + 1;
					tot = curr.ln + 1;
					q.push(next);
					vis[curr.y - 1][curr.x] = true;
					ae[curr.y - 1][curr.x] = curr.k + 1;
				}
			} else {
				Node next;
				next.x = curr.x;
				next.y = curr.y - 1;
				next.k = curr.k;
				next.ln = curr.ln + 1;
				tot = curr.ln + 1;
				q.push(next);
				vis[curr.y - 1][curr.x] = true;
				ae[curr.y - 1][curr.x] = curr.k;
			}
		}
	}

	if (vis[y - 1][x - 1] == false) {
		cout << "nej";
	} else {
		cout << tot;
	}
#ifdef _DEBUG
	system("pause");
#endif // _DEBUG
}