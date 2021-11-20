#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include <string>

void swap(int* a, int* b) {
  int c = *a;
  *a = *b;
  *b = c;
}

void _solution(std::vector<int>* _container, std::vector<int> _pattern) {
  for(int key : _pattern) {
    for(size_t i = 0; i < (*_container).size(); ++i) {
      for(size_t j = i; j < (*_container).size(); ++j) {
        if(key == (*_container)[i]) {
          swap(&(*_container)[i], &(*_container)[j]);
        }
      }
    }

  }
}
typedef struct problem {
  std::vector<int> container;
  std::vector<int> pattern;
  std::vector<int> solution;

  problem(std::vector<int> _c, std::vector<int> _p, std::vector<int> _s) {
    this->container = _c;
    this->pattern = _p;
    this->solution = _s;
  }
} problem;

int main() {
  std::map<std::string, problem> problems = {
    {
      "1",
      problem(
        {1, 0, -1, 0, 0, 1, 1, -1, 0, 1},
        {0, 1, -1},
        {0, 0, 0, 0, 1, 1, 1, 1, -1, -1}
      )
    },
    {
      "2",
      problem(
        {4, 2, 10, 10, 7, 2, 10, 7, 4, 2, 4},
        {2, 4, 7, 10},
        {2, 2, 2, 4, 4, 4, 7, 7, 10, 10, 10}
      )
    },
    {
      "3",
      problem(
          {9, -2, 9, 23, 23, -2, 9, 23, 9, -2},
          {9, -2, 23},
          {9, 9, 9, 9, -2, -2, -2, 23, 23, 23}
      )
    }
  };

  for(auto _problem : problems) {
    std::cout << "[INFO] Conducting test " << _problem.first << std::endl;
    _solution(&_problem.second.container, _problem.second.pattern);
    assert(_problem.second.container == _problem.second.solution);
  }

  return 0;
}
