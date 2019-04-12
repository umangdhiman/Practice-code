//https://www.geeksforgeeks.org/difference-of-two-large-numbers/
//Given two numbers as strings. The numbers may be very large (may not fit in long long int), the task is to find difference of these two numbers.

//Examples:
//
//Input : str1 = "11443333311111111100",
//        str2 =     "1144422222221111"
//Output : 11442188888888889989
//
//Input :str1 = "122387876566565674",
//       str2 =     "31435454654554"
//Output : 122356441111911120
//
//O(n1+n2)
#include <iostream>
using namespace std;
bool small(string s1, string s2){
    if(s1.length()<s2.length()) return true;
    if(s1.length()>s2.length()) return false;
    for(int i=0;i<s1.length();i++){
        if(s1[i]<s2[i]) return true;
    }
    return false;
}
string findDiff(string s1, string s2){
    bool sign=false;
    if(small(s1,s2)) {sign=true;swap(s1,s2);}
    string res="";
    int carry=0,diff=0, i=s1.length()-1;
    for(int j=s2.length()-1;i>=0&&j>=0;i--, j--){
        diff=(s1[i]-s2[j]-carry);
        if(diff<0){
            diff=(s1[i]-'0')+10-(s2[j]-'0')-carry;
            carry=1;
        }
        else carry=0;
        res=char(diff+'0')+res;
    }
    while(i>=0){
        diff=(s1[i]-'0'-carry);
        if(diff<0) {diff=s1[i]-'0'+10-carry; carry=1;}
        else carry=0;
        if(i>0||(i==0&&diff>0))
        res=char(diff+'0')+res;
        i--;
    }
    if(carry) res=char(carry+'0')+res;
    return sign?"-"+res:res;
}
int main()
{
    string str2 = "978";
    string str1 = "12977";
    cout << findDiff(str1, str2) << endl;
    
    string s1 = "100";
    string s2 = "1000000";
    cout << findDiff(s1,s2);
    
    return 0;
}

