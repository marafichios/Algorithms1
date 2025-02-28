#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iomanip>

using namespace std;

int compress(int* partial_sum_A, int* partial_sum_B, int n, int m) {
	int equal_sums = 0;
	int i, j;

	// iterate through the partial sums
	for (i = 1, j = 1; i < n && j < m; ) {
		// if the partial sums are equal, it means there is a valid compression
		if (partial_sum_A[i] == partial_sum_B[j]) {
			i++;
			j++;
			equal_sums++;
		} else if (partial_sum_A[i] < partial_sum_B[j]) {
			i++;
		} else {
			j++;
		}
	}

	return equal_sums;
}


int main() {
	ifstream fin("compresie.in");
	ofstream fout("compresie.out");

	int n, m;

	fin >> n;
	vector<int> A(n);

	for (int i = 0; i < n; i++)
		fin >> A[i];

	fin >> m;
	vector<int> B(m);

	for (int i = 0; i < m; i++)
		fin >> B[i];

	int partial_sum_A[n + 1], partial_sum_B[m + 1];
	partial_sum_A[0] = 0;
	partial_sum_B[0] = 0;

	// calculate the partial sums
	for (int i = 1; i <= n; i++)
		partial_sum_A[i] = partial_sum_A[i - 1] + A[i - 1];

	for (int i = 1; i <= m; i++)
		partial_sum_B[i] = partial_sum_B[i - 1] + B[i - 1];

	int result = compress(partial_sum_A, partial_sum_B, n + 1, m + 1);

	// no valid compression
	if (partial_sum_A[n] != partial_sum_B[m])
		fout << -1 << "\n";

	fout << result << "\n";

	fin.close();
	fout.close();

	return 0;
}
