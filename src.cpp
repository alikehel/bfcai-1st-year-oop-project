//*************************************************************
// PROJECT --> COMPUTER STORE MANAGEMENT SYSTEM BY ALI KEHEL
//*************************************************************

//**********************************************************
// INCLUDED HEADER FILES
//**********************************************************

#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

//************************************************************************
// CLASS NAME : Product
// DETAILS : IT HAS ALL THE PROPERTIES AND METHODS FOR ALL THE PRODUCTS.
//************************************************************************

class Product {
  protected:
  int code;
  string name;
  float price;
  int quantity;
  int purchase_date_day;
  int purchase_date_month;
  int purchase_date_year;
  float warranty;

  public:
  Product();
  Product(int, string, float, int, float);
  void add_product();
  void delete_product();
  void modify_product();
  void purchase_product();
  void list_products();
};

//**************************************************************************************
// CLASS NAME : Cpu_Product
// DETAILS : IT HAS ALL THE PROPERTIES AND METHODS FOR ALL THE PROCESSORS.
//			 IT ALSO INHERITS THE PROPERTIES AND METHODS FROM THE MAIN PRODUCT CLASS.
//**************************************************************************************

// Inheritence
class Cpu_Product : public Product {
  private:
  int cores;
  int threads;
  float cache;
  float clock;

  public:
  Cpu_Product();
  Cpu_Product(int, int, float, float);
  void add_product();
  void delete_product();
  void modify_product();
  void purchase_product();
  void list_products();
};

//**************************************************************************************
// CLASS NAME : Gpu_Product
// DETAILS : IT HAS ALL THE PROPERTIES AND METHODS FOR ALL THE GRAPHIC CARDS.
//			 IT ALSO INHERITS THE PROPERTIES AND METHODS FROM THE MAIN PRODUCT CLASS.
//**************************************************************************************

// Inheritence
class Gpu_Product : public Product {
  private:
  int memory;
  float clock;

  public:
  Gpu_Product();
  Gpu_Product(int, float);
  void add_product();
  void delete_product();
  void modify_product();
  void purchase_product();
  void list_products();
};

//***************************************************************************
// ALL OF THE COMING FUNCTIONS HAVE THE SAME NAME BUT THEY DO DIFFERENT THINGS.
// POLYMORPHISM & FUNCTION OVERWRRIDING $ FUNCTION OVERLOADING
//***************************************************************************

Product::Product()
{
  code = 0;
  name = "Unknown";
  price = 0;
  quantity = 0;
  warranty = 0;
}

Product::Product(int c, string n, float p, int q, float w)
{
  code = c;
  name = n;
  price = p;
  quantity = q;
  warranty = w;
}

Cpu_Product::Cpu_Product()
{
  cores = 0;
  threads = 0;
  cache = 0;
  clock = 0;
}

Cpu_Product::Cpu_Product(int c, int t, float ca, float clk)
{
  cores = c;
  threads = t;
  cache = ca;
  clock = clk;
}

Gpu_Product::Gpu_Product()
{
  memory = 0;
  clock = 0;
}

Gpu_Product::Gpu_Product(int m, float c)
{
  memory = m;
  clock = c;
}

//***************************************************************************
// THESE FUNCTIONS ARE RESPONSIBLE FOR ADDING NEW PRODUCTS IN THE DATABASE.
//***************************************************************************

void Product::add_product()
{
  cout << endl;
  cout << "Enter the code of the product : ";
  cin >> code;
  cout << "Enter the name of the product (replace spaces with underscores) : ";
  cin >> name;
  cout << "Enter the price of the product : ";
  cin >> price;
  cout << "Enter the quantity of the product : ";
  cin >> quantity;
  cout << "Enter the warranty of the product : ";
  cin >> warranty;
  ofstream products_file("products.dat", ios::app);
  products_file << code << " " << name << " " << price << " " << quantity << " " << warranty << endl;
  products_file.close();
}

