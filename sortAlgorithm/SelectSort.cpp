/*
 * SelectSort.cpp
 *	Author：TWENTYFOUR
 *  Created on: 2019年11月20日
 *  Description of class：
 *  		介绍选择排序
 */

#include<iostream>

using namespace std;
/**
 * 选择排序类
 */
template<class T>
class selectSort {
	/*基本方法：比较，交换方法*/
private:
	/*比较方法*/
	static bool less(T a, T b) {
		return a < b;
	}
	/*交换方法*/
	static void exchange(T a[], int i, int j) {
		T temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
public:
	//选择排序
	void SelectSort(T a[], int Len) {
		int min;
		for (int i = 0; i < Len - 1; i++) {
			min = i;
			for (int j = i + 1; j < Len; j++) {
				if (less(a[j], a[min]))
					min = j;
			}
			exchange(a, i, min);
		}
	}
};

