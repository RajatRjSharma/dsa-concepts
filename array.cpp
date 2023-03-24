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
    /**
     * Custom Array Constructor
     * @param size: Integer input for array size.
     */
    MyArray(int size)
    {
        base_address = new T[size - 1];
        total_size = size;
        used_size = 0;
    }

    /**
     * Method to add values by user input.
     */
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

    /**
     * Method will return total size of custom array.
     */
    int totalSize()
    {
        if (total_size)
            return total_size;
        else
            return 0;
    }

    /**
     * Method will return used size of custom array.
     */
    int usedSize()
    {
        if (used_size)
            return used_size;
        else
            return 0;
    }

    /**
     * Method will return maximum value in custom array.
     */
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

    /**
     * Method will return minimum value in custom array.
     */
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

    /**
     * Method will return value by index in custom array.
     * @param index: Index to get value of.
     */
    T getByIndex(int index)
    {
        if (index >= 0 && index < used_size)
        {
            return base_address[index];
        }
        return (T)NULL;
    }

    /**
     * Method will set the value by index in custom array.
     * @param value: Value to set in index.
     * @param index: Index to get value of.
     */
    T setByIndex(T value, int index)
    {
        if (index >= 0 && index < used_size)
        {
            base_address[index] = value;
            return value;
        }
        return (T)NULL;
    }

    /**
     * Method will concatenate the array supplied to custom array object.
     * @param arr: Array to be concatenated.
     * @param arrSize: Size of the array to be concatenated.
     */
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

    /**
     * Method will print all the value in custom array.
     */
    void print()
    {
        for (int i = 0; i < used_size; i++)
        {
            cout << base_address[i] << " ";
        }
        cout << endl;
    }

    /**
     * Method will insert the value to end of custom array.
     * @param value: Value to be added.
     */
    T insertElement(int value)
    {
        return insertElement(value, used_size);
    }

    /**
     * Method will insert the value to given index.
     * @param value: Value to be inserted.
     * @param index: Index at which the value is to be inserted.
     */
    T insertElement(T value, int index)
    {
        if (index >= 0 && index <= used_size && used_size < total_size)
        {
            for (int j = used_size + 1; j > index; j--)
            {
                base_address[j] = base_address[j - 1];
            }
            base_address[index] = value;
            used_size++;
            return value;
        }
        return (T)NULL;
    }

    /**
     * Method will delete the value to end of custom array.
     */
    T deleteElement()
    {
        return deleteElement(used_size - 1);
    }

    /**
     * Method will delete the value at given index.
     * @param index: Index at which the value is to be deleted.
     */
    T deleteElement(int index)
    {
        if (index >= 0 && index < used_size)
        {
            T del = base_address[index];
            for (int j = index; j < used_size; j++)
            {
                base_address[j] = base_address[j + 1];
            }
            used_size--;
            return del;
        }
        return (T)NULL;
    }

    /**
     * Method to find a element in custom array by linear search.
     * @param value: Value to search in array.
     */
    int linearSearch(T value)
    {
        for (int i = 0; i < used_size; i++)
        {
            if (value == base_address[i])
            {
                return i;
            }
        }
        return -1;
    }
};

/**
 * Method to find a element in custom array by binary search.
 * Requires a sorted array.
 * @param arr: Sorted arr to search in.
 * @param value: Value to search in array.
 * @param arrSize: Size of the array.
 */
int binarySearch(int arr[], int value, int arrSize)
{
    int s = 0;
    int e = arrSize - 1;
    int mid = (s + e) / 2;
    if (arr[s] == value)
        return s;
    if (arr[e] == value)
        return e;
    while (s <= e)
    {
        if (arr[mid] == value)
        {
            return mid;
        }
        else if (arr[mid] > value)
        {
            e = mid - 1;
            mid = (s + e) / 2;
        }
        else
        {
            s = mid + 1;
            mid = (s + e) / 2;
        }
    }
    return -1;
}

