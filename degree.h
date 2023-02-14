#pragma once
#include <string>
using namespace std;

const int numDegrees = 3;
enum class DegreeProgram { SECURITY, NETWORK, SOFTWARE };
static std::string degreeProgramString[numDegrees] = { "SECURITY", "NETWORK", "SOFTWARE" };