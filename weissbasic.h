/*
//weiss algorithm book for list, stack, etc
*/
#ifndef BASIC_ALGORITHM
#define BASIC_ALGORITHM
#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
// removeEveryOtherItem: remove every other item on list using iterator
template <typename Container> void removeEveryOtherItem(Container &lst) {
  auto itr = lst.begin();
  while (itr != lst.end()) {
    itr = lst.erase(itr); // point to the next element after itr deleted
    if (itr != lst.end())
      ++itr;
  }
}
int fisherman1(int N, int F, int K) {
  //   vector<int> data = {5, 0, 8, 0, 0, 2, 4, 8, 0, 6, 9, 4};
  vector<int> data = {2, 3, 4, 7, 6, 9};

  auto x = 0;
  auto y = 0;
  if (K == N) { // base case
    auto temp = std::accumulate(data.begin(), data.end(), 0);
    return temp - F;
  }
  std::sort(data.begin(), data.end());
  // compare for one fisherman benefit with two fisherman
  auto temp = std::accumulate(data.crbegin(), data.crbegin() + K, 0);
  x = temp - F; // case one fisherman
  temp = std::accumulate(data.crbegin(), data.crbegin() + (2 * K), 0);
  y = temp - (2 * F);
  return x > y ? x : y;
}
int kotakHartaYangPalingBerharga(int N, int S, vector<vector<int>> rak) {
  set<int> sum;
  for (int i = 0; i <= N - S; ++i) {
    for (int j = 0; j <= N - S; ++j) {
      int temp = 0;
      for (int x = i; x < i + S; ++x) {
        for (int y = j; y < j + S; ++y) {
          temp += rak[x][y];
        }
      }
      sum.insert(temp);
    }
  }
  auto last = sum.end();
  --last;
  return *last;
}
void teleportation_portals() {
  auto T = 0;
  std::cin >> T;
  auto N = 0, P1 = 0, P2 = 0;
  vector<int> result;
  for (auto i = 0; i < T; ++i) {
    std::cin >> N >> P1 >> P2;
    auto cntr = 0;
    vector<int> data;
    auto val = 0;
    while (cntr != N) {
      std::cin >> val;
      data.push_back(val);
      ++cntr;
    }
    // solve the i-th case
    for (int powerlevel : data) {
      int proteclevel =
          std::min(std::abs(powerlevel - P1), std::abs(powerlevel - P2));
      result.push_back(proteclevel);
    }
    for (auto x : result) {
      std::cout << x << " ";
    }
    result.clear();
  }
}
int saveThePrisoner(int n, int m, int s) { return ((s - 1 + m - 1) % n) + 1; }
vector<int> circularArrayRotation(vector<int> a, int k, vector<int> queries) {
  auto len = a.size();
  auto shift = k % len;
  std::reverse(a.begin(), a.end());
  std::reverse(a.begin(),
               a.begin() + shift); // reverse [a.begin(), a.begin()+shift)]
  std::reverse(a.begin() + shift, a.end());
  vector<int> result;
  for (auto begin = queries.begin(), end = queries.end(); begin != end;
       ++begin) {
    result.push_back(a[*begin]);
  }
  return result;
}
vector<int> permutationEquation(vector<int> p) {
  auto result = p;
  result.clear();
  for (auto i = 0; i < p.size(); ++i) {
    auto x = std::find(p.begin(), p.end(), i + 1);
    auto cnt = std::distance(p.begin(), x);
    auto y = std::find(p.begin(), p.end(), cnt + 1);
    result.push_back(std::distance(p.begin(), y) + 1);
  }
  return result;
}
int jumpingOnClouds(vector<int> c, int k) {
  auto state = 100;
  auto begin = c.begin();
  auto jump = c.begin() + k % c.size();
  state -= *jump == 1 ? 3 : 1;
  while (jump != begin) {
    if (jump + k >= c.end()) {
      auto temp = std::distance(jump, c.end());
      auto remainder = k - temp;
      jump = c.begin() + remainder % c.size();
    } else
      jump += k;
    state -= *jump == 1 ? 3 : 1;
  }
  return state;
}
int findDigits(int n) {
  auto cnt = 0;
  auto convert = to_string(n);
  auto i = -1;
  for (const auto &val : convert) {
    ++i;
    if (val == '0')
      continue;
    else if ((n % atoi(convert.substr(i, 1).c_str())) == 0)
      ++cnt;
  }
  return cnt;
}
unsigned long long aux_factorial(int n) {
  unsigned long long result = 1;
  for (unsigned long long i = 2; i <= n; ++i)
    result *= i;
  cout << "result: " << result;
  return result;
}
int multiply(int x, int res[], int res_size) {
  int carry = 0;
  for (int i = 0; i < res_size; i++) {
    int prod = res[i] * x + carry; // forward multiplication for each digit
    res[i] = prod % 10;            // divide the resul and store the remainder
    carry = prod / 10;             // store carry
  }
  while (carry) { // since there is carry, go and store it
    res[res_size] = carry % 10;
    carry = carry / 10; // reduce it until zero
    res_size++;
  }
  return res_size;
}
void extraLongFactorials(int n) {
  const int max = 1000;
  int res[max]{};
  int res_size = 1;
  for (int x = 2; x <= n; ++x)
    res_size = multiply(x, res, res_size);
  for (int i = res_size - 1; i >= 0; --i)
    cout << res[i];
}
string appendAndDelete(string s, string t, int k) {
  if (s.size() < t.size()) {
    while (k > 0) {
      // cout << "s result : " << s << endl;
      auto difference = t.size() - s.size();
      for (auto i = 0; i < t.size(); ++i) {
        auto sizetemp = s.size();
        if (i + difference <= t.size() && k >= difference) {
          s.append(t.substr(i, difference));
          if (s == t && k - 1 == 0)
            return "Yes";
          else
            s.erase(sizetemp, difference);
        }
      }
      if (s.empty()) {
        --k;
        continue;
      }
      s.pop_back();
      --k;
    }
    return s == t ? "Yes" : "No";
  } else {
    while (k > 0) {
      if (s.size() > t.size())
        s.pop_back();
      else if (s.size() == t.size())
        if (2 * s.size() <= k)
          return "Yes";
        else {
          if (s == t)
            return "Yes";
          else
            s.pop_back();
        }
      else {
        // try to append if possible to make it match
        // otherwise delete or call pop back
        auto difference = t.size() - s.size();
        for (auto i = 0; i < t.size(); ++i) {
          auto sizetemp = s.size();
          if (i + difference <= t.size() && k >= difference) {
            s.append(t.substr(i, difference));
            if (s == t)
              return "Yes";
            else
              s.erase(sizetemp, difference);
          }
        }
        if (s != t) {
          if (s.empty()) {
            --k;
            continue;
          } else {
            s.pop_back();
          }
        }
      }
      --k;
    }
    return s == t ? "Yes" : "No";
  }
}
// int squares(int a, int b) {
// 	// for (auto i = a; i <= b; i++) {
// 	//     auto temp = std::sqrt(i);
// 	//     int convert = temp;
// 	//     if (temp - convert == 0)
// 	//         ++result;
// 	// }
// 	return std::floor(std::sqrt(b)) - std::ceil(std::sqrt(a)) + 1;
// }
int libraryFine(int d1, int m1, int y1, int d2, int m2, int y2) {
  if (y1 > y2)
    return 10000;
  else if (y1 == y2) {
    if (m1 == m2 && d1 > d2)
      return (d1 - d2) * 15;
    else if (m1 > m2)
      return (m1 - m2) * 500;
  }
  return 0;
}
vector<int> cutTheSticks(vector<int> arr) {
  vector<int> result;
  result.push_back(arr.size());
  for (;;) {
    if (arr.size() <= 1)
      break;
    auto temp = arr;
    std::sort(temp.begin(), temp.end());
    if (temp.front() == temp.back())
      break; // case: [1,1] on arr
    for (int &i : arr)
      i = i - temp.front();
    arr.erase(std::remove(arr.begin(), arr.end(), 0), arr.end());
    result.push_back(arr.size());
  }
  return result;
}
// int nonDivisibleSubset(int k, vector<int> s) {
//	std::sort(s.begin(), s.end());
//	vector<int> data,temp;
//	set<int> count;
//	for (auto i = 0; i < s.size() - 1; ++i) {
//		for (auto j = 1; j < s.size(); ++j) {
//			if ((s[0] + s[j]) % k != 0) {
//				if (std::find(data.begin(), data.end(), s[0]) ==
// data.end()) 					data.push_back(s[0]);
// data.push_back(s[j]);
//			}
//		}
//		if (temp.size() <= data.size())
//			temp = data;
//		data.clear();
//		s.erase(s.begin(), s.begin() + 1);
//	}
//	data = temp;
//
//	set<int> filter;
//	for (auto i = 1; i < data.size() - 1; ++i) {
//		for (auto j = i + 1; j < data.size(); ++j) {
//			if ((data[i] + data[j]) % k == 0) {
//				data.erase(data.begin() + i, data.begin()+i+1);
//			}
//		}
//	}
//	return data.size() ;
// }
int nonDivisibleSubset(int k, vector<int> s) {
  vector<int> remainderCounts(k, 0);
  for (int num : s) {
    remainderCounts[num % k]++;
  }

  int maxSize = min(remainderCounts[0], 1);
  for (int i = 1; i <= k / 2; ++i) {
    if (i != k - i) {
      maxSize += max(remainderCounts[i], remainderCounts[k - i]);
    }
  }

  if (k % 2 == 0) {
    maxSize++;
  }

  return maxSize;
}
string organizingContainers(vector<vector<int>> container) {
  // simple case: container type 0 and 1
  auto type1_first = container[0][0];
  auto type2_first = container[0][1];
  auto first_total = type1_first + type2_first;

  auto type1_second = container[1][0];
  auto type2_second = container[1][1];
  auto second_total = type1_second + type2_second;

  return {"Impossible"};
}
string removeKdigitss(string num, int k) {
  auto temp = num;
  temp.erase(temp.begin(), temp.begin() + k);
  if (temp.size() == 0)
    return {"0"};
  auto min = stoi(temp);
  temp = num;
  for (auto i = 1; i <= num.size() - k; ++i) {
    temp.erase(temp.begin() + i, temp.begin() + i + k);
    if (stoi(temp) < min)
      min = stoi(temp);
    temp = num;
  }
  return to_string(min);
}
inline void plusMinus(vector<int> arr) {
  int pos = 0, neg = 0, zero = 0;
  for (const auto &i : arr) {
    if (i > 0)
      ++pos;
    else if (i == 0)
      ++zero;
    else
      ++neg;
  }
  int len = arr.size();
  printf("%.6f\n", (double)pos / len);
  printf("%.6f\n", (double)neg / len);
  printf("%.6f\n", (double)zero / len);
}
inline void miniMaxSum(vector<int> arr) {
  std::sort(arr.begin(), arr.end());
  long long max = 0;
  long long min = 0;
  min = std::accumulate(arr.begin(), arr.begin() + 4, min);
  max = std::accumulate(arr.rbegin(), arr.rbegin() + 4, max);
  cout << min << " " << max;
}
inline string timeConversion(string s) {
  if (s.substr(s.size() - 2, 2) == "AM") {
    if (s.substr(0, 2) == "12") {
      if (s.substr(3, 2) != "00" || s.substr(6, 2) != "00")
        return string("00").append(s.substr(2, s.size() - 4));
      else
        return {"00:00:00"};
    } else
      return s.substr(0, s.size() - 2);
  } else {
    if (s.substr(0, 2) == "12")
      return s.substr(0, s.size() - 2);
    else {
      auto sum = stoi(s.substr(0, 2)) + 12;
      return to_string(sum).append(s.substr(2, s.size() - 4));
    }
  }
}
inline vector<int> matchingStrings(vector<string> strings,
                                   vector<string> queries) {
  vector<int> result(queries.size(), 0);
  auto idx = 0;
  for (const auto &q : queries) {
    result[idx] = std::count(strings.begin(), strings.end(), q);
    ++idx;
  }
  return result;
}
inline int lonelyinteger(vector<int> a) {
  for (const auto &i : a)
    if (std::count(a.begin(), a.end(), i) == 1)
      return i;
  return 0;
}
inline int diagonalDifference(vector<vector<int>> arr) {
  auto leftdiag = 0, rightdiag = 0;
  for (size_t j = 0; j < arr.size(); ++j)
    leftdiag += arr[j][j];
  for (int i = arr.size() - 1; i != -1; --i)
    rightdiag += arr[i][arr.size() - 1 - i];
  return std::abs(leftdiag - rightdiag);
}
inline vector<int> countingSort(vector<int> arr) {
  std::vector<int> result;
  for (auto i = 0; i < 100; ++i)
    result.push_back(i);
  auto i = 0;
  for (auto &x : result)
    x = std::count(arr.begin(), arr.end(), x);
  return result;
}
inline string pangrams(string s) {
  vector<char> ls;
  for (auto i = 0; i < 26; ++i)
    ls.push_back((char)65 + i);
  for (const auto &x : ls) {
    if (std::count(s.begin(), s.end(), x) == 0 &&
        std::count(s.begin(), s.end(), std::tolower(x)) == 0)
      return {"not pangram"};
  }
  return {"pangram"};
}
inline string twoArrays(int k, vector<int> A, vector<int> B) {
  auto temp_a = A;
  auto temp_b = B;
  std::sort(temp_a.begin(), temp_a.end(), std::greater<int>());
  std::sort(temp_b.begin(), temp_b.end());
  for (size_t i = 0; i < B.size(); ++i)
    if (temp_a[i] + temp_b[i] < k)
      return {"NO"};
  return {"YES"};
}
inline int birthday(vector<int> s, int d, int m) {
  auto way = 0;
  for (size_t i = 0; i <= s.size() - m; ++i)
    if (std::accumulate(s.begin() + i, s.begin() + i + m, 0) == d)
      ++way;
  return way;
}
inline string strings_xor(string s, string t) {
  string res = "";
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == t[i])
      res.push_back('0');
    else
      res.push_back('1');
  }
  return res;
}
// findMedian : finding median of element given arr
inline int findMedian(vector<int> arr) {
  std::sort(arr.begin(), arr.end());
  return arr[arr.size() / 2];
}
// flippingMatrix: find the maximum upper left,
// for example : [1,2], [3,4] => [2,1] [4,3] =>[4,2], [3,1]
inline int flippingMatrix(vector<vector<int>> matrix) {
  int n =
      matrix.size() / 2; // the idea is simple, just flip the top left quadrant
  int sum = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      // Select the maximum element from each 2x2 sub-matrix
      sum +=
          max({matrix[i][j], matrix[i][2 * n - j - 1], matrix[2 * n - i - 1][j],
               matrix[2 * n - i - 1][2 * n - j - 1]});
  return sum;
}
// flippingBits: flip all bits (1->0 and 0->1), return unsigned integer,
// return value to long long
inline long long flippingBits(long n) {
  std::bitset<32> bin(n);
  bin.flip(); // flip bit from 0 -> 1, and 1-> 0
  auto str = bin.to_string();
  long long sum = 0;
  for (int i = 0; i < str.size(); ++i)
    sum += stoi(str.substr(i, 1)) * std::pow(2, str.size() - i - 1);
  return sum;
}
// sockMerchant: count a pair of sock in arr
inline int sockMerchant(int n, vector<int> ar) {
  set<int> val;
  for (const auto &i : ar)
    val.insert(i);
  auto count = 0;
  for (const auto &j : val)
    count += std::count(ar.begin(), ar.end(), j) / 2;
  ;
  return count;
}
// findZigZagSequence: arrage container a to have zigzag element
inline void findZigZagSequence(vector<int> a, int n) {
  sort(a.begin(), a.end());
  int mid = n / 2;
  swap(a[mid], a[n - 1]);

  int st = mid + 1;
  int ed = n - 2;
  while (st < ed) {
    swap(a[st], a[ed]);
    st = st + 1;
    ed = ed - 1;
  }
  for (int i = 0; i < n; i++) {
    if (i > 0)
      cout << " ";
    cout << a[i];
  }
  cout << endl;
}
// pageCount: count minimum way to reach page p from n page
inline int pageCount(int n, int p) {
  auto minleft = std::abs(1 - p);
  auto minright = std::abs(n - p);
  auto count = 0;
  if (n % 2 != 0) {
    if (minleft < minright) {
      for (auto i = 1; i < p; i += 2)
        ++count;
      return count;
    } else {
      for (auto i = n - 1; i > p; i -= 2)
        ++count;
      return count;
    }
  } else {
    if (minleft <= minright) {
      for (auto i = 1; i < p; i += 2)
        ++count;
      return count;
    } else {
      for (auto i = n; i > p; i -= 2)
        ++count;
      return count;
    }
  }
}
// towerBreakers: find the player who will loose the game
constexpr auto towerBreakers(int n, int m) {
  if (m == 1)
    return 2;
  return n % 2 == 1 ? 1 : 2;
}
// caesarCipher: encrypt s by caesar cipher method, shift by k position
inline string caesarCipher(string s, int k) {
  auto maxUpper = toascii('Z');
  auto maxLower = toascii('z');
  if (k > 25)
    k %= 25;
  for (auto &i : s)
    if (std::isalpha(i)) {
      if (std::isupper(i)) {
        auto temp = ((toascii(i) + k) % maxUpper);
        if ((toascii(i) + k) == toascii('Z'))
          i = 'Z';
        else if (temp < toascii('A'))
          i = (char)(temp - 1 + toascii('A'));
        else
          i = (char)((toascii(i) + k) % maxUpper);
      } else {
        auto temp = ((toascii(i) + k) % maxLower);
        if ((toascii(i) + k) == toascii('z'))
          i = 'z';
        else if (temp < toascii('a'))
          i = (char)(temp - 1 + toascii('a'));
        else
          i = (char)((toascii(i) + k) % maxLower);
      }
    }
  return s;
}
// maxMin : find minimum arr' where arr' is element from arr which
// satisfied the condition max(arr') - min(arr')
inline int maxMin(int k, vector<int> arr) {
  std::sort(arr.begin(), arr.end());
  auto min = arr.back();
  auto min_temp = 0, max_temp = 0, res_temp = 0;
  // for (auto i = 0; i <= arr.size() - k; ++i) {
  //	for (auto j = i ; j <= arr.size()-k; ++j) {
  //		min_temp = arr[0 + i];
  //		max_temp = arr[0 + k - 1 + j];
  //		res_temp = max_temp - min_temp;
  //		if (min > res_temp)
  //			min = res_temp;
  //	}
  // }
  //  improve maxMin for O(n-k) where n is size of arr
  for (auto i = 0; i <= arr.size() - k; ++i) {
    for (auto j = 0; j < 1; ++j) {
      min_temp = arr[i];
      max_temp = arr[k - 1 + i];
      res_temp = max_temp - min_temp;
      if (min > res_temp)
        min = res_temp;
    }
  }
  return min;
}
// inline vector<int> dynamicArray(int n, vector<vector<int>> queries) {
//
// }
inline string gridChallenge(vector<string> grid) {
  for (auto i = 0; i < grid.size(); ++i)
    std::sort(grid[i].begin(), grid[i].end());
  for (auto i = 0; i < grid.size(); ++i) {
    auto min = grid[0][i];
    for (auto j = 1; j < grid.size(); ++j) {
      if (min > grid[j][i])
        return {"NO"};
      min = grid[j][i];
    }
  }
  return {"YES"};
}
#endif