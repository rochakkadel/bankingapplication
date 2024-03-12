#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits> 


double deposit(double &balance, std::string &username);
double withdraw(double &balance, std::string &username);
void signup(std::string &username, std::string &password);
void signin(std::string &username, std::string &password,bool &yes, double &balance);
void changepassword(std::string &username, std::string &password);
void validateCreditCard(std::string &cardnum);


int main() {

// Set the precision to avoid scientific notation
  std::cout << std::fixed << std::setprecision(2);

  std::string username,password;
  int menumain,menu;
  bool yes;
  double balance;


	do{
	std::cout<< "Welcome to Rochak Bank\n";
	std::cout<< "\n";
	std::cout<< "Choose from the following\n";
	std::cout<< "1. Signup\n";
	std::cout<< "2. Signin\n";
	std::cout<< "3. Change Password\n";
	std::cout<< "4. Credit Card Validator\n";
	std::cout<< "5. Exit\n";
	std::cout<< "Enter: ";
	std::cin >> menumain;
	std::cout << "\n";

		//avoid string value when user doesnt enter int value
		  if (std::cin.fail()){ 
			  std::cin.clear();
			  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
			  std::cout << "Invalid input. Please enter a number.\n";
				std::cout<<"\n";
		  }

	switch(menumain){

		case 1:
		signup(username,password);
		break;

		case 2:
		signin(username,password,yes,balance);

		if(yes == true){

			std::ofstream account;
			account.open(username +".balance");//creates file with username and store balance
			account<<balance; //send balance to file
			account.close();

			  do{
				 std::cout << "1. Deposit Money\n";
				 std::cout << "2. Withdraw Money\n";
				 std::cout << "3. Balance\n";
				 std::cout << "4. Exit\n";
				 std::cout << "Enter: ";
				 std::cin >> menu;
				 std::cout << "\n";

				  if (std::cin.fail()) {
					  std::cin.clear();
					  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
					  std::cout << "Invalid input. Please enter a number.\n";
						std::cout<<"\n";
				  }

				  switch(menu){

					  case 1:
						deposit(balance, username);
						break;

					  case 2:
						withdraw(balance, username);
						break;

					  case 3:
						std::cout << "Your balance is $" << balance << "\n";
						std::cout << "\n";
						break;
					 }

			  } while(menu != 4);
		}
		break;	

		case 3:
		changepassword(username,password);
		break;

		case 4:
		std::string cardnum;
			
		std::cout<< "Enter a credit card number(no spaces): ";
		std::cin>>cardnum;
			
		validateCreditCard(cardnum);
		break;
		
		}


	} while(menumain != 5);
	std::cout<<"Thank you for using Rochak Bank!\n";

  return 0;

}


void changepassword(std::string &username, std::string &password){

	 std::string oldpassword, passwordcheck;

	 std::cout << "CHANGE PASSWORD\n";
	 std::cout << "Enter your username: ";
	 std::cin >> username;
	 std::cout<<"\n";

	 std::ifstream accountcheck;
	 accountcheck.open(username + ".account"); // tries to open the file with username

	if(accountcheck.is_open()){

		accountcheck >> oldpassword; //read old password
		accountcheck.close();

		std::cout<< "Enter your old password: ";
		std::cin >> passwordcheck;
		std::cout<<"\n";

		 if(passwordcheck == oldpassword){

			 while(true){

				std::cout<< "Enter your new password: ";
				std::cin>>password;

				 if(password.length() != 4){

					 std::cout<< "Password must be 4 digits.\n";
					 std::cout<< "\n";
				  }
				 else if(password == oldpassword){

					 std::cout<<"Password cannot be the same as old password.\n";
					 std::cout<<"\n";
				 } 
				 else if(password == "1234" || password == "0000" || password == "4321" || password == "1111" || password == username + "123" || password == username){

					 std::cout << "Password is too weak! Try Again!\n";
					 std::cout << "\n";

					 srand(time(NULL)); // to make sure random number isn't the same every time
					 std::string passwordsuggestmenu;

					 do{

						std::cout << "Enter '1' if you'd like a new password suggestion.\n";
						std::cout << "Enter '0' to exit.\n";
						std::cout << "Enter: ";
						std::cin >> passwordsuggestmenu;
						std::cout<<"\n";

					  if(passwordsuggestmenu == "1"){

						int a = rand() % 10; 
						int b = rand() % 10;
						int c = rand() % 10;
						int d = rand() % 10;

						std::cout<< "New password suggestion: " << a << b << c << d << "\n";
						std::cout<< "\n";
						}
						 
					}while(passwordsuggestmenu != "0");

				 }
				 else{
					std::ofstream account;
					account.open(username + ".account"); //write new password
					account<<password;

					std::cout << "Password sucessfullly changed!\n";
					std::cout<<"\n";
					account.close();
					break; 
					}
			}
			}
			else{
				std::cout<< "Incorrect password\n";
				std::cout<< "\n";
			}
		}

	else{
		std::cout << "Account not found\n";
		std::cout << "\n";
	}

}


