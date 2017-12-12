#include <cstdio>

using namespace std;

#define EPS (1e-5)
#define abs(x) ((x) > 0 ? (x) : -(x))

double newton(double y) {
  double x = 1;
  while (abs(y - x * x * x) > EPS) {
    // printf("%lf\n", x);
    x -= ((x * x * x - y )/ (3 * x * x));
  }
  return x;
}
int main(int argc, char const *argv[]) {
  double y;
  while (scanf("%lf", &y) != EOF) {
    printf("%.1lf\n", newton(y));
  }
  return 0;
}

