/*
 * QuickSort.cpp
 *	Author：TWENTYFOUR
 *  Created on: 2019年11月20日
 *  Description of class：
 *  介绍快速排序算法：
 *  		基本快排以及快排算法的改进
 */

#include<iostream>
using namespace std;

/**
 * 快速排序
 * 实现方法：递归+切分数组
 */
template<class T>
class quickSort {
	/*基本方法：比较、交换、指定区间插排*/
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

	/*切分方法	:	最左端值切分+三取样中位数切分+三向切分*/
private:
	/*最左端切分*/
	int partition(T a[], int lo, int hi) {
		int i = lo, j = hi + 1; //扫描指针
		T part = a[lo]; //切分元素
		while (1) {
			while (less(a[++i], part)) {
				if (i == hi)
					break;
			}
			while (less(part, a[--j])) {
			}
			if (i >= j)
				break;
			exchange(a, i, j);
		}
		exchange(a, lo, j);
		return j;
	}
	//三取样切分
	T sub3partition(T a[], int lo, int hi) {
		T part;
		if (hi - lo < 2) {
			return a[lo];
		}
		T v1 = a[lo], v2 = a[lo + 1], v3 = a[lo + 2];
		int index;
		//获取中位数：2次比较
		if ((v1 - v2) * (v2 - v3) > 0)
			index = lo + 1;
		else if ((v2 - v1) * (v1 - v3) > 0)
			index = lo;
		else
			index = lo + 2;

		part = a[index];
		exchange(a, lo, index);
		return part;
	}
	/*三取样-中位数-切分*/
	int partitionSub3(T a[], int lo, int hi) {
		int i = lo, j = hi + 1; //扫描指针
		T part = sub3partition(a, lo, hi);
		while (1) {
			while (less(a[++i], part)) {
				if (i == hi)
					break;
			}
			while (less(part, a[--j])) {
			}
			if (i >= j)
				break;
			exchange(a, i, j);
		}
		exchange(a, lo, j);
		return j;
	}
	/*快排算法调用*/
public:

	void QuickSort(T a[], int Len) {
		QuickSort(a, 0, Len - 1);
	}
	void QuickSortSmallInsert(T a[], int Len) {
		QuickSortSmallInsert(a, 0, Len - 1);
	}
	void QuickSortSub3(T a[], int Len) {
		QuickSortSub3(a, 0, Len - 1);
	}
	void QuickSortManyRepeat(T a[], int Len) {
		QuickSortManyRepeat(a, 0, Len - 1);
	}

	/*快排实现*/
public:
	/*简单快速排序*/
	void QuickSort(T a[], int lo, int hi) {
		if (lo >= hi)
			return;
		int part = partition(a, lo, hi);
		QuickSort(a, lo, part - 1);
		QuickSort(a, part + 1, hi);
	}
	/**
	 * 使用插入排序改进快速排序
	 * 改进效率：快了10倍以上，提升一个数量级
	 */
	void QuickSortSmallInsert(T a[], int lo, int hi) {
		if (hi <= lo + 15) {
			InsertSortLimit(a, lo, hi);
			return;
		}
		int part = partition(a, lo, hi);
		QuickSortSmallInsert(a, lo, part - 1);
		QuickSortSmallInsert(a, part + 1, hi);
	}
	/**
	 * 使用三取样切分改进算法
	 * 改进效率：相比于原始快排，使用三取样切分快了10倍以上
	 */
	void QuickSortSub3(T a[], int lo, int hi) {
		if (lo >= hi)
			return;
		int part = partitionSub3(a, lo, hi);
		QuickSortSub3(a, lo, part - 1);
		QuickSortSub3(a, part + 1, hi);
	}

	/**
	 * 三向切分的快速排序
	 * 适用：存在大量重复元素的数组
	 * 改进效率：对于包含大量重复元素的输入，时间复杂度可以达到N
	 */
	void QuickSortManyRepeat(T a[], int lo, int hi) {
		if (hi <= lo)
			return;
		int lt = lo, i = lo + 1, gt = hi;
		T v = a[lo];
		while (i <= gt) {
			if (a[i] < v)
				exchange(a, lt++, i++);
			else if (a[i] > v)
				exchange(a, gt--, i);
			else
				i++;
		}
		QuickSortManyRepeat(a, lo, lt - 1);
		QuickSortManyRepeat(a, gt + 1, hi);
	}
};

