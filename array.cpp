#include <iostream>
using namespace std;

// Custom Array C++ Class
template <typename T>
class MyArray
{

    // Private Attributes
private:
    int total_size;
    int used_size;
    T *base_address;

    // Public Methods
public:
    MyArray(int size)
    {
        base_address = new T[size - 1];
        total_size = size;
        used_size = 0;
    }

    // To add value by user input
    void addElementFromUser()
    {
        if (used_size < total_size)
        {
            T user;
            cout << "Enter value to array : ";
            cin >> user;
            base_address[used_size++] = user;
        }
        else
        {
            cout << "Array Size full cannot add more value!!" << endl;
        }
    }

    int totalSize()
    {
        if (total_size)
            return total_size;
        else
            return 0;
    }

    int usedSize()
    {
        if (used_size)
            return used_size;
        else
            return 0;
    }

    T maxElement()
    {
        T maxx = base_address && base_address[0] ? base_address[0] : (T)NULL;
        if (used_size && used_size > 0)
        {
            for (int i = 0; i < used_size; i++)
            {
                if (maxx < base_address[i])
                    maxx = base_address[i];
            }
        }
        return maxx;
    }

    T minElement()
    {
        T minn = base_address && base_address[0] ? base_address[0] : (T)NULL;
        if (used_size && used_size > 0)
        {
            for (int i = 0; i < used_size; i++)
            {
                if (minn > base_address[i])
                    minn = base_address[i];
            }
        }
        return minn;
    }

    T getByIndex(int i)
    {
        if (i >= 0 && i <= used_size)
        {
            return base_address[i];
        }
        return (T)NULL;
    }

    T setByIndex(T value, int i)
    {
        if (i >= 0 && i <= used_size)
        {
            base_address[i] = value;
            return value;
        }
        return (T)NULL;
    }

    void addArray(T arr[], int arrSize)
    {
        T *tempArr = base_address;
        int tempSize = used_size;
        base_address = new T[total_size + arrSize];
        total_size = total_size + arrSize;
        used_size = 0;
        for (int i = 0; i < tempSize; i++)
        {
            base_address[used_size++] = tempArr[i];
        }
        for (int i = 0; i < arrSize; i++)
        {
            base_address[used_size++] = arr[i];
        }
        delete[] tempArr;
    }

    void print()
    {
        for (int i = 0; i < used_size; i++)
        {
            cout << base_address[i] << " ";
        }
        cout << endl;
    }

    T insertElement(int num)
    {
        return insertElement(num, used_size);
    }

    T insertElement(T value, int i)
    {
        if (i >= 0 && i <= used_size && used_size < total_size)
        {
            for (int j = used_size + 1; j > i; j--)
            {
                base_address[j] = base_address[j - 1];
            }
            base_address[i] = value;
            used_size++;
            return value;
        }
        return (T)NULL;
    }

    T deleteElement()
    {
        return deleteElement(used_size - 1);
    }

    T deleteElement(int i)
    {
        if (i >= 0 && i <= used_size)
        {
            T del = base_address[i];
            for (int j = i; j < used_size; j++)
            {
                base_address[j] = base_address[j + 1];
            }
            used_size--;
            return del;
        }
        return (T)NULL;
    }
};

