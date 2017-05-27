#include "stdafx.h"


int main(int argc, char const *argv[])
{
  Names::init();

  int amount = 10; //liczba mieszkancow

  std::vector <Sin> sins = Sin::createSins();
  std::vector <Human> people = Human::createPeople(amount);

//TU NA RAZIE TYLKO TESTY CZY DOBRZE I JAK GENERUJA SIE LUDZIE, ITP.
std::vector<Human>::iterator it_people;
std::vector <Sin>::iterator it_sins;

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


  printf("Pozyje: %i lat\n\n", it_people ->lifetime() );

  printf("Grzechy: \n");

    for(int i = 0; i<sins.size(); i++)
      it_people -> committSins(&sins[i]);

      for(int i=0; i<it_people->committedSins().size(); i++)
        printf("%s \n", it_people -> committedSins()[i].name().c_str());
        printf("--------------- \n");
}


  return 0;
}
