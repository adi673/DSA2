#include <iostream>
#include<bits/stdc++.h> 
using namespace std;

int lenOfLongSubarr(int a[],  int n, int k) 
{ 
    int left = 0, right = 0; // 2 pointers
    long long sum = a[0];
    int maxLen = 0;
    while (right < n) {
        // if sum > k, reduce the subarray from left
        // until sum becomes less or equal to k:
        cout<<"Removing: ";
        while (left <= right && sum > k) {
            cout<<a[left]<<" ";
            sum -= a[left];
            left++;
        }
        cout<<endl;
        // if sum = k, update the maxLen i.e. answer:
        if (sum == k) {
            cout<<"got the sum "<<endl;
            maxLen = max(maxLen, right - left + 1);
        }

        // Move forward thw right pointer:
        right++;
        cout<<"adding "<<a[right]<<endl;
        if (right < n) sum += a[right];
    }

    return maxLen;
} 

int main() {
   int  A[] = {-13, 0 ,6, 15, 16, 2, 15, -12 ,17 ,-16, 0, -3, 19, -3 ,2, -9, -6};
    int K = 15;
    cout<<"giving call: adding -13"<<endl;
    int len=lenOfLongSubarr(A, 17, K);
    cout<<" Length is : "<<len<<endl;
   
}