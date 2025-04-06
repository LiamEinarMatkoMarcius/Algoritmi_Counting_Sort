#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main(int argc, const char* argv[]) {
    if (argc < 3) {
        cerr << "Usage: ./your_program <0|1> <list of integers>" << endl;
        return 1;
    }

    vector<int> A;
    for (int i = 2; i < argc; ++i) {
        A.push_back(atoi(argv[i]));
    }

    int minValue = *min_element(A.begin(), A.end());
    int maxValue = *max_element(A.begin(), A.end());
    for (int i = 0; i < A.size(); i++) {
        A[i] -= minValue;
    }
    int sizeC = maxValue - minValue + 1;
    int* C = new int[sizeC]();
    for (int i : A) {
        C[i]++;
    }

    if (argv[1][0] == '0') {
        // Counting Sort
        for (int i = 1; i < sizeC; i++) {
            C[i] += C[i - 1];
        }
        vector<int> B(A.size(), 0);
        for (int i = A.size() - 1; i >= 0; i--) {
            B[C[A[i]] - 1] = A[i] + minValue;
            C[A[i]]--;
        }
        A = B;
    } else {
        // Roman Sort
        vector<int> B;
        for (int i = 0; i < sizeC; i++) {
            for (int j = 0; j < C[i]; j++) {
                B.push_back(i + minValue);
            }
        }
        A = B;
    }

    delete[] C;

    for (int x : A) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
