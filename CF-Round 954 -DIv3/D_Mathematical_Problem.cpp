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

int helper(string& s, int i, bool flag, vector<vector<int>>& dp) {
    if(i>=s.size()){
        return 1;
    }
    int& ans=dp[i][flag];
    if(ans!=-1)return ans;
    if(i==s.size()-2 && flag){
        return ans=((s[i]-'0')*10)+(s[i+1]-'0');
    }

    // now we have 2 choices if flag is set then merge curr and next 
    int ans1=INT_MAX;
    if(flag){
        int temp=((s[i]-'0')*10)+(s[i+1]-'0');
        int curr=helper(s,i+2,0,dp);
        // we can either multiply or add 
        ans1=min(temp*curr,temp+curr);
    }
    // or dont merge them 
    int temp=s[i]-'0';
    int curr=helper(s,i+1,flag,dp);
    int ans2=min(temp*curr,temp+curr);
    return ans=min(ans1,ans2);
}

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    string f="";
    if(s.size()<=2){
        cout<<stoi(s)<<"\n";
    }
    else{
        vector<vector<int>>dp(21,vector<int>(2,-1));
        int ans=helper(s,0,1,dp);
        cout<<ans<<"\n";
    }
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