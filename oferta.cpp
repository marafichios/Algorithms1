#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iomanip>

#define INF ((int)1e9)

using namespace std;

double choose_2nd_offer(vector<double>& dp, vector<double>& P, int i) {
	double reduced_price = min({P[i - 1], P[i - 2]});
	return dp[i - 2] + P[i - 1] + P[i - 2] - reduced_price / 2;
}

double choose_3rd_offer(vector<double>& dp, vector<double>& P, int i) {
	double get_free = min({P[i - 1], P[i - 2], P[i - 3]});
	return dp[i - 3] + P[i - 1] + P[i - 2] + P[i - 3] - get_free;
}

double get_price(vector<double>& dp, vector<double>& P, int N) {
	for (int i = 1; i <= N; i++) {
		// choose the offer available depending on the number of products
		dp[i] = min(dp[i], P[i - 1] + dp[i - 1]);

		if (i >= 2) {
			dp[i] = min(dp[i], choose_2nd_offer(dp, P, i));
		}
		if (i >= 3) {
			dp[i] = min(dp[i], choose_3rd_offer(dp, P, i));
		}
	}

	return dp[N];
}

int main() {
	ifstream fin("oferta.in");
	ofstream fout("oferta.out");

	int N, K;
	fin >> N >> K;

	vector<double> P(N);
	for (int i = 0; i <  N; i++)
		fin >> P[i];

	vector<double> dp(N + 1, INF);
	dp[0] = 0;

	double result = get_price(dp, P, N);

	fout << fixed << setprecision(1) << result << endl;


	fin.close();
	fout.close();
	return 0;
}
