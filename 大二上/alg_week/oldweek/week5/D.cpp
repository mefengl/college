#include<iostream>
#include <algorithm>
using namespace std;
#define int long long
const int maxm=1e5+5;
struct Node{
    int a,b;
}a[maxm];
int sum[maxm];
int c[maxm];
int n,m;
bool cmp(int a,int b){
    return a>b;
}
signed main(){
    int T;cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=m;i++){
            cin>>a[i].a>>a[i].b;
            c[i]=a[i].a;
        }
        sort(c+1,c+1+m,cmp);//从大到小排序
        for(int i=1;i<=m;i++){
            sum[i]=sum[i-1]+c[i];
        }
        int ans=0;
        for(int i=1;i<=m;i++){//枚举最后b[i]买的是哪种
            int temp=0;
            int remain=n;
            //二分找>b[i]的
            int l=1,r=m;
            int p=-1;
            while(l<=r){
                int mid=(l+r)/2;
                if(c[mid]>a[i].b){
                    p=mid,l=mid+1;
                }else{
                    r=mid-1;
                }
            }
            if(p==-1){//没有>b[i]的,那么全买这一种
                ans=max(ans,a[i].a+(n-1)*a[i].b);
                continue;
            }
            //
            if(p>n)p=n;
            temp+=sum[p];
            remain-=p;
            if(a[i].a>=c[p]){
                temp+=a[i].b*remain;
            }else{
                if(remain){
                    temp+=a[i].a;
                    remain--;
                    temp+=a[i].b*remain;
                }
            }
            //
            ans=max(ans,temp);
        }
        cout<<ans<<endl;
    }
    return 0;
}
