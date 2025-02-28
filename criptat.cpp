#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>

const int MAX_LENGTH = 10000;
const int ALPHA = 26;

using namespace std;

ifstream fin("criptat.in");
ofstream fout("criptat.out");

int main() {
	int n;
	fin >> n;

	vector<string> words(n);
	vector<vector<int>> word_freq(n, vector<int>(ALPHA, 0));
	vector<vector<int>> dp(ALPHA, vector<int>(MAX_LENGTH, 0));
	int total_length = 0;

	for (int i = 0; i < n; ++i) {
		fin >> words[i];
		for (char c : words[i]) {
			// count the frequency of each letter in each word
		    word_freq[i][c - 'a']++;
		}
		total_length += words[i].length();
	}

	for (int i = 0; i < n; ++i) {
		int word_length = words[i].size();
		for (int c = 0; c < ALPHA; ++c) {
			// check each letter in the alphabet for the given words
			int freq = word_freq[i][c];
			if (freq == 0)
				continue;

			// create passwords as long as possible
			for (int len = total_length; len >= 0; --len) {
			    if (len >= word_length)
					// check if the added words results in a greater password
			        dp[c][len] = max(dp[c][len], dp[c][len - word_length] +
									freq);
			}
		}
	}

	int max_len = 0;
	for (int len = 1; len <= total_length; ++len) {
		for (int c = 0; c < ALPHA; ++c) {
			// check if the frequency meets the desired condition
			if (dp[c][len] > len / 2) {
				// get the maximum possible length of the password
				max_len = max(max_len, len);
				break;
			}
		}
	}

	fout << max_len << endl;

	return 0;
}
