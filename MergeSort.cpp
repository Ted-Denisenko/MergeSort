#include <iostream>

#define ARRAY_SIZE 4

// ���������� ��������:
/*
* ���� 1: ������� �� ����������
��������� ������ ������ �� ����������, ���� � ������� �� ��������� 1 �������
* ���� 2: ���������� � �������
����� ��� ������� � ����, �����������
�������� ����� �������� 2�� ��������, ������� �������� � ����� ������,
���������� ������� 1�� ������� �������� � ����� ����� ��������� 2�� �������
���������, ���� �� �������� �������� � ��������
*/

void MergeSort(int a[], int size)
{
	// ���� ������ ������� �� 1 ��������, ������������
	if (size < 2) return;
	// ��������� ����� ����� (�� ������ ������� �� ��������)
	MergeSort(a, size / 2); 
	// ������ ���������� (���������� �������� �������)
	MergeSort(&a[size / 2], size - size / 2);
	// ������� ���������� ������ ��� ���������� ������������� ��������
	int* buf = new int[size];
	// ������ ������ ���. �������, ������ ����� � ������ ������� �������-���������
	int idbuf{ 0 }, idleft{ 0 }, idright{ size / 2 };

	// ���������� �� �����������: ������������ ��������� �������� ���� �������, � ����� ������ ������� ��������
		while ((idleft < size / 2) && (idright < size)) // ���� � ����� ��������� ���� �������� ��� ���������
		if (a[idleft] > a[idright])
			buf[idbuf++] = a[idright++];
		else
			buf[idbuf++] = a[idleft++];
	// ���������� ���������� �������� 
	while (idleft < size / 2)
		buf[idbuf++] = a[idleft++];
	while (idright<size)
		buf[idbuf++] = a[idright++];
	// ������������ �������� �� ������� ������� � ������-��������
	for (idleft = 0; idleft < size; idleft++)
		a[idleft] = buf[idleft];
	delete[] buf;
}

int main()
{
	int array[ARRAY_SIZE] = {16,24,60,15};
	for (int i = 0; i < ARRAY_SIZE; i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
	MergeSort(array, ARRAY_SIZE);
	for (int i = 0; i < ARRAY_SIZE; i++)
		std::cout << array[i] << " ";
}