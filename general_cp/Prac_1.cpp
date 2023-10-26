#include <bits/stdc++.h>
using namespace std;

// Returns length of smallest subarray with sum greater than x.
// If there is no subarray with given sum, then returns n+1
int  smallest(vector<int>&arr,int sum)
{   int i,j,c;
    int n=arr.size();
    int minEle = INT_MAX;
    int ans=INT_MAX;
 
    // Find minimum element in the array
    for (i = 0; i < n; i++)
        minEle = min(arr[i], minEle);
 
    // Initialize curr_sum as value of first element
    // and starting point as 0
    int curr_sum = arr[0] + abs(minEle), start = 0;
 
    // Starting window length will be 1,
    // For generating new target sum,
    // add abs(minEle) to sum only 1 time
    int targetSum = sum;
 
    // Add elements one by one to curr_sum
    // and if the curr_sum exceeds the
    // updated sum, then remove starting element
    for (i = 1; i <= n; i++) {
 
        // If curr_sum exceeds the sum,
        // then remove the starting elements
        while (curr_sum - (i - start) * abs(minEle) > targetSum && start < i) {
            curr_sum = curr_sum - arr[start] - abs(minEle);
            start++;
        }
 
        // If curr_sum becomes equal to sum, then return true
        if (curr_sum - (i - start) * abs(minEle) >= targetSum) {
            //cout << "Sum found between indexes " << start << " and " << i - 1;
            ans=min(ans,i-start);
            //return;
        }
 
        // Add this element to curr_sum
        if (i < n) {
            curr_sum = curr_sum + arr[i] + abs(minEle);
        }
    }
 
    // If we reach here, then no subarray
    return ans==INT_MAX?-1:ans;
}

/* Driver program to test above function */
int main()
{
	int n,i,j;
    cin>>n;
    vector<int>arr(n);
    for(i=0;i<n;i++)
        cin>>arr[i];
    cin>>j;
    cout<<smallest(arr,j);
	return 0;
}
