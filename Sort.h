#ifndef SORT_H
#define SORT_H
#include<vector>

typedef std::vector<int> VEC;

// 排序算法全部基于容器类型vector<int>

void PrintVec(const VEC & vec);
void BubbleSort(VEC & vec);
void SelectSort(VEC & vec);


#endif