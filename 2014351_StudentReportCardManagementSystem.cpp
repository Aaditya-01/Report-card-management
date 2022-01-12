#include <iostream>
#include<fstream>
#include<windows.h>
using namespace std;
struct student
{
char name[80];
char id[80];
int roll;
float cs1,cs2,cs3,cs4;
float phy1,phy2,phy3,phy4;
float chem1,chem2,chem3,chem4;
float math1,math2,math3,math4;
float eng1,eng2,eng3,eng4;
float sum1,sum2,sum3,sum4;
float average1,average2,average3,average4;
float totper;
};
void intro();
void mainmenu();
void acceptdata();
void view_Specific(int);
void viewall();
void result(int);
void deleterecord(int);
void modify(int);

int main()
{
    system("color a");
    char c;
    system("cls");
    intro();

    do{
   system("cls");
   system("color e");
   cout<<"\n\n";
   cout<<"==================STUDENT REPORT CARD MANEGEMENT SYSTEM=================="<<endl;
   cout<<endl;
   cout<<"\t\t\t\t1. MAIN MENU\n\n";
   cout<<"\t\t\t\t2. EXIT\n\n";
   cout<<"ENTER YOUR CHOICE :";
   cin>>c;
   system("cls");
   switch(c)
   {
   case '1':
    {
        mainmenu();
        break;
    }
   case '2':
    {          cout << "\t\t     THANK YOU FOR USING THIS SOFTWARE"<<endl;

        cout << "\n\n";
    }
   }
    }while(c!='2');
    return 0;
}
void acceptdata()
{
    system("cls");
    student s;
    ofstream outfile;
    outfile.open("Report.txt",ios::app|ios::binary);
    if(outfile.fail())
    {
        cout<<"THE FILE COULD NOT BE OPEN...press enter key";
        cin.ignore();
        cin.get();
    }
    cout<<"\n\n";
    cout<<"\t\t=======CREATE A REPORT CARD========\n\n";
    cout<<"ENTER STUDENT'S FULL NAME :";
    cin.ignore();
    cin.getline(s.name,80);
    cout<<"ENTER STUDENT'S ID NUMBER : ";
    cin.ignore();
    cin.get(s.id,80);
    cout<<"ENTER STUDENT'S ROLL NUMBER :";
    cin>>s.roll;

    cout<<"ENTER STUDENT'S MARK IN SEASONALS :\n";
    cout<<"COMPUTER SCIENCE :";
    cin>>s.cs1;
    cout<<"PHYSICS :";
    cin>>s.phy1;
    cout<<"CHEMISTRY :";
    cin>>s.chem1;
    cout<<"MATHS :";
    cin>>s.math1;
    cout<<"ENGLISH :";
    cin>>s.eng1;

    cout<<"ENTER STUDENT'S MARK IN MID TERM :\n";
    cout<<"COMPUTER SCIENCE :";
    cin>>s.cs3;
    cout<<"PHYSICS :";
    cin>>s.phy3;
    cout<<"CHEMISTRY :";
    cin>>s.chem3;
    cout<<"MATHS :";
    cin>>s.math3;
    cout<<"ENGLISH :";
    cin>>s.eng3;

    cout<<"ENTER STUDENT'S MARK IN INTERNAL :\n";
    cout<<"COMPUTER SCIENCE :";
    cin>>s.cs2;
    cout<<"PHYSICS :";
    cin>>s.phy2;
    cout<<"CHEMISTRY :";
    cin>>s.chem2;
    cout<<"MATHS :";
    cin>>s.math2;
    cout<<"ENGLISH :";
    cin>>s.eng2;

    cout<<"ENTER STUDENT'S MARK IN END TERM :\n";
    cout<<"COMPUTER SCIENCE :";
    cin>>s.cs4;
    cout<<"PHYSICS :";
    cin>>s.phy4;
    cout<<"CHEMISTRY :";
    cin>>s.chem4;
    cout<<"MATHS :";
    cin>>s.math4;
    cout<<"ENGLISH :";
    cin>>s.eng4;

    s.sum1=s.cs1+s.phy1+s.chem1+s.math1+s.eng1;
    s.sum2=s.cs2+s.phy2+s.chem2+s.math2+s.eng2;
    s.sum3=s.cs3+s.phy3+s.chem3+s.math3+s.eng3;
    s.sum4=s.cs4+s.phy4+s.chem4+s.math4+s.eng4;

    s.average1=(s.sum1/4);
    s.average2=(s.sum2/4);
    s.average3=(s.sum3/4);
    s.average4=(s.sum4/4);

    s.totper=(s.sum1+s.sum2+s.sum3+s.sum4)*2/15;

    outfile.write(reinterpret_cast<char *> (&s), sizeof(student));
    outfile.close();
    cout<<endl;
    cout<<"\t\tTHE FILE IS SUCCESSFULLY SAVED"<<endl;
    cout<<endl;
    cout<<"press any key to continue...";
    cin.ignore();
    cin.get();
}