void Cpu_Product::add_product()
{
  cout << endl;
  cout << "Enter the code of the product : ";
  cin >> code;
  cout << "Enter the name of the product (replace spaces with underscores) : ";
  cin >> name;
  cout << "Enter the price of the product : ";
  cin >> price;
  cout << "Enter the quantity of the product : ";
  cin >> quantity;
  cout << "Enter the warranty of the product : ";
  cin >> warranty;
  cout << "Enter the number of cores of the product : ";
  cin >> cores;
  cout << "Enter the number of the threads of the product : ";
  cin >> threads;
  cout << "Enter the cache size of the product : ";
  cin >> cache;
  cout << "Enter the clock speed of the product : ";
  cin >> clock;
  ofstream cpu_products_file("cpu_products.dat", ios::app);
  cpu_products_file << code << " " << name << " " << price << " " << quantity << " " << warranty << " " << cores << " " << threads << " " << cache << " " << clock << endl;
  cpu_products_file.close();
}

void Gpu_Product::add_product()
{
  cout << endl;
  cout << "Enter the code of the product : ";
  cin >> code;
  cout << "Enter the name of the product (replace spaces with underscores) : ";
  cin >> name;
  cout << "Enter the price of the product : ";
  cin >> price;
  cout << "Enter the quantity of the product : ";
  cin >> quantity;
  cout << "Enter the warranty of the product : ";
  cin >> warranty;
  cout << "Enter the memory size of the product : ";
  cin >> memory;
  cout << "Enter the clock speed of the product : ";
  cin >> clock;
  ofstream gpu_products_file("gpu_products.dat", ios::app);
  gpu_products_file << code << " " << name << " " << price << " " << quantity << " " << warranty << " " << memory << " " << clock << endl;
  gpu_products_file.close();
}

//***************************************************************************
// THESE FUNCTIONS ARE RESPONSIBLE FOR DELETING PRODUCTS FROM THE DATABASE.
//***************************************************************************

void Product::delete_product()
{
  list_products();
  int c;
  cout << "Type the code of the product that you want to delete : ";
  cin >> c;
  cout << endl;
  ifstream products_file("products.dat");
  ofstream new_products_file("new_products.dat", ios::app);
  if (!products_file.is_open()) {
    cout << "Error opening the file";
  } else {
    while (products_file >> code >> name >> price >> quantity >> warranty) {
      if (c != code) {
        new_products_file << code << " " << name << " " << price << " " << quantity << " " << warranty << endl;
      }
    }
  }
  products_file.close();
  new_products_file.close();
  remove("products.dat");
  rename("new_products.dat", "products.dat");
}

void Cpu_Product::delete_product()
{
  list_products();
  int c;
  cout << "Type the code of the product that you want to delete : ";
  cin >> c;
  cout << endl;
  ifstream cpu_products_file("cpu_products.dat");
  ofstream new_cpu_products_file("new_cpu_products.dat", ios::app);
  if (!cpu_products_file.is_open()) {
    cout << "Error opening the file";
  } else {
    while (cpu_products_file >> code >> name >> price >> quantity >> warranty >> cores >> threads >> cache >> clock) {
      if (c != code) {
        new_cpu_products_file << code << " " << name << " " << price << " " << quantity << " " << warranty << " " << cores << " " << threads << " " << cache << " " << clock << endl;
      }
    }
  }
  cpu_products_file.close();
  new_cpu_products_file.close();
  remove("cpu_products.dat");
  rename("new_cpu_products.dat", "cpu_products.dat");
}

void Gpu_Product::delete_product()
{
  list_products();
  int c;
  cout << "Type the code of the product that you want to delete : ";
  cin >> c;
  cout << endl;
  ifstream gpu_products_file("gpu_products.dat");
  ofstream new_gpu_products_file("new_gpu_products.dat", ios::app);
  if (!gpu_products_file.is_open()) {
    cout << "Error opening the file";
  } else {
    while (gpu_products_file >> code >> name >> price >> quantity >> warranty >> memory >> clock) {
      if (c != code) {
        new_gpu_products_file << code << " " << name << " " << price << " " << quantity << " " << warranty << " " << memory << " " << clock << endl;
      }
    }
  }
  gpu_products_file.close();
  new_gpu_products_file.close();
  remove("gpu_products.dat");
  rename("new_gpu_products.dat", "gpu_products.dat");
}

//***************************************************************************
// THESE FUNCTIONS ARE RESPONSIBLE FOR MODIFYING PRODUCTS IN THE DATABASE.
//***************************************************************************

