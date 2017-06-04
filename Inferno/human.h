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
  float depression;
  std::string _data;

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
  void guiltyConscience(); //wyrzuty sumienia?
  void die();
  bool suicide(int year);
  int judgement(); //wyrok - do ktorego kregu powinien trafic czlowiek
  void examinationOfConscience(); //rachunek sumienia
  void data();
  void showData(); //pokaz podstawowe dane
  void showAttributes(); //pokaz cechy

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
