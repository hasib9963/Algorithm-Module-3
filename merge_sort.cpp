#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7; // Maximum size of the array
int a[N];              // Array to be sorted

// Merge function to merge two sorted subarrays
void merge(int l, int r, int mid)
{
    int left_size = mid - l + 1;
    int L[left_size + 1];
    int right_size = r - mid;
    int R[right_size + 1];

    // Copying elements to temporary left array
    for (int i = l, j = 0; i <= mid; i++, j++)
    {
        L[j] = a[i];
    }

    // Copying elements to temporary right array
    for (int i = mid + 1, j = 0; i <= r; i++, j++)
    {
        R[j] = a[i];
    }

    L[left_size] = INT_MIN;  // Sentinel value
    R[right_size] = INT_MIN; // Sentinel value

    int lp = 0, rp = 0;
    for (int i = l; i <= r; i++)
    {
        if (L[lp] >= R[rp])
        {
            a[i] = L[lp];
            lp++;
        }
        else
        {
            a[i] = R[rp];
            rp++;
        }
    }
}

// Merge sort function to sort the array
void mergesort(int l, int r)
{
    if (l == r)
        return; // Base case: array of size 1
    int mid = (l + r) / 2;
    mergesort(l, mid);     // Sort the left half
    mergesort(mid + 1, r); // Sort the right half
    merge(l, r, mid);      // Merge the sorted halves
}

int main()
{
    int n;
    cin >> n; // Read the number of elements
    for (int i = 0; i < n; i++)
    {
        cin >> a[i]; // Read the elements of the array
    }
    mergesort(0, n - 1); // Sort the array
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " "; // Print the sorted array
    }
    return 0;
}
