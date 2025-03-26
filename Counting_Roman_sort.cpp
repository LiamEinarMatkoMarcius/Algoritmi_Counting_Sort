#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool Branje_Stevil(vector<int>& vec, const char s[]) {
	ifstream input(s);
	int st;

	if (!input.is_open()) {
		return false;
	}

	while (!input.eof()) {
		input >> st;
		vec.push_back(st);
		while (isspace(input.peek())) input.get();
	}
	input.close();
	return true;
}

void Izpis_Stevil(int* polje, unsigned int velikost) {
	ofstream output("out.txt");

	for (int i = 0; i < velikost; i++)
		output << polje[i] << ' ';
}
int main(int argc, const char* argv[]) {
	vector<int> A;

	if (argc < 3) return 0;
	if (!Branje_Stevil(A, argv[2])) return 0;

	if (argv[1][0] == '0') {
		//counting sort
        int minValue = *min_element(A.begin(), A.end());
        int maxValue = *max_element(A.begin(), A.end());
        for (int i = 0; i < A.size(); i++) {
        	A[i] = A[i] - minValue;
        }
        int sizeC = maxValue - minValue + 1;
        int* C = new int[sizeC]();
        for (int i : A) {
        	C[i]++;
        }
        for (int i = 1; i < sizeC; i++) {
        	C[i] += C[i - 1];
        }
        vector<int> B(A.size(), 0);
        for (int i = A.size() - 1; i >= 0; i--) {
        	B[C[A[i]] - 1] = A[i] + minValue;
        	C[A[i]]--;
        }
        A = B;
        cout << "A is " << (is_sorted(A.begin(), A.end()) ? "sorted" : "not sorted") << endl;
            
	}
	else {
		//Roman sort
	}
	
	Izpis_Stevil(&A[0], A.size());

	return 0;
}
