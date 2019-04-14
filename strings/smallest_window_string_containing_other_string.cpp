//https://www.geeksforgeeks.org/find-the-smallest-window-in-a-string-containing-all-characters-of-another-string/
//Given two strings string1 and string2, the task is to find the smallest substring in string1 containing all characters of string2 efficiently.

//Examples:

//Input: string = “this is a test string”, pattern = “tist”
//Output: Minimum window is “t stri”
//Explanation: “t stri” contains all the characters of pattern.
//
//Input: string = “geeksforgeeks”, pattern = “ork”
//Output: Minimum window is “ksfor”

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int main(){
    cout<<"enter\n";
    string str, pattern;
    getline(cin, str);
    cin>>pattern;
    vector<int> counts_str(256,0), counts_pat(256,0);
    for(int i=0;i<pattern.size();i++){
        counts_pat[pattern[i]]++;
    }
    int count=0, start=0,w_len, min_len=INT_MAX, min_start=0;
    for(int i=0; i<str.size();i++){
        counts_str[str[i]]++;
        if(counts_str[str[i]]<=counts_pat[str[i]]){
            count++;
        }
        if(count==pattern.size()){
            while(counts_str[str[start]]>counts_pat[str[start]]){
                counts_str[str[start]]--;
                start++;
            }
            w_len=i-start+1;
            if(w_len<min_len){
                min_len=w_len;
                min_start=start;
            }
        }
    }
    cout<<"window length="<<min_len<<endl;
    cout<<"window string="<<str.substr(min_start,min_len)<<endl;
}

