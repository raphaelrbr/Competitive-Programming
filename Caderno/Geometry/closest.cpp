#include "bits/stdc++.h"
using namespace std;
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
    
#define fr(i,n)	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
    
#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
    
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
    
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;
typedef int ftype;
const int INF = 0x3f3f3f3f;

struct point{
    double x;
    double y;
};

bool cmp(point a,point b)
{
    return a.x<b.x;
}
const int maxn = 1e4+5;
point pontos[maxn];

double dist(point a,point b)
{
    return (double)sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}

double MERGE(int low,int mid,int high,double ll,double rr)
{
    double d=(ll<rr)?ll:rr;
    double line=(double)(pontos[mid].x+pontos[mid+1].x)/2;
    double min_D=d;
    for(int i=mid+1;pontos[i].x<line+d && i<=high;i++){ 
        for(int j=mid;pontos[j].x>line-d && j>=low;j--){
            double temp=dist(pontos[i],pontos[j]);
            if(temp<min_D) min_D=temp;
        }
    }
    return min_D;
}
double DIVIDE(point a[],int low,int high)
{
    if(low>=high) return INF; 

    int mid=(low+high)/2;
    double min_left=DIVIDE(a,low,mid);
    double min_right=DIVIDE(a,mid+1,high);
    return MERGE(low,mid,high,min_left,min_right);
}


int main()
{
    int n;
    
    while(scanf("%d",&n))
    {
        if (n==0) break;
        for(int i=0;i<n;i++)
            scanf("%lf %lf",&pontos[i].x,&pontos[i].y);
        sort(pontos,pontos+n,cmp);
        double dis=DIVIDE(pontos,0,n-1);
        if(dis>=10000.0) printf("INFINITY\n");
        else printf("%.4lf\n",dis);
    }
    return 0;
}