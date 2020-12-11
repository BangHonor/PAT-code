/*
struct people{
    bool vip,played;
    int come,begin,playtime1,wait;
}p[10010];
struct table{
    bool vip;
    int last,num;
}t[101];    //从0开始
bool cmp(people a,people b){
    return a.come<b.come;
}
const int inf=10000000;
int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int h,m,s;
        scanf("%d:%d:%d %d %d",&h,&m,&s,&p[i].playtime1,&p[i].vip);
        int come=h*3600+m*60+s;
        p[i].come=come;
        p[i].played=0;
    }
    int tablenum,vipnum;
    cin>>tablenum>>vipnum;
    for(int i=1;i<tablenum;i++){
        t[i].vip=0;
        t[i].last=0;
        t[i].num=0;
    }
    for(int i=0;i<vipnum;i++){
        int index;
        cin>>index;
        t[index].vip=1;
    }
    sort(p,p+n,cmp);
    int last=0;     //轮到谁了
    while(1){
        int index=-1,mintime1=inf;
        for(int i=1;i<=tablenum;i++){ //得到最早结束的那张台
            if(t[i].last<mintime1){
                index=i;
                mintime1=t[i].last;
            }
        }   
        if(mintime1>21*3600||last>=n)
            break;  //如果还没结束，寻找下一对选手
        if(t[index].vip==0){    //不是vip台
            for(int i=last;i<n;i++){
                if(p[i].played==0){
                    //找到下家
                    int begintime1=max(p[i].come,mintime1);
                    p[i].played=1;
                    p[i].wait=begintime1-p[i].come;
                    p[i].begin=begintime1;
                    t[index].num++;
                    t[index].last=begintime1+p[i].playtime1;
                    last=i+1;
                    break;
                }
            }
        }
        else{       //vip台
            for(int i=last;i<n;i++){
                if(p[i].played==0&&p[i].vip==1){
                    //找到下家
                    int begintime1=max(p[i].come,mintime1);
                    p[i].played=1;
                    p[i].wait=begintime1-p[i].come;
                    p[i].begin=begintime1;
                    t[index].num++;
                    t[index].last=begintime1+p[i].playtime1;
                    break;
                }
            }
        }
    }
    int i=0;
    while(i<n){
        if(p[i].played==0)
            continue;
        printf("%02d:%02d:%02d ",p[i].come/3600,p[i].come/60%60,p[i].come%60);
        printf("%02d:%02d:%02d ",p[i].begin/3600,p[i].begin/60%60,p[i].begin%60);
        printf("%d\n",p[i].wait);
        i++;
    }
    return 0;
}
*/

/*
int main(){
    int n,num=0;
    long double a[100010],sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        cin>>a[i];
   for(int i=0;i<n;i++)
        sum+=a[i]*(n-i)*(i+1);
    printf("%.02llf",sum);
    return 0;
}
*/
/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
//螺旋矩阵
bool cmp(int a,int b){
    return a>b;
}
int main(){
    int n;
    cin>>n;
    int a[10010];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int matrix[110][110];
    sort(a,a+n,cmp);
    int n1=sqrt(n),m1;
    while(1){
        if(n%n1==0){
            m1=n/n1;
            break;
        }
        n1--;       //m1行大于n1列
    }
    int now=0;
    int x=0,y=0;
    int up=0,bottom=m1-1,left=0,right=n1-1; //界限，可取到
    while(now<n){
        //右下左上
        while(x<=right)
            matrix[y][x++]=a[now++];
        if(now>=n)
            break;
        x--;
        up++;
        y++;
        while(y<=bottom)
             matrix[y++][x]=a[now++];
        if(now>=n)
            break;
        right--;
        y--;
        x--;
        while(x>=left)
            matrix[y][x--]=a[now++];
        if(now>=n)
            break;
        bottom--;
        x++;
        y--;
        while(y>=up)
            matrix[y--][x]=a[now++];
        if(now>=n)
            break;
        y++;
        x++;
        left++;
    }
    for(int i=0;i<m1;i++){
        for(int j=0;j<n1-1;j++)
            cout<<matrix[i][j]<<" ";
        cout<<matrix[i][n1-1]<<endl;
    }
    return 0;
}
*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
struct node{
    vector<int> child;
    int lay;
}a[100010];
int minlay=10000,minnum=0;
void dfs(int index,int lay){
    if(a[index].child.size()==0){
        if(a[index].lay<minlay){
            minlay=a[index].lay;
            minnum=1;
        }
        else if(a[index].lay==minlay)
            minnum++;
    }
    for(int i=0;i<a[index].child.size();i++){
        a[a[index].child[i]].lay=lay+1;
        dfs(a[index].child[i],lay+1);
    }
}
int main(){
    int n;
    float p,tao;
    cin>>n>>p>>tao;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        for(int j=0;j<num;j++){
            int child;cin>>child;
            a[i].child.push_back(child);
        }
    }
    a[0].lay=0;
    dfs(0,0);
    float minp=p*pow((1+tao/100),minlay);
    printf("%.04f %d",minp,minnum);
    return 0;
}
*/

