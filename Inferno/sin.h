#pragma once

class Sin {
private:
  std::string _name;
  int _circle; //numer kregu do ktorego przynalezy grzech
  std::map<std::string, int> _requirements; //cechy i ich wartosci minimalne wymagane do popelnienia grzechu

public:
  Sin (std::string name, int circle, std::string req_name1, std::string req_name2, int req_value1, int req_value2);

  static std::vector <Sin> createSins();

  std::string name();
  int circle();
  std::map <std::string, int> requirements();

};
