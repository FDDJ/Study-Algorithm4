/*
 * HeapSort.cpp
 *	Author：TWENTYFOUR
 *  Created on: 2019年11月20日
 *  Description of class：
 *			介绍堆排序算法
 */

#include<iostream>
using namespace std;

template<class T>
class HeapSort {
private:
	//元素比较
	bool less(T a, T b) {
		return a < b;
	}
	//元素交换
	void exchange(T pq[], int i, int j) {
		T temp = pq[i];
		pq[i] = pq[j];
		pq[j] = temp;
	}
	//下沉操作
	void sink(T a[], int k, int N) {
		//从根节点开始向下寻找最大的元素
		while (2 * k <= N) {
			int j = 2 * k;
			//找到左右子节点的最大值
			if (j < N && less(a[j - 1], a[j]))
				j++;
			//如果父节点大于叶子节点的最大值就退出，否则就交换
			if (!less(a[k - 1], a[j - 1]))
				break;
			exchange(a, k - 1, j - 1);
			//以最大的叶节点继续向下找
			k = j;
		}
	}

public:
	HeapSort(T a[], int Len) {
		int N = Len;
		//构造堆
		for (int k = N / 2; k >= 1; k--) {
			sink(a, k, N);
		}
		while (N > 1) {
			exchange(a, 1 - 1, N - 1);
			N--;
			sink(a, 1, N);
		}

	}
};