/*
//复杂写法      有理有据   但是复杂啊啊啊啊啊啊啊啊
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <string>
using namespace std;
int main(){
    int n,num=0;
    cin>>n;
    float sum=0;
    for(int i=0;i<n;i++){
        string a;
        cin>>a;
        int len=a.length();
        vector<int> fu;
        vector<int> dian;  
        vector<int> el;
        for(int j=0;j<len;j++){
            if((a[j]>'9'||a[j]<'0')&&a[j]!='.'&&a[j]!='-'){
                cout<<"ERROR1: "<<a<<" is not a legal number"<<endl;
                el.push_back(j);
                break;
            }
            else if(a[j]=='-')
                fu.push_back(j);
            else if(a[j]=='.')
                dian.push_back(j);
        }
        //进行判断
        if(fu.size()>1||(fu.size()==1&&fu[1]!=0))
            cout<<"ERROR2: "<<a<<" is not a legal number"<<endl;
        else if(dian.size()>1||(dian.size()==1&&len-dian[0]>3))
            cout<<"ERROR3: "<<a<<" is not a legal number"<<endl;
        else if(el.size()==0){
            //判断大小是否适合
            float b=atof(a.c_str());
            if(-1000<=b&&b<=1000){      //不可以连着写
                num++;
                sum+=b;
            }
            else
                cout<<"ERROR4: "<<a<<" is not a legal number"<<endl;
        }
    }
    if(num==0)
        cout<<"The average of 0 numbers is Undefined"<<endl;
    else{
        float ave=sum/num;
        printf("The average of %d numbers is %.02f",num,ave);
    }
    return 0;
}
*/
//简单写法
/*
#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
int main() {
    int n, cnt = 0;
    char a[50], b[50];
    double temp = 0.0, sum = 0.0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        scanf("%s", a);
        sscanf(a, "%lf", &temp);
        sprintf(b, "%.2f",temp);
        cout<<temp<<" "<<b<<endl;
        int flag = 0;
        for(int j = 0; j < strlen(a); j++)
            if(a[j] != b[j]) flag = 1;
        if(flag || temp < -1000 || temp > 1000) {
            printf("ERROR: %s is not a legal number\n", a);
            continue;
        } else {
            sum += temp;
            cnt++;
        }
    }
    if(cnt == 1)
        printf("The average of 1 number is %.2f", sum);
    else if(cnt > 1)
        printf("The average of %d numbers is %.2f", cnt, sum / cnt);
    else
        printf("The average of 0 numbers is Undefined");
    return 0;
}
*/


