#include "stdafx.h"


int main(int argc, char const *argv[])
{
  Names::init();

  int amount = 5; //liczba grzesznikow
  int numberOfAlive = amount;
  short year = 0;

  int cricle_1, circle_2, circle_3, circle_4; //zmienne odpowiadajace za poziomy w piekle

  std::vector <Sin> sins = Sin::createSins();
  std::vector <Human> people = Human::createPeople(amount);

std::vector <Human>::iterator it_people;
std::vector <Sin>::iterator it_sins;

while (numberOfAlive > 0)
{
  for(it_people = people.begin(); it_people!=people.end(); it_people++)
  {
    if(it_people -> isDead() != true)
    {
      for(size_t i=0; i < sins.size(); i++)
        it_people -> commitSins(&sins[i]);

      if(it_people -> lifetime() == year )
      {
          it_people -> die();
          numberOfAlive--;
      }
    }
  }
  year++;
}

//TU NA RAZIE TYLKO TESTY CZY DOBRZE I JAK GENERUJA SIE LUDZIE, ITP.
for(it_people=people.begin(); it_people!=people.end(); it_people++)
{

  std::map<std::string, int> attributes = it_people->attributes();
  std::map<std::string, int>::iterator it_attributes;

  printf("Imie: %s \n", it_people->name().c_str());

    if(it_people -> gender() == 0)
      printf("Mezczyzna\n");

      else
        printf("Kobieta\n");

    if(it_people -> isBeliever())
      printf("Katol \n" );

      else
        printf("Ateista \n");

    printf("Cechy: \n");

    for(it_attributes=attributes.begin(); it_attributes!=attributes.end(); it_attributes++ )
    {
      printf(" \t %s : %d \n", it_attributes -> first.c_str(), it_attributes -> second);
    }


  printf("Zyl: %i lat\n\n", it_people ->lifetime() );

  printf("Liczba popelnionych grzechow ogolem: %i\n\n", it_people ->numberOfAllSins());

  printf("--------------- \n");

}

  return 0;
}