int main()
{

    cout << "Integer";
    cout << endl;
    cout << endl;

    MyArray<int> arr(5);
    int arr1[] = {1, 2, 3, 4, 5, 6};
    int arrSize = sizeof(arr1) / sizeof(arr1[0]);
    arr.addArray(arr1, arrSize);
    cout << "Total Size : " << arr.totalSize() << endl;
    cout << "Used Size : " << arr.usedSize() << endl;
    arr.addArray(arr1, arrSize);
    cout << "Total Size : " << arr.totalSize() << endl;
    cout << "Used Size : " << arr.usedSize() << endl;
    arr.print();
    cout << "Insert Element : " << arr.insertElement(100, 0) << endl;
    cout << "Insert Element : " << arr.insertElement(100, 17) << endl;
    cout << "Insert Element : " << arr.insertElement(101) << endl;
    arr.addElementFromUser();
    arr.addElementFromUser();
    arr.addElementFromUser();
    arr.addElementFromUser();
    arr.addElementFromUser();
    arr.addElementFromUser();
    arr.print();
    cout << "Total Size : " << arr.totalSize() << endl;
    cout << "Used Size : " << arr.usedSize() << endl;
    cout << "Max Element : " << arr.maxElement() << endl;
    cout << "Set Success : " << arr.setByIndex(25, 5) << endl;
    cout << "Set Success : " << arr.setByIndex(324, 19) << endl;
    cout << "Get 4th Element : " << arr.getByIndex(4) << endl;
    cout << "Get 15th Element : " << arr.getByIndex(15) << endl;
    arr.print();
    cout << "Delete Element : " << arr.deleteElement(2) << endl;
    cout << "Delete Element : " << arr.deleteElement(12) << endl;
    cout << "Delete Element : " << arr.deleteElement(17) << endl;
    cout << "Delete Element : " << arr.deleteElement(7) << endl;
    cout << "Delete Element : " << arr.deleteElement() << endl;
    cout << "Total Size : " << arr.totalSize() << endl;
    cout << "Used Size : " << arr.usedSize() << endl;
    cout << "Min Element : " << arr.minElement() << endl;
    arr.print();

    cout << endl;
    cout << endl;
    cout << "CHAR";
    cout << endl;
    cout << endl;

    MyArray<char> arr2(5);
    char arr3[] = {'a', 'b', 'c', 'd', 'e'};
    arrSize = sizeof(arr3) / sizeof(arr3[0]);
    arr2.addArray(arr3, arrSize);
    cout << "Total Size : " << arr2.totalSize() << endl;
    cout << "Used Size : " << arr2.usedSize() << endl;
    arr2.addArray(arr3, arrSize);
    cout << "Total Size : " << arr2.totalSize() << endl;
    cout << "Used Size : " << arr2.usedSize() << endl;
    arr2.print();
    cout << "Insert Element : " << arr2.insertElement('y', 0) << endl;
    cout << "Insert Element : " << arr2.insertElement('r', 17) << endl;
    cout << "Insert Element : " << arr2.insertElement('o') << endl;
    cout << "Total Size : " << arr2.totalSize() << endl;
    cout << "Used Size : " << arr2.usedSize() << endl;
    arr2.addElementFromUser();
    arr2.addElementFromUser();
    arr2.addElementFromUser();
    arr2.addElementFromUser();
    arr2.addElementFromUser();
    arr2.addElementFromUser();
    arr2.print();
    cout << "Total Size : " << arr2.totalSize() << endl;
    cout << "Used Size : " << arr2.usedSize() << endl;
    cout << "Max Element : " << arr2.maxElement() << endl;
    cout << "Set Success : " << arr2.setByIndex('n', 5) << endl;
    cout << "Set Success : " << arr2.setByIndex('r', 19) << endl;
    cout << "Get 4th Element : " << arr2.getByIndex(4) << endl;
    cout << "Get 15th Element : " << arr2.getByIndex(15) << endl;
    arr2.print();
    cout << "Delete Element : " << arr2.deleteElement(2) << endl;
    cout << "Delete Element : " << arr2.deleteElement(12) << endl;
    cout << "Delete Element : " << arr2.deleteElement(17) << endl;
    cout << "Delete Element : " << arr2.deleteElement(7) << endl;
    cout << "Delete Element : " << arr2.deleteElement() << endl;
    cout << "Total Size : " << arr2.totalSize() << endl;
    cout << "Used Size : " << arr2.usedSize() << endl;
    cout << "Min Element : " << arr2.minElement() << endl;
    arr2.print();
}