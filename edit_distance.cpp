#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i < (n); ++i)
#define repB(i, a, n)  for(int i = a; i <=(n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define vec(i, a)  for( auto i=a.begin();i != a.end(); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define time cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long double ld;
typedef long long ll;
typedef std::pair<ll, ll> pii;
typedef std::vector<ll> vi;

const ll MOD = 1e9 + 7;
using namespace std;
// ll n_bits(ll n ) { ll x= __builtin_popcount(n) ;return x ;}
// #define in  freopen("input.txt","r",stdin);
// #define out freopen("output.txt","w",stdout);
// #define dark_lord in out
// #define fast  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

std::map<pii, ll> mpi;

int min(int x, int y, int z)
{
    return min(min(x, y), z);
}

int editDist(string str1, string str2, int m, int n)
{ ll a;
    // If first string is empty, the only option is to
    // insert all characters of second string into first
    if (m == 0)
    {
    	a=n;
    	if(mpi.count({m,n}))
    	{auto it=mpi.find({m,n});
    		return it->second;
    	}
    	else
    	{
    	mpi.insert({{m,n},n});
        return n;
    	}
    }

    // If second string is empty, the only option is to
    // remove all characters of first string
    if (n == 0){
    	a=m;
    	if(mpi.count({m,n}))
    	{auto it=mpi.find({m,n});
    		return it->second;
    	}
    	else
    	{
    	mpi.insert({{m,n},m});
        return m;
    	}
        }

    // If last characters of two strings are same, nothing
    // much to do. Ignore last characters and get count for
    // remaining strings.
    if (str1[m - 1] == str2[n - 1])
    {
    	if(mpi.count({m,n}))
    	{auto it=mpi.find({m,n});
    		return it->second;
    	}
    	else
    	{
        a= editDist(str1, str2, m - 1, n - 1);
    	mpi.insert({{m,n},a});
    	return a;
    	}
    }

    // If last characters are not same, consider all three
    // operations on last character of first string, recursively
    // compute minimum cost for all three operations and take
    // minimum of three values.
    if(mpi.count({m,n}))
    	{auto it=mpi.find({m,n});

    		return it->second;
    	}
   	else
   	{
  a=1 + min(editDist(str1, str2, m, n - 1), // Insert
                   editDist(str1, str2, m - 1, n), // Remove
                   editDist(str1, str2, m - 1, n - 1) // Replace
                   );

    	mpi.insert({{m,n},a});
    	return a;
    }
}

int main()
{
    // #ifndef ONLINE_JUDGE
    // dark_lord
    // #endif
    // fast
    ll t=1;
    cin>>t;
    while(t--)
    { mpi.clear();
     ll m,n;
    cin>>m>>n;
    string str1,str2;
    cin>>str1>>str2;


    cout << editDist(str1, str2, m,n)<<endl;

    //return 0;
    }


//     #ifndef ONLINE_JUDGE
// 	time
// 	#endif
    return 0;
}
