// Slavic has a very tough exam and needs your help in order to pass it. Here is the question he is struggling with:

// There exists a string 𝑠
// , which consists of lowercase English letters and possibly zero or more "?".

// Slavic is asked to change each "?" to a lowercase English letter such that string 𝑡
//  becomes a subsequence (not necessarily continuous) of the string 𝑠
// .

// Output any such string, or say that it is impossible in case no string that respects the conditions exists.

// Input
// The first line contains a single integer 𝑇
//  (1≤𝑇≤104
// ) — the number of test cases.

// The first line of each test case contains a single string 𝑠
//  (1≤|𝑠|≤2⋅105
// , and 𝑠
//  consists only of lowercase English letters and "?"-s)  – the original string you have.

// The second line of each test case contains a single string 𝑡
//  (1≤|𝑡|≤|𝑠|
// , and 𝑡
//  consists only of lowercase English letters)  – the string that should be a subsequence of string 𝑠
// .

// The sum of |𝑠|
//  over all test cases doesn't exceed 2⋅105
// , where |𝑥|
//  denotes the length of the string 𝑥
// .

// Output
// For each test case, if no such string exists as described in the statement, output "NO" (without quotes).

// Otherwise, output "YES" (without quotes). Then, output one line — the string that respects all conditions.

// You can output "YES" and "NO" in any case (for example, strings "yEs", "yes", and "Yes" will be recognized as a positive response).

// If multiple answers are possible, you can output any of them.

// Example
// Input
// 5
// ?????
// xbx
// ab??e
// abcde
// ayy?x
// a
// ab??e
// dac
// paiu
// mom
// Output
// YES
// xabax
// YES
// abcde
// YES
// ayyyx
// NO
// NO


#include<iostream>
using namespace std;
 
int main(){
    int tc;
    cin>>tc;
    while(tc--){
        string s,t;
        cin>>s;
        cin>>t;
        int size1=s.size();
        int size2=t.size();
        int left=0;
        int right=0;
        while(left<size1 && right<size2){
            if(s[left]=='?' || s[left]==t[right]){
                s[left]=t[right];
                left++;
                right++;
            }
            else if(s[left]!=t[right]){
                left++;
            }
        }
        if(right>=size2){
            while(left<size1){
                if(s[left]=='?'){
                    s[left]='a';
                }
                left++;
            }
            cout<<"YES"<<endl;
            cout<<s<<endl;
        }
        else if(left>=size1){
            cout<<"NO"<<endl;
        }
    }
return 0;
}
