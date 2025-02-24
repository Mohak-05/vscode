// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <chrono>
// #include <string>

// using namespace std;

// //class created(called emp) to store the employee details
// class Emp {
// public:
//     int id;
//     string nm;
//     string dept;
//     float sal;
// //constructor to initialize the employee details
//     Emp(int i, const string& n, const string& d, float s)
//         : id(i), nm(n), dept(d), sal(s) {}
// //overloading the < operator to compare the employee id
//     bool operator<(const Emp& o) const {
//         return id < o.id;
//     }
// };
// //function to partition the employee details for quicksort
// int partition(vector<Emp>& a, int low, int high) {
//     Emp pivot = a[high];
//     int i = low - 1;
//     for (int j = low; j < high; ++j) {
//         if (a[j].id < pivot.id) {
//             ++i;
//             swap(a[i], a[j]);
//         }
//     }
//     swap(a[i + 1], a[high]);
//     return i + 1;
// }
// //function to sort the employee details using quicksort
// void qSort(vector<Emp>& a, int low, int high) {
//     if (low < high) {
//         int pi = partition(a, low, high);
//         qSort(a, low, pi - 1);
//         qSort(a, pi + 1, high);
//     }
// }
// //function to read the employee details from the file
// vector<Emp> rFile(const string& fn) {
//     vector<Emp> e;
//     ifstream f(fn);
//     if (f.is_open()) {
//         string l;
//         while (getline(f, l)) {
//             if (l.find("Employee ID:") != string::npos) {
//                 int id = stoi(l.substr(l.find(":") + 1));

//                 getline(f, l);
//                 string nm = l.substr(l.find(":") + 2);

//                 getline(f, l);
//                 string d = l.substr(l.find(":") + 2);

//                 getline(f, l);
//                 float s = stof(l.substr(l.find(":") + 1));

//                 e.emplace_back(id, nm, d, s);

//                 getline(f, l);
//             }
//         }
//         f.close();
//     } else {
//         cerr << "Error: Could not open file " << fn << endl;
//     }
//     return e;
// }
// //function to write the sorted employee details to the file
// void wFile(const string& fn, const vector<Emp>& e) {
//     ofstream f(fn);
//     if (f.is_open()) {
//         for (const auto& x : e) {
//             f << "Employee ID: " << x.id << "\n";
//             f << "Name: " << x.nm << "\n";
//             f << "Department: " << x.dept << "\n";
//             f << "Salary: " << x.sal << "\n";
//             f << "\n";
//         }
//         f.close();
//     } else {
//         cerr << "Error: Could not open file " << fn << endl;
//     }
// }

// int main() {
//     //file paths for the input and output files 
//     string rF = "../random_numbers.txt";
//     string aF = "../ascending_numbers.txt";
//     string dF = "../descending_numbers.txt";
//     string oF = "sorted_output.txt";

//     vector<Emp> d1 = rFile(rF);
//     //start time for the random case
//     auto s1 = chrono::high_resolution_clock::now();
//     qSort(d1, 0, d1.size() - 1);
//     auto e1 = chrono::high_resolution_clock::now();
//     //end time for the random case
//     chrono::duration<double, milli> dur1 = e1 - s1;
//     printf("Random case took %.3f ms to sort.\n", dur1.count());

//     vector<Emp> d2 = rFile(aF);
//     //start time for the ascending case
//     auto s2 = chrono::high_resolution_clock::now();
//     qSort(d2, 0, d2.size() - 1);
//     auto e2 = chrono::high_resolution_clock::now();
//     //end time for the ascending case
//     chrono::duration<double, milli> dur2 = e2 - s2;
//     printf("Ascending case took %.3f ms to sort.\n", dur2.count());

//     vector<Emp> d3 = rFile(dF);
//     //start time for the descending case
//     auto s3 = chrono::high_resolution_clock::now();
//     qSort(d3, 0, d3.size() - 1);
//     auto e3 = chrono::high_resolution_clock::now();
//     //end time for the descending case
//     chrono::duration<double, milli> dur3 = e3 - s3;
//     printf("Descending case took %.3f ms to sort.\n", dur3.count());

