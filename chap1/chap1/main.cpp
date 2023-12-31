#include <iostream>
#include <vector>
using namespace std;

// 以下数组下标从0开始

// 1.1 线性查找
int linearSearch(vector<int>& a, int x) {
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] == x) {
			return i;
		}
	}
	return 0;
}

// 1.2 二分查找，与书上的算法有些差异
int binarySearch(vector<int>& a, int x) {
	int l = 0, r = a.size()-1;
	while (l < r) {
		int mid = (l + r) / 2;
		if (a[mid] < x) {
			l = mid + 1;
		}
		else {
			r = mid;
		}
	}
	if (a[l] == x) {
		return l;
	}
	return 0;
}

// 1.3 合并两个已经有序的表（按书上的输入和输出，可用于归并排序）
// a[p, q]和a[q+1, r]已经有序
void merge(vector<int>& a, int p, int q, int r) {
 	int i = p, j = q + 1, len = r - p + 1, k = 0;
	vector<int> tmp(len);
	while (i <= q && j <= r) {
		if (a[i] < a[j]) {
			tmp[k++] = a[i++];
		}
		else {
			tmp[k++] = a[j++];
		}
	}
	while (i <= q) {
		tmp[k++] = a[i++];
	}
	while (j <= r) {
		tmp[k++] = a[j++];
	}
	for (int i = 0; i < len; ++i) {
		a[p + i] = tmp[i];
	}
}

// 1.4 选择排序
void selectionSort(vector<int>& a) {
	for (int i = 0; i < a.size(); ++i) {
		int p = i;
		for (int j = i + 1; j < a.size(); ++j) {
			p = a[j] < a[p] ? j : p;
		}
		if (i != p) {
			int tmp = a[p];
			a[p] = a[i];
			a[i] = tmp;
		}
	}
}

// 1.5 插入排序
void insertionSort(vector<int>& a) {
	for (int i = 1; i < a.size(); ++i) {
		int p = i;
		while (p > 0 && a[p-1] > a[p]) {
			int tmp = a[p];
			a[p] = a[p - 1];
			a[p - 1] = a[tmp];
			p--;
		}
	}
}

// 1.6 自底向上归并排序（使用递推，与书上不同）
void bottomupSort(vector<int>& a, int l, int r);
void bottomupSort(vector<int>& a) {
	bottomupSort(a, 0, a.size()-1);
}
void bottomupSort(vector<int>& a, int l, int r) {
	if (l >= r) return;
	int mid = (l + r) / 2;
	bottomupSort(a, l, mid);
	bottomupSort(a, mid + 1, r);
	merge(a, l, mid, r);
}

// 1.6 自底向上归并排序（使用递推，使用书上算法）
void bottomupSort1(vector<int>& a) {
	int t = 1, n = a.size();
	while (t < n) {
		for (int i = 0; i < n; i += 2 * t) {
			if (i + t >= n) break;
			merge(a, i, i + t - 1, min(i + 2 * t - 1, n-1));
		}
		t <<= 1;
	}
}

// 1.7 暴力进行素数测试
bool bruteForcePrimalityTest(int n) {
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) return false;
	}
	return true;
}

// 1.8 count1, n为2的整数次幂
int count1(int n) {
	int cnt = 0;
	while (n >= 1) {
		for (int j = 0;j < n;++j) {
			cnt++;
		}
		n >>= 1;
	}
	return cnt;
}

// 1.9 count2 
int count2(int n) {
	int cnt = 0;
	for (int i = 0;i < n;++i) {
		for (int j = 0;j < n / (i + 1);++j) {
			cnt++;
		}
	}
	return cnt;
}

// 1.10 count3，n=2^(2^k)
int count3(int n) {
	int cnt = 0;
	for (int i = 1; i <= n;++i) {
		int j = 2;
		while (j <= n) {
			j = j * j;
			cnt++;
		}
	}
	return cnt;
}

// 1.11 PSUM n为1个完全平方数
vector<int> psum(int n) {
	vector<int> sum;
	for (int j = 1; j * j <= n; ++j) {
		sum.push_back(0);
		for (int i = 1; i <= j * j;++i) {
			sum[j - 1] += i;
		}
	}
	return sum;
}

// 1.12 修改后的插入排序，查找过程改为二分查找
void modInsertionSort(vector<int>& a) {
	for (int i = 1; i < a.size(); ++i) {
		int l = 0, r = i;
		// 寻找第一个大于当前位置值的下标
		while (l < r) {
			int mid = (l + r) >> 1;
			if (a[mid] <= a[i]) {
				l = mid + 1;
			}
			else {
				r = mid;
			}
		}
		int tmp = a[i], p = i;
		while (p > l) {
			a[p] = a[p - 1];
			p--;
		}
		a[p] = tmp;
	}
}

// 1.13 first
int first(vector<int>& a) {
	int sum = 0;
	for (int i = 0;i < a.size();++i) {
		sum += a[i];
	}
	return sum;
}

// 1.14 second
int second(int n) {
	int sum = 0;
	for (int i = 0;i < n;++i) {
		sum += i;
	}
	return sum;
}

int main() {
	vector<int> a = { 3, 5,1,7,8,5,3,0,5 };
	modInsertionSort(a);
	for (auto e : a) {
		cout << e << " ";
	}
	cout << endl;
	
	return 0;
}