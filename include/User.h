//
// Created by Amodh on 12/13/24.
//

#ifndef CHESS_USER_H
#define CHESS_USER_H

#include <string>

class User
{
public:
  explicit User( std::string name, std::string outputColor );

  std::string getOutputColor();

  std::string getName();

  bool operator==( User &comparingUser );

  bool operator!=( User &comparingUser );

private:
  std::string m_Name;
  std::string m_OutputColor;
};

#endif //CHESS_USER_H
