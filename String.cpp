#include <iostream> 
#include <fstream>  
#include <string>   
using namespace std;
int main() {
    ofstream outputFile("student_data.txt",ios::app); 

   
    if (!outputFile.is_open()) {
        cerr << "Error opening file!" <<endl;
        return 1; 
    }

    string studentName;
    int studentScore;
    char choice;

    do {
        cout << "Enter student name: ";
        getline(cin >>ws, studentName);
        
        cout << "Enter student score: ";
        cin >> studentScore;

        
        outputFile << studentName << "=" << studentScore <<endl;

        cout << "Do you want to add another student? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    outputFile.close(); 

    cout << "Student data saved to student_data.txt" <<endl;

    ifstream inFile("student_data.txt");
    string line;

    if(!inFile) {
        cout<<"File not Found";
        return 1;
    }
    while (getline(inFile, line)) {
        cout<<line<<endl;

    }

    inFile.close();
    return 0; 
}