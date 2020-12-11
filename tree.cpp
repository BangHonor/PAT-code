//1087
/*
#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <cstring>
#include  <stack>
using namespace std;
struct node{
    int data;
    node* leftchild;
    node* rightchild;
};
//记录先序遍历  中序遍历的数组
const int maxn=30;
int pre[maxn],in[maxn],post[maxn],cnt=0;
node* createTree(int prel,int prer,int inl,int inr){
    if(prel>prer)
        return NULL;
    node *root=new node;
    root->data=pre[prel];       //先序作为标准，则说明当前第一个为根节点
    int k;
    for(k=inl;k<=inr;k++){
        if(in[k]==pre[prel])
            break;      //记录根节点所在的位置，再次基础上创建左右子树
    }
    int numleft=k-inl;      //左的个数
    root->leftchild=createTree(prel+1,prel+numleft,inl,k-1);//前两个为先序序列中的左右界限，后两个为后序序列中的左右界限
    root->rightchild=createTree(prel+numleft+1,prer,k+1,inr);
    return root;
}
void postTraverse(node *root){
    if(root==NULL)
        return;
    postTraverse(root->leftchild);
    postTraverse(root->rightchild);
    if(cnt==0)
        printf("%d",root->data);
    else
        printf(" %d",root->data);
    cnt++;
}
int main(){
    //push为先序遍历，pop为中序遍历
    int n,prefirst=0,postfirst=0;
    stack<int> s;
    cin>>n;
    for(int i=0;i<2*n;i++){
        string status;
        int num;
        cin>>status;
        if(strcmp(status.c_str(),"Push")==0){
            cin>>num;
            pre[prefirst++]=num;
            s.push(num);
        }
        else{
            in[postfirst++]=s.top();
            s.pop();
        }
    }
    node* root=createTree(0,prefirst-1,0,postfirst-1);        //传入两个数组内的下标
    postTraverse(root);
    return 0;
}
*/

/*
#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <cstring>
#include  <deque>
using namespace std;
struct node{
    int data;
    node* leftchild;
    node* rightchild;
};
//记录先序遍历  中序遍历的数组
const int maxn=30;
int pre[maxn],in[maxn],post[maxn],cnt=0;
node* createTree(int postl,int postr,int inl,int inr){
    if(postl>postr)
        return NULL;
    node* root=new node;
    root->data=post[postr];     //和pre相反
    int k;
    for(k=inl;k<=inr;k++){
        if(in[k]==post[postr])      //k前面为左，后面为右
            break;
    }
    int numleft=k-inl;
    root->leftchild=createTree(postl,postl+numleft-1,inl,k-1);
    root->rightchild=createTree(postl+numleft,postr-1,k+1,inr);
    return root;
}
//前序遍历
void preTraverse(node *root){
    if(root==NULL)
        return;
    if(cnt==0)
        printf("%d",root->data);
    else
        printf(" %d",root->data);
    cnt++;
    preTraverse(root->leftchild);
    preTraverse(root->rightchild);
}
//层序遍历
void layTraverse(node *root){       //广度优先
    deque<node*> q;
    q.push_back(root);
    while(q.size()>0){
        root=q.front();
        if(cnt==0)
            printf("%d",root->data);
        else
            printf(" %d",root->data);
        cnt++;
        q.pop_front();
        if(root->leftchild!=NULL)
            q.push_back(root->leftchild);
        if(root->rightchild!=NULL)
            q.push_back(root->rightchild);
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>post[i];
    for(int i=0;i<n;i++)
        cin>>in[i];
    node* root=createTree(0,n-1,0,n-1);
    layTraverse(root);
    return 0;
}
*/

