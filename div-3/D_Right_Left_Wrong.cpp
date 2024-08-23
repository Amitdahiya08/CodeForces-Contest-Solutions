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

int sum(int left,int right){
    if(left==right)return left;
    int leftSum=(left*(left+1))/2;
    int rightSum=(right*(right+1))/2;
    return rightSum-leftSum;
}
void solve(){

    int n;
    cin>>n;
    vi arr(n);
    cin>>arr;
    string s;
    cin>>s;
    vector<int>left,right;
    for(int i=0;i<n;i++){
        if(s[i]=='L')left.push_back(arr[i]);
        else right.push_back(arr[i]);
    }
    sort(all(left));
    sort(all(right));
    int i=0,j=right.size()-1;
    int ans=0;
    while(i<left.size() && j>=0){
        if(left[i]>right[j])break;
        cout<<left[i]<<" "<<right[j]<<endl;
        for(int k=left[i]-1;k<=right[j]-1;k++){
            ans+=arr[k];
        }
        i++,j--;
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