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

set<int> s;
bool resolve(int n){
    if(s.find(n)!=s.end())return true;
    for(auto& it:s){
        if(it==1)continue;
        if(n%it==0){
            if(resolve(n/it))return true;
        }
    }
    return false;
}
void solve(){
    int n;
    cin>>n;
    bool flag=false;
    if(n==1)flag=true;
    flag=resolve(n);
    if(!flag)cout<<"NO";
    else cout<<"YES";
    ndl;
}
bool isBinary(const std::string &s) {
    for (char c : s) {
        if (c != '0' && c != '1') {
            return false;
        }
    }
    return true;
}
signed main()
{

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // Loop through numbers from 1 to 100,001
    for (int i = 1; i <= 100001; ++i) {
        string numberStr = to_string(i);
        if (isBinary(numberStr)) {
            s.insert(i);
        }
    }
    int t = 1;
    cin >> t;
    while(t--)
     solve();
    return 0;
}