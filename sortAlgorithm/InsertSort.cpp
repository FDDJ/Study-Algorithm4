/*
 * InsertSort.cpp
 *	Author：TWENTYFOUR
 *  Created on: 2019年11月20日
 *  Description of class：
 *  		介绍插入排序及其改进
 */
#include<iostream>
using namespace std;

template<class T>
class insertSort {
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
	/**
	 * 插入排序
	 * 基本插入排序+指定区间上的插入排序
	 */
	void InsertSort(T a[], int Len) {
		int j;
		for (int i = 1; i < Len; i++) {
			j = i;
			while (less(a[j], a[j - 1]) && j > 0) { //比较操作
				exchange(a, j, j - 1); //交换操作
				j--;
			}
		}
	}
	/*在指定区间上的插入排序*/
	void InsertSortLimit(T a[], int lo, int hi) {
		int j;
		for (int i = lo + 1; i <= hi; i++) {
			j = i;
			while (less(a[j], a[j - 1]) && j > lo) {
				exchange(a, j - 1, j);
				j--;
			}
		}
	}
	/**
	 * 不用进行边界检测的插入排序
	 * 改进效率：与简单插入排序效率相当
	 */
	void InsertSortNoCheck(T a[], int Len) {
		//找到最小值
		int min = 0;
		for (int i = 1; i < Len; i++) {
			if (less(a[i], a[min])) {
				min = i;
			}
		}
		exchange(a, 0, min); //将最小值交换到0处
		//不用进行边界检测的插入排序
		int j;
		for (int i = 1; i < Len; i++) {
			j = i;
			while (less(a[j], a[j - 1])) {		//比较操作
				exchange(a, j, j - 1);		//交换操作
				j--;
			}
		}
	}
	/*
	 * 带有检查点并且不用交换的插入排序
	 * 改进效率：比原始插入排序大约快2倍
	 */
	void InSortPandNoExch(T a[], int Len) {
		//找到最小值
		int min = 0, changes = 0;
		for (int i = 1; i < Len; i++) {
			if (less(a[i], a[min])) {
				exchange(a, i, min);
				changes++;
			}
		}
		if (changes == 0)
			return;
		T temp;
		int j;
		for (int i = 2; i < Len; i++) {
			temp = a[i];
			j = i;
			while (less(temp, a[j - 1])) {		//比较操作
				a[j] = a[j - 1];		//移动操作
				j--;
			}
			a[j] = temp;
		}
	}
};

