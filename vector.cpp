/* 1039  map<string,vector<int> >
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string.h>
#include <string>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;;
    map<string,vector<int> > mp;
    for(int i=0;i<k;i++){
        int course,num;
        cin>>course>>num;
        for(int j=0;j<num;j++){
            string name;
            cin>>name;
            mp[name].push_back(course);
        }
    }
    char name[10];      //可能要改
    while(scanf("%s",&name)!=EOF){
        string s(name);
        cout<<s<<" "<<mp[s].size();
        sort(mp[s].begin(),mp[s].end());
        for(int i=0;i<mp[s].size();i++)
            cout<<" "<<mp[s][i];
        cout<<endl;
    }
    return 0;
}
*/

/*
// 1039  vector<int> a[m]
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string.h>
#include <string>
using namespace std;
const int m=26*26*26*10+1;
vector<int> v[m];
int getID(string name){
    int id=0;
    for(int i=0;i<3;i++)
        id=id*26+(name[i]-'A');
    id=id*10+(name[3]-'0');
    return id;
}
int main(){
    int n,k;
    cin>>n>>k;;
    for(int i=0;i<k;i++){
        int course,num;
        cin>>course>>num;
        for(int j=0;j<num;j++){
            string name;
            cin>>name;
            int id=getID(name);
            v[id].push_back(course);
        }
    }
    char name[10];      //可能要改
    while(scanf("%s",&name)!=EOF){
        string s(name);
        int id=getID(s);
        cout<<s<<" "<<v[id].size();
        sort(v[id].begin(),v[id].end());
        for(int i=0;i<v[id].size();i++)
            cout<<" "<<v[id][i];
        cout<<endl;
    }
    return 0;
}
*/

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string.h>
#include <string>
using namespace std;
vector<int> v[2510];        //存名字的下标
char na[40010][5];       //名字对应下标
bool cmp(int a,int b){
    return strcmp(na[a],na[b])<0;
}
int main(){
    int n,k;
    cin>>n>>k;;
    for(int i=0;i<n;i++){
        int num;
        scanf("%s%d",&na[i],&num);
        for(int j=0;j<num;j++){
            int course;
            cin>>course;
            v[course].push_back(i);
        }
    }
    for(int i=1;i<=k;i++){
        printf("%d %d\n",i,v[i].size());
        sort(v[i].begin(),v[i].end(),cmp);
        for(int j=0;j<v[i].size();j++)
            printf("%s\n",na[v[i][j]]);
    }
    return 0;
}