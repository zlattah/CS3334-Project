#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
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

    unordered_map<int, int> hash;
    for (int i = 0; i < arr.size(); i++)
        hash[arr[i]]++;

    int maksrep = -1;
    int maksel = 0;
    for(int i=0;i<arr.size();i++){
        if (maksrep<hash[arr[i]]){
            maksrep = hash[arr[i]];
            maksel = arr[i];
        }
    }
    cout<<maksel<<endl;
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
    
    