// #include <iostream>
// #include <cstdio>
// #include <string.h>
// #include <string>
// #include <queue>
// #include <stdlib.h>
// using namespace std;
// const int inf=10010;
// struct Node{
//     int left,right,index;
// }node[21];
// void dfs(int now,int index){    //赋予index,其实不需要得到每一个的index，只需要判断最后一个的index即可
//     if(node[now].left==inf&&node[now].right==inf)
//         return;
//     if(node[now].left!=inf){
//         node[node[now].left].index=2*index;
//         dfs(node[now].left,2*index);
//     }
//     if(node[now].right!=inf){
//         node[node[now].right].index=2*index+1;
//         dfs(node[now].right,2*index+1);
//     }
// }
// // int layindex=1;
// // bool layTraverse(int root){     //判断index是否符合层序遍历
// //     queue<int> q;
// //     q.push(root);
// //     while(!q.empty()){
// //         int front=q.front();
// //         q.pop();
// //         if(node[front].left!=inf){
// //             q.push(node[front].left);
// //             layindex++;
// //             if(node[node[front].left].index!=layindex)
// //                 return false;
// //         }
// //         if(node[front].right!=inf){
// //             q.push(node[front].right);
// //             layindex++;
// //             if(node[node[front].right].index!=layindex)
// //                 return false;
// //         }
// //     }
// //     return true;
// // }
// int main() {
//     int n;
//     cin>>n;
//     int father[21];
//     for(int i=0;i<n;i++)
//         father[i]=i;
//     for(int i=0;i<n;i++){
//         string a,b;
//         cin>>a>>b;
//         if(a[0]!='-'){
//             node[i].left=atoi(a.c_str());
//             father[node[i].left]=i;
//         }
//         else
//             node[i].left=inf;
//         if(b[0]!='-'){
//             node[i].right=atoi(b.c_str());
//             father[node[i].right]=i;
//         }
//         else
//             node[i].right=inf;
//     }
//     int root=0;
//     while(father[root]!=root)
//         root=father[root];
//     node[root].index=1;
//     dfs(root,1);
//     int last,maxindex=-1;
//     for(int i=0;i<n;i++){
//         if(node[i].index>maxindex){
//             last=i;
//         }
//     }
//     // if(layTraverse(root)==true){
//     //     int ans;
//     //     for(int i=0;i<n;i++){
//     //         if(node[i].index==n){
//     //             ans=i;
//     //             break;
//     //         }
//     //     }
//     //     cout<<"YES "<<ans;
//     // }
//     // else
//     //     cout<<"NO "<<root;
//     if(node[last].index==n)
//         cout<<"YES "<<last;
//     else
//         cout<<"NO "<<root;
//     return 0;
// }


