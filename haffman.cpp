#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
priority_queue<long long,vector<long long>,greater<long long> > q;
int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        long long num;cin>>num;
        q.push(num);
    }
    while(q.size()!=1){
        long long first=q.top();
        q.pop();
        long long second=q.top();
        q.pop();
        long long sum=first+second;
        q.push(sum);
    }
    cout<<q.top();
    return 0;
}