// helooo
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// ========================= PAYMENT CLASS ========================= 
class Payment
{
private:
    int totalAmount;
    bool paymentStatus;

    vector<string> paymentHistory;

public:
    // Constructor
    Payment()
    {
        totalAmount = 0;
        paymentStatus = false;
    }

    // ================= PROCESS PAYMENT =================
    void processPayment(int amount)
    {
        totalAmount = amount;

        cout << "\n========== PAYMENT PROCESS ==========\n";
        cout << "Total Amount : Rs. "
             << totalAmount << endl;

        paymentStatus = true;

        cout << "Payment Successful!\n";

        stringstream ss;

        ss << "Payment of Rs. "
           << totalAmount
           << " completed.";

        paymentHistory.push_back(ss.str());
    }

    // ================= GENERATE RECEIPT =================
    void generateReceipt()
    {
        cout << "\n========== PAYMENT RECEIPT ==========\n";

        if (paymentStatus)
        {
            cout << "Payment Received Successfully\n";

            cout << "Amount Paid : Rs. "
                 << totalAmount << endl;
        }
        else
        {
            cout << "No payment has been made yet.\n";
        }
    }

    // ================= REFUND =================
    void refund()
    {
        cout << "\n========== REFUND PROCESS ==========\n";

        if (paymentStatus)
        {
            cout << "Refund of Rs. "
                 << totalAmount
                 << " has been processed.\n";

            stringstream ss;

            ss << "Refund of Rs. "
               << totalAmount
               << " processed.";

            paymentHistory.push_back(ss.str());

            paymentStatus = false;
        }
        else
        {
            cout << "No payment available for refund.\n";
        }
    }

    // ================= VIEW HISTORY =================
    void viewHistory()
    {
        cout << "\n========== PAYMENT HISTORY ==========\n";

        if (paymentHistory.empty())
        {
            cout << "No payment history available.\n";
        }
        else
        {
            for (int i = 0; i < paymentHistory.size(); i++)
            {
                cout << i + 1 << ". "
                     << paymentHistory[i]
                     << endl;
            }
        }
    }
};

// ========================= MAIN FUNCTION =========================
int main()
{
    Payment payment;

    int choice;

    do
    {
        cout << "\n========== PAYMENT MANAGEMENT SYSTEM ==========\n";

        cout << "1. Process Payment\n";
        cout << "2. Generate Receipt\n";
        cout << "3. Refund Payment\n";
        cout << "4. View Payment History\n";
        cout << "5. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            payment.processPayment(15000);
            break;

        case 2:
            payment.generateReceipt();
            break;

        case 3:
            payment.refund();
            break;

        case 4:
            payment.viewHistory();
            break;

        case 5:
            cout << "\nProgram Ended.\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}
