// C++ MINI PROJECT.
// STUDENT MANAGMENT SYSTEM USING FILE HANDLING.
/*

#  Team Members:-

-> Pratham Tagotra.
-> Abhay Solan.
-> Aryan Sharma(1).
-> Aryan Sharma(2).

*/

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include <string>
// #include <string_view>
#include <regex>
#include<conio.h>

using namespace std;

class Student{

    private:
        string name, roll_no, course, address, email_id;
        long long int contact_no;

    public:
        void menu();
        void insert();
        void display();
        void modify();
        void search();
        void deleted(); //Because we can't use function name as delete.
};

void Student :: menu(){

    menustart:

    int choice;
    char x;

    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t| STUDENT MANAGEMENT SYSTEM |" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t 1. Enter New Record" << endl;
    cout << "\t\t\t 2. Display Record" << endl;
    cout << "\t\t\t 3. Modify Record" << endl;
    cout << "\t\t\t 4. Search Record" << endl;
    cout << "\t\t\t 5. Delete Record" << endl;
    cout << "\t\t\t 6. Exit\n"<< endl;

    cout << "\t\t\t............................" << endl;
    cout << "\t\t\tChoose Options:[1/2/3/4/5/6]" << endl;
    cout << "\t\t\t............................" << endl;
    cout << " Enter Your Choice: ";
    cin >> choice;

    switch (choice){
    case 1:
        // do{
        //     insert();
        //     cout << "\n\n\t\t\t Add Another Student Record (Y, N) : ";
        //     cin >> x;
        // } while (x == 'y' || x == 'Y');
        // break;
        while(true){
            insert();
            cout << "\n\n\t\t\t Add Another Student Record (Y, N) : ";
            cin >> x;
            if(x=='Y' || x=='y'){
                continue;
            }
            else{
                break;
            }
        }
        break;



    case 2:
        display();
        break;



    case 3:
        modify();
        break;


    case 4:
        search();
        break;


    case 5:
        deleted();
        break;


    case 6:
        exit(0);

    default:
        cout << "\n\n\t\t\t Invalid Choice... Please Try Again...";
    }

    getch(); 
    goto menustart;
}


void Student :: insert(){
    fstream file;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Add Student Details ---------------------------------------------" << endl;
    cout << "\t\t\tEnter Name: ";
    cin >> name;
    cout << "\t\t\tEnter Roll No.: ";
    cin >> roll_no;
    cout << "\t\t\tEnter Course: ";
    cin >> course;
    cout << "\t\t\tEnter Email Id: ";
    cin >> email_id;
    cout << "\t\t\tEnter Contact No: ";
    cin >> contact_no;
    cout << "\t\t\tEnter Adress: ";
    cin >> address;

    file.open("studentRecord.txt", ios::app | ios::out);
    //ios::in allows input (read operations) from a stream.
    // ios::out allows output (write operations) to a stream.
    // | (bitwise OR operator) is used to combine the two ios flags,
    // meaning that passing ios::in | ios::out to the constructor
    // of std::fstream enables both input and output for the stream.
    file<<" "<<name <<" "<< roll_no <<" " << course <<" " <<email_id <<" " <<contact_no<<" "<<address<<"\n";
    file.close();
}


void Student :: display(){
    fstream file;
    int total=0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Student Record Table ---------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);

    if(!file){
        cout<<"\n\t\t\t\tNo File Present...";
        file.close();
    }
    else{
        file>>name>>roll_no>>course>>email_id>>contact_no>>address;
        while(file.eof()==0){
            cout << "\n\n\t\t\tStudent No.: " << total++ << endl;
            cout << "\t\t\tName: " << name << "\n";
            cout << "\t\t\tRoll No.: " << roll_no << "\n";
            cout << "\t\t\tCourse: " << course << "\n";
            cout << "\t\t\tEmail Id: " << email_id << "\n";
            cout << "\t\t\tContact No.: " << contact_no << "\n";
            cout << "\t\t\tAddress: " << address << "\n";
            file>>name>>roll_no>>course>>email_id>>contact_no>>address;
        }
    }

    if(total==0){
        cout<<"\t\tNo Data to Display\n";
    }
    cout<<"Press any key to continue!!...";

    file.close();

}

