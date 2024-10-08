#include <iostream>
#include <vector>
#include<ctime>
namespace myspace{
template <typename T>
class vector{
     public:
	vector(){data =new T*[N];}
	vector(int _N, T _Val);
	~vector();
	T operator[] (int i);
	void resize(int newsize);
	void insert(T member,int index);
	void remove(int index);
	int size(){
		return N;
	}
     protected:
        T** data;	
		int N=0;	
};


template <typename T>
vector<T>::vector(int _N, T _Val ):N(_N){
    data = new T*[N];
    for (int i{0}; i < N; i++){
	    data[i] = new T(_Val);
    }
}

template <typename T>
vector<T>::~vector(){
	for (int i{0};i < N; i++){
		delete data[i];
		std :: cout << i << "\n";
	}
	delete [] data;
}

template <typename T>
T vector<T>::operator[] (int i){
	try {
		if (i>=0 && i < N){
			return *data[i];
		}
		else
		 throw(i);
	}
		catch(int i){
			std::cout << "out of range, try to access "<< i << " out of " << N <<"\n";
			exit(-1);
		}
	}
template <typename T>
void vector<T>::resize(int newsize){
	T default_var;
    T** temp= new T*[newsize];
    for (int i=0;i<newsize;i++){
        temp[i]=data[i];
    }
    delete[]data;
    data=temp;
    N=newsize;
}
template <typename T>
void vector<T>::insert(T member,int index){
	if (index < 0 || index > N) {
		
		exit(1);
	}
		
	resize(N + 1);
    for (int i = N - 1; i > index; --i) {
        data[i] = data[i - 1];
	}
    data[index] = new T(member);
}
template <typename T>
void vector<T>::remove(int index) {
    if (index < 0 || index >= N) {
        std::cout <<"Out Of Range !"<<std::endl;
        return;
    }
    delete data[index];
    for (int i = index; i < N - 1; ++i) {
        data[i] = data[i + 1];
    }
    resize(N - 1);
}
}
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
    myspace::vector<Shape> obj;
    Shape a;
    int number =10;
   std::clock_t startinsert = std::clock();
    for (size_t i=0 ; i<number ; ++i){
    obj.insert(a,0);
    }
   std::clock_t endinsert= std::clock();
    double durationinsert =  (endinsert - startinsert) ;
    std::cout<<"The avergae Duartion for insert <"<<number<<"> Shape :  "<<durationinsert/number<<" ms"<<std::endl;
    std::cout<<"The Total Duration for insert <"<<number<<"> Shape : "<<durationinsert<<" ms"<<std::endl;
    
    std::cout<<std::endl;

   std::clock_t startremove = std::clock();
    for (size_t i=0 ; i<number ; ++i){
    obj.remove(0);
    }
   std::clock_t endremove= std::clock();
    double durationremove =  (endremove - startremove) ;
    std::cout<<"The avergae Duartion for remove <"<<number<<"> Shape :  "<<durationremove/number<<" ms"<<std::endl;
    std::cout<<"The Total Duration for remove <"<<number<<"> Shape : "<<durationremove<<" ms"<<std::endl;
    return 0;
}