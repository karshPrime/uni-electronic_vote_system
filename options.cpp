/*
Contains user option functions
*/

#include <ctime>
#include "options.h"
#include "general.h"
#include "person.cpp"

// would display passed candidate's vote count
void print_candidate_vote_count(int &id) {
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
  } else {
    std::cout << "candidate database not found" << std::endl;
  }
}

// would add votes to required candidate
void add_vote_to_candidate(int &cid, int &vid) {
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
  std::vector<Candidate> losing = {};
  Candidate candidate;

  // open the candidate file
  std::fstream myfile;
  myfile.open("candidates.txt", std::ios::in);

  // check if the file is valid
  if (!myfile.is_open()) {
    std::cout << "File can't open" << std::endl;
  } else {
    std::size_t min = 1, check = 0;
    while (myfile.good()) {
      //print from the file to the string line by line
      myfile >> candidate.count;
      myfile >> candidate.id;
      myfile >> candidate.symbol;
      myfile >> candidate.l_name;
      myfile >> candidate.f_name;
      myfile >> candidate.age;
      myfile >> candidate.gender;
      myfile >> candidate.suburb;
      myfile >> candidate.email;
      myfile >> candidate.phone;
      // check if the candidate has the smallest votes
      if (candidate.count < min) {
        //store to the struct
        min = candidate.count;
        losing.clear();
        losing.push_back(candidate);
      } else if (candidate.count == min) {
        losing.push_back(candidate);
      }
      //check if the file has data
      check++;
    }
    if (check == 1) {
      std::cout << "Unable to determine the smallest number  - list is empty" << std::endl;
      //print out the candidate has the smallest votes
    } else {
      std::cout << losing.size() << " Candidate(s) got total votes: " << min << std::endl;
      for (auto & winners : losing) {
        winners.print();
        std::cout << std::endl;
      }
    }
  }
  myfile.close();
}

// would display candidate with highest vote count
void print_highest_candidate_votes() {
  std::vector<Candidate> winning = {};
  Candidate candidate;

  // open the candidate file
  std::fstream myfile;
  myfile.open("candidates.txt", std::ios::in);

  // check if the file is valid
  if (!myfile.is_open()) {
    std::cout << "File can't open" << std::endl;

  } else {
    std::size_t max = 0, check = 0;
    while (myfile.good()) {
      //print from the file to the string line by line
      myfile >> candidate.count;
      myfile >> candidate.id;
      myfile >> candidate.symbol;
      myfile >> candidate.l_name;
      myfile >> candidate.f_name;
      myfile >> candidate.age;
      myfile >> candidate.gender;
      myfile >> candidate.suburb;
      myfile >> candidate.email;
      myfile >> candidate.phone;

      // check if the candidate has the most votes
      if (candidate.count > max) {
        //store to the struct
        max = candidate.count;
        winning.clear();
        winning.push_back(candidate);
      } else if (candidate.count == max) {
        winning.push_back(candidate);
      }

      //check if the file has data
      check++;
    }

    if (max == 0 or check == 1) {
      std::cout << "Unable to determine the largest number  - list is empty" << std::endl;
    } else {
      std::cout << winning.size() << " Candidate(s) got total votes: " << max << std::endl;
      for (auto & winners : winning) {
        winners.print();
        std::cout << std::endl;
      }
    }
  }
  myfile.close();
}
