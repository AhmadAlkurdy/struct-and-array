///////////////////////////////////////////////////////////////////////////////////////////
// This code shows:                                                                      //
//                1- shows the menu of the restuarant                                    //
//                2- ask the user for the choice by typing the number of the choice      //
//                3- ask the user for the quantity of the chocie.                        //
//                4- shows the recipt of the order                                       //
//    Name : Ahmad Alkurdy                                                               //
//    Class: CSC 102                                                                     //
//    Assignment 2                                                                       //
///////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <array>
#include <iomanip>
#include <string>

using namespace std;
//declare the struct
struct menuItemType
{
	string menuItem;
    double menuPrice;

	

};
//declare the array of the struct
menuItemType menulist[8];
//fucntion declarations
void getData (menuItemType menulist[8]);
void showMenu (menuItemType menulist[8]);
void printCheck( menuItemType menulist[8], int choice,int howMany,const double &total1);
const double total1 = 0;



//the main call two functions
int main ()
{
	showMenu(menulist);
	getData(menulist);

	system("pause");
	return 0;

}
void showMenu (menuItemType menulist[8])
{
	// this function shows the menu of the resturant 
	
	cout << "Welcome to Ahmad's Restaurant" << endl;
	cout << left << "1-Plain Egg" << setfill(' ') << setw(30) << right << "$1.45" << endl;
	cout << left << "2-Bacon and Egg" << setfill(' ') << setw(26) << right << "$2.45" << endl;
	cout << left << "3-Muffin" << setfill(' ') << setw(33) << right << "$0.99" << endl;
	cout << left << "4-French Toast" << setfill(' ') << setw(27) << right << "$1.99" << endl;
	cout << left << "5-Fruit Basket" << setfill(' ') << setw(27) << right << "$2.49" << endl;
	cout << left << "6-Cereal" << setfill(' ') << setw(33) << right << "$0.69" << endl;
	cout << left << "7-Coffee" << setfill(' ') << setw(33) << right << "$0.50" << endl;
	cout << left << "8-Tea" << setfill(' ') << setw(36) << right << "$0.75" << endl;
}
void getData (menuItemType menulist[8])
{
	// getData functions stores the data in the struct and the arrays and prompt the user to get their choices
	int choice= 0;
	int howMany = 0;
	menulist[0].menuPrice = 1.45;
	menulist[1].menuPrice = 2.45;
	menulist[2].menuPrice = 0.99;
	menulist[3].menuPrice = 1.99;
	menulist[4].menuPrice = 2.49;
	menulist[5].menuPrice = 0.69;
	menulist[6].menuPrice = 0.50;
	menulist[7].menuPrice = 0.75;
	menulist[0].menuItem = "Plain Egg";
	menulist[1].menuItem = "Bacon and Egg";
	menulist[2].menuItem = "Muffin";
	menulist[3].menuItem = "French Toast";
	menulist[4].menuItem = "Fruit Basket";
	menulist[5].menuItem = "Cereal";
	menulist[6].menuItem = "Coffee";
	menulist[7].menuItem = "Tea";
	int counter = 0;
	while (counter >= 0)
	{
		cout << endl;

	cout << "enter the number of your choice, and when you are done just press 11: " << endl;
	cin >> choice;
	if(choice == 11)
	{
		break;
	}
	if(choice > 8)
	{
		cout << "Error: choice between 1-8" << endl;
	}
	else 
	{
	cout << "How many of " <<  menulist[choice - 1].menuItem  << " would you like today?" << endl;
	cin >> howMany;
	counter ++;
	 printCheck(menulist, choice, howMany,total1);// calling the printing function
	}
	}

}
void printCheck( menuItemType menulist[8], int choice,int howMany, double &total1)
{
	// print the recipt for the user
	double tax = 0;
	double total = 0;
	double fullTotal = 0;
	cout << endl;
	cout << "Recipt" << endl;
	cout << "------------------------------------------------------" << endl;

	cout <<right <<  menulist[choice - 1].menuItem << setw(20) << right << '$' << menulist[choice - 1].menuPrice
		<< endl;
	tax =  (menulist[choice - 1].menuPrice * 5 * howMany)/100;
	cout << left << "Tax" << setw(28) << right <<  '$' <<  tax << endl;
	total = (menulist[choice - 1].menuPrice * howMany) + tax;
	total1 = total1 + total;
	
	cout << left << "Quantity" << setw(25) << right << howMany << endl;
	cout << left <<  "Amount Due" << setw(21) << right << '$' << total << endl;

}
