/*1032
#include <iostream>
#include <map>
#include <vector>
#include <list>
using namespace std;
map<int,int> mp;   //当前节点与下一个节点
int main(){
    int fs,ss,n;
    char c1,c2;
    cin>>fs>>ss>>n;
    for(int i=0;i<n;i++){
        int start,end;char c;
        cin>>start>>c>>end;
        mp[start]=end;
    }
    int next=mp[fs];
    list<int> l1,l2;
    while(next!=-1){
        l1.push_back(next);
        next=mp[next];      //把next放进去
    }
    l1.push_back(next);
    next=mp[ss];
    while(next!=-1){
        l2.push_back(next);
        next=mp[next];
    }
    l2.push_back(next);
    l1.pop_back();
    l2.pop_back();
    while(l1.back()==l2.back()&&l1.size()>0&&l2.size()>0){
        l1.pop_back();
        l2.pop_back();
    }
    if(mp[l1.back()]==mp[l2.back()])
        cout<<mp[l1.back()];
    else
        cout<<"-1";
    return 0;
}
*/

//1052
/*
#include <iostream>
#include <map>
#include <algorithm>
#include <list>
using namespace std;
struct node{
    int start;      //知道key怎么找下一个key？除非建立另外一个map
    int next;
};
map<int,node> mp;       //int对应node
map<int,int> findkey;
int main(){
    int n,begin,beginkey;
    cin>>n>>begin;
    for(int i=0;i<n;i++){
        int start,key,next;
        cin>>start>>key>>next;      //wrong?
        mp[key].start=start;
        mp[key].next=next;
        findkey[start]=key;     //通过节点找key
        if(start==begin)
            beginkey=key;
    }
    int next=beginkey;
    list<int> l;        //记录每一个点编号
    while(mp[next].next!=-1){   //得通过next编号去寻找下一个点，但同时l又得依靠key升序
        l.push_back(next);
        next=findkey[mp[next].next];
    }
    l.push_back(next);
    l.sort();
    for(list<int>::iterator it=l.begin();it!=l.end();){
        if(it==l.begin())
            printf("%d %05d\n",l.size(),mp[*it].start);
        printf("%05d %d ",mp[*it].start,*it);
        it++;
        if(it==l.end())
            cout<<"-1"<<endl;
        else 
            printf("%05d\n",mp[*it].start);
    }
    return 0;
}
*/

/* 1052 静态链表
#include <iostream>
#include <map>
#include <algorithm>
#include <list>
using namespace std;
struct nodes{
    int start;
    int key;
    int next;
    bool flag;
}node[100000];
bool cmp(nodes a,nodes b){
    if(a.flag==false||b.flag==false)
        return a.flag>b.flag;
    return a.key<b.key;
}
int main(){
    int n,begin;
    cin>>n>>begin;
    for(int i=0;i<n;i++)
        node[i].flag=false;
    for(int i=0;i<n;i++){
        int start;cin>>start;
        cin>>node[start].key>>node[start].next;
        node[start].start=start;
    }    
    int next=begin;
    int count=0;
    while(node[next].next!=-1){
        node[next].flag=true;
        next=node[next].next;
        count++;
    }
    node[next].flag=true;
    next=node[next].next;
    count++;
    if(count==0)
        printf("0 -1");
    else{
        sort(node,node+100005,cmp);
        cout<<count<<" "<<node[0].start<<endl;
        for(int i=0;i<count-1;i++)
            printf("%05d %d %05d\n",node[i].start,node[i].key,node[i+1].start);
        printf("%05d %d -1\n",node[count-1].start,node[count-1].key);
    }
    return 0;
}
*/


//1097
#include <iostream>
#include <map>
#include <algorithm>
#include <list>
#include <iomanip>
#include <string.h>
#include <string>
using namespace std;
struct nodes{
    int start;
    int key;
    int next;
}node[100005];
map<int,bool> mp;   //查找key书否出现过
int main(){
    int n,begin;
    cin>>begin>>n;
    for(int i=0;i<n;i++){
        int start;cin>>start;
        cin>>node[start].key>>node[start].next;
        node[start].start=start;
    }    
    list<int> l1,l2;
    while(1){
        if(mp[abs(node[begin].key)]==0){//未出现
            mp[abs(node[begin].key)]=1;
            l1.push_back(begin);
        }
        else{//duplicated
            l2.push_back(begin);
        }
        if(node[begin].next==-1)
            break;
        begin=node[begin].next;
    }
    int len1=l1.size(),len2=l2.size();
    for(int i=0;i<len1;i++){
        printf("%05d %d ",l1.front(),node[l1.front()].key);
        if(l1.size()>1){
            l1.pop_front();
            printf("%05d\n",l1.front());
        }
        else
            cout<<"-1"<<endl;
    }
    for(int i=0;i<len2;i++){
        printf("%05d %d ",l2.front(),node[l2.front()].key);
        if(l2.size()>1){
            l2.pop_front();
            printf("%05d\n",l2.front());
        }
        else
            cout<<"-1"<<endl;
    }
    return 0;
}