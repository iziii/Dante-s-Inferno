#include "stdafx.h"
#include "human.h"

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

  _numberOfSins[0] = 0;
  _numberOfSins[1] = 0;
  _numberOfSins[2] = 0;
  _numberOfSins[3] = 0;

  _name = Names::name(_gender);

  //Cechy, na razie przykladowe:
  _attributes["cruel"] = rand() % 100;
  _attributes["degenerate"] = rand() % 100;
  _attributes["perverse"] = rand() % 100;
  _attributes["bad"] = rand() % 100;
  _attributes["insincere"] = rand () % 100;
  _attributes["lecherous"] = rand () % 100;
  //itd...
}

void Human::commitSins(Sin *sin)
{

  int chance = rand () % 100;

  std::map <std::string, int> requirements = sin -> requirements();
  std::map<std::string, int>::iterator it_requirements = requirements.begin();
  std::map<std::string, int>::iterator it_attributes1, it_attributes2;

  for(it_attributes1 = _attributes.begin();
          it_attributes1 != _attributes.end();
            it_attributes1++)
  {
      if(it_requirements -> first == it_attributes1 -> first
          && it_requirements -> second <= it_attributes1 -> second)

          {
              for(it_requirements++, it_attributes2 = _attributes.begin();
                  it_attributes2 != _attributes.end();
                    it_attributes2++)
              {

                if(it_requirements -> first == it_attributes2 -> first
                   && it_requirements -> second <= it_attributes2 -> second && chance > 50)
                    {
                       _committedSins.push_back(*sin);
                        addSins(sin -> circle());
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

void Human::die()
{
  _isDead = true;
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
  std::map <std::string, int>::iterator it;

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

void Human::showData()
{
  printf("%s, ", _name.c_str());
  if(_gender == 0)
  {
    printf("mężczyzna, ");
    if(_isBeliever)
      printf("wierzący, " );
        else printf("ateista, " );
          printf("żył %i lat.\n\n", _lifetime );
  }
  else
  {
    printf("kobieta, ");
      if(_isBeliever)
        printf("wierząca, " );
          else printf("ateistka, " );
            printf("żyła %i lat.\n\n", _lifetime );
  }
  printf("Liczba popełnionych grzechów: %i.\n", numberOfAllSins());

}

void Human::showAttributes()
{
  std::map<std::string, int>::iterator it;
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
