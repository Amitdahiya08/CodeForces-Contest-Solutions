#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#endif

#define int long long
#define ll long long
#define ndl cout<<"\n";
#define spc <<" "<<
#define pb push_back
#define vi vector<int>
#define vpi vector<pii>
#define pii pair<int, int>
#define all(v)  v.begin(),v.end()
#define mii map<int, int>
#define bits __builtin_popcount
#define gcd __gcd
#define in insert

template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }

int helper(int a,int b,int c){
    if(a+1!=c)return -1;
    if(a+b+c==1)return 0;
    int levels=1;
    int curr;
    if(a>0){
        a-=1;
        curr=2;
    }
    else{
         b-=1;
         curr=1;
    }
    // a will incg the level size , and b will make it const
    while(a+b > 0){
        int next=0;
        while(curr--){
            if(a){
                a--;
                next+=2;
            }
            else if(b){
                b--;
                next++;
            }
            else if(c){
                c--;
            }
            else {
                return -1;
            }
        }
        levels++;
        curr=next;
        if(!curr)break;
        next=0;
    }
    return levels;
}
void solve(){

    int a,b,c;
    cin>>a>>b>>c;
    cout<<helper(a,b,c)<<"\n";
}

signed main()
{

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    cin >> t;

    while(t--)
     solve();
    return 0;
}