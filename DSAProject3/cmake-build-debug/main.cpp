//Zachary Tenn Yuk, Anna Chen, Jessica Leathe
#include "App.h"
#include <cctype>
#include <chrono>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
using namespace std::chrono;
int main() {
    cout << "▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄ Welcome to App-o-matic! ▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄" << endl;
    cout << endl;
    cout << "Answer the following with a 'Y' for yes or an 'N' for no:" << endl;

    map<string, string> filters;
    filters["Category"];
    filters["Rating"];
    filters["Installs"];
    filters["Price"];
    filters["Content Rating"];

    string decision;

    //select filters to sort by
    for (auto i : filters) {
        cout << "Would you like to filter by " << i.first << "? ";

        cin >> decision;

        if (decision == "Y" || decision == "N") {
            filters[i.first] = decision;
        } else {
            cout << "Incorrect choice, automatic N" << endl;
            filters[i.first] = "N";
        }
    }

    cout << endl;

    map<string, string> choices;
    string extra;
    bool cont;

    string helper;
    getline(cin, helper);

    //select choices for filters
    for (auto j : filters) {
        if (j.second == "Y") {

            cont = false;

            while (!cont) {
                if (j.first == "Category") {
                    cout << "Pick one category:" << endl;

                    vector<string> categories = {"Tools",
                                                 "Productivity",
                                                 "Communication",
                                                 "Social",
                                                 "Libraries & Demo",
                                                 "Lifestyle",
                                                 "Food & Drink",
                                                 "Books & Reference",
                                                 "Racing",
                                                 "Maps & Navigation",
                                                 "Travel & Local",
                                                 "Medical",
                                                 "Puzzle",
                                                 "Entertainment",
                                                 "Arcade",
                                                 "Auto & Vehicles",
                                                 "Photography",
                                                 "Health & Fitness",
                                                 "Board",
                                                 "Music & Audio",
                                                 "Sports",
                                                 "Beauty",
                                                 "Business",
                                                 "News & Magazine",
                                                 "Casual",
                                                 "Art & Design",
                                                 "Education",
                                                 "Card",
                                                 "Finance",
                                                 "Weather",
                                                 "Trivia",
                                                 "Adventure",
                                                 "Strategy",
                                                 "Events",
                                                 "Word",
                                                 "Shopping"};

                    for (int i = 0; i < categories.size() - 1; i++) {
                        cout << categories[i] << ", ";
                        // make category list neater
                        if (i % 6 == 5)
                            cout << endl;
                    }

                    cout << categories[categories.size() - 1] << endl;

                    cout << "Choice: ";
                    bool final = false;

                    getline(cin, extra);

                    for (int j = 0; j < categories.size(); j++) {
                        if (extra == categories[j]) {
                            final = true;
                            break;
                        }
                    }

                    if (final == true) {
                        choices["Category"] = extra;
                        cont = true;
                    } else {
                        cout << "Incorrect choice" << endl;
                        cont = false;
                    }

                    cout << endl;
                }

                else if (j.first == "Rating") {
                    cout << "Choose the minimum rating you'd like between 0.0 - 5.0: ";

                    cin >> extra;
                    bool satisfied = false;

                    for (int i = 0; i < extra.length(); i++) {
                        if (isdigit(extra.at(i)) || (extra.at(i) == '.')) {
                            satisfied = true;
                        } else {
                            satisfied = false;
                            break;
                        }
                    }

                    if (satisfied == true) {
                        double rating = stod(extra);

                        if (rating >= 0.0 && rating <= 5.0) {
                            choices["Rating"] = extra;
                            cont = true;
                        } else {
                            cout << "Incorrect choice" << endl;
                            cont = false;
                        }
                    } else {
                        cout << "Incorrect choice" << endl;
                        cont = false;
                    }

                    cout << endl;
                }

                else if (j.first == "Installs") {
                    cout << "Enter the minimum number of app installs: ";

                    cin >> extra;
                    bool satisfied = false;

                    for (int i = 0; i < extra.length(); i++) {
                        if (isdigit(extra.at(i))) {
                            satisfied = true;
                        } else {
                            satisfied = false;
                            break;
                        }
                    }

                    if (satisfied == true) {
                        choices["Installs"] = extra;
                        cont = true;
                    } else {
                        cout << "Incorrect choice" << endl;
                        cont = false;
                    }

                    cout << endl;
                }

                else if (j.first == "Price") {
                    cout << "Enter a maximum price (if you want free, put 0.00): $";

                    cin >> extra;
                    bool satisfied = false;

                    for (int i = 0; i < extra.length(); i++) {
                        if (isdigit(extra.at(i)) || (extra.at(i) == '.')) {
                            satisfied = true;
                        } else {
                            satisfied = false;
                            break;
                        }
                    }

                    if (satisfied == true) {
                        choices["Price"] = extra;
                        cont = true;
                    } else {
                        cout << "Incorrect choice" << endl;
                        cont = false;
                    }

                    cout << endl;
                }

                else if (j.first == "Content Rating") {
                    cout << "Enter a number to select a content rating:" << endl;

                    vector<string> cR = {"Everyone", "Everyone 10+", "Teen",
                                         "Mature 17+"};

                    for (int i = 0; i < cR.size() - 1; i++) {
                        cout << i + 1 << ". " << cR[i] << ", ";
                    }
                    cout << "4. " << cR[cR.size() - 1] << endl;

                    cout << "Choice: ";

                    cin >> extra;
                    bool satisfied = false;

                    for (int i = 0; i < extra.length(); i++) {
                        if (isdigit(extra.at(i))) {
                            satisfied = true;
                        } else {
                            satisfied = false;
                            break;
                        }
                    }

                    if (satisfied == true) {
                        int rating = stod(extra);

                        if (rating > 0 && rating < 5) {
                            choices["Content Rating"] = cR[rating - 1];
                            cont = true;
                        } else {
                            cout << "Incorrect choice" << endl;
                            cont = false;
                        }
                    } else {
                        cout << "Incorrect choice" << endl;
                        cont = false;
                    }

                    cout << endl;
                }
            }
        }
    }

    AppList apps;
    fstream file("playstore.csv", ios::in);
    if (!file.is_open()) {
        cout << "Apps cannot be accessed!" << endl;
        return 0;
    }
    apps.loadApps(file);        // read data from csv
    apps.assignScores(choices); // calculating scores for each app
    apps.copyLists();           // creating two lists to sort by merge and quick

    cout << "▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄     Sorting Apps...     ▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄" << endl
         << endl;

    // tracking mergesort time
    auto initialTimeM = high_resolution_clock::now();
    apps.mergesort();
    auto finalTimeM = high_resolution_clock::now();
    auto mergeTime = duration_cast<milliseconds>(finalTimeM - initialTimeM);

    // tracking quicksort time
    auto initialTimeQ = high_resolution_clock::now();
    apps.quicksort();
    auto finalTimeQ = high_resolution_clock::now();
    auto quickTime = duration_cast<milliseconds>(finalTimeQ - initialTimeQ);

    // print merge sort results
    cout << "Using Merge Sort: " << endl;
    apps.printMerge();

    // print quick sort results
    cout << "Using Quick Sort: " << endl;
    apps.printQuick();

    cout << "Merge Sort Time: " << mergeTime.count() << " milliseconds" << endl;
    cout << "Quick Sort Time: " << quickTime.count() << " milliseconds" << endl
         << endl;

    cout << "▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄    Have a hAPPy day!    ▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄" << endl;
}