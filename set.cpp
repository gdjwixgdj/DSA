/*
	Name : Madhur Chandratre

	Roll no : 18

	Title :	To create ADT that implement the "set" concept.
			a. Add (new Element) -Place a value into the set , 
			b. Remove (element) Remove the value
			c. Contains (element) Return true if element is in collection, 
			d. Size () Return number of values in collection 
			   Iterator () Return an iterator used to loop over collection, 
			e. Intersection of two sets , 
			f. Union of two sets, 
			g. Difference between two sets,
			h. Subset

*/
#include <iostream>
using namespace std;

class Set
{
		int arr[20], count;
	public:
		Set()
		{
			count = 0;
		}
		void size()
		{
			cout << "Total Elements : " << count << endl;
		}
		void addElement()
		{
			int key;
			cout << "Enter element to Add : ";
			cin >> key;
			arr[count++] = key;
		}
		void display()
		{
			cout << "Set Elements" << endl;
			for(int i = 0; i < count; i++)
				cout << arr[i] << " ";
			cout << endl;
		}
		int search(int key)
		{
			for(int i = 0; i < count; i++)
				if(key == arr[i])
					return i;
			return -1;
		}
		void remove()
		{
			int key;
			cout << "Enter element to be deleted : ";
			cin >> key;
			int index = search(key);
			if(index != -1)
			{
				for(int i = index; i < count - 1; i++)
					arr[i] = arr[i+1];
				count--;
				cout << key << " deleted successfully" << endl;
				return;
			}
			cout << "Element Not Found" << endl;
		}
		void intersection(Set B)
		{
			cout << "Intersection of sets" << endl;
			for(int i = 0; i < this->count; i++)
				if(this->search(this->arr[i]) != -1 && B.search(this->arr[i]) != -1)
					cout << arr[i] << " ";
			cout << endl;
		} //A: 1 2 3 4 5 6 	B :  4 5 6
		
		void unionSet(Set B)
		{
			cout << "Union of sets" << endl;
			for(int i = 0; i < count; i++)
				cout << arr[i] << " ";
			for(int i = 0; i < B.count; i++)
				if(this->search(B.arr[i]) == -1)
					cout << B.arr[i] << " ";
			cout << endl;
		}
		void difference(Set B)
		{ //
			cout << "Difference of sets" << endl;
			for(int i = 0; i < this->count; i++) // for A : 1 2 3 4 5 6
				if(B.search(arr[i]) == -1)
					cout << arr[i] << " ";
			for (int i = 0; i < B.count; i++) // for B
				if(this->search(B.arr[i]) == -1)
					cout << B.arr[i] << " ";
			cout << endl;
		}
		void subset(Set B) // 1 2 3 4 5 6   B: 4 5 6 7
		{
			for(int i = 0; i < B.count; i++)
				if(this->search(B.arr[i]) == -1)
				{
					cout << "No Subsets present" << endl;
					return;
				}
			cout << "Subset is present" << endl;
		}
};
int main()
{
	Set A, B;
	int choice, key, num;
	bool flag = true;

	while(flag)
	{
		cout << "*************MENU*************" << endl;
		cout << "1. Add Element" << endl;
		cout << "2. Remove Element" << endl;
		cout << "3. Search" << endl;
		cout << "4. Size of Set" << endl;
		cout << "5. Intersection" << endl;
		cout << "6. Union" << endl;
		cout << "7. Difference" << endl;
		cout << "8. Subset" << endl;
		cout << "9. Display" << endl;
		cout << "10. Exit" << endl;
		cout << "Enter your choice : ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				cout << "Choose Set" << endl;
				cout << "1. A\n2. B" << endl;
				cout << "Enter your choice : ";
				cin >> choice;
				switch(choice)
				{
					case 1:
						A.addElement();
						break;
					case 2:
						B.addElement();
						break;
					default:
						cout << "Invalid Choice" << endl;
				}
				break;
			case 2:
				cout << "Choose Set" << endl;
				cout << "1. A\n2. B" << endl;
				cout << "Enter your choice : ";
				cin >> choice;
				switch(choice)
				{
					case 1:
						A.remove();
						break;
					case 2:
						B.remove();
						break;
					default:
						cout << "Invalid Choice" << endl;
				}
				break;
			case 3:
				int key;
				cout << "Enter element to be searched : ";
				cin >> key;
				cout << "Choose Set" << endl;
				cout << "1. A\n2. B" << endl;
				cout << "Enter your choice : ";
				cin >> choice;
				switch(choice)
				{
					case 1:
						num = A.search(key);
						break;
					case 2:
						num = B.search(key);
						break;
					default:
						cout << "Invalid Choice" << endl;
				}
				if(num != -1)
					cout << key << " found at index " << num << endl;
				else
					cout << key << " not found" << endl;
				break;
			case 4:
				cout << "Choose Set" << endl;
				cout << "1. A\n2. B" << endl;
				cout << "Enter your choice : ";
				cin >> choice;
				switch(choice)
				{
					case 1:
						A.size();
						break;
					case 2:
						B.size();
						break;
					default:
						cout << "Invalid Choice" << endl;
				}
				break;
			case 5:
				A.intersection(B);
				break;
			case 6:
				A.unionSet(B);
				break;
			case 7:
				A.difference(B);
				break;
			case 8:
				A.subset(B);
				break;
			case 9:
				cout << "Choose Set" << endl;
				cout << "1. A\n2. B" << endl;
				cout << "Enter your choice : ";
				cin >> choice;
				switch(choice)
				{
					case 1:
						A.display();
						break;
					case 2:
						B.display();
						break;
					default:
						cout << "Invalid Choice" << endl;
				}
				break;
			case 10:
				cout << "End of Program" << endl;
				flag = false;
				break;
			default:
				cout << "Invalid Choice" << endl;	
		}
	}
	return 0;
}
