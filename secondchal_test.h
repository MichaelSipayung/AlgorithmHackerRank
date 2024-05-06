#ifndef WEEK_TWO_TEST
#define WEEK_TWO_TEST
#include "secondchal.h"
#include <gtest/gtest.h>
TEST(balancedSums, testcase1) {
	EXPECT_EQ(string("YES"), balancedSums({ 5,6,8,11 }));
}
TEST(balancedSums, noway) {
	EXPECT_EQ(string("NO"), balancedSums({ 1,2,3 }));
}
TEST(balancedSums, singleway) {
	EXPECT_EQ(string("YES"), balancedSums({ 1,2,3,3 }));
}
TEST(balancedSums, involvezero) {
	EXPECT_EQ(string("YES"), balancedSums({ 2,0,0,0 }));
}
TEST(balancedSums, sizeisone) {
	EXPECT_EQ(string("YES"), balancedSums({ 1 }));
}
TEST(counterGame, sampletest1){
    EXPECT_EQ(string("Louise"), counterGame(132));
}
TEST(counterGame, sampletest2) {
	EXPECT_EQ(string("Richard"), counterGame(6));
}
TEST(superDigit, sampletest1) {
	EXPECT_EQ(8, superDigit({ "9875" }, 4));
}
TEST(superDigit, sampletest2) {
	EXPECT_EQ(3, superDigit({ "148" }, 3));
}
TEST(superDigit, longdigits) {
	EXPECT_EQ(1, superDigit({ "1" }, pow(10, 5)));
}
TEST(sumXor, sampletest1) {
	EXPECT_EQ(4, sumXor(4));
}
TEST(sumXor, sampletest2) {
	EXPECT_EQ(2, sumXor(5));
}
TEST(sumXor, sampletest3) {
	EXPECT_EQ(16, sumXor(100));
}
TEST(sumXor, sampletest4) {
	EXPECT_EQ(16, sumXor(1000));
}
TEST(palindromeIndex, sampletest1) {
	EXPECT_EQ(-1, palindromeIndex({ "abcdedcba" }));
}
TEST(palindromeIndex, sampletest2) {
	EXPECT_EQ(0, palindromeIndex({ "baa" }));
}
TEST(palindromeIndex, sampletest3) {
	EXPECT_EQ(3, palindromeIndex({ "aaab" }));
}
TEST(getTotalX, sampletest1) {
	EXPECT_EQ(2, getTotalX({ 2,6 }, { 24,36 }));
}
TEST(getTotalX, sampletest2) {
	EXPECT_EQ(3, getTotalX({ 2,4 }, { 16,32,96 }));
}
TEST(isValid, sample1){
    EXPECT_EQ(string("YES"), isValid({"abc"}));
}
TEST(isvalid, sample2){
    EXPECT_EQ(string("NO"), isValid({"abccc"}));
}
TEST(isvalid, sample3){
    EXPECT_EQ(string("NO"), isValid({"aabbcd"}));
}
TEST(isvalid, sample4) {
	EXPECT_EQ(string("YES"), isValid({ "aabbccd" }));
}
TEST(isvalid, sample5) {
	EXPECT_EQ(string("NO"), isValid({ "aabbcddd" }));
}
TEST(isvalid, sample7) {
	EXPECT_EQ(string("NO"), isValid({ "aaaabbcc" }));
}
TEST(isvalid, sample8) {
	EXPECT_EQ(string("YES"), isValid({ "aaaaaaaaaaa" }));
}
TEST(isvalid, sample9) {
	EXPECT_EQ(string("NO"), isValid({ "aaabbcccdd" }));
}
TEST(isvalid, sample10) {
	const string s = "ibfdgaeadiaefgbhbdghhhbgdfgeiccbiehhfcggchgghadhdhagfbahhddgghbdehidbibaeaagaeeigffcebfbaieggabcfbiiedcabfihchdfabifahcbhagccbdfifhghcadfiadeeaheeddddiecaicbgigccageicehfdhdgafaddhffadigfhhcaedcedecafeacbdacgfgfeeibgaiffdehigebhhehiaahfidibccdcdagifgaihacihadecgifihbebffebdfbchbgigeccahgihbcbcaggebaaafgfedbfgagfediddghdgbgehhhifhgcedechahidcbchebheihaadbbbiaiccededchdagfhccfdefigfibifabeiaccghcegfbcghaefifbachebaacbhbfgfddeceababbacgffbagidebeadfihaefefegbghgddbbgddeehgfbhafbccidebgehifafgbghafacgfdccgifdcbbbidfifhdaibgigebigaedeaaiadegfefbhacgddhchgcbgcaeaieiegiffchbgbebgbehbbfcebciiagacaiechdigbgbghefcahgbhfibhedaeeiffebdiabcifgccdefabccdghehfibfiifdaicfedagahhdcbhbicdgibgcedieihcichadgchgbdcdagaihebbabhibcihicadgadfcihdheefbhffiageddhgahaidfdhhdbgciiaciegchiiebfbcbhaeagccfhbfhaddagnfieihghfbaggiffbbfbecgaiiidccdceadbbdfgigibgcgchafccdchgifdeieicbaididhfcfdedbhaadedfageigfdehgcdaecaebebebfcieaecfagfdieaefdiedbcadchabhebgehiidfcgahcdhcdhgchhiiheffiifeegcfdgbdeffhgeghdfhbfbifgidcafbfcd";
	EXPECT_EQ(string{ "YES" }, isValid(s));
}
TEST(isvalid, sample11) {
	string s = "abcdefghhgfedecba";
	EXPECT_EQ(string("YES"), isValid(s));
}
TEST(climbingLeaderboard, sample1) {
	EXPECT_EQ(vector({4,3,1}), climbingLeaderboard({100,90,90,80},{70,80,105}));
}
TEST(climbingLeaderboard, sample2) {
	EXPECT_EQ(vector({ 6,4,2,1 }), climbingLeaderboard({ 100, 100, 50, 40, 40, 20, 10 },
		{ 5, 25, 50 ,120 }));
}
TEST(climbingLeaderboard, sample3) {
	EXPECT_EQ(vector({ 6,5,4,2,1 }), climbingLeaderboard({ 100, 90, 90, 80, 75, 60 },
		{ 50, 65, 77, 90, 102 }));
}
TEST(isBalanced,sample1){
	EXPECT_EQ(string("YES"), isBalanced({ "{[()]}" }));
}
TEST(isBalanced, sample2){
	EXPECT_EQ(string("YES"), isBalanced({ "{{[[(())]]}}" }));
}
TEST(isBalanced, sample3) {
	EXPECT_EQ(string("NO"), isBalanced({ "{[(])}" }));
}
TEST(isBalanced, sample4){
	EXPECT_EQ(string("NO"), isBalanced({ "{[(])}" }));
}
TEST(isBalanced, sample5) {
	EXPECT_EQ(string("NO"), isBalanced({ "{[(])}" }));
}
TEST(isBalanced, sample6){
	EXPECT_EQ(string("YES"), isBalanced({ "{(([])[])[]}[]" }));
}
TEST(isBalanced, sample7){
	EXPECT_EQ(string("NO"), isBalanced({ "{(([])[])[]]}" }));
}
TEST(iceCreamPolar, sample1){
	EXPECT_EQ(vector({ 1,4 }), icecreamParlor(6, { 1,3,4,5,6 }));
}
TEST(iceCreamPolar, sample2){
	EXPECT_EQ(vector({ 1,4 }), icecreamParlor(4, { 1, 4, 5, 3, 2 }));
}
TEST(iceCreamPolar, sample3){
	EXPECT_EQ(vector({ 1,2 }), icecreamParlor(4, { 2, 2 ,4 ,3 }));
}
TEST(waiter, sample1) {
	vector<int> dest = { 2,4,6,3,5,7 };
	EXPECT_EQ(dest, waiter({2,3,4,5,6,7}, 3));
}
TEST(waiter, sample2) {
	vector<int> dest = {4,6,3,7,5};
	EXPECT_EQ(dest,waiter({3,4,7,6,5}, 1));
}
TEST(equalStacks, sample1) {
	EXPECT_EQ(5, equalStacks({ 3,2,1,1,1 }, { 4,3,2 }, { 1,1,4,1 }));
}
TEST(equalStacks, sample2){
	EXPECT_EQ(2,equalStacks({1,2,1,1},{1,1,2},{1,1}));
}
TEST(maxSubarray, sample1) {
	EXPECT_EQ(vector({ 16,20 }), maxSubarray({ -1,2,3,-4,5,10 }));
}
TEST(maxSubarray, sample2) {
	EXPECT_EQ(vector({ 10,11}), maxSubarray({ 2, -1, 2, 3, 4, -5 }));
}
TEST(crosingdemo, sample1) {
	vector<int> data = { 13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7 };
	int len = data.size()-1;
	auto temp = crosing_demo(data, 0, len);
	//println("result: {}", temp);
	EXPECT_EQ(vector({7,10,43}), temp );
}
TEST(crosingdemo, sample2) {
	vector<int> data = {-1,2,3,-4,5,10};
	int len = data.size()-1;
	auto temp = crosing_demo(data, 0, len);
	//println("result: {}",temp);
	EXPECT_EQ(vector<int>({1,5,16}), temp);
}
TEST(maxSubarray, sample3) {
	vector<int> data = {1};
	EXPECT_EQ(vector({ 1,1 }), maxSubarray(data));
}
TEST(maxSubarray, sample4) {
	vector<int> data = { -1 ,-2 ,-3 ,-4 ,-5 ,-6 };
	EXPECT_EQ(vector({ -1,-1 }), maxSubarray(data));
}
TEST(maxSubarray, sample5) {
	vector<int> data = { 1 ,-2 };
	EXPECT_EQ(vector({ 1,1 }), maxSubarray(data));
}
TEST(maxSubarray, sample6) {
	vector<int> data = { 1, -1 ,-1 ,-1 ,-1, 5 };
	EXPECT_EQ(vector({ 5,6 }), maxSubarray(data));
}
TEST(maxcrosing, sample1){
	vector<int> data = { 13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7 };
	EXPECT_EQ(vector({ 7,10,43 }), max_crossing_array(data, 0,7,15));
}
#endif // !WEEK_TWO_TEST
