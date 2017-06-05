#include "stdafx.h"
#include "human.h"

std::map<std::string, int>::iterator it;

std::vector <Human> Human::createPeople(int n)
{
  std::vector <Human> people;
  Human *_people = new Human[n];
  std::copy(&_people[0], &_people[n], std::back_inserter(people));
  return people;
}

Human::Human()
{
  _isDead = false;
  _gender = rand() % 2 == 0 ? male : female;
  _lifetime = rand() % 100 + 1;
  _isBeliever = rand() % 2;
  depression = 0;

  _numberOfSins[0] = 0;
  _numberOfSins[1] = 0;
  _numberOfSins[2] = 0;
  _numberOfSins[3] = 0;

  _name = Names::name(_gender);

  //Cechy:
  _attributes["rozpustny"] = rand() % 100;
  _attributes["zachłanny"] = rand() % 100;
  _attributes["lubieżny"] = rand() % 100;
  _attributes["perwersyjny"] = rand() % 100;
  _attributes["zły"] = rand() % 100;
  _attributes["gniewny"] = rand () % 100;
  _attributes["zdegenerowany"] = rand () % 100;
  _attributes["okrutny"] = rand () % 100;
  _attributes["nieszczery"] = rand () % 100;
}

void Human::commitSins(Sin *sin)
{

  int chance = rand () % 100;

  std::map <std::string, int> requirements = sin -> requirements();
  it = requirements.begin();
  std::map<std::string, int>::iterator it_attributes1, it_attributes2;

  for(it_attributes1 = _attributes.begin();
          it_attributes1 != _attributes.end();
            it_attributes1++)
  {
      if(it -> first == it_attributes1 -> first
          && it -> second <= it_attributes1 -> second)

          {
              for(it++, it_attributes2 = _attributes.begin();
                  it_attributes2 != _attributes.end();
                    it_attributes2++)
              {

                if(it -> first == it_attributes2 -> first
                   && it -> second <= it_attributes2 -> second && chance > 70)
                    {
                       _committedSins.push_back(*sin);
                        addSins(sin -> circle());
                        guiltyConscience();
                      }
              }
          }
  }

}

void Human::addSins(int whichCircle)
{
  switch (whichCircle)
  {
      case 1: _numberOfSins[0]++; break;
      case 2: _numberOfSins[1]++; break;
      case 3: _numberOfSins[2]++; break;
      case 4: _numberOfSins[3]++; break;
  }
}

void Human::guiltyConscience()
{
  float value = 0;
  it = _attributes.find("zdegenerowany");
    if(it !=_attributes.end())
    {
      value =  100 - (it -> second) ;

      int chance = rand () % 100;
      if(chance > 50)
        _isBeliever ? (depression += value/50) : (depression += value/100);
      }

}

void Human::die()
{
  _isDead = true;
  data();
}

bool Human::suicide(int year)
{
  int chance = rand () % 100;
  if(depression > 100 && chance > 50)
  {
    _lifetime=year;

    die();

    if(!_gender)
      _data += "\nPopełnił samobójstwo na skutek depresji.";
    else
      _data += "\nPopełniła samobójstwo na skutek depresji.";

    return true;
  }
  else return false;
}

int Human::judgement()
{
  if( numberOfAllSins() == 0 && _isBeliever == true) return 0;
  else if( numberOfAllSins() == 0 && _isBeliever == false ) return 1;
  else
  {
    int i_max = 0, max = _numberOfSins[0];

      for(int i = 0; i < 4 ; i++)
      {
        if(_numberOfSins[i] > max)
            {
              max = _numberOfSins[i];
              i_max = i;
            }
      }
      return ++i_max;
  }
}

void Human::examinationOfConscience()
{
  std::map <std::string, int> collection;

  for(size_t i =0; i < numberOfAllSins(); i++)
  {
    it = collection.find(_committedSins[i].name());
      if (it != collection.end()) it -> second ++;
        else collection.insert ( std::pair<std::string, int>(_committedSins[i].name(), 1) );
  }

  printf("\nRachunek sumenia: \n");
  for(it = collection.begin(); it != collection.end(); it++)
  {
    printf("\t%s: %ix\n", it -> first.c_str(), it -> second );
  }
}

void Human::data()
{
  std::ostringstream ss;

  ss << _name;

  if(!_gender)
  {  ss << ", mężczyzna, ";
    if(_isBeliever)
      ss << "wierzący, ";
      else ss << "ateista, ";
    ss << "żył ";
    ss << _lifetime;
    ss << " lat.";
  }

  else
  {
    ss << ", kobieta, ";
    if(_isBeliever)
      ss << "wierząca, ";
      else ss << "ateistka, ";
    ss << "żyła ";
    ss << _lifetime;
    ss << " lat.";
  }
  ss << "\nLiczba popełnionych grzechów: ";
  ss << numberOfAllSins();

  _data = ss.str();
}

void Human::showData()
{
  printf("\n%s\n", _data.c_str() );
}

void Human::showAttributes()
{
  printf("\nCechy: \n");
    for(it = _attributes.begin(); it != _attributes.end(); it++ )
    {
      printf("\t%s: %d%c \n", it -> first.c_str(), it -> second, 37);
    }
}

std::string Human::name()
{
  return _name;
}

enum gender Human::gender()
{
  return _gender;
}

int Human::lifetime()
{
  return _lifetime;
}

bool Human::isBeliever()
{
  return _isBeliever;
}

bool Human::isDead()
{
  return _isDead;
}

std::map <std::string, int> Human::attributes()
{
  return _attributes;
}

std::vector<Sin> Human::committedSins()
{
  return _committedSins;
}

int Human::numberOfAllSins()
{
  return _committedSins.size();
}
