/*
 * SuanFa.cpp
 *
 *  Created on: 2019��11��13��
 *      Author: 31907
 */

#include<iostream>
#include<time.h>
#include<math.h>
#include<string>

using namespace std;
/**
 * ջ�����
 * ʹ������ʵ��ջ
 * */
//����ڵ�
template<typename T>
class node {
public:
	T data;
	node<T>* next;
public:
	node() {
		next = nullptr;
	}
	;
	node(T d) {
		next = nullptr;
		data = d;
	}
	~node() {
	}
	;
};
//����ջ
template<typename T>
class MyStack {
private:
	typedef struct node {
		T data;
		node* next;
	} Node;
	Node *first;
	int N = 0;
public:
	MyStack() {
		first = nullptr;
	}
	void push(T StackData) {
		Node *old = new Node();
		old->data = StackData;
		old->next = first;
		first = old;
		N++;
	}
	T pop() {
		T d = first->data;
		first = first->next;
		N--;
		return d;
	}
	bool isEmpty() {
		return N == 0;
	}
	int size() {
		return N;
	}

};
/**
 * ϰ��1.4.19-����ľֲ���Сֵ
 * ��������
 */
typedef struct point{
	int x;
	int y;
	int value;
}Point;
/*
 * �㷨��1�µ�ϰ������
 * */
class Algs4Chapter1{
public:

public:
	Algs4Chapter1(){}
	~Algs4Chapter1(){}
	/*1.4.18 ����ľֲ���СԪ��*/
	//�����к���N��������ͬ������
	//һ��������Сֵ����һ�����ھֲ���СԪ��
	int LocalMin(int num[ ],int L){
		if(L==0)
			return -1;
		if(L==1||num[0]<num[1]){
			return 0;
		}
		if(num[L-1]<num[L-2])
			return L-1;
		//���ֲ��ң�
		int left=0,right=L-1;
		int mid;
		while(left<right){
			mid=(left+right)/2;
			if(num[mid]<num[mid-1]&&num[mid]<num[mid+1]){
				return mid;
			}
			else if(num[mid]>num[mid-1]){
				right=mid-1;
			}
			else if(num[mid]>num[mid+1]){
				left=mid+1;
			}
		}
		return -1;
	}
	void LocalMinTest(){
		int L=5;
		int num[L]={7,3,2,4,6};
		cout<<LocalMin(num, L)<<endl;
	}
	/*1.3.10 ��׺���ʽת��׺���ʽ*/
	//�ж����ȼ�

