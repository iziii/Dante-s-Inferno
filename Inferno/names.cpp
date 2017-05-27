#include "stdafx.h"
#include "names.h"

std::vector<std::string> Names::names[2];

void Names::init()
{
  srand(time(NULL));
  std::ifstream file1 = std::ifstream{"data/names_men.txt"};

  std::string male_name, female_name;
  while(file1.good())
  {
    file1 >> male_name;
    names[male].push_back(male_name);
  }

  std::ifstream file2 = std::ifstream{"data/names_women.txt"};

  while(file2.good())
  {
    file2 >> female_name;
    names[female].push_back(female_name);
  }

}

std::string Names::name(gender gender)
{
  return names[gender][rand() % names[gender].size()];
}