void Product::modify_product()
{
  list_products();
  int c;
  cout << "Type the code of the product that you want to modify : ";
  cin >> c;
  cout << endl;
  ifstream products_file("products.dat");
  ofstream new_products_file("new_products.dat", ios::app);
  if (!products_file.is_open()) {
    cout << "Error opening the file";
  } else {
    while (products_file >> code >> name >> price >> quantity >> warranty) {
      if (c != code) {
        new_products_file << code << " " << name << " " << price << " " << quantity << " " << warranty << endl;
      } else {
        cout << "Enter the new code : ";
        cin >> code;
        cout << "Enter the new name (replace spaces with underscores) : ";
        cin >> name;
        cout << "Enter the new price : ";
        cin >> price;
        cout << "Enter the new quantity : ";
        cin >> quantity;
        cout << "Enter the new warranty : ";
        cin >> warranty;
        new_products_file << code << " " << name << " " << price << " " << quantity << " " << warranty << endl;
      }
    }
  }
  products_file.close();
  new_products_file.close();
  remove("products.dat");
  rename("new_products.dat", "products.dat");
}

void Cpu_Product::modify_product()
{
  list_products();
  int c;
  cout << "Type the code of the product that you want to modify : ";
  cin >> c;
  cout << endl;
  ifstream cpu_products_file("cpu_products.dat");
  ofstream new_cpu_products_file("new_cpu_products.dat", ios::app);
  if (!cpu_products_file.is_open()) {
    cout << "Error opening the file";
  } else {
    while (cpu_products_file >> code >> name >> price >> quantity >> warranty >> cores >> threads >> cache >> clock) {
      if (c != code) {
        new_cpu_products_file << code << " " << name << " " << price << " " << quantity << " " << warranty << " " << cores << " " << threads << " " << cache << " " << clock << endl;
      } else {
        cout << "Enter the new code : ";
        cin >> code;
        cout << "Enter the new name (replace spaces with underscores) : ";
        cin >> name;
        cout << "Enter the new price : ";
        cin >> price;
        cout << "Enter the new quantity : ";
        cin >> quantity;
        cout << "Enter the new warranty : ";
        cin >> warranty;
        cout << "Enter the new number of cores of the product : ";
        cin >> cores;
        cout << "Enter the new number of the threads of the product : ";
        cin >> threads;
        cout << "Enter the new cache size of the product : ";
        cin >> cache;
        cout << "Enter the new clock speed of the product : ";
        cin >> clock;
        new_cpu_products_file << code << " " << name << " " << price << " " << quantity << " " << warranty << " " << cores << " " << threads << " " << cache << " " << clock << endl;
      }
    }
  }
  cpu_products_file.close();
  new_cpu_products_file.close();
  remove("cpu_products.dat");
  rename("new_cpu_products.dat", "cpu_products.dat");
}

void Gpu_Product::modify_product()
{
  list_products();
  int c;
  cout << "Type the code of the product that you want to modify : ";
  cin >> c;
  cout << endl;
  ifstream gpu_products_file("gpu_products.dat");
  ofstream new_gpu_products_file("new_gpu_products.dat", ios::app);
  if (!gpu_products_file.is_open()) {
    cout << "Error opening the file";
  } else {
    while (gpu_products_file >> code >> name >> price >> quantity >> warranty >> memory >> clock) {
      if (c != code) {
        new_gpu_products_file << code << " " << name << " " << price << " " << quantity << " " << warranty << " " << memory << " " << clock << endl;
      } else {
        cout << "Enter the new code : ";
        cin >> code;
        cout << "Enter the new name (replace spaces with underscores) : ";
        cin >> name;
        cout << "Enter the new price : ";
        cin >> price;
        cout << "Enter the new quantity : ";
        cin >> quantity;
        cout << "Enter the new warranty : ";
        cin >> warranty;
        cout << "Enter the new memory size of the product : ";
        cin >> memory;
        cout << "Enter the new clock speed of the product : ";
        cin >> clock;
        new_gpu_products_file << code << " " << name << " " << price << " " << quantity << " " << warranty << " " << memory << " " << clock << endl;
      }
    }
  }
  gpu_products_file.close();
  new_gpu_products_file.close();
  remove("gpu_products.dat");
  rename("new_gpu_products.dat", "gpu_products.dat");
}

//***************************************************************************
// THESE FUNCTIONS ARE RESPONSIBLE FOR PURCHASING PRODUCTS.
//***************************************************************************

