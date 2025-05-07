/*
         Title : Consider telephone book database of N clients. Make use of a hash table
            implementation to quickly look up client's telephone number. Make use of two collision 
            handling techniques and compare them using number of comparisons required to find a set 
            of telephone numbers.
*/

#include <iostream>
#include <iomanip>
using namespace std;

class Hashing
{
    long long* hashTable;
    int size;
    public:
        void createTable()
        {
            cout << "Enter size of Hash Table: ";
            cin >> size; // 10
            hashTable = new long long[size];
            for(int i = 0; i < size; i++)
                hashTable[i] = -1;
            cout << "Hash Table Created Successfully!" << endl;
        }
        void insertNumber()
        {
            long long mobile;
            int index;
            cout << "Enter mobile number: ";
            cin >> mobile;
            index = mobile % size; 
            if(hashTable[index] == -1)
            {
                hashTable[index] = mobile;
                cout << "Number stored at index " << index << endl;
            }
            else
            {
                cout << "Collision Occured!" << endl;
                cout << "1. Linear Probing" << endl;
                cout << "2. Quadratic Probing" << endl;
                cout << "Enter your choice : ";
                int choice;
                cin >> choice;
                switch(choice)
                {
                    case 1:
                        cout << "Collision handling using Linear Probing" << endl;
                        linearProbing(mobile, index);
                        break;
                    case 2:
                        cout << "Collision handling using Quadratic Probing" << endl;
                        quadraticProbing(mobile, index);
                        break;
                    default:
                        cout << "Invalid Choice!" << endl;
                }
            }
        }
        void linearProbing(long long mobile, int index)
        {
            for(int i = (index+1)%size, count = 0; count < size; i++, count++)
            {
                if(hashTable[i] == -1)
                {
                    hashTable[i] = mobile;
                    cout << "Number stored at index " << i << " using linear probing" << endl;
                    break;
                }
                if(i == size - 1)
                    i = -1;
            }
        }
        void quadraticProbing(long long mobile, int index)
        {
            int newIndex;
            for(int i = 0; i < size; i++)
            {
                newIndex = (index + i*i)%10;
                if(hashTable[newIndex] == -1)
                {
                    hashTable[newIndex] = mobile;
                    cout << "Number stored at index " << newIndex << " using quadratic probing" << endl;
                    break;
                }
            }
        }
        void displayHashTable()
        {
            cout << "Hash Table Elements" << endl;
            for(int i = 0; i < size; i++)
            {
                std::printf("%2d. ", i+1);
                cout << hashTable[i] << endl;
            }
        }
        void search()
        {
            long long mob;
            cout << "Enter Mobile Number to search : "; 
            cin >> mob;
            for(int i = 0; i < size; i++)
            {
                if(hashTable[i] == mob)
                {
                    cout << "Found at index : " << i << endl;
                    return;
                }
            }
            cout << "Mobile Number not found" << endl;
        }
};
int main()
{
    Hashing ht;
    bool flag = true;
    while(flag)
    {
        cout << "***********Menu***********" << endl;
        cout << "1. Create Hash Table" << endl;
        cout << "2. Insert Mobile Number" << endl;
        cout << "3. Display Hash Table" << endl;
        cout << "4. Search Mobile Number" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice : ";
        int choice;
        cin >> choice;
        
        switch(choice)
        {
            case 1:
                ht.createTable();
                break;
            case 2:
                ht.insertNumber();
                break;
            case 3:
                ht.displayHashTable();
                break;
            case 4:
                ht.search();
                break;
            case 5:
                cout << "End of Program" << endl;
                flag = false;
                break;
            default:
                cout << "Invalid Choice!" << endl;
        }
    }
}
