#include <bits/stdc++.h>
using namespace std;

// Function to find the first occurrence of k in array a
int first_half(int a[], int n, int k) {
    int l = 0;
    int r = n - 1;
    int result = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] == k) {
            result = mid; // Update result
            r = mid - 1; // Search in the left half
        } else if (a[mid] > k) {
            r = mid - 1; // Search in the left half
        } else {
            l = mid + 1; // Search in the right half
        }
    }
    return result; // Return the first occurrence index
}

// Function to find the last occurrence of k in array a
int last_half(int a[], int n, int k) {
    int l = 0;
    int r = n - 1;
    int result = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] == k) {
            result = mid; // Update result
            l = mid + 1; // Search in the right half
        } else if (a[mid] > k) {
            r = mid - 1; // Search in the left half
        } else {
            l = mid + 1; // Search in the right half
        }
    }
    return result; // Return the last occurrence index
}

int main() {
    int n;
    cin >> n; // Read the number of elements
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i]; // Read the elements of the array
    }
    int k;
    cin >> k; // Read the target value
    int first = first_half(a, n, k); // Find the first occurrence of k
    int last = last_half(a, n, k); // Find the last occurrence of k
    if (first != last) {
        cout << "YES" << endl; // Multiple occurrences found
    } else {
        cout << "NO" << endl; // No multiple occurrences found
    }
    return 0;
}
