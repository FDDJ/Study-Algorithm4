/*
 * InsertSort.cpp
 *	Author��TWENTYFOUR
 *  Created on: 2019��11��20��
 *  Description of class��
 *  		���ܲ���������Ľ�
 */
#include<iostream>
using namespace std;

template<class T>
class insertSort {
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
	/**
	 * ��������
	 * ������������+ָ�������ϵĲ�������
	 */
	void InsertSort(T a[], int Len) {
		int j;
		for (int i = 1; i < Len; i++) {
			j = i;
			while (less(a[j], a[j - 1]) && j > 0) { //�Ƚϲ���
				exchange(a, j, j - 1); //��������
				j--;
			}
		}
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
	/**
	 * ���ý��б߽���Ĳ�������
	 * �Ľ�Ч�ʣ���򵥲�������Ч���൱
	 */
	void InsertSortNoCheck(T a[], int Len) {
		//�ҵ���Сֵ
		int min = 0;
		for (int i = 1; i < Len; i++) {
			if (less(a[i], a[min])) {
				min = i;
			}
		}
		exchange(a, 0, min); //����Сֵ������0��
		//���ý��б߽���Ĳ�������
		int j;
		for (int i = 1; i < Len; i++) {
			j = i;
			while (less(a[j], a[j - 1])) {		//�Ƚϲ���
				exchange(a, j, j - 1);		//��������
				j--;
			}
		}
	}
	/*
	 * ���м��㲢�Ҳ��ý����Ĳ�������
	 * �Ľ�Ч�ʣ���ԭʼ���������Լ��2��
	 */
	void InSortPandNoExch(T a[], int Len) {
		//�ҵ���Сֵ
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
			while (less(temp, a[j - 1])) {		//�Ƚϲ���
				a[j] = a[j - 1];		//�ƶ�����
				j--;
			}
			a[j] = temp;
		}
	}
};

