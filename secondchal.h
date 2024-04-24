#ifndef WEEK_TWO
#define WEEK_TWO
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <fmt/core.h>
#include <fmt/ranges.h>
using namespace fmt;
using namespace std;

int month[15];

void updateLeapYear(int year) {
	if (year % 400 == 0) {
		month[2] = 29;
	}
	else if (year % 100 == 0) {
		month[2] = 28;
	}
	else if (year % 4 == 0) {
		month[2] = 29;
	}
	else {
		month[2] = 28;
	}
}

void storeMonth() {
	month[1] = 31;
	month[2] = 28;
	month[3] = 31;
	month[4] = 30;
	month[5] = 31;
	month[6] = 30;
	month[7] = 31;
	month[8] = 31;
	month[9] = 30;
	month[10] = 31;
	month[11] = 30;
	month[12] = 31;
}

int findLuckyDates(int d1, int m1, int y1, int d2, int m2, int y2) {
	storeMonth();

	int result = 0;

	while (true) {
		int x = d1;
		x = x * 100 + m1;
		x = x * 10000 + y1;
		if (x % 4 == 0 || x % 7 == 0) {
			result = result + 1;
		}
		if (d1 == d2 && m1 == m2 && y1 == y2) {
			break;
		}
		updateLeapYear(y1);
		d1 = d1 + 1;
		if (d1 > month[m1]) {
			m1 = m1 + 1;
			d1 = 1;
			if (m1 > 12) {
				y1 = y1 + 1;
				m1 = 1;
			}
		}
	}
	return result;
}
// balancedSums: check is there any possible way to sum from left ro right and right to left
// which give equals some or balance sum
inline string balancedSums(vector<int> arr) {
	int sum = std::accumulate(arr.begin(), arr.end(), 0);
	int left = 0;
	for (int& it : arr) {
		sum -= it; // reduce sum by arr[0, .....end), reduce before compare
		// example [ 1,2 {3} , 4,5], exclude 3 
		if (left == sum) //compare the left with sum
			return { "YES" };
		left += it; // increase left
	}
	return { "NO" };
}
inline const auto ispower(const long& n) {
	auto x = std::log2l(n);
	return (x - (int)x) == 0;
}
inline constexpr auto reduceToPower(long n) {
	while (n & (n - 1))// make it to zero
		n = n & (n - 1);
	return n;
}
inline string counterGame(long n) {
	auto idx = 0;
	while (n != 1) {
		++idx;
		if (ispower(n))
			n /= 2;
		else
			n = n - reduceToPower(n);
	}
	return idx == 0 || idx % 2 != 0 ?
		string("Louise") : string("Richard");
}
// superDigit: recursively sum each digit until get super digit, n = single integer
// for example, 9875 -> 29 -> 11 -> 2, 2 is super digit, k is for scale the digit
inline int superDigit(string n, int k) {
	auto idx = 0;
	long long temp = 0; // note, for large string since the problem involve large digit
	while (n.size() != 1) {
		vector<int> digit;
		for (size_t i = 0; i < n.size(); ++i)
			digit.push_back(stoi(n.substr(i, 1)));
		if (idx == 0) {
			n = to_string(k * std::accumulate(digit.begin(), digit.end(), temp));
			++idx;
		}
		else
			n = to_string(std::accumulate(digit.begin(), digit.end(), temp));
	}
	return stoi(n);
}
inline long sumXor(long n) {
	long cnt = 1;
	while (n) {
		if (!(n & 1)) {
			cnt *= 2;
		}
		n >>= 1;
	}
	return cnt;
}
inline vector<int> dynamicArray(int n, vector<vector<int>> queries) {
	vector<vector<int>> arr;
	for (auto i = 0; i < n; ++i)
		std::fill(arr[i].begin(), arr[i].end(), 0);
	auto lastanswer = 0;
	return { 0,1 };
}
bool ispalindrome(const string& s, int& pos) {
	auto state = true;
	for (auto i = 0; i < s.size(); ++i) {
		if (s[i] != s[s.size() - i - 1]) {
			state = false;
			pos = i;
			break;
		}

	}
	return state;
}
inline int palindromeIndex(string s) {
	auto pos = -1;
	auto palin = ispalindrome(s, pos);
	if (palin)
		return -1;
	else {
		auto remfront = s;
		remfront.erase(remfront.begin() + pos, remfront.begin() + pos + 1);
		if (ispalindrome(remfront, pos)) {
			return pos;
		}
		else {
			return s.size() - pos - 1;
		}
	}
}
inline auto vecgcd(const vector<int>& a) {
	int lstfact = a.front();
	for (const auto& j : a)
		lstfact = std::lcm(lstfact, j);
	return lstfact;
}
inline int getTotalX(vector<int> a, vector<int> b) {
	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());
	vector<int> ls;
	auto counter = 0;
	auto i = 1;
	auto lstfact = vecgcd(a);
	while (i * lstfact <= b.front()) {
		ls.push_back(i * lstfact);
		++i;
	}
	int sizels = ls.size();
	for (const auto& i : ls) {
		for (const auto& j : b) {
			if (j < i) {
				if (i % j != 0) {
					sizels -= 1;
					break;
				}
			}
			else {
				if (j % i != 0) {
					sizels -= 1;
					break;
				}
			}
		}
	}
	return sizels;
}

