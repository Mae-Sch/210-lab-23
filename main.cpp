#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;
const string MENU =
"*** GOAT MANAGER 3001 ***\n
[1] Add a goat\n
[2] Delete a goat\n
[3] List goats\n
[4] Quit\n
Choice --> ";

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

int select_goat(list<Goat> trip) {
    int count = 1;
    int selection;
    for (Goat goat : trip) {
        cout << "[" << count << "] " << goat.get_name() << "(" << goat.get_age()
        << ", " << goat.get_color() << ")\n";
    }
    cout << "which goat would you like? ";
    cin >> selection;
    return selection;
}

void delete_goat(list<Goat> &trip) {

}

int main_menu() {
    cout << MENU;
    cin >> input;
    return input;
}

int main() {
    srand(time(0));
    bool again;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    list<Goat> Goats;

    int input = main_menu();
    while (input != 4) {
        switch(input) {
            case 1:
                add_goat(Goats, names, colors);
                break;
            case 2:
                delete_goat(Goats);
                break;
            case 3:
                display_trip(Goats);
                break;
            default:
                cout << "Invalid choice, try again\n";
        }
        input = main_menu();
    }
    cout << "Thank you for using Goat Manager 3001!\n";


    return 0;
}

