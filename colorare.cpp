#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iomanip>

using namespace std;

struct Rectangle {
	size_t number;
	char type;
};

struct Final_power {
	size_t power_of_2 = 0;
	size_t power_of_3 = 0;
};

#define MODULO 1000000007

// used the function from the lab solutions
size_t power(size_t number, size_t power) {
	if (!power)
		return 1;

	int aux = 1;
	while (power != 1) {
		if (power % 2 == 0) {
			number = (1LL * number * number) % MODULO;
			power /= 2;
		} else {
			aux = (1LL * aux * number) % MODULO;
			power--;
		}
	}

	return (1LL * aux * number) % MODULO;
}

size_t final_result(vector<Rectangle> rectangles) {
	size_t result = 1;
	size_t i;
	vector<Final_power> final_powers(rectangles.size());

	if (rectangles[0].type == 'H') {
		// compute the first element of the final_powers vector
		final_powers[0].power_of_2 = 1;
		final_powers[0].power_of_3 = rectangles[0].number;
	} else {
		final_powers[0].power_of_2 = rectangles[0].number - 1;
		final_powers[0].power_of_3 = 1;
	}

	for (i = 1; i < rectangles.size(); i++) {
		if (rectangles[i].type == 'H') {
			// compute the rest of the elements of the final_powers vector
			// use the discovered formula (readme.md)
			final_powers[i].power_of_2 = final_powers[i - 1].power_of_2 + 1;
			final_powers[i].power_of_3 = final_powers[i - 1].power_of_3 +
										rectangles[i].number;
		} else {
			final_powers[i].power_of_2 = final_powers[i - 1].power_of_2 +
										rectangles[i].number - 1;
			final_powers[i].power_of_3 = final_powers[i - 1].power_of_3 + 1;
		}
	}

	final_powers[rectangles.size() - 1].power_of_3 -= (rectangles.size() - 1);

	// use MODULO to avoid overflow
	result = ((power(2, final_powers[rectangles.size() - 1].power_of_2) % MODULO)
	* (power(3, final_powers[rectangles.size() - 1].power_of_3) % MODULO)) %
	MODULO;

	return result % MODULO;
}

// compress the rectangles that have the same type
void compress_same_zone(vector<Rectangle> &rectangles) {
	vector<Rectangle> new_rectangles(rectangles.size());
	int index = 0;
	new_rectangles[index] = rectangles[0];
	size_t i;
	for (i = 1; i < rectangles.size(); i++) {
		if (rectangles[i].type == new_rectangles[index].type) {
			new_rectangles[index].number += rectangles[i].number;
		} else {
			index++;
			new_rectangles[index] = rectangles[i];
		}
	}

	rectangles = vector<Rectangle>(new_rectangles.begin(),
				new_rectangles.begin() + index + 1);
}

int main() {
	ifstream fin("colorare.in");
	ofstream fout("colorare.out");

	int n;
	fin >> n;
	vector<Rectangle> rectangles(n);

	for (int i = 0; i < n; i++)
		fin >> rectangles[i].number >> rectangles[i].type;

	compress_same_zone(rectangles);

	fout << final_result(rectangles) << endl;
	return 0;
}
