// two sum problem, adding a pair of number which result is 0
#ifndef ALGORITHM_TWOSUM_H
#define ALGORITHM_TWOSUM_H
#include <algorithm>
#include <iostream>
#include <vector>
template <typename Number> class TwoSum {
public:
  explicit TwoSum(const std::vector<Number> &data) : data(data) {}
  size_t count();
  static int rank(const Number &, const std::vector<Number> &);

private:
  std::vector<Number> data;
};

template <typename Number> size_t TwoSum<Number>::count() {
  std::sort(data.begin(), data.end());
  size_t cnt = 0;
  for (int i = 0; i < data.size(); ++i) {
    if (rank(-data[i], data) > i)
      cnt++;
  }
  return cnt;
}

template <typename Number>
int TwoSum<Number>::rank(const Number &_val, const std::vector<Number> &_data) {
  int low = 0;
  int high = _data.size() - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (_val < _data[mid])
      high = mid - 1;
    else if (_val > _data[mid])
      low = mid + 1;
    else
      return mid;
  }
  return -1;
}
#endif // ALGORITHM_TWOSUM_H
