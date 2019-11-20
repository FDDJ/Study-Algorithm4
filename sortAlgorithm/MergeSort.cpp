/*
 * MergeSort.cpp
 *	Author��TWENTYFOUR
 *  Created on: 2019��11��20��
 *  Description of class��
 */
#include<iostream>
using namespace std;

template<class T>
class mergeSort {
	/*�����������Ƚϣ���������*/
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

	/*�鲢����*/
private:
	/*�鲢��������*/
	void Merge(T a[], T aux[], int lo, int mid, int hi) {
		//�������ݵ���������
		for (int i = lo; i <= hi; i++) {
			aux[i] = a[i];
		}
		//�鲢
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
	 * ���ٹ鲢
	 * ��;��ȥ����ѭ���м��ĳ����Ƿ��þ��Ĵ���
	 * 			if(i>mid) a[k]=aux[j++];
	 *			else if(j>hi) a[k]=aux[i++];
	 *	���ۣ���������ȶ�
	 * */
	void QuickMerge(T a[], T aux[], int lo, int mid, int hi) {
		//���鸴��
		for (int i = lo; i <= mid; i++)
			aux[i] = a[i];
		for (int j = mid + 1; j <= hi; j++)
			aux[j] = a[hi - j + mid + 1];
		//�鲢
		int i = lo, j = hi;
		for (int k = lo; k <= hi; k++)
			if (less(aux[j], aux[i]))
				a[k] = aux[j--];
			else
				a[k] = aux[i++];
	}
	/*�㷨����*/
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
	/*�㷨ʵ��*/
public:
	/*�Զ����µĹ鲢����*/
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
	 * �Ե����ϵĹ鲢����
	 * Ч�ʣ����Զ����µĹ鲢����Ч���൱
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
	 * �޸��жϹ鲢����1�Ҷ�С������2��˼�ֱ�ӷ���
	 * Ч�ʣ������������������Ϊ����ʱ��
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

