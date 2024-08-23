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


void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>>a(n),b(n),c(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[i]={x,i};
    }
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        b[i]={x,i};
    }
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        c[i]={x,i};
    }
    sort(a.rbegin(),a.rend());
    sort(b.rbegin(),b.rend());
    sort(c.rbegin(),c.rend());
    int ans=0;
    for(int i=0;i<3;i++){
        int val1=a[i].first,ind1=a[i].second;
        for(int j=0;j<3;j++){
            int val2=b[j].first,ind2=b[j].second;
            for(int k=0;k<3;k++){
                int val3=c[k].first,ind3=c[k].second;
                if(ind1!=ind2 && ind2!=ind3 && ind1!=ind3){
                    ans=max(ans,val1+val2+val3);
                }
            }
        }
    }
    cout<<ans<<"\n";
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