/*
 * SelectSort.cpp
 *	Author��TWENTYFOUR
 *  Created on: 2019��11��20��
 *  Description of class��
 *  		����ѡ������
 */

#include<iostream>

using namespace std;
/**
 * ѡ��������
 */
template<class T>
class selectSort {
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
public:
	//ѡ������
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

