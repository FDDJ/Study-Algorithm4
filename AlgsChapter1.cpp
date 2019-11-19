/*
 * SuanFa.cpp
 *
 *  Created on: 2019年11月13日
 *      Author: 31907
 */

#include<iostream>
#include<time.h>
#include<math.h>
#include<string>

using namespace std;
/**
 * 栈的设计
 * 使用链表实现栈
 * */
//链表节点
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
//创建栈
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
 * 习题1.4.19-矩阵的局部最小值
 * 矩阵坐标
 */
typedef struct point{
	int x;
	int y;
	int value;
}Point;
/*
 * 算法第1章的习题解答类
 * */
class Algs4Chapter1{
public:

public:
	Algs4Chapter1(){}
	~Algs4Chapter1(){}
	/*1.4.18 数组的局部最小元素*/
	//数组中含有N个互不相同的整数
	//一定存在最小值，故一定存在局部最小元素
	int LocalMin(int num[ ],int L){
		if(L==0)
			return -1;
		if(L==1||num[0]<num[1]){
			return 0;
		}
		if(num[L-1]<num[L-2])
			return L-1;
		//二分查找，
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
	/*1.3.10 中缀表达式转后缀表达式*/
	//判断优先级

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
				//判断操作数
				//如果栈为空，直接入栈
				if (temp.isEmpty()) {
					temp.push(str[i]);
					p = priority(str[i]);
				}//栈非空，判断符号优先级
				else {
					if (str[i] != ')') {
						//如果不是反括号
						int k1 = priority(str[i]);
						//如果优先级较高或者是正括号
						if (k1 > p||k1==0) {
							temp.push(str[i]);
							p=priority(str[i]);
						}else {
							//优先级较低
							char c2 = temp.pop();
							//仔细，这里容易出错，第一个元素肯定满足弹栈,所以先弹栈
							//while循环判断，如果弹出的元素优先级较高，输出，否则退出
							//如果栈为空，退出
							while (k1 <= p) {
								cout << c2;
								if(temp.isEmpty()){
									break;
								}
								c2 = temp.pop();
								p = priority(c2);
							}
							//不能为空，如果栈为空，需要输出的c2被重复压栈
							//栈非空，那么c2是不该弹出的元素，压栈
							if(!temp.isEmpty()){
								temp.push(c2);
							}
							temp.push(str[i]);//当前元素压栈
							p=priority(str[i]);
						}
					} else {
						//如果是反括号
						char c2 = temp.pop();
						p = priority(c2);
						while (p != 0) {
							cout << c2;
							c2 = temp.pop();
							p = priority(c2);
						}
						//每次弹栈之后都得判断是否为空
						//如果栈非空，获取当前栈顶元素的优先级
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
	/*1.2.6 回环变位*/
	int CircularRotation(string s1, string s2) {
		//原理：s1=ABC，s2=BCA，那么s3=s2+s2=BCABCA
		//若是回环变位，s3中一定包含s1，即在s3中找是否存在子串s1
		string temp = s2 + s2;
		return temp.find(s1);
	}
	void CircularRotationTest(){
		string s1="ABC",s2="BCA";
		int flag=CircularRotation(s1, s2);
		if(flag!=-1) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}

	/*1.1.27 二项分布*/
	//递归的二项分布
	/*递归陷阱：当迭代数目比较大的时候就跑不出来*/
	double binomial1(int N, int K, double p) {
		//计数
		//count++;
		if (N == 0 && K == 0)
			return 1.0;
		if (N < 0 || K < 0)
			return 0.0;
		return (1.0 - p) * binomial1(N - 1, K, p) + p * binomial1(N - 1, K - 1, p);
	}
	//比递归更优化的实现
	double binomial2(int N, int K, double p) {
		double **A = new double*[N + 1];
		for (int i = 0; i <= N; i++) {
			A[i] = new double[K + 1];
		}
		//对底层迭代进行赋值
		A[0][0] = 1.0;
		for (int i = 0; i <= N; i++) {
			A[i][0] = pow(1.0 - p, i);
		}
		//C++中需要初始化数组，java中声明就默认初始化为0
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
	 * 找到矩阵的局部最小值/最大值
	 * N*N的矩阵中各元素的值不相同
	 * */
	Point* MatrixMin(int **num,int L,int C){

		Point *result=new Point;
		/**
		 * 边界判断
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
		 * 二分搜索
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
	//生成二维数组
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
	 * 1.4.20 双调查找
	 * 功能：在一个先增后减的数组中查找某个值
	 * 参数：数组，数组长度，待查找元素
	 */
	int halfSearch1(int num[],int left,int right,int k){
		//升序二分查找
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
		//降序二分查找
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
	//将数组划分为递增序列和递减序列，两端分别进行二分查找
	int BitonicSearch(int a[],int Len,int k){
		int index;
		int left=0,right=Len-1;
		int  mid;
		//使用二分查找先找到最大值
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
	//输出程序运行时间
	void RunTime(){
		clock_t startTime, endTime;
		startTime = clock();
		//执行函数主体
		Algs4Chapter1 Algs;
		Algs.MatrixMinTest();
		//执行函数
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
