/*
//递归
const int maxv=10010;
int dp[maxv];
int f(int n){
    if(n==0||n==0)  return 1;
    if(dp[n]==-1){
        dp[n]=f(n-1)+f(n-2);  //实时记录
        return dp[n];
    }
    else
        return dp[n];
}

//递推
int dp[maxv][maxv],f[maxv][maxv];       //f记录每一个数，dp记录路径上最大的数
int main(){
    for(int i=1;i<=n;i++){
        for(int j=0;j<n;j++)
            dp[i][j]=f[i][j];       //初始化,从第一层开始
    }
    for(int i=n-1;i>=1;i--){
        for(int j=1;j<=i;j++)
            dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+f[i][j];
    }
    return 0;
}
*/

/*
//最大子序列
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    int dp[10000],n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>dp[i];
    //利用递推
    for(int i=1;i<n;i++){
        dp[i]=max(dp[i],dp[i-1]+dp[i]);
    }
    int maxn=-1;
    for(int i=0;i<n;i++){
        if(dp[i]>maxn)
            maxn=dp[i];
    }
    cout<<maxn;
    return 0;
}
*/

/*
//整数规划
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    int dp[100][100],n,m;
    cin>>n>>m;
    //初始化
    for(int i=1;i<=n;i++)
        dp[i][1]=1;
    for(int i=2;i<=m;i++)
        dp[1][i]=0;
    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            if(i>=j) dp[i][j]=dp[i-j][j]+dp[i-1][j-1];
            else dp[i][j]=0;
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}
*/

/*
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int A[100],dp[100]={1};
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>A[i];
    for(int i=1;i<n;i++){
        int flag=0;
        for(int j=0;j<i;j++){
            if(A[i]>=A[j]&&dp[j]+1>dp[i])
                dp[i]=dp[j]+1;
        }
    }
    int maxn=-1;
    for(int i=0;i<n;i++){
        if(dp[i]>maxn)
            maxn=dp[i];
    }
    cout<<maxn;
    return 0;
}
*/

/*
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int A[100],dp[100]={1};
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>A[i];
    for(int i=1;i<n;i++){
        int flag=0;
        for(int j=0;j<i;j++){
            if(A[i]>=A[j]&&dp[j]+1>dp[i])
                dp[i]=dp[j]+1;
        }
    }
    int maxn=-1;
    for(int i=0;i<n;i++){
        if(dp[i]>maxn)
            maxn=dp[i];
    }
    cout<<maxn;
    return 0;
}
*/

/*  最长子序列问题，自定义排序规则
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
int A[10010],dp[10010],first[210];
int main(){
    fill(dp,dp+10010,1);
    fill(first,first+210,10000);
    int total,order,n;
    cin>>total>>order;
    for(int i=1;i<=order;i++){
        int num;
        cin>>num;
        first[num]=i;       //优先度
    }
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>A[i];
    for(int i=1;i<=n;i++){
        if(first[A[i]]==10000){//有可能全是不喜欢的颜色
            dp[i]=0;
            for(int j=1;j<i;j++){
                if(dp[j]>dp[i])
                    dp[i]=dp[j];      
            }
        }
        else{
            for(int j=1;j<i;j++){
                if(first[A[i]]>=first[A[j]]&&dp[j]+1>dp[i])
                    dp[i]=dp[j]+1;      
            }
        }
    }
    int maxn=-1;
    for(int i=1;i<=n;i++){
        if(dp[i]>maxn)
            maxn=dp[i];
    }
    cout<<maxn;
    return 0;
}
*/

//最长相同字符串

// #include <iostream>
// #include <algorithm>
// #include <cmath>
// #include <map>
// #include <string>
// #include <string.h>
// using namespace std;
// int main(){
//     string a,b;
//     cin>>a>>b;
//     int dp[100][100]={0};
//     int maxn=-1;
//     /*
//     for(int i=0;i<a.length();i++){
//         for(int j=0;j<b.length();j++){
//             if(a[i]==b[j]){
//                 dp[i][j]=dp[max(0,i-1)][max(0,j-1)]+1;
//             }
//             else
//                 dp[i][j]=max(dp[i][max(0,j-1)],dp[max(0,i-1)][j]);
//             maxn=max(maxn,dp[i][j]);
//         }
//     }
//     */
//    for(int i=0;i<=a.length();i++)
//         dp[i][0]=0;
//     for(int i=0;i<=b.length();i++)
//         dp[0][i]=0;
//     for(int i=1;i<=a.length();i++){
//         for(int j=1;j<=b.length();j++){
//             if(a[i]==b[j]){
//                 dp[i][j]=dp[i-1][j-1]+1;
//             }
//             else
//                 dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
//             maxn=max(maxn,dp[i][j]);
//         }
//     }
//     cout<<maxn;
//     return 0;
// }

