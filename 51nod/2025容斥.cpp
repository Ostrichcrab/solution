/*
我们知道，对于一个直角三角形，它的三边一定满足a^2+b^2=c^2，其中a,b是直角边，c是斜边，这就是大名鼎鼎的勾股定理。
规定a<b<c，求满足l1 <= a <= r1，l2 <= b <= r2，l3 <= c <= r3 的所有直角三角形的周长和。由于答案很大结果Mod 10^9+7。
*/
#include <cstdio>
#include <array>
#include <vector>
#include <algorithm>
using int64 = long long;
using tri = std::array<int64, 3>;
const int mod = 1e9 + 7;
const int N = 2859901 + 10;
const int A[3][3] = {{1,-2,2},{2,-1,2},{2,-2,3}};
const int B[3][3] = {{1,2,2},{2,1,2},{2,2,3}};
const int C[3][3] = {{-1,2,2},{-2,1,2},{-2,2,3}};
int64 l1, r1, l2, r2, l3, r3;
tri queue[N];
int64 gen() {
  if (r3 < 3) return 0;
  queue[0] = {3, 4, 5};
  int64 ret = 0;
  for (int head = 0, tail = 1; head < tail; ++head) {
    auto a = queue[head];
    int64 x = a[0], y = a[1], z = a[2];
    if (x > y) std::swap(x, y);
    if (x > r1 || z > r3) continue;
    int64 u = std::max((l1 + x - 1) / x, std::max((l2 + y - 1) / y, (l3 + z - 1) / z));
    int64 v = std::min(r1 / x, std::min(r2 / y, r3 / z));
    if (u <= v) {
      int64 mul = (u + v) * (v - u + 1) / 2 % mod;
      ret += (x + y + z) % mod * mul % mod;
      if (ret >= mod) ret -= mod;
    }
    tri b;
    for (int i=0;i<3;++i)b[i]=A[i][0]*a[0]+A[i][1]*a[1]+A[i][2]*a[2];
    if (std::min(b[0], b[1]) <= r1) {
      queue[tail++] = b;
    }
    for (int i=0;i<3;++i)b[i]=B[i][0]*a[0]+B[i][1]*a[1]+B[i][2]*a[2];
    if (std::min(b[0], b[1]) <= r1) {
      queue[tail++] = b;
    }
    for (int i=0;i<3;++i)b[i]=C[i][0]*a[0]+C[i][1]*a[1]+C[i][2]*a[2];
    if (std::min(b[0], b[1]) <= r1) {
      queue[tail++] = b;
    }
  }
  return ret;
}
int main() {
  scanf("%lld%lld%lld%lld%lld%lld", &l1, &r1, &l2, &r2, &l3, &r3);
  printf("%lld\n", gen());
  return 0;
}
