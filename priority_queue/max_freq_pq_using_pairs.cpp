#include <iostream>
#include<math.h>
#include <vector>
#include <queue>
using namespace std;
struct Key{
    int freq;
    char ch;
    bool operator<(const Key &k) const{
        return freq<k.freq;
    }
};
int main() {
    string s, res="";
    cout<<"Enter string";
    getline(cin, s);
    vector<int> alphas(26,0);
    for(char c:s){
        if(c>96 and c<123) alphas[c-'a']++;
        else if(c<97 and c>=65) alphas[c-'A']++;
        
    }
    priority_queue<pair<int, char> pq;
    for(int i=0;i<26;i++){
        if(alphas[i]>0)
            pq.push(Key{alphas[i], (char)('a'+i)});
    }
    Key prev{-1,'#'};
    while(!pq.empty()){
        Key curr=pq.top();
        pq.pop();
        res+=curr.ch;
        if(prev.freq>0){
            pq.push(prev);
        }
        prev=curr;
        prev.freq--;
    }
    if(s.length()!=res.length()) cout<<"NOT POSSIBLE\n";
    else
    cout<<"res="<<res;
    return 0;
}