void Student :: modify(){
    fstream file,file1;
    string rollno;
    int found=0;

    file.open("studentRecord.txt",ios::in);

    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Student Modify Details ------------------------------------------" << endl;

    if(!file){
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }

    else{
        cout << "\nEnter Roll No. of Student which you want to Modify: ";
        cin >> rollno;

        file1.open("record.txt", ios::app | ios::out);

        file>>name>>roll_no>>course>>email_id>>contact_no>>address;
        while(file.eof() == 0){
            if(rollno != roll_no){
                file1<< name<< " "<< roll_no<< " "<< course<< " "<< email_id<< " "<< contact_no<< " "<<address<< "\n";
            }
            else{
                cout << "\n\t\t\tEnter Name: ";
                cin >> name;
                cout << "\t\t\tEnter Roll No.: ";
                cin >> roll_no;
                cout << "\t\t\tEnter Course: ";
                cin >> course;
                cout << "\n\t\t\tEnter Emial Id: ";
                cin >> email_id;
                cout << "\t\t\tEnter Contact No.: ";
                cin >> contact_no;
                cout << "\t\t\tEnter Address: ";
                cin >> address;

                file1<< name<< " "<< roll_no<< " "<< course<< " "<< email_id<< " "<< contact_no<< " "<<address<< "\n";
                found++;
            }
            
            file>>name>>roll_no>>course>>email_id>>contact_no>>address;
        }

        if(found==0){
            cout<<"\n\n\t\t\t Student Roll No. Not Found...";
        }
        else{
            cout<<"\n\n\t\t\t Updated Sucessfully...";
        }

        file1.close();
        file.close();

        remove("studentRecord.txt");
        rename("record.txt","studentRecord.txt");
    }
}

void Student :: search(){
    fstream file;
    int found=0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Student Search -------------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if(!file){
        cout<<"No file present\n";
    }
    else{

        string rollno;
        cout<<"Enter the Roll No of the student you want to search: ";
        cin>>rollno;

        file>>name>>roll_no>>course>>email_id>>contact_no>>address;

        while(!file.eof()){
            if(rollno==roll_no){
                cout << "\n\n\t\t\tName: " << name << "\n";
                cout << "\t\t\tRoll No.: " << roll_no << "\n";
                cout << "\t\t\tCourse: " << course << "\n";
                cout << "\t\t\tEmail Id: " << email_id << "\n";
                cout << "\t\t\tContact No.: " << contact_no << "\n";
                cout << "\t\t\tAddress: " << address << "\n";
                found++;
            }
            file>>name>>roll_no>>course>>email_id>>contact_no>>address;
        }

        if(found==0){
            cout << "\n\t\t\t Student Roll NO. Not Found....";
        }

        file.close();
    }
}



void Student :: deleted(){
    fstream file,file1;
    string rno;
    int found=0;
    file.open("studentRecord.txt", ios::in);
    if(!file){
        cout<<"No Data to delete...\n";
        file.close();
    }
    else{
        cout << "\nEnter Roll No. of Student which you want Delete Data: ";
        cin >> rno;
        file1.open("record.txt", ios::app | ios::out);

        file>>name>>roll_no>>course>>email_id>>contact_no>>address;

        while(!file.eof()){
            if(roll_no == rno){
                found++;
                cout<<"\n\t\t\tDeleted Sucessfully!...";
            }
            else{
                file1<< name<< " "<< roll_no<< " "<< course<< " "<< email_id<< " "<< contact_no<< " "<<address<< "\n";
            }

            file>>name>>roll_no>>course>>email_id>>contact_no>>address;

        }

        if(found==0){
            cout << "\n\t\t\t Student Roll NO. Not Found....";
        }
        file.close();
        file1.close();

        remove("studentRecord.txt");
        rename("record.txt", "studentRecord.txt");
    }
}


int main(){

    Student s;
    s.menu();

    return 0;
}