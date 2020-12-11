#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;
const int maxn=10010;
int heap[maxn];     //里面已经有数据
void downAdjust(int low,int high){  //最大堆
    int i=low,j=2*low;
    while(j<=high){
        //总是选择更大的一边下沉
        if(j+1<=high&&heap[j+1]>heap[j])
            j++;
        if(heap[j]>heap[i]){
            int temp=heap[j];
            heap[j]=heap[i];
            heap[i]=temp;
            i=j;
            j=i*2;
        }
        else
            break;
    }
}
void buildHeap(int n){  //n是最大的下标，从一开始
    for(int i=n/2;i>=1;i--)
        downAdjust(i,n);
}
void deleteTop(int &n){
    heap[1]=heap[n--];
    downAdjust(1,n);
}
void upAdjust(int low,int high){    //为什么有上界？
    int i=high,j=i/2;
    while(j>=low){  
        if(heap[i]>heap[i]){
            int temp=heap[j];
            heap[j]=heap[i];
            heap[i]=temp;
            i=j;
            j=i/2;
        }
        else
            break;
    }
}
void insert(int v,int &n){
    heap[++n]=v;
    upAdjust(1,n);
}
void heapSort(int n){       //最大堆的升序排序，每一次的交换都让没排序的最大值到heap[1]的位置，下沉之后便到了该到的位置
    buildHeap(n);
    for(int i=n;i>1;i--){
        int temp=heap[1];//未排序的最大值
        heap[1]=heap[i];
        heap[i]=temp;
        downAdjust(1,i-1);
    }
}




















int n,first[110],second[110];
int isInsert(){
    int i=1;
    while(second[i]<second[i+1])
        i++;
    i++;
    int temp=i;
    while(i<=n){
        if(second[i]!=first[i])
            break;
        i++;
    }
    if(i>n)
        return temp;
    else
        return -1;
}
void insertSort(int start){  //对某一个位置进行修改一
    int t=first[start];
    int i=1;
    while(t>second[i])
        i++;
    for(int j=start;j>i;j--)
        second[j]=second[j-1];
    second[i]=t;
}
void heapSort1(int n,int time){       //最大堆的升序排序，每一次的交换都让没排序的最大值到heap[1]的位置，下沉之后便到了该到的位置
    buildHeap(n);
    for(int i=n;i>1;i--){
        int temp=first[1];//未排序的最大值
        heap[1]=heap[i];
        heap[i]=temp;
        downAdjust(1,i-1);
    }
}
int main(){
    //插入排序 堆排序
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>first[i];
    for(int i=1;i<=n;i++)
        cin>>second[i];    
    int start=isInsert();
    if(start!=-1){
        cout<<"Insertion Sort"<<endl;
        insertSort(start);
    }
    else{
        cout<<"Heap Sort"<<endl;
        int i,num=0;
        for(i=n;i>1;i--){
            if(second[i]>second[i-1]){
                i--;num++;
            }
            else
                break;
        }
        //下一次,对i进行排序
        int temp=second[1];//未排序的最大值
        second[1]=second[i];
        second[i]=temp;
        int high=i-1;
        i=1;int j=2;
        while(j<=high){
            //总是选择更大的一边下沉
            if(j+1<=high&&second[j+1]>second[j])
                j++;
            if(second[j]>second[i]){
                int temp=second[j];
                second[j]=second[i];
                second[i]=temp;
                i=j;
                j=i*2;
            }
            else
                break;
            }
        }
    cout<<second[1];
    for(int i=2;i<=n;i++)
        cout<<" "<<second[i];
    return 0;
}