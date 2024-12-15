#include <iostream>
using namespace std;

class Date {
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }

    void print() {
        cout << day << " " << month << " " << year;
    }

    int getDay() {
        return day;
    }

    int getMonth() {
        return month;
    }

    int getYear() {
        return year;
    }
};

class Subscriber {
    char name[50];
    long long mobileNumber;
    Date dateOfBirth;
    static int subscriberCount;

public:
    Subscriber(const char* n = "", long long number, int d = 1, int m = 1, int y = 2000) : mobileNumber(number), dateOfBirth(d, m, y) {
        strcpy_s(name, sizeof(name), n);
        subscriberCount++;
    }

    ~Subscriber() {
        subscriberCount--;
    }

    char* getName() {
        return name;
    }

    long long getMobileNumber() {
        return mobileNumber;
    }

    Date& getDateOfBirth() {
        return dateOfBirth;
    }

    static int getSubscriberCount() {
        return subscriberCount;
    }
};

int Subscriber::subscriberCount = 0;

class PhoneBook {
    Subscriber subscribers[100];
    int size;

public:
    PhoneBook() {
        size = 0;
    }

    void addSubscriber() {
        char name[50];
        long long number;
        int day, month, year;

        cout << "Enter name: ";
        cin.ignore();
        cin.getline(name, 50);

        cout << "Enter mobile number: ";
        cin >> number;

        cout << "Enter date of birth (day month year): ";
        cin >> day >> month >> year;

        subscribers[size] = Subscriber(name, number, day, month, year);
        size++;
        cout << "Subscriber added successfully.\n";
    }

    void deleteSubscriber() {
        char name[50];
        cout << "Enter name of subscriber to delete: ";
        cin.ignore();
        cin.getline(name, 50);

        int index = -1;
        for (int i = 0; i < size; ++i) {
            if (strcmp(subscribers[i].getName(), name) == 0) {
                index = i;
                break;
            }
        }

        for (int i = index; i < size - 1; ++i) {
            subscribers[i] = subscribers[i + 1];
        }

        size--;
        cout << "Subscriber deleted successfully.\n";
    }

    void searchSubscriber() {
        char name[50];
        cout << "Enter name of subscriber to search: ";
        cin.ignore();
        cin.getline(name, 50);

        for (int i = 0; i < size; ++i) {
            if (strcmp(subscribers[i].getName(), name) == 0) {
                cout << "Name: " << subscribers[i].getName();
                cout << ", Mobile: " << subscribers[i].getMobileNumber();
                cout << ", Birthday: " << subscribers[i].getDateOfBirth().getDay();
                cout << subscribers[i].getDateOfBirth().getMonth() << " ";
                cout << subscribers[i].getDateOfBirth().getYear() << " ";
                cout << endl;

            }
            else {
                cout << "Subscriber not found!\n";
            }
        }

    }

    void showAllSubscribers() {

        for (int i = 0; i < size; ++i) {
            cout << "Name: " << subscribers[i].getName();
            cout << ", Mobile: " << subscribers[i].getMobileNumber();
            cout << ", Birthday: " << subscribers[i].getDateOfBirth().getDay();
            cout << subscribers[i].getDateOfBirth().getMonth() << " ";
            cout << subscribers[i].getDateOfBirth().getYear() << " ";
            cout << endl;
        }
    }
};

int main() {
    PhoneBook phoneBook;
    int choice;

    do {
        cout << "\nPhone Book Menu:\n";
        cout << "1. Add Subscriber\n";
        cout << "2. Delete Subscriber\n";
        cout << "3. Search Subscriber\n";
        cout << "4. Show All Subscribers\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            phoneBook.addSubscriber();
            break;
        case 2:
            phoneBook.deleteSubscriber();
            break;
        case 3:
            phoneBook.searchSubscriber();
            break;
        case 4:
            phoneBook.showAllSubscribers();
            break;
        }

    } while (choice != 0);

    return 0;
}