/*
//两个dijkstra
#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>
#include <queue>
#include <vector>
#include <stdlib.h>
using namespace std;
const int inf=10000;
int n,m;
int gd[510][510],gt[510][510],dist[510],time1[510];
vector<int> pred[510],pret[510];
int s,d;
void dijkstra1(){
    int flag[510]={0};
    dist[s]=0;
    for(int k=0;k<n;k++){
        int mind=inf,index=-1;
        for(int i=0;i<n;i++){
            if(dist[i]<mind&&flag[i]==0){
                mind=dist[i];
                index=i;
            }
        }
        if(index==-1)   return;
        flag[index]=1;
        for(int i=0;i<n;i++){
            if(gd[index][i]!=inf&&flag[i]==0){  //没遍历过的邻接点
                if(dist[index]+gd[index][i]<dist[i]){
                    dist[i]=dist[index]+gd[index][i];
                    pred[i].clear();
                    pred[i].push_back(index);
                }
                else if(dist[index]+gd[index][i]==dist[i])
                    pred[i].push_back(index);
            }
        }
    }
}
void dijkstra2(){
    int flag[510]={0};
    time1[s]=0;
    for(int k=0;k<n;k++){
        int mint=inf,index=-1;
        for(int i=0;i<n;i++){
            if(time1[i]<mint&&flag[i]==0){
                mint=time1[i];
                index=i;
            }
        }
        if(index==-1)   return;
        flag[index]=1;
        for(int i=0;i<n;i++){
            if(gt[index][i]!=inf&&flag[i]==0){  //没遍历过的邻接点
                if(time1[index]+gt[index][i]<time1[i]){
                    time1[i]=time1[index]+gt[index][i];
                    pret[i].clear();
                    pret[i].push_back(index);
                }
                else if(time1[index]+gt[index][i]==time1[i])
                    pret[i].push_back(index);
            }
        }
    }
}
vector<int> tempd,tempt,bestd,bestt;
int mint=inf,mini=inf;
void dfs1(int d,int t){
    if(d==s){
        if(t<mint){
            bestd.clear();
            bestd=tempd;
            mint=t;
        }
        return;
    }
    for(int i=0;i<pred[d].size();i++){
        tempd.push_back(pred[d][i]);
        dfs1(pred[d][i],t+gt[pred[d][i]][d]);
        tempd.pop_back();
    }
}
void dfs2(int d,int i){
    if(d==s){
        if(i<mini){
            bestt.clear();
            bestt=tempt;
            mini=i;
        }
        return;
    }
    for(int j=0;j<pret[d].size();j++){
        tempt.push_back(pret[d][j]);
        dfs2(pret[d][j],i+1);
        tempt.pop_back();
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){   //初始化
        for(int j=0;j<n;j++){
            gd[i][j]=inf;
            gt[i][j]=inf;
        }
        dist[i]=time1[i]=inf;
    }
    for(int i=0;i<m;i++){
        int start,end,dir,len,t;
        cin>>start>>end>>dir>>len>>t;
        gd[start][end]=len;
        gt[start][end]=t;
        if(dir==1){
            gd[end][start]=inf;
            gt[end][start]=inf;
        }
        else{
            gd[end][start]=len;
            gt[end][start]=t;
        }
    }
    cin>>s>>d;
    dijkstra1();
    dijkstra2();
    dfs1(d,0);
    dfs2(d,0);
    if(bestd!=bestt){
        cout<<"Distance = "<<dist[d]<<": ";
        for(int i=bestd.size()-1;i>=0;i--)
            cout<<bestd[i]<<" -> ";
        cout<<d<<endl;
        cout<<"Time = "<<time1[d]<<": ";
        for(int i=bestt.size()-1;i>=0;i--)
            cout<<bestt[i]<<" -> ";
        cout<<d<<endl;
    }
    else{
        cout<<"Distance = "<<dist[d]<<"; "<<"Time = "<<time1[d]<<": ";
        for(int i=bestt.size()-1;i>=0;i--)
            cout<<bestt[i]<<" -> ";
        cout<<d<<endl;
    }
    return 0;
}
*/

/*  坏键盘
#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>
#include <map>
#include <vector>
#include <stdlib.h>
using namespace std;
int main(){
    //一旦发现有不符合的情况，这个字母就不是坏的。
    //如果发现符合了，得结合之前的情况进行考虑。
    int k;//0表示没判断过，1表示可以，2表示不行
    map<char,int> mp;       //判断是不是
    vector<char> v; //按出现顺序存储
    string a;
    cin>>k>>a;
    int now=0;
    while(now<a.length()){
        char first=a[now];
        if(mp[first]==0)
            v.push_back(first);
        int temp=now;
        while(a[temp]==first)
            temp++; //退出来的temp不符合条件
        int num=temp-now;
        if(num%k==0){   //符合次数要求，进一步判断
            if(mp[first]!=2)
                mp[first]=1;
        }
        else{       //不符合，不需要再判断，一定不是
            mp[first]=2;
        }
        now=temp; //接着来
    }
    for(int i=0;i<v.size();i++){
        if(mp[v[i]]==1)
            cout<<v[i];
    }
    cout<<endl;
    //按顺序输出
    for(int i=0;i<a.length();i++){
        if(mp[a[i]]!=1)
            cout<<a[i];
        else{
            int temp=i;
            while(a[temp]==a[i])
                temp++;
            int realout=(temp-i)/k;
            for(int j=0;j<realout;j++)
                cout<<a[i];
            i=temp-1;
        }
    }
}
*/

