// Naweed Wahedi
// Homework-07B
// This program reads the contents of two files and show results,
// using vector sequence containers

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main()
{
   // read answers from file
   ifstream inputFile;
   inputFile.open("CorrectAnswers.txt");
   vector<char> correct;
   char answer;
   while ((inputFile >> answer))
   {
      correct.push_back(answer);
   }
   //closing the file
   inputFile.close();

   // read student answers from file
   ifstream inFile;
   inFile.open("StudentAnswers.txt");
   vector<char> student;
   while(inFile >> answer)
   {
      student.push_back(answer);
   }
   //closing the file
   inFile.close();

   // declare variables
   int incorrect=0;
   int num;
   double percentage;
   if (student.size() != correct.size())
   {
      cout << "Answers in both files are not same" << endl;
      return(0);
   }
   cout<<"\nNaweed Wahedi Grading Program"<<endl;
   cout<<"Incorrect Answers"<<endl;
   cout<<"QNo \tStudent.A\tCorrect.A"<<endl;
   for (int i=0; i < correct.size(); i++)
   {
      if (correct[i] != student[i])
      {
         cout <<i+1 << "\t" << student[i]<<"\t\t" << correct[i] << endl;
         incorrect++;
      }
   }

   //calculat average and display all results
   int qn = correct.size();
   cout << "\nThe total number of questions missed is " << incorrect << endl;
   percentage = 100.00*(qn- incorrect)/qn;
   cout << "The percentage of questions answered correctly is " << percentage <<"%"<< endl;

   if (percentage > 70)
       cout << "Student passed the exam \n" << endl;
   else
       cout << "Student failed the exam \n" << endl;

   //return 0 to mark successful termination
   return 0;
}
