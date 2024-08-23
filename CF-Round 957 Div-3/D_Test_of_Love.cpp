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

bool helper(string&s ,int jump ,int swim){
    int i=-1;
    int n=s.size();
    while(i<n){
        // jump in this case
        if(i==-1 || s[i]=='L'){
            int water=0,next=0;
            if(i+jump >=s.size())return true;
            for(int j=i;j<=i+jump;j++){
                if(s[j]=='L'){
                    next=j;
                    break;
                }
                else if(s[j]=='W')water=j;
            }
            if(next)i=next;
            else if(water)i=water;
            else return false;
        }
        else if(s[i]=='W'){
            if(swim==0)return false;
            i++;
            swim--;
        }
        else return false;
    }
    return i>=s.size();

}
void solve() {
    int n, jump, swim;
    cin >> n >> jump >> swim;
    string s;
    cin >> s;
    // memset(dp, -1, sizeof(dp));
    bool ans = helper(s, jump, swim);
    if (ans) cout << "YES";
    else cout << "NO";
    cout << endl;
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