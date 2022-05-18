/*
Contains user option functions
*/

#include <ctime>
#include <limits>

#include "options.h"
#include "general.h"
#include "person.cpp"

// would display passed candidate's vote count
void print_candidate_vote_count(int& id) {
	std::ifstream file("candidates.txt");

	if (file.is_open()) {
		std::string line;

		while (std::getline(file, line)) {
			// create and initialize candidate from the given text string
			Candidate candidate; candidate.init(line);

			// check if this is the candidate we are searching for
			if (candidate.id == id) {
				// print out the candidate vote count
				candidate.print();

				break;
			}
		}
		file.close();
	}
	else {
		std::cout << "candidate database not found" << std::endl;
	}
}

// would add votes to required candidate
void add_vote_to_candidate(int& cid, int& vid) {
	// open the candidate and voter files
	std::fstream candidate_file("candidates.txt");
	std::fstream voter_file("voters.txt");

	// if there is a problem opening the files show an error and exit the function
	if (!candidate_file.is_open() || !voter_file.is_open()) {
		std::cout << "There was a problem opening the database files." << std::endl;

		candidate_file.close();
		voter_file.close();

		return;
	}

	// this string is used to store the updated file contents (after writing new data)
	// and is rewritten back to the file
	std::string updated_file_contents;

	// the line being read from the files
	std::string line;

	while (std::getline(voter_file, line)) {
		// create and initialize voter from the given text string
		Voter voter; voter.init(line);

		// check if this is the voter we are searching for
		if (voter.id == vid) {
			// create the timestamp (c++ why you make this so complicated?)
			std::time_t date = time(0);
			std::tm tm;
			localtime_s(&tm, &date);

			// If the voter has already voted show a message, close the files, and exit the function
			if (line.substr(0, 1) == "y") {
				std::cout << "Voter " << vid << " has already voted!" << std::endl;

				voter_file.close();
				candidate_file.close();

				return;
			}
			// replace the first character (voting status) with y to represent yes
			line.replace(0, 1, "y");

			// append the date string to end of the line
			line.append(" " + std::to_string(tm.tm_mday) + "/" + std::to_string(tm.tm_mon + 1) + "/" + std::to_string(tm.tm_year - 100));
		}
		// append the line to the temporary string (whether updated or not)
		updated_file_contents.append(line + "\n");
	}

	// move to beginning of the file
	voter_file.clear();
	voter_file.seekp(0);

	// write the updated data and close the file
	voter_file << updated_file_contents;
	voter_file.close();

	// reset the string to move on to the voter file
	updated_file_contents = "";

	while (std::getline(candidate_file, line)) {
		// create and initialize candidate from the given text string
		Candidate candidate; candidate.init(line);

		// check if this is the candidate we are searching for
		if (candidate.id == cid) {
			// increment the candidate votecount
			// since the vote count is the first token we have to get the index of the first delimeter
			// and replace the value with the incremented vote count
			line.replace(0, line.find(' '), std::to_string(++candidate.count));
		}

		// append the line to the temporary string (whether updated or not)
		updated_file_contents.append(line + "\n");
	}

	// move to beginning of the file
	candidate_file.clear();
	candidate_file.seekp(0);

	// write the updated data and close the file
	candidate_file << updated_file_contents;
	candidate_file.close();
}

// would display candidate with lowest vote count
void print_lowest_candidate_votes() {
	// open candidate file
	std::ifstream file("candidates.txt");

	// store multiple candidates since they can have equal votes
	std::vector<Candidate> results;

	// if failed to open file show an error and exit the function
	if (!file.is_open()) {
		std::cout << "unable to open candidate file" << std::endl;
		return;
	}

	// if the list is empty (empty file) show an error and exit function
	if (file.peek() == std::ifstream::traits_type::eof()) {
		std::cout << "Unable to determine the smallest number  - list is empty" << std::endl;
		return;
	}

	// the line being read from the files
	std::string line;

	// the current lowest vote count (defaults to highest int value)
	int minVoteCount = INT_MAX;

	while (std::getline(file, line)) {
		// create and initialize candidate from the given text string
		Candidate candidate; candidate.init(line);

		// if the candidate has lower vote count
		// clear the results and set the new minimum
		if (candidate.count < minVoteCount) {
			minVoteCount = candidate.count;

			results.clear();
			results.push_back(candidate);
		}
		// if candidate vote count is equal to minimum
		// add them to the list
		else if (candidate.count == minVoteCount) {
			results.push_back(candidate);
		}
	}

	// print out the results
	std::cout << results.size() << " candiate(s) have the lowest votes equal to: " << minVoteCount << std::endl;
	std::cout << "The following candidates are: " << std::endl;

	for (auto& candidate : results) {
		candidate.print();
		std::cout << "----------" << std::endl;
	}

	file.close();
}

// would display candidate with highest vote count
void print_highest_candidate_votes() {
	// open candidate file
	std::ifstream file("candidates.txt");

	// store multiple candidates since they can have equal votes
	std::vector<Candidate> results;

	// if failed to open file show an error and exit the function
	if (!file.is_open()) {
		std::cout << "unable to open candidate file" << std::endl;
		return;
	}

	// if the list is empty (empty file) show an error and exit function
	if (file.peek() == std::ifstream::traits_type::eof()) {
		std::cout << "Unable to determine the smallest number  - list is empty" << std::endl;
		return;
	}

	// the line being read from the files
	std::string line;

	// the current highest vote count (defaults to lowest int value)
	int maxVoteCount = -1;

	while (std::getline(file, line)) {
		// create and initialize candidate from the given text string
		Candidate candidate; candidate.init(line);

		// if the candidate has higher vote count
		// clear the results and set the new maximum
		if (candidate.count > maxVoteCount) {
			maxVoteCount = candidate.count;

			results.clear();
			results.push_back(candidate);
		}
		// if candidate vote count is equal to maximum
		// add them to the list
		else if (candidate.count == maxVoteCount) {
			results.push_back(candidate);
		}
	}

	// print out the results
	std::cout << results.size() << " candiate(s) have the highest votes equal to: " << maxVoteCount << std::endl;
	std::cout << "The following candidates are: " << std::endl;

	for (auto& candidate : results) {
		candidate.print();
		std::cout << "----------" << std::endl;
	}
	file.close();
}