/* 1114 Family Property (25分) 树不适用
#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;
struct Node{
    vector<int> child;
    int set,father,mother;
    float area;
}node[10000];
struct temp{
    int minindex,family;
    float num,area;
};
vector<temp> v;
void dfs(int index,int minindex,int family,int num,float area){ 
    //index，最小的编号，房产数，房产面积  
    if(index<minindex)
        minindex=index;
    if(node[index].child.size()==0){
        float avenum=(float)num/family;
        float avearea=(float)area/family;
        temp a;
        a.minindex=minindex;a.family=family;
        a.num=(float)num/family;a.area=(float)area/family;
        v.push_back(a);
        return;
    }
    for(int i=0;i<node[index].child.size();i++){
        family+=node[index].child.size();
        if(node[node[index].child[i]].set!=0){
            num+=node[node[index].child[i]].set;
            area+=node[node[index].child[i]].area;
        }
    }
}
bool cmp(temp a,temp b){
    return a.area>b.area;
}
int main(){
    int n;
    cin>>n;
    int root;
    for(int i=0;i<n;i++){
        int id,father,mother,childnum,set;
        float area;
        cin>>id>>father>>mother>>childnum;
        node[i].father=father;
        node[i].mother=mother;
        for(int j=0;j<childnum;j++){
            int child;
            cin>>child;
            node[id].child.push_back(child);
        }
        cin>>node[id].set>>node[id].area;
    }
    //形成了网络，对父母的开始遍历即可
    for(int i=1000;i<10000;i++){
        if(node[i].father==node[i].mother==-1){
            //找到祖宗
            dfs(i,100001,1,0,0);
        }
    }
    cout<<v.size();
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++)
        printf("%d %d %.3f %.3f\n",v[i].minindex,v[i].family,v[i].num,v[i].area);
    return 0;
}
*/

/* 并查集
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
struct Node {
    int id,fid,mid;
    double num, area;
}node[10000];
struct Ans {
    int id, people;
    double num, area;
    bool flag;
}ans[10000];
int father[10000];
bool visit[10000];
int find(int x) {
    while(x != father[x])
        x = father[x];
    return x;
}
void Union(int a, int b) {
    int faA = find(a);
    int faB = find(b);
    if(faA > faB)
        father[faA] = faB;
    else if(faA < faB)
        father[faB] = faA;
}
bool cmp1(Ans a, Ans b) {
    if(a.area != b.area)
        return a.area > b.area;
    else
        return a.id < b.id;
}
int main(){
    int n, k, cnt = 0;
    scanf("%d", &n);
    for(int i = 0; i < 10000; i++)
        father[i] = i;
    bool visited[10000]={0};
    for(int i=0;i<n;i++){
        int id;
        cin>>id;
        node[id].id=id;
        scanf("%d %d %d", &node[id].fid, &node[id].mid, &k);
        visited[node[id].id]=1;
        if(node[id].fid!=-1){
            visited[node[id].fid]=1;
            Union(node[id].id,node[id].fid);
        }
        if(node[id].mid!=-1){
            visited[node[id].mid]=1;
            Union(node[id].id,node[id].mid);
        }
        for(int j=0;j<k;j++){
            int child;
            cin>>child;
            visited[child]=1;
            Union(node[id].id,child);
        }
        scanf("%lf %lf", &node[id].num, &node[id].area);
    }//这样下来所有的father都产生了
    for(int i=0;i<10000;i++){
        if(visited[i]==1){
            ans[i].id=i;
            int root=find(i);
            ans[root].id=root;
            ans[root].area+=node[i].area;
            ans[root].num+=node[i].num;
            ans[root].people++;
            ans[root].flag=true;
        }
    }
    for(int i=0;i<10000;i++){
        if(ans[i].flag==true){
            ans[i].area/=ans[i].people;
            ans[i].num/=ans[i].people;
        }
    }
    sort(ans,ans+10000,cmp1);
    for(int i=0;i<10000;i++){
        if(ans[i].flag==true)
            cnt++;
    }
    cout<<cnt<<endl;
     for(int i=0;i<10000;i++){
        if(ans[i].flag==true)
            printf("%04d %d %.3lf %.3lf\n",ans[i].id,ans[i].people,ans[i].num,ans[i].area);
    }
    //cout<<find(8888)<<endl;
    return 0;
}
*/

