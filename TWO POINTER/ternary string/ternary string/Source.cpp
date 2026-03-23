#include <iomanip>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXT 20005

string s;
int t, startIdx, j, minLen[MAXT];
bool found;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;
	for (int i = 0; i < t; i++) {
		startIdx = 0;
		j = 1;
		minLen[i] = INT_MAX;
		found = false;

		cin >> s;
		while (j < s.length()) {
			if (s[j] == s[startIdx]) {
				if (s[j - 1] != s[startIdx]) startIdx = j - 1;
				else startIdx = j;
			}
			else if (j >= 2 && j - 1 != startIdx && s[j] != s[j - 1]) {
				minLen[i] = min(minLen[i], j - startIdx + 1);
				startIdx = j - 1;
				found = true;
			}
			j++;
		}
		if (!found) minLen[i] = 0;
	}

	for (int i = 0; i < t; i++) cout << minLen[i] << endl;
	return 0;
}