#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class Weather {
protected:
    static Weather* head;
    Weather* next;
    int temperature;
    
public:
    Weather(){
       cout << "Температура: ";
       cin >> temperature;
    }
    
    virtual void Add();
    virtual void show();
    

};

Weather* Weather::head = nullptr;

class Wind : public Weather {
protected:
    string type;
    int speed;
public:
    Wind(){
    
    }
    
    void SetType(string type){
    this->type =type;
    }
    
    string GetType(){return type;}
    
    void SetSpeed(int speed) {
        this->speed = speed;
    }
    int GetSpeed(){return speed;}
};

class Rain : public Wind
{

}

class Snow : public Wind
{

}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	 
	return 0;
}