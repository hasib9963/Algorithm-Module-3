#include <bits/stdc++.h>
using namespace std;

// Function to merge two sorted arrays into a single sorted array in descending order
void solve(int a1[], int a2[], int n, int m, int result[]) {
    int x = 0, y = 0, k = 0;

    // Merge elements from both arrays in descending order
    while (x < n && y < m) {
        if (a1[x] > a2[y]) {
            result[k++] = a1[x++];
        } else {
            result[k++] = a2[y++];
        }
    }

    // Append remaining elements from the first array (if any)
    while (x < n) {
        result[k++] = a1[x++];
    }

    // Append remaining elements from the second array (if any)
    while (y < m) {
        result[k++] = a2[y++];
    }
}

int main() {
    int n, m;
    cin >> n; // Read the size of the first array
    int a1[n];
    for (int i = 0; i < n; i++) {
        cin >> a1[i]; // Read elements of the first array
    }
    cin >> m; // Read the size of the second array
    int a2[m];
    for (int i = 0; i < m; i++) {
        cin >> a2[i]; // Read elements of the second array
    }
    int result[n + m]; // Array to store the merged result
    solve(a1, a2, n, m, result); // Merge the arrays
    for (int i = 0; i < n + m; i++) {
        cout << result[i] << " "; // Print the merged array
    }
    return 0;
}