/*  爱丁顿树
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    int n;
    cin>>n;
    int a[100010];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n,cmp);
    int maxd=-1,day=1;
    for(int i=0;i<n;i++,day++){
        if(day>=a[i]){
            maxd=day-1; //应该以day为准，因为a是跳跃的
            break;
        }
    }
    cout<<maxd<<endl;
    return 0;
}
*/

/*
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
int father[10010];
int find(int x){
    while(father[x]!=x)
        x=father[x];
    return x;
}
void Union(int a,int b){
    int fa=find(a);;
    int fb=find(b);
    if(fa!=fb);
        father[fa]=fb;
    return;
}
int main(){
    int n=0;
    map<int,int> mp;
    for(int i=0;i<1010;i++)
        father[i]=i;
    int pic;
    cin>>pic;
    for(int i=0;i<pic;i++){
        int num;
        cin>>num;
        int bird1;
        cin>>bird1;
        if(mp[bird1]==0){
            mp[bird1]=1;
            n++;
        }
        for(int j=1;j<num;j++){
            int bird2;
            cin>>bird2;
            if(mp[bird2]==0){
                mp[bird2]=1;
                n++;
            }
            Union(bird1,bird2);
        }
    }
    //n为总数量，并查集操作完成
    int tree=0;
    for(int i=1;i<=n;i++){
        if(find(i)==i)
            tree++;
    }
    cout<<tree<<" "<<n<<endl;
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int a1,a2;
        cin>>a1>>a2;
        if(find(a1)==find(a2))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
*/

/*
#include <iostream>
#include <vector>
using namespace std;
vector<int> in, pre, post;
bool unique = true;
//pre：中左右  post：左右根
void getIn(int preLeft, int preRight, int postLeft, int postRight) {
    if(preLeft == preRight) {
        in.push_back(pre[preLeft]);
        return;
    }
    if (pre[preLeft] == post[postRight]) {//找到当前根节点，找左右节点
        int i = preLeft + 1;
        while (i <= preRight && pre[i] != post[postRight-1]) i++;
        //下面的总体思路：前中右
        if (i - preLeft > 1)        //左子树建树
            getIn(preLeft + 1, i - 1, postLeft, postLeft + (i - preLeft - 1) - 1);
        else        //无左子树，则不唯一，可左可右
            unique = false;
        in.push_back(post[postRight]);//中序：前中右
        //右子树建树
        getIn(i, preRight, postLeft + (i - preLeft - 1), postRight - 1);
    }
}
void getIn(int prel,int prer,int postl,int postr){
    if(prel == prer) {
        in.push_back(pre[prel]);
        return;
    }
    if(pre[prel]==post[postr]){//找到根节点
        int last=post[postr-1];//假设的根节点的右子节点
        //在前序序列中找到相应的位置；
        int i=prel+1;
        while(i<=prer&&pre[i]!=last) i++;
        int num=i-prel-1;//则左树有num个数
        if(num>0){
            getIn(prel+1,prel+1+num,postl,postl+num-1);//左子树
        }
        else
            unique=false;
        in.push_back(post[postr]);
        getIn(i,prer,postl+num,postr-1);//右子树
    }
}
int main() {
    int n;
    scanf("%d", &n);
    pre.resize(n), post.resize(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &post[i]);
    getIn(0, n-1, 0, n-1);
    printf("%s\n%d", unique == true ? "Yes" : "No", in[0]);
    for (int i = 1; i < in.size(); i++)
        printf(" %d", in[i]);
    printf("\n");
    return 0;
}
*/

/*
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
map<int,int> mp;    //记录次数
vector<int> v;        //记录已经有的数
bool cmp(int a,int b){
    if(mp[a]==mp[b])
        return a<b;
    return mp[a]>mp[b];
}
int main(){
    int n,k;
    cin>>n>>k;
    int num;
    cin>>num;
    mp[num]++;
    v.push_back(num);
    for(int i=1;i<n;i++){
        cin>>num;
        //输出现在为止最大的三个数
        sort(v.begin(),v.end(),cmp);    //超时，方法:使用set的自动二叉树排序
        //进行输出：
        cout<<num<<":";
        for(int j=0;j<k&&j<v.size();j++)
            cout<<" "<<v[j];
        cout<<endl;
        if(mp[num]==0)
            v.push_back(num);
        mp[num]++;
    }
    return 0;
}
*/


