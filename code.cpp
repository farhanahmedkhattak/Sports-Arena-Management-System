#include <iostream>
using namespace std;

// ---------------- EVENT CLASS ----------------

class Event
{
private:
    int eventID;
    string eventName;
    string date;
    string eventType;

public:

    // event schedule karne ke liye
    void scheduleEvent()
    {
        cout << "\nEnter Event ID: "; // event ID input karne ke liye
        cin >> eventID;

        cin.ignore();

        cout << "Enter Event Name: "; // event name input karne ke liye
        getline(cin, eventName);

        cout << "Enter Event Date: "; // event kis ko schedule karna hai uska date input karne ke liye
        getline(cin, date);

        cout << "Enter Event Type: "; // event type input karne ke liye (jaise ki football, basketball, etc.)
        getline(cin, eventType);

        cout << "\nEvent Scheduled Successfully!\n"; // event schedule hone ke baad success message print karne ke liye 
    }

    void cancelEvent()  // event cancel karne ke liye
    {
        cout << "\nEvent Cancelled.\n"; // agr event cancel karna hai to ye message print karne ke liye
    }

    void updateEvent()
    {
        cin.ignore(); 

        cout << "\nEnter New Event Name: "; // new event name input karne ke liye
        getline(cin, eventName);

        cout << "Enter New Date: "; // new date input karne ke liye
        getline(cin, date);

        cout << "\nEvent Updated Successfully!\n"; // event update hone ke baad success message print karne ke liye
    }

    void getDetails()
    {
        cout << "\n----- Event Details -----\n";

        cout << "Event ID: " << eventID << endl;
        cout << "Event Name: " << eventName << endl;
        cout << "Date: " << date << endl;
        cout << "Event Type: " << eventType << endl;
    }
};


// ---------------- TEAM CLASS ----------------

class Team // team create karne ke liye
{
private:
    int teamID;
    string teamName;
    string sport;
    int totalPlayers;

public:

    void createTeam()
    {
        cout << "\nEnter Team ID: ";
        cin >> teamID;

        cin.ignore();

        cout << "Enter Team Name: ";
        getline(cin, teamName);

        cout << "Enter Sport Name: ";
        getline(cin, sport);

        totalPlayers = 0;

        cout << "\nTeam Created Successfully!\n";
    }

    // player add karne ke liye
    void addPlayer()
    {
        totalPlayers++;

        cout << "\nPlayer Added Successfully!\n";
        cout << "Total Players: " << totalPlayers << endl;
    }

    void removePlayer()
    {
        if(totalPlayers > 0)
        {
            totalPlayers--;

            cout << "\nPlayer Removed Successfully!\n";
        }
        else
        {
            cout << "\nNo Players In Team.\n";
        }
    }

    void viewRoster()
    {
        cout << "\n----- Team Details -----\n";

        cout << "Team ID: " << teamID << endl;
        cout << "Team Name: " << teamName << endl;
        cout << "Sport: " << sport << endl;
        cout << "Total Players: " << totalPlayers << endl;
    }

    void participateInEvent()
    {
        cout << "\nTeam Registered In Event Successfully!\n";
    }
};


// ---------------- EQUIPMENT CLASS ----------------

class Equipment
{
private:
    int equipID;
    string equipName;
    string condition;
    int quantity;

public:

    void addEquipment()
    {
        cout << "\nEnter Equipment ID: ";
        cin >> equipID;

        cin.ignore();

        cout << "Enter Equipment Name: ";
        getline(cin, equipName);

        cout << "Enter Quantity: ";
        cin >> quantity;

        cin.ignore();

        cout << "Enter Condition: ";
        getline(cin, condition);

        cout << "\nEquipment Added Successfully!\n";
    }

    void removeEquipment()
    {
        int removeQty;

        cout << "\nEnter Quantity To Remove: ";
        cin >> removeQty;

        if(removeQty <= quantity)
        {
            quantity = quantity - removeQty;

            cout << "\nEquipment Removed Successfully!\n";
        }
        else
        {
            cout << "\nNot Enough Stock Available.\n";
        }
    }

    void checkStock()
    {
        cout << "\nCurrent Stock: " << quantity << endl;
    }

    void updateCondition()
    {
        cin.ignore();

        cout << "\nEnter New Condition: ";
        getline(cin, condition);

        cout << "\nCondition Updated Successfully!\n";
    }
};


// ---------------- MAIN FUNCTION ----------------

int main()
{
    Event e1;
    Team t1;
    Equipment eq1;

    int choice;

    do
    {
        cout << "\n========== SPORTS ARENA SYSTEM ==========\n";

        cout << "1. Schedule Event\n";
        cout << "2. View Event Details\n";
        cout << "3. Create Team\n";
        cout << "4. Add Player In Team\n";
        cout << "5. View Team Roster\n";
        cout << "6. Add Equipment\n";
        cout << "7. Check Equipment Stock\n";
        cout << "8. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                e1.scheduleEvent();
                break;

            case 2:
                e1.getDetails();
                break;

            case 3:
                t1.createTeam();
                break;

            case 4:
                t1.addPlayer();
                break;

            case 5:
                t1.viewRoster();
                break;

            case 6:
                eq1.addEquipment();
                break;

            case 7:
                eq1.checkStock();
                break;

            case 8:
                cout << "\nProgram Ended.\n";
                break;

            default:
                cout << "\nInvalid Choice.\n";
        }

    } while(choice != 8);

    return 0;
}