#include <cstdio>
#include <cstdlib>
#include <utility>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  char slopes[20001];
  int heights[20001];
  size_t end = 0;
  heights[end] = 0;

  scanf("%s", slopes);
  for (size_t i = 0;; i++) {
    char slope = slopes[i];
    if (slope == '/') {
      heights[end + 1] = heights[end] + 1;
      end++;
    } else if (slope == '_') {
      heights[end + 1] = heights[end];
      end++;
    } else if (slope == '\\') {
      heights[end + 1] = heights[end] - 1;
      end++;
    } else {  // EOS
      break;
    }
  }

  // printf("end:%zu max:%d min:%d\n", end, max, min);

  vector<pair<size_t, size_t> > lakes;

  for (size_t i = 0; i <= end - 1; i++) {
    if (heights[i] > heights[i + 1]) {
      // printf("i:%zu\n", i);
      for (size_t j = i + 1; j <= end; j++) {
        // printf("j:%zu height:%d\n", j, heights[j]);
        if (heights[j] == heights[i]) {
          // printf("surface:%d left:%zu right:%zu\n", surface, i, j);
          // if not within an alread-lake
          lakes.push_back(make_pair(i, j));
          i = j - 1;
          break;
        }
      }
    }
  }

  int totalArea = 0;
  size_t numLakes = lakes.size();
  int areas[numLakes];
  for (size_t i = 0; i < numLakes; i++) {
    // printf("%zu %zu\n", it->first, it->second);
    int depth = 0;
    float area = 0;
    for (size_t j = lakes[i].first; j < lakes[i].second; j++) {
      if (slopes[j] == '/') {
        area += (float)depth - 0.5;  // should really be depth + 0.5
        // printf("/:%f", area);
        depth--;
      } else if (slopes[j] == '_') {
        // printf("_:%f", area);
        area += depth;
      } else if (slopes[j] == '\\') {
        area += (float)depth + 0.5;  // should really be depth + 0.5
        // printf("\\:%f", area);
        depth++;
      }
    }
    areas[i] = (int)area;
    totalArea += area;
    // printf("left:%zu right:%zu area:%d\n", it->first, it->second, area);
  }

  printf("%d\n", (int)totalArea);
  printf("%zu", lakes.size());
  for (size_t i = 0; i < numLakes; i++) {
    printf(" %d", areas[i]);
  }
  printf("\n");
}