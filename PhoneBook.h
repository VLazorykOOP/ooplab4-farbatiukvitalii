#pragma once
#include <iostream>
#include <map>
#include <string>

class PhoneBook {
private:
    std::map<std::string, std::string> data;

public:
    PhoneBook() = default;

    void add(const std::string& phone, const std::string& name);
    void remove(const std::string& phone);
    void edit(const std::string& phone, const std::string& newName);
    std::string find(const std::string& phone) const;
    void print() const;

    bool saveToFile(const std::string& filename) const;
    bool loadFromFile(const std::string& filename);
};
