/*
#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
const int inf=10000000;
int dist[510][510],cost[510][510],fd[510],fc[510],flag[510]={0},path[510];
//二维初始化不可以直接dist[][]=maxn?
int n,m,s,d;
void dijkstra(){
    fill(fd,fd+n,inf);
    fd[s]=0;
    fc[s]=0;
    for(int i=0;i<n;i++){
        //寻找最小点
        int min=inf,v=-1;
        for(int j=0;j<n;j++){
            if(flag[j]==0&&fd[j]<min){
                min=fd[j];
                v=j;
            }
        }
        if(v==-1)
            return;
        flag[v]=1;
        for(int j=0;j<n;j++){   //找到了当前最近点，搜索周边点进行更新
            if(flag[j]==0&&dist[v][j]!=inf){
                if(dist[v][j]+fd[v]<fd[j]){
                    fd[j]=dist[v][j]+fd[v];
                    fc[j]=cost[v][j]+fc[v];
                    path[j]=v;
                }
                else if(dist[v][j]+fd[v]==fd[j]){
                    if(fc[v]+cost[v][j]<fc[j]){
                        fc[j]=cost[v][j]+fc[v];
                        path[j]=v;
                    }
                }
            }
        }
    }
    
}
int main(){
    cin>>n>>m>>s>>d;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dist[i][j]=inf;
            cost[i][j]=inf;
        }
    }
    for(int i=0;i<m;i++){
        int c1,c2,dd,c;
        cin>>c1>>c2>>dd>>c;
        dist[c1][c2]=dd;
        dist[c2][c1]=dd;
        cost[c1][c2]=c;
        cost[c2][c1]=c;
    }
    fill(fd,fd+n,inf);
    fill(fc,fc+n,inf);
    dijkstra();
    int now=d;
    stack<int> temp;
    while(now!=s){
        temp.push(now);
        now=path[now];
    }
    cout<<s;
    while(!temp.empty()){
        cout<<" "<<temp.top();
        temp.pop();
    }
    cout<<" "<<fd[d]<<" "<<fc[d];
    return 0;
}
*/

/*
//Bellman-Ford
#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
const int maxv=10000,inf=10000;
struct node{
    int v,dist;
    node(int v1,int d1):v(v1),dist(d1){}
};
vector<node> adj[maxv];
int n,m,c1,c2;
int d[510],p[510],people[510],cnt=0;
bool Bellman(int s){    //s为原点
    fill(d,d+510,inf);
    d[s]=0;
    p[s]=people[s];
    for(int i=0;i<n-1;i++){     //执行n-1次
        int flag=0;
        for(int u=0;u<n;u++){    //每轮操作都遍历所有的边
            for(int j=0;j<adj[u].size();j++){
                int v=adj[u][j].v;
                if(d[u]+adj[u][j].dist<d[v]){
                    d[v]=d[u]+adj[u][j].dist;
                    p[v]=people[v]+p[u];
                    flag=1;
                    if(v==c2)
                        cnt=1;
                }
                else if(d[u]+adj[u][j].dist==d[v]){
                    if(people[v]+p[u]>p[v]){
                        p[v]=people[v]+p[u];
                        flag=1;
                        if(v==c2)
                            cnt++;
                    }
                }
            }
        }
        if(flag==0)
            return true;
    }
    //判断负环
    for(int u=0;u<n;u++){
        for(int j=0;j<adj[u].size();j++){
            int v=adj[u][j].v;
            if(d[u]+adj[u][j].dist<d[v])
                return false;
        }
    }
    return true;
}
//1003
int main(){
    cin>>n>>m>>c1>>c2;
    for(int i=0;i<n;i++)
        cin>>people[i];
    for(int i=0;i<m;i++){
        int c1,c2,dist;
        cin>>c1>>c2>>dist;
        adj[c1].push_back(node(c2,dist));
        adj[c2].push_back(node(c1,dist));
    }
    Bellman(c1);
    cout<<cnt<<" "<<p[c2];
    return 0;
}
*/

