#include <iostream>
using namespace std;

class MyArray {
    private:
    int total_size;
    int used_size;
    int* base_address;

    public:
    MyArray(int size) {
        base_address = new int [size-1];
        total_size = size;
        used_size = 0;
    }

    void addFromUser() {
        if(used_size < total_size) {
        int user;
        cout<<"Enter integer value to array : ";
        cin>>user;
        base_address[used_size++] = user;
        } else {
            cout<<"Array Size full cannot add more value!!"<<endl;
        }
    }

    int totalSize() {
        if(total_size)
        return total_size;
        else
        return 0;
    }

    int usedSize() {
        if(used_size)
        return used_size;
        else
        return 0;
    }


    int max(){
        int maxx = -1;
        if(used_size && used_size > 0) {
            for(int i=0; i<used_size; i++) {
                if(maxx < base_address[i])
                    maxx = base_address[i];
            }
        }
        return maxx;
    }

    int get(int i) {
        if(i>=0 && i <= used_size) {
            return base_address[i];
        }
        return -1;
    }

    int set(int num, int i) {
        if(i>=0 && i <= used_size) {
            base_address[i] = num;
            return 1;
        }
        return 0;
    }

    void add(int arr[], int arrSize) {
        int* tempArr =  base_address;
        int tempSize = used_size;
        base_address = new int [total_size + arrSize];
        total_size = total_size + arrSize;
        used_size = 0;
        for(int i = 0; i< tempSize; i++) {
            base_address[used_size++] = tempArr[i];
        }
        for(int i = 0; i< arrSize; i++) {
            base_address[used_size++] = arr[i];
        }
        delete[] tempArr;
    }

    void print() {
        for(int i=0; i< used_size; i++) {
            cout<< base_address[i] << " ";
        }
        cout<<endl;
    }

    int insert(int num) {
        return insert(num,used_size);
    }

    int insert(int num, int i) {
        if(i>=0 && i <= used_size && used_size < total_size) {
            for(int j= used_size + 1; j > i ; j--) {
                base_address[j] = base_address[j - 1];
            }
            base_address[i] = num;
            used_size++;
            return 1;
        }
        return 0;
    }

    int deleteEle() {
        return deleteEle(used_size-1);
    }

    int deleteEle(int i) {
        if(i>=0 && i <= used_size) {
            int del = base_address[i];
            for(int j= i; j < used_size ; j++) {
                base_address[j] = base_address[j+1];
            }
            used_size--;
            return del;
        }
        return -1;
    }
};

int main() {
    MyArray arr(5);
    int arr1[] = {1,2,3,4,5,6};
    int arrSize = sizeof(arr1)/sizeof(arr1[0]);
    arr.add(arr1, arrSize);
    cout<<"Total Size : "<<arr.totalSize()<<endl;
    cout<<"Used Size : "<<arr.usedSize()<<endl;
    arr.add(arr1, arrSize);
    cout<<"Total Size : "<<arr.totalSize()<<endl;
    cout<<"Used Size : "<<arr.usedSize()<<endl;
    arr.print();
    cout<<"Insert Element : "<<arr.insert(100,0)<<endl;
    cout<<"Insert Element : "<<arr.insert(100,17)<<endl;
    cout<<"Insert Element : "<<arr.insert(101)<<endl;
    arr.addFromUser();
    arr.addFromUser();
    arr.addFromUser();
    arr.addFromUser();
    arr.addFromUser();
    arr.addFromUser();
    arr.print();
    cout<<"Total Size : "<<arr.totalSize()<<endl;
    cout<<"Used Size : "<<arr.usedSize()<<endl;
    cout<<"Max Element : "<<arr.max()<<endl;
    cout<<"Set Success : "<<arr.set(25, 5)<<endl;
    cout<<"Set Success : "<<arr.set(324, 19)<<endl;
    cout<<"Get 4th Element : "<<arr.get(4)<<endl;
    cout<<"Get 15th Element : "<<arr.get(15)<<endl;
    arr.print();
    cout<<"Delete Element : "<<arr.deleteEle(2)<<endl;
    cout<<"Delete Element : "<<arr.deleteEle(12)<<endl;
    cout<<"Delete Element : "<<arr.deleteEle(17)<<endl;
    cout<<"Delete Element : "<<arr.deleteEle(7)<<endl;
    cout<<"Delete Element : "<<arr.deleteEle()<<endl;
    cout<<"Total Size : "<<arr.totalSize()<<endl;
    cout<<"Used Size : "<<arr.usedSize()<<endl;
    arr.print();
}