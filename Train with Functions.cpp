#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>
#include<conio.h>

using namespace std;

void guidance() {
    cout << "\n\n\t\t\t****Welcome To Sami And Salman's Railway Station'****" << endl;
    cout << "\n\n\t\t\t\t\t****User Guide****" << endl;
    cout << "\t\t\t\t\tPut '-' instead of spaces" << endl;
    cout << "\t\t\t\t\tEnter valid inputs" << endl;
    cout << "\t\t\t\t\tCheck data in files too" << endl << endl;
    cout << "\t\t\t\t\tPress any key to continue....";
    getch();
    system("CLS");
}

void trainChoiceFun() {
    cout << "\n\n\t\t\tPress 1 to enter new train" << endl;
    cout << "\t\t\tPress 2 to check existing trains" << endl;
    cout << "\t\t\tPress 3 to search specific train" << endl;
    cout << "\t\t\tPress 4 back to dashboard" << endl;
    cout << "\t\t\t";
}

void dashboard() {
    cout << "\n\n\t\t\tPress 1 for train operations" << endl;
    cout << "\t\t\tPress 2 for booking options" << endl;
    cout << "\t\t\tPress 3 for logout" << endl;
    cout << "\t\t\t";
}

void bookingChoiceFun() {
    cout << "\n\n\t\t\tPress 1 for booking tickets" << endl;
    cout << "\t\t\tPress 2 for view booking" << endl;
    cout << "\t\t\tPress 3 for search booking" << endl;
    cout << "\t\t\tPress 4 back to dashboard" << endl;
    cout << "\t\t\t";
}

void signup() {
	
    ofstream fout("Authentication.txt", ios::app);
    ifstream fin("Authentication.txt");
    string username, password, admin;
    cout << "\n\n\t\t\tEnter name of admin: ";
    cin >> admin;
    label:
    cout << "\n\n\t\t\tEnter username: ";
    cin >> username;
    string x;
    while (fin >> x) {
        if (x == username) {
            cout << "\n\n\t\t\tThis username already exists, please enter a unique one" << endl;
            goto label;
        }
    }
    cout << "\n\n\t\t\tEnter password: ";
    cin >> password;
    fout << "Admin name: " << admin << endl;
    fout << "Username: " << username;
    fout << "  Password: " << password << endl;
    fout.close();
}

bool login() {
    ifstream fin("Authentication.txt");
    string username, password;
    cout << "\n\n\t\t\tEnter username: ";
    cin >> username;
    cout << "\n\n\t\t\tEnter password: ";
    cin >> password;
    string x;
    while (getline(fin, x)) {
        if (x == "Username: " + username + "  Password: " + password) {
            fin.close();
            return true;
        }
    }
    fin.close();
    return false;
}

void addNewTrain() {
    ofstream fout("TrainFile.txt", ios::app);
    string trainNumber, numberOfSeats, route, timing, rent;
    
    cout << "\t\t\tEnter train number: ";
    cin >> trainNumber;
    cout << "\t\t\tEnter number of seats: ";
    cin >> numberOfSeats;
    cout << "\t\t\tEnter route: ";
    cin >> route;
    cout << "\t\t\tEnter timings: ";
    cin >> timing;
    cout << "\t\t\tEnter rent: ";
    cin >> rent;
    
    fout << "Train number: " << trainNumber << endl;
    fout << "Number of seats: " << numberOfSeats << endl;
    fout << "Route: " << route << endl;
    fout << "Timing: " << timing << endl;
    fout << "Rent: " << rent << endl;
    fout << "_______________" << endl;
    fout.close();
}


void viewTrains() {
    ifstream fin("TrainFile.txt");
    string x;
    while (getline(fin, x)) {
        cout << "\t\t\t" << x << endl;
    }
    fin.close();
}

void searchTrain() {
    ifstream fin("TrainFile.txt");
    string search;
    cout << "\t\t\tEnter train number: ";
    cin >> search;
    string y;
    while (getline(fin, y)) {
        if (y == ("Train number: " + search)) {
            while (getline(fin, y)) {
                cout << y << endl;
                if (y == "_______________") {
                    break;
                }
            }
        }
    }
    fin.close();
}

