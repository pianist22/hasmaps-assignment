#include<iostream>
#include<queue>
#include<unordered_map>
#include<climits>
using namespace std;

class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val = val;
        left= NULL;
        right = NULL;
    }
};

Node* construct(int arr[],int n){
    queue<Node*>q;
    Node* root = new Node(arr[0]);
    q.push(root);
    int i=1;
    int j=2;
    while(!q.empty() && i<n){
        Node* temp = q.front();
        q.pop();
        Node* l;
        Node* r;
        if(arr[i]!=INT_MIN) l = new Node(arr[i]);
        else l= NULL;
        if(j<n && arr[j]!=INT_MIN) r= new Node(arr[j]);
        else r = NULL;

        temp->left = l;
        temp->right = r;

        if(l) q.push(l);
        if(r) q.push(r);

        i += 2;
        j += 2;
    }
    return root;
}

void levelOrderQueue(Node* root){
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cout<<temp->val<<" ";
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}


int levelNo(Node* root){
    if(root==NULL) return 0;
    return 1+max(levelNo(root->left),levelNo(root->right));
}

void printLevel(Node* root,int level,int m){
    if(root==NULL) return;
    printLevel(root->left,level,m+1);
    printLevel(root->right,level,m+1);
    if(level==m) {
        cout<<root->val<<" ";
        return;
    }
}


void levelOrder(Node* root){
    int level = levelNo(root);
    for(int i=1;i<=level;i++){
        printLevel(root,i,1);
        cout<<endl;
    }
}

void bottomView(Node* root){
    unordered_map<int,int> m;
    queue< pair<Node*,int> > q;
    pair<Node*,int> r;
    r.first = root;
    r.second = 0;
    q.push(r);
    while(q.size()>0){
        Node* temp = (q.front()).first;
        int level = (q.front()).second;
        q.pop();
        m[level] = temp->val;
        if(temp->left!=NULL){
            pair<Node*,int> r;
            r.first = temp->left;
            r.second = level-1;
            q.push(r);    
        }
        if(temp->right!=NULL){
            pair<Node*,int> r;
            r.first = temp->right;
            r.second = level+1;
            q.push(r);             
        }
    }
    int minLevel = INT_MAX;
    int maxLevel = INT_MIN;
    for(auto x: m){
        int level = x.first;
        minLevel = min(level,minLevel);
        maxLevel = max(level,maxLevel);
    }
    for(int i=minLevel;i<=maxLevel;i++){
        cout<<m[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[]={1,2,3,4,5,INT_MIN,6,INT_MIN,INT_MIN,7,8};
    int n= sizeof(arr)/sizeof(arr[0]);
    Node* root= construct(arr,n);
    levelOrder(root);
    bottomView(root);
    return 0;
}