void intro()

{
    cout<<"\t\t\t============================================="<<endl;
    Sleep(500);
    cout<<"\t\t\tTHIS IS STUDENT REPORT CARD MANEGEMENT SYSTEM"<<endl;
    Sleep(500);
    cout<<"\t\t\t============================================="<<endl;
    Sleep(500);
}

void mainmenu()

{
    system("color c");
    char cc;
    cout<<"\t\t\t=================MAIN MENU================\n\n"<<endl;
    Sleep(300);
    cout<<"\t\t\t1. CREATE STUDENT REPORT CARD\n\n"<<endl;
     Sleep(300);
    cout<<"\t\t\t2. VIEW ALL STUDENTs REPORT CARD\n\n"<<endl;
     Sleep(300);
    cout<<"\t\t\t3. VIEW A SINGLE STUDENT REPORT CARD\n\n"<<endl;
     Sleep(300);
    cout<<"\t\t\t4. MODIFY REPORT CARD\n\n"<<endl;
     Sleep(300);
    cout<<"\t\t\t5. RESULT\n\n"<<endl;
     Sleep(300);
    cout<<"\t\t\t6. DELETE RECORD\n\n"<<endl;
     Sleep(300);
    cout<<"\t\t\t=============================="<<endl;
     Sleep(300);
    cout<<"\t\t\tENTER YOUR CHOICE...:) <1-6> :";
     Sleep(300);
    cin>>cc;
    cout<<endl;
    switch(cc)
    {
    case '1':
        {
            acceptdata();
            break;
        }
    case '2':
        {
            viewall();
            break;
        }
    case '3':
          {
              int n;
              cout<<"ENTER YOUR ROLL NUMBER :";
              cin>>n;
              view_Specific(n);
              break;
          }
    case '4':
        {
            int n;
            cout<<"ENTER YOUR ROLL NUMBER :";
            cin>>n;
            modify(n);
            break;
        }

    case '5':
        {
            int n;
            cout<<"ENTER YOUR ROLL NUMBER :";
            cin>>n;
            cout<<endl;
            result(n);
            break;
        }
    case '6':
        {
            int n;
            cout<<"ENTER YOUR ROLL NUMBER :";
            cin>>n;
            cout<<endl;
            deleterecord(n);
            break;
        }
    }
}

void viewall()

{
    system("cls");
    student s;
    ifstream infile;
    bool check=false;
    infile.open("Report.txt",ios::app|ios::binary);
    if(infile.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED.....press enter key...";
        cin.ignore();
        cin.get();
    }
     cout<<"\n\n";
     cout<<"\t\t\tALL STUDENTS REPORT CARDS"<<endl;
     cout<<"================================================================================"<<endl;
    while(infile.read(reinterpret_cast<char*>(&s),sizeof(student)))
    {
        cout<<"\t\t\t\tSTUDENT NAME :"<<s.name<<endl<<endl;
        cout<<"\t\t\t\tSTUDENT ID NUMBER :"<<s.id<<endl<<endl;
        cout<<"\t\t\t\tSTUDENT ROLL NUMBER :"<<s.roll<<endl<<endl;
        cout<<"SUBJECT\t\t    SEASONAL     MID--TERM      INTERNAL        FINAL"<<endl;
        cout<<"COMPUTER SCIENCE |   "<<s.cs1<<"|  30\t  "<<s.cs3<<"|  50\t "<<s.cs2<<"|  20  \t"<<s.cs4<<"|  50"<<endl;
        cout<<"PHYSICS          |   "<<s.phy1<<"|  30\t  "<<s.phy3<<"|  50\t "<<s.phy2<<"|  20  \t"<<s.phy4<<"|  50"<<endl;
        cout<<"CHEMISTRY        |   "<<s.chem1<<"|  30\t  "<<s.chem3<<"|  50\t "<<s.chem2<<"|  20  \t"<<s.chem4<<"|  50"<<endl;
        cout<<"MATHS            |   "<<s.math1<<"|  30\t  "<<s.math3<<"|  50\t "<<s.math2<<"|  20  \t"<<s.math4<<"|  50"<<endl;
        cout<<"ENGLISH          |   "<<s.eng1<<"|  30\t  "<<s.eng3<<"|  50\t "<<s.eng2<<"|  20  \t"<<s.eng4<<"|  50"<<endl<<endl;
        cout<<"TOTAL            |  "<<s.sum1<<"| 150\t "<<s.sum3<<"| 250\t "<<s.sum2<<"| 100\t"<<s.sum4<<"| 250"<<endl<<endl;
        cout<<"PERCENTAGE = "<<s.totper<<endl;
        if(s.totper<=40)
         cout<<"*****FAIL*****"<<endl;
        else
         cout<<"*****PASSED*****\n";
        cout<<"=================================================================================="<<endl;
        check=true;
    }
    infile.close();
    if(check==false)
    cout<<"\t\t\t\tNO RECORD FOUND..."<<endl<<endl;
    cout<<"press any key to continue....";
    cin.ignore();
    cin.get();
}

