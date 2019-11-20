/*
 * QuickSort.cpp
 *	Author��TWENTYFOUR
 *  Created on: 2019��11��20��
 *  Description of class��
 *  ���ܿ��������㷨��
 *  		���������Լ������㷨�ĸĽ�
 */

#include<iostream>
using namespace std;

/**
 * ��������
 * ʵ�ַ������ݹ�+�з�����
 */
template<class T>
class quickSort {
	/*�����������Ƚϡ�������ָ���������*/
private:
	/*�ȽϷ���*/
	static bool less(T a, T b) {
		return a < b;
	}
	/*��������*/
	static void exchange(T a[], int i, int j) {
		T temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	/*��ָ�������ϵĲ�������*/
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

	/*�зַ���	:	�����ֵ�з�+��ȡ����λ���з�+�����з�*/
private:
	/*������з�*/
	int partition(T a[], int lo, int hi) {
		int i = lo, j = hi + 1; //ɨ��ָ��
		T part = a[lo]; //�з�Ԫ��
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
	//��ȡ���з�
	T sub3partition(T a[], int lo, int hi) {
		T part;
		if (hi - lo < 2) {
			return a[lo];
		}
		T v1 = a[lo], v2 = a[lo + 1], v3 = a[lo + 2];
		int index;
		//��ȡ��λ����2�αȽ�
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
	/*��ȡ��-��λ��-�з�*/
	int partitionSub3(T a[], int lo, int hi) {
		int i = lo, j = hi + 1; //ɨ��ָ��
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
	/*�����㷨����*/
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

	/*����ʵ��*/
public:
	/*�򵥿�������*/
	void QuickSort(T a[], int lo, int hi) {
		if (lo >= hi)
			return;
		int part = partition(a, lo, hi);
		QuickSort(a, lo, part - 1);
		QuickSort(a, part + 1, hi);
	}
	/**
	 * ʹ�ò�������Ľ���������
	 * �Ľ�Ч�ʣ�����10�����ϣ�����һ��������
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
	 * ʹ����ȡ���зָĽ��㷨
	 * �Ľ�Ч�ʣ������ԭʼ���ţ�ʹ����ȡ���зֿ���10������
	 */
	void QuickSortSub3(T a[], int lo, int hi) {
		if (lo >= hi)
			return;
		int part = partitionSub3(a, lo, hi);
		QuickSortSub3(a, lo, part - 1);
		QuickSortSub3(a, part + 1, hi);
	}

	/**
	 * �����зֵĿ�������
	 * ���ã����ڴ����ظ�Ԫ�ص�����
	 * �Ľ�Ч�ʣ����ڰ��������ظ�Ԫ�ص����룬ʱ�临�Ӷȿ��ԴﵽN
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

