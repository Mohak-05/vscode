#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <string>

using namespace std;

//class created(called emp) to store the employee details
class Emp {
public:
    int id;
    string nm;
    string dept;
    float sal;
//constructor to initialize the employee details
    Emp(int i, const string& n, const string& d, float s)
        : id(i), nm(n), dept(d), sal(s) {}
//overloading the < operator to compare the employee id
    bool operator<(const Emp& o) const {
        return id < o.id;
    }
};
//function to sort the employee details
void sSort(vector<Emp>& a) {
    for (size_t i = 0; i < a.size() - 1; ++i) {
        size_t m = i;
        for (size_t j = i + 1; j < a.size(); ++j) {
            if (a[j].id < a[m].id) {
                m = j;
            }
        }
        if (m != i) {
            swap(a[i], a[m]);
        }
    }
}
//function to read the employee details from the file
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
//function to write the sorted employee details to the file
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
    //file paths for the input and output files 
    string rF = "../random_numbers.txt";
    string aF = "../ascending_numbers.txt";
    string dF = "../descending_numbers.txt";
    string oF = "sorted_output.txt";

    vector<Emp> d1 = rFile(rF);
    //start time for the random case
    auto s1 = chrono::high_resolution_clock::now();
    sSort(d1);
    auto e1 = chrono::high_resolution_clock::now();
    //end time for the random case
    chrono::duration<double, milli> dur1 = e1 - s1;
    printf("Random case took %.3f ms to sort.\n", dur1.count());

    vector<Emp> d2 = rFile(aF);
    //start time for the ascending case
    auto s2 = chrono::high_resolution_clock::now();
    sSort(d2);
    auto e2 = chrono::high_resolution_clock::now();
    //end time for the ascending case
    chrono::duration<double, milli> dur2 = e2 - s2;
    printf("Ascending case took %.3f ms to sort.\n", dur2.count());

    vector<Emp> d3 = rFile(dF);
    //start time for the descending case
    auto s3 = chrono::high_resolution_clock::now();
    sSort(d3);
    auto e3 = chrono::high_resolution_clock::now();
    //end time for the descending case
    chrono::duration<double, milli> dur3 = e3 - s3;
    printf("Descending case took %.3f ms to sort.\n", dur3.count());

    wFile(oF, d1);
    printf("Sorted data written to '%s'.\n", oF.c_str());

    return 0;
}
