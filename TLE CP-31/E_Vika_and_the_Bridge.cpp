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
    int n,k;
    cin>>n>>k;
    vi arr(n);
    cin>>arr;
    vector<pair<int,int>>maxStep(k);
    vi vis(k,-1);
    // we can color 1 plank in between so we will be making the distance shorter but in that case the 2nd maxm step
    // might become max step taken , so we need 2 maxm values to check max step needed to cross plank using any color
    for(int i=0;i<n;i++){
        int step=i-vis[arr[i]-1];
        if(step>maxStep[arr[i]-1].first){
            maxStep[arr[i]-1].second=maxStep[arr[i]-1].first;
            maxStep[arr[i]-1].first=step;
        }
        else if(step>maxStep[arr[i]-1].second)maxStep[arr[i]-1].second=step;
        vis[arr[i]-1]=i;
    }
    // check for last step to cross the bridge
    for(int i=0;i<k;i++){
        int step=n-vis[arr[i]-1];
        if(step>maxStep[i].first){
            maxStep[i].second=maxStep[i].first;
            maxStep[i].first=step;
        }
        else if(step>maxStep[i].second)maxStep[i].second=step;
    }
    // we have max 2 steps for each color 
    // now we can use the minm step needed for any color 
    // we can paint a plank , so will be painting middle plank for longest step
    int ans=INT_MAX;
    for(int i=0;i<k;i++){
        maxStep[i].first=(maxStep[i].first+1)/2;
        ans=min(ans,max(maxStep[i].first,maxStep[i].second));
    }
    cout<<ans-1<<"\n";
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