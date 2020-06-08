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

#define eps 1e-9

/*Estrutura padrao de pontos 2d*/
struct Pt {
    double x, y;
    Pt(double a = 0, double b = 0):
    x(a), y(b) {}
    bool operator<(const Pt &a) const {
        if (fabs(x-a.x) > eps)	return x < a.x;
        return y < a.y;
    }
    bool operator==(const Pt &a) const {
        return fabs(x-a.x) < eps && fabs(y-a.y) < eps;
    }
    Pt operator+(const Pt &a) const {
        return Pt(x + a.x, y + a.y);
    }
    Pt operator-(const Pt &a) const {
        return Pt(x - a.x, y - a.y);
    }
    Pt operator/(const double val) const {
        return Pt(x / val, y / val);
    }
    Pt operator*(const double val) const {
        return Pt(x * val, y * val);
    }
};
double cross(Pt o, Pt a, Pt b) {
    return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}

/*Gera o convex hull e retorna numero de pontos no convex hull*/
int convexHull(int n, Pt p[], Pt ch[]) {
    sort(p, p+n);
    int i, m = 0, t;
    for (i = 0; i < n; i++) {
        while(m >= 2 && cross(ch[m-2], ch[m-1], p[i]) <= 0)
            m--;
        ch[m++] = p[i];
    }
    for (i = n-1, t = m+1; i >= 0; i--) {
        while(m >= t && cross(ch[m-2], ch[m-1], p[i]) <= 0)
            m--;
        ch[m++] = p[i];
    }
    return m-1;
}

/*Verifica se um ponto pertence ao convex hull*/
int belongs(const Pt &p, Pt ch[], int n) {
    if (n < 3)
        return false;
    if (cross(ch[0], p, ch[1]) > eps)
        return false;
    if (cross(ch[0], p, ch[n-1]) < -eps)
        return false;
    
    int l = 2, r = n-1;
    int line = -1;
    while (l <= r) {
        int mid = (l + r)>>1;
        if (cross(ch[0],p, ch[mid]) > -eps) {
            line = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    return cross(ch[line-1], p, ch[line]) < eps;
}

Pt pontos[200200];
Pt convex[200200];

int main() {
    int n, m;
    double x, y;
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf", &x, &y);
            pontos[i] = Pt(x, y);
        }
        int pontosNoConvexHull = convexHull(n, pontos, convex);
        scanf("%d", &m);
        int ret = 0;
        for (int i = 0; i < m; i++) {
            scanf("%lf %lf", &x, &y);
            int f = belongs(Pt(x, y), convex, pontosNoConvexHull);
            ret += f;
        }        
        printf("%d\n", ret);
    }
    return 0;
}
