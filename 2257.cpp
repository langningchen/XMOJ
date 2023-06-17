/*
# 2257: 2^k 进制
## Description
设 $r$ 是个 $2^k$ 进制数，并满足以下条件：$r$ 至少是个 $2$ 位的 $2^k$ 进制数。
作为 $2^k$ 进制数，除最后一位外，$r$ 的每一位严格小于它右边相邻的那一位。
将 $r$ 转换为二进制数 $q$ 后，则 $q$ 的总位数不超过 $w$。在这里，正整数 $k,w$ 是事先给定的。
问：满足上述条件的不同的 $r$ 共有多少个？我们再从另一角度作些解释：设 $S$ 是长度为 $w$ 的 $01$ 字符串（即字符串 $S$ 由 $w$ 个 $0$ 或 $1$ 组成），$S$ 对应于上述条件三中的 $q$。将 $S$ 从右起划分为若干个长度为 $k$ 的段，每段对应一位 $2^k$ 进制的数，如果 $S$ 至少可分成 $2$ 段，则 $S$ 所对应的二进制数又可以转换为上述的 $2^k$ 进制数 $r$。例：设 $k=3,w=7$。则 $r$ 是个八进制数（ $2^3=8$ ）。由于 $w=7$，长度为 $7$ 的 $01$ 字符串按 $3$ 位一段分，可分为 $3$ 段（即 $1,3,3$，左边第一段只有一个二进制位），则满足条件的八进制数有：
$2$ 位数：
高位为 $1$：$6$ 个（即 $12,13,14,15,16,17$ ），
高位为 $2$：$5$ 个，
…，
高位为 $6$：$1$ 个（即 $67$ ）。
共 $6+5+…+1=21$ 个。$3$ 位数：
高位只能是 $1$，
第 $2$ 位为 $2$：$5$ 个（即 $123,124,125,126,127$ ），
第 $2$ 位为 $3$：$4$ 个，
…，
第 $2$ 位为 $6$：$1$ 个（即 $167$ ）。
共 $5+4+…+1=15$ 个。所以，满足要求的 $r$ 共有 $36$ 个。
## Input format
一行两个正整数 $k,w$ 用一个空格隔开。
## Output format
一行一个个正整数，为所求的计算结果。
即满足条件的不同的 $r$ 的个数（用十进制数表示），要求不得有前导零，各数字之间不得插入数字以外的其他字符（例如空格、换行符、逗号等）。
## Range
30% 的数据，$1 \le k \le 5$，$1 \le w \le 20$
100% 的数据，$1 \le k \le 9$，$1 \le w \le 3 \times 10^4$
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 3e4 + 5;
ll k, w, dp[2][N];
int main()
{
    scanf("%lld%lld", &k, &w);
    // dp[i][j] = sum{dp[i-1][t] | j < t <= min{x}}
    dp[1][1] = 1;
    for (ll i = 2; i <= k; i++)
    {
        ll sum = 0;
        for (ll j = 1; j <= w; j++)
        {
            sum += dp[(i - 1) & 1][j];
            dp[i & 1][j] = sum;
        }
    }
    ll ans = 0;
    for (ll i = 1; i <= w; i++)
        ans += dp[k & 1][i];
    printf("%lld\n", ans);
    return 0;
}