/*
//最大回文子序列  A1040
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
#include <string.h>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    int len=s.length(),maxl=1;
    int dp[1010][1010];
    memset(dp,0,sizeof(dp));
    //初始化长度1 2
    for(int i=0;i<len;i++){
        dp[i][i]=1;
        if(i<len-1){
            if(s[i]==s[i+1]){
                dp[i][i+1]=1;
                maxl=2;
            }
        }
    }
    for(int l=3;l<=len;l++){        //长度从小到大进行遍历
        for(int i=0;i<=len-l;i++){     //从0开始向右遍历
            int right=i+l-1;
            if(s[i]==s[right]&&dp[i+1][right-1]==1){
                dp[i][right]=1;
                maxl=l;
            }
        }
    }
    cout<<maxl;
    return 0;
}
*/

/*
// DAG
int DP(int n){      //邻接矩阵实现,表示这一点出发能到达的最远距离
    if(dp[n]>0)
        return dp[n];
    for(int i=0;i<n;i++){
        if(G[i][n]!=inf){
            int temp=G[i][n]+DP[i];
            if(temp>dp[n]){
                dp[n]=temp;
                path[n]=i;
            }
        }
    }
    return dp[n];
}
*/

/*
//0-1背包
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
#include <string.h>
using namespace std;
int main(){
    int n,V,dp[100][100];
    cin>>n>>V;
    int c[100],w[100];
    for(int i=0;i<n;i++)
        cin>>w[i];
    for(int i=0;i<n;i++)
        cin>>c[i];
    int maxn=-1;
    for(int i=0;i<=V;i++){
        dp[0][i]=0;
        dp[i][0]=0;
    }
    for(int i=1;i<=n;i++){
        for(int v=w[i];v<=V;v++){
            dp[i][v]=max(dp[i-1][v],dp[i-1][v-w[i]]+c[i]);
            if(dp[i][v]>maxn)
                maxn=dp[i][v];
        }
    }
    cout<<maxn;
    return 0;
}
*/

//     用转移方程解决
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[10010], w[10010];
bool choice[10010][110];
int cmp1(int a, int b){return a > b;}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    sort(w + 1, w + n + 1, cmp1);
    for(int i = 1; i <= n; i++) {
        for(int j = m; j >= w[i]; j--) {
            if(dp[j] <= dp[j-w[i]] + w[i]) {
                choice[i][j] = true;
                dp[j] = dp[j-w[i]] + w[i];
            }
        }
    }
    if(dp[m] != m) printf("No Solution");
    else {
        vector<int> arr;
        int v = m, index = n;
        while(v > 0) {
            if(choice[index][v] == true) {
                arr.push_back(w[index]);
                v -= w[index];
            }
            index--;
        }
        for(int i = 0; i < arr.size(); i++) {
            if(i != 0) printf(" ");
            printf("%d", arr[i]);
        }
    }
    return 0;
}


//背包问题的dfs求解
/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <string.h>
using namespace std;
int n,v,w[10010],flag=0;
vector<int> temp;
vector<vector<int> > ans;
void dfs(int index,int sum){
    if(flag==1)
        return;
    if(sum==v){
        ans.push_back(temp);
        flag=1;
        return;
    }
    if(sum>v||index>=n)
        return;
    //两条路子，选或者不选
    temp.push_back(w[index]);
    dfs(index+1,sum+w[index]);
    temp.pop_back();
    dfs(index+1,sum);
}
int main(){
    cin>>n>>v;
    for(int i=0;i<n;i++)
        cin>>w[i];
    sort(w,w+n);
    dfs(0,0);
    if(flag==0)
        cout<<"No Solution"<<endl;
    else{
        cout<<ans[0][0];
        for(int i=1;i<ans[0].size();i++)
            cout<<" "<<ans[0][i];
    }
    return 0;
}
*/

