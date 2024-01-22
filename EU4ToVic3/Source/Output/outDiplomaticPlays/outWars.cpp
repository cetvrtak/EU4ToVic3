#include "outDiplomaticPlays/outWars.h"
#include "CommonFunctions.h"
#include "PoliticalManager/Country/Country.h"
#include <fstream>
#include <ranges>

void OUT::outputWars(const std::string& outputName, const std::vector<EU4::WarParser>& wars)
{
	for (const auto& war: wars)
	{
		std::ofstream output("output/" + outputName + "/common/history/diplomatic_plays/00_" + war.getName() + ".txt");
		if (!output.is_open())
			throw std::runtime_error("Could not create " + outputName + "/common/history/diplomatic_plays/00_" + war.getName() + ".txt");

		output << commonItems::utf8BOM << "DIPLOMATIC_PLAYS = {\n";
		output << "\tc:" << *war.getAttackers().begin() << " = {\n";
		output << "\t\tcreate_diplomatic_play = {\n";
		output << "\t\t\tname = \"" << war.getName() << "\"\n";
		output << "\t\t\n";
		output << "\t\t\ttarget_state = s:" << war.getDetails().targetTag << ".region_state:" << *war.getDefenders().begin() << "\n";
		output << "\t\t\t\n";
		output << "\t\t\trequires_interest_marker = no\n";
		output << "\t\t\twar = yes\n";
		output << "\t\t\t\n";
		output << "\t\t\ttype = " << war.getDetails().warGoalType << "\n";
		output << "\n";

		for (const auto& [holder, type, targetState]: war.getDetails().secondaryWargoals)
		{
			output << "\t\t\tadd_war_goal = {\n";
			output << "\t\t\t\tholder = c:" << holder << "\n";
			output << "\t\t\t\ttype = " << type << "\n";
			output << "\t\t\t\ttarget_state = s:" << targetState << ".region_state:" << *war.getAttackers().begin() <<"\n";
			output << "\t\t\t}\n";
			output << "\n";
		}

		output << "\t\t\tadd_initiator_backers = {";
		for (const auto& attacker: war.getAttackers())
		{
			output << " c:" << attacker;
		}
		output << " }\n";

		output << "\t\t\tadd_target_backers = {";
		for (const auto& defender: war.getDefenders())
		{
			output << " c:" << defender;
		}
		output << " }\n";
		output << "\t\t}\t\n";
		output << "\t}\n";
		output << "}\n";
		output.close();
	}
}