void signup(std::string &username, std::string &password){

	 std::cout << "SIGNUP\n";
	 std::cout << "Create a username: ";
	 std::cin >> username;

	 std::ifstream accountcheck;
	 accountcheck.open(username + ".account"); // tries to open the file with username

if(accountcheck.is_open()){

		  std::cout<< "Username already taken!\n";
		  std::cout<< "\n";
		  accountcheck.close();	 
	 }

else{

	 accountcheck.close();

	 while(true){

		std::cout<< "Create a 4-digit password: ";
		std::cin>> password;
		std::cout<< "\n";

		 if(password.length() != 4){

			 std::cout<< "Password must be 4 digits.\n";
			 std::cout<< "\n";
				}

		 else if(password == "1234" || password == "0000" || password == "4321" || password == "1111" || password == username + "123" || password == username){

			 std::cout << "Password is too weak! Try Again!\n";
			 std::cout << "\n";

			 srand(time(NULL)); // to make sure random number isn't the same every time

			while(true){

				std::string passwordsuggestmenu;

				std::cout << "Enter '1' if you'd like a new password suggestion.\n";
				std::cout << "Enter '0' to exit.\n";
				std::cout << "Enter: ";
				std::cin >> passwordsuggestmenu;
				std::cout<<"\n";

			  if(passwordsuggestmenu == "1"){

				int a = rand() % 10; 
				int b = rand() % 10;
				int c = rand() % 10;
				int d = rand() % 10;

				std::cout<< "New password suggestion: " << a << b << c << d << "\n";
				std::cout<< "\n";
				} 

			 else{
					break;
				  }

			}
			}

		else{
			std::ofstream account;
			account.open(username + ".account"); // opens file with username
			account << password; // set password to file

			std::cout << "Account successfully created\n";
			std::cout<<"\n";
			account.close();
			break;
			} 
	}
 }

}


void signin(std::string &username, std::string &password, bool &yes, double &balance) {

	std::string passwordstore;

	 std::cout << "SIGNIN\n";
	 std::cout << "Enter your username: ";
	 std::cin >> username;

	 std::ifstream account;
	 account.open(username+".account");//opens file with username 

	 if (account.is_open()) {

		  std::cout << "Enter your password: ";
		  std::cin >> password;
		  std::cout << "\n";

		  account >> passwordstore; 

		  if (password == passwordstore) {
				std::cout<< "You are signed in\n";
				std::cout<<"\n";

			  std::ifstream balancefile;
			  balancefile.open(username +".balance");//creates file with username and store balance
				balancefile>>balance; //send balance to file
				balancefile.close();

				yes = true;

		  } else {
				yes = false;
				std::cout << "Incorrect password\n";
				std::cout << "\n";
		  }

		  account.close();

	 } else {
		  yes = false;
		  std::cout << "Account not found\n";
		  std::cout<<"\n";
	 }

}


double deposit(double &balance, std::string &username) {

  double input;

  do {
	 std::cout<<"DEPOSIT\n";
	 std::cout << "Your balance is $" << balance << "\n";
	 std::cout << "Enter the amount you'd like to deposit: $";
	 std::cin >> input;

		 if (std::cin.fail()) {
			 std::cin.clear();
			 std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
			 std::cout << "Invalid input. Please enter a number.\n";
			 std::cout<<"\n";
		 }

  } while (input < 0);

	balance = balance + input;

	std::ofstream account;
	account.open(username +".balance");//creates file with username and store balance
	account<<balance; //send balance to file
	account.close();

  std::cout << "You sucessfully deposited $" << input << "\n";
  std::cout << "\n";

  return balance;

}


double withdraw(double &balance, std::string &username) {

  double input;

  do {
	 std::cout << "WITHDRAW\n";
	 std::cout << "Your balance is $" << balance << "\n";
	 std::cout << "Enter the amount you'd like to withdraw: $";
	 std::cin >> input;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
			std::cout << "Invalid input. Please enter a number.\n";
			std::cout<<"\n";
		}

  } while (input < 0);

  if (input > balance) {
	 std::cout << "Insufficent funds\n";
	 std::cout << "\n";

  } else {
	 balance = balance - input;

	 std::ofstream account;
	 account.open(username +".balance");//creates file with username and store balance
	 account<<balance; //send balance to file

	 std::cout << "You sucessfully withdrew $" << input << "\n";
	 std::cout << "\n";
	 account.close();

  }

  return balance;

}


void validateCreditCard(std::string &cardnum) {
	
	 int sum = 0;

	 // Check if the input contains only numeric characters
	 for (char digit : cardnum) {
		  if (!isdigit(digit)) {
			std::cout << "Invalid input. Please enter a numeric credit card number.\n";
			std::cout<<"\n";  
			return; //Exit the function if input is invalid
		  }
	 }

	 // Loop through each digit of the card number from right to left
	 for (int i = cardnum.length() - 1; i >= 0; i--) {
		  int digit = cardnum[i] - '0';

		  // Double every second digit (counting from the right)
		  if ((cardnum.length() - i) % 2 == 0) {
				digit *= 2;

				// If the doubled digit is two digits, split and add them separately
				if (digit > 9) {
					 digit = digit % 10 + digit / 10;
				}
		  }

		  // Add the current digit (original or modified) to the running sum
		  sum += digit;
	 }

	 // Check if the sum is a multiple of 10 and print the result
	 if (sum % 10 == 0){
		  std::cout << cardnum << " is a Valid card number!\n";
		  std::cout<<"\n";
		  }
	 else {
		  std::cout << cardnum <<" is an Invalid card number!\n";
		  std::cout<<"\n";
	 }
}



