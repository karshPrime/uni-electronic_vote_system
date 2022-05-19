# Electoral Commission
In this Assignment, you are required to implement a practical application based on State 
electoral commission E-system. You have to design and program E-system, where the 
assessment involves project brief, project demonstrate (Team based - 30%) and a final project 
report (Team based - 20%). This particular project task is for project coding and demonstration 
which is assessed 15% of your unit grades. Always engage in discussion forum and further 
announcements for the project related matters which will be available in Canvas. You are 
responsible for checking Canvas on a regular basis to stay in formed with regards to any updates 
about the project. 

<details>
<summary>Detailed Requirements</summary>
 
# Task 1: Create a Primary Database 
To start with, create a primary database with voter table and a candidate table as shown below. Add at least 10 different field names on both. You need to input sample datasets (create at least 10 to 15 datasets). 

### Voter Table
| Field Name | Data Type  |
|-|-|
| Voter ID   | Integer    |
| Name       | String     |
| Age        | Integer    |
| Suburb     | String     |
| Status     | Boolean    |

### Candidate Table
| Field Name | Data Type  | 
|-|-|
| Symbol     | String     | 
| First Name | String     | 
| Last Name  | String     |
| Age        | Integer    | 
| Suburb     | String     | 
| Count      | Integer    | 
| Phone No.  | Integer    |
| Sex        | String     |
| Email      | String     |


## Task Requirements: 
- This assignment must be written in C++ 
- Your code must have appropriate comments including your name and student number, the name of the .cpp file, the purpose of the program, brief explanations of variables and explanations of any code, which is not obvious to another programmer. 
- Include a block (multiline) comment summarising the input, output and local variables used in your program. 
- Include a block comment stating any equations, and test data. 
- Use appropriate and descriptive variable and constant identifiers. 
- Project report: Write a brief (no more than several pages) report, which illustrates your program design (algorithm or flowchart, identification of variables, constants) and include  evidence of testing – screen shots or pasted output text, and the contents of the .cpp file.


# Task 2: Analyse the status
In this module, you are asked to analyse the status of all candidates while people are voting in different suburbs of Melbourne at different time slots. 

This challenge is about using a collection (list) of integers and allowing the user to select options from a menu to perform operations on the list.
 
Your program should display a menu options to the user as follows: 
```
 P - Print numbers for a particular candidate (for example candidate 1 or candidate 2) 
 A - Add number of votes to a candidate (with an existing voter ID) 
 S - Display the smallest number of votes candidate 
 L - Display the largest number of votes candidate 
 Q - Quit 
Enter your choice: 
```

The program should only accept valid choices from the user, both upper and lowercase selections should be allowed. 
- If an illegal choice is made, you should display, "Unknown selection, please try again" and the menu options should be displayed again. 
- If the user enters 'P' or 'p', you should display number of votes (ints) in the list for a candidate. 
- If the list is empty you should display "the list is empty" 
- If the user enters 'A' or 'a' then you should prompt the user for an integer (Vote) to add to the candidate which you will add to the list of candidate’s dataset and then display it was added. For example, if the vote enters to candidate x You should display, "Candidate x has 20 votes". 
- If the list is empty you should display, "Unable to calculate the mean - no data" 
- If the user enters 'S' or 's' you should display the smallest number of votes in the list. 
- If the list is empty you should display, "Unable to determine the smallest number - list is empty" 
- If the user enters 'L' or 'l' you should display the largest number of votes in the list. 
- If the list is empty you should display, "Unable to determine the largest number - list is empty" 
- If the user enters 'Q' or 'q' then you should display 'Goodbye" and the program should terminate. 

Before you begin. Write out the steps you need to take and decide in what order they should be done. 

Think about what loops you should use as well as what you will use for your selection logic. 

This exercise can be challenging! It may likely take a few attempts before you complete it -- that's OK! 

Finally, be sure to test your program as you go and at the end. 

**Hint:** Come up with your own ideas! 

# Other General Requirements 
This section contains the general requirements which must be met by your submitted project. 
Marks will be deducted if you fail to meet any of the following general requirements. 
- You must include code-level comments in your resource file to explain the key parts of your code. 
- You must follow the instructions given in each task (team based) to complete the corresponding task. 
- You must submit your project related submissions (code, demonstration, and report) before the due date mentioned in the canvas project submission page. 
- You (the Team) are only allowed to use Text File as database for your project outcome. We will not accept any other formats for assessment purpose. 

</details>
