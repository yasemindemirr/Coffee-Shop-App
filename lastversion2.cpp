#include <iostream>
#include <string>
#include "windows.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cctype>

using namespace std;
static float total_price = 0;
bool controller;

// Hot drink counter
void countHotDrinks(int filter, int latte, int mocha, int chocolate, int tea, string Nfilter, string Nlatte, string Nmocha, string Nchocolate, string Ntea)
{
	int del = 0;
	int list[5] = { filter, latte, mocha, chocolate, tea }; // price list
	string nameList[5] = { Nfilter, Nlatte, Nmocha, Nchocolate, Ntea }; // to print the variable
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (list[i] > list[j])
			{
				for (int k = 0; k < 5; k++)
				{
					if (list[k] > list[i])
					{
						del++;
						if (del == 1) {
							cout << "	The best selling hot drink is " << nameList[k] << ". Quantity sold is " << list[k] << " unit(s)." << endl;
							cout << endl;
							cout << endl;
							break;
						}
					}
				}
			}
		}
	}
}


// Cold drink counter
void countColdDrinks(int lemonade, int milkshake, int frappe, string Nlemonade, string Nmilkshake, string Nfrappe)
{
	int del = 0;
	int list[3] = { lemonade, milkshake, frappe };
	string nameList[3] = { Nlemonade, Nmilkshake, Nfrappe };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (list[i] > list[j])
			{
				for (int k = 0; k < 3; k++)
				{
					if (list[k] > list[i])
					{
						del++;
						if (del == 1) {
							cout << "	The best selling cold drink is " << nameList[k] << ". Quantity sold is " << list[k] << " unit(s)." << endl;
							cout << endl;
							cout << endl;
							break;
						}
					}
				}
			}
		}
	}
}

// Dessert counter
void countDeserts(int muffin, int brownie, int cheesecake, int magnolia, string Nmuffin, string Nbrownie, string Ncheesecake, string Nmagnolia)
{
	int del = 0;
	int list[4] = { muffin, brownie, cheesecake, magnolia };
	string nameList[4] = { Nmuffin, Nbrownie, Ncheesecake, Nmagnolia };
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (list[i] > list[j])
			{
				for (int k = 0; k < 4; k++)
				{
					if (list[k] > list[i])
					{
						del++;
						if (del == 1) {
							cout << "	The best selling dessert is " << nameList[k] << ". Quantitiy sold is " << list[k] << " unit(s)." << endl;
							cout << endl;
							cout << endl;
							break;
						}
					}
				}
			}
		}
	}
}

float sum_price(float _price) {

	total_price += _price;

	return total_price;
}

float zero_price() {
	total_price = 0;
	return total_price;
}

class Product
{
public:

	string name, type, description;
	float price;
	int counter = 0;
	int stock;


	Product(string _name, string _type, float _price, int _counter, int _stock, string _description = "")
	{
		name = _name;
		type = _type;
		price = _price;
		stock = _stock;
		description = _description;
		counter = _counter;


	}

	void show() {
		cout << name << ": " << price << "$" << "  (" << description << ")" << endl;
	}

	int stock_down(int number_of_times)
	{
		if (stock - number_of_times >= 0)
		{
			stock -= number_of_times;
			controller = true;
			counter += number_of_times;
			return stock;
		}
		else
		{
			cout << "\n\n";
			//Sleep(2000);
			cout << "	  " << name << " is out of stock" << endl;
			cout << "	  Current stock is : " << stock << endl << endl;

			controller = false;

			return 0;
		}

	}

};
class Bitcoin
{
public:

	string address;
	float amount;

};

