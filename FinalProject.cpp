#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>

using namespace std;

class shopping {
private:
    int pcode;
    float price;
    float dis;
    string pname;
    int productQuantity;
    map<int, pair<float, int>> inventory; 

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
    void updateInventory(int productCode, int quantity);  // Function Declaration
};

void shopping::menu() {
        m:
    int choice;
    string email;
    string password;

    cout << "\t\t\t\t______________________________________________\n";
    cout << "\t\t\t\t                                              \n";
    cout << "\t\t\t\t         Anaksh Tuck Shop Main Menu              \n";
    cout << "\t\t\t\t                                               \n";
    cout << "\t\t\t\t_______________________________________________\n";
    cout << "\t\t\t\t|          1) Administrator                      |\n";
    cout << "\t\t\t\t|                                             |\n";
    cout << "\t\t\t\t|          2) Buyer                            |\n";
    cout << "\t\t\t\t|                                             |\n";
    cout << "\t\t\t\t|          3) Exit                             |\n";
    cout << "\n\t\t\t Please Select ";
    cin >> choice;
    switch (choice) {
        case 1:
            cout << "Please Enter Email:-\t";
            cin >> email;
            cout << "Please Enter Password:\t";
            cin >> password;
            if ((email == "Lakshay@gmail.com" && password == "2424") || (email == "Ananya01@gmail.com" && password == "0101"))
                administrator();

            else
                cout << "Please Enter Correct Email or Password \n";
            break;
        case 2:
            buyer();
            break;
        case 3:
            exit(0);
        default:
            cout << "Please enter a Valid Choice";
    }
    goto m;
    //Your existing menu function code
}

void shopping::administrator() {
    m:
    int choice;
    cout << "\n\n\n\t\t\tAdministrator Menu";
    cout << "\n\t\t\t|_____1) Add The Product_____________|";
    cout << "\n\t\t\t|                                    |";
    cout << "\n\t\t\t|_____2) Modify The Product__________|";
    cout << "\n\t\t\t|                                    |";
    cout << "\n\t\t\t|_____3) Delete The Product__________|";
    cout << "\n\t\t\t|                                    |";
    cout << "\n\t\t\t|_____4) Back Menu___________________|";

    cout << "\nPlease Enter The Choice: ";
    cin >> choice;
    switch (choice) {
        case 1:
            add();
            break;
        case 2:
            edit();
            break;
        case 3:
            rem();
            break;
        case 4:
            menu();
            break;
        default:
            cout << "Invalid Choice";
    }
    goto m;
    //Your existing administrator function code
}

void shopping::buyer() {
     m:
    int choice;
    cout << "\t\t\tBuyer   \n";
    cout << "\t\t\t__________\n";
    cout << "\t\t\t           \n";
    cout << "\t\t\t1) Buy Product   \n";
    cout << "\t\t\t           \n";
    cout << "\t\t\t2) Go Back\n";
    cout << "\t\t\t           \n";
    cout << "Please Enter Choice: ";
    cin >> choice;
    switch (choice) {
        case 1:
            receipt();
            break;
        case 2:
            menu();
            break;
        default:
            cout << "Invalid Choice";
    }
    goto m;
    //Your existing buyer function code
}

