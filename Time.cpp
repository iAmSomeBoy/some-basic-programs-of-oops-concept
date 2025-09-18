//seamless convertion between time24 and time12 using conversion operators
#include <iostream>
#include <string>
using namespace std;

/////////////////////////////////////////////////////////////
class time24;  // Forward declaration

class time12
{
private:
    bool pm;    //true = pm, false = am
    int hrs;    //1 to 12
    int mins;    //0 to 59
public:
    time12() : pm(true), hrs(0), mins(0) { }
    time12(bool ap, int h, int m) : pm(ap), hrs(h), mins(m) { }
    void display() const
    {
        cout << hrs << ':';
        if(mins < 10) cout << '0';
        cout << mins << ' ';
        cout << (pm ? "p.m." : "a.m.");
    }
    operator time24() const;  // Conversion to time24
};

class time24
{
private:
    int hours;    //0 to 23
    int minutes;    //0 to 59
    int seconds;    //0 to 59
public:
    time24() : hours(0), minutes(0), seconds(0) { }
    time24(int h, int m, int s) : hours(h), minutes(m), seconds(s) { }
    void display() const
    {
        if(hours < 10) cout << '0';
        cout << hours << ':';
        if(minutes < 10) cout << '0';
        cout << minutes << ':';
        if(seconds < 10) cout << '0';
        cout << seconds;
    }
    operator time12() const;    // Conversion to time12
};

// time12 to time24 conversion
time12::operator time24() const
{
    int hrs24 = hrs;
    if(pm && hrs != 12) {
        hrs24 += 12;
    } else if (!pm && hrs == 12) {
        hrs24 = 0;
    }
    return time24(hrs24, mins, 0);  // Seconds set to 0 in conversion
}

// time24 to time12 conversion
time24::operator time12() const
{
    int hrs24 = hours;
    bool pm = hours >= 12;    //find am/pm
    //round secs
    int roundMins = seconds < 30 ? minutes : minutes+1;
    if(roundMins == 60)    //carry mins?
    {
        roundMins=0;
        ++hrs24;
        if(hrs24 == 12 || hrs24 == 24)    //carry hrs?
            pm = !pm; //toggle am/pm
    }
    int hrs12 = (hrs24 < 13) ? hrs24 : hrs24-12;
    if(hrs12==0)    //00 is 12 a.m.
    { hrs12=12; pm=false; }
    return time12(pm, hrs12, roundMins);
}

/////////////////////////////////////////////////////////////
int main()
{
    while(true)
    {
        cout << "Choose conversion:\n";
        cout << "1. 24-hour to 12-hour\n";
        cout << "2. 12-hour to 24-hour\n";
        cout << "3. Exit\n";
        cout << "Choice: ";
        
        int choice;
        cin >> choice;
        
        if(choice == 1) {
            int h, m, s;
            cout << "Enter 24-hour time:\n";
            cout << " Hours (0-23): "; cin >> h;
            if(h < 0 || h > 23) break;
            cout << " Minutes: "; cin >> m;
            cout << " Seconds: "; cin >> s;
            
            time24 t24(h, m, s);
            cout << "24-hour time: ";
            t24.display();
            time12 t12 = t24;
            cout << "\n12-hour time: ";
            t12.display();
            cout << "\n\n";
        }
        else if(choice == 2) {
            int h, m;
            char ap;
            cout << "Enter 12-hour time:\n";
            cout << " Hours (1-12): "; cin >> h;
            if(h < 1 || h > 12) break;
            cout << " Minutes: "; cin >> m;
            cout << " AM or PM (a/p): "; cin >> ap;
            
            time12 t12(tolower(ap) == 'p', h, m);
            cout << "12-hour time: ";
            t12.display();
            time24 t24 = t12;
            cout << "\n24-hour time: ";
            t24.display();
            cout << "\n\n";
        }
        else {
            break;
        }
    }
    return 0;
}

