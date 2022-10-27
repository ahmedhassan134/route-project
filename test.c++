#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <vector>

class Person
{
protected:
    string name, password;
    int id;

public:
    void setName(string name)
    {
        if ((name.size() <= 20 && name.size() >= 5) && ((name >= "a" && name <= "z") || (name >= "A" && name <= "Z")))
            Person::name = name;

        else
        {
            cout << "name is wrong it is not validate ";
            cout << endl;
        }
    }

    void setPassword(string password)
    {
        if (password.size() <= 20 && password.size() >= 8)
            Person::password = password;
        else
        {
            cout << "password is wrong it is not validate";
            cout << endl;
        }
    }

    void setId(int id)
    {
        Person::id = id;
    }

    string getName()
    {
        if ((name.size() <= 20 && name.size() >= 5) && ((name >= "a" && name <= "z") || (name >= "A" && name <= "Z")))
        {

            return name;
        }
        else
        {

            cout << "name is wrong it is not validate ";
            cout << endl;
        }
    }
    string getPassword()
    {
        if (password.size() <= 20 && password.size() >= 8)
            return password;
        else
        {
            cout << "password is wrong it is not validate";
            cout << endl;
        }
    }
    int getId() { return id; }

    virtual void printData()
    {

        cout << "My Name is : " << getName() << endl;

        cout << "My Password is : " << getPassword() << endl;

        cout << "My Id  is : " << getId() << endl;
    }
    Person() {}

    Person(string name, string password, int id)
    {
        setName(name);
        setPassword(password);
        setId(id);
    }
};

class Client : public Person
{
private:
    double balance;

public:
    void setBalance(double balance)
    {

        if (balance >= 1500)
            Client::balance = balance;
        else
            cout << "there is not validate balance" << endl;
    }
    double getBalance() { return balance; }

    void printData()
    {
        Person::printData();

        cout << "My balance is : " << getBalance() << endl;
    }

    void deposite(double amount)
    {
        double total = balance += amount;
        cout << total;
    }

    void withdraw(double amount)
    {

        if (balance > amount)
        {
            double total = balance -= amount;
            cout << total;
        }
        else
            cout << "There is not money enough ";
    }
    void transfer_to(Client &a, double amount)
    {
        if (balance > amount)
        {
            balance -= amount;
            a.deposite(amount);
        }
        else
        {
            cout << "Balance is too low";
        }
    }

    void checkBalance()
    {

        cout << "the current balance is : " << getBalance() << endl;
    }

    Client() {}
    Client(double balance, string name, string password, int id) : Person(name, password, id)
    {
        setBalance(balance);
    }
};

class Employee : public Person
{

private:
    double balance;

public:
    void setBalance(double balance)
    {

        if (balance >= 5000)
            Employee::balance = balance;
        else
            cout << "there is not validate balance" << endl;
    }
    double getBalance() { return balance; }

    void printData()
    {
        Person::printData();
        cout << "My balance is : " << getBalance() << endl;
    }
    void addClient(Client &client){
      

            ofstream clientData;
            clientData.open("clients.txt");
            clientData  <<client.getName() << endl;
            clientData  << client.getPassword() << endl;
            clientData  << client.getId() << endl;
            clientData  << client.getBalance() << endl;
            clientData.close();
        
    }

    Client *searchClient(int id){
        ifstream fin;
        fin.open("clients.txt");
        if (fin.fail())
        {
            cout << "Input file opening failed.\n";
            exit(1);
        }

        string search;
        cout << "Please enter an Id: ";
        cin >> search;
        bool isFound = 0;
        while (!fin.eof())
        {
            string temp = "";
            getline(fin, temp);
            for (int i = 0; i < search.size(); i++)
            {
                if (temp[i] == search[i])
                    isFound = 1;
                else
                {
                    isFound = 0;
                    break;
                }
            }

            if (isFound)
            {
                cout << "Id is: ";
                for (int i = search.size() + 1; i < temp.size(); i++)
                    cout << temp[i];

                break;
            }
        }

        if (fin.eof() && (!isFound))
        {
            cout << "Id not found!\n";
        }

        fin.close();
    }
    void listClient(){
       
            ifstream clientDataShowing;
            clientDataShowing.open("clients.txt");
            if (clientDataShowing.fail())
            {
                clientDataShowing.open("admin.txt");
            }
            else
            {
                cout << "exicted" << endl;
            }

            cout << "the client info : " << endl;
            string name[100];
            for (int i = 0; i < 100; i++)
            {
                clientDataShowing >> name[i];
            }
            for (int i = 0; i < 100; i++)
            {
                cout << name[i] << " ";
            }

            clientDataShowing.close();
        
    }
    void editClient(int id, string name, string password, double balance){

        ofstream clientData;
        clientData.open("clients.txt");
        clientData << id << endl;
        clientData << name << endl;
        clientData << password << endl;
        clientData << balance << endl;
    }

        Employee()
    {
    }
    Employee(double balance, string name, string password, int id) : Person(name, password, id)
    {
        setBalance(balance);
    }
};

