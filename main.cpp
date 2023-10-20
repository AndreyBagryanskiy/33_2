#include <iostream>
#include <exception>
#include <stdlib.h>
#include <ctime>

class BootCatch: public std::exception  {
 public:
    const char* what() const noexcept override{
        return "You've catch the boot!\n";
    }
};

class FishCatch:  public std::exception {
 public:
    const char* what() const noexcept override{
        return "You've caught the fish!\n";
    }
};

class NoCatch:  public std::exception {
public:
    const char* what() const noexcept override{
        return "You've catch nothing! Try again!\n";
    }
}; 

enum  CatchState{No, Fish, Boot};

int main(){
    std::srand(std::time(nullptr));
    int field[9]{};
    field[std::rand() % 9] = Fish;
    int count = 0;
    while(count < 3){
        int bootField = std::rand() % 9;
        if(field[bootField] == No){
            field[bootField] = Boot;
            ++count;
        }
    }
    std::cout <<" ";



}


