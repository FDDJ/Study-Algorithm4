/*
 * HeapSort.cpp
 *	Author��TWENTYFOUR
 *  Created on: 2019��11��20��
 *  Description of class��
 *			���ܶ������㷨
 */

#include<iostream>
using namespace std;

template<class T>
class HeapSort {
private:
	//Ԫ�رȽ�
	bool less(T a, T b) {
		return a < b;
	}
	//Ԫ�ؽ���
	void exchange(T pq[], int i, int j) {
		T temp = pq[i];
		pq[i] = pq[j];
		pq[j] = temp;
	}
	//�³�����
	void sink(T a[], int k, int N) {
		//�Ӹ��ڵ㿪ʼ����Ѱ������Ԫ��
		while (2 * k <= N) {
			int j = 2 * k;
			//�ҵ������ӽڵ�����ֵ
			if (j < N && less(a[j - 1], a[j]))
				j++;
			//������ڵ����Ҷ�ӽڵ�����ֵ���˳�������ͽ���
			if (!less(a[k - 1], a[j - 1]))
				break;
			exchange(a, k - 1, j - 1);
			//������Ҷ�ڵ����������
			k = j;
		}
	}

public:
	HeapSort(T a[], int Len) {
		int N = Len;
		//�����
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

