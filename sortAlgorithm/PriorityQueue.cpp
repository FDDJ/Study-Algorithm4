/*
 * PriorityQueue.cpp
 *	Author��TWENTYFOUR
 *  Created on: 2019��11��20��
 *  Description of class��
 *  		������ι������/��С���ȶ���
 */
#include<iostream>
using namespace std;

/**
 * ������ȶ��е�ʵ��
 * ��С���ȶ��У��ı�ȽϷ�������
 */
template <class T>
class MaxPQ{
private:
	//������󳤶�
	int maxSize;
	//���г���
	int N=0;
	//���ȶ���
	T* pq;
	//Ԫ�رȽ�
	bool less(int i,int j){
		return pq[i]<pq[j];
	}
	//Ԫ�ؽ���
	void exchange(int i,int j){
		T temp = pq[i];
		pq[i] = pq[j];
		pq[j] = temp;
	}

	//�ϸ�����
	void swim(int k){
		while(k>1&&less(k/2,k)){
			exchange(k/2,k);
			k=k/2;
		}
	}
	//�³�����
	void sink(int k){
		while(2*k<=N){
			int j=2*k;
			if(j<N&&less(j,j+1)) j++;
			if(!less(k,j)) break;
			exchange(k,j);
			k=j;
		}
	}
	//��̬�������г���
	void reSize(int Len){
		T* temp=new T[N+1];
		for(int i=1;i<=N;i++){
			temp[i]=pq[i];
		}
		pq=new T[Len];
		for(int i=1;i<=N;i++){
			pq[i]=temp[i];
		}
		delete [] temp;
	}

public:
	//�����������Ϊmax�����ȶ���
	MaxPQ(int max){
		pq=new T[max];
		maxSize=max;
	}
	//�����ȶ����в���һ��Ԫ��
	void insert(T v){
		pq[++N]=v;
		swim(N);
		//��̬���������С
		if(N==maxSize){
			reSize(2*N);
		}
	}
	//�������Ԫ��
	T max(){
		T *result=NULL;
		if(N!=0){
			return pq[1];
		}
		return *result;
	}
	//ɾ�����������Ԫ��
	T delMax(){
		T max=pq[1];
		exchange(1,N--);
		pq[N+1]=NULL;//��ֹԽ��
		sink(1);
		//��̬���������С
		if(N<=maxSize/4){
			reSize(2*N);
		}

		return max;
	}
	//���ض����Ƿ��ǿ�
	bool isEmpty(){
		return N==0;
	}
	//�������ȶ�����Ԫ�ص���Ŀ
	int size(){
		return N;
	}
};