/*1102
#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
struct Node{
    int father;
    char left,right;
}a[10];
vector<int> in;
void layTraverse(int root){
    int time=0;
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int num=q.front();
        if(time==0){
            printf("%d",num);
            time++;
        }
        else
            printf(" %d",num);
        q.pop();
        if(a[num].left!='-')
            q.push(a[num].left-'0');
        if(a[num].right!='-')
            q.push(a[num].right-'0');
    }
}
void inTraverse(int root){
    if(a[root].left!='-')
        inTraverse(a[root].left-'0');
    in.push_back(root);
    if(a[root].right!='-')
        inTraverse(a[root].right-'0');
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        a[i].father=-1;
    }
    for(int i=0;i<n;i++){
        cin>>a[i].left;
        cin>>a[i].right;
        if(a[i].left!='-')
            a[a[i].left-'0'].father=i;
        if(a[i].right!='-')
            a[a[i].right-'0'].father=i;
    }
    //invert
    for(int i=0;i<n;i++){
        char left,right;
        left=a[i].left;
        right=a[i].right;
        a[i].left=right;
        a[i].right=left;
    }
    //获得树节点
    int root;
    for(int i=0;i<n;i++){
        if(a[i].father==-1){
            root=i;
            break;
        }
    }
    layTraverse(root);
    cout<<endl;
    inTraverse(root);
    for(int i=0;i<n;i++){
        if(i==0)
            printf("%d",in[i]);
        else
            printf(" %d",in[i]);
    }
    return 0;
}
*/

//1053
/*
#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
struct Node{
    int data;
    vector<int> child;
    int father;
    int sum;
}node[100];
bool cmp(stack<int> s1,stack<int> s2){
    stack<int> t1=s1,t2=s2;
    while(t1.top()==t2.top()&&t1.size()>1&&t2.size()>1){
        t1.pop();t2.pop();
    }
    return t1.top()>t2.top();
}
int main(){
    vector<stack<int> > ans;
    int n,m,s;
    cin>>n>>m>>s;
    for(int i=0;i<n;i++)
        cin>>node[i].data;
    node[0].sum=node[0].data;
    for(int i=0;i<m;i++){
        int father,num;
        cin>>father>>num;
        for(int j=0;j<num;j++){
            int child;
            cin>>child;
            node[father].child.push_back(child);
            node[child].father=father;
            node[child].sum=node[father].sum+node[child].data;
        }
    }
    for(int i=0;i<n;i++){
        int child=i;
        if(node[child].child.size()==0&&node[child].sum==s){
            stack<int> temp;
            while(child!=0){
                temp.push(node[child].data);
                child=node[child].father;
            }
            ans.push_back(temp);
        }
    }
    sort(ans.begin(),ans.end(),cmp);
    for(int i=0;i<ans.size();i++){
        printf("%d",node[0].data);
        int size=ans[i].size();
        for(int j=0;j<size;j++){
            printf(" %d",ans[i].top());
            ans[i].pop();
        }
        printf("\n");
    }
    return 0;
}
*/

//1079
/*
#include <iostream>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct node{
    int data,father;
    vector<int> child;
    int lay,num;
}a[10000];
int n;
double p,tao;
double layTraverse(int root){
    double sum=0;
    queue<int> q;
    q.push(root);
    a[root].lay=0;
    while(!q.empty()){
        int num=q.front();
        if(a[num].child.size()==0){
            sum+=a[num].num*p*pow(1+tao/100,a[num].lay);
        }
        q.pop();
        for(int i=0;i<a[num].child.size();i++){
            q.push(a[num].child[i]);
            a[a[num].child[i]].lay=a[num].lay+1;
        }
    }
    return sum;
}
int main()
{
    cin>>n>>p>>tao;
    for(int i=0;i<n;i++){
        a[i].father=-1;
    }
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        if(num>0){
            for(int j=0;j<num;j++){
                int child;cin>>child;
                a[i].child.push_back(child);
                a[child].father=i;
            }
        }
        else
            cin>>a[i].num;
    }
    //获得树节点
    int root;
    for(int i=0;i<n;i++){
        if(a[i].father==-1){
            root=i;
            break;
        }
    }
    double ans=layTraverse(root);
    printf("%.01lf",ans);
    return 0;
}
*/

//1090
/*
#include <iostream>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct node{
    int data,num;
    vector<int> child;
}a[100010];
int n,maxd=-1,total=1;
double p,tao;
void dfs(int num,int depth){
    if(a[num].child.size()==0){
        if(depth>maxd){
            maxd=depth;
            total=1;
        }
        else if(depth==maxd)
            total++;
    }
    else
    {
        for(int i=0;i<a[num].child.size();i++)
            dfs(a[num].child[i],depth+1);
    }
}
int main()
{
    cin>>n>>p>>tao;
    int root;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        if(num>=0)
            a[num].child.push_back(i);
        else
            root=i;    
    }
    dfs(root,0);
    double maxp=p*pow((1+tao/100),maxd);
    printf("%.02lf %d",maxp,total);
    return 0;
}
*/

