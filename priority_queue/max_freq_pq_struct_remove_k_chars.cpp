/*https://www.geeksforgeeks.org/minimum-sum-squares-characters-counts-given-string-removing-k-characters/
perm_identity
Minimum sum of squares of character counts in a given string after removing k characters

Given a string of lowercase alphabets and a number k, the task is to print the minimum value of the string after removal of ‘k’ characters. The value of a string is defined as the sum of squares of the count of each distinct character. For example consider the string “saideep”, here frequencies of characters are s-1, a-1, i-1, e-2, d-1, p-1 and value of the string is 1^2 + 1^2 + 1^2 + 1^2 + 1^2 + 2^2 = 9.

Expected Time Complexity : O(n)

Examples:

Input :  str = abccc, K = 1
Output :  6
We remove c to get the value as 12 + 12 + 22

Input :  str = aaab, K = 2
Output :  2
*/

//First Method
//Using vectors - O(k*nlogn)
/*
 * #include <iostream>
#include<unordered_map>
#include <vector>
#include <queue>
using namespace std;
bool comparator(const pair<char, int> &v1, const pair<char, int> &v2){
    return v1.second>v2.second;
}
int main()
{
    string s="abccc";
    vector<int> freq(26,0);
    int k=1, count=0;
    for(int i=0;i<s.size();i++){
        freq[s[i]-'a']++;
    }
    vector<pair<char,int>> v;
    for(int i=0;i<26;i++){
        v.push_back(make_pair(char(i+'a'),freq[i]));
    }
    for(int i=0;i<k;i++){
        sort(v.begin(), v.end(), comparator);
        v[0].second--;
    }
    for(auto c:v){
        count+=(c.second*c.second);
    }
    cout<<count<<endl;    return 0;
}

 */


//Second Method using priority queue
//#include <iostream>
//#include<unordered_map>
//#include <vector>
//#include <queue>
//using namespace std;
//struct Key{
//    char ch;
//    int count;
//    bool operator<(const Key &k) const{
//        return count<k.count;
//    }
//};
//int main(){
//    string s="aaab";
//    vector<int> freq(26,0);
//    int k=2, count=0;
//    for(int i=0;i<s.size();i++){
//        freq[s[i]-'a']++;
//    }
//    priority_queue<Key> pq;
//    for(int i=0;i<26;i++){
//        if(freq[i])
//            pq.push(Key{char(i+'a'),freq[i]});
//    }
//    for(int i=0;!pq.empty()&&i<k;i++){
//        Key key=pq.top();
//        pq.pop();
//        key.count--;
//        if(key.count>0) pq.push(key);
//    }
//    while (!pq.empty()) {
//        Key key=pq.top();
//        pq.pop();
//        cout<<"key="<<key.ch<<"count="<<key.count<<endl;
//        count+=(key.count*key.count);
//    }
//    cout<<count<<endl;
//    return 0;
//}
//
//
//Third - In second method no need of keping the characters along with frequency just the frequency is enough

#include <iostream>
#include<unordered_map>
#include <vector>
#include <queue>
using namespace std;
int main(){
    string s="aaab";
    vector<int> freq(26,0);
    int k=2, count=0;
    for(int i=0;i<s.size();i++){
        freq[s[i]-'a']++;
    }
    priority_queue<int> pq;
    for(int i=0;i<26;i++){
        if(freq[i])
            pq.push(freq[i]);
    }
    for(int i=0;!pq.empty()&&i<k;i++){
        int key=pq.top();
        pq.pop();
        key--;
        if(key>0) pq.push(key);
    }
    while (!pq.empty()) {
        int key=pq.top();
        pq.pop();
        count+=(key*key);
    }
    cout<<count<<endl;
    return 0;
}

