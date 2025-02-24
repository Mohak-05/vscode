#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <string>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortHelper(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}

void quickSort(vector<int>& arr) {
    quickSortHelper(arr, 0, arr.size() - 1);
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

    quickSort(data);

    auto stop = chrono::high_resolution_clock::now();
    
    chrono::duration<double, milli> duration = stop - start;
    printf("Average (Random) case took %.3f ms to sort.\n", duration.count());

    return 0;
}
