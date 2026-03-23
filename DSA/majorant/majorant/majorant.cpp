#include <vector>
#include <iostream>
using namespace std;
int swaps;

void alg(vector<int>& arr) {
    vector<int> cnt;
    int m;
    int c = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (c == 0) {
            m = arr[i];
            c = 1;
        }
        else if (arr[i] == m) c++;
        else c--;
    }

    int count = 0;
    for (int i = 0; i < arr.size(); i++) 
        if (arr[i] == m) count++;
     
    if (count >= arr.size() / 2) cout << m << endl;
    else cout << "No majoring element i the array.\n";
    return;
}

void f() {
    int r = 9;
    while (r != -99) {
        cout << "Enter array size: ";
        vector<int> arr;
        int n;
        cin >> n;
        int x;
        for (int i = 0; i < n; i++) {
            cin >> x;
            arr.push_back(x);
        }
        alg(arr);
        cout << "Enter -99 to quit.\n";
        cin >> r;
    }
}


int dsort(vector<int>& arr, int i) {
    if (i == arr.size() - 1) {
        for (int j = 1; j < arr.size(); j++) {
            if (arr[j - 1] > arr[j]) return 0;
        }
        return 1;
    }
    else {
        for (int j = i; j < arr.size(); j++) {
            swap(arr[i], arr[j]);
            swaps++;
            if (dsort(arr, i + 1)) return 1;
            else {
                swaps++;
                swap(arr[i], arr[j]);
            }
        }
    }
    return 0;
}

void print(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int r = 9;
    while (r != -99) {
        cout << "Enter array size: ";
        vector<int> arr;
        int n;
        cin >> n;
        int x;
        for (int i = 0; i < n; i++) {
            cin >> x;
            arr.push_back(x);
        }
        dsort(arr, 0);
        print(arr);
        cout << "Swaps: "<< swaps << endl;
        swaps = 0;
        cout << "Enter -99 to quit.\n";
        cin >> r;
    }
    

    return 0;
}
