#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "testing.h"

using namespace std;

vector<int> merge(vector<int>& arr1, vector<int>& arr2) {
    int counter1 = 0;
    int counter2 = 0;
    vector<int> arrRes(arr1.size() + arr2.size());
    for (int i = 0; i < arrRes.size(); ++i) {
        if (counter1 == arr1.size()) {
            arrRes[i] = arr2[counter2];
            ++counter2;
        }
        else if (counter2 == arr2.size()) {
            arrRes[i] = arr1[counter1];
            ++counter1;
        }
        else if (arr1[counter1] <= arr2[counter2]) {
            arrRes[i] = arr1[counter1];
            ++counter1;
        }
        else {
            arrRes[i] = arr2[counter2];
            ++counter2;
        }
    }

    return arrRes;
}

vector<int> mergeSort(vector<int>& arr, int left, int right, ostream& output) {
    vector<int> res;
    if (right - left == 1) {
        res.resize(1);
        res[0] = arr[left];
        return res;
    }

    int middle = (left + right) / 2;
    vector<int> leftPart = mergeSort(arr, left, middle, output);
    vector<int> rightPart = mergeSort(arr, middle, right, output);

    res = merge(leftPart, rightPart);

    output << left + 1 << " " << right << " " << res[0] << " " << res[res.size() - 1] << endl;

    return res;
}

void merge_sort_task(istream& input = cin, ostream& output = cout) {
    int n;
    input >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        input >> arr[i];

    arr = mergeSort(arr, 0, n, output);
    for (int i = 0; i < n; ++i)
        output << arr[i] << " ";
}

int main() {
    
	testing(merge_sort_task, 6);

	return 0;
}