class Admin : public Person
{

private:
    double balance;

public:
    void setBalance(double balance)
    {

        if (balance >= 5000)
            Admin::balance = balance;
        else
            cout << "there is not validate balance" << endl;
    }
    double getBalance() { return balance; }

    void printData()
    {
        Person::printData();
        cout << "My balance is : " << getBalance() << endl;
    }

    void addClient(Client &client)
    {

        ofstream clientData;
        clientData.open("clients.txt");
        clientData  << client.getName() << endl;
        clientData  << client.getPassword() << endl;
        clientData  << client.getId() << endl;
        clientData  << client.getBalance() << endl;
        clientData.close();
    }
    Client *searchClient(int id)
    {
        ifstream fin;
        fin.open("clients.txt");
        if (fin.fail())
        {
            cout << "Input file opening failed.\n";
            exit(1);
        }

        string search;
        cout << "Please enter an Id: ";
        cin >> search;
        bool isFound = 0;
        while (!fin.eof())
        {
            string temp = "";
            getline(fin, temp);
            for (int i = 0; i < search.size(); i++)
            {
                if (temp[i] == search[i])
                    isFound = 1;
                else
                {
                    isFound = 0;
                    break;
                }
            }

            if (isFound)
            {
                cout << "Id is: ";
                for (int i = search.size() + 1; i < temp.size(); i++)
                    cout << temp[i];

                break;
            }
        }

        if (fin.eof() && (!isFound))
        {
            cout << "Id not found!\n";
        }

        fin.close();
    }
    void listClient()
    {

        ifstream clientDataShowing;
        clientDataShowing.open("clients.txt");
        if (clientDataShowing.fail())
        {
            clientDataShowing.open("admin.txt");
        }
        else
        {
            cout << "exicted" << endl;
        }

        cout << "the client info : " << endl;
        string name[100];
        for (int i = 0; i < 100; i++)
        {
            clientDataShowing >> name[i];
        }
        for (int i = 0; i < 100; i++)
        {
            cout << name[i] << " ";
        }

        clientDataShowing.close();
    }
    void editClient(int id, string name, string password, double balance)
    {

        ofstream clientData;
        clientData.open("clients.txt");
        clientData << id << endl;
        clientData << name << endl;
        clientData << password << endl;
        clientData << balance << endl;
    }



    // -----------------------------------------------------------

    void addEmployee(Employee &employee)
    {

        ofstream clientData;
        clientData.open("employee.txt");
        clientData <<employee.getName() << endl;
        clientData  << employee.getPassword() << endl;
        clientData << employee.getId() << endl;
        clientData << employee.getBalance() << endl;
        clientData.close();
    }
    Employee *searchEmployee(int id)
    {
        ifstream fin;
        fin.open("employee.txt");
        if (fin.fail())
        {
            cout << "Input file opening failed.\n";
            exit(1);
        }

        string search;
        cout << "Please enter an Id: ";
        cin >> search;
        bool isFound = 0;
        while (!fin.eof())
        {
            string temp = "";
            getline(fin, temp);
            for (int i = 0; i < search.size(); i++)
            {
                if (temp[i] == search[i])
                    isFound = 1;
                else
                {
                    isFound = 0;
                    break;
                }
            }

            if (isFound)
            {
                cout << "Id is: ";
                for (int i = search.size() + 1; i < temp.size(); i++)
                    cout << temp[i];

                break;
            }
        }

        if (fin.eof() && (!isFound))
        {
            cout << "Id not found!\n";
        }

        fin.close();
    }
    void listEmployee()
    {

        ifstream clientDataShowing;
        clientDataShowing.open("employee.txt");
        if (clientDataShowing.fail())
        {
            clientDataShowing.open("admin.txt");
        }
        else
        {
            cout << "exicted" << endl;
        }

        cout << "the client info : " << endl;
        string name[100];
        for (int i = 0; i < 100; i++)
        {
            clientDataShowing >> name[i];
        }
        for (int i = 0; i < 100; i++)
        {
            cout << name[i] << " ";
        }

        clientDataShowing.close();
    }
    void editEmployee(int id, string name, string password, double balance)
    {

        ofstream clientData;
        clientData.open("employee.txt");
        clientData << id << endl;
        clientData << name << endl;
        clientData << password << endl;
        clientData << balance << endl;
    }

    Admin() {}
    Admin(double balance, string name, string password, int id) : Person(name, password, id)
    {
        setBalance(balance);
    }
};

class DataSourceInterface
{
public:
    virtual void addClient(Client c);
    virtual void addEmployee(Employee e);
    virtual void addAdmin(Admin a);
    virtual vector<Client> getAllClients();
    virtual vector<Employee> getAllEmployees();
    virtual vector<Employee> getAllAdmins();
    virtual void removeAllClients();
    virtual void removeAllEmployees();
    virtual void removeAllAdmins();
};

