#include<iostream>
#include "Sort.h"
#include "MyError.h"
using std::cout;
using std::endl;


void PrintVec(const VEC & vec){
	for (auto elem : vec){
		cout << elem << " ";
	}
	cout << endl;
	cout << "-------------------------------" << endl;
}

void SwapHelp(int & a, int & b){
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

/*
	冒泡排序(稳定排序)
*/
void BubbleSort(VEC & vec){
	if (vec.empty())
		return;

	bool change = true;
	for (unsigned i = 0; (i < vec.size() - 1) && change; ++i){
		change = false;
		for (unsigned j = 0; j < vec.size() - 1 - i; ++j){
			if (vec[j] > vec[j + 1]){
				change = true;
				SwapHelp(vec[j], vec[j + 1]);
			}
		}
	}
}

/*
	选择排序（非稳定排序）
*/

void SelectSort(VEC & vec){
	if (vec.empty())
		return;

	unsigned min_id;
	for (unsigned i = 0; i < vec.size() - 1; ++i){
		min_id = i;
		for (unsigned j = min_id + 1; j < vec.size(); ++j){
			if (vec[min_id] > vec[j])
				min_id = j;
		}

		// swap
		if (min_id != i){
			SwapHelp(vec[min_id], vec[i]);
		}
	}
}

/*
	插入排序（稳定排序）
*/
bool SmallCmp(const int &a, const int &b){
	return a <= b;
}

bool BigCmp(const int &a, const int &b){
	return a >= b;
}

void InsertSort(VEC & vec, bool(*cmp)(const int &, const int &)){
	if (vec.empty())
		return;

	int swap_temp;
	for (unsigned index = 1; index < vec.size(); ++index){
		if (cmp(vec[index - 1], vec[index]))
			continue;

		swap_temp = vec[index];
		int index_temp = index;
		while (index_temp > 0 && (!cmp(vec[index_temp - 1], swap_temp))){
			vec[index_temp] = vec[index_temp - 1];
			--index_temp;
		}
		vec[index_temp] = swap_temp;
	}
}



/*
快速排序（非稳定排序）
*/
void q_sort(VEC & vec, int low, int high, bool(*cmp)(const int &, const int &)){
	if (low >= high)
		return;

	int low_temp = low;
	int high_temp = high;
	int temp_val = vec[low];
	
	while (low < high){
		while (low < high && !cmp(vec[high], temp_val))
			--high;
		vec[low] = vec[high];

		while (low < high && cmp(vec[low], temp_val))
			++low;
		vec[high] = vec[low];
	}
	vec[low] = temp_val;

	q_sort(vec, low_temp, low - 1, cmp);
	q_sort(vec, low + 1, high_temp, cmp);
}


void QuickSort(VEC & vec, bool(*cmp)(const int &, const int &)){
	if (vec.empty())
		return;

	q_sort(vec, 0, vec.size() - 1, cmp);
}


/*
归并排序（稳定）
*/
void merge(VEC & vec1, VEC & vec2, bool(*cmp)(const int &, const int &), VEC::size_type low, VEC::size_type mid, VEC::size_type high){
	if (low > mid || mid > high){
		myerrno = ErrorNo::bad_param;
		return;
	}

	VEC::size_type i = low;
	VEC::size_type j = mid + 1;
	VEC::size_type k = low;
	
	while (i <= mid && j <= high){
		if (cmp(vec1[i], vec1[j]))
			vec2[k++] = vec1[i++];
		else
			vec2[k++] = vec1[j++];
	}

	while (i <= mid){
		vec2[k++] = vec1[i++];
	}

	while (j <= high){
		vec2[k++] = vec1[j++];
	}
}

void merge_sort_core(VEC & vec1, VEC & vec2, bool(*cmp)(const int &, const int &), VEC::size_type low, VEC::size_type high, int cnt){
	if (low > high)
		return;

	if (low == high){
		if (!(cnt & 0x1))
			vec2[low] = vec1[low];
	}
	else{
		VEC::size_type mid = low + (high - low) / 2;   // 避免溢出
		merge_sort_core(vec1, vec2, cmp, low, mid, cnt + 1);
		merge_sort_core(vec1, vec2, cmp, mid + 1, high, cnt + 1);

		if (cnt & 0x1)
			merge(vec2, vec1, cmp, low, mid, high);
		else
			merge(vec1, vec2, cmp, low, mid, high);
	}


		
}



void merge_sort(VEC & vec1, bool(*cmp)(const int &, const int &)){
	if (vec1.empty())
		return;
	// 创建辅助空间
	VEC vec2(vec1.size(), 0);
	merge_sort_core(vec1, vec2, cmp, 0, vec1.size() - 1, 1);      // 注意unsigned负数问题
}














