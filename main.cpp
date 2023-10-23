#include <iostream>
#include <exception>
#include <stdlib.h>
#include <ctime>

class BootCatch: public std::exception  {
 public:
    const char* what() const noexcept override{
        return "You've catch the boot!";
    }
};

class FishCatch:  public std::exception {
 public:
    const char* what() const noexcept override{
        return "You've caught the fish!";
    }
};

class NoCatch:  public std::exception {
public:
    const char* what() const noexcept override{
        return "You've catch nothing! Try again!";
    }
}; 

enum  CatchState{No, Fish, Boot};

void printField(int (&field)[9]){
    for(int i = 0; i < 9; ++i){
        std::cout << field[i] << " ";
    }
    std::cout << std::endl;
}

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
    //printField(field);
    while(true){
        std::cout << "Input the sector number (0 - 8) to cast the fishing rod: ";
        int number;
        try{
            std::cin >> number;
            if(std::cin.fail() || number < 0 || number > 8){ 
                std::cin.clear();
                std::cin.sync();
                throw std::invalid_argument("Invalid number sector, repeat input!");
            }
            if(field[number] == No){
                throw NoCatch();
            }
            else if(field[number] == Boot){
                throw BootCatch();
            }else{
                throw FishCatch();
            }          
        }catch(const std::invalid_argument& e){
            std::cerr << e.what() << std::endl;
        }
        catch(const NoCatch& e){
            std::cerr << e.what() << std::endl;
        }catch(const BootCatch& e){
            std::cerr << e.what() << std::endl;
            break;
        }catch(const FishCatch& e){
            std::cerr << e.what() << std::endl;
            break;
        }

    }
}


