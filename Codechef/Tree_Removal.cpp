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
    vector<int>score(n);
    cin>>score;
    unordered_map<int,unordered_set<int>>mp;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        mp[u].insert(v);
        mp[v].insert(u);
    }
    priority_queue<pair<pair<int,int>,int>>pq;
    for(auto& [node, v] : mp) {
        if(v.size() % 2)
            pq.push({{-v.size(), score[node-1]},node});
    }
    vector<int>ans;int count=0;
    while(!pq.empty()) {
        int current_score = pq.top().first.second;
        int node = pq.top().second;
        pq.pop();
        // if edges have become even
        if(mp[node].size() % 2 == 0) continue;
        count++;
        ans.push_back(node);
        for(auto it : mp[node]) {
            mp[it].erase(node);
            if(mp[it].size() % 2)
                pq.push({make_pair(-mp[it].size(), score[it-1]), it});
        }
        mp.erase(node);
    }
    cout<<count<<"\n";
    cout<<ans;
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