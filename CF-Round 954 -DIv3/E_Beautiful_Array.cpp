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

int calc(vector<int>&v , int k){
    int ans=0,n=v.size();
    // leaving first element for middle
    for(int i=1;i<n;i+=2){
        ans+=(v[i+1]-v[i])/k;
    }
    int val1=0,val2=ans;
    for(int i=1;i<n;i+=2){
        // make new pair with prev element
        val1+=(v[i]-v[i-1])/k;
        // subtract already made pair 
        val2-=(v[i+1]-v[i])/k;
        ans=min(ans,val1+val2);
    }
    return ans;
}
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    cin>>arr;
    sort(all(arr));
    map<int,vector<int>>mp;
    // elements whose %k is same can only be made pairs 
    for(int i=0;i<n;i++){
        mp[arr[i]%k].push_back(arr[i]);
    }
    int ans=0,odd=0;
    for(auto& [it,v]:mp){
        sort(all(v));
        // if odd one will be in middle
        if(v.size()%2){
            odd++;
            ans+=calc(v,k);
        }
        else{
            // if one make pair of adjacents
            for(int i=0;i<v.size();i+=2){
                ans+=(v[i+1]-v[i])/k;
            }
        }
    }
    if(odd>1)cout<<-1<<"\n";
    else cout<<ans<<"\n";
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