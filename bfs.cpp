/*
#include <iostream>
#include <math.h>
#include <vector>
#include <deque>
using namespace std;
int m,n,l,t;
int node[130][1290][61];        //横竖纵
bool flag[130][1290][61]={false};
int dx[6]={-1,0,1,0,0,0};
int dy[6]={0,-1,0,1,0,0};
int dz[6]={0,0,0,0,1,-1};
struct three{
    int x,y,z;
}xyz;
bool judge(int x,int y,int z){
    if(x>=m||x<0||y>=n||y<0||z>=l||z<0)
        return false;
    if(node[x][y][z]==0||flag[x][y][z]==1)
        return false;
    return true;
}
int bfs(int x,int y,int z){     //深度优先需要的参数，当前坐标，从零开始
    int cnt=0;
    deque<three> q;
    flag[x][y][z]=true;        //所有的点都会遍历一遍，用于记录某一个点用不用调查
    xyz.x=x;xyz,y=y;xyz.z=z;
    q.push_back(xyz);     //符合要求的才进去
    while(q.size()>0){      //对所有没搜索过的邻接点遍历,0直接不分析
        int xx=q.front().x;
        int yy=q.front().y;
        int zz=q.front().z;
        cnt++;      //只在出队记录即可
        q.pop_front();
        for(int i=0;i<6;i++){
            int newx=xx+dx[i],newy=yy+dy[i],newz=zz+dz[i];
            if(judge(newx,newy,newz)){
                flag[newx][newy][newz]=true;       //已经遍历
                xyz.x=newx;
                xyz.y=newy;
                xyz.z=newz;
                q.push_back(xyz);
            }
        }
    }
    if(cnt>=t)
        return cnt;
    else
        return 0;
}
int main(){
    cin>>n>>m>>l>>t;        //m*n矩阵
    for(int k=0;k<l;k++){
        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++)
                cin>>node[i][j][k];
        }
    }
    int num=0;
    for(int k=0;k<l;k++){
        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                if(node[i][j][k]==1&&flag[i][j][k]==false)
                    num+=bfs(i,j,k);
            }
        }
    }
    cout<<num;
    return 0;
}
*/

#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;
struct node{
    int x,y,step;
};
bool flag[10][10]={false};      //程序外初始化？
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int m,n,step=0;
char a[10][10];
queue<node> q;
int judge(int x,int y){
    if(a[y][x]=='T')
        return 1;
    else if(a[y][x]!='*'&&x>=0&&x<m&&y>=0&&y<n&&flag[y][x]==false)
        return 0;
    else
        return -1;
}
void bfs(int starty,int startx){
    node qnode;
    qnode.x=startx;
    qnode.y=starty;
    qnode.step=0;
    flag[starty][startx]=true;
    q.push(qnode);
    while(!q.empty()){
        qnode=q.front();
        q.pop();
        step++;
        for(int i=0;i<4;i++){
            int x=qnode.x+dx[i];
            int y=qnode.y+dy[i];
            if(judge(x,y)==0){
                node temp;
                temp.x=x;
                temp.y=y;
                temp.step=qnode.step+1;
                flag[y][x]=true;
                q.push(temp);
                cout<<x<<" "<<y<<endl;
            }
            else if(judge(x,y)==1){
                printf("%d",qnode.step+1);
                return;
            }
        }
    }
}
int main(){
    int startx,starty;
    cin>>m>>n>>startx>>starty;
    for(int i=0;i<n;i++){
        getchar();
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    }
    bfs(starty,startx);
    return 0;
}