#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define int long long
#define LL long long
#define MP make_pair
#define PB push_back
#define fi first
#define se second
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef pair<int,int>PII;typedef vector<int>VI;typedef vector<PII>VII;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=100005;
int n,q;
set<int>S;
multiset<int>T;
void insert(int x){
	auto it=S.insert(x).fi;
	auto pre=it,nxt=it;
	if(it!=S.begin())--pre;
	if(it!=--S.end())++nxt;
	if(it!=S.begin()){
		T.insert(*it-*pre);
	}
	if(it!=--S.end()){
		T.insert(*nxt-*it);
	}
	if(it!=S.begin()&&it!=--S.end()){
		T.erase(T.find(*nxt-*pre));
	}
}
void erase(int x){
	auto it=S.lower_bound(x);
	auto pre=it,nxt=it;
	if(it!=S.begin())--pre;
	if(it!=--S.end())++nxt;
	if(it!=S.begin()){
		T.erase(T.find(*it-*pre));
	}
	if(it!=--S.end()){
		T.erase(T.find(*nxt-*it));
	}
	if(it!=S.begin()&&it!=--S.end()){
		T.insert(*nxt-*pre);
	}
	S.erase(it);
}
signed main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n),rd(q);
	rep(i,1,n){
		int x;rd(x);
		insert(x);
	}
	rep(_,0,q){
		if(_){
			int o,x;rd(o),rd(x);
			if(o==0){
				erase(x);
			}else{
				insert(x);
			}
		}
		if(SZ(S)<=2){
			puts("0");
		}else{
			pt(*--S.end()-*S.begin()-*--T.end(),'\n');
		}
	}
	return 0;
}

    