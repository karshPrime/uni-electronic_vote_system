#pragma once

/*
Contains user option functions
*/

#include <string>
#include <ctime>

#include "options.h"
#include "general.h"

//todo (aweb): comment code

// would display passed candidate's vote count
void print_candidate_vote_count(int& id) {
	std::ifstream file("candidates.txt");

	if (file.is_open()) {
		std::string line;
		while (std::getline(file, line)) {
			auto candidate = construct_candidate(line);

			if (candidate.id == id) {
				std::cout << "Candidate " << id << " has " << candidate.count << " votes." << std::endl;
				break;
			}
		}

		file.close();
	}
	else
		std::cout << "candidate database not found" << std::endl;
}

// would add votes to required candidate
// todo(aweb): clean up and comment this monstrosity
void add_vote_to_candidate(int& cid, int& vid) {
	std::fstream candidateFile("candidates.txt");
	std::fstream voterFile("voters.txt");
	std::string tmpStr;

	if (candidateFile.is_open()) {
		std::string line;

		while (std::getline(candidateFile, line)) {
			auto candidate = construct_candidate(line);

			if (candidate.id == cid) {
				line.replace(0, line.find(" "), std::to_string(++candidate.count));
				tmpStr.append(line + "\n");
			}
		}

		candidateFile << tmpStr;
		candidateFile.close();
	}
	else
		std::cout << "candidate database not found" << std::endl;

	tmpStr = "";

	if (voterFile.is_open()) {
		std::string line;

		while (std::getline(voterFile, line)) {
			auto voter = construct_voter(line);

			if (voter.id == vid) {
				std::time_t date = time(0);
				std::tm tm;
				localtime_s(&tm, &date);

				line.replace(0, 1, "y");
				line.append(" " + std::to_string(tm.tm_mday) + "/" + std::to_string(tm.tm_mon + 1) + "/" + std::to_string(tm.tm_year - 100));
			}

			tmpStr.append(line + "\n");
		}

		voterFile << tmpStr;
		voterFile.close();
	}
	else
		std::cout << "voter database not found" << std::endl;
}

// would display candidate with lowest vote count
void print_lowest_candidate_votes() {

}

// would display candidate with highest vote count
void print_highest_candidate_votes() {

}