void view_Specific(int n)

{
    system("cls");
    student s;
    ifstream infile;
    infile.open("Report.txt",ios::app|ios::binary);
    if(infile.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED...";

        cin.ignore();
        cin.get();
    }
    bool equality=false;
    cout<<"\t\t==========VIEW A SINGLE STUDENT REPORT==========\n\n";
    while(infile.read(reinterpret_cast<char*>(&s),sizeof(student)))
    {
        if(s.roll==n)
        {
        cout<<"\t\tSTUDENT NAME :"<<s.name;
        cout<<"\t\tSTUDENT ID NUMBER :"<<s.id<<endl;
        cout<<"\t\tSTUDENT ROLL NUMBER :"<<s.roll<<endl<<endl;
        cout<<"SUBJECT\t\t    SEASONAL     MID--TERM      INTERNAL        FINAL"<<endl;
        cout<<"COMPUTER SCIENCE |   "<<s.cs1<<"|  30\t  "<<s.cs3<<"|  50\t "<<s.cs2<<"|  20  \t"<<s.cs4<<"|  50"<<endl;
        cout<<"PHYSICS          |   "<<s.phy1<<"|  30\t  "<<s.phy3<<"|  50\t "<<s.phy2<<"|  20  \t"<<s.phy4<<"|  50"<<endl;
        cout<<"CHEMISTRY        |   "<<s.chem1<<"|  30\t  "<<s.chem3<<"|  50\t "<<s.chem2<<"|  20  \t"<<s.chem4<<"|  50"<<endl;
        cout<<"MATHS            |   "<<s.math1<<"|  30\t  "<<s.math3<<"|  50\t "<<s.math2<<"|  20  \t"<<s.math4<<"|  50"<<endl;
        cout<<"ENGLISH          |   "<<s.eng1<<"|  30\t  "<<s.eng3<<"|  50\t "<<s.eng2<<"|  20  \t"<<s.eng4<<"|  50"<<endl<<endl;
        cout<<"TOTAL            |  "<<s.sum1<<"| 150\t "<<s.sum3<<"| 250\t "<<s.sum2<<"| 100\t"<<s.sum4<<"| 250"<<endl<<endl;
        cout<<"PERCENTAGE = "<<s.totper<<endl;
        if(s.totper<=40)
         cout<<"*****FAIL*****"<<endl;
        else
         cout<<"*****PASSED*****\n";
        cout<<"\t\t================================================"<<endl;
        equality=true;
        }
    }
        infile.close();
        if(equality==false)
            cout<<"\t\t\t\tRECORD NOT FOUND..."<<endl;
            cout<<endl;
            cout<<"press any key to continue...";
            cin.ignore();
            cin.get();
}

void result(int n)

