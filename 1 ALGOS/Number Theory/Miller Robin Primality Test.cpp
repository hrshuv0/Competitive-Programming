#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll mulmod(ll a, ll b, ll mod)
{
    ll res = 0;
    while(b)
    {
        if(b&1)
            res = (res + a)%mod;
        res = (res << 1)%mod;
        b >>= 1;
    }
    return res;
}

ll bigmod(ll a, ll b, ll mod)
{
    ll res = 1%mod;
    while (b)
    {
        if (b & 1)
            res = (res * a)%mod;
        a = (a * a)%mod;
        b >>= 1;
    }
    return res;
}

bool check_composite(ll n, ll a, ll d, int s) {
    ll x = bigmod(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = mulmod(x, x, n);
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(ll n) { // returns true if n is prime, else returns false.
    if (n < 2)
        return 0;

    int r = 0;
    ll d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return 1;
        if (check_composite(n, a, d, r))
            return 0;
    }
    return 1;
}

