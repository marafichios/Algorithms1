#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iomanip>

using namespace std;

double min_power(int N, double current, vector<int> P, vector<int> C) {
	double power;
	double min_power = 1e9;

	// compute the power for each server
	for (int i = 0; i < N; i++) {
		power = P[i] - abs(current - C[i]);
		min_power = min(min_power, power);
	}

	return min_power;
}

int main() {
	ifstream fin("servere.in");
	ofstream fout("servere.out");

	int N;
	fin >> N;
	vector<int> P(N), C(N);

	for (int i = 0; i < N; i++)
		fin >> P[i];

	for (int i = 0; i < N; i++)
		fin >> C[i];

	double mid;
	double left = 1e9;
	double right = -1e9;

	for (int i = 0; i < N; i++) {
		left = min(left, (double)C[i]);
		right = max(right, (double)C[i]);
	}

	double result = -1e9;

	while (right - left > 1e-3) {
		mid = left + (right - left) / 2;

		// find a smaller/ higher power with a precision of 1e-3
		double left_power = min_power(N, mid - 1e-3, P, C);
		double right_power = min_power(N, mid + 1e-3, P, C);

		// search for the maximum power
		if (left_power > right_power) {
			right = mid;
			result = max(result, left_power);
		} else {
			left = mid;
			result = max(result, right_power);
		}
	}



	fout << fixed << setprecision(1) << result << "\n";

	fin.close();
	fout.close();

	return 0;
}