//1094
/*
#include <iostream>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct node{
    vector<int> child;
}a[110];
int laynum[110]={0};        //层数对应的数目
void dfs(int index,int depth){
    laynum[depth]++;
    for(int i=0;i<a[index].child.size();i++)
        dfs(a[index].child[i],depth+1);
} 
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int k,num;
        cin>>k>>num;
        for(int j=0;j<num;j++){
            int child;cin>>child;
            a[k].child.push_back(child);
        }
    }
    dfs(1,1);
    int maxp=-1,maxl=-1;
    for(int i=1;;i++){
        if(laynum[i]==0)
            break;
        if(laynum[i]>maxp){
            maxp=laynum[i];
            maxl=i;
        }
    }
    printf("%d %d",maxp,maxl);
    return 0;
}
*/

/*
#include <iostream>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct node{
    node* left;;
    node* right;
    int data;
};
node* findMax(node* root){
    while(root->right!=NULL)
        root=root->right;
    return root;
}
node* findMin(node* root){
    while(root->left)
        root==root->left;
    return root;
}
void deleteNode(node* &root,int x){
    if(root==NULL)
        return;
    if(root->data==x){//找到了这个点，用前驱节点替换
        if(root->left==NULL&&root->right==NULL)
            root=NULL;//这样就相当于删除了
        else if(root->right==NULL){     //先左，左没有就右
            node* pre=findMax(root);
            root->data=pre->data;
            deleteNode(pre,pre->data);
        }
        else{
            node* pre=findMin(root);
            root->data=pre->data;
            deleteNode(pre,pre->data);
        }
    }
    else if(root->data>x)
        deleteNode(root->left,x);
    else
        deleteNode(root->right,x);
}

node* insert(node* &root,int x){
    if(root==NULL){
        root=new node;
        root->data=x;
        root->left=root->right=NULL;
        return root;
    }
    if(root->data>x)
        insert(root->left,x);
    else
        insert(root->right,x);
}
vector<int> pre,post,prem,postm;
void preTraverse(node* root,vector<int> &v){
    if(root==NULL)
        return;
    v.push_back(root->data);
    preTraverse(root->left,v);
    preTraverse(root->right,v);
}
void postTraverse(node* root,vector<int> &v){
    if(root==NULL)
        return;
    postTraverse(root->left,v);
    postTraverse(root->right,v);
    v.push_back(root->data);
}
void premTraverse(node* root,vector<int> &v){
    if(root==NULL)
        return;
    v.push_back(root->data);
    premTraverse(root->left,v);
    premTraverse(root->right,v);
}
void postmTraverse(node* root,vector<int> &v){
    if(root==NULL)
        return;
    postmTraverse(root->left,v);
    postmTraverse(root->right,v);
    v.push_back(root->data);
}
int main(){
    int n;cin>>n;
    vector<int> first;
    node* root=NULL;
    for(int i=0;i<n;i++){
        int num;cin>>num;
        insert(root,num);
        first.push_back(num);
    }
    //用first序列和接下来的几个序列进行对比即可
    preTraverse(root,pre);
    postTraverse(root,post);
    premTraverse(root,prem);
    postmTraverse(root,postm);
    if(pre==first){
        cout<<"YES"<<endl;
        for(int i=0;i<post.size();i++){
            if(i==0)
                cout<<post[i];
            else
                cout<<" "<<post[i];
        }
    }
    else if(prem==first){
        cout<<"YES"<<endl;
        for(int i=0;i<postm.size();i++){
            if(i==0)
                cout<<postm[i];
            else
                cout<<" "<<postm[i];
        }
    }
    else
        cout<<"NO";
    return 0;
}
*/

