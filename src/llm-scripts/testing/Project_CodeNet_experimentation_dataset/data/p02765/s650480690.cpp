/************************************************************************
*                  -> Bismillahir Rahmanir Rahim <-                     *
*                                                                       *
*                                                                       *
*                                                                       *
*                                                                       *
* __________             .___        .__              ____ ________     *
* \______   \_____     __| _/  ______|  |__  _____   /_   |\_____  \    *
*  |    |  _/\__  \   / __ |  /  ___/|  |  \ \__  \   |   | /  ____/    *
*  |    |   \ / __ \_/ /_/ |  \___ \ |   Y  \ / __ \_ |   |/       \    *
*  |______  /(____  /\____ | /____  >|___|  /(____  / |___|\_______ \   *
*         \/      \/      \/      \/      \/      \/               \/   *
*                                                                       *
*                                                                       *
*                                                                       *
*              .=.,                                                     *
*             ;c =\                                                     *
*           __|  _/                                                     *
*         .'-'-._/-'-._                                                 *
*        /..   ____    \                                                *
*       /' _  [<BF>] )  \                                               *
*      (  / \--\_>/-/'._ )                                              *
*       \-;_/\__;__/ _/ _/                                              *
*        '._}|==o==\{_\/                                                *
*         /  /-._.--\  \_                                               *
*        // /   /|   \ \ \                                              *
*       / | |   | \;  |  \ \                                            *
*      / /  | :/   \: \   \_\                                           *
*     /  |  /.'|   /: |    \ \                                          *
*     |  |  |--|   |--|     \_\                                         *
*     / _/   \ |   | /___--._) \                                        *
*    |_(---'-| >   | |       '-'                                        *
*           /_/     \_\                                                 *
*                                                                       *
 ***********************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define pi acos(-1)
typedef  long long ll;
typedef  unsigned long long ull;
typedef  unsigned un;

//defined taking input;
#define sf           scanf
#define si(a)        sf("%d",&a)
#define sc(a)        sf("%c",&a)
#define sii(a,b)     sf("%d %d",&a,&b)
#define siii(a,b,c)  sf("%d %d %d",&a,&b,&c)
#define sl(a)        sf("%lld",&a)
#define sll(a,b)     sf("%lld %lld",&a,&b);
#define slll(a,b,c)  sf("%lld %lld %lld",&a,&b,&c);

#define pf           printf
#define pfi(a)       pf("%d\n",a)
#define pfii(a,b)    pf("%d %d\n",a,b)
#define pfl(a)       pf("%ld\n",a)
#define pfn          pf("\n")
#define pfyes        pf("YES\n")
#define pfno         pf("NO\n")
#define pfYes        pf("Yes\n")
#define pfNo         pf("No\n")
#define wh           while
#define wht(t)       while(t--)
#define vi           vector<int>
#define vl           vector<long long>
#define endl         "\n"

#define input        freopen("input.txt","r",stdin);
#define output       freopen("output.txt","w",stdout);


int main()
{
    int n,r;
    cin>>n>>r;
    int a = 100*(10-n);
    if(a>=0){
        cout<<r+a<<endl;
    }else{
        cout<<r<<endl;
    }

    return 0;
}
