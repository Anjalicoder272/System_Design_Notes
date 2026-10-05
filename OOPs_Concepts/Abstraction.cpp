// Abstraction means hiding the unnecessary details and show only what is necessary 
// basically it means show what to do and hide how it is done.

// Whenever we add the virtual void before the method than it says that here we are declaring it but not defining it,
// it will be defined by its child class.

// In c++ OOPs the parent class pointer can points to the child class object.

#include <iostream>
#include <string>
using namespace std;

class Car{
public:
    virtual void startEngine() = 0;
    virtual void stopEngine() = 0;
    virtual void shiftGear(int gear) = 0;
    virtual void accelerate() = 0;
    virtual void brake() = 0;

};
class SportsCar : public Car {
public:
     string brand;
     string model;
     bool isEngineOn;
     int currentSpeed;
     int currentGear;

     SportsCar(string carBrand, string carModel){
         brand = carBrand;
         model = carModel;
         isEngineOn = false;
         currentSpeed = 0;
         currentGear = 0;
     }
     void startEngine(){
         isEngineOn = true;
         cout<<"Sports Car Engine Started"<<endl;
     }
     void stopEngine(){
         isEngineOn = false;
         currentSpeed = 0;
         currentGear = 0;
         cout<<"Sports Car Engine Stopped"<<endl;
     }
     void shiftGear(int gear){
         if(isEngineOn){
             currentGear++;
             cout<<"Shifted to Gear "<<currentGear<<endl;
         }
     }
     void accelerate(){
         if(isEngineOn && currentGear != 0){
             currentSpeed += 10;
             cout<<"Accelerated to Speed "<<currentSpeed<<endl;
         }
     }
     void brake(){
         if(isEngineOn && currentSpeed > 0){
             currentSpeed -= 10;
             cout<<"Break Applied, Speed is "<<currentSpeed<<endl;
         }
     }
};

int main(){
Car* myCar = new SportsCar("Kia", "Seltos");
     myCar->startEngine();
     myCar->shiftGear(2);
     myCar->accelerate();
     myCar->brake();
     myCar->stopEngine();
}