void Product::purchase_product()
{
  list_products();
  int c;
  cout << "Type the code of the product that you want to purchase : ";
  cin >> c;
  cout << endl;
  ifstream products_file("products.dat");
  ofstream new_products_file("new_products.dat", ios::app);
  if (!products_file.is_open()) {
    cout << "Error opening the file";
  } else {
    while (products_file >> code >> name >> price >> quantity >> warranty) {
      if (c != code) {
        new_products_file << code << " " << name << " " << price << " " << quantity << " " << warranty << endl;
      } else {
        quantity--;
        if (quantity != 0) {
          new_products_file << code << " " << name << " " << price << " " << quantity << " " << warranty << endl;
        }

        time_t ttime = time(0);
        tm* local_time = localtime(&ttime);
        purchase_date_day = local_time->tm_mday;
        purchase_date_month = 1 + local_time->tm_mon;
        purchase_date_year = 1900 + local_time->tm_year;

        ofstream purchased_products_file("purchased_products.dat", ios::app);
        if (!purchased_products_file.is_open()) {
          cout << "Error opening the file";
        } else {
          purchased_products_file << code << " " << name << " " << price << " " << quantity << " " << warranty << " " << purchase_date_day << " " << purchase_date_month << " " << purchase_date_year << endl;
        }
        purchased_products_file.close();
      }
    }
  }
  cout << "You purchased the product successfully :)" << endl;
  cout << "Press any key to continue...";
  _getch();
  products_file.close();
  new_products_file.close();
  remove("products.dat");
  rename("new_products.dat", "products.dat");
}

void Cpu_Product::purchase_product()
{
  list_products();
  int c;
  cout << "Type the code of the product that you want to purchase : ";
  cin >> c;
  cout << endl;
  ifstream cpu_products_file("cpu_products.dat");
  ofstream new_cpu_products_file("new_cpu_products.dat", ios::app);
  if (!cpu_products_file.is_open()) {
    cout << "Error opening the file";
  } else {
    while (cpu_products_file >> code >> name >> price >> quantity >> warranty) {
      if (c != code) {
        new_cpu_products_file << code << " " << name << " " << price << " " << quantity << " " << warranty << " " << cores << " " << threads << " " << cache << " " << clock << endl;
      } else {
        quantity--;
        if (quantity != 0) {
          new_cpu_products_file << code << " " << name << " " << price << " " << quantity << " " << warranty << " " << cores << " " << threads << " " << cache << " " << clock << endl;
        }

        time_t ttime = time(0);
        tm* local_time = localtime(&ttime);
        purchase_date_day = local_time->tm_mday;
        purchase_date_month = 1 + local_time->tm_mon;
        purchase_date_year = 1900 + local_time->tm_year;

        ofstream purchased_cpu_products_file("purchased_cpu_products.dat", ios::app);
        if (!purchased_cpu_products_file.is_open()) {
          cout << "Error opening the file";
        } else {
          purchased_cpu_products_file << code << " " << name << " " << price << " " << quantity << " " << warranty << " " << cores << " " << threads << " " << cache << " " << clock << " ";
          purchased_cpu_products_file << purchase_date_day << " " << purchase_date_month << " " << purchase_date_year << endl;
        }
        purchased_cpu_products_file.close();
      }
    }
  }
  cout << "You purchased the product successfully :)" << endl;
  cout << "Press any key to continue...";
  _getch();
  cpu_products_file.close();
  new_cpu_products_file.close();
  remove("cpu_products.dat");
  rename("new_cpu_products.dat", "cpu_products.dat");
}

