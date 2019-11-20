/*
 * PriorityQueue.cpp
 *	Author：TWENTYFOUR
 *  Created on: 2019年11月20日
 *  Description of class：
 *  		介绍如何构建最大/最小优先队列
 */
#include<iostream>
using namespace std;

/**
 * 最大优先队列的实现
 * 最小优先队列：改变比较方法即可
 */
template <class T>
class MaxPQ{
private:
	//队列最大长度
	int maxSize;
	//队列长度
	int N=0;
	//优先队列
	T* pq;
	//元素比较
	bool less(int i,int j){
		return pq[i]<pq[j];
	}
	//元素交换
	void exchange(int i,int j){
		T temp = pq[i];
		pq[i] = pq[j];
		pq[j] = temp;
	}

	//上浮操作
	void swim(int k){
		while(k>1&&less(k/2,k)){
			exchange(k/2,k);
			k=k/2;
		}
	}
	//下沉操作
	void sink(int k){
		while(2*k<=N){
			int j=2*k;
			if(j<N&&less(j,j+1)) j++;
			if(!less(k,j)) break;
			exchange(k,j);
			k=j;
		}
	}
	//动态调整队列长度
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
	//创建最大容量为max的优先队列
	MaxPQ(int max){
		pq=new T[max];
		maxSize=max;
	}
	//向优先队列中插入一个元素
	void insert(T v){
		pq[++N]=v;
		swim(N);
		//动态调整数组大小
		if(N==maxSize){
			reSize(2*N);
		}
	}
	//返回最大元素
	T max(){
		T *result=NULL;
		if(N!=0){
			return pq[1];
		}
		return *result;
	}
	//删除并返回最大元素
	T delMax(){
		T max=pq[1];
		exchange(1,N--);
		pq[N+1]=NULL;//防止越界
		sink(1);
		//动态调整数组大小
		if(N<=maxSize/4){
			reSize(2*N);
		}

		return max;
	}
	//返回队列是否是空
	bool isEmpty(){
		return N==0;
	}
	//返回优先队列中元素的数目
	int size(){
		return N;
	}
};




