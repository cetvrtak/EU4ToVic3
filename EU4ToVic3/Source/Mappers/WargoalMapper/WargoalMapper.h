#ifndef WARGOAL_MAPPER_H
#define WARGOAL_MAPPER_H
#include "Parser.h"
#include <set>

namespace mappers
{
class WargoalMapper: commonItems::parser
{
  public:
	WargoalMapper() = default;
	void loadMappingRules(const std::string& filePath);

	[[nodiscard]] std::optional<std::string> getVic3Wargoal(const std::string& eu4Wargoal) const;

  private:
	void registerKeys();

	std::map<std::string, std::set<std::string>> mappings;
};
} // namespace mappers

#endif // WARGOAL_MAPPER_H
