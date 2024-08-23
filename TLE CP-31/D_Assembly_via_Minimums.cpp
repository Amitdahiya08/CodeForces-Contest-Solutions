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
    int m=(n*(n-1))/2;
    vi arr(m);
    cin>>arr;
    sort(all(arr));
    // now we know that 1st element will appear n-1 times 2nd n-2 time and so on 
    int x=n-1;
    for(int i=0;i<m;){
        cout<<arr[i]<<" ";
        i+=x;
        x--;
    }
    // now left with last element we can print it anything greater than arr[m-1]
    cout<<"1000000000\n";
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