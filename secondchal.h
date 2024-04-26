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
	if (filter.size() > 2)
		return { "NO" };
	//only two element
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
		return { "NO" };
	}
	return { "NO" };
}

// climbingLeaderboard: hackerarnk problem to determine rank of each player
//inline vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {
//	vector<int> filter;
//	for (size_t i = 0; i < ranked.size(); i++) {
//		if (i == 0)
//			filter.push_back(ranked[i]);
//		else
//			if (ranked[i] != ranked[i - 1])
//				filter.push_back(ranked[i]);
//	}
//	vector<int> result;
//	for (const int i : player)
//	{
//		if (i <= filter.back()) {
//			if (i == filter.back())
//				result.push_back(filter.size());
//			else
//				result.push_back(filter.size() + 1);
//		}
//		else if (i >= filter.front())
//			result.push_back(1);
//		else {
//			for (auto j = 1; j < filter.size(); ++j)
//				if (i >= filter[j]) {
//					result.push_back(j + 1);
//					break;
//				}
//		}
//	}
//	return result;
//}
inline vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {
	vector<int> filter;
	const int len = ranked.size() - 1;
	for (int i = len; i >= 0; --i) {
		if (i == len)
			filter.push_back(ranked[i]);
		else
			if (ranked[i] != filter.back())
				filter.push_back(ranked[i]);
	}
	auto memory = 0; //remember the position
	vector<int> result;
	for (const int i : player)
	{
		if (i <= filter.front()) {
			if (i == filter.front())
				result.push_back(filter.size());
			else
				result.push_back(filter.size() + 1);
		}
		else if (i >= filter.back())
			result.push_back(1);
		else {
			for (auto j = 1 + memory; j < filter.size(); ++j)
				if (i <= filter[j]) {
					if (i == filter[j])
						result.push_back(filter.size() - j);
					else
						result.push_back(filter.size() - j + 1);

					memory = j - 1;
					break;
				}
		}
	}
	return result;
}
inline string isBalanced(string s) {
	return { "YES" };
}
// example : [1 3 4 5 6], m = 6, return 1 and 4 (index)
inline vector<int> icecreamParlor(int m, vector<int> arr) {
	vector<int> result;
	for (auto i = 0; i < arr.size() - 1; ++i)
		for (auto j = i + 1; j < arr.size(); ++j)
			if (arr[i] + arr[j] == m)
			{
				result.push_back(i + 1);
				result.push_back(j + 1);
				break;
			}
	std::sort(result.begin(), result.end());
	return  result;
}
inline constexpr int isPrime(const int& n) {
	if (n % 2 == 0 || n % 3 == 0)
		return false;
	// Check from 5 to square root of n 
	// Iterate i by (i+6) 
	for (int i = 5; i <= sqrt(n); i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;
	return true;
}
inline vector<int> generatePrime(const int& n) {
	vector<int> prime = { 2, 3, 5, 7,
		11, 13, 17, 19, 23, 29, 31, 37,
		41, 43, 47, 53, 59, 61, 67, 71, 73,
		79, 83, 89, 97, 101, 103, 107, 109, 113,
		127, 131, 137, 139, 149, 151, 157, 163, 167,
		173, 179, 181, 191, 193, 197, 199, 211, 223,
		227, 229, 233, 239, 241, 251, 257, 263, 269, 271,
		277, 281, 283, 293, 307, 311, 313, 317, 331, 337,
		347, 349, 353, 359, 367, 373, 379, 383, 389, 397,
		401, 409, 419, 421, 431, 433, 439, 443, 449, 457,
		461, 463, 467, 479, 487, 491, 499, 503, 509, 521,
		523, 541, 547, 557, 563, 569, 571, 577, 587, 593,
		599, 601, 607, 613, 617, 619, 631, 641, 643, 647,
		653, 659, 661, 673, 677, 683, 691, 701, 709, 719,
		727, 733, 739, 743, 751, 757, 761, 769, 773, 787,
		797, 809, 811, 821, 823, 827, 829, 839, 853, 857,
		859, 863, 877, 881, 883, 887, 907, 911, 919, 929,
		937, 941, 947, 953, 967, 971, 977, 983, 991, 997 };
	//generate the other i-th prime number
	auto i = 998;
	while (n >= prime.size()) {
		if (isPrime(i))
			prime.push_back(i);
		++i;
	}
	return prime;
}
inline vector<int> waiter(vector<int> number, int q) {
	vector<int> answer;
	vector<int> a = number;
	vector<int> b;
	auto listprime = generatePrime(q);
	for (auto i = 0; i < q; ++i) {
		b.clear();
		for (int j = a.size()-1; j>=0;--j) {
			if (a[j] % listprime[i] == 0) {
				b.push_back(a[j]);
				a.erase(a.begin() + j, a.begin() + j + 1);
			}
		}
		std::reverse(a.begin(), a.end());
		//std::sort(a.begin(), a.end(), greater<int>());
		//println("a {}", a);
		//std::sort(b.begin(), b.end(),greater<int>());
		//println("b {}", b);

		for (auto begin = b.rbegin(); begin != b.rend(); ++begin)
			answer.push_back(*begin);
	}
	for (auto begin= a.rbegin(); begin!=a.rend(); ++begin)
		answer.push_back(*begin);
	return answer;
}

#endif // !WEEK_TWO