/*
 * ShellSort.cpp
 *	Author��TWENTYFOUR
 *  Created on: 2019��11��20��
 *  Description of class��
 *  		����ϣ�������㷨
 */

#include<iostream>
using namespace std;

template<class T>
class shellSort {
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
	//ϣ������
	void ShellSort(T a[], int Len) {
		int gap = 1; //����
		while (gap < Len / 3)
			gap = 3 * gap + 1; //����1��4��13��40��121��......����������
		T temp;
		while (gap >= 1) {
			//���������еĲ�������
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

