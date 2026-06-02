#include <iostream>
#include <time.h>
using namespace std;
// Arrays
const int userArrSize = 50;
string userName[userArrSize];
string password[userArrSize];
string role[userArrSize];
string dishes[userArrSize] = {"Pizza", "Burger", "Sandwich", "Shawarma", "Pasta","Fries","Macaroni",
"Chicken Nuggets", "Chicken Wings", "Biryani", "Pulao", "Karahi", "Paratha", "Nihari",
"Chicken Tikka", "Seekh Kabab", "Aloo Gosht", "Haleem", "Veg Salad", "Roti", "Samosas",
"Pakory", "Chaat","Gol Gappy","Tea","Coffee", "Cold Drinks", "Shakes", "Milk", "Mineral Water"};
int prices[userArrSize] =
{800, 350, 250, 220, 300, 180, 280, 400, 500, 250,
220, 900, 80, 350, 450, 400, 380, 300, 150, 25,
60, 80, 120, 100, 70, 120, 100, 220, 90, 50};
int quantity[userArrSize] = { 10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
10,10,10,10,10,10,10,10,10,10,10,10,10,10};
// Variables
int idxdishes = 30;
int idxprices = 30;
int idxQuantity = 30;
int usersCount = 0;
int loginchoice = 0;
int adminchoice = 0;
int userChoice = 0;
// Functions
int LoginMenu();
void admin();
void signup();
void SignIn();
void header();
void addMenu();
void updateMenu();
int getindex(string dish);
void deleteMenu();
void displayMenu();
int userMenu();
void user();
void orders();
main()
{
    while (loginchoice != 3)
    {
        header();
        loginchoice = LoginMenu();
        if (loginchoice == 1)
        {
            signup();
        }
        else if (loginchoice == 2)
        {
            SignIn();
        }
        else
        {
            cout << "Exiting The Program ";
        }
    }
}
int LoginMenu()
{
    int loginchoice;
    cout << "1.For SignUp" << endl;
    cout << "2.For SignIN " << endl;
    cout << "3.For exit " << endl;
    cout << "Please enter your choice :";
    cin >> loginchoice;
    return loginchoice;
}
void signup()
{
    cout << "Enter Name :";
    cin >> userName[usersCount];
    cout << "Enter Password :";
    cin >> password[usersCount];
    cout << "Enter your Role (admin or user) :";
    cin >> role[usersCount];
    usersCount++;
    cout << "SignUp Successfully " << endl;
}
int adminMenu()
{
    int adminchoice;
    cout << "Please enter Your Choice :" << endl;
    cout << "1.Add Menu " << endl;
    cout << "2.Update Menu " << endl;
    cout << "3.Delete Menu " << endl;
    cout << "4.Display Menu " << endl;
    cout << "5.Exit" << endl;
    cout << "Please Enter your Choice :";
    cin >> adminchoice;
    return adminchoice;
}
void SignIn()
{
    string Name, passwords;
    string adminId, adminPass;
    cout << "Enter Name :";
    cin >> Name;
    cout << "Enter Password :";
    cin >> passwords;
    for (int i = 0; i < usersCount; i++)
    {
        if (Name != userName[i] && passwords != password[i])
        {
            cout << "The username And Password you Entered Both are Wrong ";
            cout << "Please enter Again Both" << endl;
            cout << "Enter Name :";
            cin >> Name;
            cout << "Enter Password :";
            cin >> passwords;
        }
        if (Name == userName[i] && passwords != password[i])
        {
            cout << "The UserName you Entered is Correct But Password is incorrect ";
            cout << "Please enter Password Again " << endl;
            cout << "Enter Password :";
            cin >> passwords;
        }
        if (Name != userName[i] && passwords == password[i])
        {
            cout << "The Password you Entered is Correct But Username is incorrect ";
            cout << "So Enter Username Again " << endl;
            cout << "Enter Name :";
            cin >> Name;
        }
        if (Name == userName[i] && passwords == password[i])
        {
            if (role[i] == "admin")
            {
                int attempts;
                cout << "Please enter Admin ID :";
                cin >> adminId;
                cout << "Please enter Admin Password :";
                cin >> adminPass;
                attempts++;
                if (attempts <= 3)
                {
                    if (adminId != "Haseeb" && adminPass != "8899")
                    {
                        cout << "The Admin ID and Admin Pass you Entered Both Are wrong ";
                        cout << "So Enter Again Both " << endl;
                        cout << "Please enter Admin ID :";
                        cin >> adminId;
                        cout << "Please enter Admin Password :";
                        cin >> adminPass;
                    }
                    if (adminId == "Haseeb" && adminPass != "8899")
                    {
                        cout << "The Admin ID You Entered Is correct But The Admin Pass is Incorrect ";
                        cout << "So Enter the Admin Pass Again" << endl;
                        cout << "Please enter Admin Password :";
                        cin >> adminPass;
                    }
                    if (adminId != "Haseeb" && adminPass == "8899")
                    {
                        cout << "The Admin Pass You Entered is correct  But The Admin ID is Wrong ";
                        cout << "So Again Enter The Admin ID " << endl;
                        cout << "Please enter Admin ID :";
                        cin >> adminId;
                    }

                    if (adminId == "Haseeb" && adminPass == "8899")
                    {
                        cout << "Congratulations SignIn Successfully ";
                        admin();
                    }
                }
                else
                {
                    cout << "You Have tried Maximum Times! Please try Again Later ";
                }
            }
            if (role[i] == "user")
            {
                user();
            }
            if (role[i] != "admin" || role[i] != "user")
            {
                cout << "Please enter a Defined User or Admin ";
            }
        }
    }
}
void admin()
{
    while (adminchoice != 5)
    {
        adminchoice = adminMenu();
        if (adminchoice == 1)
        {
            addMenu();
        }
        if (adminchoice == 2)
        {
            updateMenu();
        }
        if (adminchoice == 3)
        {
            deleteMenu();
        }
        if (adminchoice == 4)
        {
            displayMenu();
        }
    }
}
void addMenu()
{
    cout << "Enter the Dish Name: ";
    cin.ignore();
    getline(cin, dishes[idxdishes]);
    int idx = getindex(dishes[idxdishes]);
    if (idx == -1)
    {
    cout << "Enter the Dish Price: ";
    cin >> prices[idxdishes];
    cout << "Please enter Dish Quantity :";
    cin >> quantity[idxdishes];
    idxdishes++;
    cout << "Dish Added Successfully " << endl;
    }
    else
    {
        cout << "This Dish Already Exists " << endl;
    }
}
void updateMenu()
{
    string dish;
    cout << "Enter the Dish Name you want to Update: ";
    cin.ignore();
    getline(cin, dish);
    int idx = getindex(dish);
    if (idx == -1)
    {
        cout << "This dish is not available" << endl;
    }
    else
    {
        cout << "The old Price of Item is :" << prices[idx] << endl;
        cout << "Enter the Dish (" << dish << ") New Price: ";
        cin >> prices[idx];
        cout << "Please enter the New Quantity :";
        cin >> quantity[idx];
        cout << "Updated successfully" << endl;
    }
}
int getindex(string dish)
{
    int index = -1;
    for (int i = 0; i < idxdishes; i++)
    {
        if (dish == dishes[i])
        {
            index = i;
        }
    }
    return index;
}