/*公共自行车
#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
const int maxv=10000,inf=10000;
struct node{
    int v,dist;
    node(int v1,int d1):v(v1),dist(d1){}
};
vector<node> adj[maxv];
vector<int> pre[510],temp;
vector<vector<int> > temppath,path;
int cmax,n,m,sp;
int d[maxv],bike[maxv],need[maxv],maxneed[maxv],num[maxv],inq[maxv];    //记录入站次数,在不在队列里面
bool spfa(){        //多条最优距离的路径
    fill(d,d+maxv,inf);
    fill(num,num+maxv,0);
    fill(inq,inq+maxv,0);
    //源点入队
    queue<int> q;
    num[0]++;
    d[0]=0;
    q.push(0);
    while(!q.empty()){
        int front=q.front();
        q.pop();
        inq[front]=0;
        for(int j=0;j<adj[front].size();j++){
            int v=adj[front][j].v;
            int dist=adj[front][j].dist;
            if(dist+d[front]<=d[v]){
                if(dist+d[front]<d[v])
                    pre[v].clear();
                pre[v].push_back(front);
                d[v]=dist+d[front];
                if(!inq[v]){
                    q.push(v);
                    inq[v]=1;
                    num[v]++;
                    if(num[v]>=n)
                        return false;
                }
            }
        }
    }
    return true;
}
void dfs(int now){         //深度优先计算当前方法的所需单车最大值
    if(now==0){
            temppath.push_back(temp);
            return;
    }
    for(int i=0;i<pre[now].size();i++){
        temp.push_back(pre[now][i]);
        dfs(pre[now][i]);
        temp.pop_back();
    }
}
int main(){
    cin>>cmax>>n>>sp>>m;
    for(int i=1;i<=n;i++)
        cin>>bike[i];
    for(int i=0;i<m;i++){
        int c1,c2,dist;
        cin>>c1>>c2>>dist;
        adj[c1].push_back(node(c2,dist));
        adj[c2].push_back(node(c1,dist));
    }
    spfa();
    //将pre转化成temppath
    temp.push_back(sp);
    dfs(sp);
    //得到几条路径之后，分别判断这些方法最大的need;
    int maxneed[510];
    for(int i=0;i<temppath.size();i++){     //每一种方法
        int maxneed1=-1,nowbike=0;
        for(int j=temppath[i].size()-2;j>=0;j--){//从头开始
            if(bike[temppath[i][j]]>=cmax/2)
                nowbike+=bike[temppath[i][j]]-cmax/2;
            else{
                int need=cmax/2-bike[temppath[i][j]];
                if(need<=nowbike){
                    nowbike-=need;
                }
                else{   //还不够，需要请求支援
                    if(need-nowbike>maxneed1)
                        maxneed1=need-nowbike;
                    nowbike=0;
                }
            }
        }
        maxneed[i]=maxneed1;
    }
    int finalneed=inf,index;
    for(int i=0;i<temppath.size();i++){
        if(maxneed[i]<finalneed){
            finalneed=maxneed[i];
            index=i;
        }
    }
    cout<<finalneed<<" "<<"0";
    int sum=0;
    for(int i=temppath[index].size()-2;i>=0;i--){
        cout<<"->"<<temppath[index][i];
        sum+=bike[temppath[index][i]];
    }
    int left=finalneed+sum-(temppath[index].size()-1)*(cmax/2);
    cout<<" "<<left;
    return 0;
}
*/


//Floyd算法
/*
void Floyd(){
    for(int i=0;i<n;i++){       //枚举某一个点
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(dist[i][j]!=inf&&dist[i][k]!=inf&&dist[i][k]+dist[j][k]<dist[j][k])
                    dist[j][k]=dist[i][k]+dist[j][k];
            }
        }
    }
}
*/