void shopping::add() {
     m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;
    float productPrice; // Added to store the product price
    int productQuantity; // Added to store the product quantity

    cout << "\n\n\t\t\t Add new Product";
    cout << "\n\n\tProduct Code of The Product:\t";
    cin >> pcode;
    cout << "\n\n\tEnter Product name:\t";
    cin >> pname;
    cout << "\n\n\tEnter Product price:\t";
    cin >> productPrice; // Store product price
    cout << "\n\n\tEnter Product Discount:\t";
    cin >> dis;
    cout << "\n\n\tEnter Product Quantity:\t";
    cin >> productQuantity; // Store product quantity

    data.open("C:\\Users\\Mindventor\\OneDrive\\Desktop\\c++\\database.txt", ios::in);
    if (!data) {
        data.open("C:\\Users\\Mindventor\\OneDrive\\Desktop\\c++\\database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << productPrice << " " << dis << " " << productQuantity << "\n";
        data.close();
    } else {
        data >> c >> n >> p >> d >> productQuantity;
        while (!data.eof()) {
            if (c == pcode)
                token++;
            data >> c >> n >> p >> d >> productQuantity;
        }
        data.close();
        if (token == 1) {
            goto m;
        } else {
            data.open("C:\\Users\\Mindventor\\OneDrive\\Desktop\\c++\\database.txt", ios::app | ios::out);
            data << " " << pcode << " " << pname << " " << productPrice << " " << dis << " " << productQuantity << "\n";
            data.close();
        }
    }
    cout << "\n\n\tRecord inserted";
    //Your existing add function code
}

void shopping::edit() {
    fstream data;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;
    int productQuantity; // Added to store the product quantity
    cout << "\n\t\t\tModify the Record";
    cout << "\n\t\t\tProduct Code";
    cin >> pkey;

    data.open("C:\\Users\\Mindventor\\OneDrive\\Desktop\\c++\\database.txt", ios::in);
    if (!data) {
        cout << "\n File Doesn't Exist";
    } else {
        data.open("C:\\Users\\Mindventor\\OneDrive\\Desktop\\c++\\database.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis >> productQuantity;
        while (!data.eof()) {
            if (pkey == pcode) {
                cout << "\n\t\tEnter Product New Code";
                cin >> c;
                cout << "\n\t\t Name of product";
                cin >> n;
                cout << "\n\t\tPrice";
                cin >> p;
                cout << "\n\t\tDiscount";
                cin >> d;
                cout << "\n\t\tEnter Product Quantity:";
                cin >> productQuantity;
                data << " " << c << " " << n << " " << p << " " << d << " " << productQuantity << "\n";
                cout << "Record Editted";
                token++;
            } else {
                data << " " << pcode << " " << pname << " " << price << " " << dis << " " << productQuantity << "\n";
            }
            data >> pcode >> pname >> price >> dis >> productQuantity;
        }
        data.close();
        if (token == 0) {
            cout << "\n\nRecord Not Found !";
        }
    }
    //Your existing edit function code
}

void shopping::rem() {
    fstream data, data1;
    int pkey;
    int token = 0;
    cout << "\n\n\t Delete a Product";
    cout << "\n\n\t Enter The Product Code:";
    cin >> pkey;
    data.open("C:\\Users\\Mindventor\\OneDrive\\Desktop\\c++\\database.txt", ios::in);
    if (!data) {
        cout << "\nFile Doesn't Exist";
    } else {
        data.open("C:\\Users\\Mindventor\\OneDrive\\Desktop\\c++\\database.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis >> productQuantity;
        while (!data.eof()) {
            if (pcode == pkey) {
                cout << "\n\n\tProduct Deleted Successfully";
                token++;
            } else {
                data << " " << pcode << " " << pname << " " << price << " " << dis << " " << productQuantity << "\n";
            }
            data >> pcode >> pname >> price >> dis >> productQuantity;
        }
        data.close();
        if (token == 0) {
            cout << "\n\nRecord Not found";
        }
    }
    //Your existing rem function code
}

void shopping::list() {
    fstream data;
    data.open("C:\\Users\\Mindventor\\OneDrive\\Desktop\\c++\\database.txt", ios::in);
    cout << "\n\n|______________________________________\n";
    cout << "ProNo\t\tName\t\tPrice\tQuantity\n";
    cout << "\n\n|______________________________________\n";
    data >> pcode >> pname >> price >> dis >> productQuantity;
    while (!data.eof()) {
        cout << pcode << "\t\t" << pname << "\t\t" << price << "\t" << productQuantity << "\n";
        data >> pcode >> pname >> price >> dis >> productQuantity;
    }
    data.close();
    //Your existing list function code
}

/**
 * This function displays a receipt for the items purchased by the user.
 * It prompts the user to enter the product code and quantity of each item they want to purchase.
 * It then calculates the total amount with discount for each item and displays it in a table format.
 * Finally, it updates the inventory with the remaining quantity of each item and displays the total amount of the purchase.
 */
void shopping::receipt() {

    fstream data;
    m:
    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;

    cout << "\n\n\t\t\t\t Receipt";
    data.open("C:\\Users\\Mindventor\\OneDrive\\Desktop\\c++\\database.txt", ios::in);
    
    if (!data) {
        cout << "\n\n Empty Database";
        return;
    } 
    else {
        data.close();
        list();
        
        cout << "\n_______________________________\n";
        cout << "\n|                              \n";
        cout << "\n       please place Order      \n";
        cout << "\n|                              \n";
        cout << "\n_______________________________\n";
        
        do {
            cout << "\n\nEnter The Product code: ";
            cin >> arrc[c];
            cout << "\nEnter Product Quantity: ";
            cin >> arrq[c];
            
            for (int i = 0; i < c; i++) {
                if (arrc[c] == arrc[i]) {
                    cout << "\n\nDuplicate Product code. Please re-enter";
                    goto m;
                }
            }
            
            c++;
            cout << "\n\n Do you want to buy another Product? If yes, then press 'y' else 'n': ";
            cin >> choice;
            
        } while (choice == 'y');
        
        cout << "\n\n\t\t________________________________Receipt__________________________________\n";
        cout << "\nProduct No\t Product Name\t Product Quantity\t Price\t Amount\t Amount with discount\n";
        
        data.open("C:\\Users\\Mindventor\\OneDrive\\Desktop\\c++\\database.txt", ios::in);
        
        if (!data) {
            cout << "\n\n Empty Database";
            return;
        } 
        
        while (data >> pcode >> pname >> price >> dis >> productQuantity) {
            for (int i = 0; i < c; i++) {
                if (pcode == arrc[i]) {
                    int productPrice = price;
                    int remainingQuantity = productQuantity;

                    if (arrq[i] <= remainingQuantity) {
                        amount = productPrice * arrq[i];
                        dis = amount - (amount * dis / 100);
                        total += dis;
                        
                        // Update the remaining quantity in the inventory
                        remainingQuantity -= arrq[i];
                        updateInventory(pcode, remainingQuantity);
                        
                        cout << pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t" << productPrice << "\t" << amount << "\t\t" << dis << "\n";
                        
                    } else {
                        cout << "\n\nQuantity not available for product code: " << arrc[i];
                    }
                }
            }
        }
        
        data.close();
    }
    
    cout << "\n\n________________________________________";
    cout << "\n Total Amount: " << total;
}


void shopping::updateInventory(int productCode, int quantity) {
    if (inventory.find(productCode) != inventory.end()) {
        int currentQuantity = inventory[productCode].second;
        if (currentQuantity >= quantity) {
            inventory[productCode].second -= quantity;
            cout << "Product quantity updated for product code " << productCode << endl;
        } else {
            cout << "Insufficient quantity for product code " << productCode << endl;
        }
    } 
}

int main() {
    shopping s;
    s.menu();
}
