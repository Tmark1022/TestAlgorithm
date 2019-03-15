#include<iostream>
#include "MyError.h"
#include "Sort.h"

using std::vector;

int main(int argc, char * argv[]){
	VEC vec1;
	VEC vec2 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	VEC vec3(vec2.rbegin(), vec2.rend());
	VEC vec4 = { 4, 1, 2, 8, 5, 3, 8, 6, 10, 8, 9 , 0};

	vector<VEC *> all = { &vec1, &vec2, &vec3, &vec4 };
	all.shrink_to_fit();

	for (VEC * elem : all){
		merge_sort(*elem, SmallCmp);
		PrintVec(*elem);
	}
	return 0;
} 