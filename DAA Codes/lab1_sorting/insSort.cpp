#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <string>

using namespace std;

void insertionSort(vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
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

    vector<int> data1 = readFile(randomFile);

    auto start1 = chrono::high_resolution_clock::now();

    insertionSort(data1);

    auto stop1 = chrono::high_resolution_clock::now();
    
    chrono::duration<double, milli> duration1 = stop1 - start1;
    printf("Average (Random) case took %.3f ms to sort.\n", duration1.count());

    string ascFile = "../ascending_numbers.txt";

    vector<int> data2 = readFile(ascFile);

    auto start2 = chrono::high_resolution_clock::now();

    insertionSort(data2);

    auto stop2 = chrono::high_resolution_clock::now();
    
    chrono::duration<double, milli> duration2 = stop2 - start2;
    printf("Ascending case took %.3f ms to sort.\n", duration2.count());

    string descFile = "../descending_numbers.txt";

    vector<int> data3 = readFile(descFile);

    auto start3 = chrono::high_resolution_clock::now();

    insertionSort(data3);

    auto stop3 = chrono::high_resolution_clock::now();
    
    chrono::duration<double, milli> duration3 = stop3 - start3;
    printf("Descending case took %.3f ms to sort.\n", duration3.count());

    return 0;
}
