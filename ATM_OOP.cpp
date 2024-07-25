#include<iostream>
#include<conio.h>
#include<fstream> //file handling header file
#include<string.h>
#include<windows.h>
#include<stdlib.h>
using namespace std;





class Bank{
	public:
		string name;
		int crdnum;
		int crdpin;
		char type[10];
		int amount = 0;
		int total = 0;
		shutdown();
		restart();
		hibernate();
		ping();
		
};Bank b; //global object


Bank :: shutdown(){
	char admin;
	char pw ;
	cout<<"Enter username:";
	cin>>admin;
	cout<<"Enter Passward:";
	cin>>pw;
	if(admin=='admin'&&pw=='admin'){
	system("shutdown -s");
 }
}
Bank :: restart(){
	system("shutdown -r");
}
Bank :: hibernate(){
	system("shutdown -h");
}
Bank :: ping(){

	system("ping 8.8.4.4");
	
}



class activecard: public Bank{
	
	public:
		void active_card(){		
		
		//system("cls");
		
		cout<<"Enter your Card Number: ";
		cin>>b.crdnum;
		cout<<"Enter your Card PIN: ";
		cin>>b.crdpin;
		cout<<"Please Enter your name: ";
		//cin<<b.ignore();
		//To use space in string
		cin>>b.name;
		cout<<"Enter your Account type: ";
		cin>>b.type;
		cout<<"Enter your Total Balance: ";
		cin>>b.total;
		ofstream f1("record.txt",ios::app);
		f1<<b.crdnum<<' '<<b.crdpin<<' '<<b.name<<' '<<b.type<<' '<<b.total<<endl;
		system("cls");
		cout<<"Thankyou Activation is Successful!\n";
	
	
	
		int main();
		}
		void showdetail(){
			cout<<"Costumer Name: "<<b.name<<endl;
			cout<<"Account type: "<<b.type<<endl;
			cout<<"Total Balance: "<<b.total<<endl;
		}
};





class widral: public activecard{
	int temp;
	public:
		int count;
		int cdn, pinn, avail_blnc;
		int amnt;
		void widthrawal(){
		
		
			cout<<"Enter your card Number and PIN to widrawal amount"<<endl;
			cout<<"Enter your card Number: ";
			cin>>b.crdnum;
			cout<<"Enter your PIN: ";
			cin>>b.crdpin;
			
		
		
			ifstream input("record.txt");
			while(input>>cdn>>pinn){
				if(cdn==b.crdnum && pinn==b.crdpin){
					count = 1;
					cout<<"you are entered"<<endl;
					cout<<"Enter your Balance to widrawal:";
				cin>>b.amount;
			}
			else{
				cout<<"wrong card No & PIN"<<endl;
				break;
			}
			}
			
			if(count==1){
				if(b.amount!=b.total){
					b.total = b.total - b.amount;
					cout<<"Remaining Balance: "<<b.total<<endl;
					}
				}
			input.close();
		}
		
};





int main(){

	system ("color 0A");

	cout<<"~WELCOME TO CHAWALAN THE BANK~"<<endl;
			cout<<"\n\t\t\t\t\t\t_________________________________________________________"<<endl;
		cout<<"\n\t\t\t\t\t\t_________________________________________________________"<<endl;
		cout<<"\n\t\t\t\t\t\t=             *     **********   **         **          ="<<endl;	
		cout<<"\t\t\t\t\t\t=           ** **   **********   ** **   ** **          ="<<endl;
		cout<<"\t\t\t\t\t\t=          **   **      **       **   ***   **          ="<<endl;
		cout<<"\t\t\t\t\t\t=         *********     **       **    *    **          ="<<endl;
		cout<<"\t\t\t\t\t\t=        **       **    **       **         **          ="<<endl;
		cout<<"\t\t\t\t\t\t=       ***        **   **       **         **          ="<<endl;
		cout<<"\n\t\t\t\t\t\t_________________________________________________________"<<endl;
		cout<<"\n\t\t\t\t\t\t_________________________________________________________"<<endl;
		cout<<"\n\t\t\t\t\t\t\t\t\t\tProject By :RunTime Terror"<<endl;

	widral w1;
	activecard a1;
	Bank B1;
	int choice;
	
	
	
	while(1){
		
		cout<<"Enter your choice"<<endl;
		cout<<"Press 1 to card activation"<<endl;
		cout<<"Press 2 to widhtrawal amount"<<endl;
		cout<<"Press 3 to show details"<<endl;
		cout<<"Press 4 to check connectivity"<<endl;
		cout<<"Press 5 to shutdown"<<endl;
		cout<<"Press 6 to Restart"<<endl;
		cout<<"Press 7 to hibernate"<<endl;
		cin>>choice;
		switch(choice){
			case 1:
				a1.active_card();
				break;
			case 2:
				w1.widthrawal();
				break;
			case 3:
				w1.showdetail();
				break;
			case 4:
				B1.ping();
				break;
			case 5:
				B1.shutdown();
			case 6:
				B1.restart();
			case 7:
				B1.hibernate();
			default:
				cout<<"Invalid choise";
				
				
		}
		
		
	}
	return 0;
}
