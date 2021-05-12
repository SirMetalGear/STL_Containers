#include <iostream>

const int nmax = 1000;

void Merg(int arr[], int begin, int end) 
{
	int i = begin;
	int	t = 0;
	int	mid = begin + (end - begin) / 2;
	int	j = mid + 1;
	int	d[nmax];

	while (i <= mid && j <= end) {
		if (arr[i] <= arr[j]) { 
			d[t] = arr[i];
			i++; 
		}
		else { 
			d[t] = arr[j];
			j++;
		}
		t++;
	}
	while (i <= mid) {
		d[t] = arr[i];
		i++;
		t++;
	}

	while (j <= end) {
		d[t] = arr[j];
		j++;
		t++;
	}
	for (i = 0; i < t; i++)
		arr[begin + i] = d[i];
}

void MergSort(int *arr, int left, int right)
{
	int	temp;
	if (left < right)
	{
		if (right - left == 1)	{
			if (arr[right]<arr[left])	{
				temp = arr[left]; 
				arr[left] = arr[right]; 
				arr[right] = temp;
			}
		}
		else {
			MergSort(arr, left, left + (right - left) / 2); 
			MergSort(arr, left + (right - left) / 2 + 1, right);
			Merg(arr, left, right);
		}
	}
}

void input(int *m, int &n)		
{									
	std::cout << "insert mzfk ";
	std::cin >> n;
	for (int i = 0; i<n; i++)
	{
		std::cout << "a[" << i << "]=";
		std::cin >> m[i];				
	}
}

void print(int *m, int n)
{
	for (int i = 0; i<n; i++)
		std::cout << m[i] << " ";
	std::cout << "\n";
}

int main()
{
	int n;
	int a[nmax];
	input(a, n);
	std::cout << "mzfk array:\n";
	print(a, n);
	MergSort(a, 0, n - 1);
	std::cout << "not mzfk array:\n";
	print(a, n);
	return (0);
}
