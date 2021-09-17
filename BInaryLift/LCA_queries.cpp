#include<bits/stdc++.h>
using namespace std;
/////////////////////////////////////////////// JAI SHREE RAM /////////////////////////////////////////////////////////////////////
#define mem(x,y)                   memset(x,y,sizeof(x))
#define pb                         push_back
#define mp                         make_pair
#define pi                         pair<ll,ll>
#define vib                        vector<bool>
#define vi                         vector<ll>
#define ff                         first
#define ss                         second
#define MOD                        1000000007
const int mod =                    1e9 + 7;
#define PI                         3.141592653589793
#define setBitCount(x)             __builtin_popcount(x)
#define all(a)                     (a).begin(), (a).end()
#define all_r(a)                   (a).rbegin(), (a).rend()
#define sz(x)                      (int)(x.size())
#define endl                       '\n'
#define mxn                         200005
typedef long long                   ll;
typedef unsigned  long long         ull;
typedef long double                 lld;
void fastIO()                       { ios_base::sync_with_stdio(false); cin.tie(NULL);}
// -----------------------------------------------------------------------------------------------------------------------------------------------------------
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
string yes = "YES";
string no = "NO"    ;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
void google(ll t , ll ans) {cout << "Case #" << t << ": " << ans << endl; return;}
ll gcd(ll a, ll b) {if (b == 0)return a; return gcd(b, a % b);}
ll binpow(ll a, ll  b) {ll res = 1; while (b > 0) {if (b & 1)res = res * a; a = a * a; b >>= 1;} return res;}
ll modpow(ll  a, ll  b, ll m) {a %= m; ll  res = 1; while (b > 0) {if (b & 1)res = res * a % m; a = a * a % m; b >>= 1;} return res;}
ll lcm (ll a, ll b) {return a / gcd(a, b) * b;}
ll extendedgcd(ll a, ll b, ll& x, ll& y) {if (b == 0) {x = 1; y = 0; return a;} ll x1, y1; ll d = extendedgcd(b, a % b, x1, y1); x = y1; y = x1 - y1 * (a / b); return d;}
bool primalitTest(ll n) {if (n == 1)return false; for (ll i = 2; i * i <= n; i++) {if (n % i == 0)return false;} return true;}
void  PRIME(ll n) {vector<bool>isPrime(100005, true); for (ll i = 2; i * i <= n; i++) { if (isPrime[i]) {for (ll j = i * i; j <= n; j = j + 2) {isPrime[j] = false;} }}}
//////////////////////////////////////////////JAI SHREE RAM /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int NNN;
vector<vector<int>>Move_Up_To(21, vector<int>(mxn, 0));
vector<int>Tree[mxn];
vector<int>Level;
void Level_Finder(int currNode, int ParentNode, int curr_level) {
    int first_parent = 0;
    Move_Up_To[first_parent][currNode] = ParentNode;
    Level[currNode] = curr_level;

    for (auto child : Tree[currNode]) {
        if (child != ParentNode) {
            Level_Finder(child, currNode, curr_level + 1);
        }
    }
}
void Preprocess_LCA() {
    Level_Finder(1, -1, 0);
    for (int ith_parent = 1; 1 << ith_parent <= NNN ; ith_parent++)
        for (int currNode = 0; currNode <= NNN; currNode++) {
            int Parent_of_curr_Node = Move_Up_To[ith_parent - 1][currNode];
            Move_Up_To[ith_parent][currNode] = Move_Up_To[ith_parent - 1][Parent_of_curr_Node];
        }

}
int LCA_Finder(int firstNode, int  secondNode) {

    if (Level[firstNode] < Level[secondNode]) {
        swap(firstNode, secondNode);
    }
    int level_difference = Level[firstNode] - Level[secondNode];

    for (int level = 20; level >= 0; level--) {
        if (level_difference & (1 << level)) {
            firstNode = Move_Up_To[level][firstNode];
        }
    }
    if (firstNode == secondNode) {
        return firstNode;
    }
    for (int level_jump = 20; level_jump >= 0; level_jump--) {
        if (Move_Up_To[level_jump][firstNode] != Move_Up_To[level_jump][secondNode]) {
            firstNode = Move_Up_To[level_jump][firstNode];
            secondNode = Move_Up_To[level_jump][secondNode];
        }
    }
    return Move_Up_To[0][firstNode];
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
void JaiShreeRam() {
/// write your code here
    int t, n, m, x, y;
    cin >> n >> x;
    NNN = n;

    for (int i = 2; i <= n; i++) {
        cin >> y;
        Tree[y].pb(i);
        Tree[i].pb(y);
    }
    Level.assign(mxn, 0);
    Preprocess_LCA();
    while (x--) {
        int u, v;
        cin >> u >> v;
        cout << LCA_Finder(u, v) << endl;
    }


}
//////////////////////////////////////////////JAI SHREE RAM /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    fastIO();
    JaiShreeRam();
    return 0;
}