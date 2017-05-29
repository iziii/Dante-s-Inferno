#pragma once
#include "gender.h"

class Human
{
private:
  //dane:
  std::string _name;
  enum gender _gender;
  int _lifetime;
  bool _isBeliever;
  bool _isDead;

  //cechy:
  std::map <std::string, int> _attributes;

  //popełnione grzechy:
  std::vector <Sin> _committedSins;

  //tablica, ktorej elementy to ilość popełnionych grzechów powiazanych z odpowiadajacym kręgiem:
  int _numberOfSins[4];

public:
  //metody klasy:
  static std::vector <Human> createPeople(int n);

 //metody obiektu:
  Human();
  void commitSins(Sin *sin);
  void addSins(int whichCircle);
  void die();
  int judgement();
  void examinationOfConscience(); //rachunek sumienia
  void showData();
  void showAttributes();


  //akcesory:
  std::string name();
  enum gender gender();
  int lifetime();
  bool isBeliever();
  bool isDead();
  std::map <std::string, int> attributes();
  std::vector<Sin> committedSins();
  int numberOfAllSins();

};