class FileManager : public DataSourceInterface
{

public:
    void addClient(Client c)
    {

        ofstream clientData;
        clientData.open("clients.txt");
        clientData << c.getName() << endl;
        clientData <<  c.getPassword() << endl;
        clientData <<  c.getId() << endl;
        clientData <<  c.getBalance() << endl;
        clientData.close();
    }

    void addEmployee(Employee e)
    {
        ofstream employeeData;
        employeeData.open("employee.txt");
        employeeData <<  e.getName() << endl;
        employeeData <<  e.getPassword() << endl;
        employeeData <<  e.getId() << endl;
        employeeData <<  e.getBalance() << endl;
        employeeData.close();
    }
    void addAdmin(Admin a)
    {
        ofstream AdminData;
        AdminData.open("admin.txt");
        AdminData << a.getName() << endl;
        AdminData <<  a.getPassword() << endl;
        AdminData <<  a.getId() << endl;
        AdminData <<  a.getBalance() << endl;
        AdminData.close();
    }

    vector<Client> getAllClients()
    {
        ifstream clientDataShowing;
        clientDataShowing.open("clients.txt");
        if (clientDataShowing.fail())
        {
            clientDataShowing.open("admin.txt");
        }
        else
        {
            cout << "exicted" << endl;
        }

        cout << "the client info : " << endl;
        string name[100];
        for (int i = 0; i < 100; i++)
        {
            clientDataShowing >> name[i];
        }
        for (int i = 0; i < 100; i++)
        {
            cout << name[i] << " ";
        }

        clientDataShowing.close();
    }

    vector<Employee> getAllEmployees()
    {

        ifstream employeeDataShowing;
        employeeDataShowing.open("employee.txt");
        if (employeeDataShowing.fail())
        {
            employeeDataShowing.open("clients.txt");
        }
        else
        {
            cout << "exicted" << endl;
        }

        cout << "the employee info : " << endl;
        string name[100];
        for (int i = 0; i < 100; i++)
        {
            employeeDataShowing >> name[i];
        }
        for (int i = 0; i < 100; i++)
        {
            cout << name[i] << " ";
        }

        employeeDataShowing.close();
    }

    vector<Employee> getAllAdmins()
    {

        ifstream adminDataShowing;
        adminDataShowing.open("admin.txt");
        if (adminDataShowing.fail())
        {
            adminDataShowing.open("employee.txt");
        }
        else
        {
            cout << "exicted" << endl;
        }

        cout << "the admin info : " << endl;
        string name[100];
        for (int i = 0; i < 100; i++)
        {
            adminDataShowing >> name[i];
        }
        for (int i = 0; i < 100; i++)
        {
            cout << name[i] << " ";
        }

        adminDataShowing.close();
    }

    void removeAllClients()
    {

        ofstream data;
        data.open("clients.txt");
        data.clear();
        data << "empty data !!";
        data.close();
    }

    void removeAllEmployees()
    {
        ofstream data;
        data.open("employee.txt");
        data.clear();
        data << "empty data !!";
        data.close();
    }

    void removeAllAdmins()
    {
        ofstream data;
        data.open("admin.txt");
        data.clear();
        data << "empty data !!";
        data.close();
    }
};





class FilesHelper{
public:
    static void saveLast(string fileName, int id){
        ofstream myfile;

        myfile.open(fileName, std::ofstream::app);

        myfile <<"the new id is " <<id << endl;

      
    }

    static int getLast(string fileName){

        // string line;
        // int i;
        // std::string *new1;
        // new1 = new string;
        // ifstream myfile("path.txt");
        // while (getline(myfile, line))
        // {
        //     cout << line << endl;
        //     new1 = line;
        // }
        // cout << new1 << endl;
        // myfile.close();
        // cin.get();
    }
};

int main()
{
// take object from classes
    Client c(12000, "ahmed", "12345678900", 1);
    FileManager f1;

  

    f1.addClient(c);

    Employee e(5000.0, "Mohamed", "1234123456", 11);
    f1.addEmployee(e);

    Admin a(30000.0, "ali ahmed", "#9876543211", 111);
    f1.addAdmin(a);
    a.searchEmployee(10);
    a.listEmployee();


// to save id in last
   FilesHelper::saveLast("clients.txt", 10);
   cout << "$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
   cout << FilesHelper::getLast("clients.txt");

   // ********************************************************
   // to search about id in client class
   //   e.searchClient(3);
   // ********************************************************

   // ********************************************************

   // to edit in client class
   //  e.editClient(10, "jabeer ", "111111111111", 4000);

   // ********************************************************

   // to choose any class to show its data
   // int chooseNumber;
   // cin >> chooseNumber;
   // switch (chooseNumber)
   // {
   // case 1:
   //     f1.getAllClients();
   //     break;
   // case 2:
   //     f1.getAllEmployees();
   //     break;
   // default:
   //     f1.getAllAdmins();
   //     break;
   // }
   // f1.removeAllClients();
   // f1.removeAllClients();
   // f1.removeAllEmployees();

   return 0;
}