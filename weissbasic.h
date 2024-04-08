/*
//weiss algorithm book for list, stack, etc
*/
#ifndef BASIC_ALGORITHM
#define BASIC_ALGORITHM
#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>
using namespace std;
// removeEveryOtherItem: remove every other item on list using iterator
template <typename Container> void removeEveryOtherItem(Container& lst) {
	auto itr = lst.begin();
	while (itr != lst.end()) {
		itr = lst.erase(itr); // point to the next element after itr deleted
		if (itr != lst.end())
			++itr;
	}
}
int fisherman1(int N, int F, int K) {
	//   vector<int> data = {5, 0, 8, 0, 0, 2, 4, 8, 0, 6, 9, 4};
	vector<int> data = { 2, 3, 4, 7, 6, 9 };

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
		}
		else
			jump += k;
		state -= *jump == 1 ? 3 : 1;
	}
	return state;
}
int findDigits(int n) {
	auto cnt = 0;
	auto convert = to_string(n);
	auto i = -1;
	for (const auto& val : convert) {
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
			//cout << "s result : " << s << endl;
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
	}
	else {
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
				if (s != t)
					if (s.empty()) {
						--k;
						continue;
					}
					else
						s.pop_back();
			}
			--k;
		}
		return s == t ? "Yes" : "No";
	}
}
int squares(int a, int b) {
	// for (auto i = a; i <= b; i++) {
	//     auto temp = std::sqrt(i);
	//     int convert = temp;
	//     if (temp - convert == 0)
	//         ++result;
	// }
	return floor(sqrt(b)) - ceil(sqrt(a)) + 1;
}
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
			break; //case: [1,1] on arr
		for (auto i = 0; i < arr.size(); ++i)
			arr[i] = arr[i] - temp.front();
		arr.erase(std::remove(arr.begin(), arr.end(), 0), arr.end());
		result.push_back(arr.size());
	}
	return result;
}
//int nonDivisibleSubset(int k, vector<int> s) {
//	std::sort(s.begin(), s.end());
//	vector<int> data,temp;
//	set<int> count;
//	for (auto i = 0; i < s.size() - 1; ++i) {
//		for (auto j = 1; j < s.size(); ++j) {
//			if ((s[0] + s[j]) % k != 0) {
//				if (std::find(data.begin(), data.end(), s[0]) == data.end())
//					data.push_back(s[0]);
//				data.push_back(s[j]);
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
//}
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
#endif