/*
//1072          floyd
#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string.h>
#include <string>
using namespace std;
const int maxv=10010;
const float inf=100000;
int n,m,k;
float ds;
float dist[maxv][maxv];
void Floyd(){   
    for(int i=1;i<=n+m;i++){       //枚举某一个点
        for(int j=1;j<=n+m;j++){
            for(int k=1;k<=n+m;k++){
                if(dist[i][j]!=inf&&dist[i][k]!=inf&&dist[i][k]+dist[i][j]<dist[j][k])
                    dist[k][j]=dist[j][k]=dist[i][j]+dist[i][k];
            }
        }
    }
}   
int main(){
    cin>>n>>m>>k>>ds;
    for(int i=1;i<=n+m;i++){
        for(int j=1;j<=n+m;j++)
            dist[i][j]=100000;
    }
    for(int i=0;i<k;i++){
        string a,b;
        float d;
        int flag1=0,flag2=0;
        cin>>a>>b>>d;
        if(a[0]=='G'){
            a=a.substr(1);
            flag1=1;
        }
        if(b[0]=='G'){
            b=b.substr(1);
            flag2=1;
        }
        int first,second;
        first=(flag1==0)? atoi(a.c_str()):atoi(a.c_str())+n;
        second=(flag2==0)? atoi(b.c_str()):atoi(b.c_str())+n;
        dist[first][second]=dist[second][first]=d;
    }
    Floyd();
    float ave[maxv],mindist[maxv];
    for(int i=n+1;i<=n+m;i++){
        float mindist1=inf,maxdist1=-1,sum=0;
        for(int j=1;j<=n;j++){
            sum+=dist[i][j];
            if(dist[i][j]<mindist1)
                mindist1=dist[i][j];
            if(dist[i][j]>maxdist1)
                maxdist1=dist[i][j];
        }
        if(maxdist1<=ds){
            mindist[i]=mindist1;
            ave[i]=(float)sum/n;        //attention
        }
        else{
            mindist[i]=-inf;
            ave[i]=inf; 
        }
    }
    float mind=-1,mina=inf;     //最小距离中的最大值
    int ans=-1;
    for(int i=n+1;i<=n+m;i++){
        if(mindist[i]>mind){
            mind=mindist[i];
            mina=ave[i];
            ans=i;
        }
        else if(mindist[i]==mind){
            if(ave[i]<mina){
                mina=ave[i];
                ans=i;
            }
        }
    }
    if(ans==-1)
        cout<<"No Solution"<<endl;
    else{
        cout<<"G"<<ans-n<<endl;
        printf("%.01f %.01f",mind,mina+0.05);
    }
    return 0;
}
*/

/*
int prim(){
    fill(d,d+maxv,inf);
    d[0]=0;
    int ans=0;
    for(int i=0;i<n;i++){       //每个点轮一遍
        int mind=inf,index;
        for(int j=0;j<n;j++){
            if(d[j]<mind){
                mind=d[j];
                index=j;
            }
        }
        if(mind==inf)   return -1;//剩下的点不连通，则没有最小生成树
        flag[index]=1;
        ans+=mind;
        for(int j=0;j<n;j++){
            if(flag[j]==0&&g[index][j]!=inf&&g[index][j]<d[j])
                d[j]=g[index][j];
        }
    }
    return ans;
}
*/


/*
//kruskal
#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string.h>
#include <string>
using namespace std;
const int maxv=10010;
struct edge{
    int u,v;
    int len;
}E[maxv];
int n;
int father[maxv];
int findFather(int x){
    int n=x;
    while(n!=father[n])
        n=father[n];
    //路径压缩
    while(x!=father[x]){
        int z=x;
        father[z]=n;
        x=father[x];
    }
        return n;
}
bool cmp(edge a,edge b){
    return a.len<b.len;
}
int kruskal(int n,int m){
    //n m分别为点和边的数量
    int ans=0,edgenum=0;
    for(int i=0;i<m;i++)
        father[i]=i;
    sort(E,E+m,cmp);    //从小到大排序
    for(int i=0;i<m;i++){   //枚举所有的边
        int father1=findFather(E[i].u);
        int father2=findFather(E[i].v);
        if(father1!=father2){       //不在一个区
            father[father1]=father[father2];
            ans+=E[i].len;
            edgenum++;
            if(edgenum==n-1)    break;
        }
    }
    if(edgenum!=n-1)    return -1;
    else return ans;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int first,second,dist;
        cin>>first>>second>>dist;
        E[i].u=first;E[i].v=second;E[i].len=dist;
    }
    int ans=kruskal(n,m);
    cout<<ans;
    return 0;
}
*/

