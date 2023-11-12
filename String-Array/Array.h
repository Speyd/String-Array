#include <iostream>
#include <cassert>
using namespace std;

class Array {
private:
	double* num;
	int amountNum;

	void ChangeDoubleArray(double*& array, const double* arrayP, const int size) {

		if (arrayP != nullptr) {

			delete[]array;
			array = new double[size];
			for (int i = 0; i != size; i++)if(!isnan(arrayP[i]))array[i] = arrayP[i];

		}
		else array = nullptr;
	}

public:

	Array(const double* numP, const int amountNumP) :num{ nullptr }, amountNum{ amountNumP } {

		ChangeDoubleArray(num, numP, amountNumP);

	}

	Array():Array{nullptr,0}{}

	Array(const Array& array) = delete;

	Array(Array&& array) :num{ array.num }, amountNum{ array.amountNum } {
	
		array.num = nullptr;
		array.amountNum = 0;

	}

	int GetAmountNum()const { return amountNum; }


	double& operator[](int index)
	{
		assert((index >= 0 && index < amountNum) and "Index out of range!");
		return num[index];
	}
	double operator[](int index)const
	{
		assert((index >= 0 && index < amountNum) and "Index out of range!");
		return num[index];
	}

	friend istream& operator>>(istream& input, Array& array) {
		double* tempNum{ nullptr };
		array.ChangeDoubleArray(tempNum, array.num, array.amountNum);
		array.ChangeDoubleArray(array.num, tempNum, ++array.amountNum);

		cout << "Enter new number: ";
		input >> array[array.amountNum - 1];

		return input;
	}

	

};