// //set排序
// #include <iostream>
// #include <vector>
// #include <map>
// #include <set>
// #include <algorithm>
// using namespace std;
// struct node{
//     int index,value;
//     node(int a,int b):index(a),value(b){}   
//     bool operator < (const node &a) const{  //重定义操作符
//         if(value==a.value)
//             return index<a.index;
//         return value>a.value;
//     }
// };
// int main(){
//     int n,k;
//     cin>>n>>k;
//     int num;
//     set<node> s;
//     int book[50010]={0};
//     cin>>num;
//     book[num]++;
//     s.insert(node(num,book[num]));
//     for(int i=1;i<n;i++){
//         cin>>num;
//         printf("%d:", num);
//         int tempcnt=0;
//         for(set<node>::iterator it = s.begin(); tempcnt < k && it != s.end(); it++) {
//             printf(" %d", it->index);
//             tempcnt++;
//         }
//         cout<<endl;
//         set<node>::iterator it=s.find(node(num,book[num]));
//         if(it!=s.end()) s.erase(it);
//         book[num]++;
//         s.insert(node(num,book[num]));
//     }
//     return 0;
// }

/*
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <CString>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string b;
        cin>>b;
        int a=atoi(b.c_str());  //string b=to_string(a);可用
        string left=b.substr(0,b.length()/2);
        string right=b.substr(b.length()/2,b.length()/2);
        int l=atoi(left.c_str());
        int r=atoi(right.c_str());
        int p=l*r;
        int flag=0;
        if(p!=0){
            if(a%p==0)
                flag=1;
        }
        if(flag==1)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
*/


/*
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
struct node{
    int data;
    int address,next;
}a[100010];
int start,n,k;
int main(){
    cin>>start>>n>>k;
    for(int i=0;i<n;i++){
        int address,data,next;
        cin>>address>>data>>next;
        a[address].address=address;
        a[address].data=data;
        a[address].next=next;
    }
    //先找出原来的顺序,对address排序
    vector<int> v,ans;
    int now=start;
    for(int i=0;i<n;i++){
        v.push_back(now);
        now=a[now].next;        //到-1结束
    }
    int flag=0;
    for(int i=0;i<n;i++){   //输出负的
        if(a[v[i]].data<0)
            ans.push_back(v[i]);
    }
    for(int i=0;i<n;i++){   //大于零小于等于K
        if(a[v[i]].data<=k&&a[v[i]].data>=0)
            ans.push_back(v[i]);
    }
    for(int i=0;i<n;i++){   //大于k
        if(a[v[i]].data>k)
            ans.push_back(v[i]);
    }
    for(int i=0;i<n-1;i++)
        printf("%05d %d %05d\n",ans[i],a[ans[i]].data,ans[i+1]);
    printf("%05d %d -1\n",ans[n-1],a[ans[n-1]].data);
    return 0;
}
*/

/*
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
using namespace std;
struct node{
    int first,second;
}e[10010];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
        cin>>e[i].first>>e[i].second;
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        int num,flag=1;
        cin>>num;
        map<int,int> mp;    //1代表里面，0代表外面
        for(int j=0;j<num;j++){
            int temp;
            cin>>temp;
            mp[temp]=1;
        }
        for(int j=0;j<m;j++){       //对边遍历
            if(mp[e[j].first]==0&&mp[e[j].second]==0){
                flag=0;
                break;
            }
        }
        if(flag==1)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
*/

