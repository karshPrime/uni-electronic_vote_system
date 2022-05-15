#pragma once

/*
Contains user option functions
*/

#include <string>
#include <ctime>

#include "options.h"
#include "general.h"

//todo (aweb): check if candidate/voter exists (and other validation)

// would display passed candidate's vote count
void print_candidate_vote_count(int& id) {
	std::ifstream file("candidates.txt");

	if (file.is_open()) {
		std::string line;

		while (std::getline(file, line)) {
			// create the candidate given the text string
			auto candidate = construct_candidate(line);

			// check if this is the candidate we are searching for
			if (candidate.id == id) {
				// print out the candidate vote count
				print_candidate(candidate);

				// another option
				// std::cout << "Candidate " << id << " (" << candidate.f_name << " " << candidate.l_name + ") " << " has " << candidate.count << " votes." << std::endl;
				break;
			}
		}

		file.close();
	}
	else
		std::cout << "candidate database not found" << std::endl;
}

// would add votes to required candidate
void add_vote_to_candidate(int& cid, int& vid) {
	// open the candidate and voter files
	std::fstream candidateFile("candidates.txt");
	std::fstream voterFile("voters.txt");

	// this string is used to store the updated file contents (after writing new data)
	// and is rewritten back to the file
	std::string updatedFileContents;

	if (candidateFile.is_open()) {
		std::string line;

		while (std::getline(candidateFile, line)) {
			// create the candidate given the text string
			auto candidate = construct_candidate(line);

			// check if this is the candidate we are searching for
			if (candidate.id == cid) {
				// increment the candidate votecount
				// since the vote count is the first token we have to get the index of the first delimeter
				// and replace the value with the new vote count
				line.replace(0, line.find(" "), std::to_string(++candidate.count));
			}

			// append the line to the temporary string (whether updated or not)
			updatedFileContents.append(line + "\n");
		}

		// write the updated data and close the file
		candidateFile << updatedFileContents;
		candidateFile.close();
	}
	else
		std::cout << "candidate database not found" << std::endl;

	// reset the string to move on to the voter file
	updatedFileContents = "";

	if (voterFile.is_open()) {
		std::string line;

		while (std::getline(voterFile, line)) {
			// create the voter given the text string
			auto voter = construct_voter(line);

			// check if this is the voter we are searching for
			if (voter.id == vid) {
				// create the timestamp (c++ why you make this so complicated?)
				std::time_t date = time(0);
				std::tm tm;
				localtime_s(&tm, &date);

				// replace the first character (voting status) with y to represent yes
				line.replace(0, 1, "y");

				// append the date string to end of the line
				line.append(" " + std::to_string(tm.tm_mday) + "/" + std::to_string(tm.tm_mon + 1) + "/" + std::to_string(tm.tm_year - 100));
			}

			// append the line to the temporary string (whether updated or not)
			updatedFileContents.append(line + "\n");
		}

		// write the updated data and close the file
		voterFile << updatedFileContents;
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
