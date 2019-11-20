/*
 * MergeSort.cpp
 *	Author：TWENTYFOUR
 *  Created on: 2019年11月20日
 *  Description of class：
 */
#include<iostream>
using namespace std;

template<class T>
class mergeSort {
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

	/*归并操作*/
private:
	/*归并有序数组*/
	void Merge(T a[], T aux[], int lo, int mid, int hi) {
		//复制数据到辅助数组
		for (int i = lo; i <= hi; i++) {
			aux[i] = a[i];
		}
		//归并
		int i = lo, j = mid + 1;
		for (int k = lo; k <= hi; k++) {
			if (i > mid)
				a[k] = aux[j++];
			else if (j > hi)
				a[k] = aux[i++];
			else if (less(aux[i], aux[j]))
				a[k] = aux[i++];
			else
				a[k] = aux[j++];
		}
	}
	/**
	 * 快速归并
	 * 用途：去掉内循环中检测某半边是否用尽的代码
	 * 			if(i>mid) a[k]=aux[j++];
	 *			else if(j>hi) a[k]=aux[i++];
	 *	代价：造成排序不稳定
	 * */
	void QuickMerge(T a[], T aux[], int lo, int mid, int hi) {
		//数组复制
		for (int i = lo; i <= mid; i++)
			aux[i] = a[i];
		for (int j = mid + 1; j <= hi; j++)
			aux[j] = a[hi - j + mid + 1];
		//归并
		int i = lo, j = hi;
		for (int k = lo; k <= hi; k++)
			if (less(aux[j], aux[i]))
				a[k] = aux[j--];
			else
				a[k] = aux[i++];
	}
	/*算法调用*/
public:
	void MergeSortUb(T a[], int Len) {
		T* aux = new T[Len];
		MergeSortUb(a, aux, 0, Len - 1);
		delete[] aux;
	}
	void MergeSortBu(T a[], int Len) {
		T* aux = new T[Len];
		MergeSortBu(a, aux, Len);
		delete[] aux;
	}
	void MergeSortBuLine(T a[], int Len) {
		T* aux = new T[Len];
		MergeSortBuLine(a, aux, Len);
		delete[] aux;
	}
	/*算法实现*/
public:
	/*自顶向下的归并排序*/
	void MergeSortUb(T a[], T aux[], int lo, int hi) {
		if (hi <= lo)
			return;
		int mid = (lo + hi) / 2;
		MergeSortUb(a, aux, lo, mid);
		MergeSortUb(a, aux, mid + 1, hi);
		if (a[mid] > a[mid + 1]) {
			Merge(a, aux, lo, mid, hi);
		}
	}
	/**
	 * 自底向上的归并排序
	 * 效率：与自顶向下的归并排序效率相当
	 */
	void MergeSortBu(T a[], T aux[], int Len) {
		for (int aSize = 1; aSize < Len; aSize *= 2) {
			for (int lo = 0; lo < Len; lo += 2 * aSize) {
				int hi = lo + 2 * aSize - 1, mid = lo + aSize - 1;
				hi = hi > (Len - 1) ? Len - 1 : hi;
				Merge(a, aux, lo, mid, hi);
			}
		}
	}
	/**
	 * 修改判断归并数组1右端小与数组2左端及直接返回
	 * 效率：处理任意有序数组变为线性时间
	 */
	void MergeSortBuLine(T a[], T aux[], int Len) {
		for (int aSize = 1; aSize < Len; aSize *= 2) {
			for (int lo = 0; lo < Len; lo += 2 * aSize) {
				int hi = lo + 2 * aSize - 1, mid = lo + aSize - 1;
				hi = hi > (Len - 1) ? Len - 1 : hi;
				if (a[mid] > a[mid + 1]) {
					Merge(a, aux, lo, mid, hi);
				}
			}
		}
	}

};

