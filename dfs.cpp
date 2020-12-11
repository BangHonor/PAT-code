/*
#include <iostream>
#include <math.h>
#include <vector>
#include <list>
using namespace std;
int n,k,p,maxsum=-1;
int fac[400];
vector<int> ans,temp;       //temp用于中间进行比较
void dfs(int index,int nowk,int sum,int facsum){
    if(sum==n&&nowk==k){
        if(facsum>maxsum){
            maxsum=facsum;
            ans=temp;
        }
        return;
    }
    if(sum>n||nowk>k)
        return;
    if(index>=1){
        temp.push_back(index);
        dfs(index,nowk+1,sum+fac[index],facsum+index);
        temp.pop_back();
        dfs(index,nowk,sum,facsum);
    }
}
int main(){     //和质因子分解问题不同，
//这里并没给出可以选取对象的范围，质因子问题中明确给了是质数
    cin>>n>>k>>p;
    int first=pow(float(n),(float)1/p);
    for(int i=first;i>=0;i--)
        fac[i]=pow(i,p);
    //cout<<first<<" "<<fac[12]<<endl;
    dfs(first,0,0,0);
    if(maxsum!=-1){
        cout<<n<<" = ";
        for(int i=0;i<ans.size();i++){
            if(i==0)
                cout<<ans[i]<<"^"<<p;
            else
                cout<<" + "<<ans[i]<<"^"<<p;        
        }
    }
    else
        cout<<"Impossible";
    return 0;        
}
*/


//选择最多钱的物品
/*
#include <iostream>
#include <math.h>
#include <vector>
#include <list>
using namespace std;
int n,w[10],c[10],maxc=-1,maxw;
void dfs(int index,int sumc,int sumw){
    if(index>n-1){
        if(sumc>maxc&&sumw<=maxw)
            maxc=sumc;
        return;
    }
    else{
        dfs(index+1,sumc+c[index],sumw+w[index]);     //选
        dfs(index+1,sumc,sumw);   //不选
    }
}
int main(){     
    cin>>n>>maxw;
    for(int i=0;i<n;i++)
        cin>>w[i];
    for(int i=0;i<n;i++)
        cin>>c[i];
    dfs(0,0,0);
    cout<<maxc;
    return 0;        
}
*/

//N个数里面选K个数问题
#include <iostream>
#include <math.h>
#include <vector>
#include <list>
using namespace std;
int n,k,a[10];
int nowk,nowsum,sum,maxsq=-1,index=0;
vector<int> temp,ans;
void dfs(int index,int nowk,int nowsum,int sq){
    if(nowk>k||nowsum>sum||index>=n)
        return;
    if(nowk==k&&nowsum==sum){
        if(sq>maxsq){
            ans=temp;
            maxsq=sq;
        }
        return;
    }
    temp.push_back(a[index]);
    dfs(index+1,nowk+1,nowsum+a[index],sq+a[index]^2);
    temp.pop_back();
    dfs(index+1,nowk,nowsum,sq);
}
int main(){     
    cin>>n>>k>>sum;
    for(int i=0;i<n;i++)
        cin>>a[i];
    dfs(0,0,0,0);    
    for(int i=0;i<ans.size();i++)
        cout<<ans[i];
    return 0;
}