#include<iostream>
#include<cmath>
using namespace std;
int main(){
	char operation;
	double number1,number2;
	
	cout<<"Enter first number :";
	cin>>number1;
	cout<<"Enter second number :";
	cin>>number2;
	cout<<"Enter operation :";
	cin>>operation;
	
	switch(operation){
		case '+' :
			
			cout<<number1+number2;
			break;
		
		case '-':
			
			cout<<	number1-number2;
			break;
		
		case '*':
			
			cout<<number1*number2;
			break;
		
		case '/':
			
				if(number2!=0){
				cout<<number1 / number2<<endl;
				
				
			}else{
				cout<<"Division by zero is not allowed"<<endl;
			}
			break;
		
		case '%':
			cout<<static_cast<int>(number1) % static_cast<int>(number2)<<endl;
			break;
		
		
		default:
			cout<<"Invalid Operation"<<endl;
			break;
		
		
			
	}
	
	return 0;
	
}
