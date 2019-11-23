#ifndef SORT_H
#define SORT_H
#include<vector>
https://www.pornhub.com/view_video.php?viewkey=ph5dae71a549a46#1
typedef std::vector<int> VEC;

// 排序算法全部基于容器类型vector<int>

void PrintVec(const VEC & vec);
void BubbleSort(VEC & vec);
void SelectSort(VEC & vec);
bool SmallCmp(const int &a, const int &b);
bool BigCmp(const int &a, const int &b);
void InsertSort(VEC & vec, bool(*cmp)(const int &, const int &));
void QuickSort(VEC & vec, bool(*cmp)(const int &, const int &));
void merge_sort(VEC & vec1, bool(*cmp)(const int &, const int &));
#endif
