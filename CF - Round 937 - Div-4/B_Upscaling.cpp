#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){
       int n;
       cin>>n;
       string a="##",b="..";
       for(int i=1;i<=n;i++){
            if(i%2!=0){
                int line=2;
                while(line--){
                    for(int j=1;j<=n;j++){
                        if(j%2!=0)cout<<a;
                        else cout<<b;
                    }
                    cout<<"\n";
                }
            }
            else{
                int line=2;
                while(line--){
                    for(int j=1;j<=n;j++){
                        if(j%2==0)cout<<a;
                        else cout<<b;
                    }
                    cout<<"\n";
                }
            }
        }
    }

    return 0;
}