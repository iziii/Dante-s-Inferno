#pragma once
#include "gender.h"

class Human
{
private:
  std::string _name;
  enum gender _gender;
  short _lifetime;
  bool _isBeliever;
  bool _isDead;
  std::map <std::string, int> _attributes;
  std::vector<Sin> _committedSins;
  int _circle_1, _circle_2, _circle_3, _circle_4;

public:
  static std::vector <Human> createPeople(int n);

  Human();

  void commitSins(Sin *sin);

  std::map <std::string, int> attributes();
  std::vector<Sin> committedSins();
  std::string name();
  short lifetime();
  enum gender gender();
  bool isBeliever();
  bool isDead();

  void addSins(int whichCircle);
  void die();

};
