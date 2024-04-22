#include <iostream>
#include "Array.h"
using namespace std;


void menu() {

	cout << "1 - Show arr\t\t8 - Get at\n";
	cout << "2 - Get size\t\t9 - Set at\n";
	cout << "3 - Set size\t\t10 - Add\n";
	cout << "4 - Get last index\t11 - Append\n";
	cout << "5 - Is empty?\t\t12 - Get data\n";
	cout << "6 - Free extra mem\t13 - Insert at\n";
	cout << "7 - Remove all\t\t14 - Remove at\n";
	cout << "\n============\n";
	cout << "Enter choice: ";
}



int main() {
	
	srand(time(0));

	int size = 5;

	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 10 + 1;
	}

	Array<int> arr1(size, arr);

	int* arr2 = new int[size];
	for (int i = 0; i < size; i++) {
		arr2[i] = rand() % 10 + 1;
	}
	 
	Array<int> arr3(size, arr2);

	int choice;

	int sizeForGet;
	int sizeForSet;

	int lastIndex;
	bool isEmpt;

	int getAtIndex;
	int setAtIndex;
	int valGetAt;
	int valSetAt;

	int addValue;
	int* getData;
	int insertIndex;
	int insertValue;
	int removeIndex;

	do {

		menu();
		cin >> choice;

		switch (choice)
		{
		case 1:
			arr1.showArr();

			break;
		case 2:
			sizeForGet = arr1.getSize();
			cout << "Current size :" << sizeForGet << endl;
			break;
		case 3:
			cout << "Enter new size: ";
			cin >> sizeForSet;
			arr1.setSize(sizeForSet);
			
			break;
		case 4:
			lastIndex = arr1.getUpperBound();
			cout << "Current last index: " << lastIndex << endl;
			break;
		case 5:
			isEmpt = arr1.isEmpty();
			if (isEmpt == false) {
				cout << "Array is filled" << endl;
			}
			else {
				cout << "Array is empty" << endl;
			}
			break;
		case 6:
			arr1.freeExtra();
			cout << "Extra memory delete\n";
			break;
		case 7:
			arr1.removeAll();
			cout << "\nAll elements removed\n";
			break;
		case 8:
			cout << "Enter index: ";
			cin >> getAtIndex;
			
			valGetAt = arr1.getAt(getAtIndex);
			cout << "Searched value: " << valGetAt << endl;
			break;
		case 9:
			cout << "Enter index: ";
			cin >> setAtIndex;
			cout << "Enter value: ";
			cin >> valSetAt;
			arr1.setAt(valSetAt, setAtIndex);
			cout << "Done!";
			break;
		case 10:
			cout << "Enter value: ";
			cin >> addValue;
			arr1.addEl(addValue);
			cout << "Element added\n";
			break;
		case 11:
			arr1.append(arr3);

			break;
		case 12:
			getData = arr1.getData();
			cout << "Current addres: " << getData << endl;
			break;
		case 13:
			cout << "Enter value: ";
			cin >> insertValue;
			cout << "Enter index: ";
			cin >> insertIndex;
			arr1.insertAt(insertValue, insertIndex);
			break;
		case 14:
			cout << "Enter remove index: ";
			cin >> removeIndex;
			arr1.removeAt(removeIndex);
			break;
		
		default:
			break;
		}
	} while (choice != 0);

	return 0;
}