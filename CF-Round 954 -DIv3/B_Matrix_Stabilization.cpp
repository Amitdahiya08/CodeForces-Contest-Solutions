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
    int n,m;
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            bool flag=true;
            int maxm=0;
            if(i>0){
                if(arr[i][j] > arr[i-1][j])maxm=max(arr[i-1][j],maxm);
                else flag=false;
            }
            if(i+1<n){
                if(arr[i][j] > arr[i+1][j])maxm=max(arr[i+1][j],maxm);
                else flag=false;
            }
            if(j>0){
                if(arr[i][j] > arr[i][j-1])maxm=max(arr[i][j-1],maxm);
                else flag=false;
            }
            if(j+1<m){
                if(arr[i][j] > arr[i][j+1])maxm=max(arr[i][j+1],maxm);
                else flag=false;
            }
            if(flag)arr[i][j]=maxm;
        }
    }
    for(auto& v:arr){
        for(auto& it:v){
            cout<<it<<" ";
        }
        cout<<"\n";
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