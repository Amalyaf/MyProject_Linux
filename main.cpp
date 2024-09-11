#include "User.h"

using namespace std;

int main() {
setlocale (LC_ALL,"");

User user;

cout << "\nНачальные данные: " << endl;
cout << "Name:" << user.getName() << endl;
cout << "Login:" << user.getLogin() << endl;
cout << "Password:" << user.getPassword() << endl;

string newName = "Vanya";
string newLogin = "vanyaa";
string newPassword  = "vanya123";

user.setName(newName);
user.setLogin(newLogin);
user.setPassword(newPassword);

cout << "\nТекущие данные: " << endl;
cout << "Name:" << user.getName() << endl;  
cout << "Login:" << user.getLogin() << endl;
cout << "Password:" << user.getPassword() << endl;

cout << endl;

}
