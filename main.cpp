#include "twosum.h"
#include "weissbasic.h"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
void fisherman_2() {
  auto T = 0;
  std::cin >> T;
  auto N = 0, F = 0, K = 0;
  auto itr = 0;
  int datai = 0;
  while (itr != T) {
    cin >> N;
    cin >> F;
    cin >> K;
    auto cntr = 0;
    auto val = 0;
    vector<int> data;

    while (cntr != N) {
      std::cin >> val;
      data.push_back(val);
      ++cntr;
    }
    auto temp = data;
    std::sort(temp.begin(), temp.end());

    if (K <= 1) {
      std::cout << "0" << std::endl;
    } else if (K == N) {
      auto total = 0;
      total = accumulate(data.begin(), data.end(), 0);
      std::cout << total - F << std::endl;
    } else {
      auto total = 0;
      auto len = temp.size();
      len = len - 1;
      for (int i = 0; i < (2 * K); ++i) {
        if (N > i) {
          break;
        }
        if (K % 2 != 0) {
          if ((K * 2 - 1) == i) {
            total += temp[0];
            break;
          }
        }
        total += temp[len - i];
      }
      cout << (total - (2 * F)) << endl;
    }
    ++itr;
  }
}
void fisherman_1() {
  auto N = 5;
  auto F = 20;
  auto K = 1;
  std::vector<int> data = {4, 8, 3, 2, 8};
  if (K <= 1) {
    std::cout << "0" << std::endl;
    return;
  }
  auto fisherman = 2;
  auto totalcost = fisherman * F;
  if (N % K) {
    auto total = 0;
    total = accumulate(data.begin(), data.end(), 0);
    std::cout << total - totalcost << std::endl;
    return;
  }
  auto temp = data;
  std::sort(temp.begin(), temp.end());

  auto len = data.size();
  auto totalbenefit =
      temp[len - 1] + temp[len - 2] + temp[len - 3] + temp[len - 4];
  totalbenefit = totalbenefit - totalcost;
  cout << totalbenefit << endl;
}
int main() {
  //    auto result = TwoSum({-2,-3,-4,-5,-6,2,3,4,5,6,7});
  //    std::cout<< "result : " << result.count();
  // cout<<fisherman1(6,10,2)<<endl;
  // cout<<fisherman1(6,10,3)<<endl;
  // cout<<fisherman1(12,10,4)<<endl;
  // cout<<fisherman1(12,10,5)<<endl;
  vector<vector<int>> data = {
      {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 3, 2, 1, 1},
      {1, 1, 1, 1, 1, 2, 3, 1, 1, 1}, {1, 1, 1, 1, 1, 3, 1, 2, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  };
  // cout<<kotakHartaYangPalingBerharga(10,3,data);
  teleportation_portals();
  return 0;
}
