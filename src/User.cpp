//
// Created by Amodh on 12/13/24.
//

#include "../include/User.h"

using namespace std;

User::User( std::string name, std::string outputColor ) : m_Name( std::move( name )),
                                                          m_OutputColor( std::move( outputColor ))
{}

string User::getOutputColor()
{
  return User::m_OutputColor;
}

string User::getName()
{
  return User::m_Name;
}

bool User::operator==( User &comparingUser )
{
  std::string originalName = User::getName();
  std::string comparingName = comparingUser.getName();
  return originalName == comparingName;
}

bool User::operator!=( User &comparingUser )
{
  std::string originalName = User::getName();
  std::string comparingName = comparingUser.getName();
  return originalName != comparingName;
}
