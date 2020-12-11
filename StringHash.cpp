/*
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string.h>
#include <string>
using namespace std;
typedef long long ll;
const int maxl=1010;
const ll p=10000019,mod=1000000007;
vector<pair<ll,int> > pr1,pr2;
ll hash1[maxl]={0},hash2[maxl]={0};     //存储两个字符串的所有hash值
void Hash(string a,ll H[]){
    H[0]=a[0];   //自动转化为整数
    for(int i=1;i<a.length();i++)
        H[i]=(H[i-1]*p+a[i])%mod;
}
ll subHash(ll H[],int i,int j){
    if(i==0)    return H[j];
    ll ans=((H[j]-H[i-1]*p^(j-i+1))%mod+mod)%mod;
    return ans;
}
void calsubHash(int len,ll H[],vector<pair<ll,int> >&pr){
    for(int i=0;i<len;i++){
        for(int j=i;j<len;j++){
            ll value=subHash(H,i,j);
            pr.push_back(make_pair(value,j-i+1));
        }
    }
}
int getMaxLen(){
    int ans=0;
    for(int i=0;i<pr1.size();i++){
        for(int j=0;j<pr2.size();j++){
            if(pr1[i].first==pr2[j].first)
                ans=max(ans,pr1[i].second);
        }
    }
    return ans;
}
int main(){
    string a,b;
    cin>>a>>b;
    int lena=a.length(),lenb=b.length();
    Hash(a,hash1);
    Hash(b,hash2);
    calsubHash(lena,hash1,pr1);
    calsubHash(lenb,hash2,pr2);
    int maxlen=getMaxLen();
    cout<<maxlen;
    for(int i=0;i<lena;i++)
        cout<<hash1[i]<<" ";
    return 0;
}
*/
/*
const int maxv=10010;
int next1[maxv];
void getNext(char s[],int len){ //求解长度为len的字符串s的next少数族
    int j=-1;
    next1[0]=-1;
    for(int i=1;i<len;i++){
        while(j!=-1&&s[i]!=s[j+1])
            j=next1[j];
        if(s[i]==s[j+1])
            j++;
        next1[i]=j;
    }
}
*/


//1057 分块
#include <iostream>
#include <algorithm>
#include <math.h>
#include <stack>
#include <string.h>
#include <string>
using namespace std;
stack<int> s;
int each=sqrt(100000);      //each个块，每一块each个
int n,table[100010]={0},block[320]={0};
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        string order;
        cin>>order;
        if(order=="Pop"){
            if(s.size()>0){
                int top=s.top();
                s.pop();
                block[top/each]--;
                table[top]--;
                cout<<top<<endl;
            }
            else
                cout<<"Invalid"<<endl;
        }
        else if(order=="PeekMedian"){
            if(s.size()>0){
                int t=s.size()%2==0? s.size()/2 : (s.size()+1)/2;   //从1起的第i个
                int nowi=0,sum=block[0];
                while(sum<t)
                    sum+=block[nowi++]; //得出的nowi即为所在的块号
                int start=sum-block[nowi];      //现在已经有的
                //从这个区开始分析
                for(int i=nowi*each;i<=(nowi+1)*each-1;i++){
                    start+=table[i];
                    if(start>=t){
                        cout<<i<<endl;
                        break;
                    }
                }
            }
            else
                cout<<"Invalid"<<endl;
        }
        else{
            int num;        //0-each-1是第一个block
            cin>>num;
            s.push(num);
            block[num/each]++;
            table[num]++;       //数字对应编号
        }
    }
    return 0;
}