[[maybe_unused]] inline int anagram(string s) {
	int n = s.length();
	if (n % 2 != 0) {
		return -1;
	}
	std::string s1 = s.substr(0, n / 2);
	std::string s2 = s.substr(n / 2, n / 2);

	// Create frequency arrays for both strings
	std::vector<int> freq1(26, 0), freq2(26, 0);
	for (int i = 0; i < n / 2; i++) {
		freq1[s1[i] - 'a']++;
		freq2[s2[i] - 'a']++;
	}
	// Count the minimum number of character changes required
	int res = 0;
	for (int i = 0; i < 26; i++) {
		res += std::abs(freq1[i] - freq2[i]);
	}

	return res / 2;
}
inline string isValid(string s) {
	map<char, size_t> temp;
	auto cnt = 0;
	auto falsecnt = 0;
	for (const auto& i : s)
		++temp[i];
	//println("logs: ");
	//print("{}", temp);
	//store the result on a set
	set<int> filter;
	for (const auto& i : temp)
		filter.insert(i.second);
	// check the current filter
	if (filter.size() == 1)
		return { "YES" };
	else if (filter.size() > 2)
		return { "NO" };
	else { //only two element
		vector<int> lastfilter;
			for (const auto& i : temp)
				lastfilter.push_back(i.second);
			if (std::count(lastfilter.begin(), lastfilter.end(), 1) == 1)
				return { "YES" };
			auto left = std::count(lastfilter.begin(), lastfilter.end(),
				*(filter.begin()));
			auto right = std::count(lastfilter.begin(), lastfilter.end(),
				*(++filter.begin()));
			if (left == 1 || right == 1) {
				if (abs(*filter.begin() - *(++filter.begin())) == 1)
					return { "YES" };
				else
					return { "NO" };
			}
			else
				return { "NO" };
	}
}

// climbingLeaderboard: hackerarnk problem to determine rank of each player
inline vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {
	/*std::set<int> leaderboard;
	for (const auto& i : ranked)
		leaderboard.insert(i);*/
	vector<int> filter ;
	for (size_t i = 0; i < ranked.size(); i++)
	{
		if (ranked[i+1] != ranked[i])
			filter.push_back(ranked[i]);
	}
	//auto begin = leaderboard.rbegin();
	//auto end = leaderboard.rend();
	//while (begin != end) { // leaderboard rank, first, ..... last
	//	filter.push_back(*begin);
	//	++begin;
	//}
	auto pointfind = 0;
	vector<int> result;
	for (const auto& i : player) {
		if (i <= filter.back()) {
			if (i == filter.back())
				result.push_back(filter.size());
			else
				result.push_back(filter.size() + 1);
		}
		else if (i >= filter.front())
				result.push_back(1);
		else { // position either not in front or back, move to left or right
			// but excluded the front and back
			for (auto j = 1; j < filter.size(); ++j) {
				if (i >= filter[j]) {
					result.push_back(j + 1);
					break;
				}
			}
		}

	}
	return result;
}
#endif // !WEEK_TWO