	int priority(char c1) {
		if (c1 == '*' || c1 == '/') {
			return 2;
		}
		if (c1 == '+' || c1 == '-') {
			return 1;
		}
		if (c1 == '(') {
			return 0;
		}
		else{
			return -1;
		}
	}
	void convert(string str) {
		MyStack<char> temp;
		int Len = str.length();
		int  p;
		for (int i = 0; i < Len; i++) {
			if (str[i] >= '0' && str[i] <= '9') {
				cout << str[i];
			}
			else {
				//�жϲ�����
				//���ջΪ�գ�ֱ����ջ
				if (temp.isEmpty()) {
					temp.push(str[i]);
					p = priority(str[i]);
				}//ջ�ǿգ��жϷ������ȼ�
				else {
					if (str[i] != ')') {
						//������Ƿ�����
						int k1 = priority(str[i]);
						//������ȼ��ϸ߻�����������
						if (k1 > p||k1==0) {
							temp.push(str[i]);
							p=priority(str[i]);
						}else {
							//���ȼ��ϵ�
							char c2 = temp.pop();
							//��ϸ���������׳�����һ��Ԫ�ؿ϶����㵯ջ,�����ȵ�ջ
							//whileѭ���жϣ����������Ԫ�����ȼ��ϸߣ�����������˳�
							//���ջΪ�գ��˳�
							while (k1 <= p) {
								cout << c2;
								if(temp.isEmpty()){
									break;
								}
								c2 = temp.pop();
								p = priority(c2);
							}
							//����Ϊ�գ����ջΪ�գ���Ҫ�����c2���ظ�ѹջ
							//ջ�ǿգ���ôc2�ǲ��õ�����Ԫ�أ�ѹջ
							if(!temp.isEmpty()){
								temp.push(c2);
							}
							temp.push(str[i]);//��ǰԪ��ѹջ
							p=priority(str[i]);
						}
					} else {
						//����Ƿ�����
						char c2 = temp.pop();
						p = priority(c2);
						while (p != 0) {
							cout << c2;
							c2 = temp.pop();
							p = priority(c2);
						}
						//ÿ�ε�ջ֮�󶼵��ж��Ƿ�Ϊ��
						//���ջ�ǿգ���ȡ��ǰջ��Ԫ�ص����ȼ�
						if(!temp.isEmpty()){
							c2=temp.pop();
							p = priority(c2);
							temp.push(c2);
						}
					}
				}
			}
		}

		while(!temp.isEmpty()){
			cout<<temp.pop();
		}
	}
	void convertTest(){
		string test = "(2+3)*(5-4)+2*3";
		convert(test);
	}
	/*1.2.6 �ػ���λ*/
	int CircularRotation(string s1, string s2) {
		//ԭ��s1=ABC��s2=BCA����ôs3=s2+s2=BCABCA
		//���ǻػ���λ��s3��һ������s1������s3�����Ƿ�����Ӵ�s1
		string temp = s2 + s2;
		return temp.find(s1);
	}
	void CircularRotationTest(){
		string s1="ABC",s2="BCA";
		int flag=CircularRotation(s1, s2);
		if(flag!=-1) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}

