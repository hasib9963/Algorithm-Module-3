#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7; // Maximum size of the array
int a[N];              // Array to be searched

// Binary search function to find the index of target value k
int binary_search(int a[], int n, int k)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] == k)
        {
            return mid; // Target value found
        }
        else if (a[mid] < k)
        {
            low = mid + 1; // Search in the right half
        }
        else
        {
            high = mid - 1; // Search in the left half
        }
    }

    return -1; // Target value not found
}

int main()
{
    int n;
    cin >> n; // Read the number of elements

    for (int i = 0; i < n; i++)
    {
        cin >> a[i]; // Read the elements of the array
    }

    int k;
    cin >> k; // Read the target value

    int index = binary_search(a, n, k); // Perform binary search

    if (index == -1)
    {
        cout << "Not Found" << endl; // Target value not found
    }
    else
    {
        cout << "Found at index" << " " << index << endl; // Print the index of the target value
    }

    return 0;
}
