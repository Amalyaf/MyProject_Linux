#include "User.h"
#include <filesystem>

User::User(std::string name, std::string login, std::string password): _name(name), _login(login), _password(password) {
readUser();
}

User::~User() {
	writeUser();
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

	std::fstream file (userData, std::ios::in | std::ios::trunc);
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
		std::string line;
		std::string title;
		std::string value;

		while (std::getline(file, line)) {
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
		}
	}
	file.close();
}

void User::writeUser() const {
	std::fstream file (userData, std::ios::out);
	file << "Name:" << _name << "\n";
	file << "Login:" << _login << "\n";
	file << "Password:" << _password << "\n";

	file.close();
}


