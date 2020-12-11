//1051
/*
#include <iostream>
#include <map>
#include <stack>
using namespace std;
int main(){
    int n,m,k;
    cin>>m>>n>>k;
    for(int i=0;i<k;i++){
        stack<int> s;       //遇到格式一样的分析组 循环后再初始化
        s.push(0);
        int a[1000];
        for(int j=0;j<n;j++)
            cin>>a[j];
        int j;
        int now=1;
        for(j=0;j<n;j++){
            if(a[j]>=s.top()){
                while(s.top()<a[j])
                    s.push(now++);
                if(s.size()-1>m){
                    cout<<"NO"<<endl;
                    break;
                }
                s.pop();
            }
            else{
                cout<<"NO"<<endl;
                break;
            }
        }
        if(j==n)
            cout<<"YES"<<endl;
    }
    return 0;
}
*/

//简单计算器
#include <iostream>
#include <map>
#include <stack>
#include <string.h>
#include <string>
#include <queue>
using namespace std;
struct node{            //统一格式
    int num;
    char op;
    bool flag;  //true是数
};
string in;
stack<node> s;
queue<node> q;   //后缀
map<char,int> mp;//优先级
void intTOpost(){       //将中缀化成后缀，方法：用stack装操作符进行比对，用q装全部进行待会的计算
    int num;
    node temp;
    for(int i=0;i<in.length();){
        //如果是数字
        if(in[i]>='0'&&in[i]<='9'){
            temp.flag=true;
            temp.num=in[i++]-'0';
            while(in[i]>='0'&&in[i]<='9'&&i<in.length()){
                temp.num=temp.num*10+(in[i]-'0');     //从高位向低位计数的技巧
                i++;
            }
            q.push(temp);
        }
        else{       //是操作符
            temp.flag=false;
            while(!s.empty()&&mp[s.top().op]>=mp[in[i]]){
                q.push(s.top());
                s.pop();            //直到前面全是比自己小的
            }
            temp.op=in[i];
            s.push(temp);   //注意：不会直接加到里面，每次经过比对都是从s pop出来的
            i++;
        }
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    return;
}
double cal(){
    stack<double> s1;
    double temp1,temp2;
    while(q.size()>0){
        if(q.front().flag==true) {//是数
            s1.push((double)q.front().num);
        }    
        else{
            temp1=s1.top();
            s1.pop();
            temp2=s1.top();
            s1.pop();
            double res;
            if(q.front().op=='+')
                res=temp1+temp2;
            else if(q.front().op=='-')
                res=temp1-temp2;
            else if(q.front().op=='*')
                res=temp1*temp2;
            else
                res=temp1/temp2;
            s1.push(res);
        }
        q.pop();
    }
    return s1.top();
}
int main(){
    //中缀表达式转化为后缀表达式
    cin>>in;
    mp['+']=1;mp['-']=1;mp['*']=2;mp['/']=2;
    while(!s.empty())
        s.pop();
    intTOpost();
    printf("%.2f",cal());
    return 0;
}