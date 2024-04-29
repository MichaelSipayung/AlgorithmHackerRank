#ifndef CORMEN_ALGORITHM
#define CORMEN_ALGORITHM
#include <iostream>
#include <vector>
using std::vector;
namespace cormen {
	template <typename T, typename Compareble> 
	void insertion_sort(vector<T>& data, Compareble comp) {
		auto len = data.size();
		auto j = 0;
		auto key = T();
		for (auto i = 1; i < len; ++i) {
			j = i - 1;
			key = data[i];
			while (j >= 0 && comp(data[j], key)) {
				data[j + 1] = data[j];
				--j;
			}
			data[j + 1] = key;
		}
	}
	template <typename T>
	void insertion_sort(vector<T>& data) {
		auto len = data.size();
		auto j = 0;
		auto key = T();
		for (auto i = 1; i < len; ++i) {
			j = i - 1;
			key = data[i];
			while (j >= 0 && data[j]>key) {
				data[j + 1] = data[j];
				--j;
			}
			data[j + 1] = key;
		}
	}
}
#endif // !CORMEN_ALGORITHM
