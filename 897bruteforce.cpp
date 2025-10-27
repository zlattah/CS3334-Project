#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

void f(string line) {
    istringstream ss(line);
    vector<int> arr;
    int num;

    while (ss >> num) {
        arr.push_back(num);
    }

    if (arr.empty()) {
        cout << "0" << endl;
        return;
    }

    vector<int> repetitions(arr.size());

    for (int i = 0; i < arr.size(); i++) {
        for (int j=0;j<arr.size();j++){
            if (arr[j] == arr[i])
                repetitions[i]++;
        }
    }

    int maksrep = repetitions[0];
    int maksel = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (repetitions[i] > maksrep) {
            maksrep = repetitions[i];
            maksel = arr[i]; 
        }
    }

    cout << maksel << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string line;
    while (getline(cin, line)) {
        f(line);
    }
    return 0;
} 