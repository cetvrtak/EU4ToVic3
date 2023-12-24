#ifndef OUT_WARS_H
#define OUT_WARS_H
#include "PoliticalManager/PoliticalManager.h"
#include "WarParser/WarParser.h"

namespace OUT
{
void outputWars(const std::string& outputName, const std::vector<EU4::WarParser>& wars);

} // namespace OUT

#endif // OUT_WARS_H