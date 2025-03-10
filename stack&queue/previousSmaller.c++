#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int sumOfPreviousSmaller(vector<int>& arr) {
    int n = arr.size();
    stack<int> st; 
    int sum = 0;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }
        
        if (!st.empty()) {
            sum += st.top();
        }else sum+=-1;
        
        st.push(arr[i]);
    }
    return sum;
}

int main() {
    vector<int> arr = {4, 2,1, 1, 5, 3};
    cout << "Sum of previous smaller elements: " << sumOfPreviousSmaller(arr) << endl;
    return 0;
}