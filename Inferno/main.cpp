#include "stdafx.h"


int main(int argc, char const *argv[])
{
  Names::init();

  int amount = 200,numberofAlive = amount; //liczba grzesznikow
  int year = 0;

  std::vector <Sin> sins = Sin::createSins();
  std::vector <Human> people = Human::createPeople(amount);

  Human *winner = new Human;
  *winner = people[0];

  std::vector <Human> circle_0; //ewenementy?
  std::vector <Human> circle_1; //POŻĄDANIE
  std::vector <Human> circle_2; //PRZEMOC
  std::vector <Human> circle_3; //OSZUSTWO
  std::vector <Human> circle_4; //ZDRADA

  //iteratory:
  std::vector <Human>::iterator it_people;
  std::vector <Sin>::iterator it_sins;
  std::map<std::string, int>::iterator it_attributes;

  //startujemy:
  while (numberofAlive > 0)
  {
    for(int i=0; i < people.size(); i++)
    {
      if(people[i].isDead() != true)
      {
        for(int j = 0; j < sins.size(); j++)
          people[i].commitSins(&sins[j]);

          if(people[i].lifetime() == year )
          {
            people[i].die();

          switch (people[i].judgement())
          {
            case 0: circle_0.push_back(people[i]); break;
            case 1: circle_1.push_back(people[i]); break;
            case 2: circle_2.push_back(people[i]); break;
            case 3: circle_3.push_back(people[i]); break;
            case 4: circle_4.push_back(people[i]); break;
          }
            if(winner -> numberOfAllSins() < people[i].numberOfAllSins())
              *winner = people[i];

        //    people.erase(people.begin()+i);
            numberofAlive--;
          }
      }
    }
    year++;
  }

  //statystyki:
  printf("\n\tSTATYSTYKI:\n" );
  printf("\n--------------------------------------- \n");

    if(circle_0.size() != 0)
    {
      printf("\n*Ktoś jednak nie trafi do piekła...*\n\n");
      if(circle_0.size() > 3)
      {
        printf("Aż %zu ludzi nic nie robiło w życiu. \n\n", circle_3.size() );
        printf("--------------------------------------- \n");
      }
      else
        for(int i=0; i<circle_0.size(); i++)
      {
        std::map<std::string, int> attributes = circle_0[i].attributes();

        printf("%s, ", circle_0[i].name().c_str());
        if(circle_0[i].gender() == 0)  printf("mężczyzna, żył: %i lat.\n", circle_0[i].lifetime());
          else  printf("kobieta, żyła: %i lat.\n", circle_0[i].lifetime());

        printf("\nCechy: \n");
        for(it_attributes = attributes.begin(); it_attributes != attributes.end(); it_attributes++ )
        {
          printf(" \t %s : %d \n", it_attributes -> first.c_str(), it_attributes -> second);
        }
        printf("\n--------------------------------------- \n");
      }
    }
    printf("\n\t***PIEKŁO***\n");
    printf("\nKRĄG I *POŻĄDANIE* \n\tTutaj trafiło: ");
      printf("%zu\n", circle_1.size() );

      /*statystyki ludzi, ktorzy tutaj trafili:
      for(int i=0; i < circle_1.size(); i++)
      {   std::map <std::string, int> attributes = circle_1[i].attributes();
          printf("%s, ", circle_1[i].name().c_str());

          if(circle_1[i].gender() == 0)  printf("mężczyzna, żył: %i lat.\n", circle_1[i].lifetime());
            else  printf("kobieta, żyła: %i lat.\n", circle_1[i].lifetime());

          printf("Liczba popelnionych grzechow ogolem: %i\n\n", circle_1[i].numberOfAllSins());
          printf("--------------------------------------- \n");
      }*/

    printf("\nKRĄG II *PRZEMOC* \n\tTutaj trafiło: ");
      printf("%zu\n", circle_2.size() );

      /*jw.
      for(int i=0; i < circle_2.size(); i++)
      {   std::map <std::string, int> attributes = circle_2[i].attributes();
          printf("%s, ", circle_2[i].name().c_str());

          if(circle_2[i].gender() == 0)  printf("mężczyzna, żył: %i lat.\n", circle_2[i].lifetime());
            else  printf("kobieta, żyła: %i lat.\n", circle_2[i].lifetime());

          printf("Liczba popelnionych grzechow ogolem: %i\n\n", circle_2[i].numberOfAllSins());
          printf("--------------------------------------- \n");
      }*/

  printf("\nKRĄG III *OSZUSTWO* \n\tTutaj trafiło: ");
    printf("%zu\n", circle_3.size() );

    /*jw.
    for(int i=0; i < circle_3.size(); i++)
    {   std::map <std::string, int> attributes = circle_3[i].attributes();
        printf("%s, ", circle_3[i].name().c_str());

        if(circle_3[i].gender() == 0)  printf("mężczyzna, żył: %i lat.\n", circle_3[i].lifetime());
          else  printf("kobieta, żyła: %i lat.\n", circle_3[i].lifetime());

        printf("Liczba popelnionych grzechow ogolem: %i\n\n", circle_3[i].numberOfAllSins());
        printf("--------------------------------------- \n");

    }*/


  printf("\nKRĄG IV *ZDRADA* \n\tTutaj trafiło: ");
    printf("%zu\n", circle_4.size() );

    /*jw.
    for(int i=0; i < circle_4.size(); i++)
    {   std::map <std::string, int> attributes = circle_4[i].attributes();
        printf("%s, ", circle_4[i].name().c_str());

        if(circle_4[i].gender() == 0)  printf("mężczyzna, żył: %i lat.\n", circle_4[i].lifetime());
          else  printf("kobieta, żyła: %i lat.\n", circle_4[i].lifetime());

        printf("Liczba popelnionych grzechow ogolem: %i\n\n", circle_4[i].numberOfAllSins());
        printf("--------------------------------------- \n");
    }*/

    printf("\n--------------------------------------- \n");

    if(winner -> numberOfAllSins() != 0)
    {
      printf("\n*And the winner is...* \n\n" );
      printf("%s, ", winner -> name().c_str());
      if(winner -> gender() == 0)  printf("mężczyzna, żył: %i lat.\n\n", winner -> lifetime());
        else  printf("kobieta, żyła: %i lat.\n", winner -> lifetime());

      printf("Liczba popełnionych grzechów ogółem: %i\n", winner -> numberOfAllSins());

      std::map <std::string, int> attributes = winner -> attributes();

      printf("\nCechy: \n");
        for(it_attributes=attributes.begin(); it_attributes!=attributes.end(); it_attributes++ )
        {
          printf("\t %s : %d \n", it_attributes -> first.c_str(), it_attributes -> second);
        }
      }
      printf("\n--------------------------------------- \n");
    return 0;
  }
