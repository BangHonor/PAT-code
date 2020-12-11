/*
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main(){
    int n,num;
    cin>>n;
    map<int,int> mp;
    vector<int> v;
    for(int i=0;i<n;i++){
        cin>>num;
        mp[num]++;
        v.push_back(num);
    }
    for(int i=0;i<v.size();i++){
        if(mp[v[i]]==1){
            cout<<v[i];
            return 0;
        }
    }
    cout<<"None";
    return 0;
}
*/

/*
#include <iostream>
#include <map>
#include <string.h>
#include <string>
using namespace std;
int main(){
    string s1,s2;
    getline(cin,s1);        //头文件string
    getline(cin,s2);
    map<char,int> mp;
    for(int i=0;i<s2.length();i++){
        mp[s2[i]]=1;
    }
    for(int i=0;i<s1.length();i++){
        if(mp[s1[i]]==0)
            cout<<s1[i];
    }
    return 0;;
}
*/

#include <iostream>
#include <map>
#include <string.h>
#include <string>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;      //n枚硬币，m为付款额
    map<int,int> mp;
    for(int i=0;i<n;i++){       //慎用bool,否则mapp[1] map[2]都一样
        int num;cin>>num;
        mp[num]++;
    }
    for(map<int,int>::iterator it=mp.begin();it!=mp.end()&&it->first<=m-it->first;it++){
        if(mp[it->first]&&mp[m-it->first]&&it->first!=m-it->first){
            cout<<it->first<<" "<<m-it->first;
            return 0;
        }     
    }
    if(mp[m/2]>1&&m%2==0){
        cout<<m/2<<" "<<m/2;
        return 0;
    }   
    cout<<"No Solution";
    return 0;
}