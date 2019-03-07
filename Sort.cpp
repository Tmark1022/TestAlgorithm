#include<iostream>
#include "Sort.h"
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
	√∞≈›≈≈–Ú(Œ»∂®≈≈–Ú)
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
	—°‘Ò≈≈–Ú£®∑«Œ»∂®≈≈–Ú£©
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
	≤Â»Î≈≈–Ú£®Œ»∂®≈≈–Ú£©
*/
void InsertSort(VEC & vec){
	if (vec.empty())
		return;

	//unsigned min_id;
	//for (unsigned i = 0; i < vec.size() - 1; ++i){
	//	min_id = i;
	//	for (unsigned j = min_id + 1; j < vec.size(); ++j){
	//		if (vec[min_id] > vec[j])
	//			min_id = j;
	//	}

	//	// swap
	//	if (min_id != i){
	//		SwapHelp(vec[min_id], vec[i]);
	//	}
	//}
}

















