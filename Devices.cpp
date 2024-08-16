#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

class Shape {
    public:
        Shape(double density):density(density){}
        ~Shape(){}

        virtual double volume() const = 0;
        virtual double area() const = 0;
        virtual double mass(){return volume() * density ;}
        void set_density(double new_density){density = new_density;}
        double get_density(){return density;}
    protected:
        double density;
};
class Device{
    private:
    vector<Shape*> shapes ;
    vector<Device*> devices ;
    public:
        void addshape(Shape* shape){shapes.push_back(shape);}
        void adddevice(Device* device){devices.push_back(device);}

        double EvalVolume(){
            double t_volume=0;
            for(unsigned int i=0; i<shapes.size();++i){
                t_volume+=shapes[i]->volume();
            }
            for(unsigned int i=0; i<devices.size();++i){
                t_volume+=devices[i]->EvalVolume();
            }
            return t_volume;
            }
        double EvalArea(){
            double t_area=0;
            for(unsigned int i=0; i<shapes.size();++i){
                t_area+=shapes[i]->area();
            }
            for(unsigned int i=0; i<devices.size();++i){
                t_area+=devices[i]->EvalArea();
            }
            return t_area;
            }
        double EvalMass(){
            double t_mass=0;
            for(unsigned int i=0; i<shapes.size();++i){
                t_mass+=shapes[i]->mass();
            }
            for(unsigned int i=0; i<devices.size();++i){
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


class Cylinder : public Shape {
private:
    double r;
    double h;
public :
    Cylinder(double redius,double heigh,double density): Shape(density),r(redius),h(heigh){}
    double volume() const override {
        return M_PI * r * r * h;
    }
    double area() const override {
        return 2 * M_PI * r * (r + h);
    }

};






int main(){
    Cube  cube1(2,3);
    Cube  cube2(1,4);
    Cube  cube3(5,6);
    Device device1;

    Sphere sphere1(4,2);
    Sphere sphere2(2,1);
    Sphere sphere3(6,2.5);
    Device device2;

    Cylinder cylinder1(3,2.6,4.8);
    Cylinder cylinder2(4,3.6,4.8);
    Cylinder cylinder3(3,2,3.1);
    Device device3;

    device1.addshape(&cube1);
    device1.addshape(&sphere1);
    device1.addshape(&cylinder1);

    device2.addshape(&cube2);
    device2.addshape(&sphere2);
    device2.addshape(&cylinder2);
    
    device3.addshape(&cube3);
    device3.addshape(&sphere3);
    device3.addshape(&cylinder3);

    cout<<"Eval Volume for device 1 :  "<<device1.EvalVolume()<<endl;
    cout<<"Eval Area for device 1 :  "<<device1.EvalArea()<<endl;
    cout<<"Eval Mass for device 1 :  "<<device1.EvalMass()<<endl;
    
    cout<<endl;

    cout<<"Eval Volume for device 2 :  "<<device2.EvalVolume()<<endl;
    cout<<"Eval Area for device 2 :  "<<device2.EvalArea()<<endl;
    cout<<"Eval Mass for device 2 :  "<<device2.EvalMass()<<endl;

    cout<<endl;

    cout<<"Eval Volume for device 3 :  "<<device3.EvalVolume()<<endl;
    cout<<"Eval Area for device 3 :  "<<device3.EvalArea()<<endl;
    cout<<"Eval Mass for device 3 :  "<<device3.EvalMass()<<endl;


    Device device_total;

    device_total.adddevice(&device1);
    device_total.adddevice(&device2);
    device_total.adddevice(&device3);


    cout<<endl;

    cout<<"Eval Volume for All Devices : "<<device_total.EvalVolume()<<endl;
    cout<<"Eval Area for All Devices : "<<device_total.EvalArea()<<endl;
    cout<<"Eval Mass for All Devices : "<<device_total.EvalMass()<<endl;

    cout<<endl;
    return 0;
}