void Gpu_Product::purchase_product()
{
  list_products();
  int c;
  cout << "Type the code of the product that you want to purchase : ";
  cin >> c;
  cout << endl;
  ifstream gpu_products_file("gpu_products.dat");
  ofstream new_gpu_products_file("new_gpu_products.dat", ios::app);
  if (!gpu_products_file.is_open()) {
    cout << "Error opening the file";
  } else {
    while (gpu_products_file >> code >> name >> price >> quantity >> warranty) {
      if (c != code) {
        new_gpu_products_file << code << " " << name << " " << price << " " << quantity << " " << warranty << " " << memory << " " << clock << endl;
      } else {
        quantity--;
        if (quantity != 0) {
          new_gpu_products_file << code << " " << name << " " << price << " " << quantity << " " << warranty << " " << memory << " " << clock << endl;
        }

        time_t ttime = time(0);
        tm* local_time = localtime(&ttime);
        purchase_date_day = local_time->tm_mday;
        purchase_date_month = 1 + local_time->tm_mon;
        purchase_date_year = 1900 + local_time->tm_year;

        ofstream purchased_gpu_products_file("purchased_gpu_products.dat", ios::app);
        if (!purchased_gpu_products_file.is_open()) {
          cout << "Error opening the file";
        } else {
          purchased_gpu_products_file << code << " " << name << " " << price << " " << quantity << " " << warranty << " " << memory << " " << clock << " ";
          purchased_gpu_products_file << purchase_date_day << " " << purchase_date_month << " " << purchase_date_year << endl;
        }
        purchased_gpu_products_file.close();
      }
    }
  }
  cout << "You purchased the product successfully :)" << endl;
  cout << "Press any key to continue...";
  _getch();
  gpu_products_file.close();
  new_gpu_products_file.close();
  remove("gpu_products.dat");
  rename("new_gpu_products.dat", "gpu_products.dat");
}

//***************************************************************************
// THESE FUNCTIONS ARE RESPONSIBLE FOR VIWING ALL THE AVAILABLE PRODUCTS.
//***************************************************************************

void Product::list_products()
{
  cout << endl;
  cout << "List of products :-" << endl;
  cout << setw(10) << left << "Code"
       << " " << setw(10) << "Name"
       << " " << setw(10) << "Price"
       << " " << setw(10) << "quantity"
       << " " << setw(10) << "warranty" << endl;
  ifstream products_file("products.dat");
  if (!products_file.is_open()) {
    cout << "Error opening the file";
  } else {
    while (products_file >> code >> name >> price >> quantity >> warranty) {
      cout << setw(10) << left << code << "  " << setw(10) << name << "  " << setw(10) << price << "  " << setw(10) << quantity << "  " << setw(10) << warranty << endl;
    }
  }
  products_file.close();
  cout << endl;
}

void Cpu_Product::list_products()
{
  cout << endl;
  cout << "List of cpu products :-" << endl;
  cout << "Code"
       << " "
       << "Name"
       << " "
       << "Price"
       << " "
       << "quantity"
       << " "
       << "warranty"
       << " "
       << "cores"
       << " "
       << "threads"
       << " "
       << "cache"
       << " "
       << "clock" << endl;
  ifstream cpu_products_file("cpu_products.dat");
  if (!cpu_products_file.is_open()) {
    cout << "Error opening the file";
  } else {
    while (cpu_products_file >> code >> name >> price >> quantity >> warranty >> cores >> threads >> cache >> clock) {
      cout << code << "  " << name << "  " << price << "  " << quantity << "  " << warranty << " " << cores << " " << threads << " " << cache << " " << clock << endl;
    }
  }
  cpu_products_file.close();
  cout << endl;
}

void Gpu_Product::list_products()
{
  cout << endl;
  cout << "List of gpu products :-" << endl;
  cout << "Code"
       << " "
       << "Name"
       << " "
       << "Price"
       << " "
       << "quantity"
       << " "
       << "warranty"
       << " "
       << "memory"
       << " "
       << "clock" << endl;
  ifstream gpu_products_file("gpu_products.dat");
  if (!gpu_products_file.is_open()) {
    cout << "Error opening the file";
  } else {
    while (gpu_products_file >> code >> name >> price >> quantity >> warranty >> memory >> clock) {
      cout << code << "  " << name << "  " << price << "  " << quantity << "  " << warranty << " " << memory << " " << clock << endl;
    }
  }
  gpu_products_file.close();
  cout << endl;
}

