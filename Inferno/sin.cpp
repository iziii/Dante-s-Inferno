#include "stdafx.h"
#include "sin.h"

Sin::Sin (std::string name, int circle, std::string req_name1, std::string req_name2, int req_value1, int req_value2)
{
  _name = name;
  _circle = circle;
  _requirements.insert ( std::pair<std::string,int>(req_name1, req_value1) );
  _requirements.insert ( std::pair<std::string,int>(req_name2, req_value2) );
}

std::vector <Sin> Sin::createSins()
{
  std::vector <Sin> sins;

  std::string name, req_name1, req_name2;
  int req_value1, req_value2, circle;

  std::ifstream file = std::ifstream{"data/sins.txt"};

  while(file.good())
  {
    file >> name >> circle >> req_name1 >> req_value1 >> req_name2 >> req_value2;
    Sin Sin(name, circle, req_name1, req_name2, req_value1, req_value2);
    sins.push_back(Sin);
  }

  return sins;
}

std::string Sin::name()
{
  return _name;
}

int Sin::circle()
{
  return _circle;
}

std::map<std::string, int> Sin::requirements()
{
  return _requirements;
}
