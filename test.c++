#include <iostream>
#include <vector>
#include <string>
using namespace std;
// ========================= FACILITY CLASS =========================
class Facility
{
protected:
    vector<string> facilityNames;
    vector<int> facilityCharges;
public:
    Facility()
    {
        facilityNames.push_back("Gym Facility");
        facilityCharges.push_back(3000);

        facilityNames.push_back("Swimming Pool");
        facilityCharges.push_back(5000);

        facilityNames.push_back("Football Ground");
        facilityCharges.push_back(7000);

        facilityNames.push_back("Basketball Court");
        facilityCharges.push_back(4000);

        facilityNames.push_back("Cricket Ground");
        facilityCharges.push_back(10000);
    }
    void displayFacilities()
    {
        cout << "\n========== AVAILABLE FACILITIES ==========\n";
        for (int i = 0; i < facilityNames.size(); i++)
        {
            cout << i + 1 << ". " << facilityNames[i]
                 << "  | Charges: Rs. " << facilityCharges[i] << endl;
        }
    }
    void getFacilityInfo(int choice)
    {
        cout << "\n========== FACILITY INFORMATION ==========\n";
        if (choice == 1)
            cout << "Facility : Gym Facility\nIncludes : Trainers, Machines, Lockers\nCharges  : Rs. 3000\n";
        else if (choice == 2)
            cout << "Facility : Swimming Pool\nIncludes : Clean Pool, Coach, Changing Rooms\nCharges  : Rs. 5000\n";
        else if (choice == 3)
            cout << "Facility : Football Ground\nIncludes : Flood Lights, Seating Area\nCharges  : Rs. 7000\n";
        else if (choice == 4)
            cout << "Facility : Basketball Court\nIncludes : Indoor Court, Score Board\nCharges  : Rs. 4000\n";
        else if (choice == 5)
            cout << "Facility : Cricket Ground\nIncludes : Pavilion, Practice Nets\nCharges  : Rs. 10000\n";
    }
};
// ========================= ARENA CLASS =========================
class Arena : public Facility
{
private:
    string customerName;
    string selectedArena;
    vector<string> selectedFacilities;
    vector<int> selectedCharges;
    int arenaCharges;
public:
    Arena()
    {
        arenaCharges = 15000;
        selectedArena = "National Sports Arena";
    }
    void checkAvailability()
    {
        cout << "\n========== WEEKLY AVAILABILITY ==========\n";
        cout << "Monday    : Open\n";
        cout << "Tuesday   : Open\n";
        cout << "Wednesday : Closed\n";
        cout << "Thursday  : Open\n";
        cout << "Friday    : Maintenance\n";
        cout << "Saturday  : Open\n";
        cout << "Sunday    : Closed\n";
    }
    void scheduleMaintenance()
    {
        cout << "\n========== MAINTENANCE SCHEDULE ==========\n";
        cout << "5 May   : Swimming Pool Cleaning\n";
        cout << "12 May  : Basketball Court Repair\n";
        cout << "18 May  : Gym Equipment Checking\n";
        cout << "25 May  : Football Ground Grass Cutting\n";
    }
    void book()
    {
        int choice;
        char more;

        cin.ignore();
        cout << "\nEnter Customer Name: ";
        getline(cin, customerName);
        cout << "\nArena Selected: " << selectedArena << endl;
        cout << "Arena Charges : Rs. " << arenaCharges << endl;
        do
        {
            displayFacilities();
            cout << "\nSelect Facility Number: ";
            cin >> choice;
            if (choice < 1 || choice > 5)
            {
                cout << "Invalid choice!\n";
                continue;
            }
            getFacilityInfo(choice);
            selectedFacilities.push_back(facilityNames[choice - 1]);
            selectedCharges.push_back(facilityCharges[choice - 1]);
            cout << "\nDo you want to add another facility? (y/n): ";
            cin >> more;
        } while (more == 'y' || more == 'Y');
        cout << "\nBooking Successful!\n";
    }
    void cancelBooking()
    {
        int reasonChoice;
        cout << "\n========== BOOKING CANCELLATION ==========\n";
        cout << customerName << " had already booked the arena.\n";
        cout << "Now booking is being cancelled.\n";
        cout << "\nSelect Cancellation Reason:\n";
        cout << "1. Personal Reason\n";
        cout << "2. Budget Issue\n";
        cout << "3. Schedule Conflict\n";
        cout << "4. Health Problem\n";
        cout << "5. Other\n";
        cout << "\nEnter choice: ";
        cin >> reasonChoice;
        cout << "\nBooking Cancelled Successfully.\n";
    }
    void generateReport()
    {
        int facilityTotal = 0;
        cout << "\n========== FINAL REPORT ==========\n";
        cout << "Customer Name : " << customerName << endl;
        cout << "Arena Name    : " << selectedArena << endl;
        cout << "Arena Charges : Rs. " << arenaCharges << endl;
        cout << "\nFacilities Availed:\n";
        for (int i = 0; i < selectedFacilities.size(); i++)
        {
            cout << i + 1 << ". " << selectedFacilities[i]
                 << " | Charges: Rs. " << selectedCharges[i] << endl;
            facilityTotal += selectedCharges[i];
        }
        cout << "\nTotal Facility Charges : Rs. " << facilityTotal << endl;
        cout << "Arena Charges          : Rs. " << arenaCharges << endl;
        cout << "----------------------------------\n";
        cout << "Grand Total            : Rs. "
             << facilityTotal + arenaCharges << endl;
    }
};
// ========================= MAIN FUNCTION =========================
int main()
{
    Arena arena;
    int choice;
    do
    {
        cout << "\n========== SPORTS ACADEMY MANAGEMENT SYSTEM ==========\n";
        cout << "1. Book Arena\n";
        cout << "2. Cancel Booking\n";
        cout << "3. Check Availability\n";
        cout << "4. Schedule Maintenance\n";
        cout << "5. Display Facilities\n";
        cout << "6. Generate Report\n";
        cout << "7. Exit\n";
        cout << "\nEnter Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1: arena.book(); break;
        case 2: arena.cancelBooking(); break;
        case 3: arena.checkAvailability(); break;
        case 4: arena.scheduleMaintenance(); break;
        case 5: arena.displayFacilities(); break;
        case 6: arena.generateReport(); break;
        case 7: cout << "\nProgram Ended.\n"; break;
        default: cout << "\nInvalid Choice!\n";
        }
    } while (choice != 7);
    return 0;
}
