
/*
int main(){
    map<string,int> mp;
    string a;
    getline(cin,a);
    int i=0;
    while(i<a.length()){
        string temp="";
        int flag=0,start=i;
        while((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z')){
            if(a[i]>='A'&&a[i]<='Z')
                a[i]+=32;
            temp+=a[i];
            flag=1;
            i++;
        }
        if(flag==1&&(a[i]<'0'||a[i]>'9'||i==a.length())&&((a[start-1]<'0'||a[start-1]>'9')||i==0))
            mp[temp]++;
        i++;
    }
    string maxstring;
    int max=0;
    for(map<string,int>::iterator it=mp.begin();it!=mp.end();it++){
        if(it->second>max){
            max=it->second;
            maxstring=it->first;
        }
    }
    if(max==0)
        cout<<"0";
    else
        cout<<maxstring<<" "<<max<<endl;
    return 0;
}
*/

/*1022 低效！要查什么，什么作为对象！
struct book{
    int id;
    string title;
    string author;
    string keyword;
    string publisher;
    int year;
};
vector<book> v;
bool cmp(book a,book b){
    return a.id<id;
}
int main(){ 
    int n;
    cin>>n;getchar();
    for(int i=0;i<n;i++){
        book b;
        cin>>id;getchar();getline(cin,title);getline(cin,author);getline(cin,keyword);
        getline(cin,publisher);getchar();cin>>year;
        v.push_back(b);
    }
    sort(v.begin(),v.end(),cmp);
    cout<<v[1].id<<v[1].author<<v[1].keyword<<endl;
    return 0;
}
*/

/*
#include <iostream>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
map<string,vector<int> > mpname,mpauthor,mpkeyword,mppublisher,mpyear;
int n;
void print(int num,string temp){
    int i=0;
    switch(num){
        case 1:{
            sort(mpname[temp].begin(),mpname[temp].end());
            for(i=0;i<mpname[temp].size();i++)
                cout<<mpname[temp][i]<<endl;
            break;
        }
        case 2:{
            sort(mpauthor[temp].begin(),mpauthor[temp].end());
            for(i=0;i<mpauthor[temp].size();i++)
                cout<<mpauthor[temp][i]<<endl;
            break;
        }
        case 3:{
            sort(mpkeyword[temp].begin(),mpkeyword[temp].end());
            for(i=0;i<mpkeyword[temp].size();i++)
                cout<<mpkeyword[temp][i]<<endl;
            break;
        }
        case 4:{
            sort(mppublisher[temp].begin(),mppublisher[temp].end());
            for(i=0;i<mppublisher[temp].size();i++)
                cout<<mppublisher[temp][i]<<endl;
            break;
        }
        case 5:{
            sort(mpyear[temp].begin(),mpyear[temp].end());
            for(i=0;i<mpyear[temp].size();i++)
                cout<<mpyear[temp][i]<<endl;
            break;
        }
    }
    if(i==0)
        cout<<"Not Found"<<endl;
    return;
}
int main(){
    cin>>n;getchar();
    for(int i=0;i<n;i++){
        int id;
        string name,author,keyword,publisher,year;
        cin>>id;getchar();getline(cin,name);getline(cin,author);
        getline(cin,keyword);getline(cin,publisher);getline(cin,year);
        //对关键字进行处理
        for(int j=0;j<keyword.length();j++){
            string temp="";
            while(keyword[j]!=' '&&j<keyword.length())
                temp+=keyword[j++];
            mpkeyword[temp].push_back(id);
        }
        mpname[name].push_back(id);
        mpauthor[author].push_back(id);
        mpkeyword[keyword].push_back(id);
        mppublisher[publisher].push_back(id);
        mpyear[year].push_back(id);
        //cout<<mpname[name][0]<<"!!!!!"<<endl;
    }
    int k;cin>>k;
    for(int i=0;i<k;i++){
        int num;string temp;
        scanf("%d: ",&num);/////////注意一下,scanf后面不能带getchar()
        getline(cin,temp);
        cout<<num<<": "<<temp<<endl;
        print(num,temp);
    }
    return 0;
}
*/