int main()
{
	// Creating products:
		// Hots;
	Product filter_coffee("Filter Coffee", "Hot Drinks", 2, 0, 50, "Brewed, balanced, dense filter coffee");
	Product latte("Latte", "Hot Drinks", 4, 0, 50, "Balanced blend of rich espresso, steamed velvety milk and milk foam");
	Product mocha("Mocha", "Hot Drinks", 4, 0, 50, "Espresso is served with mocha sauce and steam-heated milk,complete with cream.");
	Product hot_chocolate("Hot Chocolate", "Hot Drinks", 4, 0, 50, "Sweet flavor that emerges when steamed milk meets mocha sauce");
	Product tea("Tea", "Hot Drinks", 2, 0, 50, "Freshly brewed black tea from carefully selected Turkish Tea leaves");

	// Colds;

	Product lemonade("Lemonade", "Cold Drinks", 3, 0, 50, "Lemonade obtained from carefully selected lemons from Mersin");
	Product milkshake("Milkshake", "Cold Drinks", 5, 0, 50, "A drink made with a tremendous harmony of milk, crushed ice, chocolate and various fruits.");
	Product frappe("Frappe", "Cold Drinks", 5, 0, 50, "Greek iced coffee drink made from instant coffee, water, sugar, and milk.");

	// Desserts;

	Product muffin("Muffin", "Desserts", 10, 0, 50, "Belgian Chocolate Muffin. A pleasant meeting of chocolate chips with muffins");
	Product brownie("Brownie", "Desserts", 15, 0, 50, "An indispensable taste with butter and dark chocolate");
	Product cheesecake("Cheesecake", "Desserts", 15, 0, 50, "Cheesecake decorated with a special cheese filling and lemon sauce combined with a biscuit base");
	Product magnolia("Magnolia", "Desserts", 10, 0, 50, "A dessert with banana, cream and sponge cake");
	Product crumble("Crumble with ice cream", "Desserts", 10, 0, 50, "A crumble is a dish that can be made in a sweet or savoury version with ice cream");
	//Cultural Menu Products

//Saturday(Mexico and Japan)
	Product chamoyada("Chamoyada", "Saturday", 15, 0, 50, "Chamoyada is a sweet and spicy Mexican cuisine drink prepared with grated ice and fruits, flavored with chamoy.");
	Product bionico("Bionico", "Saturday", 20, 0, 50, "It is a fruit salad consisting of different fruits chopped into small cubes,soaked in cream and topped with granola, grated coconut, raisins and honey.");
	Product japanese_cheescake("Japanese Cheesecake", "Saturday", 20, 0, 50, "It is also known as souffle-style cheesecake, cotton cheesecake or light cheesecake.");
	Product matcha_tea("Matcha Tea", "Saturday", 10, 0, 50, "Matcha is a ground form of specially grown green tea found in classic Japanese tea ceremonies.");

	//Sunday(India and Spain)
	Product gajor_ka_doodh("Gajor ka Doodh", "Sunday", 25, 0, 50, "A drink prepared with milk,dried nuts, carrots and various spices.");
	Product shahi_tukda("Shahi Tukda", "Sunday", 25, 0, 50, "A traditional syrupy toasted bread dessert of India.");
	Product horchata("Horchata", "Sunday", 15, 0, 50, "A soft drink whose main ingredient is rice and in which there are almonds, dried nuts.");
	Product churros("Churros", "Sunday", 10, 0, 50, "It is a fried dumpling covered with cinnamon and sugar and served.");


	string choice;
	int choice_int;

	// First screen
	//LOG IN PART AND TABLE ENTRY PART
first:

	cout << "\t\t******************************************" << endl;
	cout << "\t\t* \t \t \t \t \t *" << endl;
	cout << "\t\t* \t    WELCOME TO GAEGY \t\t *" << endl;
	cout << "\t\t* \t \t \t \t \t *" << endl;
	cout << "\t\t* \t \t \t \t \t *" << endl;
	cout << "\t\t* \t   coffee and dessert\t	 * " << endl;
	cout << "\t\t* \t \t \t \t \t *" << endl;
	cout << "\t\t******************************************" << endl;
	cout << endl << endl;
	cout << "\t\t A. WHO WE ARE? " << endl;
	cout << "\t\t B. Do you want to call for help?" << endl;
	cout << "\t\t C. Would you like to see ou menu ?" << endl;


	char a = 'z';
	cin >> a;
	char ch = tolower(a);
	switch (ch)
	{
	case 'a':
		cout << "\n";
		cout << "\tWe are studying at Duzce University together on this project as five friends.\n" << endl;
		cout << "\tWe aim for our customers to place orders more quicklyand easilyand to reach us more easily." << endl;
		cout << "\tIn this way, we aim to reduce the workload of our employeesand increase their productivity.\n" << endl;
		cout << "\tGorkem participated by categorizing and promoting the products on our menu." << endl;
		cout << "\tIn addition, he made the current price total, stock decreaseand added the product number" << endl << "\tselection in the product purchase." << endl;
		cout << "\t\n\tYasemin Kultur added products to our menu with explanation. Next, a feedback box has been added. " << endl;
		cout << "\tShe made the user login and report preparation created by Yasemin and Gizem. " << endl;
		cout << "\t\n\tGizem created the table number entry, the about section, the call-to-duty section and the web page." << endl << "\tShe also prepared the presentation." << endl;
		cout << "\t\n\tEfrail made the definition of bestsellers, discounted products and coupons." << endl << "\tAreefa made the payment methods and the remaining products part." << endl;
		cout << endl << endl << endl;
		break;

	case 'b':
		cout << "\t\t We will refer a friend to you to assist you. Thank you for your understanding." << endl;
		break;
	}

	// Day choice
	string day;
	while (true) {
		cout << endl << endl;
		cout << "What day is it today?\n\n";
		cout << "[1]Monday\n";
		cout << "[2]Tuesday\n";
		cout << "[3]Wednesday\n";
		cout << "[4]Thursday\n";
		cout << "[5]Friday\n";
		cout << "[6]Saturday\n";
		cout << "[7]Sunday\n";
		cout << "\nSelect the number of today: ";
		cin >> day;
		cout << endl;
		if (day == "1" || day == "2" || day == "3" || day == "4" || day == "5" || day == "6" || day == "7") {
			break;
		}
		else {
			cout << "\nInvalid choice!\n\n";
			continue;
		}
	};

	while (true)
	{
		cout << "***   		  Menu		   ***" << endl << endl;

		cout << "	  1) Hot Drinks" << endl;
		cout << "	  2) Cold Drinks" << endl;
		cout << "	  3) Desserts" << endl;
		cout << "	  4) Cultural Products" << endl;
		cout << "	  5) Feed back to us!" << endl;
		cout << "Choice: ";
		cin >> choice;
		cout << endl;


		if (choice == "1")
		{
			cout << "	  1)"; filter_coffee.show();
			cout << "	  2)"; latte.show();
			cout << "	  3)"; mocha.show();
			cout << "	  4)"; hot_chocolate.show();
			cout << "	  5)"; tea.show();
			cout << endl;

			cout << "Select one : ";
			cin >> choice;

			if (choice == "1")
			{
				cout << "\n How many: ";
				cin >> choice_int;
				cout << endl;
				cout << "\n	  product is adding...\n" << endl;
				filter_coffee.stock_down(choice_int);
				//Sleep(2000);

				// Discount or price
				if (controller == true && day == "1")
				{
					sum_price(choice_int * filter_coffee.price * 0.9);
					cout << " Today is the day of discount on hot drinks.\n";
					//Sleep(2000);
					cout << "\n	  Total price is: " << total_price << "$\n\n" << endl;
				}
				else if (controller == true)
				{
					sum_price(choice_int * filter_coffee.price);
					cout << "\n	  Total price is: " << total_price << "$\n\n" << endl;
				}

				//Sleep(1000);

				// Best selling for hot drink
				cout << "___________________________________________________" << endl;
				cout << endl;
				cout << endl;
				countHotDrinks(filter_coffee.counter, latte.counter, mocha.counter, hot_chocolate.counter, tea.counter, filter_coffee.name, latte.name, mocha.name, hot_chocolate.name, tea.name);

				cout << "Will you continue with the order (1) or proceed to the payment part? (2): ";
				cin >> choice;
				cout << endl;

				if (choice == "1")
				{
					//Sleep(1000);
					continue;
				}
				else if (choice == "2")
				{

					cout << "\t\t1.Would you like to have a seat?" << endl;
					cout << "\t\t2.Would you like to order takeout?" << endl;
					cout << "\t\t please choose one of the option !" << endl;
					int ga;
					cin >> ga;
					if (ga == 1)
					{
						cout << "\tPlease enter the table number you will sit at" << endl;
						int tablenumber;
						cin >> tablenumber;

					}
					else if (ga == 2)
					{
						cout << "\t 1.Please login as a user." << endl;
						cout << "\t 2.If you are not a member, register." << endl;
						cout << "Please choose 1 or 2" << endl;


						string username;
						int systempassword = 123;
						int g;
						cin >> g;
						if (g == 1)
						{
							string username;
							int password;
							cout << "Please enter your user name" << endl;
							cin >> username;
							cout << "The password that gives you from the system: ";
							cout << systempassword;
							cout << endl;
							cout << "Membership successfully completed, please log in" << endl << endl;
							goto first;
						}
						else if (g == 2)
						{
							cout << "\nPlase enter your user name" << endl;
							cin >> username;
							cout << "Dear " << username << " ," << endl;
							cout << "Welcome back again\n " << endl;

							int trying = 3;
						loop1:
							//Asking for determined password from user
							int testingPassword;
							cout << "Please enter password: " << endl;
							cin >> testingPassword;
							if (testingPassword == systempassword) {
								cout << "Dear " << username << "," << endl;

							}
							else if (trying == 1) {
								cout << "\nPassword is wrong. You have no trials to try. get new password.....\n";
								cout << "\nEnter 1 or 2!\n " << endl;
								goto first;
							}
							else {
								cout << "Password is wrong. You have " << trying - 1 << " trials to left..." << endl;
								trying--;
								goto loop1;
								return 0;
							}

						}
						else
						{
							cout << "\nInvalid number! Enter 1 or 2!\n " << endl;
							goto first;
						}
					}
					// Ask for payment method
					cout << "\n		Please select a payment method:\n" << endl;
					cout << "			1) Credit card" << endl;
					cout << "			2) Debit card" << endl;
					cout << "			3) Cash" << endl;
					cout << "			4) Bitcoin" << endl;
					cout << "			5) Cancel\n" << endl;
					cout << "			Choice: ";
					cin >> choice;
					cout << endl;

					// Process payment based on the selected method
					if (choice == "1" || choice == "2") {
						string cardNumber, cardExpiry, cardCVV;
						cout << "			Please enter your card number: ";
						cin >> cardNumber;
						cout << "			Please enter your card expiry date (MM/YY): ";
						cin >> cardExpiry;
						cout << "			Please enter your card CVV: ";
						cin >> cardCVV;

						// Process payment using a payment gateway or API
						// ...

						// Confirm payment
						cout << "			Payment confirmed. Thank you for your purchase!\n" << endl;
						cout << "           Hope to see you soon!" << endl;
					}
					else if (choice == "3") {
						double cashPaid;
						do {
							cout << "			Please enter the amount of cash paid: ";
							cin >> cashPaid;
						} while (cashPaid < total_price); // Make sure enough cash is paid

						// Calculate change
						double change = cashPaid - total_price;

						// Print receipt
						cout << "			Receipt:\n";
						cout << "			---------------------------\n";
						cout << "			Total: " << total_price << "$\n";
						cout << "			Paid: " << cashPaid << "$\n";
						cout << "			Change: " << change << "$\n";
						cout << "			---------------------------\n";

						// Confirm payment
						cout << "			Payment confirmed. Thank you for your purchase!\n" << endl;
						cout << "           Hope to see you soon!" << endl;
					}
					else if (choice == "4") {
						Bitcoin bitcoin;
						cout << "Please enter your Bitcoin address: ";
						cin >> bitcoin.address;
						cout << "Please enter the amount of Bitcoin to be paid: ";
						cin >> bitcoin.amount;

						// Process payment using a Bitcoin payment gateway or API
						// ...

						// Confirm payment
						cout << "Payment confirmed. Thank you for your purchase!\n" << endl;
						cout << " Hope to see you soon!" << endl;

					}
					else if (choice == "5") {
						cout << "			Payment cancelled. Order cancelled.\n" << endl;
						cout << "           Hope to see you soon!" << endl;
						continue;
					}
					else {
						cout << "			Invalid choice. Order cancelled.\n" << endl;
						continue;
					}
					break;
					zero_price();
					continue;
				}
				else
				{
					cout << "Please select 1 or 2" << endl;
					continue;
				}
			}
			else if (choice == "2")
			{
				cout << "\n How many: ";
				cin >> choice_int;
				cout << endl;
				cout << "\n	  product is adding..." << endl;
				latte.stock_down(choice_int);
				//Sleep(2000);

				// Discount or price
				if (controller == true && day == "1")
				{
					sum_price(choice_int * latte.price * 0.9);
					cout << " Today is the day of discount on hot drinks.\n";
					cout << "\n	  Total price is: " << total_price << "$\n\n" << endl;
				}
				else if (controller == true)
				{
					sum_price(choice_int * latte.price);
					cout << "\n	  Total price is: " << total_price << "$\n\n" << endl;
				}

				//Sleep(1000);

				// Best selling for hot drink
				cout << "___________________________________________________" << endl;
				cout << endl;
				cout << endl;
				countHotDrinks(filter_coffee.counter, latte.counter, mocha.counter, hot_chocolate.counter, tea.counter, filter_coffee.name, latte.name, mocha.name, hot_chocolate.name, tea.name);



				cout << "Will you continue with the order (1) or proceed to the payment part? (2): ";
				cin >> choice;
				cout << endl;

				if (choice == "1")
				{
					//Sleep(1000);
					continue;
				}
				else if (choice == "2")
				{

					cout << "\t\t1.Would you like to have a seat?" << endl;
					cout << "\t\t2.Would you like to order takeout?" << endl;
					cout << "\t\t please choose one of the option !" << endl;
					int ga;
					cin >> ga;
					if (ga == 1)
					{
						cout << "\tPlease enter the table number you will sit at" << endl;
						int tablenumber;
						cin >> tablenumber;
					}
					else if (ga == 2)
					{
						cout << "\t 1.Please login as a user." << endl;
						cout << "\t 2.If you are not a member, register." << endl;
						cout << "Please choose 1 or 2" << endl;


						string username;
						int systempassword = 123;
						int g;
						cin >> g;
						if (g == 1)
						{
							string username;
							int password;
							cout << "Please enter your user name" << endl;
							cin >> username;
							cout << "The password that gives you from the system: ";
							cout << systempassword;
							cout << endl;
							cout << "Membership successfully completed, please log in" << endl << endl;
							goto first;
						}
						else if (g == 2)
						{
							cout << "\nPlase enter your user name" << endl;
							cin >> username;
							cout << "Dear " << username << " ," << endl;
							cout << "Welcome back again\n " << endl;

							int trying = 3;
						loop2:
							//Asking for determined password from user
							int testingPassword;
							cout << "Please enter password: " << endl;
							cin >> testingPassword;
							if (testingPassword == systempassword) {
								cout << "Dear " << username << "," << endl;

							}
							else if (trying == 1) {
								cout << "\nPassword is wrong. You have no trials to try. get new password.....\n";
								cout << "\nEnter 1 or 2!\n " << endl;
								goto first;
							}
							else {
								cout << "Password is wrong. You have " << trying - 1 << " trials to left..." << endl;
								trying--;
								goto loop2;
								return 0;
							}

						}
						else
						{
							cout << "\nInvalid number! Enter 1 or 2!\n " << endl;
							goto first;
						}
					}

					// Ask for payment method
					cout << "\n		Please select a payment method:" << endl;
					cout << "			1) Credit card" << endl;
					cout << "			2) Debit card" << endl;
					cout << "			3) Cash" << endl;
					cout << "			4) Bitcoin" << endl;
					cout << "			5) Cancel" << endl;
					cout << "			Choice: ";
					cin >> choice;
					cout << endl;

					// Process payment based on the selected method
					if (choice == "1" || choice == "2") {
						string cardNumber, cardExpiry, cardCVV;
						cout << "			Please enter your card number: ";
						cin >> cardNumber;
						cout << "			Please enter your card expiry date (MM/YY): ";
						cin >> cardExpiry;
						cout << "			Please enter your card CVV: ";
						cin >> cardCVV;

						// Process payment using a payment gateway or API
						// ...

						// Confirm payment
						cout << "			Payment confirmed. Thank you for your purchase!\n" << endl;
						cout << "           Hope to see you soon!" << endl;
					}
					else if (choice == "3") {
						double cashPaid;
						do {
							cout << "			Please enter the amount of cash paid: ";
							cin >> cashPaid;
						} while (cashPaid < total_price); // Make sure enough cash is paid

						// Calculate change
						double change = cashPaid - total_price;

						// Print receipt
						cout << "			Receipt:\n";
						cout << "			---------------------------\n";
						cout << "			Total: " << total_price << "$\n";
						cout << "			Paid: " << cashPaid << "$\n";
						cout << "			Change: " << change << "$\n";
						cout << "			---------------------------\n";

						// Confirm payment
						cout << "			Payment confirmed. Thank you for your purchase!\n" << endl;
						cout << "           Hope to see you soon!" << endl;
					}
					else if (choice == "4") {
						Bitcoin bitcoin;
						cout << "Please enter your Bitcoin address: ";
						cin >> bitcoin.address;
						cout << "Please enter the amount of Bitcoin to be paid: ";
						cin >> bitcoin.amount;

						// Process payment using a Bitcoin payment gateway or API
						// ...

						// Confirm payment
						cout << "Payment confirmed. Thank you for your purchase!\n" << endl;
						cout << "Hope to see you soon!" << endl;
					}
					else if (choice == "5") {
						cout << "			Payment cancelled. Order cancelled.\n" << endl;
						continue;
					}
					else {
						cout << "			Invalid choice. Order cancelled.\n" << endl;
						continue;
					}
					break;
					zero_price();
					continue;
				}
				else
				{
					cout << "Please select 1 or 2" << endl;
					continue;
				}
			}
			else if (choice == "3")
			{
				cout << "\n How many: ";
				cin >> choice_int;
				cout << endl;
				cout << "\n	  product is adding..." << endl;
				mocha.stock_down(choice_int);
				//Sleep(2000);

				// Discount or price
				if (controller == true && day == "1")
				{
					sum_price(choice_int * mocha.price * 0.9);
					cout << " Today is the day of discount on hot drinks.\n";
					cout << "\n	  Total price is: " << total_price << "$\n\n" << endl;
				}
				else if (controller == true)
				{
					sum_price(choice_int * mocha.price);
					cout << "\n	  Total price is: " << total_price << "$\n\n" << endl;
				}

				//Sleep(1000);

				// Best selling for hot drink
				cout << "___________________________________________________" << endl;
				cout << endl;
				cout << endl;
				countHotDrinks(filter_coffee.counter, latte.counter, mocha.counter, hot_chocolate.counter, tea.counter, filter_coffee.name, latte.name, mocha.name, hot_chocolate.name, tea.name);

				cout << "Will you continue with the order (1) or proceed to the payment part? (2): ";
				cin >> choice;
				cout << endl;

				if (choice == "1")
				{
					//Sleep(1000);
					continue;
				}
				else if (choice == "2")
				{

					cout << "\t\t1.Would you like to have a seat?" << endl;
					cout << "\t\t2.Would you like to order takeout?" << endl;
					cout << "\t\t please choose one of the option !" << endl;
					int ga;
					cin >> ga;
					if (ga == 1)
					{
						cout << "\tPlease enter the table number you will sit at" << endl;
						int tablenumber;
						cin >> tablenumber;
					}
					else if (ga == 2)
					{
						cout << "\t 1.Please login as a user." << endl;
						cout << "\t 2.If you are not a member, register." << endl;
						cout << "Please choose 1 or 2" << endl;


						string username;
						int systempassword = 123;
						int g;
						cin >> g;
						if (g == 1)
						{
							string username;
							int password;
							cout << "Please enter your user name" << endl;
							cin >> username;
							cout << "The password that gives you from the system: ";
							cout << systempassword;
							cout << endl;
							cout << "Membership successfully completed, please log in" << endl << endl;
							goto first;
						}
						else if (g == 2)
						{
							cout << "\nPlase enter your user name" << endl;
							cin >> username;
							cout << "Dear " << username << " ," << endl;
							cout << "Welcome back again\n " << endl;

							int trying = 3;
						loop3:
							//Asking for determined password from user
							int testingPassword;
							cout << "Please enter password: " << endl;
							cin >> testingPassword;
							if (testingPassword == systempassword) {
								cout << "Dear " << username << "," << endl;

							}
							else if (trying == 1) {
								cout << "\nPassword is wrong. You have no trials to try. get new password.....\n";
								cout << "\nEnter 1 or 2!\n " << endl;
								goto first;
							}
							else {
								cout << "Password is wrong. You have " << trying - 1 << " trials to left..." << endl;
								trying--;
								goto loop3;
								return 0;
							}

						}
						else
						{
							cout << "\nInvalid number! Enter 1 or 2!\n " << endl;
							goto first;
						}
					}

					// Ask for payment method
					cout << "\n		Please select a payment method:" << endl;
					cout << "			1) Credit card" << endl;
					cout << "			2) Debit card" << endl;
					cout << "			3) Cash" << endl;
					cout << "			4) Bitcoin" << endl;
					cout << "			5) Cancel" << endl;
					cout << "			Choice: ";
					cin >> choice;
					cout << endl;

					// Process payment based on the selected method
					if (choice == "1" || choice == "2") {
						string cardNumber, cardExpiry, cardCVV;
						cout << "			Please enter your card number: ";
						cin >> cardNumber;
						cout << "			Please enter your card expiry date (MM/YY): ";
						cin >> cardExpiry;
						cout << "			Please enter your card CVV: ";
						cin >> cardCVV;

						// Process payment using a payment gateway or API
						// ...

						// Confirm payment
						cout << "			Payment confirmed. Thank you for your purchase!\n" << endl;
						cout << "           Hope to see you soon!" << endl;
					}
					else if (choice == "3") {
						double cashPaid;
						do {
							cout << "			Please enter the amount of cash paid: ";
							cin >> cashPaid;
						} while (cashPaid < total_price); // Make sure enough cash is paid

						// Calculate change
						double change = cashPaid - total_price;

						// Print receipt
						cout << "			Receipt:\n";
						cout << "			---------------------------\n";
						cout << "			Total: " << total_price << "$\n";
						cout << "			Paid: " << cashPaid << "$\n";
						cout << "			Change: " << change << "$\n";
						cout << "			---------------------------\n";

						// Confirm payment
						cout << "			Payment confirmed. Thank you for your purchase!\n" << endl;
						cout << "           Hope to see you soon!" << endl;
					}
					else if (choice == "4") {
						Bitcoin bitcoin;
						cout << "Please enter your Bitcoin address: ";
						cin >> bitcoin.address;
						cout << "Please enter the amount of Bitcoin to be paid: ";
						cin >> bitcoin.amount;

						// Process payment using a Bitcoin payment gateway or API
						// ...

						// Confirm payment
						cout << "Payment confirmed. Thank you for your purchase!\n" << endl;
						cout << "Hope to see you soon!" << endl;
					}
					else if (choice == "5") {
						cout << "			Payment cancelled. Order cancelled.\n" << endl;

						continue;
					}
					else {
						cout << "			Invalid choice. Order cancelled.\n" << endl;
						continue;
					}
					break;
					zero_price();
					continue;
				}
				else
				{
					cout << "Please select 1 or 2" << endl;
					continue;
				}
			}
			else if (choice == "4")
			{

				cout << "\n How many: ";
				cin >> choice_int;
				cout << endl;
				cout << "\n	  product is adding..." << endl;
				hot_chocolate.stock_down(choice_int);
				//Sleep(2000);

				// Discount or price
				if (controller == true && day == "1")
				{
					sum_price(choice_int * hot_chocolate.price * 0.9);
					cout << " Today is the day of discount on hot drinks.!\n";
					cout << "\n	  Total price is: " << total_price << "$\n\n" << endl;
				}
				else if (controller == true)
				{
					sum_price(choice_int * hot_chocolate.price);
					cout << "\n	  Total price is: " << total_price << "$\n\n" << endl;


					//Sleep(1000);

					// Best selling for hot drink
					cout << "___________________________________________________" << endl;
					cout << endl;
					cout << endl;
					countHotDrinks(filter_coffee.counter, latte.counter, mocha.counter, hot_chocolate.counter, tea.counter, filter_coffee.name, latte.name, mocha.name, hot_chocolate.name, tea.name);

					cout << "Will you continue with the order (1) or proceed to the payment part? (2): ";
					cin >> choice;
					cout << endl;

					if (choice == "1")
					{
						//Sleep(1000);
						continue;
					}
					else if (choice == "2")
					{

						cout << "\t\t1.Would you like to have a seat?" << endl;
						cout << "\t\t2.Would you like to order takeout?" << endl;
						cout << "\t\t please choose one of the option !" << endl;
						int ga;
						cin >> ga;
						if (ga == 1)
						{
							cout << "\tPlease enter the table number you will sit at" << endl;
							int tablenumber;
							cin >> tablenumber;
						}
						else if (ga == 2)
						{
							cout << "\t 1.Please login as a user." << endl;
							cout << "\t 2.If you are not a member, register." << endl;
							cout << "Please choose 1 or 2" << endl;


							string username;
							int systempassword = 123;
							int g;
							cin >> g;
							if (g == 1)
							{
								string username;
								int password;
								cout << "Please enter your user name" << endl;
								cin >> username;
								cout << "The password that gives you from the system: ";
								cout << systempassword;
								cout << endl;
								cout << "Membership successfully completed, please log in" << endl << endl;
								goto first;
							}
							else if (g == 2)
							{
								cout << "\nPlase enter your user name" << endl;
								cin >> username;
								cout << "Dear " << username << " ," << endl;
								cout << "Welcome back again\n " << endl;

								int trying = 3;
							loop4:
								//Asking for determined password from user
								int testingPassword;
								cout << "Please enter password: " << endl;
								cin >> testingPassword;
								if (testingPassword == systempassword) {
									cout << "Dear " << username << "," << endl;

								}
								else if (trying == 1) {
									cout << "\nPassword is wrong. You have no trials to try. get new password.....\n";
									cout << "\nEnter 1 or 2!\n " << endl;
									goto first;
								}
								else {
									cout << "Password is wrong. You have " << trying - 1 << " trials to left..." << endl;
									trying--;
									goto loop4;
									return 0;
								}

							}
							else
							{
								cout << "\nInvalid number! Enter 1 or 2!\n " << endl;
								goto first;
							}
						}

						// Ask for payment method
						cout << "\n		Please select a payment method:" << endl;
						cout << "			1) Credit card" << endl;
						cout << "			2) Debit card" << endl;
						cout << "			3) Cash" << endl;
						cout << "			4) Bitcoin" << endl;
						cout << "			5) Cancel" << endl;
						cout << "			Choice: ";
						cin >> choice;
						cout << endl;

						// Process payment based on the selected method
						if (choice == "1" || choice == "2") {
							string cardNumber, cardExpiry, cardCVV;
							cout << "			Please enter your card number: ";
							cin >> cardNumber;
							cout << "			Please enter your card expiry date (MM/YY): ";
							cin >> cardExpiry;
							cout << "			Please enter your card CVV: ";
							cin >> cardCVV;

							// Process payment using a payment gateway or API
							// ...

							// Confirm payment
							cout << "			Payment confirmed. Thank you for your purchase!\n" << endl;
							cout << "           Hope to see you soon!" << endl;
						}
						else if (choice == "3") {
							double cashPaid;
							do {
								cout << "			Please enter the amount of cash paid: ";
								cin >> cashPaid;
							} while (cashPaid < total_price); // Make sure enough cash is paid

							// Calculate change
							double change = cashPaid - total_price;

							// Print receipt
							cout << "			Receipt:\n";
							cout << "			---------------------------\n";
							cout << "			Total: " << total_price << "$\n";
							cout << "			Paid: " << cashPaid << "$\n";
							cout << "			Change: " << change << "$\n";
							cout << "			---------------------------\n";

							// Confirm payment
							cout << "			Payment confirmed. Thank you for your purchase!\n" << endl;
							cout << "           Hope to see you soon!" << endl;
						}
						else if (choice == "4") {
							Bitcoin bitcoin;
							cout << "Please enter your Bitcoin address: ";
							cin >> bitcoin.address;
							cout << "Please enter the amount of Bitcoin to be paid: ";
							cin >> bitcoin.amount;

							// Process payment using a Bitcoin payment gateway or API
							// ...

							// Confirm payment
							cout << "Payment confirmed. Thank you for your purchase!\n" << endl;
							cout << "Hope to see you soon!" << endl;
						}
						else if (choice == "5") {
							cout << "			Payment cancelled. Order cancelled.\n" << endl;
							continue;
						}
						else {
							cout << "			Invalid choice. Order cancelled.\n" << endl;
							continue;
						}
						break;
						zero_price();
						continue;
					}
					else
					{
						cout << "Please select 1 or 2" << endl;
						continue;
					}
				}
			}
			else if (choice == "5")
			{
				cout << "\n How many: ";
				cin >> choice_int;
				cout << endl;
				cout << "\n	  product is adding..." << endl;
				tea.stock_down(choice_int);
				//Sleep(2000);

				// Discount or price
				if (controller == true && day == "1")
				{
					sum_price(choice_int * tea.price * 0.9);
					cout << " Today is the day of discount on hot drinks.\n";
					cout << "\n	  Total price is: " << total_price << "$\n\n" << endl;
				}
				else if (controller == true)
				{
					sum_price(choice_int * tea.price);
					cout << "\n	  Total price is: " << total_price << "$\n\n" << endl;
				}

				//Sleep(1000);

				// Best selling for hot drink
				cout << "___________________________________________________\n\n" << endl;
				countHotDrinks(filter_coffee.counter, latte.counter, mocha.counter, hot_chocolate.counter, tea.counter, filter_coffee.name, latte.name, mocha.name, hot_chocolate.name, tea.name);

				cout << "Will you continue with the order (1) or proceed to the payment part? (2): ";
				cin >> choice;
				cout << endl;

				if (choice == "1")
				{
					//Sleep(1000);
					continue;
				}
				else if (choice == "2")
				{

					cout << "\t\t1.Would you like to have a seat?" << endl;
					cout << "\t\t2.Would you like to order takeout?" << endl;
					cout << "\t\t please choose one of the option !" << endl;
					int ga;
					cin >> ga;
					if (ga == 1)
					{
						cout << "\tPlease enter the table number you will sit at" << endl;
						int tablenumber;
						cin >> tablenumber;
					}
					else if (ga == 2)
					{
						cout << "\t 1.Please login as a user." << endl;
						cout << "\t 2.If you are not a member, register." << endl;
						cout << "Please choose 1 or 2" << endl;


						string username;
						int systempassword = 123;
						int g;
						cin >> g;
						if (g == 1)
						{
							string username;
							int password;
							cout << "Please enter your user name" << endl;
							cin >> username;
							cout << "The password that gives you from the system: ";
							cout << systempassword;
							cout << endl;
							cout << "Membership successfully completed, please log in" << endl << endl;
							goto first;
						}
						else if (g == 2)
						{
							cout << "\nPlase enter your user name" << endl;
							cin >> username;
							cout << "Dear " << username << " ," << endl;
							cout << "Welcome back again\n " << endl;

							int trying = 3;
						loop5:
							//Asking for determined password from user
							int testingPassword;
							cout << "Please enter password: " << endl;
							cin >> testingPassword;
							if (testingPassword == systempassword) {
								cout << "Dear " << username << "," << endl;

							}
							else if (trying == 1) {
								cout << "\nPassword is wrong. You have no trials to try. get new password.....\n";
								cout << "\nEnter 1 or 2!\n " << endl;
								goto first;
							}
							else {
								cout << "Password is wrong. You have " << trying - 1 << " trials to left..." << endl;
								trying--;
								goto loop5;
								return 0;
							}

						}
						else
						{
							cout << "\nInvalid number! Enter 1 or 2!\n " << endl;
							goto first;
						}
					}

					// Ask for payment method
					cout << "\n		Please select a payment method:" << endl;
					cout << "			1) Credit card" << endl;
					cout << "			2) Debit card" << endl;
					cout << "			3) Cash" << endl;
					cout << "			4) Bitcoin" << endl;
					cout << "			5) Cancel" << endl;
					cout << "			Choice: ";
					cin >> choice;
					cout << endl;

					// Process payment based on the selected method
					if (choice == "1" || choice == "2") {
						string cardNumber, cardExpiry, cardCVV;
						cout << "			Please enter your card number: ";
						cin >> cardNumber;
						cout << "			Please enter your card expiry date (MM/YY): ";
						cin >> cardExpiry;
						cout << "			Please enter your card CVV: ";
						cin >> cardCVV;

						// Process payment using a payment gateway or API
						// ...

						// Confirm payment
						cout << "			Payment confirmed. Thank you for your purchase!\n" << endl;
						cout << "           Hope to see you soon!" << endl;
					}
					else if (choice == "3") {
						double cashPaid;
						do {
							cout << "			Please enter the amount of cash paid: ";
							cin >> cashPaid;
						} while (cashPaid < total_price); // Make sure enough cash is paid

						// Calculate change
						double change = cashPaid - total_price;

						// Print receipt
						cout << "			Receipt:\n";
						cout << "			---------------------------\n";
						cout << "			Total: " << total_price << "$\n";
						cout << "			Paid: " << cashPaid << "$\n";
						cout << "			Change: " << change << "$\n";
						cout << "			---------------------------\n";

						// Confirm payment
						cout << "			Payment confirmed. Thank you for your purchase!\n" << endl;
						cout << "           Hope to see you soon!" << endl;
					}
					else if (choice == "4") {
						Bitcoin bitcoin;
						cout << "Please enter your Bitcoin address: ";
						cin >> bitcoin.address;
						cout << "Please enter the amount of Bitcoin to be paid: ";
						cin >> bitcoin.amount;

						// Process payment using a Bitcoin payment gateway or API
						// ...

						// Confirm payment
						cout << "Payment confirmed. Thank you for your purchase!\n" << endl;
						cout << "Hope to see you soon!" << endl;
					}
					else if (choice == "5") {
						cout << "			Payment cancelled. Order cancelled.\n" << endl;
						continue;
					}
					else {
						cout << "			Invalid choice. Order cancelled.\n" << endl;
						continue;
					}
					break;
					zero_price();
					continue;
				}
				else
				{
					cout << "Please select 1 or 2" << endl;
					continue;
				}
			}

		}
		else if (choice == "2")
		{
			cout << "	  1)"; lemonade.show();
			cout << "	  2)"; milkshake.show();
			cout << "	  3)"; frappe.show();
			cout << endl;

			cout << "Select one : ";
			cin >> choice;

			if (choice == "1")
			{
				cout << "\n How many: ";
				cin >> choice_int;
				cout << endl;
				cout << "\n	  product is adding..." << endl;
				lemonade.stock_down(choice_int);
				//Sleep(2000);

				// Discount or price
				if (controller == true && day == "4")
				{
					sum_price(choice_int * lemonade.price * 0.9);
					cout << " Today is the day of discount on cold drinks.\n";
					cout << "\n	  Total price is: " << total_price << "$\n\n" << endl;
				}
				else if (controller == true)
				{
					sum_price(choice_int * lemonade.price);
					cout << "\n	  Total price is: " << total_price << "$\n\n" << endl;
				}

				//Sleep(1000);

				// Best selling for cold drink
				cout << "___________________________________________________\n\n" << endl;
				countColdDrinks(lemonade.counter, milkshake.counter, frappe.counter, lemonade.name, milkshake.name, frappe.name);


				cout << "Will you continue with the order (1) or proceed to the payment part? (2): ";
				cin >> choice;
				cout << endl;

				if (choice == "1")
				{
					//Sleep(1000);
					continue;
				}
				else if (choice == "2")
				{

					cout << "\t\t1.Would you like to have a seat?" << endl;
					cout << "\t\t2.Would you like to order takeout?" << endl;
					cout << "\t\t please choose one of the option !" << endl;
					int ga;
					cin >> ga;
					if (ga == 1)
					{
						cout << "\tPlease enter the table number you will sit at" << endl;
						int tablenumber;
						cin >> tablenumber;
					}
					else if (ga == 2)
					{
						cout << "\t 1.Please login as a user." << endl;
						cout << "\t 2.If you are not a member, register." << endl;
						cout << "Please choose 1 or 2" << endl;


						string username;
						int systempassword = 123;
						int g;
						cin >> g;
						if (g == 1)
						{
							string username;
							int password;
							cout << "Please enter your user name" << endl;
							cin >> username;
							cout << "The password that gives you from the system: ";
							cout << systempassword;
							cout << endl;
							cout << "Membership successfully completed, please log in" << endl << endl;
							goto first;
						}
						else if (g == 2)
						{
							cout << "\nPlase enter your user name" << endl;
							cin >> username;
							cout << "Dear " << username << " ," << endl;
							cout << "Welcome back again\n " << endl;

							int trying = 3;
						loop6:
							//Asking for determined password from user
							int testingPassword;
							cout << "Please enter password: " << endl;
							cin >> testingPassword;
							if (testingPassword == systempassword) {
								cout << "Dear " << username << "," << endl;

							}
							else if (trying == 1) {
								cout << "\nPassword is wrong. You have no trials to try. get new password.....\n";
								cout << "\nEnter 1 or 2!\n " << endl;
								goto first;
							}
							else {
								cout << "Password is wrong. You have " << trying - 1 << " trials to left..." << endl;
								trying--;
								goto loop6;
								return 0;
							}

						}
						else
						{
							cout << "\nInvalid number! Enter 1 or 2!\n " << endl;
							goto first;
						}
					}

					// Ask for payment method
					cout << "\n		Please select a payment method:" << endl;
					cout << "			1) Credit card" << endl;
					cout << "			2) Debit card" << endl;
					cout << "			3) Cash" << endl;
					cout << "			4) Bitcoin" << endl;
					cout << "			5) Cancel" << endl;
					cout << "			Choice: ";
					cin >> choice;
					cout << endl;

					// Process payment based on the selected method
					if (choice == "1" || choice == "2") {
						string cardNumber, cardExpiry, cardCVV;
						cout << "			Please enter your card number: ";
						cin >> cardNumber;
						cout << "			Please enter your card expiry date (MM/YY): ";
						cin >> cardExpiry;
						cout << "			Please enter your card CVV: ";
						cin >> cardCVV;

						// Process payment using a payment gateway or API
						// ...

						// Confirm payment
						cout << "			Payment confirmed. Thank you for your purchase!\n" << endl;
						cout << "           Hope to see you soon!" << endl;
					}
					else if (choice == "3") {
						double cashPaid;
						do {
							cout << "			Please enter the amount of cash paid: ";
							cin >> cashPaid;
						} while (cashPaid < total_price); // Make sure enough cash is paid

						// Calculate change
						double change = cashPaid - total_price;

						// Print receipt
						cout << "			Receipt:\n";
						cout << "			---------------------------\n";
						cout << "			Total: " << total_price << "$\n";
						cout << "			Paid: " << cashPaid << "$\n";
						cout << "			Change: " << change << "$\n";
						cout << "			---------------------------\n";

						// Confirm payment
						cout << "			Payment confirmed. Thank you for your purchase!\n" << endl;
						cout << "           Hope to see you soon!" << endl;
					}
					else if (choice == "4") {
						Bitcoin bitcoin;
						cout << "Please enter your Bitcoin address: ";
						cin >> bitcoin.address;
						cout << "Please enter the amount of Bitcoin to be paid: ";
						cin >> bitcoin.amount;

						// Process payment using a Bitcoin payment gateway or API
						// ...

						// Confirm payment
						cout << "Payment confirmed. Thank you for your purchase!\n" << endl;
						cout << "Hope to see you soon!" << endl;
					}
					else if (choice == "5") {
						cout << "			Payment cancelled. Order cancelled.\n" << endl;
						continue;
					}
					else {
						cout << "			Invalid choice. Order cancelled.\n" << endl;
						continue;
					}
					break;
					zero_price();
					continue;
				}
				else
				{
					cout << "Please select 1 or 2" << endl;
					continue;
				}
			}
			else if (choice == "2")
			{
				cout << "\n How many: ";
				cin >> choice_int;
				cout << endl;
				cout << "\n	  product is adding..." << endl;
				milkshake.stock_down(choice_int);
				//Sleep(2000);

				// Discount or price
				if (controller == true && day == "4")
				{
					sum_price(choice_int * milkshake.price * 0.9);
					cout << " Today is the day of discount on cold drinks.\n";
					cout << "\n	  Total price is: " << total_price << "$\n\n" << endl;
				}
				else if (controller == true)
				{
					sum_price(choice_int * milkshake.price);
					cout << "\n	  Total price is: " << total_price << "$\n\n" << endl;
				}

				//Sleep(1000);

				// Best selling for cold drink
				cout << "___________________________________________________\n\n" << endl;
				countColdDrinks(lemonade.counter, milkshake.counter, frappe.counter, lemonade.name, milkshake.name, frappe.name);


				cout << "Will you continue with the order (1) or proceed to the payment part? (2): ";
				cin >> choice;
				cout << endl;

				if (choice == "1")
				{
					//Sleep(1000);
					continue;
				}
				else if (choice == "2")
				{

					cout << "\t\t1.Would you like to have a seat?" << endl;
					cout << "\t\t2.Would you like to order takeout?" << endl;
					cout << "\t\t please choose one of the option !" << endl;
					int ga;
					cin >> ga;
					if (ga == 1)
					{
						cout << "\tPlease enter the table number you will sit at" << endl;
						int tablenumber;
						cin >> tablenumber;
					}
					else if (ga == 2)
					{
						cout << "\t 1.Please login as a user." << endl;
						cout << "\t 2.If you are not a member, register." << endl;
						cout << "Please choose 1 or 2" << endl;


						string username;
						int systempassword = 123;
						int g;
						cin >> g;
						if (g == 1)
						{
							string username;
							int password;
							cout << "Please enter your user name" << endl;
							cin >> username;
							cout << "The password that gives you from the system: ";
							cout << systempassword;
							cout << endl;
							cout << "Membership successfully completed, please log in" << endl << endl;
							goto first;
						}
						else if (g == 2)
						{
							cout << "\nPlase enter your user name" << endl;
							cin >> username;
							cout << "Dear " << username << " ," << endl;
							cout << "Welcome back again\n " << endl;

							int trying = 3;
						loop7:
							//Asking for determined password from user
							int testingPassword;
							cout << "Please enter password: " << endl;
							cin >> testingPassword;
							if (testingPassword == systempassword) {
								cout << "Dear " << username << "," << endl;

							}
							else if (trying == 1) {
								cout << "\nPassword is wrong. You have no trials to try. get new password.....\n";
								cout << "\nEnter 1 or 2!\n " << endl;
								goto first;
							}
							else {
								cout << "Password is wrong. You have " << trying - 1 << " trials to left..." << endl;
								trying--;
								goto loop7;
								return 0;
							}

						}
						else
						{
							cout << "\nInvalid number! Enter 1 or 2!\n " << endl;
							goto first;
						}
					}

					// Ask for payment method
					cout << "\n		Please select a payment method:" << endl;
					cout << "			1) Credit card" << endl;
					cout << "			2) Debit card" << endl;
					cout << "			3) Cash" << endl;
					cout << "			4) Bitcoin" << endl;
					cout << "			5) Cancel" << endl;
					cout << "			Choice: ";
					cin >> choice;
					cout << endl;

					// Process payment based on the selected method
					if (choice == "1" || choice == "2") {
						string cardNumber, cardExpiry, cardCVV;
						cout << "			Please enter your card number: ";
						cin >> cardNumber;
						cout << "			Please enter your card expiry date (MM/YY): ";
						cin >> cardExpiry;
						cout << "			Please enter your card CVV: ";
						cin >> cardCVV;

						// Process payment using a payment gateway or API
						// ...

						// Confirm payment
						cout << "			Payment confirmed. Thank you for your purchase!\n" << endl;
						cout << "           Hope to see you soon!" << endl;
					}
					else if (choice == "3") {
						double cashPaid;
						do {
							cout << "			Please enter the amount of cash paid: ";
							cin >> cashPaid;
						} while (cashPaid < total_price); // Make sure enough cash is paid

						// Calculate change
						double change = cashPaid - total_price;

						// Print receipt
						cout << "			Receipt:\n";
						cout << "			---------------------------\n";
						cout << "			Total: " << total_price << "$\n";
						cout << "			Paid: " << cashPaid << "$\n";
						cout << "			Change: " << change << "$\n";
						cout << "			---------------------------\n";

						// Confirm payment
						cout << "			Payment confirmed. Thank you for your purchase!\n" << endl;
						cout << "           Hope to see you soon!" << endl;
					}
					else if (choice == "4") {
						Bitcoin bitcoin;
						cout << "Please enter your Bitcoin address: ";
						cin >> bitcoin.address;
						cout << "Please enter the amount of Bitcoin to be paid: ";
						cin >> bitcoin.amount;

						// Process payment using a Bitcoin payment gateway or API
						// ...

						// Confirm payment
						cout << "Payment confirmed. Thank you for your purchase!\n" << endl;
						cout << "Hope to see you soon!" << endl;
					}
					else if (choice == "5") {
						cout << "			Payment cancelled. Order cancelled.\n" << endl;
						continue;
					}
					else {
						cout << "			Invalid choice. Order cancelled.\n" << endl;
						continue;
					}
					break;
					zero_price();
					continue;
				}
				else
				{
					cout << "Please select 1 or 2" << endl;
					continue;
				}
			}
			else if (choice == "3")
			{
				cout << "\n How many: ";
				cin >> choice_int;
				cout << endl;
				cout << "\n	  product is adding..." << endl;
				frappe.stock_down(choice_int);
				//Sleep(2000);

				// Discount or price
				if (controller == true && day == "4")
				{
					sum_price(choice_int * frappe.price * 0.9);
					cout << " Today is the day of discount on cold drinks.\n";
					cout << "\n	  Total price is: " << total_price << "$\n\n" << endl;
				}
				else if (controller == true)
				{
					sum_price(choice_int * frappe.price);
					cout << "\n	  Total price is: " << total_price << "$\n\n" << endl;
				}

				//Sleep(1000);


				// Best selling for cold drink
				cout << "___________________________________________________\n\n" << endl;
				countColdDrinks(lemonade.counter, milkshake.counter, frappe.counter, lemonade.name, milkshake.name, frappe.name);


				cout << "Will you continue with the order (1) or proceed to the payment part? (2): ";
				cin >> choice;
				cout << endl;

				if (choice == "1")
				{
					//Sleep(1000);
					continue;
				}
				else if (choice == "2")
				{

					cout << "\t\t1.Would you like to have a seat?" << endl;
					cout << "\t\t2.Would you like to order takeout?" << endl;
					cout << "\t\t please choose one of the option !" << endl;
					int ga;
					cin >> ga;
					if (ga == 1)
					{
						cout << "\tPlease enter the table number you will sit at" << endl;
						int tablenumber;
						cin >> tablenumber;
					}
					else if (ga == 2)
					{
						cout << "\t 1.Please login as a user." << endl;
						cout << "\t 2.If you are not a member, register." << endl;
						cout << "Please choose 1 or 2" << endl;


						string username;
						int systempassword = 123;
						int g;
						cin >> g;
						if (g == 1)
						{
							string username;
							int password;
							cout << "Please enter your user name" << endl;
							cin >> username;
							cout << "The password that gives you from the system: ";
							cout << systempassword;
							cout << endl;
							cout << "Membership successfully completed, please log in" << endl << endl;
							goto first;
						}
						else if (g == 2)
						{
							cout << "\nPlase enter your user name" << endl;
							cin >> username;
							cout << "Dear " << username << " ," << endl;
							cout << "Welcome back again\n " << endl;

							int trying = 3;
						loop8:
							//Asking for determined password from user
							int testingPassword;
							cout << "Please enter password: " << endl;
							cin >> testingPassword;
							if (testingPassword == systempassword) {
								cout << "Dear " << username << "," << endl;

							}
							else if (trying == 1) {
								cout << "\nPassword is wrong. You have no trials to try. get new password.....\n";
								cout << "\nEnter 1 or 2!\n " << endl;
								goto first;
							}
							else {
								cout << "Password is wrong. You have " << trying - 1 << " trials to left..." << endl;
								trying--;
								goto loop8;
								return 0;
							}

						}
						else
						{
							cout << "\nInvalid number! Enter 1 or 2!\n " << endl;
							goto first;
						}
					}

					// Ask for payment method
					cout << "\n		Please select a payment method:" << endl;
					cout << "			1) Credit card" << endl;
					cout << "			2) Debit card" << endl;
					cout << "			3) Cash" << endl;
					cout << "			4) Bitcoin" << endl;
					cout << "			5) Cancel" << endl;
					cout << "			Choice: ";
					cin >> choice;
					cout << endl;

					// Process payment based on the selected method
					if (choice == "1" || choice == "2") {
						string cardNumber, cardExpiry, cardCVV;
						cout << "			Please enter your card number: ";
						cin >> cardNumber;
						cout << "			Please enter your card expiry date (MM/YY): ";
						cin >> cardExpiry;
						cout << "			Please enter your card CVV: ";
						cin >> cardCVV;

						// Process payment using a payment gateway or API
						// ...

						// Confirm payment
						cout << "			Payment confirmed. Thank you for your purchase!\n" << endl;
						cout << "           Hope to see you soon!" << endl;
					}
					else if (choice == "3") {
						double cashPaid;
						do {
							cout << "			Please enter the amount of cash paid: ";
							cin >> cashPaid;
						} while (cashPaid < total_price); // Make sure enough cash is paid

						// Calculate change
						double change = cashPaid - total_price;

						// Print receipt
						cout << "			Receipt:\n";
						cout << "			---------------------------\n";
						cout << "			Total: " << total_price << "$\n";
						cout << "			Paid: " << cashPaid << "$\n";
						cout << "			Change: " << change << "$\n";
						cout << "			---------------------------\n";

						// Confirm payment
						cout << "			Payment confirmed. Thank you for your purchase!\n" << endl;
						cout << "           Hope to see you soon!" << endl;
					}
					else if (choice == "4") {
						Bitcoin bitcoin;
						cout << "Please enter your Bitcoin address: ";
						cin >> bitcoin.address;
						cout << "Please enter the amount of Bitcoin to be paid: ";
						cin >> bitcoin.amount;

						// Process payment using a Bitcoin payment gateway or API
						// ...

						// Confirm payment
						cout << "Payment confirmed. Thank you for your purchase!\n" << endl;
						cout << "Hope to see you soon!" << endl;
					}
					else if (choice == "5") {
						cout << "			Payment cancelled. Order cancelled.\n" << endl;
						continue;
					}
					else {
						cout << "			Invalid choice. Order cancelled.\n" << endl;
						continue;
					}
					break;
					zero_price();
					continue;
				}
				else
				{
					cout << "Please select 1 or 2" << endl;
					continue;
				}
			}
		}
		else if (choice == "3")
		{
			cout << "	  1)"; muffin.show();
			cout << "	  2)"; brownie.show();
			cout << "	  3)"; cheesecake.show();
			cout << "	  4)"; magnolia.show();
			cout << "	  5)"; crumble.show();
			cout << endl;

			cout << "Select one : ";
			cin >> choice;

			if (choice == "1")
			{
				cout << "\n How many: ";
				cin >> choice_int;
				cout << endl;
				cout << "\n	  product is adding..." << endl;
				muffin.stock_down(choice_int);
				//Sleep(2000);

				// Discount or price
				if (controller == true && day == "7")
				{
					sum_price(choice_int * muffin.price * 0.9);
					cout << " Today is the day of sale on sweets.\n";
					cout << "\n	  Total price is: " << total_price << "$\n\n" << endl;
				}
				else if (controller == true)
				{
					sum_price(choice_int * muffin.price);
					cout << "\n	  Total price is: " << total_price << "$\n\n" << endl;
				}

				//Sleep(1000);


				// Best seller for desserts
				cout << "___________________________________________________\n\n" << endl;
				countDeserts(muffin.counter, brownie.counter, cheesecake.counter, magnolia.counter, muffin.name, brownie.name, cheesecake.name, magnolia.name);


				cout << "Will you continue with the order (1) or proceed to the payment part? (2): ";
				cin >> choice;
				cout << endl;

				if (choice == "1")
				{
					//Sleep(1000);
					continue;
				}
				else if (choice == "2")
				{

					cout << "\t\t1.Would you like to have a seat?" << endl;
					cout << "\t\t2.Would you like to order takeout?" << endl;
					cout << "\t\t please choose one of the option !" << endl;
					int ga;
					cin >> ga;
					if (ga == 1)
					{
						cout << "\tPlease enter the table number you will sit at" << endl;
						int tablenumber;
						cin >> tablenumber;
					}
					else if (ga == 2)
					{
						cout << "\t 1.Please login as a user." << endl;
						cout << "\t 2.If you are not a member, register." << endl;
						cout << "Please choose 1 or 2" << endl;


						string username;
						int systempassword = 123;
						int g;
						cin >> g;
						if (g == 1)
						{
							string username;
							int password;
							cout << "Please enter your user name" << endl;
							cin >> username;
							cout << "The password that gives you from the system: ";
							cout << systempassword;
							cout << endl;
							cout << "Membership successfully completed, please log in" << endl << endl;
							goto first;
						}
						else if (g == 2)
						{
							cout << "\nPlase enter your user name" << endl;
							cin >> username;
							cout << "Dear " << username << " ," << endl;
							cout << "Welcome back again\n " << endl;

							int trying = 3;
						loop9:
							//Asking for determined password from user
							int testingPassword;
							cout << "Please enter password: " << endl;
							cin >> testingPassword;
							if (testingPassword == systempassword) {
								cout << "Dear " << username << "," << endl;

							}
							else if (trying == 1) {
								cout << "\nPassword is wrong. You have no trials to try. get new password.....\n";
								cout << "\nEnter 1 or 2!\n " << endl;
								goto first;
							}
							else {
								cout << "Password is wrong. You have " << trying - 1 << " trials to left..." << endl;
								trying--;
								goto loop9;
								return 0;
							}

						}
						else
						{
							cout << "\nInvalid number! Enter 1 or 2!\n " << endl;
							goto first;
						}
					}

					// Ask for payment method
					cout << "\n		Please select a payment method:" << endl;
					cout << "			1) Credit card" << endl;
					cout << "			2) Debit card" << endl;
					cout << "			3) Cash" << endl;
					cout << "			4) Bitcoin" << endl;
					cout << "			5) Cancel" << endl;
					cout << "			Choice: ";
					cin >> choice;
					cout << endl;

					// Process payment based on the selected method
					if (choice == "1" || choice == "2") {
						string cardNumber, cardExpiry, cardCVV;
						cout << "			Please enter your card number: ";
						cin >> cardNumber;
						cout << "			Please enter your card expiry date (MM/YY): ";
						cin >> cardExpiry;
						cout << "			Please enter your card CVV: ";
						cin >> cardCVV;

						// Process payment using a payment gateway or API
						// ...

						// Confirm payment
						cout << "			Payment confirmed. Thank you for your purchase!\n" << endl;
						cout << "Hope to see you soon!" << endl;
					}
					else if (choice == "3") {
						double cashPaid;
						do {
							cout << "			Please enter the amount of cash paid: ";
							cin >> cashPaid;
						} while (cashPaid < total_price); // Make sure enough cash is paid

						// Calculate change
						double change = cashPaid - total_price;

						// Print receipt
						cout << "			Receipt:\n";
						cout << "			---------------------------\n";
						cout << "			Total: " << total_price << "$\n";
						cout << "			Paid: " << cashPaid << "$\n";
						cout << "			Change: " << change << "$\n";
						cout << "			---------------------------\n";

						// Confirm payment
						cout << "			Payment confirmed. Thank you for your purchase!\n" << endl;
						cout << "           Hope to see you soon!" << endl;
					}
					else if (choice == "4") {
						Bitcoin bitcoin;
						cout << "Please enter your Bitcoin address: ";
						cin >> bitcoin.address;
						cout << "Please enter the amount of Bitcoin to be paid: ";
						cin >> bitcoin.amount;

						// Process payment using a Bitcoin payment gateway or API
						// ...

						// Confirm payment
						cout << "Payment confirmed. Thank you for your purchase!\n" << endl;
						cout << "Hope to see you soon!" << endl;
					}
					else if (choice == "5") {
						cout << "			Payment cancelled. Order cancelled.\n" << endl;
						continue;
					}
					else {
						cout << "			Invalid choice. Order cancelled.\n" << endl;
						continue;
					}
					break;
					zero_price();
					continue;
				}
				else
				{
					cout << "Please select 1 or 2" << endl;
					continue;
				}
			}
			else if (choice == "2")
			{
				cout << "\n How many: ";
				cin >> choice_int;
				cout << endl;
				cout << "\n	  product is adding..." << endl;
				brownie.stock_down(choice_int);
				//Sleep(2000);

				// Discount or price
				if (controller == true && day == "7")
				{
					sum_price(choice_int * brownie.price * 0.9);
					cout << " Today is the day of sale on sweets.\n";
					cout << "\n	  Total price is: " << total_price << "$\n\n" << endl;
				}
				else if (controller == true)
				{
					sum_price(choice_int * brownie.price);
					cout << "\n	  Total price is: " << total_price << "$\n\n" << endl;
				}

				//Sleep(1000);


				// Best seller for desserts
				cout << "___________________________________________________\n\n" << endl;
				countDeserts(muffin.counter, brownie.counter, cheesecake.counter, magnolia.counter, muffin.name, brownie.name, cheesecake.name, magnolia.name);


				cout << "Will you continue with the order (1) or proceed to the payment part? (2): ";
				cin >> choice;
				cout << endl;

				if (choice == "1")
				{
					//Sleep(1000);
					continue;
				}
				else if (choice == "2")
				{

					cout << "\t\t1.Would you like to have a seat?" << endl;
					cout << "\t\t2.Would you like to order takeout?" << endl;
					cout << "\t\t please choose one of the option !" << endl;
					int ga;
					cin >> ga;
					if (ga == 1)
					{
						cout << "\tPlease enter the table number you will sit at" << endl;
						int tablenumber;
						cin >> tablenumber;
					}
					else if (ga == 2)
					{
						cout << "\t 1.Please login as a user." << endl;
						cout << "\t 2.If you are not a member, register." << endl;
						cout << "Please choose 1 or 2" << endl;


						string username;
						int systempassword = 123;
						int g;
						cin >> g;
						if (g == 1)
						{
							string username;
							int password;
							cout << "Please enter your user name" << endl;
							cin >> username;
							cout << "The password that gives you from the system: ";
							cout << systempassword;
							cout << endl;
							cout << "Membership successfully completed, please log in" << endl << endl;
							goto first;
						}
						else if (g == 2)
						{
							cout << "\nPlase enter your user name" << endl;
							cin >> username;
							cout << "Dear " << username << " ," << endl;
							cout << "Welcome back again\n " << endl;

							int trying = 3;
						loop10:
							//Asking for determined password from user
							int testingPassword;
							cout << "Please enter password: " << endl;
							cin >> testingPassword;
							if (testingPassword == systempassword) {
								cout << "Dear " << username << "," << endl;

							}
							else if (trying == 1) {
								cout << "\nPassword is wrong. You have no trials to try. get new password.....\n";
								cout << "\nEnter 1 or 2!\n " << endl;
								goto first;
							}
							else {
								cout << "Password is wrong. You have " << trying - 1 << " trials to left..." << endl;
								trying--;
								goto loop10;
								return 0;
							}

						}
						else
						{
							cout << "\nInvalid number! Enter 1 or 2!\n " << endl;
							goto first;
						}
					}

					// Ask for payment method
					cout << "\n		Please select a payment method:" << endl;
					cout << "			1) Credit card" << endl;
					cout << "			2) Debit card" << endl;
					cout << "			3) Cash" << endl;
					cout << "			4) Bitcoin" << endl;
					cout << "			5) Cancel" << endl;
					cout << "			Choice: ";
					cin >> choice;
					cout << endl;

					// Process payment based on the selected method
					if (choice == "1" || choice == "2") {
						string cardNumber, cardExpiry, cardCVV;
						cout << "			Please enter your card number: ";
						cin >> cardNumber;
						cout << "			Please enter your card expiry date (MM/YY): ";
						cin >> cardExpiry;
						cout << "			Please enter your card CVV: ";
						cin >> cardCVV;

						// Process payment using a payment gateway or API
						// ...

						// Confirm payment
						cout << "			Payment confirmed. Thank you for your purchase!\n" << endl;
						cout << "           Hope to see you soon!" << endl;
					}
					else if (choice == "3") {
						double cashPaid;
						do {
							cout << "			Please enter the amount of cash paid: ";
							cin >> cashPaid;
						} while (cashPaid < total_price); // Make sure enough cash is paid

						// Calculate change
						double change = cashPaid - total_price;

						// Print receipt
						cout << "			Receipt:\n";
						cout << "			---------------------------\n";
						cout << "			Total: " << total_price << "$\n";
						cout << "			Paid: " << cashPaid << "$\n";
						cout << "			Change: " << change << "$\n";
						cout << "			---------------------------\n";

						// Confirm payment
						cout << "			Payment confirmed. Thank you for your purchase!\n" << endl;
						cout << "           Hope to see you soon!" << endl;
					}
					else if (choice == "4") {
						Bitcoin bitcoin;
						cout << "Please enter your Bitcoin address: ";
						cin >> bitcoin.address;
						cout << "Please enter the amount of Bitcoin to be paid: ";
						cin >> bitcoin.amount;

						// Process payment using a Bitcoin payment gateway or API
						// ...

						// Confirm payment
						cout << "Payment confirmed. Thank you for your purchase!\n" << endl;
						cout << "Hope to see you soon!" << endl;
					}
					else if (choice == "5") {
						cout << "			Payment cancelled. Order cancelled.\n" << endl;
						continue;
					}
					else {
						cout << "			Invalid choice. Order cancelled.\n" << endl;
						continue;
					}
					break;
					zero_price();
					continue;
				}
				else
				{
					cout << "Please select 1 or 2" << endl;
					continue;
				}
			}
			else if (choice == "3")
			{
				cout << "\n How many: ";
				cin >> choice_int;
				cout << endl;
				cout << "\n	  product is adding..." << endl;
				cheesecake.stock_down(choice_int);
				//Sleep(2000);

				// Discount or price
				if (controller == true && day == "7")
				{
					sum_price(choice_int * cheesecake.price * 0.9);
					cout << " Today is the day of sale on sweets.\n";
					cout << "\n	  Total price is: " << total_price << "$\n\n" << endl;
				}
				else if (controller == true)
				{
					sum_price(choice_int * cheesecake.price);
					cout << "\n	  Total price is: " << total_price << "$\n\n" << endl;
				}

				//Sleep(1000);

				// Best seller for desserts
				cout << "___________________________________________________\n\n" << endl;
				countDeserts(muffin.counter, brownie.counter, cheesecake.counter, magnolia.counter, muffin.name, brownie.name, cheesecake.name, magnolia.name);


				cout << "Will you continue with the order (1) or proceed to the payment part? (2): ";
				cin >> choice;
				cout << endl;

				if (choice == "1")
				{
					//Sleep(1000);
					continue;
				}
				else if (choice == "2")
				{

					cout << "\t\t1.Would you like to have a seat?" << endl;
					cout << "\t\t2.Would you like to order takeout?" << endl;
					cout << "\t\t please choose one of the option !" << endl;
					int ga;
					cin >> ga;
					if (ga == 1)
					{
						cout << "\tPlease enter the table number you will sit at" << endl;
						int tablenumber;
						cin >> tablenumber;
					}
					else if (ga == 2)
					{
						cout << "\t 1.Please login as a user." << endl;
						cout << "\t 2.If you are not a member, register." << endl;
						cout << "Please choose 1 or 2" << endl;


						string username;
						int systempassword = 123;
						int g;
						cin >> g;
						if (g == 1)
						{
							string username;
							int password;
							cout << "Please enter your user name" << endl;
							cin >> username;
							cout << "The password that gives you from the system: ";
							cout << systempassword;
							cout << endl;
							cout << "Membership successfully completed, please log in" << endl << endl;
							goto first;
						}
						else if (g == 2)
						{
							cout << "\nPlase enter your user name" << endl;
							cin >> username;
							cout << "Dear " << username << " ," << endl;
							cout << "Welcome back again\n " << endl;

							int trying = 3;
						loop11:
							//Asking for determined password from user
							int testingPassword;
							cout << "Please enter password: " << endl;
							cin >> testingPassword;
							if (testingPassword == systempassword) {
								cout << "Dear " << username << "," << endl;

							}
							else if (trying == 1) {
								cout << "\nPassword is wrong. You have no trials to try. get new password.....\n";
								cout << "\nEnter 1 or 2!\n " << endl;
								goto first;
							}
							else {
								cout << "Password is wrong. You have " << trying - 1 << " trials to left..." << endl;
								trying--;
								goto loop11;
								return 0;
							}

						}
						else
						{
							cout << "\nInvalid number! Enter 1 or 2!\n " << endl;
							goto first;
						}
					}

					// Ask for payment method
					cout << "\n		Please select a payment method:" << endl;
					cout << "			1) Credit card" << endl;
					cout << "			2) Debit card" << endl;
					cout << "			3) Cash" << endl;
					cout << "			4) Bitcoin" << endl;
					cout << "			5) Cancel" << endl;
					cout << "			Choice: ";
					cin >> choice;
					cout << endl;

					// Process payment based on the selected method
					if (choice == "1" || choice == "2") {
						string cardNumber, cardExpiry, cardCVV;
						cout << "			Please enter your card number: ";
						cin >> cardNumber;
						cout << "			Please enter your card expiry date (MM/YY): ";
						cin >> cardExpiry;
						cout << "			Please enter your card CVV: ";
						cin >> cardCVV;

						// Process payment using a payment gateway or API
						// ...

						// Confirm payment
						cout << "			Payment confirmed. Thank you for your purchase!\n" << endl;
						cout << "           Hope to see you soon!" << endl;
					}
					else if (choice == "3") {
						double cashPaid;
						do {
							cout << "			Please enter the amount of cash paid: ";
							cin >> cashPaid;
						} while (cashPaid < total_price); // Make sure enough cash is paid

						// Calculate change
						double change = cashPaid - total_price;

						// Print receipt
						cout << "			Receipt:\n";
						cout << "			---------------------------\n";
						cout << "			Total: " << total_price << "$\n";
						cout << "			Paid: " << cashPaid << "$\n";
						cout << "			Change: " << change << "$\n";
						cout << "			---------------------------\n";

						// Confirm payment
						cout << "			Payment confirmed. Thank you for your purchase!\n" << endl;
						cout << "           Hope to see you soon!" << endl;
					}
					else if (choice == "4") {
						Bitcoin bitcoin;
						cout << "Please enter your Bitcoin address: ";
						cin >> bitcoin.address;
						cout << "Please enter the amount of Bitcoin to be paid: ";
						cin >> bitcoin.amount;

						// Process payment using a Bitcoin payment gateway or API
						// ...

						// Confirm payment
						cout << "Payment confirmed. Thank you for your purchase!\n" << endl;
						cout << "Hope to see you soon!" << endl;
					}
					else if (choice == "5") {
						cout << "			Payment cancelled. Order cancelled.\n" << endl;
						continue;
					}
					else {
						cout << "			Invalid choice. Order cancelled.\n" << endl;
						continue;
					}
					break;
					zero_price();
					continue;
				}
				else
				{
					cout << "Please select 1 or 2" << endl;
					continue;
				}
			}
			else if (choice == "4")
			{
				cout << "\n How many: ";
				cin >> choice_int;
				cout << endl;
				cout << "\n	  product is adding..." << endl;
				magnolia.stock_down(choice_int);
				//Sleep(2000);

				// Discount or price
				if (controller == true && day == "7")
				{
					sum_price(choice_int * magnolia.price * 0.9);
					cout << " Today is the day of sale on sweets.\n";
					cout << "\n	  Total price is: " << total_price << "$\n\n" << endl;
				}
				else if (controller == true)
				{
					sum_price(choice_int * magnolia.price);
					cout << "\n	  Total price is: " << total_price << "$\n\n" << endl;
				}

				//Sleep(1000);

				// Best seller for desserts
				cout << "___________________________________________________\n\n" << endl;
				countDeserts(muffin.counter, brownie.counter, cheesecake.counter, magnolia.counter, muffin.name, brownie.name, cheesecake.name, magnolia.name);


				cout << "Will you continue with the order (1) or proceed to the payment part? (2): ";
				cin >> choice;
				cout << endl;

				if (choice == "1")
				{
					//Sleep(1000);
					continue;
				}
				else if (choice == "2")
				{

					cout << "\t\t1.Would you like to have a seat?" << endl;
					cout << "\t\t2.Would you like to order takeout?" << endl;
					cout << "\t\t please choose one of the option !" << endl;
					int ga;
					cin >> ga;
					if (ga == 1)
					{
						cout << "\tPlease enter the table number you will sit at" << endl;
						int tablenumber;
						cin >> tablenumber;
					}
					else if (ga == 2)
					{
						cout << "\t 1.Please login as a user." << endl;
						cout << "\t 2.If you are not a member, register." << endl;
						cout << "Please choose 1 or 2" << endl;


						string username;
						int systempassword = 123;
						int g;
						cin >> g;
						if (g == 1)
						{
							string username;
							int password;
							cout << "Please enter your user name" << endl;
							cin >> username;
							cout << "The password that gives you from the system: ";
							cout << systempassword;
							cout << endl;
							cout << "Membership successfully completed, please log in" << endl << endl;
							goto first;
						}
						else if (g == 2)
						{
							cout << "\nPlase enter your user name" << endl;
							cin >> username;
							cout << "Dear " << username << " ," << endl;
							cout << "Welcome back again\n " << endl;

							int trying = 3;
						loop12:
							//Asking for determined password from user
							int testingPassword;
							cout << "Please enter password: " << endl;
							cin >> testingPassword;
							if (testingPassword == systempassword) {
								cout << "Dear " << username << "," << endl;

							}
							else if (trying == 1) {
								cout << "\nPassword is wrong. You have no trials to try. get new password.....\n";
								cout << "\nEnter 1 or 2!\n " << endl;
								goto first;
							}
							else {
								cout << "Password is wrong. You have " << trying - 1 << " trials to left..." << endl;
								trying--;
								goto loop12;
								return 0;
							}

						}
						else
						{
							cout << "\nInvalid number! Enter 1 or 2!\n " << endl;
							goto first;
						}
					}

					// Ask for payment method
					cout << "\n		Please select a payment method:" << endl;
					cout << "			1) Credit card" << endl;
					cout << "			2) Debit card" << endl;
					cout << "			3) Cash" << endl;
					cout << "			4) Bitcoin" << endl;
					cout << "			5) Cancel" << endl;
					cout << "			Choice: ";
					cin >> choice;
					cout << endl;

					// Process payment based on the selected method
					if (choice == "1" || choice == "2") {
						string cardNumber, cardExpiry, cardCVV;
						cout << "			Please enter your card number: ";
						cin >> cardNumber;
						cout << "			Please enter your card expiry date (MM/YY): ";
						cin >> cardExpiry;
						cout << "			Please enter your card CVV: ";
						cin >> cardCVV;

						// Process payment using a payment gateway or API
						// ...

						// Confirm payment
						cout << "			Payment confirmed. Thank you for your purchase!\n" << endl;
						cout << "           Hope to see you soon!" << endl;
					}
					else if (choice == "3") {
						double cashPaid;
						do {
							cout << "			Please enter the amount of cash paid: ";
							cin >> cashPaid;
						} while (cashPaid < total_price); // Make sure enough cash is paid

						// Calculate change
						double change = cashPaid - total_price;

						// Print receipt
						cout << "			Receipt:\n";
						cout << "			---------------------------\n";
						cout << "			Total: " << total_price << "$\n";
						cout << "			Paid: " << cashPaid << "$\n";
						cout << "			Change: " << change << "$\n";
						cout << "			---------------------------\n";

						// Confirm payment
						cout << "			Payment confirmed. Thank you for your purchase!\n" << endl;
						cout << "           Hope to see you soon!" << endl;
					}
					else if (choice == "4") {
						Bitcoin bitcoin;
						cout << "Please enter your Bitcoin address: ";
						cin >> bitcoin.address;
						cout << "Please enter the amount of Bitcoin to be paid: ";
						cin >> bitcoin.amount;

						// Process payment using a Bitcoin payment gateway or API
						// ...

						// Confirm payment
						cout << "Payment confirmed. Thank you for your purchase!\n" << endl;
						cout << "Hope to see you soon!" << endl;
					}
					else if (choice == "5") {
						cout << "			Payment cancelled. Order cancelled.\n" << endl;
						continue;
					}
					else {
						cout << "			Invalid choice. Order cancelled.\n" << endl;
						continue;
					}
					zero_price();
					continue;
				}
				else
				{
					cout << "Please select 1 or 2" << endl;
					continue;
				}
			}
			else if (choice == "5")
			{
				cout << "\n How many: ";
				cin >> choice_int;
				cout << endl;
				cout << "\n	  product is adding..." << endl;
				crumble.stock_down(choice_int);
				//Sleep(2000);

				// Discount or price
				if (controller == true && day == "7")
				{
					sum_price(choice_int * crumble.price * 0.9);
					cout << " Today is the day of sale on sweets.\n";
					cout << "\n	  Total price is: " << total_price << "$\n\n" << endl;
				}
				else if (controller == true)
				{
					sum_price(choice_int * crumble.price);
					cout << "\n	  Total price is: " << total_price << "$\n\n" << endl;
				}

				//Sleep(1000);

				// Best seller for desserts
				cout << "___________________________________________________\n\n" << endl;
				countDeserts(muffin.counter, brownie.counter, cheesecake.counter, magnolia.counter, muffin.name, brownie.name, cheesecake.name, magnolia.name);


				cout << "Will you continue with the order (1) or proceed to the payment part? (2): ";
				cin >> choice;
				cout << endl;

				if (choice == "1")
				{
					//Sleep(1000);
					continue;
				}
				else if (choice == "2")
				{

					cout << "\t\t1.Would you like to have a seat?" << endl;
					cout << "\t\t2.Would you like to order takeout?" << endl;
					cout << "\t\t please choose one of the option !" << endl;
					int ga;
					cin >> ga;
					if (ga == 1)
					{
						cout << "\tPlease enter the table number you will sit at" << endl;
						int tablenumber;
						cin >> tablenumber;
					}
					else if (ga == 2)
					{
						cout << "\t 1.Please login as a user." << endl;
						cout << "\t 2.If you are not a member, register." << endl;
						cout << "Please choose 1 or 2" << endl;


						string username;
						int systempassword = 123;
						int g;
						cin >> g;
						if (g == 1)
						{
							string username;
							int password;
							cout << "Please enter your user name" << endl;
							cin >> username;
							cout << "The password that gives you from the system: ";
							cout << systempassword;
							cout << endl;
							cout << "Membership successfully completed, please log in" << endl << endl;
							goto first;
						}
						else if (g == 2)
						{
							cout << "\nPlase enter your user name" << endl;
							cin >> username;
							cout << "Dear " << username << " ," << endl;
							cout << "Welcome back again\n " << endl;

							int trying = 3;
						loop13:
							//Asking for determined password from user
							int testingPassword;
							cout << "Please enter password: " << endl;
							cin >> testingPassword;
							if (testingPassword == systempassword) {
								cout << "Dear " << username << "," << endl;

							}
							else if (trying == 1) {
								cout << "\nPassword is wrong. You have no trials to try. get new password.....\n";
								cout << "\nEnter 1 or 2!\n " << endl;
								goto first;
							}
							else {
								cout << "Password is wrong. You have " << trying - 1 << " trials to left..." << endl;
								trying--;
								goto loop13;
								return 0;
							}

						}
						else
						{
							cout << "\nInvalid number! Enter 1 or 2!\n " << endl;
							goto first;
						}
					}

					// Ask for payment method
					cout << "\n		Please select a payment method:" << endl;
					cout << "			1) Credit card" << endl;
					cout << "			2) Debit card" << endl;
					cout << "			3) Cash" << endl;
					cout << "			4) Bitcoin" << endl;
					cout << "			5) Cancel" << endl;
					cout << "			Choice: ";
					cin >> choice;
					cout << endl;

					// Process payment based on the selected method
					if (choice == "1" || choice == "2") {
						string cardNumber, cardExpiry, cardCVV;
						cout << "			Please enter your card number: ";
						cin >> cardNumber;
						cout << "			Please enter your card expiry date (MM/YY): ";
						cin >> cardExpiry;
						cout << "			Please enter your card CVV: ";
						cin >> cardCVV;

						// Process payment using a payment gateway or API
						// ...

						// Confirm payment
						cout << "			Payment confirmed. Thank you for your purchase!\n" << endl;
						cout << "           Hope to see you soon!" << endl;
					}
					else if (choice == "3") {
						double cashPaid;
						do {
							cout << "			Please enter the amount of cash paid: ";
							cin >> cashPaid;
						} while (cashPaid < total_price); // Make sure enough cash is paid

						// Calculate change
						double change = cashPaid - total_price;

						// Print receipt
						cout << "			Receipt:\n";
						cout << "			---------------------------\n";
						cout << "			Total: " << total_price << "$\n";
						cout << "			Paid: " << cashPaid << "$\n";
						cout << "			Change: " << change << "$\n";
						cout << "			---------------------------\n";

						// Confirm payment
						cout << "			Payment confirmed. Thank you for your purchase!\n" << endl;
						cout << "           Hope to see you soon!" << endl;
					}
					else if (choice == "4") {
						Bitcoin bitcoin;
						cout << "Please enter your Bitcoin address: ";
						cin >> bitcoin.address;
						cout << "Please enter the amount of Bitcoin to be paid: ";
						cin >> bitcoin.amount;

						// Process payment using a Bitcoin payment gateway or API
						// ...

						// Confirm payment
						cout << "Payment confirmed. Thank you for your purchase!\n" << endl;
						cout << "Hope to see you soon!" << endl;
					}
					else if (choice == "5") {
						cout << "			Payment cancelled. Order cancelled.\n" << endl;
						continue;
					}
					else {
						cout << "			Invalid choice. Order cancelled.\n" << endl;
						continue;
					}
					break;
					zero_price();
					continue;
				}
				else
				{
					cout << "Please select 1 or 2" << endl;
					continue;
				}
			}
			else { cout << "You have to choice between 1-5" << endl; }

		}
		else if (choice == "4")
		{
			if (day == "6" || day == "7") {
				cout << "***   		 Cultural Menu		   ***" << endl << endl;


				if (day == "6")
				{
					cout << "Japan Menu:\n";
					cout << "	  1)";  japanese_cheescake.show();
					cout << "	  2)"; matcha_tea.show();
					cout << "Mexico Menu:\n";
					cout << "	  3)"; chamoyada.show();
					cout << "	  4)"; bionico.show();
					cout << endl;

					cout << "Select one : ";
					cin >> choice;

					if (choice == "1")
					{
						cout << "\n How many: ";
						cin >> choice_int;
						cout << endl;
						cout << "\n	  product is adding..." << endl;
						japanese_cheescake.stock_down(choice_int);
						Sleep(2000);
						if (controller == true)
						{
							sum_price(choice_int * japanese_cheescake.price);
							cout << "\n	  Total price is: " << total_price << "$\n\n" << endl;
						}
						Sleep(1000);
						cout << "Will you continue with the order (1) or proceed to the payment part? (2): ";
						cin >> choice;
						cout << endl;

						if (choice == "1")
						{
							Sleep(1000);
							continue;
						}
						else if (choice == "2")
						{

							cout << "\t\t1.Would you like to have a seat?" << endl;
							cout << "\t\t2.Would you like to order takeout?" << endl;
							cout << "\t\t please choose one of the option !" << endl;
							int ga;
							cin >> ga;
							if (ga == 1)
							{
								cout << "\tPlease enter the table number you will sit at" << endl;
								int tablenumber;
								cin >> tablenumber;
							}
							else if (ga == 2)
							{
								cout << "\t 1.Please login as a user." << endl;
								cout << "\t 2.If you are not a member, register." << endl;
								cout << "Please choose 1 or 2" << endl;


								string username;
								int systempassword = 123;
								int g;
								cin >> g;
								if (g == 1)
								{
									string username;
									int password;
									cout << "Please enter your user name" << endl;
									cin >> username;
									cout << "The password that gives you from the system: ";
									cout << systempassword;
									cout << endl;
									cout << "Membership successfully completed, please log in" << endl << endl;
									goto first;
								}
								else if (g == 2)
								{
									cout << "\nPlase enter your user name" << endl;
									cin >> username;
									cout << "Dear " << username << " ," << endl;
									cout << "Welcome back again\n " << endl;

									int trying = 3;
								loop14:
									//Asking for determined password from user
									int testingPassword;
									cout << "Please enter password: " << endl;
									cin >> testingPassword;
									if (testingPassword == systempassword) {
										cout << "Dear " << username << "," << endl;

									}
									else if (trying == 1) {
										cout << "\nPassword is wrong. You have no trials to try. get new password.....\n";
										cout << "\nEnter 1 or 2!\n " << endl;
										goto first;
									}
									else {
										cout << "Password is wrong. You have " << trying - 1 << " trials to left..." << endl;
										trying--;
										goto loop14;
										return 0;
									}

								}
								else
								{
									cout << "\nInvalid number! Enter 1 or 2!\n " << endl;
									goto first;
								}
							}

							// Ask for payment method
							cout << "\n		Please select a payment method:" << endl;
							cout << "			1) Credit card" << endl;
							cout << "			2) Debit card" << endl;
							cout << "			3) Cash" << endl;
							cout << "			4) Bitcoin" << endl;
							cout << "			5) Cancel" << endl;
							cout << "			Choice: ";
							cin >> choice;
							cout << endl;

							// Process payment based on the selected method
							if (choice == "1" || choice == "2") {
								string cardNumber, cardExpiry, cardCVV;
								cout << "			Please enter your card number: ";
								cin >> cardNumber;
								cout << "			Please enter your card expiry date (MM/YY): ";
								cin >> cardExpiry;
								cout << "			Please enter your card CVV: ";
								cin >> cardCVV;

								// Process payment using a payment gateway or API
								// ...

								// Confirm payment
								cout << "			Payment confirmed. Thank you for your purchase!\n" << endl;
								cout << "           Hope to see you soon!" << endl;
							}
							else if (choice == "3") {
								double cashPaid;
								do {
									cout << "			Please enter the amount of cash paid: ";
									cin >> cashPaid;
								} while (cashPaid < total_price); // Make sure enough cash is paid

								// Calculate change
								double change = cashPaid - total_price;

								// Print receipt
								cout << "			Receipt:\n";
								cout << "			---------------------------\n";
								cout << "			Total: " << total_price << "$\n";
								cout << "			Paid: " << cashPaid << "$\n";
								cout << "			Change: " << change << "$\n";
								cout << "			---------------------------\n";

								// Confirm payment
								cout << "			Payment confirmed. Thank you for your purchase!\n" << endl;
								cout << "           Hope to see you soon!" << endl;
							}
							else if (choice == "4") {
								Bitcoin bitcoin;
								cout << "Please enter your Bitcoin address: ";
								cin >> bitcoin.address;
								cout << "Please enter the amount of Bitcoin to be paid: ";
								cin >> bitcoin.amount;

								// Process payment using a Bitcoin payment gateway or API
								// ...

								// Confirm payment
								cout << "Payment confirmed. Thank you for your purchase!\n" << endl;
								cout << "Hope to see you soon!" << endl;
							}
							else if (choice == "5") {
								cout << "			Payment cancelled. Order cancelled.\n" << endl;
								continue;
							}
							else {
								cout << "			Invalid choice. Order cancelled.\n" << endl;
								continue;
							}

							break;
						}
						else
						{
							cout << "Please select 1 or 2" << endl;
							continue;
						}
					}
					else if (choice == "2")
					{
						cout << "\n How many: ";
						cin >> choice_int;
						cout << endl;
						cout << "\n	  product is adding..." << endl;
						matcha_tea.stock_down(choice_int);
						Sleep(2000);
						if (controller == true)
						{
							sum_price(choice_int * matcha_tea.price);
							cout << "\n	  Total price is: " << total_price << "$\n\n" << endl;
						}
						Sleep(1000);
						cout << "Will you continue with the order (1) or proceed to the payment part? (2): ";
						cin >> choice;
						cout << endl;

						if (choice == "1")
						{
							Sleep(1000);
							continue;
						}
						else if (choice == "2")
						{

							cout << "\t\t1.Would you like to have a seat?" << endl;
							cout << "\t\t2.Would you like to order takeout?" << endl;
							cout << "\t\t please choose one of the option !" << endl;
							int ga;
							cin >> ga;
							if (ga == 1)
							{
								cout << "\tPlease enter the table number you will sit at" << endl;
								int tablenumber;
								cin >> tablenumber;
							}
							else if (ga == 2)
							{
								cout << "\t 1.Please login as a user." << endl;
								cout << "\t 2.If you are not a member, register." << endl;
								cout << "Please choose 1 or 2" << endl;


								string username;
								int systempassword = 123;
								int g;
								cin >> g;
								if (g == 1)
								{
									string username;
									int password;
									cout << "Please enter your user name" << endl;
									cin >> username;
									cout << "The password that gives you from the system: ";
									cout << systempassword;
									cout << endl;
									cout << "Membership successfully completed, please log in" << endl << endl;
									goto first;
								}
								else if (g == 2)
								{
									cout << "\nPlase enter your user name" << endl;
									cin >> username;
									cout << "Dear " << username << " ," << endl;
									cout << "Welcome back again\n " << endl;

									int trying = 3;
								loop15:
									//Asking for determined password from user
									int testingPassword;
									cout << "Please enter password: " << endl;
									cin >> testingPassword;
									if (testingPassword == systempassword) {
										cout << "Dear " << username << "," << endl;

									}
									else if (trying == 1) {
										cout << "\nPassword is wrong. You have no trials to try. get new password.....\n";
										cout << "\nEnter 1 or 2!\n " << endl;
										goto first;
									}
									else {
										cout << "Password is wrong. You have " << trying - 1 << " trials to left..." << endl;
										trying--;
										goto loop15;
										return 0;
									}

								}
								else
								{
									cout << "\nInvalid number! Enter 1 or 2!\n " << endl;
									goto first;
								}
							}

							// Ask for payment method
							cout << "\n		Please select a payment method:" << endl;
							cout << "			1) Credit card" << endl;
							cout << "			2) Debit card" << endl;
							cout << "			3) Cash" << endl;
							cout << "			4) Bitcoin" << endl;
							cout << "			5) Cancel" << endl;
							cout << "			Choice: ";
							cin >> choice;
							cout << endl;

							// Process payment based on the selected method
							if (choice == "1" || choice == "2") {
								string cardNumber, cardExpiry, cardCVV;
								cout << "			Please enter your card number: ";
								cin >> cardNumber;
								cout << "			Please enter your card expiry date (MM/YY): ";
								cin >> cardExpiry;
								cout << "			Please enter your card CVV: ";
								cin >> cardCVV;

								// Process payment using a payment gateway or API
								// ...

								// Confirm payment
								cout << "			Payment confirmed. Thank you for your purchase!\n" << endl;
								cout << "           Hope to see you soon!" << endl;
							}
							else if (choice == "3") {
								double cashPaid;
								do {
									cout << "			Please enter the amount of cash paid: ";
									cin >> cashPaid;
								} while (cashPaid < total_price); // Make sure enough cash is paid

								// Calculate change
								double change = cashPaid - total_price;

								// Print receipt
								cout << "			Receipt:\n";
								cout << "			---------------------------\n";
								cout << "			Total: " << total_price << "$\n";
								cout << "			Paid: " << cashPaid << "$\n";
								cout << "			Change: " << change << "$\n";
								cout << "			---------------------------\n";

								// Confirm payment
								cout << "			Payment confirmed. Thank you for your purchase!\n" << endl;
								cout << "           Hope to see you soon!" << endl;
							}
							else if (choice == "4") {
								Bitcoin bitcoin;
								cout << "Please enter your Bitcoin address: ";
								cin >> bitcoin.address;
								cout << "Please enter the amount of Bitcoin to be paid: ";
								cin >> bitcoin.amount;

								// Process payment using a Bitcoin payment gateway or API
								// ...

								// Confirm payment
								cout << "Payment confirmed. Thank you for your purchase!\n" << endl;
								cout << "Hope to see you soon!" << endl;
							}
							else if (choice == "5") {
								cout << "			Payment cancelled. Order cancelled.\n" << endl;
								continue;
							}
							else {
								cout << "			Invalid choice. Order cancelled.\n" << endl;
								continue;
							}

							break;
						}
						else
						{
							cout << "Please select 1 or 2" << endl;
							continue;
						}
					}
					else if (choice == "3")
					{
						cout << "\n How many: ";
						cin >> choice_int;
						cout << endl;
						cout << "\n	  product is adding..." << endl;
						chamoyada.stock_down(choice_int);
						Sleep(2000);
						if (controller == true)
						{
							sum_price(choice_int * chamoyada.price);
							cout << "\n	  Total price is: " << total_price << "$\n\n" << endl;
						}
						Sleep(1000);
						cout << "Will you continue with the order (1) or proceed to the payment part? (2): ";
						cin >> choice;
						cout << endl;

						if (choice == "1")
						{
							Sleep(1000);
							continue;
						}
						else if (choice == "2")
						{

							cout << "\t\t1.Would you like to have a seat?" << endl;
							cout << "\t\t2.Would you like to order takeout?" << endl;
							cout << "\t\t please choose one of the option !" << endl;
							int ga;
							cin >> ga;
							if (ga == 1)
							{
								cout << "\tPlease enter the table number you will sit at" << endl;
								int tablenumber;
								cin >> tablenumber;
							}
							else if (ga == 2)
							{
								cout << "\t 1.Please login as a user." << endl;
								cout << "\t 2.If you are not a member, register." << endl;
								cout << "Please choose 1 or 2" << endl;


								string username;
								int systempassword = 123;
								int g;
								cin >> g;
								if (g == 1)
								{
									string username;
									int password;
									cout << "Please enter your user name" << endl;
									cin >> username;
									cout << "The password that gives you from the system: ";
									cout << systempassword;
									cout << endl;
									cout << "Membership successfully completed, please log in" << endl << endl;
									goto first;
								}
								else if (g == 2)
								{
									cout << "\nPlase enter your user name" << endl;
									cin >> username;
									cout << "Dear " << username << " ," << endl;
									cout << "Welcome back again\n " << endl;

									int trying = 3;
								loop16:
									//Asking for determined password from user
									int testingPassword;
									cout << "Please enter password: " << endl;
									cin >> testingPassword;
									if (testingPassword == systempassword) {
										cout << "Dear " << username << "," << endl;

									}
									else if (trying == 1) {
										cout << "\nPassword is wrong. You have no trials to try. get new password.....\n";
										cout << "\nEnter 1 or 2!\n " << endl;
										goto first;
									}
									else {
										cout << "Password is wrong. You have " << trying - 1 << " trials to left..." << endl;
										trying--;
										goto loop16;
										return 0;
									}

								}
								else
								{
									cout << "\nInvalid number! Enter 1 or 2!\n " << endl;
									goto first;
								}
							}

							// Ask for payment method
							cout << "\n		Please select a payment method:" << endl;
							cout << "			1) Credit card" << endl;
							cout << "			2) Debit card" << endl;
							cout << "			3) Cash" << endl;
							cout << "			4) Bitcoin" << endl;
							cout << "			5) Cancel" << endl;
							cout << "			Choice: ";
							cin >> choice;
							cout << endl;

							// Process payment based on the selected method
							if (choice == "1" || choice == "2") {
								string cardNumber, cardExpiry, cardCVV;
								cout << "			Please enter your card number: ";
								cin >> cardNumber;
								cout << "			Please enter your card expiry date (MM/YY): ";
								cin >> cardExpiry;
								cout << "			Please enter your card CVV: ";
								cin >> cardCVV;

								// Process payment using a payment gateway or API
								// ...

								// Confirm payment
								cout << "			Payment confirmed. Thank you for your purchase!\n" << endl;
								cout << "           Hope to see you soon!" << endl;
							}
							else if (choice == "3") {
								double cashPaid;
								do {
									cout << "			Please enter the amount of cash paid: ";
									cin >> cashPaid;
								} while (cashPaid < total_price); // Make sure enough cash is paid

								// Calculate change
								double change = cashPaid - total_price;

								// Print receipt
								cout << "			Receipt:\n";
								cout << "			---------------------------\n";
								cout << "			Total: " << total_price << "$\n";
								cout << "			Paid: " << cashPaid << "$\n";
								cout << "			Change: " << change << "$\n";
								cout << "			---------------------------\n";

								// Confirm payment
								cout << "			Payment confirmed. Thank you for your purchase!\n" << endl;
								cout << "           Hope to see you soon!" << endl;
							}
							else if (choice == "4") {
								Bitcoin bitcoin;
								cout << "Please enter your Bitcoin address: ";
								cin >> bitcoin.address;
								cout << "Please enter the amount of Bitcoin to be paid: ";
								cin >> bitcoin.amount;

								// Process payment using a Bitcoin payment gateway or API
								// ...

								// Confirm payment
								cout << "            Payment confirmed. Thank you for your purchase!\n" << endl;
								cout << "            Hope to see you soon!" << endl;
							}
							else if (choice == "5") {
								cout << "			Payment cancelled. Order cancelled.\n" << endl;
								continue;
							}
							else {
								cout << "			Invalid choice. Order cancelled.\n" << endl;
								continue;
							}
							break;

						}
						else
						{
							cout << "Please select 1 or 2" << endl;
							continue;
						}
					}
					else if (choice == "4")
					{
						cout << "\n How many: ";
						cin >> choice_int;
						cout << endl;
						cout << "\n	  product is adding..." << endl;
						bionico.stock_down(choice_int);
						Sleep(2000);
						if (controller == true)
						{
							sum_price(choice_int * bionico.price);
							cout << "\n	  Total price is: " << total_price << "$\n\n" << endl;
						}
						Sleep(1000);
						cout << "Will you continue with the order (1) or proceed to the payment part? (2): ";
						cin >> choice;
						cout << endl;

						if (choice == "1")
						{
							Sleep(1000);
							continue;
						}
						else if (choice == "2")
						{

							cout << "\t\t1.Would you like to have a seat?" << endl;
							cout << "\t\t2.Would you like to order takeout?" << endl;
							cout << "\t\t please choose one of the option !" << endl;
							int ga;
							cin >> ga;
							if (ga == 1)
							{
								cout << "\tPlease enter the table number you will sit at" << endl;
								int tablenumber;
								cin >> tablenumber;
							}
							else if (ga == 2)
							{
								cout << "\t 1.Please login as a user." << endl;
								cout << "\t 2.If you are not a member, register." << endl;
								cout << "Please choose 1 or 2" << endl;


								string username;
								int systempassword = 123;
								int g;
								cin >> g;
								if (g == 1)
								{
									string username;
									int password;
									cout << "Please enter your user name" << endl;
									cin >> username;
									cout << "The password that gives you from the system: ";
									cout << systempassword;
									cout << endl;
									cout << "Membership successfully completed, please log in" << endl << endl;
									goto first;
								}
								else if (g == 2)
								{
									cout << "\nPlase enter your user name" << endl;
									cin >> username;
									cout << "Dear " << username << " ," << endl;
									cout << "Welcome back again\n " << endl;

									int trying = 3;
								loop17:
									//Asking for determined password from user
									int testingPassword;
									cout << "Please enter password: " << endl;
									cin >> testingPassword;
									if (testingPassword == systempassword) {
										cout << "Dear " << username << "," << endl;

									}
									else if (trying == 1) {
										cout << "\nPassword is wrong. You have no trials to try. get new password.....\n";
										cout << "\nEnter 1 or 2!\n " << endl;
										goto first;
									}
									else {
										cout << "Password is wrong. You have " << trying - 1 << " trials to left..." << endl;
										trying--;
										goto loop17;
										return 0;
									}

								}
								else
								{
									cout << "\nInvalid number! Enter 1 or 2!\n " << endl;
									goto first;
								}
							}

							// Ask for payment method
							cout << "\n		Please select a payment method:" << endl;
							cout << "			1) Credit card" << endl;
							cout << "			2) Debit card" << endl;
							cout << "			3) Cash" << endl;
							cout << "			4) Bitcoin" << endl;
							cout << "			5) Cancel" << endl;
							cout << "			Choice: ";
							cin >> choice;
							cout << endl;

							// Process payment based on the selected method
							if (choice == "1" || choice == "2") {
								string cardNumber, cardExpiry, cardCVV;
								cout << "			Please enter your card number: ";
								cin >> cardNumber;
								cout << "			Please enter your card expiry date (MM/YY): ";
								cin >> cardExpiry;
								cout << "			Please enter your card CVV: ";
								cin >> cardCVV;

								// Process payment using a payment gateway or API
								// ...

								// Confirm payment
								cout << "			Payment confirmed. Thank you for your purchase!\n" << endl;
								cout << "           Hope to see you soon!" << endl;
							}
							else if (choice == "3") {
								double cashPaid;
								do {
									cout << "			Please enter the amount of cash paid: ";
									cin >> cashPaid;
								} while (cashPaid < total_price); // Make sure enough cash is paid

								// Calculate change
								double change = cashPaid - total_price;

								// Print receipt
								cout << "			Receipt:\n";
								cout << "			---------------------------\n";
								cout << "			Total: " << total_price << "$\n";
								cout << "			Paid: " << cashPaid << "$\n";
								cout << "			Change: " << change << "$\n";
								cout << "			---------------------------\n";

								// Confirm payment
								cout << "			Payment confirmed. Thank you for your purchase!\n" << endl;
								cout << "           Hope to see you soon!" << endl;
							}
							else if (choice == "4") {
								Bitcoin bitcoin;
								cout << "Please enter your Bitcoin address: ";
								cin >> bitcoin.address;
								cout << "Please enter the amount of Bitcoin to be paid: ";
								cin >> bitcoin.amount;

								// Process payment using a Bitcoin payment gateway or API
								// ...

								// Confirm payment
								cout << "Payment confirmed. Thank you for your purchase!\n" << endl;
								cout << "Hope to see you soon!" << endl;
							}
							else if (choice == "5") {
								cout << "			Payment cancelled. Order cancelled.\n" << endl;
								continue;
							}
							else {
								cout << "			Invalid choice. Order cancelled.\n" << endl;
								continue;
							}
							break;
						}
						else
						{
							cout << "Please select 1 or 2" << endl;
							continue;
						}
					}
					else
					{
						cout << "You have to select from 1 to 4." << endl;
						continue;
					}





				}
				else if (day == "7")
				{
					cout << "India Menu:\n";
					cout << "	  1)";  gajor_ka_doodh.show();
					cout << "	  2)"; shahi_tukda.show();
					cout << "Spain Menu:\n";
					cout << "	  3)"; horchata.show();
					cout << "	  4)"; churros.show();
					cout << endl;

					cout << "Select one : ";
					cin >> choice;

					if (choice == "1")
					{
						cout << "\n How many: ";
						cin >> choice_int;
						cout << endl;
						cout << "\n	  product is adding..." << endl;
						gajor_ka_doodh.stock_down(choice_int);
						Sleep(2000);
						if (controller == true)
						{
							sum_price(choice_int * gajor_ka_doodh.price);
							cout << "\n	  Total price is: " << total_price << "$\n\n" << endl;
						}
						Sleep(1000);
						cout << "Will you continue with the order (1) or proceed to the payment part? (2): ";
						cin >> choice;
						cout << endl;

						if (choice == "1")
						{
							Sleep(1000);
							continue;
						}
						else if (choice == "2")
						{

							cout << "\t\t1.Would you like to have a seat?" << endl;
							cout << "\t\t2.Would you like to order takeout?" << endl;
							cout << "\t\t please choose one of the option !" << endl;
							int ga;
							cin >> ga;
							if (ga == 1)
							{
								cout << "\tPlease enter the table number you will sit at" << endl;
								int tablenumber;
								cin >> tablenumber;
							}
							else if (ga == 2)
							{
								cout << "\t 1.Please login as a user." << endl;
								cout << "\t 2.If you are not a member, register." << endl;
								cout << "Please choose 1 or 2" << endl;


								string username;
								int systempassword = 123;
								int g;
								cin >> g;
								if (g == 1)
								{
									string username;
									int password;
									cout << "Please enter your user name" << endl;
									cin >> username;
									cout << "The password that gives you from the system: ";
									cout << systempassword;
									cout << endl;
									cout << "Membership successfully completed, please log in" << endl << endl;
									goto first;
								}
								else if (g == 2)
								{
									cout << "\nPlase enter your user name" << endl;
									cin >> username;
									cout << "Dear " << username << " ," << endl;
									cout << "Welcome back again\n " << endl;

									int trying = 3;
								loop18:
									//Asking for determined password from user
									int testingPassword;
									cout << "Please enter password: " << endl;
									cin >> testingPassword;
									if (testingPassword == systempassword) {
										cout << "Dear " << username << "," << endl;

									}
									else if (trying == 1) {
										cout << "\nPassword is wrong. You have no trials to try. get new password.....\n";
										cout << "\nEnter 1 or 2!\n " << endl;
										goto first;
									}
									else {
										cout << "Password is wrong. You have " << trying - 1 << " trials to left..." << endl;
										trying--;
										goto loop18;
										return 0;
									}

								}
								else
								{
									cout << "\nInvalid number! Enter 1 or 2!\n " << endl;
									goto first;
								}
							}

							// Ask for payment method
							cout << "\n		Please select a payment method:" << endl;
							cout << "			1) Credit card" << endl;
							cout << "			2) Debit card" << endl;
							cout << "			3) Cash" << endl;
							cout << "			4) Bitcoin" << endl;
							cout << "			5) Cancel" << endl;
							cout << "			Choice: ";
							cin >> choice;
							cout << endl;

							// Process payment based on the selected method
							if (choice == "1" || choice == "2") {
								string cardNumber, cardExpiry, cardCVV;
								cout << "			Please enter your card number: ";
								cin >> cardNumber;
								cout << "			Please enter your card expiry date (MM/YY): ";
								cin >> cardExpiry;
								cout << "			Please enter your card CVV: ";
								cin >> cardCVV;

								// Process payment using a payment gateway or API
								// ...

								// Confirm payment
								cout << "			Payment confirmed. Thank you for your purchase!\n" << endl;
								cout << "           Hope to see you soon!" << endl;
							}
							else if (choice == "3") {
								double cashPaid;
								do {
									cout << "			Please enter the amount of cash paid: ";
									cin >> cashPaid;
								} while (cashPaid < total_price); // Make sure enough cash is paid

								// Calculate change
								double change = cashPaid - total_price;

								// Print receipt
								cout << "			Receipt:\n";
								cout << "			---------------------------\n";
								cout << "			Total: " << total_price << "$\n";
								cout << "			Paid: " << cashPaid << "$\n";
								cout << "			Change: " << change << "$\n";
								cout << "			---------------------------\n";

								// Confirm payment
								cout << "			Payment confirmed. Thank you for your purchase!\n" << endl;
								cout << "           Hope to see you soon!" << endl;
							}
							else if (choice == "4") {
								Bitcoin bitcoin;
								cout << "Please enter your Bitcoin address: ";
								cin >> bitcoin.address;
								cout << "Please enter the amount of Bitcoin to be paid: ";
								cin >> bitcoin.amount;

								// Process payment using a Bitcoin payment gateway or API
								// ...

								// Confirm payment
								cout << "Payment confirmed. Thank you for your purchase!\n" << endl;
								cout << "Hope to see you soon!" << endl;
							}
							else if (choice == "5") {
								cout << "			Payment cancelled. Order cancelled.\n" << endl;
								continue;
							}
							else {
								cout << "			Invalid choice. Order cancelled.\n" << endl;
								continue;
							}
							break;
						}
						else
						{
							cout << "Please select 1 or 2" << endl;
							continue;
						}
					}
					else if (choice == "2")
					{
						cout << "\n How many: ";
						cin >> choice_int;
						cout << endl;
						cout << "\n	  product is adding..." << endl;
						shahi_tukda.stock_down(choice_int);
						Sleep(2000);
						if (controller == true)
						{
							sum_price(choice_int * shahi_tukda.price);
							cout << "\n	  Total price is: " << total_price << "$\n\n" << endl;
						}
						Sleep(1000);
						cout << "Will you continue with the order (1) or proceed to the payment part? (2): ";
						cin >> choice;
						cout << endl;

						if (choice == "1")
						{
							Sleep(1000);
							continue;
						}
						else if (choice == "2")
						{

							cout << "\t\t1.Would you like to have a seat?" << endl;
							cout << "\t\t2.Would you like to order takeout?" << endl;
							cout << "\t\t please choose one of the option !" << endl;
							int ga;
							cin >> ga;
							if (ga == 1)
							{
								cout << "\tPlease enter the table number you will sit at" << endl;
								int tablenumber;
								cin >> tablenumber;
							}
							else if (ga == 2)
							{
								cout << "\t 1.Please login as a user." << endl;
								cout << "\t 2.If you are not a member, register." << endl;
								cout << "Please choose 1 or 2" << endl;


								string username;
								int systempassword = 123;
								int g;
								cin >> g;
								if (g == 1)
								{
									string username;
									int password;
									cout << "Please enter your user name" << endl;
									cin >> username;
									cout << "The password that gives you from the system: ";
									cout << systempassword;
									cout << endl;
									cout << "Membership successfully completed, please log in" << endl << endl;
									goto first;
								}
								else if (g == 2)
								{
									cout << "\nPlase enter your user name" << endl;
									cin >> username;
									cout << "Dear " << username << " ," << endl;
									cout << "Welcome back again\n " << endl;

									int trying = 3;
								loop19:
									//Asking for determined password from user
									int testingPassword;
									cout << "Please enter password: " << endl;
									cin >> testingPassword;
									if (testingPassword == systempassword) {
										cout << "Dear " << username << "," << endl;

									}
									else if (trying == 1) {
										cout << "\nPassword is wrong. You have no trials to try. get new password.....\n";
										cout << "\nEnter 1 or 2!\n " << endl;
										goto first;
									}
									else {
										cout << "Password is wrong. You have " << trying - 1 << " trials to left..." << endl;
										trying--;
										goto loop19;
										return 0;
									}

								}
								else
								{
									cout << "\nInvalid number! Enter 1 or 2!\n " << endl;
									goto first;
								}
							}

							// Ask for payment method
							cout << "\n		Please select a payment method:" << endl;
							cout << "			1) Credit card" << endl;
							cout << "			2) Debit card" << endl;
							cout << "			3) Cash" << endl;
							cout << "			4) Bitcoin" << endl;
							cout << "			5) Cancel" << endl;
							cout << "			Choice: ";
							cin >> choice;
							cout << endl;

							// Process payment based on the selected method
							if (choice == "1" || choice == "2") {
								string cardNumber, cardExpiry, cardCVV;
								cout << "			Please enter your card number: ";
								cin >> cardNumber;
								cout << "			Please enter your card expiry date (MM/YY): ";
								cin >> cardExpiry;
								cout << "			Please enter your card CVV: ";
								cin >> cardCVV;

								// Process payment using a payment gateway or API
								// ...

								// Confirm payment
								cout << "			Payment confirmed. Thank you for your purchase!\n" << endl;
								cout << "           Hope to see you soon!" << endl;
							}
							else if (choice == "3") {
								double cashPaid;
								do {
									cout << "			Please enter the amount of cash paid: ";
									cin >> cashPaid;
								} while (cashPaid < total_price); // Make sure enough cash is paid

								// Calculate change
								double change = cashPaid - total_price;

								// Print receipt
								cout << "			Receipt:\n";
								cout << "			---------------------------\n";
								cout << "			Total: " << total_price << "$\n";
								cout << "			Paid: " << cashPaid << "$\n";
								cout << "			Change: " << change << "$\n";
								cout << "			---------------------------\n";

								// Confirm payment
								cout << "			Payment confirmed. Thank you for your purchase!\n" << endl;
								cout << "           Hope to see you soon!" << endl;
							}
							else if (choice == "4") {
								Bitcoin bitcoin;
								cout << "Please enter your Bitcoin address: ";
								cin >> bitcoin.address;
								cout << "Please enter the amount of Bitcoin to be paid: ";
								cin >> bitcoin.amount;

								// Process payment using a Bitcoin payment gateway or API
								// ...

								// Confirm payment
								cout << "Payment confirmed. Thank you for your purchase!\n" << endl;
								cout << "Hope to see you soon!" << endl;
							}
							else if (choice == "5") {
								cout << "			Payment cancelled. Order cancelled.\n" << endl;
								continue;
							}
							else {
								cout << "			Invalid choice. Order cancelled.\n" << endl;
								continue;
							}
							break;
						}
						else
						{
							cout << "Please select 1 or 2" << endl;
							continue;
						}
					}
					else if (choice == "3")
					{
						cout << "\n How many: ";
						cin >> choice_int;
						cout << endl;
						cout << "\n	  product is adding..." << endl;
						horchata.stock_down(choice_int);
						Sleep(2000);
						if (controller == true)
						{
							sum_price(choice_int * horchata.price);
							cout << "\n	  Total price is: " << total_price << "$\n\n" << endl;
						}
						Sleep(1000);
						cout << "Will you continue with the order (1) or proceed to the payment part? (2): ";
						cin >> choice;
						cout << endl;

						if (choice == "1")
						{
							Sleep(1000);
							continue;
						}
						else if (choice == "2")
						{

							cout << "\t\t1.Would you like to have a seat?" << endl;
							cout << "\t\t2.Would you like to order takeout?" << endl;
							cout << "\t\t please choose one of the option !" << endl;
							int ga;
							cin >> ga;
							if (ga == 1)
							{
								cout << "\tPlease enter the table number you will sit at" << endl;
								int tablenumber;
								cin >> tablenumber;
							}
							else if (ga == 2)
							{
								cout << "\t 1.Please login as a user." << endl;
								cout << "\t 2.If you are not a member, register." << endl;
								cout << "Please choose 1 or 2" << endl;


								string username;
								int systempassword = 123;
								int g;
								cin >> g;
								if (g == 1)
								{
									string username;
									int password;
									cout << "Please enter your user name" << endl;
									cin >> username;
									cout << "The password that gives you from the system: ";
									cout << systempassword;
									cout << endl;
									cout << "Membership successfully completed, please log in" << endl << endl;
									goto first;
								}
								else if (g == 2)
								{
									cout << "\nPlase enter your user name" << endl;
									cin >> username;
									cout << "Dear " << username << " ," << endl;
									cout << "Welcome back again\n " << endl;

									int trying = 3;
								loop20:
									//Asking for determined password from user
									int testingPassword;
									cout << "Please enter password: " << endl;
									cin >> testingPassword;
									if (testingPassword == systempassword) {
										cout << "Dear " << username << "," << endl;

									}
									else if (trying == 1) {
										cout << "\nPassword is wrong. You have no trials to try. get new password.....\n";
										cout << "\nEnter 1 or 2!\n " << endl;
										goto first;
									}
									else {
										cout << "Password is wrong. You have " << trying - 1 << " trials to left..." << endl;
										trying--;
										goto loop20;
										return 0;
									}

								}
								else
								{
									cout << "\nInvalid number! Enter 1 or 2!\n " << endl;
									goto first;
								}
							}

							// Ask for payment method
							cout << "\n		Please select a payment method:" << endl;
							cout << "			1) Credit card" << endl;
							cout << "			2) Debit card" << endl;
							cout << "			3) Cash" << endl;
							cout << "			4) Bitcoin" << endl;
							cout << "			5) Cancel" << endl;
							cout << "			Choice: ";
							cin >> choice;
							cout << endl;

							// Process payment based on the selected method
							if (choice == "1" || choice == "2") {
								string cardNumber, cardExpiry, cardCVV;
								cout << "			Please enter your card number: ";
								cin >> cardNumber;
								cout << "			Please enter your card expiry date (MM/YY): ";
								cin >> cardExpiry;
								cout << "			Please enter your card CVV: ";
								cin >> cardCVV;

								// Process payment using a payment gateway or API
								// ...

								// Confirm payment
								cout << "			Payment confirmed. Thank you for your purchase!\n" << endl;
								cout << "           Hope to see you soon!" << endl;
							}
							else if (choice == "3") {
								double cashPaid;
								do {
									cout << "			Please enter the amount of cash paid: ";
									cin >> cashPaid;
								} while (cashPaid < total_price); // Make sure enough cash is paid

								// Calculate change
								double change = cashPaid - total_price;

								// Print receipt
								cout << "			Receipt:\n";
								cout << "			---------------------------\n";
								cout << "			Total: " << total_price << "$\n";
								cout << "			Paid: " << cashPaid << "$\n";
								cout << "			Change: " << change << "$\n";
								cout << "			---------------------------\n";

								// Confirm payment
								cout << "			Payment confirmed. Thank you for your purchase!\n" << endl;
								cout << "           Hope to see you soon!" << endl;
							}
							else if (choice == "4") {
								Bitcoin bitcoin;
								cout << "Please enter your Bitcoin address: ";
								cin >> bitcoin.address;
								cout << "Please enter the amount of Bitcoin to be paid: ";
								cin >> bitcoin.amount;

								// Process payment using a Bitcoin payment gateway or API
								// ...

								// Confirm payment
								cout << "Payment confirmed. Thank you for your purchase!\n" << endl;
								cout << "Hope to see you soon!" << endl;
							}
							else if (choice == "5") {
								cout << "			Payment cancelled. Order cancelled.\n" << endl;
								continue;
							}
							else {
								cout << "			Invalid choice. Order cancelled.\n" << endl;
								continue;
							}
							break;

						}
						else
						{
							cout << "Please select 1 or 2" << endl;
							continue;
						}
					}
					else if (choice == "4")
					{
						cout << "\n How many: ";
						cin >> choice_int;
						cout << endl;
						cout << "\n	  product is adding..." << endl;
						churros.stock_down(choice_int);
						Sleep(2000);
						if (controller == true)
						{
							sum_price(choice_int * churros.price);
							cout << "\n	  Total price is: " << total_price << "$\n\n" << endl;
						}
						Sleep(1000);
						cout << "Will you continue with the order (1) or proceed to the payment part? (2): ";
						cin >> choice;
						cout << endl;

						if (choice == "1")
						{
							Sleep(1000);
							continue;
						}
						else if (choice == "2")
						{

							cout << "\t\t1.Would you like to have a seat?" << endl;
							cout << "\t\t2.Would you like to order takeout?" << endl;
							cout << "\t\t please choose one of the option !" << endl;
							int ga;
							cin >> ga;
							if (ga == 1)
							{
								cout << "\tPlease enter the table number you will sit at" << endl;
								int tablenumber;
								cin >> tablenumber;
							}
							else if (ga == 2)
							{
								cout << "\t 1.Please login as a user." << endl;
								cout << "\t 2.If you are not a member, register." << endl;
								cout << "Please choose 1 or 2" << endl;


								string username;
								int systempassword = 123;
								int g;
								cin >> g;
								if (g == 1)
								{
									string username;
									int password;
									cout << "Please enter your user name" << endl;
									cin >> username;
									cout << "The password that gives you from the system: ";
									cout << systempassword;
									cout << endl;
									cout << "Membership successfully completed, please log in" << endl << endl;
									goto first;
								}
								else if (g == 2)
								{
									cout << "\nPlase enter your user name" << endl;
									cin >> username;
									cout << "Dear " << username << " ," << endl;
									cout << "Welcome back again\n " << endl;

									int trying = 3;
								loop21:
									//Asking for determined password from user
									int testingPassword;
									cout << "Please enter password: " << endl;
									cin >> testingPassword;
									if (testingPassword == systempassword) {
										cout << "Dear " << username << "," << endl;

									}
									else if (trying == 1) {
										cout << "\nPassword is wrong. You have no trials to try. get new password.....\n";
										cout << "\nEnter 1 or 2!\n " << endl;
										goto first;
									}
									else {
										cout << "Password is wrong. You have " << trying - 1 << " trials to left..." << endl;
										trying--;
										goto loop21;
										return 0;
									}

								}
								else
								{
									cout << "\nInvalid number! Enter 1 or 2!\n " << endl;
									goto first;
								}
							}

							// Ask for payment method
							cout << "\n		Please select a payment method:" << endl;
							cout << "			1) Credit card" << endl;
							cout << "			2) Debit card" << endl;
							cout << "			3) Cash" << endl;
							cout << "			4) Bitcoin" << endl;
							cout << "			5) Cancel" << endl;
							cout << "			Choice: ";
							cin >> choice;
							cout << endl;

							// Process payment based on the selected method
							if (choice == "1" || choice == "2") {
								string cardNumber, cardExpiry, cardCVV;
								cout << "			Please enter your card number: ";
								cin >> cardNumber;
								cout << "			Please enter your card expiry date (MM/YY): ";
								cin >> cardExpiry;
								cout << "			Please enter your card CVV: ";
								cin >> cardCVV;

								// Process payment using a payment gateway or API
								// ...

								// Confirm payment
								cout << "			Payment confirmed. Thank you for your purchase!\n" << endl;
								cout << "           Hope to see you soon!" << endl;
							}
							else if (choice == "3") {
								double cashPaid;
								do {
									cout << "			Please enter the amount of cash paid: ";
									cin >> cashPaid;
								} while (cashPaid < total_price); // Make sure enough cash is paid

								// Calculate change
								double change = cashPaid - total_price;

								// Print receipt
								cout << "			Receipt:\n";
								cout << "			---------------------------\n";
								cout << "			Total: " << total_price << "$\n";
								cout << "			Paid: " << cashPaid << "$\n";
								cout << "			Change: " << change << "$\n";
								cout << "			---------------------------\n";

								// Confirm payment
								cout << "			Payment confirmed. Thank you for your purchase!\n" << endl;
								cout << "           Hope to see you soon!" << endl;
							}
							else if (choice == "4") {
								Bitcoin bitcoin;
								cout << "Please enter your Bitcoin address: ";
								cin >> bitcoin.address;
								cout << "Please enter the amount of Bitcoin to be paid: ";
								cin >> bitcoin.amount;

								// Process payment using a Bitcoin payment gateway or API
								// ...

								// Confirm payment
								cout << "Payment confirmed. Thank you for your purchase!\n" << endl;
								cout << "Hope to see you soon!" << endl;
							}
							else if (choice == "5") {
								cout << "			Payment cancelled. Order cancelled.\n" << endl;
								continue;
							}
							else {
								cout << "			Invalid choice. Order cancelled.\n" << endl;
								continue;
							}
							break;

						}
						else
						{
							cout << "Please select 1 or 2" << endl;
							continue;
						}
					}
					else
					{
						cout << "Invalid request. Please choose between 1-4. " << endl << endl;
						continue;

					}
				}

			}
			else
			{

				cout << "Cultural Products are available only on weekends. Sorry about that..." << endl << endl << endl;
			}
		}
		else if (choice == "5") {
			string feedback;
			cout << "The thoughts of our precious customers are very necessary to us. Share any wishes, requests, or complaints with us:\n\n";
			cin.ignore();
			getline(cin, feedback);

			// Open file for writing
			ofstream file("customer_feedback.txt", ios::app);

			// Check if file is opened
			if (file.is_open()) {

				file << feedback << endl;
			}
			else if (!file.is_open()) {
				cout << "Error: Could not open file.";
			}



			// Close file
			file.close();

			cout << "\nThank you for sharing your thoughts with us. We are going to take note of every details that you wrote.\n";

			return 0;







		}
	}
}