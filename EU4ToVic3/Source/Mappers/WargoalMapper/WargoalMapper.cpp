#include "WargoalMapper.h"
#include "CommonRegexes.h"
#include "Log.h"
#include "ParserHelpers.h"

void mappers::WargoalMapper::loadMappingRules(const std::string& filePath)
{
	Log(LogLevel::Info) << "-> Parsing Wargoal Mapping Rules.";
	registerKeys();
	parseFile(filePath);
	clearRegisteredKeywords();
	Log(LogLevel::Info) << "<> Loaded " << mappings.size() << " wargoals.";
}

void mappers::WargoalMapper::registerKeys()
{
	registerRegex(commonItems::catchallRegex, [this](const std::string& wargoal, std::istream& theStream) {
		const auto theList = commonItems::getStrings(theStream);
		mappings.emplace(wargoal, std::set<std::string>{});
		mappings.at(wargoal).insert(theList.begin(), theList.end());
	});
}

std::optional<std::string> mappers::WargoalMapper::getVic3Wargoal(const std::string& eu4Wargoal) const
{
	for (const auto& [vic3Wargoal, eu4Wargoals]: mappings)
		if (eu4Wargoals.contains(eu4Wargoal))
			return vic3Wargoal;
	return std::nullopt;
}
