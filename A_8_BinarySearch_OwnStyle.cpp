#include <bits/stdc++.h>
using namespace std;

bool BinarySearchHelper(int arr[], int left, int right, int x){
    int middle = (left + right)/2;
    if(x == arr[middle]){
        return true;
    }
    else if(x < arr[middle]){
        BinarySearchHelper(arr, left, middle, x);
    }
    else{
        BinarySearchHelper(arr, middle, right, x);
    }
        return false;
}

bool BinarySearch(int arr[], int n, int x){
    return BinarySearchHelper(arr, 0, n, x);
}

int main(){
    int n, x;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << "Enter the element to search: ";
    cin >> x;

    if(BinarySearch(arr, n-1, x)){
        cout << "Element found!" << "\n";
    }
    else {
        cout << "Element not found!" << "\n";
    }
}