int main()
{
  Product P;
  Cpu_Product Cpu_P;
  Gpu_Product Gpu_P;

  ofstream products_file("products.dat", ios::app);
  ofstream cpu_products_file("cpu_products.dat", ios::app);
  ofstream gpu_products_file("gpu_products.dat", ios::app);
  ofstream purchased_products_file("purchased_products.dat", ios::app);
  ofstream purchased_cpu_products_file("purchased_cpu_products.dat", ios::app);
  ofstream purchased_gpu_products_file("purchased_gpu_products.dat", ios::app);

  products_file.close();
  cpu_products_file.close();
  gpu_products_file.close();
  purchased_products_file.close();
  purchased_cpu_products_file.close();
  purchased_gpu_products_file.close();

  while (1) {

    system("cls");
    int choice;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "1.Login as Admin" << endl;
    cout << "2.Login as Customer" << endl;
    cout << "3.Exit" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cin >> choice;

    if (choice == 1) {

      while (1) {

        system("cls");
        cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "1.Add a Product" << endl;
        cout << "2.Delete a Product" << endl;
        cout << "3.Modify a Product" << endl;
        cout << "4.View Products" << endl;
        cout << "5.Back" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cin >> choice;

        if (choice == 1) {
          system("cls");
          cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
          cout << "1.General Product" << endl;
          cout << "2.Cpu" << endl;
          cout << "3.Gpu" << endl;
          cout << "4.Back" << endl;
          cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
          cin >> choice;

          if (choice == 1) {
            P.add_product();
          } else if (choice == 2) {
            Cpu_P.add_product();
          } else if (choice == 3) {
            Gpu_P.add_product();
          } else if (choice == 4) {
            break;
          }

        } else if (choice == 2) {
          system("cls");
          cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
          cout << "1.General Product" << endl;
          cout << "2.Cpu" << endl;
          cout << "3.Gpu" << endl;
          cout << "4.Back" << endl;
          cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
          cin >> choice;

          if (choice == 1) {
            P.delete_product();
          } else if (choice == 2) {
            Cpu_P.delete_product();
          } else if (choice == 3) {
            Gpu_P.delete_product();
          } else if (choice == 4) {
            break;
          }

        } else if (choice == 3) {
          system("cls");
          cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
          cout << "1.General Product" << endl;
          cout << "2.Cpu" << endl;
          cout << "3.Gpu" << endl;
          cout << "4.Back" << endl;
          cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
          cin >> choice;

          if (choice == 1) {
            P.modify_product();
          } else if (choice == 2) {
            Cpu_P.modify_product();
          } else if (choice == 3) {
            Gpu_P.modify_product();
          } else if (choice == 4) {
            break;
          }

        } else if (choice == 4) {
          system("cls");
          cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
          cout << "1.View general products" << endl;
          cout << "2.View cpu products" << endl;
          cout << "3.View gpu products" << endl;
          cout << "4.Back" << endl;
          cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
          cin >> choice;

          if (choice == 1) {
            P.list_products();
            cout << "Press any key to continue...";
            _getch();
          } else if (choice == 2) {
            Cpu_P.list_products();
            cout << "Press any key to continue...";
            _getch();
          } else if (choice == 3) {
            Gpu_P.list_products();
            cout << "Press any key to continue...";
            _getch();
          } else if (choice == 4) {
            break;
          }

        } else if (choice == 5) {
          break;
        }
      }
    } else if (choice == 2) {

      while (1) {
        system("cls");
        cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "1.View Products" << endl;
        cout << "2.Purchase a Product" << endl;
        cout << "3.Back" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cin >> choice;

        if (choice == 1) {
          system("cls");
          cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
          cout << "1.View general products" << endl;
          cout << "2.View cpu products" << endl;
          cout << "3.View gpu products" << endl;
          cout << "4.Back" << endl;
          cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
          cin >> choice;
          if (choice == 1) {
            P.list_products();
            cout << "Press any key to continue...";
            _getch();
          } else if (choice == 2) {
            Cpu_P.list_products();
            cout << "Press any key to continue...";
            _getch();
          } else if (choice == 3) {
            Gpu_P.list_products();
            cout << "Press any key to continue...";
            _getch();
          } else if (choice == 4) {
            break;
          }

        } else if (choice == 2) {
          system("cls");
          cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
          cout << "1.General Product" << endl;
          cout << "2.Cpu" << endl;
          cout << "3.Gpu" << endl;
          cout << "4.Back" << endl;
          cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
          cin >> choice;

          if (choice == 1) {
            P.purchase_product();

          } else if (choice == 2) {
            Cpu_P.purchase_product();

          } else if (choice == 3) {
            Gpu_P.purchase_product();
          } else if (choice == 4) {
            break;
          }

        } else if (choice == 3) {
          break;
        }
      }
    } else if (choice == 3) {
      break;
      exit(-1);
    } else {
      cout << "Please type a valid choice!" << endl;
    }
  }

  return 0;
}