/*1043
#include <iostream>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct node{
    node* left;;
    node* right;
    int data;
};
node* findMax(node* root){
    while(root->right!=NULL)
        root=root->right;
    return root;
}
node* findMin(node* root){
    while(root->left)
        root=root->left;
    return root;
}
void deleteNode(node* &root,int x){
    if(root==NULL)
        return;
    if(root->data==x){//找到了这个点，用前驱节点替换
        if(root->left==NULL&&root->right==NULL)
            root=NULL;//这样就相当于删除了
        else if(root->right==NULL){     //先左，左没有就右
            node* pre=findMax(root);
            root->data=pre->data;
            deleteNode(pre,pre->data);
        }
        else{
            node* pre=findMin(root);
            root->data=pre->data;
            deleteNode(pre,pre->data);
        }
    }
    else if(root->data>x)
        deleteNode(root->left,x);
    else
        deleteNode(root->right,x);
}

node* insert(node* &root,int x){
    if(root==NULL){
        root=new node;
        root->data=x;
        root->left=root->right=NULL;
        return root;
    }
    if(root->data>x)
        insert(root->left,x);
    else
        insert(root->right,x);
}
vector<int> pre,post,prem,postm;
void preTraverse(node* root){
    if(root==NULL)
        return;
    pre.push_back(root->data);
    preTraverse(root->left);
    preTraverse(root->right);
}
void postTraverse(node* root){
    if(root==NULL)
        return;
    postTraverse(root->left);
    postTraverse(root->right);
    post.push_back(root->data);
}
void premTraverse(node* root){
    if(root==NULL)
        return;
    prem.push_back(root->data);
    premTraverse(root->left);
    premTraverse(root->right);
}
void postmTraverse(node* root){
    if(root==NULL)
        return;
    postmTraverse(root->left);
    postmTraverse(root->right);
    postm.push_back(root->data);
}
int main(){
    int n;cin>>n;
    vector<int> first;
    node* root=NULL;
    for(int i=0;i<n;i++){
        int num;cin>>num;
        insert(root,num);
        first.push_back(num);
    }
    //用first序列和接下来的几个序列进行对比即可
    preTraverse(root);
    postTraverse(root);
    premTraverse(root);
    postmTraverse(root);
    if(pre==first){
        cout<<"YES"<<endl;
        for(int i=0;i<post.size();i++){
            if(i==0)
                cout<<post[i];
            else
                cout<<" "<<post[i];
        }
    }
    else if(prem==first){
        cout<<"YES"<<endl;
        for(int i=0;i<postm.size();i++){
            if(i==0)
                cout<<postm[i];
            else
                cout<<" "<<postm[i];
        }
    }
    else
        cout<<"NO";
    return 0;
}
*/

/*
//1064 中序建完全二叉排序树
#include <iostream>
#include <algorithm>
using namespace std;
int CBT[1010],num[1010],index=0,n;
void inOrderBuildTree(int root){
    if(root>n)
        return;
    inOrderBuildTree(root*2);
    CBT[root]=num[index++];
    inOrderBuildTree(root*2+1);
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>num[i];
    sort(num,num+n);
    inOrderBuildTree(1);
    for(int i=1;i<n;i++)
        cout<<CBT[i]<<" ";
    cout<<CBT[n];
    return 0;
}
*/

/*
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct node{
    int left,right;
    int data;
}a[110];
int num[110],index=0,n;    //BST对应的节点存储该树的信息
void inOrderBuildTree(int root){        //已知树的外形，完全二叉树更是如此
    if(a[root].left!=-1)
        inOrderBuildTree(a[root].left);
    a[root].data=num[index++];
    if(a[root].right!=-1)
        inOrderBuildTree(a[root].right);
    if(a[root].left==-1&&a[root].right==-1)
        return;
}
void layTraverse(int root){
    queue<int> q;
    q.push(root);
    int time=0;
    while(!q.empty()){
        int num=q.front();
        q.pop();
        if(time==0){
            time++;
            cout<<a[num].data;
        }
        else
            cout<<" "<<a[num].data;
        if(a[num].left!=-1)
            q.push(a[num].left);
        if(a[num].right!=-1)
            q.push(a[num].right);
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        a[i].left=l;
        a[i].right=r;
    }
    for(int i=0;i<n;i++)
        cin>>num[i];
    sort(num,num+n);
    inOrderBuildTree(0);
    layTraverse(0);
    return 0;
}
*/







