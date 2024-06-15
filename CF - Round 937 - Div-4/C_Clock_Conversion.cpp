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

    string s;
    cin>>s;
    int hour=stoi(s.substr(0,2));
    int min=stoi(s.substr(3,2));
    if(hour <= 11){
        hour = hour==0 ? 12 : hour;
        string ans="";
        if(hour < 10)ans+='0';
        ans+=to_string(hour);
        ans+=':';
        if(min < 10)ans+="0";
        ans+=to_string(min);
        ans+=" AM";
        cout<<ans;
    }
    else {
        hour=(hour + 12)%12;
        hour = hour==0 ? 12 : hour;
        string ans="";
        if(hour < 10)ans+='0';
        ans+=to_string(hour);
        ans+=':';
        if(min < 10)ans+="0";
        ans+=to_string(min);
        ans+=" PM";
        cout<<ans;
    }
    ndl;

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