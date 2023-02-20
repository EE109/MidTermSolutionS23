/*********************************************
* Alabama A&M University - EE109 - Spring 2023
* Mid Term Exam: Accounting Epic
* By:            Prof J Zehnpfennig, PE
* Created:       20 Februrary 2023
* Last Updated:  20 Februrary 2023
* Happy President's Day!
*********************************************/


#include <iostream>
#include <string>
#include <cstdlib> //JZ - allows us to invoke system commands such as 'clear' to clear the screen

using namespace std;

float *userInput(int numValues); //JZ - the asterisks '*' before the function or variable name tell the compiler to expect an array
float *bubbleSort(float *values);
float sumVal(float *values, int numVals);
float taxVal(float totalVal);
void userOutput(float *values, float totalVal, float totalTax, int NumMonths);


int main() 
{
  int numVal = 0;
  float *userVals, sumMonths = 0.0, totalTax = 0.0;
  char exitCondi = 'n' ;
  system(clear);
  cout << "\t\t\tWelcome to the Tax Collector!\n";
  
  while (exitCondi != 'y' /************************add a condition to exit the loop if the user inputs 'Y'************************/)
    {
      while (numVal <= 0 /************************add a condition to limit the max number of months to 12************************/)
        {
          cout << "\nHow many months would we like to calculate taxes for? (1 - 12): ";
          cin >> numVal;
        }
      
      //JZ - Function calls below - these are done and correct, no need to change
      *userVals = *userInput(numVal);
      *userVals = *bubbleSort(userVals);
      sumMonths = sumVal(userVals, numVal);
      totalTax = taxVal(sumMonths);
      userOutput(userVals, sumMonths, totalTax, numVal);

      cout << "\nWould you like to calculate another set of taxes? (y/n): ";
      /***********************add an expression to collect the user's answer into variable exitCondi***********************/
      /***********************add a while loop to check the user's input and make sure it is one of the two acceptable values.  If it is not, send an error and give the user another chance to input the correct values.***********************/
    }
  return 0;
}

//JZ - Function to collect the accounting values from the user.  Input: number of values to collect (integer numValues); Output: float array of size numValues containing the user's input values.
float *userInput(int numValues)
{
  float values[numValues];  //JZ - initializes data collection array
  int x = 0;  //JZ - initalizing counter value

  //JZ - iterative loop to collect each monthly value
  for (x = 0; x < numValues; x++)
    {
      system(clear); //JZ - clears the screen
      cout << "\t\t\tTax Calculator!\n\nThis program collects " << numValues <<" monthly revenue values.\n";
      cout << "\nPlease input the total revenue for month " << x + 1 << ": ";
      cin >> values[x];
    }
  return (float *)values;
}

//JZ - bubble sort logic.  This is complete and you do not need to do anything here.  Input: the array of monthly values; Output: the sorted monthly value list
float *bubbleSort(float *values)
{
  bool done = false;
  int x = 0, y = 0;
  int sizeVal = sizeof(values) / sizeof(float);
  float temp = 0; 
    
  while (done == false)
    {
      done = true;  
     
      for (x = 1; x < sizeVal; x++)
        {
          if (values[x-1] > values[x])
          {
            done = false;
            temp = values[x];
            values[x] = values[x-1];
            values[x-1] = temp;
          }
        }
    }
  return (float *)values;
}

//JZ - Sum monthly values.  Input: sorted float values array & integer total number of values; Output: the sum of monthly values.
float sumVal(float *values, int numVals)
{
  float totalValue = 0.0; //JZ - initialize total values
  int x = 0;  //initalize iterative counter variable
  
  /***********************make an iterative loop that goes from x = 0 to numvals.  This loop's curly brackets and logic are already done, below***********************/
  {
    totalValue = values[x];
  }
  return 0; /***********************Change the 0 to something that returns the sum totaled value***********************/
}


//JZ - Tax value calculator.  Should ask the user for tax rate between 7% and 45%.  Input: summed monthly revenue float; Output: float total taxes due
float taxVal(float totalVal)
{
  float taxRate = 0.30; //JZ - initializes the tax rate to the default 30%

 //***********************Add a condition controlled loop to ask the user for tax rate.  Only accept values between 0.07 and 0.45***********************/
  
  int totalTax = totalVal * taxRate; //JZ - calculates the taxes due.  This is done, no need to change.
  return totalTax; //JZ - returns taxes due
}


//JZ - Output to the screen.  Input: float array of monthly values, the float summed total revenues, and the float tax due.  Output: nothing
void userOutput(float *values, float totalVal, float totalTax, int numMonths)
{
  /***********************declare an integer counter value 'x' initialized to 0***********************/
  /***********************Clear the screen***********************/
  cout << "The monthly values were: \n";
  /***********************create an iterative loop that uses 'x', goes from 0, stops after 'numMonth' iterations, and increments x by one each iteration***********************/
  /***********************Output each month's value***********************/
  /***********************close the iterative loop***********************/
  cout << "\nThis totals to: $" /***********************output totaled value***********************/;
  /***********************Output a sentence on a new line stating "The total taxes due is: $" followed by the tax value***********************/
    
}