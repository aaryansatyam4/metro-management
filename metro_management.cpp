#include <fstream>
//  to create files and to write data to files.
#include <iostream>
// provides us with various functions to handle the input and output stream in c++. eg. cin
#include<iomanip>
// use to set field width

using namespace std;
class aqua
{
  string station[21]={
      "Noida Sector 51", "Noida Sector 50", "Noida Sector 76",
      "Noida Sector 101", "Noida Sector 81", "NSEZ",
      "Noida Sector 83", "Noida Sector 137", "Noida Sector 142",
      "Noida Sector 143", "Noida Sector 144", "Noida Sector 145",
      "Noida Sector 146", "Noida Sector 147", "Noida Sector 148",
      "Knowledge Park II", "Pari Chowk", "Alpha 1",
      "Delta 1", "GNIDA Office", "Depot"};
    // here we have fixed the distance between two stations as well as metro speed
  float distance[20]={1.0415, 1.0535, 1.0102, 1.1237, 0.9244, 1.976, 1.11494,
                     1.3517, 1.6480, 1.2215, 1.3522, 1.2313, 1.533, 1.042,
                     3.2935, 2.3284, 0.9218, 1.0859, 1.8558, 1.699};
  float time;

public:
  int a, b, c = 0, i, j;
  int sum;
  string A, B, C;
  void show_route()
  {

    for (i = 0; i < 21; i++)
    {
      cout << "station\t"<<setw(2) << i + 1 << "\t\t" << station[i] << endl;
    }
  }
  int x, y;
  string start, end;
  void get_data()
  {
    for (i = 0; i < 21; i++)
    {
      cout <<setw(2)<< i + 1 << " for " << station[i] << endl;
      // here setw() has set the field width using iomanip library
    }
    cout << "enter your starting station " << endl;

    cin >> x;
    cout << "enter your end station " << endl;
    cin >> y;
    // condition of getting right entry
    if(x>21 || x<1 ||y>21 ||y<1){
    
      cout<<"enter valid choice "<<endl ;
      get_data() ; 
      return ;
    }
    else{
    start = station[x - 1];
    end = station[y - 1];
    }
    }
  void time_taken()
  {
    int startIndex = min(x, y) - 1;
    int endIndex = max(x, y) - 1;

    float distance_travelled = 0;
    for (int i = startIndex; i < endIndex; i++)
    {
      distance_travelled += distance[i];
    }

    float speed = 100;
    float travel_time = distance_travelled * 60 / speed;

    float stop_time = 0.75 * abs(endIndex - startIndex);

    time = travel_time + stop_time;

    cout << "Time taken from " << start << " to " << end << " is " << time
         << " minutes" << endl;
  }

  void fare()
  {
    int rate;
    int startIndex = min(x, y) - 1;
    // min(x,y) will return the smaller value in a set of values .
    int endIndex = max(x, y) - 1;
// max(x,y) Returns the largest value in a set of values.
    int numStations = abs(endIndex - startIndex) + 1;
//  returns the absolute value of an integer number
    if (numStations == 1)
    {
      rate = 10;
    }
    else if (numStations == 2)
    {
      rate = 15;
    }
    else if (3 <= numStations && numStations <= 6)
    {
      rate = 20;
    }
    else if (7 <= numStations && numStations <= 9)
    {
      rate = 30;
    }
    else if (10 <= numStations && numStations <= 16)
    {
      rate = 40;
    }
    else if (17 <= numStations)
    {
      rate = 50;
    }
    cout << "Fare for  " << start << " to " << end << " is " << rate
         << " rupees" << endl;
  }
  void check_route()
  {
    int startIndex, endIndex;
    for (int i = 0; i < 21; i++)
    {
      if (station[i] == start)
      {
        startIndex = i;
      }
      if (station[i] == end)
      {
        endIndex = i;
      }
    }
    // here after alloting a value at startIOndex and stopIndex we 
      // comapre them in caseof their equality
    if (startIndex == endIndex)
    {
      cout << "You are already at the destination station" << endl;
      return;
    }
// here direction is given +1 or -1 to switch to that loop 
    int direction;
    if (startIndex < endIndex)
    {
      direction = 1;
    }
    else
    {
      direction = -1;
    }

    cout << "Route: " << endl;
    if (direction == 1)
    {
      for (i = startIndex; i < endIndex; i++)
      {
        cout << station[i] << " -> ";
      }
    }
    else
    {
      for (i = startIndex; i > endIndex; i--)
      {
        cout << station[i] << " -> ";
      }
    }
    cout << station[endIndex] << endl;
  }
};
class employ
{
  float present;
  string post;
  float attendance_percent;
  float basic_salary;
  float salary;
  float deductions;
  float final_salary;

public:
char p ;
int no_of_days;
  void getdata()
  {
    int ch;
   
    cout << "Enter the number of days present: ";
    cin>>present;
    // use of exception handling to make sure days input are valid
   try{
     if(present>days_in_month()){
       throw 1 ; 
     }
     else {
       throw p;
     }
   }
     catch(char){
    cout << "Enter the current post of the employee (1 for junior, 2 for "
            "senior): ";
    cin >> ch;
    switch (ch)
    {
    case 1:
    {
      post = "junior";
    }
    break;
    case 2:
    {
      post = "senior";
    }
    break;
    default:
      cout << "wrong choice employe";
    }
  }
   catch(int){
  cout<<"enter valid days in a month"<<endl ;
  getdata() ; 
  return ;
}
  }