/*
//1087
#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;
const int maxv=10000,inf=10000;
map<string,int> mp;
map<int,string> findname;
vector<int> pre[510],temp;
vector<vector<int> > temppath,path;
int n,k;
int dist[maxv][maxv],d[maxv],hap[maxv],flag[maxv];    //记录入站次数,在不在队列里面
void dijkstra(){
    fill(d,d+maxv,inf);
    fill(flag,flag+maxv,0);
    d[0]=0;
    for(int i=0;i<n;i++){
        int mind=inf+1,index=-1;
        for(int j=0;j<n;j++){
            if(flag[j]==0&&d[j]<mind){
                mind=d[j];
                index=j;
            }
        }
        if(index==-1)   return;
        flag[index]=1;
        for(int j=0;j<n;j++){
            if(flag[j]==0&&dist[j][index]!=inf&&d[index]+dist[index][j]<d[j]){
                d[j]=d[index]+dist[index][j];
                pre[j].clear();
                pre[j].push_back(index);
            }
            else if(flag[j]==0&&dist[j][index]!=inf&&d[index]+dist[index][j]==d[j])
                pre[j].push_back(index);
        }
    }
}
void dfs(int now){         //获得所有的路径存放于temppath，记录了除了最后一个的数
    if(now==0){
        temppath.push_back(temp);
        return;
    }
    for(int i=0;i<pre[now].size();i++){
        temp.push_back(pre[now][i]);
        dfs(pre[now][i]);
        temp.pop_back();
    }
}
int main(){
    string start;
    cin>>n>>k>>start;
    mp[start]=0;
    findname[0]=start;
    hap[0]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            dist[i][j]=inf;
    }
    for(int i=1;i<n;i++){       //点的信息
        string a;
        int d;
        cin>>a>>d;
        mp[a]=i;
        hap[i]=d;
        findname[i]=a;
    }
    for(int i=0;i<k;i++){
        string s1,s2;
        int d;
        cin>>s1>>s2>>d;
        dist[mp[s1]][mp[s2]]=dist[mp[s2]][mp[s1]]=d;
    }
    dijkstra();//此时的最优路程已经出来了
    //把所有的路径从pre找出
    int end=mp["ROM"];
    dfs(end);
    int totalsum=0,maxsum=-1,index=-1;
    for(int i=0;i<temppath.size();i++){
        int sum=hap[end];
        for(int j=0;j<temppath[i].size();j++)
            sum+=hap[temppath[i][j]];
        totalsum+=sum;
        if(sum>maxsum){
            maxsum=sum;
            index=i;
        }
    }
    int ave=maxsum/temppath[index].size();
    cout<<temppath.size()<<" "<<d[end]<<" "<<maxsum<<" "<<ave<<endl;
    for(int i=temppath[index].size()-1;i>=0;i--)
        cout<<findname[temppath[index][i]]<<"->";
    cout<<"ROM"<<endl;
    return 0;
}


*/

/*
struct node{
    vector<int> v;
    int indegree;
}a[maxv];
bool topsort(){
    //初始化
    int num=0;      //记录加入了的数目
    queue<int> q;
    for(int i=0;i<n;i++){
        if(a[i].indegree==0)
            q.push(i);
    }
    while(!q.empty()){
        int front=q.front();
        q.pop();
        //选取点之后，令其邻接点入度-1
        for(int i=0;i<q[front].v.size();i++){
            a[q[front].v[i]].indegree--;
            if(a[q[front].v[i]].indegree==0){
                q.push(q[front].v[i]);
            }
        }
        num++;      //反向记，记pop出来的，也即加入了的
    }
    if(num==n)  return true;
    else    return false;
}
*/

/*
#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <string.h>
#include <string>
using namespace std;
const int maxv=10010,inf=10000;
int n=0,m;
int dist[26][26],flag[26][26]={0};
map<char,int> mp;
void Floyd(){   //适用于邻接矩阵？有向图？
    for(int i=0;i<n;i++){       //枚举某一个点
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(dist[j][i]!=inf&&dist[i][k]!=inf&&dist[j][i]+dist[i][k]<dist[j][k])
                    dist[j][k]=dist[j][i]+dist[i][k];
            }
        }
    }
}   
int main(){
    cin>>m;
    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++)
            dist[i][j]=inf;
    }
    for(int i=0;i<m;i++){
        string in;
        char first,ope,second;
        cin>>in;
        first=in[0];ope=in[1];second=in[2];
        //初始化
        if(mp[first]==0){
            mp[first]=1;
            n++;
        }
        if(mp[second]==0){
            mp[second]=1;
            n++;
        }
        if(ope=='<')
            dist[first-'A'][second-'A']=1;      //有向图,小于才装
        else
            dist[second-'A'][first-'A']=1;
        flag[first-'A'][second-'A']=flag[second-'A'][first-'A']=1;
    }
    Floyd();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dist[i][j]<inf&&flag[i][j]==0){
                char first='A'+i,second='A'+j;
                cout<<first<<"<"<<second<<endl;
                flag[i][j]=flag[j][i]=1;
            }
        }
    }
    return 0;
}
*/

