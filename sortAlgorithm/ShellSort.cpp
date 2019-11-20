/*
 * ShellSort.cpp
 *	Author：TWENTYFOUR
 *  Created on: 2019年11月20日
 *  Description of class：
 *  		介绍希尔排序算法
 */

#include<iostream>
using namespace std;

template<class T>
class shellSort {
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
	//希尔排序
	void ShellSort(T a[], int Len) {
		int gap = 1; //增量
		while (gap < Len / 3)
			gap = 3 * gap + 1; //采用1，4，13，40，121，......的增量序列
		T temp;
		while (gap >= 1) {
			//按增量进行的插入排序
			for (int i = gap; i < Len; i++) {
				temp = a[i];
				int j = i;
				while (j >= gap && (less(temp, a[j - gap]))) {
					a[j] = a[j - gap];
					j -= gap;
				}
				a[j] = temp;
			}
			gap = gap / 3;
		}
	}
};