  void calculate()
  {
    attendance_percent = (present/no_of_days ) * 100;

    if (post == "senior")
    {
      basic_salary = 45000;
    }
    else if (post == "junior")
    {
      basic_salary = 15000;
    }
    salary = basic_salary * attendance_percent / 100;

    deductions = 0;
    if (attendance_percent < 80)
    {
      deductions = salary * (0.1);
    }
    else if (attendance_percent < 90)
    {
      deductions = salary * (0.05);
    }

    final_salary = basic_salary - deductions;
  }
// a function to assign value of days in a month
int days_in_month(){
  string month_name;
 
  cout << "Enter three-letter month name (e.g. JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC): ";
  
  cin >> month_name;
  if(month_name == "JAN" || month_name == "MAR" || month_name == "MAY" || month_name == "JUL" || month_name == "AUG" || month_name == "OCT" || month_name == "DEC"){
    no_of_days = 31;
  } else if(month_name == "APR" || month_name == "JUN" || month_name == "SEP" || month_name == "NOV"){
    no_of_days = 30;
  } else if(month_name == "FEB"){
    no_of_days = 28;
  } else{
    cout << "Invalid month name entered" << endl;
    // return some value to indicate error, or throw an exception
  }
  return no_of_days;
}
  void show_performance()
  {
    cout << endl
         << "Attendance percentage: " << attendance_percent << "%" << endl;
    cout << "Basic salary: " << basic_salary << endl;
    cout << "Salary deducted: " << deductions << endl;
    cout << "Final salary: " << final_salary << endl;
  }
};