/*
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
using namespace std;
struct node{
    string id;
    int assi,mid,final,flag;
    int total;
}stu[10010];    //一开始从1开始
map<string,int> mp;
bool cmp(node a,node b){
    if(a.total==b.total)
        return a.id<b.id;
    return a.total>b.total;
}
int main(){
    int p,m,n;
    cin>>p>>n>>m;
    int now=1;
    for(int i=0;i<p;i++){
        string id;
        int score;
        cin>>id>>score;
        if(mp[id]==0)
            mp[id]=now++;
        stu[mp[id]].id=id;
        stu[mp[id]].assi=score;
    }
    for(int i=0;i<m;i++){       //assi不过的可以不理
        string id;
        int score;
        cin>>id>>score;
        if(mp[id]==0)
            continue;
        stu[mp[id]].id=id;
        stu[mp[id]].mid=score;
    }
    for(int i=0;i<n;i++){
        string id;
        int score;
        cin>>id>>score;
        if(mp[id]==0)
            continue;
        stu[mp[id]].id=id;
        stu[mp[id]].final=score;
    }
    //进行判断
    for(int i=1;i<now;i++){
        int total;
        if(stu[i].mid>stu[i].final)     //attetion!!!
            total=0.4*stu[i].mid+0.6*stu[i].final+0.5;
        else
            total=stu[i].final+0.5;
        stu[i].total=total;
        if(stu[i].assi>=200&&total>=60)
            stu[i].flag=1;
    }
    sort(stu+1,stu+now,cmp);        //也许有问题
    for(int i=1;i<now;i++){
        if(stu[i].flag==1){
            if(stu[i].mid==0)
                stu[i].mid=-1;
            cout<<stu[i].id<<" "<<stu[i].assi<<" "<<stu[i].mid<<" "<<stu[i].final<<" "<<stu[i].total<<endl;
        }
    }
    return 0;
}\
*/

/*
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
using namespace std;
bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.first==b.first)
        return a.second<b.second;
    return a.first<b.first;
}
int main(){
    int n,m,k;
    cin>>n>>m;
    vector<int> v[10010];
    int a[310][310]={0};        //不然太大
    map<int,int> mp;    //把id映射到一个范围1-N;
    map<int,int> sex;
    int now=1;
    for(int i=0;i<m;i++){
        int first,second;
        cin>>first>>second;
        if(first<0){
            first=abs(first);
            sex[first]=1;//女记为1
        }
        if(second<0){
            second=abs(second);
            sex[second]=1;//女记为1
        }
        if(mp[first]==0)
            mp[first]=now++;
        if(mp[second]==0)
            mp[second]=now++;
        v[first].push_back(second);
        v[second].push_back(first);
        a[mp[first]][mp[second]]=a[mp[second]][mp[first]]=1;
    }
    cin>>k;
    for(int i=0;i<k;i++){
        int first,second;
        cin>>first>>second;
        first=abs(first);
        second=abs(second);
        vector<pair<int,int> > ans; 
        for(int j=0;j<v[first].size();j++){
            for(int k1=0;k1<v[second].size();k1++){
                if(sex[first]==sex[v[first][j]]&&sex[second]==sex[v[second][k1]]&&v[first][j]!=second&&v[second][k1]!=first){
                    int ff=mp[v[first][j]],sf=mp[v[second][k1]];
                    if(a[ff][sf]==1)
                        ans.push_back(make_pair(v[first][j],v[second][k1]));
                }
            }
        }
        cout<<ans.size()<<endl;
        //0000 -0000考虑怎么判断！只能用string
        if(ans.size()>1)
            sort(ans.begin(),ans.end(),cmp);
        for(int j=0;j<ans.size();j++)
            printf("%04d %04d\n",ans[j].first,ans[j].second);
    }
    return 0;
}
*/


/*
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
using namespace std;
int main(){
    string a;
    int n;
    cin>>a>>n;
    // for(int i=1;i<n;i++){       //n轮
    //     string temp;
    //     int j=0;
    //     while(j<a.length()){
    //         int num=1;
    //         while(a[j]==a[j+1]&&j<a.length()-1){
    //             j++;
    //             num++;
    //         }
    //         temp+=a[j];
    //         temp+="1";
    //         j++;
    //     }
    //     a=temp;
    // }
    // cout<<a<<endl;
    // return 0;
    a+="1";
    cout<<a;
    return 0;
}
*/

