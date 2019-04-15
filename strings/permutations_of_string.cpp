//Permutations of string
#include<iostream>
#include <vector>
using namespace std;
void perm(string str, int start, vector<string> &res){
    if(start==str.size()){
        res.push_back(str);
        return;
    }
    for(int i=start;i<str.size();i++){
        swap(str[i],str[start]);
        perm(str, start+1, res);
        swap(str[start], str[i]);
    }
}
int main(){
    string str;
    cout<<"Enter string\n";
    cin>>str;
    vector<string> res;
    perm(str, 0, res);
    cout<<"result-->\n";
    for(auto x:res){
        cout<<x<<endl;
    }
    cout<<res.size()<<endl;
    return 0;
}
