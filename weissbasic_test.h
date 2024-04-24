#ifndef BASIC_ALGORITHM_TEST
#define BASIC_ALGORITHM_TEST
#include "weissbasic.h"
#include <gtest/gtest.h>
#include <list>
TEST(removeEveryOtherItem, sizeiseven) {
	std::list<int> data = { 1, 2, 3, 4, 5, 6 };
	std::list<int> result = { 2, 4, 6 };
	removeEveryOtherItem(data);
	EXPECT_EQ(result, data);
}
TEST(removeEveryOtherItem, sizeisodd) {
	std::list<int> data = { 1, 2, 3 };
	std::list<int> result = { 2 };
	removeEveryOtherItem(data);
	EXPECT_EQ(result, data);
}
TEST(removeEveryOtherItem, sizeisone) {
	std::list<int> data = { 1 };
	std::list<int> result;
	removeEveryOtherItem(data);
	EXPECT_EQ(data, result);
}
TEST(removeEveryOtherItem, sizeisnil) {
	std::list<int> data;
	std::list<int> result;
	removeEveryOtherItem(data);
	EXPECT_EQ(data, result);
}
TEST(saveThePrisoner, testcase1) { EXPECT_EQ(2, saveThePrisoner(5, 2, 1)); }
TEST(saveThePrisoner, testcase2) { EXPECT_EQ(3, saveThePrisoner(5, 2, 2)); }
TEST(saveThePrisoner, testcase3) { EXPECT_EQ(7, saveThePrisoner(7, 19, 3)); }
TEST(saveThePrisoner, testcase4) { EXPECT_EQ(3, saveThePrisoner(3, 7, 3)); }
TEST(saveThePrisoner, testcase5) { EXPECT_EQ(1, saveThePrisoner(3, 7, 1)); }
TEST(saveThePrisoner, testcase6) { EXPECT_EQ(3, saveThePrisoner(5, 2, 2)); }
TEST(saveThePrisoner, testcase8) {
	EXPECT_EQ(405956028, saveThePrisoner(962975336, 972576181, 396355184));
}
TEST(saveThePrisoner, testcase9) {
	EXPECT_EQ(23525398, saveThePrisoner(94431605, 679262176, 5284458));
}
TEST(saveThePrisoner, testcase10) {
	EXPECT_EQ(122129406, saveThePrisoner(352926151, 380324688, 94730870));
}
TEST(saveThePrisoner, testcase11) {
	EXPECT_EQ(674567416, saveThePrisoner(946486979, 973168361, 647886035));
}
TEST(saveThePrisoner, testcase12) {
	EXPECT_EQ(999999999, saveThePrisoner(999999999, 999999999, 1));
}
TEST(saveThePrisoner, testcase13) {
	EXPECT_EQ(1, saveThePrisoner(499999999, 999999998, 2));
}
TEST(saveThePrisoner, testcase14) {
	EXPECT_EQ(72975907, saveThePrisoner(208526924, 756265725, 150817879));
}
TEST(circularArrayRotation, testcase1) {
	std::vector<int> data = { 3, 4, 5 };
	std::vector<int> result = { 5, 3 };
	EXPECT_EQ(result, circularArrayRotation(data, 2, { 1, 2 }));
}
TEST(circularArrayRotation, testcase2) {
	std::vector<int> data = { 1, 2, 3 };
	std::vector<int> result = { 2, 3, 1 };
	EXPECT_EQ(result, circularArrayRotation(data, 2, { 0, 1, 2 }));
}
TEST(permutationEquation, testcase1) {
	std::vector<int> data = { 2, 3, 1 };
	std::vector<int> result = { 2, 3, 1 };
	EXPECT_EQ(result, permutationEquation(data));
}
TEST(permutationEquation, testcase2) {
	std::vector<int> data = { 4, 3, 5, 1, 2 };
	std::vector<int> result = { 1, 3, 5, 4, 2 };
	EXPECT_EQ(result, permutationEquation(data));
}
TEST(jumpingOnClouds, testcase1) {
	std::vector<int> data = { 0, 0, 1, 0, 0, 1, 1, 0 };
	EXPECT_EQ(92, jumpingOnClouds(data, 2));
}
TEST(jumpingOnClouds, testcase2) {
	std::vector<int> data = { 0, 0, 1, 0 };
	EXPECT_EQ(96, jumpingOnClouds(data, 2));
}
TEST(findDigits, testcase1) {
	const auto number = 12;
	EXPECT_EQ(2, findDigits(number));
}
TEST(findDigits, testcase2) {
	const auto number = 1012;
	EXPECT_EQ(3, findDigits(number));
}
TEST(findDigits, testcase3) {
	const auto number = 124;
	EXPECT_EQ(3, findDigits(number));
}
TEST(findDigits, testcase4) {
	const auto number = 10;
	EXPECT_EQ(1, findDigits(number));
}
TEST(findDigits, testcase5) {
	const auto number = 123456789;
	EXPECT_EQ(3, findDigits(number));
}
TEST(findDigits, testcase6) {
	const auto number = 106108048;
	EXPECT_EQ(5, findDigits(number));
}
TEST(appendAndDelete, testcase1) {
	string s = "hackerhappy";
	string t = "hackerrank";
	int k = 9;
	EXPECT_EQ(string("Yes"), appendAndDelete(s, t, k));
}
TEST(appendAndDelete, testcase2) {
	string s = "abc";
	string t = "def";
	int k = 6;
	EXPECT_EQ(string("Yes"), appendAndDelete(s, t, k));
}
TEST(appendAndDelete, testcase3) {
	string s = "ashley";
	string t = "ash";
	int k = 2;
	EXPECT_EQ(string("No"), appendAndDelete(s, t, k));
}
TEST(appendAndDelete, testcase4) {
	string s = "aba";
	string t = "aba";
	int k = 7;
	EXPECT_EQ(string("Yes"), appendAndDelete(s, t, k));
}
TEST(appendAndDelete, testcase5) {
	string s = "abjad";
	string t = "abj";
	int k = 3;
	EXPECT_EQ(string("Yes"), appendAndDelete(s, t, k));
}
TEST(appendAndDelete, testcase6) {
	string s = "y";
	string t = "yu";
	int k = 2;
	EXPECT_EQ(string("No"), appendAndDelete(s, t, k));
}
// TEST(appendAndDelete, testcase7) {
//     string s = "zzzzz";
//     string t = "zzzzzzz";
//     int k = 4;
//     EXPECT_EQ(string("Yes"), appendAndDelete(s, t, k));
// }
// TEST(squares, testcase1) {
// 	auto a = 3;
// 	auto b = 9;
// 	EXPECT_EQ(2, squares(a, b));
// }
// TEST(squares, testcase2) {
// 	auto a = 17;
// 	auto b = 24;
// 	EXPECT_EQ(0, squares(a, b));
// }
// TEST(squares, testcase3) {
// 	auto a = 24;
// 	auto b = 49;
// 	EXPECT_EQ(3, squares(a, b));
// }
// TEST(squares, testcase4) {
// 	auto a = 465868129;
// 	auto b = 988379794;
// 	EXPECT_EQ(9855, squares(a, b));
// }
TEST(libraryFine, testcase1) {
	int d1 = 9, m1 = 6, y1 = 2015;
	int d2 = 6, m2 = 6, y2 = 2015;
	EXPECT_EQ(45, libraryFine(d1, m1, y1, d2, m2, y2));
}
TEST(libraryFine, testcase2) {
	int d1 = 14, m1 = 2, y1 = 2024;
	int d2 = 16, m2 = 1, y2 = 2024;
	EXPECT_EQ((m1 - m2) * 500, libraryFine(d1, m1, y1, d2, m2, y2));
}
TEST(cutTheSticks, testcase1) {
	vector<int> data = { 5,4,4,2,2,8 };
	vector<int> goal = { 6,4,2,1 };
	EXPECT_EQ(goal, cutTheSticks(data));
}
TEST(cutTheSticks, testcase2) {
	vector<int> data = { 1,2,3,4,3,3,2,1 };
	vector<int> goal = { 8,6,4,1 };
	EXPECT_EQ(goal, cutTheSticks(data));
}
TEST(nonDivisibleSubset, testcase1) {
	const int k = 3;
	vector<int> data = { 1,7,2,4 };
	EXPECT_EQ(3, nonDivisibleSubset(k, data));
}
TEST(nonDivisibleSubset, testcase2) {
	const int k = 5;
	vector<int> data = { 1,2,3,4,5,6 };
	EXPECT_EQ(4, nonDivisibleSubset(k, data));
}
TEST(nonDivisibleSubset, testcase3) {
	const int k = 7;
	vector<int> data = { 278 ,576 ,496, 727 ,410 ,124 ,
		338 ,149 ,209 ,702 ,282 ,718 ,771 ,575, 436 };
	EXPECT_EQ(11, nonDivisibleSubset(k, data));
}
//TEST(organizingContainers, testcase1) {
//	vector<vector<int>> data = {
//		{1,3,1},
//		{2,1,2},
//		{3,3,3}
//	};
//	EXPECT_EQ(string("Impossible"), organizingContainers(data));
//}
//TEST(organizingContainers, testcase2) {
//	vector<vector<int>> data = {
//		{0,2,1},
//		{1,1,1},
//		{2,0,0}
//	};
//	EXPECT_EQ(string("Possible"), organizingContainers(data));
//}
//TEST(organizingContainers, testcase3) {
//	vector<vector<int>> data = {
//		{1,1},
//		{1,1},
//	};
//	EXPECT_EQ(string("Possible"), organizingContainers(data));
//}
TEST(organizingContainers, testcase4) {
	vector<vector<int>> data = {
		{0,2},
		{1,1},
	};
	EXPECT_EQ(string("Impossible"), organizingContainers(data));
}
TEST(removeKdigitss, testcase1) {
	EXPECT_EQ(string("1219"), removeKdigitss(string("1432219"), 3));
}
TEST(removeKdigitss, testcase2) {
	EXPECT_EQ(string("200"), removeKdigitss(string("10200"), 1));
}
TEST(removeKdigitss, testcase3) {
	EXPECT_EQ(string("0"), removeKdigitss(string("10"), 2));
}
TEST(removeKdigitss, testcase4) {
	EXPECT_EQ(string("11"), removeKdigitss(string("112"), 1));
}
TEST(removeKdigitss, testcase5) {
	EXPECT_EQ(string("11"), removeKdigitss(string("11123"), 3));
}
TEST(removeKdigitss, testcase6) {
	EXPECT_EQ(string("100"), removeKdigitss(string("10200"), 2));
}
TEST(miniMaxSum, testcase1) {
	stringstream buffer;
	// redirect standart ouput to buffer
	streambuf* prevcoutbuf = cout.rdbuf(buffer.rdbuf());
	miniMaxSum({ 256741038, 623958417, 467905213, 714532089, 938071625 });
	cout.rdbuf(prevcoutbuf);
	auto output = buffer.str();
	EXPECT_EQ(output, "2063136757 2744467344");
}
TEST(timeConversion, testcase1) {
	EXPECT_EQ(string("19:05:45"), timeConversion({ "07:05:45PM" }));
}
TEST(timeConversion, testcase2) {
	EXPECT_EQ(string("12:01:00"), timeConversion({ "12:01:00PM" }));
}
TEST(timeConversion, testcase3) {
	EXPECT_EQ(string("00:01:00"), timeConversion({ "12:01:00AM" }));
}
TEST(timeConversion, testcase4) {
	EXPECT_EQ(string("00:00:00"), timeConversion({ "12:00:00AM" }));
}
TEST(timeConversion, tetstcase5) {
	EXPECT_EQ(string("12:00:00"), timeConversion({ "12:00:00PM" }));
}
TEST(matchingStrings, testcase1) {
	vector<int> result = { 2,1,0 };
	EXPECT_EQ(result, matchingStrings({"aba", "baba","aba","xzxb"}, {"aba","xzxb","ab"}));
}
TEST(matchingStrings, testcase2) {
	vector<int> result = { 1,0,1 };
	EXPECT_EQ(result, matchingStrings({ "def", "de","fgh" }, { "de","lmn","fgh" }));
}
TEST(lonelyinteger, testcase1) {
	EXPECT_EQ(4, lonelyinteger({ 1,2,3,4,3,2,1 }));
}
TEST(diagonalDifference, testcase1) {
	vector<vector<int>> data = {
		{1,2,3},
		{4,5,6},
		{9,8,9}
	};
	EXPECT_EQ(2, diagonalDifference(data));
}
TEST(countingSort, testcase1) {
	vector<int> data = { 63, 25, 73, 1, 98, 73, 56, 84, 86,
		57, 16, 83, 8, 25, 81, 56, 9 ,53, 98, 67, 99, 12, 83, 89,
		80 ,91, 39, 86, 76, 85, 74, 39, 25, 90, 59, 10 ,94, 32,
		44 ,3 ,89 ,30 ,27 ,79 ,46 ,96, 27 ,32 ,18 ,21 ,92 ,69,
		81, 40 ,40, 34, 68, 78, 24, 87, 42, 69, 23, 41, 78, 22,
		6, 90, 99 ,89, 50, 30, 20, 1, 43, 3 ,70, 95, 33,
		46 ,44 ,9 ,69 ,48, 33 ,60 ,65 ,16,
		82, 67 ,61 ,32 ,21 ,79 ,75 ,75 ,13 ,87 ,70 ,33
	};
	vector<int> goal = {
		0 ,2 ,0 ,2 ,0 ,0 ,1 ,0 ,1 ,2 ,1 ,0 ,
		1 ,1 ,0 ,0 ,2 ,0 ,1 ,0 ,1 ,2 ,1 ,1 ,1,
		3 ,0 ,2 ,0 ,0 ,2 ,0 ,3 ,3 ,1 ,0 ,0 ,0 ,
		0 ,2 ,2 ,1 ,1 ,1, 2 ,0 ,2 ,0 ,1 ,0, 1,
		0 ,0 ,1 ,0 ,0 ,2 ,1 ,0 ,1 ,1 ,1 ,0, 1 ,
		0 ,1 ,0 ,2 ,1 ,3 ,2 ,0 ,0 ,2 ,1 ,2 ,1 ,
		0 ,2 ,2 ,1 ,2 ,1 ,2 ,1 ,1 ,2 ,2 ,
		0 ,3, 2 ,1 ,1 ,0 ,1 ,1 ,1 ,0 ,2 ,2
	};
	EXPECT_EQ(goal,countingSort(data));
}
TEST(pangrams, testcase1) {
	EXPECT_EQ(string("pangram"), 
		pangrams("We promptly judged antique ivory buckles for the next prize"));
}
TEST(pangrams, testcase2) {
	EXPECT_EQ(string("not pangram"),
		pangrams("We promptl"));
}
TEST(twoArrays, testcase1) {
	EXPECT_EQ(string("YES"), twoArrays(10, {2,1,3}, {7,8,9}));
}
TEST(twoArrays, testcase2) {
	EXPECT_EQ(string("NO"), twoArrays(5, { 1,2,2,1 }, { 3,3,3,4 }));
}
TEST(twoArrays, testcase3) {
	EXPECT_EQ(string("YES"), twoArrays(1, { 0,1 }, { 0,2 }));
}
TEST(birthday, testcase1) {
	EXPECT_EQ(2, birthday({2,2,1,3,2},4,2));
}
TEST(strings_xor, testcase1) {
	EXPECT_EQ(string("10000"), strings_xor({ "10101" }, { "00101" }));
}
TEST(findMedian, testcase1) {
	EXPECT_EQ(3, findMedian({ 0,1,2,4,6,5,3 }));
}
TEST(flippingMatrix, testcase1) {
	vector<vector<int>> data = { {1,2},{3,4} };
	EXPECT_EQ(4, flippingMatrix(data));
}
TEST(flippingMatrix, testcase2) {
	vector<vector<int>> data = {
		{112,42,83,119},
		{56,125,56,49},
		{15,78,101,43},
		{62,98,114,108}
	};
	EXPECT_EQ(414, flippingMatrix(data));
}
TEST(flippingMatrix, testcase3) {
	vector<vector<int>> data = {
		{1,2,3,4},
		{1,2,3,4},
		{1,2,3,4},
		{1,2,3,4}
	};
	EXPECT_EQ(14, flippingMatrix(data));
}
TEST(flippingBits, testcase1) {
	EXPECT_EQ(2147483648, flippingBits(2147483647));
}
TEST(flippingBits, testcase2) {
	EXPECT_EQ(4294967294, flippingBits(1));
}
TEST(flippingBits, testcase3) {
	EXPECT_EQ(4294967295, flippingBits(0));;
}
TEST(sockMerchant, testcase1) {
	EXPECT_EQ(2, sockMerchant(7, { 1,2,1,2,1,3,2 }));
}
TEST(findZigZagSequence, testcase1) {
	stringstream buffer;
	streambuf* prebuffer = cout.rdbuf(buffer.rdbuf());
	findZigZagSequence({1,2,3,4,5,6,7 }, 7);
	cout.rdbuf(prebuffer);
	auto output = buffer.str();
	EXPECT_EQ(output,"1 2 3 7 6 5 4\n");
}
TEST(pageCount, testcase1) {
	EXPECT_EQ(1, pageCount(5, 3));
}
TEST(pageCount, testcase2) {
	EXPECT_EQ(0, pageCount(9, 8));
}
TEST(pageCount, testcase3) {
	EXPECT_EQ(1, pageCount(9, 7));
}
TEST(pageCount, testcase4) {
	EXPECT_EQ(1, pageCount(9, 6));
}
TEST(pageCount, testcase5) {
	EXPECT_EQ(2, pageCount(9, 4));
}
TEST(pageCount, testcase6) {
	EXPECT_EQ(2, pageCount(9, 5));
}
TEST(pageCount, testcase7) {
	EXPECT_EQ(1, pageCount(10, 9));
}
TEST(pageCount, testcase8) {
	EXPECT_EQ(1, pageCount(10, 8));
}
TEST(pageCount, testcase9) {
	EXPECT_EQ(1, pageCount(10, 2));
}
TEST(pageCount, testcase10) {
	EXPECT_EQ(1, pageCount(10, 3));
}
TEST(pageCount, testcase11) {
	EXPECT_EQ(2, pageCount(10, 4));
}
TEST(pageCount, testcase12) {
	EXPECT_EQ(2, pageCount(10, 5));
}
TEST(pageCount, testcase13) {
	EXPECT_EQ(1, pageCount(4, 2));
}
TEST(pageCount, testcase14) {
	EXPECT_EQ(1, pageCount(4, 3));
}
TEST(pageCount, testcase15) {
	EXPECT_EQ(0, pageCount(4, 4));
}
TEST(pageCount, testcase16) {
	EXPECT_EQ(0, pageCount(9, 9));
}
TEST(pageCount, testcase17) {
	EXPECT_EQ(2, pageCount(8, 5));
}
TEST(pageCount, testcase18) {
	EXPECT_EQ(2, pageCount(8, 4));
}
TEST(pageCount, testcase19) {
	EXPECT_EQ(1, pageCount(7, 4));
}
TEST(towerBreakers, DISABLED_testcase1) {
	EXPECT_EQ(2, towerBreakers(2, 2));
}
TEST(towerBreakers, DISABLED_testcase2) {
	EXPECT_EQ(1, towerBreakers(1, 4));
}
TEST(towerBreakers, DISABLED_testcase3) {
	EXPECT_EQ(2, towerBreakers(2, 6));
}
TEST(caesarCipher, testcase1) {
	EXPECT_EQ(string("bcd"), caesarCipher({ "abc" }, 1));
}
TEST(caesarCipher, testcase2) {
	EXPECT_EQ(string("defghijklmnopqrstuvwxyzabc"), 
		caesarCipher({ "abcdefghijklmnopqrstuvwxyz" }, 3));
}
TEST(caesarCipher, testcase3) {
	EXPECT_EQ(string("okffng-Qwvb"), caesarCipher({ "middle-Outz" }, 2));
}
TEST(caesarCipher, testcase4){
	EXPECT_EQ(string("cdefghijklmnopqrstuvwxyzab"),
		caesarCipher({ "abcdefghijklmnopqrstuvwxyz" },2));
}
TEST(caesarCipher, testcase5) {
	EXPECT_EQ(string("AB"), caesarCipher({ "YZ" }, 2));
}
TEST(maxMin, testcase1) {
	EXPECT_EQ(1, maxMin(2,{ 1,4,7,2 }));
}
TEST(maxMin, testcase2) {
	EXPECT_EQ(3, maxMin(4, { 1,2,3,4,10,20,30,40,100,200 }));
}
TEST(maxMin, testcase3) {
	EXPECT_EQ(0, maxMin(2, { 1,2,1,2,1 }));
}
TEST(maxMin, testcase4) {
	EXPECT_EQ(20, maxMin(3, { 10,100,300,200,1000,20,30 }));
}
TEST(maxMin, testcase5) {
	EXPECT_EQ(1, maxMin(2, { 10,12,13,14 }));
}
//TEST(dynamicArray, testcase1) {
//	EXPECT_EQ();
//}
//TEST(dynamicArray, testcase2) {
//	EXPECT_EQ();
//}
TEST(gridChallenge, testcase1) {
	vector<string> data = { "abc","ade","efg" };
	EXPECT_EQ(string("YES"), gridChallenge(data));
}
TEST(gridChallenge, testcase2) {
	EXPECT_EQ(string("YES"), gridChallenge({ "ebacd", "fghij", "olmkn", "trpqs", "xywuv" }));
}
TEST(gridChallenge, testcase3) {
    EXPECT_EQ(string("YES"), gridChallenge({ "ebacd", "fghij", "olmkn", "trpqs", "xywuv" }));
}
#endif	