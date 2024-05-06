#ifndef WEEK_TWO
#define WEEK_TWO
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <fmt/core.h>
#include <fmt/ranges.h>
#include <limits>
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

constexpr auto reduceToPower(long n) {
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
	int len = s.size();
	for (auto i = s.size()-1; i > 0 || len == 0; --i) {
		//cout << s << endl;
		switch (s[i])
		{
		case ']':
			if (s[i - 1] == '[')
				s.erase(s.begin() + i - 1, s.begin() + i+1 );
			break;
		case ')':
			if (s[i - 1] == '(')
				s.erase(s.begin() + i -1, s.begin() + i+1 );
			break;
		case '}':
			if (s[i - 1] == '{')
				s.erase(s.begin() + i - 1, s.begin() + i+1 );
			break;
		default:
			break;
		}
		--len;
	}
	return s.size() == 0 ? string("YES") : string("NO");
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

constexpr int isPrime(const int& n) {
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
inline void mytextEditor(){
	int q; //total q operation
	string s; //s for store S value
	cin>>q;
	int ops;
	int posdel; // postion that the deletion begin, look startpos
	int printkpos; // the position we want to print [1,2,...s.len]
	string appendtos; // if append command, append to the last s
	auto startpos=0; // the position we want to start delete, auxilary for s
	vector<string> history;
	vector<int> histroy_ops;
	while(q){
		cin>>ops;
		switch (ops)
		{
		case 1:
            history.push_back(s);
			cin>>appendtos; //append
			s.append(appendtos);
			break;
		case 2:
            history.push_back(s);
			cin>>posdel;
			startpos=0;
			startpos = s.size()-posdel;
			s.erase(s.begin()+startpos, s.end());
			break;
		case 3:
			cin>>printkpos;
			cout<<s[printkpos-1]<<endl;
			break;
		case 4:
            s = history.back();
            history.erase(history.begin()+ history.size()-1, history.end());
			break;
		default:
			break;
		}
		--q;
	}
}
inline int truckTour(vector<vector<int>> petrolpumps) {
    int start = 0;
    int surplus = 0;
    int deficit = 0;
    for (int i = 0; i < petrolpumps.size(); i++) {
        surplus += petrolpumps[i][0] - petrolpumps[i][1];
        if (surplus < 0) {
            start = i + 1;
            deficit += surplus;
            surplus = 0;
        }
    }
    return (surplus + deficit >= 0) ? start : -1;
}
int pairs(int k, vector<int> arr) {
	auto totalpair=0;
	std::sort(arr.begin(), arr.end());
	for(int i=0; i<arr.size()-1; ++i)
		for(int j=i; j<arr.size();++j){
			if(abs(arr[i]-arr[j])==k)
				++totalpair;
			else if(abs(arr[i]-arr[j])>k)
				break; //there is no important check needed if the value is > k
		}
	return totalpair;
}
vector<string> bigSorting(vector<string> unsorted) {
	std::sort(unsorted.begin(), unsorted.end(), [] (const string a, const string b){
		if(a.length()!= b.length())
			return a.length() < b.length(); // the small length always at the front
		return a < b; //otherwise just convert the numerical value, compare
	});
	return unsorted;
}
inline int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
	std::reverse(h1.begin(), h1.end());
	std::reverse(h2.begin(), h2.end());
	std::reverse(h3.begin(), h3.end());
	auto h1_acumulate = std::accumulate(h1.begin(), h1.end(), 0);
	auto h2_acumulate = std::accumulate(h2.begin(), h2.end(), 0);
	auto h3_acumulate = std::accumulate(h3.begin(), h3.end(), 0);
	auto min = 0;
	while (true) {
		if ((h1_acumulate == h2_acumulate) && (h1_acumulate == h3_acumulate))
			break;
		min = std::min(std::min(h1_acumulate, h2_acumulate), h3_acumulate);
		if (h1_acumulate == min) {
			// manipulate stack 2 and 3
			if (h2_acumulate != min){
				h2_acumulate-=h2.back();
				h2.pop_back();
			}
			if (h3_acumulate != min){
				h3_acumulate-=h3.back();
				h3.pop_back();
			}
		}
		else if (h2_acumulate == min) {
			// manipulate stack 1 and 3
			if (h3_acumulate != min){
				h3_acumulate-=h3.back();
				h3.pop_back();
			}
			if (h1_acumulate != min){
				h1_acumulate-=h1.back();
				h1.pop_back();
			}
		}
		else {
			// manipulate the stack 1 and 2
			if (h1_acumulate != min){
				h1_acumulate-=h1.back();
				h1.pop_back();
			}
			if (h2_acumulate != min){
				h2_acumulate-=h2.back();
				h2.pop_back();
			}
		}
	}
	return h1_acumulate;
}
inline vector<int> max_crossing_array(const vector<int> &data, const int &low, 
		const int &mid, const int &high) {
	int leftsum = INT_MIN;
	auto sum = 0;
	int maxleft = 0;
	for (int i = mid; i >= low; --i) {
		sum += data[i];
		if (sum > leftsum) {
			leftsum = sum;
			maxleft = i;
		}
	}
	int maxright = 0;
	int rightsum = INT_MIN;
	sum = 0;
	for (int j = mid+1 ; j <= high;++j) {
		sum += data[j];
		if (sum > rightsum) {
			rightsum = sum;
			maxright = j;
		}
	}
	const vector<int> &pos = { maxleft, maxright, leftsum + rightsum };
	return pos;
}
inline vector<int> crosing_demo(const vector<int>& data, const int &low, const int &high) {
	//vector<int> left_result,right_result,cross_result;
	if (high == low){
		return { low,high,data[low] };
	}
	else {
		int mid = low + (high-low)/2;
		const auto &left_result = crosing_demo(data, low, mid);
		const auto &right_result = crosing_demo(data, mid + 1, high);
		const auto &cross_result = max_crossing_array(data, low,mid,high);
		// println("cross : {}", cross_result);
		if (left_result.back() >= right_result.back() &&
			left_result.back() >= cross_result.back()) {
			return left_result;
		}
		else if (right_result.back() >= left_result.back() &&
			right_result.back() >= cross_result.back()) {
			return right_result;
		}
		return cross_result;
	}
}
inline vector<int> maxSubarray(vector<int>arr) {
	auto len = arr.size()-1;
	auto result = crosing_demo(arr,0,len);
	auto sum = result.back();
	vector<int> maxarr;
	maxarr.push_back(sum);
	// finding the subsequence 
	if (sum < 0) 
		maxarr.push_back(sum);
	else {
		sum = 0;
		for (const auto& i : arr) 
			if (i > 0)
				sum += i;
		maxarr.push_back(sum);
	}
	return maxarr;
}
#endif // !WEEK_TWO