// C++ implementation of the subsequences of the array and compute the product of all the subsequences. 
#include <bits/stdc++.h>
using namespace std;

// Function to return the count of all
// the subsequences with positive product
int cntSubSeq(int arr[], int n)
{
	// To store the count of positive
	// elements in the array
	int pos_count = 0;

	// To store the count of negative
	// elements in the array
	int neg_count = 0;

	int result;

	for (int i = 0; i < n; i++) {

		// If the current element
		// is positive
		if (arr[i] > 0)
			pos_count++;

		// If the current element
		// is negative
		if (arr[i] < 0)
			neg_count++;
	}

	// For all the positive
	// elements of the array
	result = pow(2, pos_count);

	// For all the negative
	// elements of the array
	if (neg_count > 0)
		result *= pow(2, neg_count - 1);

	// For the empty subsequence
	result -= 1;

	return result;
}

// Driver code
int main()
{
	int arr[] = { 2, -3, -1, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << cntSubSeq(arr, n);

	return 0;
}
