#pragma once

class Names
{
private:
  static std::vector<std::string> names[2];

public:
  static void init();

  static std::string name(gender);

};
