#include <iostream>
using namespace std;

class KUStudent
{
public:
    KUStudent(); 
    // Initialize stud_fname, stud_lname, stud_kuid and stud_dpt into empty strings("").
    
    KUStudent(string fname, string lname); 
    // Initialize stud_fname and stud_lname with fname and lname respectly.
    // Initialize stud_kuid and stud_dpt into empty strings("").

    KUStudent(string fname, string lname, string kuid, string dpt);
    // Initialize stud_fname, stud_lname, stud_kuid and stud_dpt 
    // with fname, lname, kuid and dpt respectly.

    void set_name(string fname, string lname);
    // Set student's name

    void set_kuinfo(string kuid, string dpt);
    // Set student's KUID and Department

    void output();
    // Output the student's infomation

private:
    string stud_fname;
    string stud_lname;
    string stud_kuid;
    string stud_dpt;
};

int main()
{
    KUStudent stud;
    
    string fname, lname, kuid, dpt;
    cout << "Please input the student's name (firstname lastname): ";
    cin >> fname >> lname;
    stud.set_name(fname,lname);
    cout << "Please input the student's KUID and department: ";
    cin >> kuid >> dpt;
    stud.set_kuinfo(kuid,dpt);
    stud.output();
    return 0;
}

// Class Member Function Definition: INSERT YOUR CODE
KUStudent::KUStudent()
{
	
}
KUStudent::KUStudent(string fname, string lname)
{
	stud_fname = fname;
	stud_lname = lname;
}
KUStudent::KUStudent(string fname, string lname, string kuid, string dpt)
{
	stud_fname = fname;
	stud_lname = lname;
	stud_kuid = kuid;
	stud_dpt = dpt;
}

void KUStudent::set_name(string fname, string lname)
{
	stud_fname = fname;
	stud_lname = lname;
}
void KUStudent::set_kuinfo(string kuid, string dpt)
{
	stud_kuid = kuid;
	stud_dpt = dpt;
}
void KUStudent::output()
{
	cout << "Your name is " << stud_fname << " " << stud_lname << "." << endl
	     << "Your KU ID number is " << stud_kuid << "." << endl
	     << "You are in department " << stud_dpt << "." << endl;
}





























