
/*  好朋友
#include <iostream>
#include <algorithm>
using namespace std;
int findFather(int a){
    while(a!=father[a])
        a=father[a];
    return a;
}
void Union(int a,int b){
    int fathera=findFather(a);
    int fatherb=findFather(b);
    if(fathera!=fatherb)
        father[fathera]=fatherb;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        father[i]=i;
    for(int i=0;i<m;i++){
        int f1,f2;
        cin>>f1>>f2;
        Union(f1,f2);
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(father[i]==i)
            cnt++;
    }
    cout<<cnt;
    return 0;
}
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int up[1010]={0},father[1010],flag[1010]={0};   //每一个union的数目
vector<int> v;
int findFather(int a){
    while(a!=father[a])
        a=father[a];
    return a;
}
void Union1(int a,int b){
    int fathera=findFather(a);
    int fatherb=findFather(b);
    if(fathera!=fatherb)
        father[fathera]=fatherb;
}
bool cmp(int a,int b){
    return a>b;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<1010;i++)
        father[i]=i;
    for(int i=0;i<n;i++){
        int num;
        scanf("%d: ",&num);
        int first;cin>>first;
        for(int j=0;j<num-1;j++){
            int after;cin>>after;
            Union1(first,after);
        }
        int father=findFather(first);
        v.push_back(father);        //n个数，所有的集团都已经生成
    }
    up[findFather(v[0])]=1;
    for(int i=1;i<n;i++){
        int father1=findFather(v[0]),father2=findFather(v[i]);
        if(father1==father2)
            up[father1]++;
        else
            up[father2]++;
    }
    sort(up,up+1010,cmp);
    int i;
    for(i=0;i<n;i++){
        if(up[i]==0)
            break;
    }
    cout<<i<<endl;
    cout<<up[0];
    for(int j=1;j<i;j++)
        cout<<" "<<up[j];
    return 0;
}