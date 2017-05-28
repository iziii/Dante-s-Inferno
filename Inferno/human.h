#pragma once
#include "gender.h"

class Human
{
private:
  //dane:
  std::string _name;
  enum gender _gender;
  short _lifetime;
  bool _isBeliever;
  bool _isDead;

  //cechy:
  std::map <std::string, int> _attributes;

  //popełnione grzechy:
  std::vector <Sin> _committedSins;

  //zmienne przechowujące ilość popełnionych grzechów powiązanych z danym kręgiem:
  int _circle_1, _circle_2, _circle_3, _circle_4;

public:
  //metody klasy:
  static std::vector <Human> createPeople(int n);

 //metody obiektu:
  Human();
  void commitSins(Sin *sin);
  void addSins(int whichCircle);
  void die();

  //akcesory:
  std::string name();
  enum gender gender();
  short lifetime();
  bool isBeliever();
  bool isDead();
  std::map <std::string, int> attributes();
  std::vector<Sin> committedSins();
  int numberOfAllSins(); //funkcja zwraca liczbę wszystkich popełnionych grzechów
  int numberOfSins(int whichCircle); //funkcja zwraca liczbę grzechów powiązanych z danym kręgiem

};
