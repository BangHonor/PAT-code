#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string.h>
#include <string>
using namespace std;
int main(){
    int n;
    cin>>n;
    set<int> s[50];
    for(int i=0;i<n;i++){
        int time;cin>>time;
        for(int j=0;j<time;j++){
            int num;cin>>num;
            s[i].insert(num);
        }
    }
    int k;
    cin>>k;

    for(int i=0;i<k;i++){
        int first,second;
        cin>>first>>second;
        int nc=0,nt=s[second-1].size();
        for(set<int>::iterator it=s[first-1].begin();it!=s[first-1].end();it++){
            if(s[second-1].find(*it)!=s[second-1].end())        //可能有误
                nc++;
            else
                nt++;        
        }
        float pos=(float)nc/nt*100;
        printf("%.01f%\n",pos);
    }
    return 0;
}