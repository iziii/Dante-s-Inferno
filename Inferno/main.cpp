#include "stdafx.h"


int main(int argc, char const *argv[])
{
  Names::init();

  int amount = 5; //liczba grzesznikow
  short years, max=0;

  int cricle_1, circle_2, circle_3, circle_4; //zmienne odpowiadajace za poziomy w piekle

  std::vector <Sin> sins = Sin::createSins();
  std::vector <Human> people = Human::createPeople(amount);

std::vector <Human>::iterator it_people;
std::vector <Sin>::iterator it_sins;

for(size_t i=0; i<people.size(); i++)
{
  max = std::max(people[i].lifetime(), max);
}

  years = max;

for(int i=0; i<max; i++)
{
    for(it_people = people.begin(); it_people!=people.end(); it_people++)
    {
      if(it_people -> isDead() != true)
      {
        for(size_t k=0; k<sins.size(); k++)
          it_people -> commitSins(&sins[k]);

        if(it_people -> lifetime() == i )
          it_people -> die();


        }

    }
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
  printf("Liczba popelnionych grzechow z kregu I: %i\n", it_people ->numberOfSins(1));
  printf("Liczba popelnionych grzechow z kregu II: %i\n", it_people ->numberOfSins(2));
  printf("Liczba popelnionych grzechow z kregu III: %i\n", it_people ->numberOfSins(3));
  printf("Liczba popelnionych grzechow z kregu IV: %i\n\n", it_people ->numberOfSins(4));

  printf("--------------- \n");

}

  return 0;
}
