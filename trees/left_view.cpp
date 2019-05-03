//Iterative solution
//#include<iostream>
//#include<queue>
//#include <vector>
//
//using namespace std;
//
//struct node{
//    int data;
//    struct node *left, *right;
//};
//
//// A utility function to create a new Binary Tree node
//struct node *newNode(int item){
//    struct node *temp =  (struct node *)malloc(sizeof(struct node));
//    temp->data = item;
//    temp->left = temp->right = NULL;
//    return temp;
//}
//void leftView(node *root, vector<int> &res){
//    if(!root) return;
//    queue<pair<node *, int>> qu;
//    qu.push(make_pair(root,0));
//    int max_till_now=0;
//    res.push_back(root->data);
//    while (!qu.empty()) {
//        int size=qu.size();
//        while (size--) {
//            pair<node *, int> front= qu.front();
//            qu.pop();
//            if(front.second>max_till_now){
//                res.push_back(front.first->data);
//                max_till_now=front.second;
//            }
//            if(front.first->left) qu.push(make_pair(front.first->left, front.second+1));
//            if(front.first->right) qu.push(make_pair(front.first->right, front.second+1));
//        }
//    }
//}
//int main(){
//    struct node *root = newNode(12);
//    root->left = newNode(10);
//    root->right = newNode(30);
//    root->right->left = newNode(25);
//    root->right->right = newNode(40);
//    
//    vector<int> res;
//    leftView(root, res);
//    cout<<"left view->\n";
//    for(auto r:res){
//        cout<<r<<" ";
//    }
//    return 0;
//}
//
//
//Recursive solution
#include<iostream>
#include<queue>
#include <vector>

using namespace std;

struct node{
    int data;
    struct node *left, *right;
};

// A utility function to create a new Binary Tree node
struct node *newNode(int item){
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
void leftView(node *root, vector<int> &res, int level, int &max_till_now){
    if(!root) return;
    if(level>max_till_now){
        res.push_back(root->data);
        max_till_now=level;
    }
    leftView(root->left, res, level+1, max_till_now);
    leftView(root->right, res, level+1, max_till_now);
}

int main(){
    struct node *root = newNode(12);
    root->left = newNode(10);
    root->right = newNode(30);
    root->right->left = newNode(25);
    root->right->right = newNode(40);
    
    vector<int> res;
    int max_till_now=-1;
    leftView(root, res, 0, max_till_now);
    cout<<"left view->\n";
    for(auto r:res){
        cout<<r<<" ";
    }
    return 0;
}