	/*1.1.27 ����ֲ�*/
	//�ݹ�Ķ���ֲ�
	/*�ݹ����壺��������Ŀ�Ƚϴ��ʱ����ܲ�����*/
	double binomial1(int N, int K, double p) {
		//����
		//count++;
		if (N == 0 && K == 0)
			return 1.0;
		if (N < 0 || K < 0)
			return 0.0;
		return (1.0 - p) * binomial1(N - 1, K, p) + p * binomial1(N - 1, K - 1, p);
	}
	//�ȵݹ���Ż���ʵ��
	double binomial2(int N, int K, double p) {
		double **A = new double*[N + 1];
		for (int i = 0; i <= N; i++) {
			A[i] = new double[K + 1];
		}
		//�Եײ�������и�ֵ
		A[0][0] = 1.0;
		for (int i = 0; i <= N; i++) {
			A[i][0] = pow(1.0 - p, i);
		}
		//C++����Ҫ��ʼ�����飬java��������Ĭ�ϳ�ʼ��Ϊ0
		for (int j = 1; j <= K; j++) {
			A[0][j] = 0.0;
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= K; j++) {
				A[i][j] = (1.0 - p) * A[i - 1][j] + p * A[i - 1][j - 1];
			}
		}
		double result = A[N][K];
		for (int i = 0; i <= N; i++) {
			delete[] A[i];
		}
		delete[] A;
		return result;
	}
	void binomialTest(){
		int N=10,K=5;
		double p=0.25;
		cout<<binomial2(N, K, p)<<endl;
	}

	/**
	 * �ҵ�����ľֲ���Сֵ/���ֵ
	 * N*N�ľ����и�Ԫ�ص�ֵ����ͬ
	 * */
	Point* MatrixMin(int **num,int L,int C){

		Point *result=new Point;
		/**
		 * �߽��ж�
		 */
		if((L==1&&C==1)){
			result->x=0;
			result->y=0;
			result->value=num[0][0];
			return result;
		}
		if((num[0][0]<num[0][1]&&num[0][0]<num[1][0])){
			result->x=0;
			result->y=0;
			result->value=num[0][0];
			return result;
		}
		if(num[L-1][C-1]<num[L-1][C-2]&&num[L-1][C-1]<num[L-2][C-1]){
			result->x=L-1;
			result->y=C-1;
			result->value=num[L-1][C-1];
			return result;
		}
		/**
		 * ��������
		 */
		int start=0,end=L-1;
		int mid,index;
		int left=0,right=C-1;
		while(start<end){
			mid=(start+end)/2;
			int min=num[mid][left];
			index=left;
			for(int i=left;i<=right;i++){
				if(num[mid][i]<min){
					min=num[mid][i];
					index=i;
				}
			}
			if(num[mid][index]<num[mid-1][index]&&
					num[mid][index]<num[mid+1][index]){
				result->x=mid;
				result->y=index;
				result->value=num[mid][index];
				return result;
			}
			else if(num[mid][index]>num[mid-1][index]){
				end=mid-1;
				right=index-1;
			}
			else if(num[mid][index]>num[mid+1][index]){
				start=mid+1;
				left=index+1;
			}
		}
		return result;
	}
	//���ɶ�ά����
	int** Matrix(int row,int column){
		int** num=new int*[row];
		for(int i=0;i<row;i++){
			num[i]=new int[column];
		}
		for(int i=0;i<row;i++){
				for(int j=0;j<column;j++){
						cin>>num[i][j];
				}
		}
		return num;
	}
	void MatrixMinTest(){
		static int L=4,C=4;
		int **num=Matrix(L, C);
		//num:5 2 3 4 1 6 7 10 9 8 11 14 13 12 15 16
		Point *result=MatrixMin(num,L,C);
		cout<<result->x<<","<<result->y<<":"<<result->value<<endl;
	}
	/**
	 * 1.4.20 ˫������
	 * ���ܣ���һ����������������в���ĳ��ֵ
	 * ���������飬���鳤�ȣ�������Ԫ��
	 */
	int halfSearch1(int num[],int left,int right,int k){
		//������ֲ���
		int mid;
		while(left<=right){
			mid=(left+right)/2;
			if(num[mid]==k){
				return mid;
			}
			else if(num[mid]>k){
				right=mid-1;
			}
			else{
				left=mid+1;
			}
		}
		return -1;
	}
	int halfSearch2(int num[],int left,int right,int k){
		//������ֲ���
		int mid;
		while(left<=right){
			mid=(left+right)/2;
			if(num[mid]==k){
				return mid;
			}
			else if(num[mid]>k){
				left=mid+1;
			}
			else{
				right=mid-1;
			}
		}
		return -1;
	}
	//�����黮��Ϊ�������к͵ݼ����У����˷ֱ���ж��ֲ���
	int BitonicSearch(int a[],int Len,int k){
		int index;
		int left=0,right=Len-1;
		int  mid;
		//ʹ�ö��ֲ������ҵ����ֵ
		while(left<=right){
			mid=(left+right)/2;
			if(a[mid]>a[mid-1]&&a[mid]>a[mid+1]){
				break;
			}
			else if(a[mid]<a[mid+1]){
				left=mid+1;
			}
			else if(a[mid]>a[mid+1]){
				right=mid-1;
			}
		}
		left=0;
		right=Len-1;
		index=halfSearch1(a, left,mid, k);
		if(index==-1){
			index=halfSearch2(a,mid+1, right, k);
		}
		return index;
	}
	void BitonicSearchTest(){
		int Len=20,k=22;
		int a[Len]={22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3};
		//num:1,3,5,7,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4
		cout<<BitonicSearch(a, Len, k)<<endl;
	}
	//�����������ʱ��
	void RunTime(){
		clock_t startTime, endTime;
		startTime = clock();
		//ִ�к�������
		Algs4Chapter1 Algs;
		Algs.MatrixMinTest();
		//ִ�к���
		endTime = clock();
		cout << "Totle Time : " << (double) (endTime - startTime) / CLOCKS_PER_SEC
				<< "s" << endl;
	}
};
/*
int main(){
	Algs4Chapter1 Algs;
	Algs.convertTest();
	return 1;
}
*/
