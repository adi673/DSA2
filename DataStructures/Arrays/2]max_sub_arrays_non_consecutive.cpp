//https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=longest-sub-array-with-sum-k
#include <iostream>
#include<bits/stdc++.h> 
using namespace std;

 int find_len(int A[], int N, int K, int len, int i,vector<int> v){
    //  cout<< "*********k value is :"<<K<<endl;
     if(K==0){
        for(int i: v ){
            cout<<i<<" ";
        }
        cout<<endl;
            return len;
        }
        if(i==N){
           if(K==0){
               for(int i: v ){
                cout<<i<<" ";
               }
               cout<<endl;
               return len;
           }
           return 0;
        }
        // cout<< "value of i is: "<<i<<endl;
        int len1=find_len(A,N,K,len,i+1,v);
        // cout<< "value of len1 is: "<<len1<<endl;
        v.push_back(A[i]);
        int len2=find_len(A,N,K-A[i],len+1,i+1,v);
        // cout<< "value of len2 is: "<<len2<<endl;
        if(len1>len2){
            // cout<< "**************************returning : "<<len1<<endl;
            return len1;
        }else{
            // cout<< "**************************returning : "<<len2<<endl;
            return len2;
        }
    }
    
    int lenOfLongSubarr(int A[],  int N, int K,vector<int> v) 
    { 
        int len=0;
        int i=0;
        len=find_len(A,N,K,len,i,v);
        
        return len;
    } 

int main() {
   
   int  A[] = {-7 ,-11, -3 ,-7, 4, 15, -13, 18 ,-10,-10};
    int K = 15;
    vector<int> v;
    int len=lenOfLongSubarr(A, 10, K,v);
    cout<<" Length is : "<<len<<endl;
   
}