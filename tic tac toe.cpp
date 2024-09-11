#include<iostream>
#include<bits/stdc++.h>
using namespace std;


	char space [3][3]={{'1','2','3' },{'4','5','6'},{'7','8','9'} };
	int row; 
	int column;
	char token ='x';
	bool istie=false;
	string n1="";
	string n2="";
	
	
	void functionOne(){

	cout<<"    |       |  \n";
	cout<<" "<<space[0][0]<<"  |  "<<space[0][1]<<"    |  "<<space[0][2]<<"  \n";
	cout<<"____|_______|___ \n";
	cout<<"    |       |  \n";
	cout<<" "<<space[1][0]<<"  |  "<<space[1][1]<<"    |  "<<space[1][2]<<"  \n";
	cout<<"____|_______|___ \n";
	cout<<"    |       |  \n";
	cout<<" "<<space[2][0]<<"  |  "<<space[2][1]<<"    |  "<<space[2][2]<<"  \n";
	cout<<"    |       |  \n";

	
}

void functionTwo(){
int digit;

if(token=='x'){
	cout<<n1<<" "<<"please enter your move";

}

else if(token=='0'){
	cout<<n2<<" "<<"please enter your move";
	
}
cin>>digit;
 switch (digit) {
        case 1: row = 0; column = 0; break;
        case 2: row = 0; column = 1; break;
        case 3: row = 0; column = 2; break;
        case 4: row = 1; column = 0; break;
        case 5: row = 1; column = 1; break;
        case 6: row = 1; column = 2; break;
        case 7: row = 2; column = 0; break;
        case 8: row = 2; column = 1; break;
        case 9: row = 2; column = 2; break;
        default:
            cout << "Invalid input! Please enter a number between 1 and 9.\n";
            functionTwo();
            return;
    }
   if (space[row][column] != 'x' && space[row][column] != '0') {
        space[row][column] = token;
        token = (token == 'x') ? '0' : 'x'; 
    } else {
        cout << "This space is already taken! Try again.\n";
         functionTwo();
    }
     functionOne();
}

bool functionThree(){
	for(int i=0;i<3;i++)
	{
		if (space[i][0] == space[i][1] && space[i][1] == space[i][2]) { // Check rows
            return true;
        }
        if (space[0][i] == space[1][i] && space[1][i] == space[2][i]) { // Check columns
            return true;
        }
	}
	 if (space[0][0] == space[1][1] && space[1][1] == space[2][2]) { // Check diagonal
        return true;
    }
    if (space[0][2] == space[1][1] && space[1][1] == space[2][0]) { // Check other diagonal
        return true;
    }
		
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(space[i][j]!='x' && space[i][j]!='0'){
				return false;
				}
			}
		}
	istie =true;
	return true ;
}


int main(){
		cout<<"Enter the name of the first player :\n";
	cin>>n1;
	cout<<"Enter the name of the second player :\n";
	cin>>n2;
	
	cout<<n1<<"is player1 so he/she will play first \n";
	cout<<n2<<"is player1 so he/she will play second \n";
	
	
	while(!functionThree()){
		functionOne();
		functionTwo();
	
	}
    functionOne();  // Show final state of the board
    
    if(istie) {
        cout<<"It's a draw!"<<endl;
    } else if(token == '0') {  
        cout<<n1<<" Wins!!"<<endl;
    } else {
        cout<<n2<<" Wins!!"<<endl;
    }
    
	return 0;
}
