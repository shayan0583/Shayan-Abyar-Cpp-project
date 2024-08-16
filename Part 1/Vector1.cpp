#include<iostream>
#include<ctime>
#include <vector>
using namespace std;

template<typename T>
class Vector {

private:
    int size=0;
    int capacity=1;
    T* arr;
public:
    Vector(int size_array,T* a){
        size=size_array;
        capacity=size*2;
        arr=new T[capacity];
        for (int i = 0; i < size; ++i) {
            arr[i] = a[i];
        }
    
    }

    Vector(){
        arr= new T[capacity];
    }
    ~Vector(){
       delete[]arr;

    }
    

void push_back(T data){
    if (size==capacity){
        T*temp = new T[capacity*2];
        for (int i=0;i<size;i++){
            temp[i]=arr[i];
        }
        delete[]arr;
        arr=temp;
        capacity*=2;
    }
    arr[size]=data;
    size++;
}

void pop_back(){
    size-=1;
    T* temp= new T[capacity];
    for (int i;i<size;i++){
        temp[i]=arr[i];
    }
    delete[]arr;
    arr=temp;
}

void insert(T data , int index){
    if (index> size){
    }
    else {
        if(size==capacity){capacity*=2;}
        T* temp= new T[capacity];
        int counter=0;
        for(int i=0 ; i<size+1 ; i++){
            if(i==index){
            temp[i]=data;
            }
            else{
                temp[i]=arr[counter];
                counter++;
            }}
        delete[]arr;
        arr=temp;
        size++;
}
}
void remove(int index){
    if(index < size){
        T* temp = new T[capacity];
        int counter=0;
        for(int i=0;i<size;i++){
            if(index==i){
            }
            else{
                temp[counter]=arr[i];
                counter++;
            }
        }
        delete[]arr;
        arr=temp;
        size--;
    }
    else{
        cout<<endl<<"Segmentation fault --->";
        cout<<"  Out Of Range"<<endl;
    }
} 
T &get(int index) const{
    return arr[index];
}

int get_size() const{
    return size;
}

void resize(int new_size){
    T default_var;
    T* temp= new T[new_size];
    for (int i=0;i<new_size;i++){
        temp[i]=arr[i];
    }
    delete[]arr;
    arr=temp;
    size=new_size;

}
/// 
int get_capacity() const{

    return capacity;
}

T& operator[](int a){return arr[a];}

};

class Shape {
    private:
    std::vector<char> memory;
    public:
        int memory_size= 10*1024*1024 ;//char(1byte)-->to make 10 megabyte memory
        
        Shape(){
            memory.resize(memory_size);

        }
        ~Shape(){
            
        }
};



int main(){
    Vector<Shape> obj;
    Shape a;
    int number =10;
   std::clock_t startinsert = std::clock();
    for (size_t i=0 ; i<number ; ++i){
    obj.insert(a,0);
    }
   std::clock_t endinsert= std::clock();
    double durationinsert =  (endinsert - startinsert) ;
    std::cout<<"The avergae Duartion for insert <"<<number<<"> Shape :  "<<durationinsert/number<<" ms"<<endl;
    std::cout<<"The Total Duration for insert <"<<number<<"> Shape : "<<durationinsert<<" ms"<<endl;
    
    std::cout<<endl;

   std::clock_t startremove = std::clock();
    for (size_t i=0 ; i<number ; ++i){
    obj.remove(0);
    }
   std::clock_t endremove= std::clock();
    double durationremove =  (endremove - startremove) ;
    std::cout<<"The avergae Duartion for remove <"<<number<<"> Shape :  "<<durationremove/number<<" ms"<<endl;
    std::cout<<"The Total Duration for remove <"<<number<<"> Shape : "<<durationremove<<" ms"<<endl;
    return 0;
}