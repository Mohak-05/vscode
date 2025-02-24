#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <string>

using namespace std;

void merge(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    merge(arr, left, mid);
    merge(arr, mid + 1, right);
    
    vector<int> temp;
    int i = left, j = mid + 1;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }
    while (i <= mid) {
        temp.push_back(arr[i++]);
    }
    while (j <= right) {
        temp.push_back(arr[j++]);
    }
    for (int i = 0; i < temp.size(); ++i) {
        arr[left + i] = temp[i];
    }
}

void mergeSort(vector<int>& arr) {
    merge(arr, 0, arr.size() - 1);
}


vector<int> readFile(const string& filename) {
    vector<int> numbers;
    ifstream file(filename);
    if (file.is_open()) {
        int number;
        while (file >> number) {
            numbers.push_back(number);
        }
        file.close();
    } else {
        cerr << "Error: Could not open file " << filename << endl;
    }
    return numbers;
}

int main() {

    string randomFile = "../random_numbers.txt";

    vector<int> data = readFile(randomFile);

    auto start = chrono::high_resolution_clock::now();

    mergeSort(data);

    auto stop = chrono::high_resolution_clock::now();
    
    chrono::duration<double, milli> duration = stop - start;
    printf("Average (Random) case took %.3f ms to sort.\n", duration.count());

    return 0;
}