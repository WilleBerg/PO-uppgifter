#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

class Person {
public:
	double ip;
	int nmr;
	int ant;
	int m;
private:

};

int main() {
	int pers;
	vector<int> aPers;
	vector<vector<int>> prc;
	vector<vector<int>> to;
	vector<Person> inf;
	queue<int> q;
	cin >> pers;
	prc.resize(pers);
	to.resize(pers);
	for (int i = 0; i < pers; i++) {
		Person p;
		p.ant = 0;
		inf.push_back(p);
		int tmp = 0;
		cin >> tmp;
		aPers.push_back(tmp);
		tmp = 0;
		cin >> tmp;
		int lp = tmp;
		if (tmp == 0) {

		} else {
			for (int j = 0; j < lp; j++) {
				tmp = 0;
				cin >> tmp;
				to[i].push_back(tmp);
				tmp = 0;
				cin >> tmp;
				prc[i].push_back(tmp);
			}
		}

	}
	for (int i = 0; i < pers; i++) {
		inf[i].m = aPers[i];
		inf[i].nmr = i;
		inf[i].ip = 0;
		for (int j = 0; j < to[i].size(); j++) {
			inf[to[i][j] - 1].ant++;
		}
	}
	for (int i = 0; i < inf.size(); i++) {
		if (inf[i].ant == 0) {
			q.push(i);
			inf[i].ip = inf[i].m;
		}
	}
	vector<int> op;
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		for (int j = 0; j < to[p].size(); j++) {
			if (inf[p].m <= inf[p].ip) {
				inf[to[p][j] - 1].ip += inf[p].m * prc[p][j] * 0.01;
				inf[to[p][j] - 1].ant--;
				if (inf[to[p][j] - 1].ant == 0) {
					q.push(to[p][j] - 1);
				}
			} else {
				inf[to[p][j] - 1].ip += inf[p].ip * prc[p][j] * 0.01;
				inf[to[p][j] - 1].ant--;
				if (inf[to[p][j] - 1].ant == 0) {
					q.push(to[p][j] - 1);
				}
			}
		}
		if (inf[p].ip - inf[p].m > -0.0001) {
			op.push_back(p + 1);
		}
	}
	sort(op.begin(), op.end());
	for (int i = 0; i < op.size(); i++) {
		cout << op[i] << " ";
	}

#ifdef _DEBUG
	system("pause");
#endif // _DEBUG

}