#include "User.h"
#include <filesystem>
#include <string>
int my_count = 0;
std::string sentence;


User::User() {
}

User::User(std::string name, std::string login, std::string password): _name(name), _login(login), _password(password) {
}

User::~User() {
}

const std::string User::getLogin() const {
	return _login;
}

const std::string User::getName() const {
	return _name;
}

const std::string User::getPassword() const {
	return _password;
}

void User::setName(std::string name) {
	_name = name;
}

void User::setLogin(std::string login) {
	_login = login;
}

void User::setPassword(std::string password) {
	_password = password;
}


void User::readUser() {
	int count = 0;
	std::fstream file = std::fstream(userData, std::ios::in);

	if (!file) 
	{
		std::cout<<"Not file"<< std::endl;
		file = std::fstream(userData, std::ios::in | std::ios::out | std::ios::trunc);
	}
	auto permissions = std::filesystem::perms::group_all |  // права, которые хотим отобрать 
		std::filesystem::perms::others_all; 
	std::filesystem::permissions (userData, permissions, std::filesystem::perm_options::remove);

	const std::string delimiter = ":";
	if (file.is_open()) {
		file.ignore(sentence.size()); // пропускаем кол-во символов переменной sentence, т.к. их уже считали
		std::string line;
		std::string title;
		std::string value;

		while (std::getline(file, line) && count < 3) { // цикл при каждом вызове метода считывает по 3 строки пока не дойдём до конца файла
			size_t delimiterPosition = line.find(delimiter);
			if (delimiterPosition > 0) {
				title = line.substr (0, delimiterPosition);
				value = line.substr (delimiterPosition + 1);

				if (title == "Name") {
					_name = value;
				}

				else if (title == "Login") {
					_login = value;
				}

				else if (title == "Password") {
					_password = value;
				}		
			}
			count++; // считали строку и увеличили счётчик
				 // записываем данные в переменную sentence для того, чтобы убрать их из файла при поторном вызове метода
			sentence += title;
			sentence += ":";
			sentence += value;
			sentence += '\n';
		}		
	}
	file.close();
}

void User::writeUser() const {
	my_count++;
	std::fstream file (userData, std::ios::out | std::ios::app);
	if (my_count == 1) {
		std::fstream file = std::fstream(userData, std::ios::out | std::ios::trunc);
	}
	
	file << "Name:" << _name << "\n";
	file << "Login:" << _login << "\n";
	file << "Password:" << _password << "\n";

	file.close();
}


