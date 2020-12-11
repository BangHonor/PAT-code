/*
#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;
struct graph{
    string name;
    vector<string> v;
    int time;
    bool flag;
    int group;
}g[10000];
map<string,int> mp; //对应结构体下标
string first,second;
int n,k,t,now=1,num=0;
vector<string> ans; 
void record(string first,string second){
    if(mp[first]==0){
            mp[first]=now;      //注意不要从0开始，不然无法判断是否赋值过
            g[now].name=first;
            g[now].time=0;
            g[now].flag=0;
            now++;
        }
        g[mp[first]].time+=t;
}
void dfs(int a,int& maxt,string& maxs,int& group,int& sumt){
    g[a].flag=1;
    group++;
    sumt+=g[a].time;
    if(g[a].time>maxt){
        maxt=g[a].time;
        maxs=g[a].name;
    }
    int vsize=g[a].v.size();
    for(int i=0;i<vsize;i++){
        if(g[mp[g[a].v[i]]].flag==0)
            dfs(mp[g[a].v[i]],maxt,maxs,group,sumt);
    }
}
void dfsTraverse(){
    for(int i=0;i<n;i++){
        if(g[i].flag==0){
            int maxt=-1,group=0,sumt=0;
            string maxs=g[i].name;
            dfs(i,maxt,maxs,group,sumt);
            if(sumt/2>k&&group>2){
                ans.push_back(maxs);
                g[mp[maxs]].group=group;
                num++;
            }
        }
    }
}
int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>first>>second>>t;
        record(first,second);
        record(second,first);
        g[mp[first]].v.push_back(second);
    }
    dfsTraverse();
    sort(ans.begin(),ans.end());
    cout<<num<<endl;
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" "<<g[mp[ans[i]]].group<<endl;
    return 0;
}
*/

/*
//1021
#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
struct graph{
    vector<int> v;
    bool flag;
    int height;
}g[10010];
int n;
vector<int> ans;  //记录每一个节点的最高高度
void dfs(int fixed,int a,int depth){
    if(depth>g[fixed].height)
        g[fixed].height=depth;
    g[a].flag=1;
    for(int i=0;i<g[a].v.size();i++){
        if(g[g[a].v[i]].flag==0)
            dfs(fixed,g[a].v[i],depth+1);
    }
}
void dfsTraverse(){     //一次tra过后所有的量都已经记录height
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            g[j].flag=0;
        //一次dfs就一个连通分量，记录连通分量的个数和每一个联通分量里面数的高度
        dfs(i,i,0);
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n-1;i++){
        int first,second;
        cin>>first>>second;
        g[first].v.push_back(second);
        g[second].v.push_back(first);
    }
    int num=0;  //联通分量个数
    for(int j=1;j<=n;j++)
        g[j].flag=0;
    for(int i=1;i<=n;i++){
        if(g[i].flag==0){
            dfs(i,i,0);
            num++;      //记录要多少次才能全部遍历
        }
    }
    if(num==1){
        dfsTraverse();
        int max=-1;
        for(int i=1;i<=n;i++){
            if(g[i].height>max)
                max=g[i].height;
        }
        //进行输出
        for(int i=1;i<=n;i++){
            if(g[i].height==max)
                cout<<i<<endl;
        }
    }
    else
        cout<<"Error: "<<num<<" components"<<endl;
    return 0;
}
*/

//1076 dfs
/*
#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
struct graph{
    vector<int> v;
    bool flag;
    int height;
}g[10010];
int n,l,temp;
void dfs(int a,int depth){
    if(depth>l)
        return;
    g[a].flag=1;
    temp++;
    for(int i=0;i<g[a].v.size();i++){
        if(g[g[a].v[i]].flag==0)
            dfs(g[a].v[i],depth+1);
    }
}
int main(){
    cin>>n>>l;
    for(int i=1;i<=n;i++){
        int num;
        cin>>num;
        for(int j=0;j<num;j++){
            int second;cin>>second;
            g[second].v.push_back(i);
        }
    }
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        int t;cin>>t;
        temp=-1;
        for(int j=1;j<=n;j++)
            g[j].flag=0;
        dfs(t,0);
        cout<<temp<<endl;
    }
    return 0;
}
*/