void header()
{
    cout << __DATE__ << endl;
    cout << __TIME__ << endl;
    cout << "***********************************" << endl;
    cout << "*    CAFETERIA BILLING SYSTEM     *" << endl;
    cout << "***********************************" << endl;
}
void deleteMenu()
{
    string dish;
    cout << "Enter the Dish Name you want to Delete: ";
    cin >> dish;
    int index = getindex(dish);
    if (index == -1)
    {
        cout << "The Dish is Not Found " << endl;
    }
    else
    {
        for (int i = index; i < idxdishes; i++)
        {
            dishes[i] = dishes[i + 1];
            prices[i] = prices[i + 1];
            quantity[i] = quantity[i + 1];
        }
        idxdishes--;
        cout << "ITEM Deleted Successfully " << endl;
    }
}
int userMenu()
{
    int userChoice = 0;
    cout << "1.Display Menu " << endl;
    cout << "2.Order " << endl;
    cout << "3.Exit " << endl;
    cout << "Please enter Your Choice :";
    cin >> userChoice;
    return userChoice;
}
void user()
{
    while (userChoice != 3)
    {
        userChoice = userMenu();
        if (userChoice == 1)
        {
            displayMenu();
        }
        if (userChoice == 2)
        {
            orders();
        }
    }
}
void orders()
{
    int orderChoice;
    int orderQuantity;
    string choice;
    int totalbill = 0;
    int bill = 0;
    do
    {
    displayMenu();
    cout << endl;
    cout << "Please Enter Dish Number :";
    cin >> orderChoice;
    orderChoice--;
    if(orderChoice >= 0 && orderChoice < idxdishes)
    {
        cout << "Please Enter Order quantity :";
        cin >> orderQuantity;
        if(orderQuantity <= quantity[orderChoice])
        {
        bill = prices[orderChoice] * orderQuantity;
        totalbill = totalbill + bill;
        cout << endl;
        cout << "Dish :" << dishes[orderChoice] << endl;
        cout << "Price :" << prices[orderChoice] << endl;
        cout << "Quantity :" << orderQuantity << endl;
        cout << "Bill :" << bill <<endl;
        quantity[orderChoice] = quantity[orderChoice] - orderQuantity;
        }
        else
        {
            cout << "Not Enough Dishes Available Only Available :" << quantity[orderChoice] << endl; 
        }
    } 
    else
    {
        cout << "Invalid Dish Number !!";
    }
    cout << endl;
    cout << "Do you want to like order more :";
    cin >> choice;
    }while(choice == "yes" || choice == "Yes");
    cout << endl;
    cout << " ============================== " << endl;
    cout << " Final Bill : Rs." << totalbill << endl;
    cout << " ============================== " << endl;
}
void displayMenu()
{
    for (int i = 0; i < idxdishes; i++)
    {
        cout << 1 + i << ". " << dishes[i];
        cout << " -Rs." << prices[i] <<" | Total Available : " << quantity[i]<< endl;
    }
}