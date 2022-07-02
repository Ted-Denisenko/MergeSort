#include <iostream>

#define ARRAY_SIZE 4

// Сортировка слиянием:
/*
* Этап 1: деление на подмассивы
начальный массив делить на подмассивы, пока в массиве не останется 1 элемент
* Этап 2: сортировка и слияние
слить два массива в один, упорядочить
сравнить левые элементы 2ух массивов, меньший записать в новый массив,
оставшийся элемент 1го массива сравнить с новым левым элементом 2го массива
повторять, пока не кончатся элементы в массивах
*/

void MergeSort(int a[], int size)
{
	// если массив состоит из 1 элемента, возвращаемся
	if (size < 2) return;
	// сортируем левую часть (от начала массива до середины)
	MergeSort(a, size / 2); 
	// правую аналогично (оставшуюся половину массива)
	MergeSort(&a[size / 2], size - size / 2);
	// создаем буферырный массив для сохранения упорядоченных значений
	int* buf = new int[size];
	// номера начала буф. массива, начала левой и правой половин массива-параметра
	int idbuf{ 0 }, idleft{ 0 }, idright{ size / 2 };

	// сортировка по возрастанию: сравниваются начальные элементы двух половин, в буфер уходит меньшее значение
		while ((idleft < size / 2) && (idright < size)) // пока в обеих половинах есть элементы для сравнения
		if (a[idleft] > a[idright])
			buf[idbuf++] = a[idright++];
		else
			buf[idbuf++] = a[idleft++];
	// записываем оставшееся значение 
	while (idleft < size / 2)
		buf[idbuf++] = a[idleft++];
	while (idright<size)
		buf[idbuf++] = a[idright++];
	// переписываем значения из буффера обратно в массив-параметр
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