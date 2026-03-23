#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, k, x;
vector<int> s;

int calcMinBoatCapacity(vector<int> arr) {

	if (arr.size() == 0) return 0;
	if (arr.size() <= k) return arr[0];

	vector<int> leftover;
	vector<bool> taken;
	for (int i = 0; i < arr.size(); i++) taken.push_back(false);
	vector<int> sums;
	for (int i = 0; i < k; i++) sums.push_back(0);

	int ans = arr[0];

	for (int i = 0; i < k; i++)  
	{
		int j = 0;
		while (j < arr.size() && sums[i] < ans) {     
			if (taken[j]) {
				j++;
				continue;
			}
			if (ans - sums[i] >= arr[j]) {
				sums[i] += arr[j];
				taken[j] = true;
			}
			j++;
		}
	}

	for (int i = 0; i < arr.size(); i++)  
		if (!taken[i]) leftover.push_back(arr[i]);

	int lo = calcMinBoatCapacity(leftover);

	for (int i = k - 1; i >= 0; i--) 
	{
		int testAns = sums[i] + lo;

		int fitCount = 0;
		vector<int> testSums = sums;
		vector<bool> takenLO;
		for (int i = 0; i < leftover.size(); i++) takenLO.push_back(false);

		for (int x = 0; x < k; x++)
		{
			int j = 0;

			while (j < leftover.size() && testSums[x] < testAns) {  
				if (takenLO[j]) {
					j++;
					continue;
				}
				if (testAns - testSums[x] >= leftover[j]) {
					testSums[x] += leftover[j];
					takenLO[j] = true;
					fitCount++;
				}
				j++;
			}
		}

		if (fitCount == leftover.size()) {
			sums = testSums;
			ans = testAns;                  
			break;
		}
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n >> k;

	for (size_t i = 0; i < n; i++)
	{
		cin >> x;
		s.push_back(x);
	}

	sort(s.begin(), s.end(), [](int a, int b) { return b < a; });
	for (size_t i = 0; i < n; i++)
	{
		cout << s[i];
	}

	//cout << calcMinBoatCapacity(s);
}