class login : public aqua, public employ
{
  string usn;
  int tm;

public:
  void valid(string str)
  {
    string dir, user;
    ifstream file;
    dir = str + ".txt";
    file.open(dir.c_str());
    if (!file.is_open() && file.fail())
    {
      // file.close();
      return;
    }
    else
    {
      tm++;
      if (tm == 3)
      {
        cout << "\nThis username already exists\nPlease try Again.";
        // file.close();
        return;
      }
      cout << "\nThis username already exists!\nCreate a username:";
      cin >> usn;
      // file.close();
      valid(usn);
    }
  }
  void start_program()
  {
    string usn1;
    string name2;

    int choice, i, exit = 0;
    string ans, password, name, fname, bio, usern, pw, line, nusn;
    ofstream fileo;
    ifstream filei;
    cout << "------------------------------Welcome to our "
            "system!---------------------------------------\n";
    while (exit == 0)
    {
      cout << "\nChoose one option:\n1. SignIn/LogIn(press 1 to select "
              "this) SignUp/Register(press 2 to select this)\n\npress any "
              "key and enter to exit\n";
      cin >> choice;
      system("clear");
      if (choice == 1)
      {
        cout << "Enter your username:";
        cin >> usn;
        cout << "\nEnter your password:";
        cin >> password;
        fname = usn + ".txt";
        filei.open(fname.c_str());
        if (!filei.is_open() && filei.fail())
        {
          cout << "\nYou are not registered, please register before logging "
                  "in.\n";
          filei.close();
          continue;
        }
        getline(filei, usern);
        getline(filei, line);
        getline(filei, pw);
        if (usn == usern && password == pw)
        {
          cout << "\nYou are successfully logged in:)\nYOUR PROFILE:\n";
          int z;
          cout << endl
               << "\t\t\t\t|\t\t\t\tNOIDA METRO \t\t\t\t" << endl
      
               << endl;
          int strt;
          cout << "enter" << endl
               << "1 to see program" << endl
               << "2 to see your data"<<endl;
          cin >> strt;
          system("clear");
          switch (strt)
          {
          case 1:
          {
            cout << "enter" << endl
                 << "1 for route" << endl
                 << "2 for time taken" << endl
                 << "3 for fare" << endl
                 << "4 to check route" << endl;
            cout << "your choice : ";
            cin >> z;
            system("clear");
            switch (z)
            {
            case 1:
              show_route();
              break;
            case 2:
              get_data();
              time_taken();
              break;
            case 3:
              get_data();
              fare();
              break;
            case 4:
              get_data();
              check_route();
              break;
            default:
              cout << "invalid options";
            }

            for (z = 1; z > 0; z++)
            {
              cout << "enter" << endl
                   << "1 for route" << endl
                   << "2 for time taken" << endl
                   << "3 for fare" << endl
                   << "4 to check route" << endl
                   << "5 to end program" << endl;
              cout << "your choice : ";
              cin >> z;
              system("clear");
              switch (z)
              {
              case 1:
                show_route();
                break;
              case 2:
                get_data();
                time_taken();
                break;
              case 3:
                get_data();
                fare();
                break;
              case 4:
                get_data();
                check_route();
                break;
              case 5:
              {
                cout << "Program ended :) ";
                return;
              }
              break;
              default:
                cout << "invalid options";
              }
            }
          }

          break;
          case 2:
          {
            employ::getdata();
            employ::calculate();
            ifstream name1(usn + ".txt");
            while (getline(name1,usn1) && getline(name1,name2))
            {
              if(usn == usn1)
              {
                 cout << "employ name : " << name2;
              }
            }
            name1.close();
            employ::show_performance();
          }
          }
        }
        else
        {
          cout << "\nWrong username or password!\nPlease try Again.\n";
        }
        cout << endl;
      }
      else if (choice == 2)
      {
        cout << "\nEnter your name:";
        cin.ignore();
        getline(cin, name);
        cout << "\nCreate a username:";
        cin >> usn;
        tm = 0;
        valid(usn);
        if (tm >= 3)
        {
          continue;
        }
        cout << "\nCreate a password:";
        cin >> password;
        fname = usn + ".txt";
        // cout<<fname;
        fileo.open(fname.c_str());
        fileo << usn << endl
              << name << endl
              << password << endl;
        cout << "\nYou are successfully registered:)";
        cout << "\nAdd to your bio and  enter when you are done:";
        cin.ignore();
        getline(cin, bio);
        fileo << bio << endl;
        cout << "\nYour bio is saved as: " << bio;
        fileo.close();
      }
      else
      {
        exit = 1;
      }
    }
  }
};

int main()
{
  login l;
  cout << "WELCOME TO SYSTEM" << endl
       << "press 1 for user" << endl
       << "press 2 for employ" << endl;
  int a;
  aqua A;
  cin >> a;
  system("clear");

  switch (a)
  {
  case 1:
  {
    cout << "\t\t\t\t NOIDA METRO \t\t\t\t" << endl
         << "\t\t\t\t" << endl
         << endl;
    cout << "enter" << endl
         << "1 for route" << endl
         << "2 for time taken" << endl
         << "3 for fare" << endl
         << "4 to check route" << endl;
    cout << "your choice : ";
    int z;
    cin >> z;
    system("clear");

    switch (z)
    {
    case 1:
      A.show_route();
      break;
    case 2:
      A.get_data();
      A.time_taken();
      break;
    case 3:
      A.get_data();
      A.fare();
      break;
    case 4:
      A.get_data();
      A.check_route();
      break;
    default:
      cout << "invalid options";
    }
  }
  break;
  case 2:
  {
    l.start_program();
  }
  break;
  default:
    cout << "wrong choice buddy retry";
  }
  int i;
  if (a == 1)
  {
    for (i = 1; i > 0; i++)
    {
      cout << "enter" << endl
           << "1 for route" << endl
           << "2 for time taken" << endl
           << "3 for fare" << endl
           << "4 to check route" << endl
           << "5 for end program" << endl;

      cout << "your choice : ";
      int x;
      cin >> x;

      switch (x)
      {
      case 1:
        A.show_route();
        break;
      case 2:
        A.get_data();
        A.time_taken();
        break;
      case 3:
        A.get_data();
        A.fare();
        break;
      case 4:
        A.get_data();
        A.check_route();
        break;
      case 5:
        cout << "end program :) ";
        return 0;
      default:
        cout << "invalid options";
      }
    }
  }
  else if (a == 2)
  {
    cout << "\t\t\t\t---------------------------------------------" << endl
         << "\t\t\t\t|\t\t\t\tNOIDA METRO \t\t\t\t|" << endl
         << "\t\t\t\t---------------------------------------------" << endl;
    l.start_program();
  }
}