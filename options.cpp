#pragma once

/*
Contains user option functions
*/

#include <string>
#include <ctime>

#include "options.h"
#include "general.h"

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

	// if there is a problem opening the files show an error and exit the function
	if (!candidateFile.is_open() || !voterFile.is_open()) {
		std::cout << "There was a problem opening the database files." << std::endl;

		candidateFile.close();
		voterFile.close();

		return;
	}

	// this string is used to store the updated file contents (after writing new data)
	// and is rewritten back to the file
	std::string updatedFileContents;

	// the line being read from the files
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

			// If the voter has already voted show a message, close the files, and exit the function
			if (line.substr(0, 1) == "y") {
				std::cout << "Voter " << vid << " has already voted!" << std::endl;

				voterFile.close();
				candidateFile.close();

				return;
			}

			// replace the first character (voting status) with y to represent yes
			line.replace(0, 1, "y");

			// append the date string to end of the line
			line.append(" " + std::to_string(tm.tm_mday) + "/" + std::to_string(tm.tm_mon + 1) + "/" + std::to_string(tm.tm_year - 100));
		}

		// append the line to the temporary string (whether updated or not)
		updatedFileContents.append(line + "\n");
	}

	// move to beginning of the file
	voterFile.clear();
	voterFile.seekp(0);

	// write the updated data and close the file
	voterFile << updatedFileContents;
	voterFile.close();

	// reset the string to move on to the voter file
	updatedFileContents = "";

	while (std::getline(candidateFile, line)) {
		// create the candidate given the text string
		auto candidate = construct_candidate(line);

		// check if this is the candidate we are searching for
		if (candidate.id == cid) {
			// increment the candidate votecount
			// since the vote count is the first token we have to get the index of the first delimeter
			// and replace the value with the incremented vote count
			line.replace(0, line.find(" "), std::to_string(++candidate.count));
		}

		// append the line to the temporary string (whether updated or not)
		updatedFileContents.append(line + "\n");
	}

	// move to beginning of the file
	candidateFile.clear();
	candidateFile.seekp(0);

	// write the updated data and close the file
	candidateFile << updatedFileContents;
	candidateFile.close();
}

// would display candidate with lowest vote count
void print_lowest_candidate_votes() {
	Candidate candidate;
	// open the candidate file
	std::fstream myfile;
	myfile.open("candidates.txt", std::ios::in);
	// check if the file is valid
	if (!myfile.is_open())
	{
		std::cout << "File can't open" << std::endl;
	}
	else
	{
		std::string msymbol, mfirstname, mlastname, mgender, msuburb, memail, mphone;
		int mage, mid;
		int min = 1, check = 0, count;
		while (myfile.good())
		{
			//print from the file to the string line by line
			myfile >> count;
			myfile >> mid;
			myfile >> msymbol;
			myfile >> mlastname;
			myfile >> mfirstname;
			myfile >> mage;
			myfile >> mgender;
			myfile >> msuburb;
			myfile >> memail;
			myfile >> mphone;
			// check if the candidate has the smallest votes
			if (count <= min)
			{
				//store to the struct 
				min = count;
				candidate.count = min;
				candidate.id = mid;
				candidate.symbol = msymbol;
				candidate.l_name = mlastname;
				candidate.f_name = mfirstname;
				candidate.age = mage;
				candidate.gender = mgender;
				candidate.suburb = msuburb;
				candidate.email = memail;
				candidate.phone = mphone;
			}
			//check if the file has data
			check++;
		}
		if (check == 1)
			std::cout << "Unable to determine the smallest number  - list is empty" << std::endl;
		//print out the candidate has the smallest votes
		else
			print_candidate(candidate);
	}
	myfile.close();
}

// would display candidate with highest vote count
void print_highest_candidate_votes() {
	Candidate candidate;
	// open the candidate file
	std::fstream myfile;
	myfile.open("candidates.txt", std::ios::in);
	// check if the file is valid
	if (!myfile.is_open())
	{
		std::cout << "File can't open" << std::endl;
	}
	else
	{
		std::string lsymbol, lfirstname, llastname, lgender, lsuburb, lemail, lphone;
		int lage, lid, count;
		int max = 0, check = 0;
		while (myfile.good())
		{
			//print from the file to the string line by line 
			myfile >> count;
			myfile >> lid;
			myfile >> lsymbol;
			myfile >> llastname;
			myfile >> lfirstname;
			myfile >> lage;
			myfile >> lgender;
			myfile >> lsuburb;
			myfile >> lemail;
			myfile >> lphone;
			// check if the candidate has the most votes
			if (count > max)
			{
				//store to the struct 
				max = count;
				candidate.count = max;
				candidate.id = lid;
				candidate.symbol = lsymbol;
				candidate.l_name = llastname;
				candidate.f_name = lfirstname;
				candidate.age = lage;
				candidate.gender = lgender;
				candidate.suburb = lsuburb;
				candidate.email = lemail;
				candidate.phone = lphone;
			}
			//check if the file has data
			check++;
		}
		if (max == 0)
			std::cout << "Unable to determine the largest number  - list is empty" << std::endl;
		else if (check == 1)
			std::cout << "Unable to determine the largest number  - list is empty" << std::endl;
		//print out the candidate has the most votes
		else
			print_candidate(candidate);
	}
	myfile.close();
}