//     wFile(oF, d1);
//     printf("Sorted data written to '%s'.\n", oF.c_str());

//     return 0;
// }
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <string>

using namespace std;

// Class to store employee details
class Emp {
public:
    int id;
    string nm;
    string dept;
    float sal;

    // Constructor to initialize employee details
    Emp(int i, const string& n, const string& d, float s)
        : id(i), nm(n), dept(d), sal(s) {}

    // Overloading the < operator to compare employee IDs
    bool operator<(const Emp& o) const {
        return id < o.id;
    }
};

// Partition function for Quicksort
int partition(vector<Emp>& a, int low, int high) {
    Emp pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (a[j].id < pivot.id) {
            ++i;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

// Iterative Quicksort
void iterativeQSort(vector<Emp>& a, int low, int high) {
    vector<pair<int, int>> stack; // Explicit stack to store subarray indices
    stack.push_back({low, high});

    while (!stack.empty()) {
        auto [l, h] = stack.back();
        stack.pop_back();

        if (l < h) {
            int pi = partition(a, l, h);

            // Push subarray indices to stack
            if (pi - 1 > l) {
                stack.push_back({l, pi - 1});
            }
            if (pi + 1 < h) {
                stack.push_back({pi + 1, h});
            }
        }
    }
}

// Function to read employee details from a file
vector<Emp> rFile(const string& fn) {
    vector<Emp> e;
    ifstream f(fn);
    if (f.is_open()) {
        string l;
        while (getline(f, l)) {
            if (l.find("Employee ID:") != string::npos) {
                int id = stoi(l.substr(l.find(":") + 1));

                getline(f, l);
                string nm = l.substr(l.find(":") + 2);

                getline(f, l);
                string d = l.substr(l.find(":") + 2);

                getline(f, l);
                float s = stof(l.substr(l.find(":") + 1));

                e.emplace_back(id, nm, d, s);

                getline(f, l);
            }
        }
        f.close();
    } else {
        cerr << "Error: Could not open file " << fn << endl;
    }
    return e;
}

// Function to write sorted employee details to a file
void wFile(const string& fn, const vector<Emp>& e) {
    ofstream f(fn);
    if (f.is_open()) {
        for (const auto& x : e) {
            f << "Employee ID: " << x.id << "\n";
            f << "Name: " << x.nm << "\n";
            f << "Department: " << x.dept << "\n";
            f << "Salary: " << x.sal << "\n";
            f << "\n";
        }
        f.close();
    } else {
        cerr << "Error: Could not open file " << fn << endl;
    }
}

int main() {
    string rF = "../random_numbers.txt";
    string aF = "../ascending_numbers.txt";
    string dF = "../descending_numbers.txt";
    string oF = "sorted_output.txt";

    vector<Emp> d1 = rFile(rF);
    auto s1 = chrono::high_resolution_clock::now();
    iterativeQSort(d1, 0, d1.size() - 1);
    auto e1 = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> dur1 = e1 - s1;
    printf("Random case took %.3f ms to sort.\n", dur1.count());

    vector<Emp> d2 = rFile(aF);
    auto s2 = chrono::high_resolution_clock::now();
    iterativeQSort(d2, 0, d2.size() - 1);
    auto e2 = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> dur2 = e2 - s2;
    printf("Ascending case took %.3f ms to sort.\n", dur2.count());

    vector<Emp> d3 = rFile(dF);
    auto s3 = chrono::high_resolution_clock::now();
    iterativeQSort(d3, 0, d3.size() - 1);
    auto e3 = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> dur3 = e3 - s3;
    printf("Descending case took %.3f ms to sort.\n", dur3.count());

    wFile(oF, d1);
    printf("Sorted data written to '%s'.\n", oF.c_str());

    return 0;
}
