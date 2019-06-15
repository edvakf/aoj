#include <cmath>
#include <cstdio>
#include <list>
#include <utility>

using namespace std;

typedef pair<double, double> point;

void koch(list<point> &P) {
  for (list<point>::iterator iter = P.begin(), prev = P.end(); iter != P.end(); prev = iter, ++iter) {
    double x0 = prev->first, y0 = prev->second, x1 = iter->first, y1 = iter->second;
    if (prev != P.end()) {
      // cout << "(" << x0 << "," << y0 << ") (" << x1 << "," << y1 << ")" << endl;

      double xs = x0 + (x1 - x0) / 3.;
      double ys = y0 + (y1 - y0) / 3.;
      double xt = x0 + (x1 - x0) * 2. / 3.;
      double yt = y0 + (y1 - y0) * 2. / 3.;
      double xu = xs + (xt - xs) / 2. - (yt - ys) * sqrt(3.) / 2.;
      double yu = ys + (xt - xs) * sqrt(3.) / 2. + (yt - ys) / 2.;
      P.insert(iter, make_pair(xs, ys));
      P.insert(iter, make_pair(xu, yu));
      P.insert(iter, make_pair(xt, yt));
    }
  }
}

int main() {
  list<point> P;

  P.push_back(make_pair(0., 0.));
  P.push_back(make_pair(100., 0.));

  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    koch(P);
  }
  for (list<point>::iterator iter = P.begin(); iter != P.end(); iter++) {
    printf("%0.8lf %0.8lf\n", iter->first, iter->second);
  }
}