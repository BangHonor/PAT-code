#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string.h>
#include <string>
using namespace  std;
typedef long long ll;
/* 愚蠢的方法
int main(){
    int n;
    string a,b;
    cin>>n>>a>>b;
    ll aend,bend; //可能要改
    if(a.find('.')!=a.npos)
        aend=a.find('.')-1;       //最后一个的下标
    else
        aend=a.length()-1;
    if(b.find('.')!=b.npos)
        bend=b.find('.')-1;       //最后一个的下标
    else
        bend=b.length()-1;
    //没考虑0
    if(strcmp(a.substr(0,n).c_str(),b.substr(0,n).c_str())==0&&aend==bend){
        if(aend+1>=n)
            cout<<"YES"<<" 0."<<a.substr(0,n)<<"*10^"<<aend+1<<endl;
        else{
            cout<<"YES"<<" 0."<<a.substr(0,n);
            for(int i=0;i<n-aend-1;i++)
                cout<<"0";
            cout<<"*10^"<<aend+1<<endl;
        }
    }
    else{
        if(aend+1>=n)
            cout<<"NO"<<" 0."<<a.substr(0,n)<<"*10^"<<aend+1;
        else{
            cout<<"NO"<<" 0."<<a.substr(0,n);
            for(int i=0;i<n-aend-1;i++)
                cout<<"0";
            cout<<"*10^"<<aend+1;
        }
        if(bend+1>=n)
            cout<<" 0."<<b.substr(0,n)<<"*10^"<<bend+1;
        else{
            cout<<" 0."<<b.substr(0,n);
            for(int i=0;i<n-aend-1;i++)
                cout<<"0";
            cout<<"*10^"<<bend+1;
        }
    }
    return 0;
}
*/
int n;
string deal(string a,int &e){
    while(a[0]=='0'&&a.length()>0)
        a.erase(a.begin());     //删除前导零
    if(a[0]=='.'){//小于1
        a.erase(a.begin());
        e=-1;
        while(a[0]=='0'&&a.length()>0){
            a.erase(a.begin());     //删除前导零
            e--;
        }
    }
    else{       //大于1得数
        for(int i=0;a[i]!='.'&&i<a.length();i++,e++);
        if(e<a.length()){
            a.erase(a.begin()+e);
            e--;        //最终的次方数
        }
    }
    int lena=a.length();
    if(a.length()==0)
        e=0;
    if(a.length()>=n)
        a=a.substr(0,n);
    else
    {
        for(int i=0;i<n-lena;i++)
            a+='0';
    }
    return a;
}
int main(){
    string a,b;
    cin>>n>>a>>b;
    int e1=0,e2=0;
    a=deal(a,e1);
    b=deal(b,e2);
    if(strcmp(a.c_str(),b.c_str())==0)
        cout<<"YES"<<" 0."<<a<<"*10^"<<e1<<endl;
    else
        cout<<"NO"<<" 0."<<a<<"*10^"<<e1<<" 0."<<b<<"*10^"<<e2<<endl;
    return 0;
}
