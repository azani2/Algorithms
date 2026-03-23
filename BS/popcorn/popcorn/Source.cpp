#include <climits>
#include <iostream>
#include <fstream>
using namespace std;

#define MAX 101000

int n, k, s, p[MAX];
int l, r, mid, l1, r1, mid1, maxPopcornPerPerson, startEatingBox, lastBoxToEat;

ofstream fout;

int closestPowerOf2(int x) {
	int res = 1;
	while (res < x) {
		res *= 2;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	fout.open("terminal.txt", ios::trunc);

	cin >> n >> k >> s;
	for (int i = 1; i <= n; i++) cin >> p[i];
	for (int i = 2; i <= n; i++) p[i] += p[i - 1];
	for (int i = 1; i <= n; i++) fout << p[i] << " ";
	fout << endl;

	l = 1; r = maxPopcornPerPerson = closestPowerOf2(p[n]);

	while (l <= r)
	{
		mid = (l + r) / 2;
		startEatingBox = 1;

		fout << "Mid = " << mid << ", l = " << l << ", r = " << r << endl;

		for (int j = 0; j < k; j++)
		{
			l1 = startEatingBox - 1;
			lastBoxToEat = startEatingBox - 1;
			r1 = n;

			fout << "\n---start inner while ----\n \tj = " << j << ", lastBoxToEat = " << lastBoxToEat << endl;

			while (l1 <= r1)
			{
				mid1 = (l1 + r1) / 2;

				fout << "\tMid1 = " << mid1 << ", l1 = " << l1 << ", r1 = " << r1 << endl
								<< "\t\tp[mid1] - p[idx - 1] = " << p[mid1] << " - " << p[startEatingBox-1] << " = " << p[mid1] - p[startEatingBox - 1] << endl;
				
				if (p[mid1] - p[startEatingBox - 1] > mid)
				{
					r1 = mid1 - 1;

					fout << "r1 <- mid-1 = " << r1;
				}
				else
				{
					l1 = mid1 + 1;

					fout << "l1 <- mid+1 = " << l1 << "\t";
					fout << "lastBoxToEat = " << lastBoxToEat;

					lastBoxToEat = max(lastBoxToEat, mid1);

					fout << ", mid1 = " << mid1 << " => lastBoxToEat <- " << lastBoxToEat << endl;
				}
			}
			startEatingBox = lastBoxToEat + 1;

			fout << "\n---end inner while ----\n" << "lastBoxToEat = " << lastBoxToEat << "\n\n";
		}

		fout << "startEatingBox = " << startEatingBox << endl;
		if (startEatingBox > n) 
		{
			maxPopcornPerPerson = min(maxPopcornPerPerson, mid);
			r = mid - 1;
		}
		else 
		{
			l = mid + 1;
		}
		fout << "r = " << r << ", l = " << l << ", maxPopcornPerPerson = " << maxPopcornPerPerson << "\n\n";
	}
	
	fout << maxPopcornPerPerson / s + (maxPopcornPerPerson % s > 0) << endl;
	fout.close();
	cout << maxPopcornPerPerson / s + (maxPopcornPerPerson % s > 0) << endl;
	return 0;
}