// Arul has a binary array∗
//  𝑎
//  of length 𝑛
// .

// He will take all subsequences†
//  of length 𝑘
//  (𝑘
//  is odd) of this array and find their median.‡
// What is the sum of all these values?

// As this sum can be very large, output it modulo 109+7
// . In other words, print the remainder of this sum when divided by 109+7
// .

// ∗
// A binary array is an array consisting only of zeros and ones.

// †
// An array 𝑏
//  is a subsequence of an array 𝑎
//  if 𝑏
//  can be obtained from 𝑎
//  by the deletion of several (possibly, zero or all) elements. Subsequences don't have to be contiguous.

// ‡
// The median of an array of odd length 𝑘
//  is the 𝑘+12
// -th element when sorted.

// Input
// The first line contains a single integer 𝑡
//  (1≤𝑡≤104
// ) — the number of test cases.

// The first line of each test case contains two integers 𝑛
//  and 𝑘
//  (1≤𝑘≤𝑛≤2⋅105
// , 𝑘
//  is odd) — the length of the array and the length of the subsequence, respectively.

// The second line of each test case contains 𝑛
//  integers 𝑎𝑖
//  (0≤𝑎𝑖≤1
// ) — the elements of the array.

// It is guaranteed that sum of 𝑛
//  over all test cases does not exceed 2⋅105
// .

// Output
// For each test case, print the sum modulo 109+7
// .

// Example
// Input
// 8
// 4 3
// 1 0 0 1
// 5 1
// 1 1 1 1 1
// 5 5
// 0 1 0 1 0
// 6 3
// 1 0 1 0 1 1
// 4 3
// 1 0 1 1
// 5 3
// 1 0 1 1 0
// 2 1
// 0 0
// 34 17
// 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
// Output
// 2
// 5
// 0
// 16
// 4
// 7
// 0
// 333606206
// Note
// In the first test case, there are four subsequences of [1,0,0,1]
//  with length 𝑘=3
// :

// [1,0,0]
// : median =0
// .
// [1,0,1]
// : median =1
// .
// [1,0,1]
// : median =1
// .
// [0,0,1]
// : median =0
// .
// The sum of the results is 0+1+1+0=2
// .
// In the second test case, all subsequences of length 1
//  have median 1
// , so the answer is 5
// .

//The solution gave memory Limit Exceeded.

#include<iostream>
#include<vector>
using namespace std;
 
void makeArr(vector<int>&binArr,int index,int n,int currStorage,int k,int zeroes,vector<int >&storage){
    if(currStorage==k){
        storage.push_back(zeroes);
        return;
    }
    if(index==n)return;
    if(binArr[index]==1){
        makeArr(binArr,index+1,n,currStorage+1,k,zeroes,storage);
    }
    else{
        makeArr(binArr,index+1,n,currStorage+1,k,zeroes+1,storage);
    }  
    makeArr(binArr,index+1,n,currStorage,k,zeroes,storage);  
}
 
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>binArr(n);
        for(int i=0;i<n;i++){
            cin>>binArr[i];
        }
        vector<int>storage;
        makeArr(binArr,0,n,0,k,0,storage);
        int pos=(k+1)/2;
        long ans=0;
        int mod=1e9+7;
        for(auto it:storage){
            if(it<pos)ans++;
            ans%=mod;
        }
        cout<<ans<<endl;
    }
return 0;
}