/*

//AVL
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
struct node{
    node* left;
    node* right;
    int data,height;
}*root;
node* newnode(int x){
    node* root=new node;
    root->left=root->right=NULL;
    root->data=x;
    root->height=1;
    return root;
}
int getHeight(node* root){
    if(root==NULL)
        return 0;
    return root->height;
}
void updateHeight(node* root){
    root->height=max(getHeight(root->left),getHeight(root->right))+1;
}
int getBalanceFactor(node* root){
    if(root==NULL) return 0;
    return getHeight(root->left)-getHeight(root->right);
}
void LeftRotation(node*& root){
    node* temp=root->right;
    root->right=temp->left;
    temp->left=root;
    updateHeight(root);
    updateHeight(temp);
    root=temp;
}
void RightRotation(node*& root){
    node* temp=root->left;
    root->left=temp->right;
    temp->right=root;
    updateHeight(root);
    updateHeight(temp);
    root=temp;
}
void insert(node* &root,int v){
    //在二叉树的基础上进行平衡即可
    if(root==NULL){
        root=newnode(v);
        return;
    }
    if(v>root->data){       //递归的思想！
        insert(root->right,v);
        updateHeight(root);
        if(getBalanceFactor(root)==-2){
            if(getBalanceFactor(root->right)==-1){      //RR
            LeftRotation(root);
            }
            else if(getBalanceFactor(root->right)==1){        //RL
                RightRotation(root->right);
                LeftRotation(root);
            }
        }
    }
    else{
        insert(root->left,v);
        updateHeight(root);
        if(getBalanceFactor(root)==2){
            if(getBalanceFactor(root->left)==1){      //LL
            RightRotation(root);
            }
            else if(getBalanceFactor(root->left)==-1){        //LR
                LeftRotation(root->left);
                RightRotation(root);
            }
        }
    }
}

node* CreateAVL(int data[],int n){
    node* root=NULL;
    for(int i=0;i<n;i++)
        insert(root,data[i]);
    return root;
}

int main(){
    int n,num[20];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i];
        insert(root,num[i]);
    }
    cout<<root->data;
    return 0;
}
*/

/*
//BST
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
struct Node{
    Node* left;
    Node* right;
    int data;
};
int laynum[1010];
int maxlay=-1;
void insert(Node* &root,int x,int lay){//当前层的高度,注意引用
    if(root==NULL){
        root=new Node;
        root->data=x;
        root->left=NULL;
        root->right=NULL;
        laynum[lay]++;
        if(lay>maxlay)
            maxlay=lay;
        return;
    }
    if(x<=root->data)
        insert(root->left,x,lay+1);
    else if(x>root->data)
        insert(root->right,x,lay+1);
}
int main(){
    Node* root=NULL;    //一开始要设为null
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        insert(root,x,0);
    }
    int first=laynum[maxlay];
    int second=laynum[maxlay-1];
    cout<<first<<" + "<<second<<" = "<<first+second;
    return 0;
}
*/

/*
#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;   
};
int post[31],in[31],n,lay[31];    //同时记录所在的层高
node* buildTree(int postl,int postr,int inl,int inr,int l){
    if(postl>postr)     //根据后序进行建树，所以从最后开始，应该是中右左
        return NULL;       
    node* root=new node;
    root->data=post[postr];     
    lay[root->data]=l;
    int k;
    for(k=inl;k<=inr;k++){      //中序遍历：左中右
        if(in[k]==post[postr])
            break;
    }
    int num=k-inl;      //左子树的个数
    root->left=buildTree(postl,postl+num-1,inl,k-1,l+1);//注意不要错!!!
    root->right=buildTree(postl+num,postr-1,k+1,inr,l+1);
    return root;
}
//进行遍历编号
map<int,vector<int> > v;
 //记录每一层都按顺序装了什么
void bfs(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* front=q.front();
        int data=front->data;
        q.pop();
        int l=lay[front->data];
        v[l].push_back(data);//写法不正确
        if(front->left!=NULL)
            q.push(front->left);
        if(front->right!=NULL)
            q.push(front->right);
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>in[i];
    for(int i=0;i<n;i++)
        cin>>post[i];
    node* root=buildTree(0,n-1,0,n-1,0);
    bfs(root);
    cout<<v[0][0];
    for(int i=1;;i++){
        if(v[i].size()==0)
            break;
        if(i%2==1){//基数，从左到右
            for(int j=0;j<v[i].size();j++)
                cout<<" "<<v[i][j];
        }
        else{   //偶数，从右到左
            for(int j=v[i].size()-1;j>=0;j--)
                cout<<" "<<v[i][j];
        }
    }
    return 0;
}   
*/