{
    system("cls");
    student s;
    ifstream infile;
    infile.open("Report.txt",ios::app|ios::binary);
    if(infile.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED..."<<endl;
        cin.ignore();
        cin.get();
    }
    bool eq=false;
    cout<<"\t\t\t\t===========VIEW A SINGLE STUDENT RESULT==========\n\n";
    while(infile.read(reinterpret_cast<char*>(&s),sizeof(student)))
    {
        if(s.roll==n)
        {
        cout<<"\t\t\t\tSTUDENT NAME :"<<s.name<<endl<<endl;

        cout<<"SUBJECT\t\t    SEASONAL     MID--TERM      INTERNAL        FINAL"<<endl;
        cout<<"COMPUTER SCIENCE |   "<<s.cs1<<"|  30\t  "<<s.cs3<<"|  50\t "<<s.cs2<<"|  20  \t"<<s.cs4<<"|  50"<<endl;
        cout<<"PHYSICS          |   "<<s.phy1<<"|  30\t  "<<s.phy3<<"|  50\t "<<s.phy2<<"|  20  \t"<<s.phy4<<"|  50"<<endl;
        cout<<"CHEMISTRY        |   "<<s.chem1<<"|  30\t  "<<s.chem3<<"|  50\t "<<s.chem2<<"|  20  \t"<<s.chem4<<"|  50"<<endl;
        cout<<"MATHS            |   "<<s.math1<<"|  30\t  "<<s.math3<<"|  50\t "<<s.math2<<"|  20  \t"<<s.math4<<"|  50"<<endl;
        cout<<"ENGLISH          |   "<<s.eng1<<"|  30\t  "<<s.eng3<<"|  50\t "<<s.eng2<<"|  20  \t"<<s.eng4<<"|  50"<<endl<<endl;
        cout<<"TOTAL            |  "<<s.sum1<<"| 150\t "<<s.sum3<<"| 250\t "<<s.sum2<<"| 100\t"<<s.sum4<<"| 250"<<endl<<endl;
        cout<<"PERCENTAGE = "<<s.totper<<endl;
        if(s.totper<=40)
         cout<<"*****FAIL*****"<<endl;
        else
         cout<<"*****PASSED*****\n";
        cout<<"\t\t================================================"<<endl;
        eq=true;
        }
    }
        infile.close();
        if(eq==false)
            cout<<"\t\t\t\tRECORD NOT FOUND..."<<endl;
            cout<<endl;
            cout<<"press any key to continue...";
            cin.ignore();
            cin.get();
}

void modify(int n)

