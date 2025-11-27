#include "PhoneBook.h"
#include <fstream>

void PhoneBook::add(const std::string& phone, const std::string& name) {
    data[phone] = name;
}

void PhoneBook::remove(const std::string& phone) {
    data.erase(phone);
}

void PhoneBook::edit(const std::string& phone, const std::string& newName) {
    if (data.count(phone))
        data[phone] = newName;
}

std::string PhoneBook::find(const std::string& phone) const {
    if (data.count(phone))
        return data.at(phone);
    return "Не знайдено";
}

void PhoneBook::print() const {
    std::cout << "\n=== Телефонна книга ===\n";
    for (const auto& p : data)
        std::cout << p.first << " → " << p.second << "\n";
}

bool PhoneBook::saveToFile(const std::string& filename) const {
    std::ofstream fout(filename);
    if (!fout) return false;

    for (const auto& p : data)
        fout << p.first << ";" << p.second << "\n";
    return true;
}

bool PhoneBook::loadFromFile(const std::string& filename) {
    std::ifstream fin(filename);
    if (!fin) return false;

    data.clear();
    std::string line;

    while (std::getline(fin, line)) {
        size_t pos = line.find(';');
        if (pos != std::string::npos) {
            std::string phone = line.substr(0, pos);
            std::string name = line.substr(pos + 1);
            data[phone] = name;
        }
    }
    return true;
}