/*
#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){       //n个例子
        int k,flag=1;
        cin>>k;
        vector<pair<int,int> > v;
        map<int,int> mp;    //每个row都得是1才能符合
        for(int j=1;j<=k;j++){
            int row;
            cin>>row;
            v.push_back(make_pair(j,row));
            mp[row]=1;
        }
        //输入处理完毕，进行判断
        int cnt=0;
        for(int j=1;j<=k;j++)
            cnt+=mp[j];
        if(cnt!=k)     //row已经不符合
            flag=0;
        //接下来判断斜线
        for(int j=0;j<k;j++){
            for(int m=0;m<j;m++){
                int x1=v[j].first,y1=v[j].second;
                int x2=v[m].first,y2=v[m].second;
                if(abs(x1-x2)==abs(y1-y2)){
                    flag=0;
                    break;
                }
            }
        }
        if(flag==1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
*/

/*
#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <string.h>
#include <string>
using namespace std;
struct node{
    string data;
    int left,right;
}a[22];
int root;
string dfs(int index) { //递归的思想
    if (index == -1) return "";
    if (a[index].right != -1) {     //如果没有右就说明操作数
        a[index].data = dfs(a[index].left) + a[index].data + dfs(a[index].right);
        if (index != root) a[index].data = '(' + a[index].data+ ')';
    }
    return a[index].data;
}
int main(){
    int n;
    cin>>n;
    int father[22];
    for(int i=1;i<=n;i++)
        father[i]=i;
    for(int i=1;i<=n;i++){
        string temp;
        int left,right;
        cin>>temp>>left>>right;
        a[i].data=temp;
        a[i].left=left;
        a[i].right=right;
        father[left]=i;
        father[right]=i;
    }
    //寻找父节点
    for(int i=1;i<=n;i++){
        if(father[i]==i){
            root=i;
            break;
        }
    }
    cout<<dfs(root);
    return 0;
}
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <string.h>
#include <string>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};
vector<int> a;
int nodenum=0;
node* preBuildTree(int prel,int prer){
    if(prel>prer)
        return NULL;
    node* root=new node;
    root->data=a[prel];
    //nodenum++;
    root->left=root->right=NULL;
    int data=root->data;
    int i;
    for(i=prel+1;i<=prer;i++){
        if(abs(a[i])>abs(data))
            break;  //记录右子树的第一个点
    }
    root->left=preBuildTree(prel+1,i-1);
    root->right=preBuildTree(i,prer);
    return root;
}
int flag;
void dfs(node* root){ //判断是否符合红色的儿子都是黑色，且点到叶节点所经路径节点的黑节点数量相同
    if(root==NULL)
        return;
    if(root->data<0){
        int data1=1,data2=1;
        if(root->left!=NULL)
            data1=root->left->data;
        if(root->right!=NULL)
            data2=root->right->data;    
        if(data1<0||data2<0)
            flag=0;
    }
    dfs(root->left);
    dfs(root->right);
}
int getNum(node *root) {
    //求解每一个点到叶节点的黑节点个数
    if(root==NULL)      //递归边界条件
        return 0;
    int l=getNum(root->left);
    int r=getNum(root->right);
    int ans=max(l,r);
    if(root->data>0)
        ans++;
    return ans;
}
bool judge2(node *root) {
    if(root==NULL)  //递归边界条件
        return true;
    int l=getNum(root->left);
    int r=getNum(root->right);
    if(l!=r)
        return false;
    return judge2(root->left)&&judge2(root->right);
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        flag=1;
        a.clear();
        for(int j=0;j<num;j++){
            int node;
            cin>>node;
            a.push_back(node);
        }
        node* root=preBuildTree(0,a.size()-1);//建好树
        if(root->data<0)
            flag=0;
        dfs(root);
        if(judge2(root)==false)
            flag=0;
        if(flag==1)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}