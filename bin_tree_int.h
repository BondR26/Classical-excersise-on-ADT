#pragma once
class ARR
{
private:
	int* arr;
	int size;
public:
	ARR(int sz);

	int operator[](int i);

	void fill_rand();

	void sort();

	bool find_bin_way(int num);


	void show();
};