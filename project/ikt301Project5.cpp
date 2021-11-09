
#include <iostream>
#include <matplotlibcpp.h>
#include <cmath>
namespace plt = matplotlibcpp;
using namespace std;


void createMaxHeap(int* keys, int heapSize, int parentIdx, int &operations) {

	int i = parentIdx;
	int left = i * 2 + 1;
	int right = i * 2 + 2;

	if (left < heapSize && keys[i] < keys[left]) {
		operations++;
		i = left;
	}

	if (right < heapSize && keys[i] < keys[right]) {
		i = right;
		operations++;
	}
	//operations += 2;
	if (i != parentIdx) {
		int tmp = keys[parentIdx];
		keys[parentIdx] = keys[i];
		keys[i] = tmp;
		createMaxHeap(keys, heapSize, i, operations);
	}
}

void heapSort(int* heap, int n, int &operations) {

	int index = n - 1;


	for (int i = n/2-1; i >= 0; i--)
	{
		createMaxHeap(heap, n, i, operations);
	}


	while (index > 0) {
		operations += 1;
		int tmp = heap[0];
		heap[0] = heap[index];
		heap[index] = tmp;
		createMaxHeap(heap, index, 0, operations);
		index--;
		
	}
}


void randomizeArray(int arr[], int size) {
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % 1000;
	}
}


int getNrOfOperations(int size){
	int* arr = new int[size];
	randomizeArray(arr, size);
	/*
	
	
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = i;
	}
	*/
	int operations = 0;
	heapSort(arr, size, operations);
	return operations;
}


int main()
{

	vector<int> x, y , z, w;


	for (size_t i = 0; i < 10000; i++)
	{
		z.push_back(2 * i * log(i));
		w.push_back(i*log(i)-1.45*i);
		x.push_back(i);
		y.push_back(getNrOfOperations(i));
	}

	cout << getNrOfOperations(10000) << endl;
	cout << z[z.size() - 1] << endl;
	cout << 268523. / 184186. << endl;

	plt::plot(x, y);
	plt::plot(x, z);
	plt::plot(x, w);
	plt::ylim(0, 250000);
	plt::show();

	return 0;

}