// #include <iostream>
// #include <math.h>
// #include <vector>
// #include <queue>
// #include <map>
// #include <algorithm>
// using namespace std;
// struct graph{
//     vector<int> v;
//     bool flag;
//     int height;
// }g[10010];
// int n,l,temp,depth;
// void bfs(int a){
//     queue<int> q;
//     q.push(a);
//     g[a].flag=1;
//     while(!q.empty()){
//         int front=q.front();
//         q.pop();
//         temp++;
//         for(int i=0;i<g[front].v.size();i++){
//             if(g[front].height>=l)
//                 break;
//             if(g[g[front].v[i]].flag==0){
//                g[g[front].v[i]].flag=1;
//                 q.push(g[front].v[i]);
//                 g[g[front].v[i]].height=g[front].height+1;
//             }
//         }
//     }
// }
// int main(){
//     cin>>n>>l;
//     for(int i=1;i<=n;i++){
//         int num;
//         cin>>num;
//         for(int j=0;j<num;j++){
//             int second;cin>>second;
//             g[second].v.push_back(i);
//         }
//     }
//     int k;
//     cin>>k;
//     for(int i=0;i<k;i++){
//         int t;cin>>t;
//         temp=-1;
//         for(int j=1;j<=n;j++){
//             g[j].flag=0;
//             g[j].height=0;
//         }
//         bfs(t);
//         cout<<temp<<endl;
//     }
//     return 0;
// }

//汉密尔顿图
/*
#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main() {
    int n, m, cnt, k, a[210][210] = {0};
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int t1, t2;
        scanf("%d%d", &t1, &t2);
        a[t1][t2] = a[t2][t1] = 1;      //图
    }
    cin >> cnt;
    while(cnt--) {  //重点：每一个点遍历一次，每两个点之间有路
        cin >> k;
        vector<int> v;  //记录路径
        set<int> s; //记录走过的点
        for(int i=0;i<k;i++){
            int num;
            cin>>num;
            v.push_back(num);
            s.insert(num);
        }
        int flag1=1,flag2=1;
        if(k!=n+1||v[0]!=v[k-1]||s.size()!=n)
            flag1=0;
        for(int i=0;i<k-1;i++){
            if(a[v[i]][v[i+1]]==0){
                flag2=0;
                break;
            }
        }
        if(flag1==1&&flag2==1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
*/


//欧拉图
#include <iostream>
#include <set>
#include <vector>
using namespace std;
int n, m, a[510][510] = {0};
int visited=0;
int flag[510]={0};
void dfs(int index){
     visited++;
     flag[index]=1;
    for(int i=1;i<=n;i++){
        if(flag[i]==0&&a[i][index]!=0)
            dfs(i);
    }
}
int main() {
    cin >> n >> m;
    int degree[510]={0};    //记录每一个点的度
    for(int i = 0; i < m; i++) {
        int t1, t2;
        scanf("%d%d", &t1, &t2);
        a[t1][t2] = a[t2][t1] = 1;      //图
        degree[t1]++;
        degree[t2]++;
    }
    int odd=0;
    for(int i=1;i<=n;i++){      //需要判断是不是连通图，
    //欧拉图与半欧拉图是在联通的基础上实现的
        if(degree[i]%2!=0)
            odd++;
    }
    cout<<degree[1];
    for(int i=2;i<=n;i++)
        cout<<" "<<degree[i];
    cout<<endl;
    dfs(1);
    if(odd==0&&visited==n)
        cout<<"Eulerian"<<endl;
    else if(odd==2&&visited==n)
        cout<<"Semi-Eulerian"<<endl;
    else    
        cout<<"Non-Eulerian"<<endl;
    return 0;
}