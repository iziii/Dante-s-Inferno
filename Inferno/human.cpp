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

  _circle_1 = 0;
  _circle_2 = 0;
  _circle_3 = 0;
  _circle_4 = 0;

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

  std::map<std::string, int> requirements = sin -> requirements();
  std::map<std::string, int>::iterator it_requirements = requirements.begin();
  std::map<std::string, int>::iterator it_attributes1, it_attributes2;

    for(it_attributes1=this -> _attributes.begin();
          it_attributes1!=this -> _attributes.end();
            it_attributes1++)
  {

      if(it_requirements -> first == it_attributes1 -> first
          && it_requirements -> second <= it_attributes1 -> second)

          {
              for(it_requirements++, it_attributes2=this -> _attributes.begin();
                  it_attributes2!=this -> _attributes.end();
                    it_attributes2++)
              {

                if(it_requirements -> first == it_attributes2 -> first
                   && it_requirements -> second <= it_attributes2 -> second && chance >= 50)
                    {
                       _committedSins.push_back(*sin);
                       addSins(sin -> circle());
                      }

              }
          }

  }

}

std::vector<Sin> Human::committedSins()
{
  return _committedSins;
}

short Human::lifetime()
{
  return _lifetime;
}
std::string Human::name()
{
  return _name;
}

enum gender Human::gender()
{
  return _gender;
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

void Human::addSins(int whichCircle)
{
  switch (whichCircle) {
    case 1: _circle_1++; break;
    case 2: _circle_2++; break;
    case 3: _circle_3++; break;
    case 4: _circle_4++; break;
  }
}

void Human::die()
{
  _isDead = true;
}
