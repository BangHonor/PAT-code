#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
struct mouse{
    int rank;
    int weight;
}m[1000];       //可能错
int main(){
    int np,ng,total;
    cin>>np>>ng;
    total=np;
    queue<int> q;   //在最前面出，最后面进
    for(int i=0;i<np;i++)
        cin>>m[i].weight;
    for(int i=0;i<np;i++){
        int order;
        cin>>order;
        q.push(order);//记录顺序
    }
    while(np>1){
        int group,temp=ng;
        if(np%ng==0)
            group=np/ng;
        else
            group=np/ng+1;
        for(int i=0;i<group;i++){       //group个组
            if(i==group-1)
                ng=np-ng*(group-1);
            int max=-1,maxq; //小组内最大的数
            for(int j=0;j<ng;j++){
                if(m[q.front()].weight>max){      //q应该编号
                    max=m[q.front()].weight;
                    maxq=q.front();
                }
                m[q.front()].rank=group+1;        //rank最大排名最高
                q.pop();
            }
            q.push(maxq);        //最大值加到最后下次进行分析,记录编号;
        }   
        ng=temp;
        np=group;
    }       //排好队后order再也无用
    m[q.front()].rank=1;      //最后一个   
    cout<<m[0].rank;
    for(int i=1;i<total;i++)
        cout<<" "<<m[i].rank;
    return 0;
}