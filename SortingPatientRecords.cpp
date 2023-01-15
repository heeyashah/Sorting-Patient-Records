#include <iostream>
#include <cstring> // required for string manipulation
#include <iomanip> // required for tabular output

using namespace std; 

void swap ();

int main()
{
    // Provided arrays and constants
    const int NUM_PATIENTS = 10; // 10 patients will be included, this value cannot be modified
    const int MAX_NAME_LENGTH = 10; // no names longer than 10 characters, this value cannot be modified
    const int ID_LENGTH = 8;
    unsigned int age[NUM_PATIENTS] = {50, 22, 22, 89, 15, 16, 22, 32, 15, 66}; // 1D int array age of each patient
    char id[NUM_PATIENTS][ID_LENGTH + 1] = {"10854893", "10983922", "98333894", "57290888", "14899822", "79278282", "44293822", "62911023", "28399020", "33212322"}; // 1D int array identification #
    char firstName[NUM_PATIENTS][MAX_NAME_LENGTH] = {"allison", "michael", "michael", "johnny", "sabrina", "helen", "ignacio", "melissa", "hassan", "melody"}; // 2D char array: first names for patients
    char lastName[NUM_PATIENTS][MAX_NAME_LENGTH] = {"pratt","xiao", "barkley", "wu", "sappal", "mcdonald", "garza", "tran", "nahas", "baker"}; // 2D char array: last names for patients
    char sex[NUM_PATIENTS] = {'f','m','m','m','f','f','m','f','m','f'}; // 1D char array sex of the patient

    bool validInput = false; //set boolean value to check for input to false to start


    // PART 1: Select a primary sorting category from user input & PART 3/4: Sorting patient records
    do{
    
    char category[5][6] = {"age", "id", "sex", "last", "first"}; //define the categories (character array with index 5 and 6) that the user is able to sort the information by  
    cout << "Please enter the sorting category (Age, ID, First, Last, Sex): "; //ask user to enter what category they want to sort by
    int count = 1; // set count equal to 1
    char array[count]; //define an array with index count 

    char input = cin.get(); //takes the input from the user about the sorting category and stores it in input
    count = 0; //set count equal to 0

//loops through each character inputted by the user and stores it into 'input' until return is entered 
    while (input != '\n') {
        array[count] = input;
        count++; 
        input = cin.get();
    }
    array[count] = 0; //sets the array to 0 

//checks the ASCII value of the characters that were inputted by the user and converts them all to lowercase letters 
    for (int i=0; i<= strlen(array)-1; i++){
        if ((int)array[i]>65 && (int)array [i]<91){
            array[i]=char((int)array[i]+32);
        }
    }

    int caseNumber = 5; //define a variable caseNumber that is for running through the 5 different cases depending on what the user enters
    for (int i = 0; i < 5; i++) {
        if (strcmp(array, category[i]) == 0) { //compares the array and the category
            caseNumber = i; // if they are equal case number is equal to the category number
        } 
    }    

    if (caseNumber == 0){ //for caseNumber 0 (age)
        cout << "Case 1, sorting by Age."<< endl; //print statement for sorting by age
        
        for( int i=0; i< NUM_PATIENTS-1; i++){ 
            for (int j = 0; j<NUM_PATIENTS-1-i; j++){ //compares the values within NUM_PATIENTS 
                if (age[j]>age[j+1]){ //check if age is bigger than the age to the right of it
            //switch all corresponding categories to new sorting order
                swap (age[j], age[j+1]);
                swap(id[j], id[j + 1]); 
                swap(firstName[j], firstName[j + 1]);
                swap(lastName[j], lastName[j + 1]);
                swap(sex[j], sex[j + 1]); 
                }

            //sort by first name as tiebreaker   
                else if (age[j]==age[j+1]){ //if the ages are equal to each other
                    if (strcmp(firstName[j], firstName[j+1])>0){ //sort by first name by checking if the first string is alphabetically later than the second
                    //switch all corresponding categories to new sorting order
                        swap(age[j], age[j + 1]); 
                        swap(id[j], id[j + 1]);
                        swap(firstName[j], firstName[j + 1]);
                        swap(lastName[j], lastName[j + 1]);
                        swap(sex[j], sex[j + 1]);
                }
        }
            }

        }
    }

    else if (caseNumber == 1){ // for caseNumber 1 (id)
        cout << "Case 2, sorting by ID."<< endl; //print statement for sorting by id
        
        for( int i=0; i< NUM_PATIENTS-1; i++){
            for (int j = 0; j<NUM_PATIENTS-1-i; j++){ //compares values within NUM_PATIENTS
                if (stoi(id[j])>stoi (id[j+1])){ //checks if the integer value of the id is greater than the one to the right of it
                //if greater, swap all corresponding categories to new sorting order
                    swap (age[j], age[j+1]);
                    swap(id[j], id[j + 1]); 
                    swap(firstName[j], firstName[j + 1]);
                    swap(lastName[j], lastName[j + 1]);
                    swap(sex[j], sex[j + 1]); 
                }  
                else if (stoi(id[j])==stoi (id[j+1])){ //if integer value of the id is equal 
                    if (strcmp(firstName[j], firstName[j+1])>0){ //sort by first name by checking if the first string is alphabetically later than the second
                    //switch all corresponding categories to new sorting order 
                        swap(age[j], age[j + 1]); 
                        swap(id[j], id[j + 1]);
                        swap(firstName[j], firstName[j + 1]);
                        swap(lastName[j], lastName[j + 1]);
                        swap(sex[j], sex[j + 1]);
                }
            }       
        }
    }
    }

    else if (caseNumber == 2){ // for caseNumber 2 (sex)
        cout << "Case 3, sorting by Sex."<< endl; //print statement for sorting by sex
        
        for( int i=0; i< NUM_PATIENTS-1; i++){
            for (int j = 0; j<NUM_PATIENTS-1-i; j++){ //compares values within NUM_PATIENTS
                if (sex[j] + '0' > sex[j+1] + '0'){ //checks if the character for sex is greater (in ASCII value) than the one to the right of it
                //if greater, swap all corresponding categories to new sorting order
                    swap (age[j], age[j+1]);
                    swap(id[j], id[j + 1]); 
                    swap(firstName[j], firstName[j + 1]);
                    swap(lastName[j], lastName[j + 1]);
                    swap(sex[j], sex[j + 1]); 
                }  
        else if (sex[j] + '0' == sex[j+1] + '0'){ //if the ASCII values for sex are equal 
                if (strcmp(firstName[j], firstName[j+1])>0){ //sort by first name by checking if the first string is alphabetically later than the second
                //switch all corresponding categories to new sorting order
                    swap(age[j], age[j + 1]); 
                    swap(id[j], id[j + 1]);
                    swap(firstName[j], firstName[j + 1]);
                    swap(lastName[j], lastName[j + 1]);
                    swap(sex[j], sex[j + 1]);
                }
        }

        }
    }
    }

    else if (caseNumber == 3){ //for caseNumber 3 (last name)
        cout << "Case 4, sorting by Last Name."<< endl; //print statement for sorting by last name
        
        for( int i=0; i< NUM_PATIENTS-1; i++){ 
            for (int j = 0; j<NUM_PATIENTS-1-i; j++){ //compares values within NUM_PATIENTS
                if (strcmp(lastName[j], lastName[j+1])>0){ //checks if the first input string is alphabetically later than the second
                //if it is, switch all corresponding categories to new sorting order
                    swap (age[j], age[j+1]);
                    swap(id[j], id[j + 1]); 
                    swap(firstName[j], firstName[j + 1]);
                    swap(lastName[j], lastName[j + 1]);
                    swap(sex[j], sex[j + 1]); 
                }  
        else if ((strcmp(lastName[j], lastName[j+1])==0)){ //if the input strings are equal to each other 
                if (strcmp(firstName[j], firstName[j+1])>0){ //sort by first name by checking if the first string is alphabetically later than the second
                //switch all corresponding categories to new sorting order 
                    swap(age[j], age[j + 1]); 
                    swap(id[j], id[j + 1]);
                    swap(firstName[j], firstName[j + 1]);
                    swap(lastName[j], lastName[j + 1]);
                    swap(sex[j], sex[j + 1]);
                }
        }
            }

    }
}

    else if (caseNumber == 4) { //for caseNumber 4 (first name)
            cout << "Case 5, sorting by First Name." << endl; //print statement for sorting by first name

            for (int i = 0; i < NUM_PATIENTS - 1; i++) {
                for (int j = 0; j < NUM_PATIENTS - i - 1; j++){ //compares values within NUM_PATIENTS
                    if (strcmp(firstName[j], firstName[j + 1])>0) { //sort by first name by checking if the first string is alphabetically later than the second
                //switch all corresponding categories to new sorting order 
                        swap(age[j], age[j + 1]); 
                        swap(id[j], id[j + 1]);
                        swap(firstName[j], firstName[j + 1]);
                        swap(lastName[j], lastName[j + 1]);
                        swap(sex[j], sex[j + 1]);
                    }
                }
            }
    }

    else if (caseNumber == 5) { // checks for caseNumber 5 which is not one of the categories that were specified (AKA ALL OTHER INPUTS)
        cout << "Unexpected input. "<<endl; 
        validInput = true; //do while loop runs again 
    }
}

while (validInput == true); //loop runs again as long as it is true



    // PART 2: Outputting patient records to terminal in tabular form

    //tabular form for age
    cout << setw(12) << "Age: ";
    for (int i = 0; i < NUM_PATIENTS; i++){
        cout << setw (10) << age[i];
    }

    cout <<endl; //line break 

    //tabular form for id 
    cout << setw(12) << "ID: ";
    for (int i = 0; i < NUM_PATIENTS; i++){
        cout << setw (10) << id[i];
    }

    cout <<endl; //line break

    //tabular form for first name 
    cout << setw(10) << "First Name: ";
    for (int i = 0; i < NUM_PATIENTS; i++){
        cout << setw (10) << firstName[i];
    }

    cout <<endl; //line break 

    //tabular form for last name 
    cout << setw(12) << "Last Name: ";
    for (int i = 0; i < NUM_PATIENTS; i++){
        cout << setw (10) << lastName[i];
    }

    cout <<endl; //line break 

    //tabular form for sex
    cout << setw(12) << "Sex: ";
    for (int i = 0; i < NUM_PATIENTS; i++){
        cout << setw (10) << sex[i];
    }

//two line breaks (for extra space & to help space out table)
    cout << endl; 
    cout << endl; 

    return 0;
}