/* FLOYD不可行,因为记录不了path
#include <iostream>
#include <math.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string.h>
#include <string>
using namespace std;
struct node{
    vector<int> route;
}a[10010];
const int inf=10010;
int n,k,dist[110][110];
map<int,int> mp,four;
void floyd(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(dist[i][j]!=inf&&dist[i][k]!=inf&&dist[i][k]+dist[i][j]<dist[j][k])
                    dist[k][j]=dist[j][k]=dist[i][j]+dist[i][k];
            }
        }
    }
}
int main(){
    cin>>n;
    int index=1;
    for(int i=1;i<=n;i++){      //mp的index从一开始
        for(int j=1;j<=n;j++)
            dist[i][j]=inf;
    }
    for(int i=1;i<=n;i++){  //线路
        int s;
        cin>>s;
        int last;
        for(int j=0;j<s;j++){
            int sta;
            cin>>sta;
            if(mp[sta]==0)  mp[sta]=index++;
            four[mp[sta]]=sta;
            a[sta].route.push_back(i);
            if(j!=0){
                dist[mp[last]][mp[sta]]=dist[mp[sta]][mp[last]]=1;
            }
            last=sta;
        }
    }
    cin>>k;
    for(int i=0;i<k;i++){
        int start,end;
        cin>>start>>end;
    }
}
*/

//这并不是一个典型的图 用dijkstra会多很多麻烦 更像是一棵树
#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<int> v[10000];
int visit[10000], minCnt, minTransfer, start, end1;
map<int, int> line;
vector<int> path, tempPath;
int transferCnt(vector<int> a) {    //路径出来，中转站自然就知道，用二维的矩阵记录两个站之间的路线即可
    int cnt = -1, preLine = 0;
    for (int i = 1; i < a.size(); i++) {
        if (line[a[i-1]*10000+a[i]] != preLine) cnt++;
        preLine = line[a[i-1]*10000+a[i]];
    }
    return cnt;
}
void dfs(int node, int cnt) {
    if (node == end1 && (cnt < minCnt || (cnt == minCnt && transferCnt(tempPath) < minTransfer))) {
        minCnt = cnt;
        minTransfer = transferCnt(tempPath);
        path = tempPath;
    }
    if (node == end1) return;
    for (int i = 0; i < v[node].size(); i++) {  //所有的邻接点都对应一条路径
        if (visit[v[node][i]] == 0) {
            visit[v[node][i]] = 1;
            tempPath.push_back(v[node][i]);
            dfs(v[node][i], cnt + 1);
            visit[v[node][i]] = 0;
            tempPath.pop_back();
        }
    }
}

int main() {
    int n, m, k, pre, temp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &m, &pre);
        for (int j = 1; j < m; j++) {
            scanf("%d", &temp);
            v[pre].push_back(temp);
            v[temp].push_back(pre);
            line[pre*10000+temp] = line[temp*10000+pre] = i + 1;
            pre = temp;
        }
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d%d", &start, &end1);
        minCnt = 99999, minTransfer = 99999;
        tempPath.clear();
        tempPath.push_back(start);
        visit[start] = 1;
        dfs(start, 0);  //过后path装着整条路线，正向的路径
        visit[start] = 0;
        printf("%d\n", minCnt);
        int preLine = 0, preTransfer = start;
        for (int j = 1; j < path.size(); j++) {
            if (line[path[j-1]*10000+path[j]] != preLine) {
                if (preLine != 0) printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, path[j-1]);
                preLine = line[path[j-1]*10000+path[j]];
                preTransfer = path[j-1];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, end1);
    }
    return 0;
}