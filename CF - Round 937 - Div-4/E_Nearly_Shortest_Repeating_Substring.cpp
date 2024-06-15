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

int helper(string& s){
    int n=s.size();
    // check every factor of n , and compare each factor length string if added can make s
    // note it can be from both side front and back check both
    for(int i=1;i<n;i++){
        if(n%i==0){
            bool flag=true;
            // check from prefix
            int count=0;
            for(int k=0,j=0;k<n;k++){
                if(s[j]!=s[k]){
                    count++;
                }
                if(count==2){
                    flag=false;
                    break;
                }
                j++;
                if(j==i)j=0;
            }
            if(flag)return i;
            flag=true;
            count=0;
            // check from suffix;
            for(int k=n-1,j=n-1;k>=0;k--){
                if(s[k]!=s[j]){
                    count++;
                }
                if(count==2){
                    flag=false;
                    break;
                }
                j--;
                if(j<n-i)j=n-1;
            }
            if(flag)return i;
        }
    }
    return n;
}
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    cout<<helper(s)<<"\n";
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