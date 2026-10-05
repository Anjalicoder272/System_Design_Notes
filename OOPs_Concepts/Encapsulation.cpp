// Encapsulation means keeping the characterstics(variables) and behaviours(methods) together inside the one class 
// and hiding the data from the outside world using the access modifiers.  

// Abstraction means hiding the unnecessary details and show only what is necessary 
// basically it means show what to do and hide how it is done.

// Whenever we add the virtual void before the method than it says that here we are declaring it but not defining it,
// it will be defined by its child class.

// In c++ OOPs the parent class pointer can points to the child class object.

// Abstraction vs Encapsulation
// basically the main diff between the abstraction and encapsulation is that IN abstraction focus on data hiding
// on the another hand encapuslation depends on the data security

#include <iostream>
#include <string>
using namespace std;


class SportsCar{
    // characterstics cout<<"Set Current Speed is "<<myCar->setCurrentSpeed(100)<<endl;
private:
     string brand;
     string model;
     bool isEngineOn;
     int currentSpeed;
     int currentGear;
public:
     SportsCar(string carBrand, string carModel){
         brand = carBrand;
         model = carModel;
         isEngineOn = false;
         currentSpeed = 0;
         currentGear = 0;
     }
    //  behaviours
    int getCurrentSpeed(){
         return this->currentSpeed;
     }
     void setCurrentSpeed(int speed){
         if(speed >= 0 && speed <= 200){
             this->currentSpeed = speed;
         }
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
SportsCar* myCar = new SportsCar("Kia", "Seltos");
     myCar->startEngine();
     myCar->shiftGear(2);
     myCar->accelerate();
    //  myCar->brake();
    //  myCar->stopEngine();

    //  myCar->currentGear = 5;
    //  cout << "my currentGear is set to "<< myCar->currentGear<<endl;
    cout<<myCar->getCurrentSpeed()<<endl;
    cout<<"Current Speed is "<<myCar->getCurrentSpeed()<<endl;
    myCar->setCurrentSpeed(100);
    cout<<"Set Current Speed is "<<myCar->getCurrentSpeed()<<endl;
}