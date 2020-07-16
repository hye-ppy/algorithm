#include<stdio.h>
#include <iostream>
#include <vector>
using namespace std;
#pragma warning(disable:4996);
vector<int> arr;
vector<int> temp;
long long int inv;
void merge(int low, int high, int mid);
void mergesort(int low, int high);
int main()
{
	FILE *input, *output;
	input = fopen("inv.inp", "rt");
	output = fopen("inv.out", "wt");

	int t, n, a;
	fscanf(input, "%d", &t);
	for (int x = 0; x < t; x++) {
		fscanf(input, "%d", &n);
		arr.clear(); arr.resize(n);
		temp.clear(); temp.resize(n);
		for (int y = 0; y < n; y++) {
			fscanf(input, "%d", &arr[y]);
		}
		inv = 0;
		mergesort(0, n - 1);
		fprintf(output, "%lld\n", inv);
	}
	fclose(input);
	fclose(output);
}
void mergesort(int low, int high) {
	int mid;
	if (low < high) {
		mid = (low + high) / 2;
		mergesort(low, mid);
		mergesort(mid + 1, high);
		merge(low, high, mid);
	}
	return;
}
void merge(int low, int high, int mid) {
	int i, j, k;
	i = low;
	j = mid + 1;
	k = low;
	while (i <= mid && j <= high) {
		if (arr[i] < arr[j]) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];
			inv += (long long int)mid - (long long int)i + 1;
		}
	}
	if (i > mid) {
		while (j <= high) {
			temp[k++] = arr[j++];
		}
	}
	else if (j > high) {
		while (i <= mid) {
			temp[k++] = arr[i++];
		}
	}
	for (i = low; i < k; i++) {
		arr[i] = temp[i];
	}
}