void bookTicket() {
    ifstream fin("TrainFile.txt");
    ofstream fout("Tickets.txt", ios::app);
    cout << "\t\t\tEnter name of passenger: ";
    string nameOfPassenger,numberOfTickets,route;
    cin >> nameOfPassenger;
    cout << "\t\t\tEnter number of tickets: ";
    cin >> numberOfTickets;
    label:
    cout << "\t\t\tEnter route: ";
    cin >> route;
    string x;
    bool flag = false;
    while (getline(fin, x)) {
        if (x == "Route: " + route) {
            flag = true;
        }
    }
    if (!flag) {
        fin.close();
        cout << "\t\t\tNo such route found...";
        Sleep(2000);
        cout << endl;
        fin.open("TrainFile.txt");
        goto label;
    }
    fin.close();
    fout << "Passenger name: " << nameOfPassenger << endl;
    fout << "Number of tickets: " << numberOfTickets << endl;
    fout << "Route: " << route << endl;
    while (getline(fin, x)) {
        if (x == "Route: " + route) {
            while (getline(fin, x)) {
                if (x == "_______________") {
                    break;
                }
                fout << x << endl;
                cout << "\t\t\t" << x << endl;
            }
        }
    }
    fout << "_______________" << endl;
    fout.close();
}

void viewBookings() {
    ifstream fin("Tickets.txt");
    string x;
    while (getline(fin, x)) {
        cout << "\t\t\t" << x << endl;
    }
    fin.close();
}

void searchBooking() {
    ifstream fin("Tickets.txt");
    string search;
    cout << "\t\t\tEnter Name Of Passenger To Search: ";
    cin >> search;
    string y;
    while (getline(fin, y)) {
        if (y == ("Passenger name: " + search)) {
            while (getline(fin, y)) {
                cout << "\t\t\t" << y << endl;
                if (y == "_______________") {	
                    break;
                }
            }
        }
    }
    fin.close();
}


int main() {
    guidance();
    char choice;
    label:
    cout << "\t\t\t******TRAIN BOOKING SYSTEM******" << endl << endl;
    cout << "\t\t\tPress 1 to create a new account" << endl;
    cout << "\t\t\tPress 2 to login to an existing account" << endl;
    cout << "\t\t\t";
    choice = getch();
    system("CLS");
    switch (choice) {
        case '1':
            cout << "\n\n\t\t\tSIGNUP" << endl;
            signup();
            cout << "\n\n\t\t\tYour account has been created successfully" << endl;
            cout << "\n\n\t\t\tPress any key to continue.....";
            getch();
            system("CLS");
            goto label;
            break;
        case '2':
            system("CLS");
            cout << "\n\n\t\t\tLOGIN" << endl;
            if (!login()) {
                cout << "\n\n\t\t\t\aInvalid username and password" << endl;
                cout << "\n\n\t\t\tPlease try again....";
                Sleep(2000);
                goto label;
            }
            break;
        default:
            cout << "\n\n\t\t\tInvalid input, please try again...\a" << endl;
            Sleep(2000);
            system("CLS");
            goto label;
            break;
    }
    while (true) {
        dashboard:
        system("CLS");
        dashboard();
        choice = getch();
        system("CLS");
        switch (choice) {
            case '1':
                trainChoiceFun();
                choice = getch();
                cout << endl;
                if (choice == '1') {
                    addNewTrain();
                    cout << "\t\t\tNew train added...";
                    Sleep(2000);
                    goto dashboard;
                } else if (choice == '2') {
                    viewTrains();
                } else if (choice == '3') {
                    searchTrain();
                } else if (choice == '4') {
                    goto dashboard;
                } else {
                    cout << "Invalid input, please try again...\a" << endl;
                    Sleep(2000);
                    goto dashboard;
                }
                cout << "\t\t\tPress any key to continue...";
                getch();
                break;
            case '2':
                bookingChoiceFun();
                choice = getch();
                cout << endl;
                if (choice == '1') {
                    bookTicket();
                } else if (choice == '2') {
                    viewBookings();
                } else if (choice == '3') {
                    searchBooking();
                } else if (choice == '4') {
                    goto dashboard;
                } else {
                    cout << "Invalid input, please try again...\a" << endl;
                    Sleep(2000);
                    goto dashboard;
                }
                cout << "\t\t\tPress any key to continue...";
                getch();
                break;
            case '3':
                goto label;
                break;
        }
    }
    return 0;
}

