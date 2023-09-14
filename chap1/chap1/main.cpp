#include <iostream>
#include <vector>
using namespace std;

// ���������±��0��ʼ

// 1.1 ���Բ���
int linearSearch(vector<int>& a, int x) {
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] == x) {
			return i;
		}
	}
	return 0;
}

// 1.2 ���ֲ��ң������ϵ��㷨��Щ����
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

// 1.3 �ϲ������Ѿ�����ı������ϵ����������������ڹ鲢����
// a[p, q]��a[q+1, r]�Ѿ�����
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

// 1.4 ѡ������
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

// 1.5 ��������
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

// 1.6 �Ե����Ϲ鲢����ʹ�õ��ƣ������ϲ�ͬ��
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

// 1.6 �Ե����Ϲ鲢����ʹ�õ��ƣ�ʹ�������㷨��
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

// 1.7 ����������������
bool bruteForcePrimalityTest(int n) {
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {
	vector<int> a = { 3, 5,1,7,8,5,3,0,5 };
	bottomupSort1(a);
	for (auto e : a) {
		cout << e << " ";
	}
	cout << endl;
	
	return 0;
}