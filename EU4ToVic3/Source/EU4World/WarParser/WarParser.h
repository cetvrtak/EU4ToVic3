#ifndef WAR_PARSER
#define WAR_PARSER
#include "Parser.h"
#include "WarDetails.h"

namespace EU4
{
class WarParser: commonItems::parser
{
  public:
	explicit WarParser(std::istream& theStream);

	[[nodiscard]] const auto& getDetails() const { return details; }
	[[nodiscard]] const auto& getAttackers() const { return attackers; }
	[[nodiscard]] const auto& getDefenders() const { return defenders; }
	[[nodiscard]] const auto& getName() const { return name; }

	void setDetails(const WarDetails& details_) { details = details_; }
	void setAttackers(const std::vector<std::string>& attackers_) { attackers = attackers_; }
	void setDefenders(const std::vector<std::string>& defenders_) { defenders = defenders_; }
	void setName(const std::string& name_) { name = name_; }

  private:
	void registerKeys();

	WarDetails details;
	std::string name;
	std::vector<std::string> attackers; // order matters! first is primary attacker.
	std::vector<std::string> defenders; // order matters! first is primary defender.
};
} // namespace EU4

#endif // WAR_PARSER