#include<iostream>
#include<cmath>

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
    if (index>= size){
        index=size;
        arr[size]=data;
        size++;
        capacity*=2;
    }
    else {
        T* temp= new T[capacity*2];
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
        capacity*=2;
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
    if (new_size<size){
    T* temp= new T[new_size];
    for (int i=0;i<new_size;i++){
        temp[i]=arr[i];
    }
    delete[]arr;
    arr=temp;
    }
    else{
    T* temp= new T[new_size];
    for (int i=0;i<new_size;i++){
        temp[i]=arr[i];
    }
    delete[]arr;
    arr=temp;
    }
    capacity=2*new_size;
    size=new_size;
}
/// 
int get_capacity() const{

    return capacity;
}

T& operator[](int a){return arr[a];}

};



class Shape {
    public:
        Shape(double density):density(density){}
        ~Shape(){}

        virtual double volume() const = 0;
        virtual double area() const = 0;
        virtual double mass(){return volume() * density ;}
        void set_density(double new_density){density = new_density;}
    protected:
        double density;
};
class Device{
    private:
    Vector<Shape*> shapes ;
    Vector<Device*> devices ;
    public:
        void addshape(Shape* shape){shapes.push_back(shape);}
        void adddevice(Device* device){devices.push_back(device);}

        double EvalVolume(){
            double t_volume=0;
            for(unsigned int i=0; i<shapes.get_size();++i){
                t_volume+=shapes[i]->volume();
            }
            for(unsigned int i=0; i<devices.get_size();++i){
                t_volume+=devices[i]->EvalVolume();
            }
            return t_volume;
            }
        double EvalArea(){
            double t_area=0;
            for(unsigned int i=0; i<shapes.get_size();++i){
                t_area+=shapes[i]->area();
            }
            for(unsigned int i=0; i<devices.get_size();++i){
                t_area+=devices[i]->EvalArea();
            }
            return t_area;
            }
        double EvalMass(){
            double t_mass=0;
            for(unsigned int i=0; i<shapes.get_size();++i){
                t_mass+=shapes[i]->mass();
            }
            for(unsigned int i=0; i<devices.get_size();++i){
                t_mass+=devices[i]->EvalMass();
            }
            return t_mass;
            }

};

class Cube : public Shape {
    private:
        double a;
    public:
    Cube (double a , double density):Shape(density),a(a){
    }
    double volume() const override { return pow(a,3); }
    double area() const override { return 6*a*a; }
};

class Sphere : public Shape {
    private :
        double r;

    public :
        Sphere (double r , double density): Shape(density), r(r) {}
        double volume() const override { return (4.0 / 3.0) * M_PI * r * r * r; }
        double area() const override { return 4 * M_PI * r * r ; }
};









int main(){
    Cube cube1(3.0,2.5);
    Cube cube2(2.0,2.5);
    Cube cube3(1.0,2.5);
    Device device1;
    device1.addshape(&cube1);
    device1.addshape(&cube2);
    cout<<device1.EvalVolume()<<endl;
    Device device2;
    device2.addshape(&cube3);
    cout<<device2.EvalVolume()<<endl;

    device1.adddevice(&device2);    
    cout<<device1.EvalVolume()<<endl;


    return 0;
}