{
    system("cls");
    student s;
    fstream infile;
    infile.open("Report.txt",ios::binary|ios::in|ios::out);
    if(infile.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED..."<<endl;
        cin.ignore();
        cin.get();
    }
     bool checker=false;
     cout<<"\t\t\t\t==========MODIFY A REPORT CARD==========\n\n";
     while(!infile.eof() && checker==false)
     {
     infile.read(reinterpret_cast<char*>(&s),sizeof(student));
     {
         if(s.roll==n)
         {
        cout<<"\t\t\t\tSTUDENT NAME :"<<s.name<<endl<<endl;
        cout<<"\t\t\t\tSTUDENT ID NUMBER :"<<s.id<<endl<<endl;
        cout<<"\t\t\t\tSTUDENT ROLL NUMBER :"<<s.roll<<endl<<endl;
        cout<<"SUBJECT\t\t    SEASONAL     MID--TERM      INTERNAL        FINAL"<<endl;
        cout<<"COMPUTER SCIENCE |   "<<s.cs1<<"|  30\t  "<<s.cs3<<"|  50\t "<<s.cs2<<"|  20  \t"<<s.cs4<<"|  50"<<endl;
        cout<<"PHYSICS          |   "<<s.phy1<<"|  30\t  "<<s.phy3<<"|  50\t "<<s.phy2<<"|  20  \t"<<s.phy4<<"|  50"<<endl;
        cout<<"CHEMISTRY        |   "<<s.chem1<<"|  30\t  "<<s.chem3<<"|  50\t "<<s.chem2<<"|  20  \t"<<s.chem4<<"|  50"<<endl;
        cout<<"MATHS            |   "<<s.math1<<"|  30\t  "<<s.math3<<"|  50\t "<<s.math2<<"|  20  \t"<<s.math4<<"|  50"<<endl;
        cout<<"ENGLISH          |   "<<s.eng1<<"|  30\t  "<<s.eng3<<"|  50\t "<<s.eng2<<"|  20  \t"<<s.eng4<<"|  50"<<endl<<endl;
        cout<<"TOTAL            |  "<<s.sum1<<"| 150\t "<<s.sum3<<"| 250\t "<<s.sum2<<"| 100\t"<<s.sum4<<"| 250"<<endl<<endl;
        cout<<"PERCENTAGE = "<<s.totper<<endl;
        if(s.totper<=40)
         cout<<"*****FAIL*****"<<endl;
        else
         cout<<"*****PASSED*****\n";
        cout<<"\t\t================================================"<<endl;
        cout<<"\t\tENTER THE NEW INFORMATION"<<endl;
        cout<<"============================================="<<endl;
    cout<<"ENTER STUDENT'S FULL NAME :";
    cin.ignore();
    cin.getline(s.name,80);
    cout<<"ENTER STUDENT'S ID NUMBER : ";
    cin.ignore();
    cin.get(s.id,80);
    cout<<"ENTER STUDENT'S ROLL NUMBER :";
    cin>>s.roll;

cout<<"ENTER STUDENT'S MARK IN SEASONNAL :\n";
    cout<<"COMPUTER SCIENCE :";
    cin>>s.cs1;
    cout<<"PHYSICS :";
    cin>>s.phy1;
    cout<<"CHEMISTRY :";
    cin>>s.chem1;
    cout<<"MATHS :";
    cin>>s.math1;
    cout<<"ENGLISH :";
    cin>>s.eng1;

    cout<<"ENTER STUDENT'S MARK IN MID TERM :\n";
    cout<<"COMPUTER SCIENCE :";
    cin>>s.cs3;
    cout<<"PHYSICS :";
    cin>>s.phy3;
    cout<<"CHEMISTRY :";
    cin>>s.chem3;
    cout<<"MATHS :";
    cin>>s.math3;
    cout<<"ENGLISH :";
    cin>>s.eng3;

    cout<<"ENTER STUDENT'S MARK IN INNTERNAL :\n";
    cout<<"COMPUTER SCIENCE :";
    cin>>s.cs2;
    cout<<"PHYSICS :";
    cin>>s.phy2;
    cout<<"CHEMISTRY :";
    cin>>s.chem2;
    cout<<"MATHS :";
    cin>>s.math2;
    cout<<"ENGLISH :";
    cin>>s.eng2;

    cout<<"ENTER STUDENT'S MARK IN END TERM :\n";
    cout<<"COMPUTER SCIENCE :";
    cin>>s.cs4;
    cout<<"PHYSICS :";
    cin>>s.phy4;
    cout<<"CHEMISTRY :";
    cin>>s.chem4;
    cout<<"MATHS :";
    cin>>s.math4;
    cout<<"ENGLISH :";
    cin>>s.eng4;

    s.sum1=s.cs1+s.phy1+s.chem1+s.math1+s.eng1;
    s.sum2=s.cs2+s.phy2+s.chem2+s.math2+s.eng2;
    s.sum3=s.cs3+s.phy3+s.chem3+s.math3+s.eng3;
    s.sum4=s.cs4+s.phy4+s.chem4+s.math4+s.eng4;

    s.average1=(s.sum1/4);
    s.average2=(s.sum2/4);
    s.average3=(s.sum3/4);
    s.average4=(s.sum4/4);

    s.totper=(s.sum1+s.sum2+s.sum3+s.sum4)*2/15;

    int pos=(-1)*static_cast<int>(sizeof(student));
    infile.seekp(pos,ios::cur);
    infile.write(reinterpret_cast<char *> (&s), sizeof(student));
    cout<<endl;
    cout<<"\t\t\t\tTHE FILE IS SUCCESSFULLY updated"<<endl;
    checker=true;
         }
     }
     }
     infile.close();
         if(checker==false)
            cout<<"\t\t\t\tRECORD NOT FOUND"<<endl;
            cout<<endl;
            cout<<"press any key to continue...";
            cin.ignore();
            cin.get();
  }

  void deleterecord(int n)

  {
     system("cls");
     student s;
     ifstream infile;
     infile.open("Report.txt",ios::binary);
     if(!infile)
     {
         cout<<"THE FILE COULD NOT BE OPENED..."<<endl;
         cin.ignore();
         cin.get();
     }
     ofstream outfile;
     outfile.open("Record2.txt",ios::binary);
     infile.seekg(0,ios::beg);
     cout<<"\t\t\t\t===========DELETE A REPORT CARD==========\n\n";
     while(infile.read(reinterpret_cast<char*>(&s),sizeof(student)))
     {
         if(s.roll!=n)
         {
             outfile.write(reinterpret_cast<char*>(&s),sizeof(student));
         }
     }
     infile.close();
     outfile.close();
     remove("Report.txt");
     rename("Record2.txt","Report.txt");
     cout<<endl;
     cout<<"\t\t\t\tRECORD SUCCESSFULLY DELETED"<<endl;
     cout<<"press any key to continue...";
     cin.ignore();
     cin.get();
  }
