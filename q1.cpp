#include<iostream>


using namespace std ; 

class Car 
{
	private:
	 
	// all public variables	
	public:	
	string Model , Color , current_status ;
	int inital_speed , current_speed ;
	
	// constructor and destructor 
	Car	(  )
	{
		cout << "Enter car details" << endl ;
		cout << "Model:";
		cin >> 	this->Model ;
	
		cout << "Color:";
		cin >> 	this->Color ;
		
		cout << "Initial speed( km / h ):" ;
		cin >> 	this->inital_speed ;
		
		cout << "A new car has been created!" << endl ; 
	
	}
	~Car ()
	{
		
	}
	
	// all public methods
	public:
	void Car_Tester();
	
	
		
};

void Car :: Car_Tester()
{
	this->current_speed = 0 ;
	this->current_status = "stopping" ; 
	int change_amount ;   
	int choice ;
	do 
		{
			cout << "1. Start" << endl ; 
			cout << "2. Stop" << endl ;
			cout << "3. Accelerate" << endl ;
			cout << "4. Decelearate" << endl ;
			cout << "5. Show Details" << endl ;
			cout << "0. Exit" << endl ;
			cout << "Enter the choice:";
						
			cin >> choice ; 
						
			switch (choice)
				{
					case 1 :
						if ( this->inital_speed > 0 )
						{
							cout << "The car has been started with initial speed " << this->inital_speed << "km/h" << endl ;
							this->current_speed = this->inital_speed; 
							this->current_status = "running";
						}
						else 
						{
							cout << "Intial speed is not proper for starting simulaiton please rearrange it (enter positive value):";
							cin >> this->inital_speed ; 
						}
						
							
					break;
							
					case 2 :
						cout << "The car has been stopped" << endl ; 
						this->current_speed = 0 ;
						this->current_status = "stopping" ; 
					break; 
							
					case 3 :
						cout << "Please enter acceleration amount:";
						cin >> change_amount ; 
						this->current_speed += change_amount ; 
						cout << "The car has accelerated. Current speed: " << current_speed << " km/h" << endl;
						
					break; 
							
					case 4 :
						cout << "Please enter deceleration amount:";
						cin >> change_amount ; 
						
						if (this->current_speed - change_amount > 0   )
						{
							this->current_speed -= change_amount ;
							cout << "The car has decelerated. Current speed: " << this->current_speed << " km/h" << endl ; 
						}
						else 
						{
							cout << "This car can not opperate this at running status you should stop the car." << endl ; 
						}
					break; 
							
					case 5 :
						cout << "The car is currently " << this->current_status << "." << endl ; 
						cout <<"Model:" << this->Model << "," << " Color: " << this->Color <<"," << " Speed:" <<  	this->current_speed << " km/h" << endl ; 
					break;   
							
				}
				
				}while(choice != 0  );
				
}



int main() 
{
	Car car1 ; 
	car1.Car_Tester();
	
	
	return 0 ; 
}