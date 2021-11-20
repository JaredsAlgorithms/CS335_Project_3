#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <map>
#include <cassert>

// This is so cool: https://stackoverflow.com/a/29325258

template <class ADAPTER>
typename ADAPTER::container_type & get_container (ADAPTER &a)
{
    struct hack : ADAPTER {
        static typename ADAPTER::container_type & get (ADAPTER &a) {
            return a.*&hack::c;
        }
    };
    return hack::get(a);
}

struct comparator {
  bool operator()(int a, int b) { return a > b; }
};

typedef struct problem {
  std::vector<std::vector<int>> container;
  std::vector<int> solution;

  problem(std::vector<std::vector<int>> _c, std::vector<int> _s) {
    this->container = _c;
    this->solution = _s;
  }
} problem;

void instance(problem p) {

  std::priority_queue<int, std::vector<int>, std::greater_equal<int>> minHeap;
  for(std::vector<int> row : p.container) {
    for(int element : row) {
      minHeap.push(element);
    }
  }
  std::vector<int> container;

  while (!minHeap.empty()) {
    container.push_back(minHeap.top());
    minHeap.pop();
  }

  assert(container == p.solution);
}

int main () {
  using problemSet = std::map<std::string, problem>;

  problemSet problems = {
    {"1",
      problem(
        {
          {2, 5, 9, 21},
          {-1, 0, 2},
          {-10, 81, 121},
          {4, 6, 12, 20, 150}
        },
        {-10, -1, 0, 2, 2, 4, 5, 6, 9, 12, 20, 21, 81, 121, 150}
      )
    },
    {
      "2",
      problem(
          {
           {10, 17, 18, 21, 29},
           {-3, 0, 3, 7, 8, 11},
           {81, 88, 121, 131},
           {9, 11, 12, 19, 29}
          },
          {-3, 0, 3, 7, 8, 9, 10, 11, 11, 12, 17, 18, 19, 21, 29, 29, 81, 88, 121, 131}
      )
    },
    {
      "3",
      problem(
          {
            {-4, -2, 0, 2, 7},
            {4, 6, 12, 14},
            {10, 15, 25},
            {5, 6, 10, 20, 24}
          },
          {-4, -2, 0, 2, 4, 5, 6, 6, 7, 10, 10, 12, 14, 15, 20, 24, 25}
      )
    }
  };

  for(auto element : problems) {
    std::cout << "[INFO] Conducting test number: " << element.first << std::endl;
    instance(element.second);
  }

  return 0;
}
