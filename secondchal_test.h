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
	string s = "ibfdgaeadiaefgbhbdghhhbgdfgeiccbiehhfcggchgghadhdhagfbahhddgghbdehidbibaeaagaeeigffcebfbaieggabcfbiiedcabfihchdfabifahcbhagccbdfifhghcadfiadeeaheeddddiecaicbgigccageicehfdhdgafaddhffadigfhhcaedcedecafeacbdacgfgfeeibgaiffdehigebhhehiaahfidibccdcdagifgaihacihadecgifihbebffebdfbchbgigeccahgihbcbcaggebaaafgfedbfgagfediddghdgbgehhhifhgcedechahidcbchebheihaadbbbiaiccededchdagfhccfdefigfibifabeiaccghcegfbcghaefifbachebaacbhbfgfddeceababbacgffbagidebeadfihaefefegbghgddbbgddeehgfbhafbccidebgehifafgbghafacgfdccgifdcbbbidfifhdaibgigebigaedeaaiadegfefbhacgddhchgcbgcaeaieiegiffchbgbebgbehbbfcebciiagacaiechdigbgbghefcahgbhfibhedaeeiffebdiabcifgccdefabccdghehfibfiifdaicfedagahhdcbhbicdgibgcedieihcichadgchgbdcdagaihebbabhibcihicadgadfcihdheefbhffiageddhgahaidfdhhdbgciiaciegchiiebfbcbhaeagccfhbfhaddagnfieihghfbaggiffbbfbecgaiiidccdceadbbdfgigibgcgchafccdchgifdeieicbaididhfcfdedbhaadedfageigfdehgcdaecaebebebfcieaecfagfdieaefdiedbcadchabhebgehiidfcgahcdhcdhgchhiiheffiifeegcfdgbdeffhgeghdfhbfbifgidcafbfcd";
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
#endif // !WEEK_TWO_TEST
