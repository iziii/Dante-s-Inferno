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
  std::vector<Sin> _commitedSins;

public:
  static std::vector <Human> createPeople(int n);

  Human();

  void committSins(Sin *sin);

  std::map <std::string, int> attributes();
  std::vector<Sin> committedSins();
  std::string name();
  short lifetime();
  enum gender gender();
  bool isBeliever();
  bool isDead();

};