int main()
{

    cout << "Integer";
    cout << endl;
    cout << endl;

    MyArray<int> arr(10);
    int arr1[] = {1, 2, 3, 4, 5, 6};
    int arrSize = sizeof(arr1) / sizeof(arr1[0]);
    arr.addArray(arr1, arrSize);
    cout << "Total Size : " << arr.totalSize() << endl;
    cout << "Used Size : " << arr.usedSize() << endl;
    arr.print();
    arr.addArray(arr1, arrSize);
    cout << "Total Size : " << arr.totalSize() << endl;
    cout << "Used Size : " << arr.usedSize() << endl;
    arr.print();
    for (int i = 0; i < 5; i++)
    {
        cout << "Insert Element : " << arr.insertElement(i * 10) << endl;
        cout << "Total Size : " << arr.totalSize() << endl;
        cout << "Used Size : " << arr.usedSize() << endl;
        arr.print();
    }
    for (int i = 0; i < 7; i++)
    {
        arr.addElementFromUser();
        cout << "Total Size : " << arr.totalSize() << endl;
        cout << "Used Size : " << arr.usedSize() << endl;
        arr.print();
    }
    cout << "Max Element : " << arr.maxElement() << endl;
    cout << "Min Element : " << arr.minElement() << endl;
    cout << "Set 5th Element : " << arr.setByIndex(25, 5) << endl;
    cout << "Set 190th Element : " << arr.setByIndex(324, 190) << endl;
    cout << "Get 4th Element : " << arr.getByIndex(4) << endl;
    cout << "Get 15th Element : " << arr.getByIndex(150) << endl;
    cout << "Linear Search : " << arr.linearSearch(6) << endl;
    cout << "Linear Search : " << arr.linearSearch(150) << endl;
    arr.print();
    for (int i = 0; i < 5; i++)
    {
        cout << "Delete Element : " << arr.deleteElement() << endl;
        cout << "Total Size : " << arr.totalSize() << endl;
        cout << "Used Size : " << arr.usedSize() << endl;
        arr.print();
    }
    for (int i = 0; i < 5; i++)
    {
        cout << "Insert Element : " << arr.insertElement(i * 11, i) << endl;
        cout << "Total Size : " << arr.totalSize() << endl;
        cout << "Used Size : " << arr.usedSize() << endl;
        arr.print();
    }
    for (int i = 0; i < 5; i++)
    {
        cout << "Delete Element : " << arr.deleteElement(i) << endl;
        cout << "Total Size : " << arr.totalSize() << endl;
        cout << "Used Size : " << arr.usedSize() << endl;
        arr.print();
    }

    cout << endl;
    cout << endl;
    cout << "CHARACTER";
    cout << endl;
    cout << endl;

    MyArray<char> arr2(10);
    char arr3[] = {'a', 'b', 'c', 'd', 'e'};
    arrSize = sizeof(arr3) / sizeof(arr3[0]);
    arr2.addArray(arr3, arrSize);
    cout << "Total Size : " << arr2.totalSize() << endl;
    cout << "Used Size : " << arr2.usedSize() << endl;
    arr2.print();
    arr2.addArray(arr3, arrSize);
    cout << "Total Size : " << arr2.totalSize() << endl;
    cout << "Used Size : " << arr2.usedSize() << endl;
    arr2.print();
    for (int i = 0; i < 5; i++)
    {
        cout << "Insert Element : " << arr2.insertElement((char)i + 70) << endl;
        cout << "Total Size : " << arr2.totalSize() << endl;
        cout << "Used Size : " << arr2.usedSize() << endl;
        arr2.print();
    }
    for (int i = 0; i < 7; i++)
    {
        arr2.addElementFromUser();
        cout << "Total Size : " << arr2.totalSize() << endl;
        cout << "Used Size : " << arr2.usedSize() << endl;
        arr2.print();
    }
    cout << "Max Element : " << arr2.maxElement() << endl;
    cout << "Min Element : " << arr2.minElement() << endl;
    cout << "Set 5th Element : " << arr2.setByIndex('h', 5) << endl;
    cout << "Set 190th Element : " << arr2.setByIndex('e', 190) << endl;
    cout << "Get 4th Element : " << arr2.getByIndex(4) << endl;
    cout << "Get 15th Element : " << arr2.getByIndex(150) << endl;
    cout << "Linear Search : " << arr2.linearSearch('e') << endl;
    cout << "Linear Search : " << arr2.linearSearch('m') << endl;
    arr2.print();
    for (int i = 0; i < 5; i++)
    {
        cout << "Delete Element : " << arr2.deleteElement() << endl;
        cout << "Total Size : " << arr2.totalSize() << endl;
        cout << "Used Size : " << arr2.usedSize() << endl;
        arr2.print();
    }
    for (int i = 0; i < 5; i++)
    {
        cout << "Insert Element : " << arr2.insertElement((char)80 + i, i) << endl;
        cout << "Total Size : " << arr2.totalSize() << endl;
        cout << "Used Size : " << arr2.usedSize() << endl;
        arr2.print();
    }
    for (int i = 0; i < 5; i++)
    {
        cout << "Delete Element : " << arr2.deleteElement(i) << endl;
        cout << "Total Size : " << arr2.totalSize() << endl;
        cout << "Used Size : " << arr2.usedSize() << endl;
        arr2.print();
    }

    cout << endl;
    cout << endl;
    cout << "BINARY SEARCH";
    cout << endl;
    cout << endl;

    int arr5[] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
    arrSize = sizeof(arr5) / sizeof(arr5[0]);
    cout << "30 at : " << binarySearch(arr5, 30, arrSize) << endl;
    cout << "60 at : " << binarySearch(arr5, 60, arrSize) << endl;
    cout << "0 at : " << binarySearch(arr5, 0, arrSize) << endl;
    cout << "90 at : " << binarySearch(arr5, 90, arrSize) << endl;
    cout << "37 at : " << binarySearch(arr5, 37, arrSize) << endl;
}