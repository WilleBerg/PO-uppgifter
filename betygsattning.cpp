#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	double aMax, cMax, eMax, a, c, e;
	cin >> aMax >> cMax >> eMax;
	cin >> a >> c >> e;
	string betyg;
	if (c < cMax / 2) {
		betyg = "E";
	}
	if (c >= cMax / 2) {
		betyg = "D";
	}
	if (c == cMax) {
		betyg = "C";
	}
	if (c == cMax && a >= aMax / 2) {
		betyg = "B";
	}
	if (c == cMax && a == aMax) {
		betyg = "A";
	}
	cout << betyg;
#ifdef _DEBUG
	system("pause");
#endif // _DEBUG
}