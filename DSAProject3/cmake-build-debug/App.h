//Zachary Tenn Yuk, Anna Chen, Jessica Leathe
#pragma once
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class AppList {
private:
    struct App {
        string name, category, contentRating;
        double rating, price, score;
        int installs;

        App() {
            name = "";
            category = "";
            contentRating = "";

            rating = 0.0;
            price = 0.0;
            score = 0.0;
            installs = 0;
        };

        ~App(){};

        App(string cName, string cCategory, string cContentRating, double cRating,
            double cPrice, int cInstalls) {
            name = cName;
            category = cCategory;
            contentRating = cContentRating;

            rating = cRating;
            price = cPrice;
            installs = cInstalls;
        }
    };

    vector<App *> allApps;
    vector<App *> mergeList;
    vector<App *> quickList;

public:
    void loadApps(fstream &file) {
        if (file.is_open()) {
            string readLine;
            getline(file, readLine);
            int i = 0;
            while (getline(file, readLine)) {
                string split = ",";
                string name = readLine.substr(0, readLine.find(split));
                readLine = readLine.substr((readLine.find(split) + 1));
                string category = readLine.substr(0, readLine.find(split));
                readLine = readLine.substr((readLine.find(split) + 1));
                double rating = stod(readLine.substr(0, readLine.find(split)));
                readLine = readLine.substr((readLine.find(split) + 1));
                int installs = stoi(readLine.substr(0, readLine.find(split)));
                readLine = readLine.substr((readLine.find(split) + 1));
                double price = stod(readLine.substr(0, readLine.find(split)));
                readLine = readLine.substr((readLine.find(split) + 1));
                string contentRating = readLine.substr(0, readLine.find(split));
                readLine = readLine.substr((readLine.find(split) + 1));
                App *newApp =
                        new App(name, category, contentRating, rating, price, installs);
                allApps.push_back(newApp);
                i++;
            }
        }
        file.close();
    }

    void assignScores(map<string, string> &choices) {
        /*
       score+5 if category matches
       score+1 if content rating matches
       score+rating if rating matches - 0.0 < 5.0
       score++ if installs matches
       score++ if price matches
       score++ if price = free
       score /= maximum;
      */

        double maximum = 1.0;
        for (auto c : choices) {
            if (c.first == "Rating")
                maximum += 5;
            else if (c.first == "Category")
                maximum += 5;
            else
                maximum++;
        }

        for (auto apps : allApps) { // updates each app score
            double tempscore = 0.0;
            // we always check if the app is free (+1)
            for (auto c : choices) { // scores apps
                if (c.first == "Category" && c.second == apps->category)
                    tempscore += 5;
                else if (c.first == "Rating" && stod(c.second) <= apps->rating)
                    tempscore += apps->rating;
                else if (c.first == "Content Rating" && c.second == apps->contentRating)
                    tempscore++;
                else if (c.first == "Installs" && stoi(c.second) <= apps->installs)
                    tempscore++;
                else if (c.first == "Price") {
                    if (stod(c.second) <= apps->price)
                        tempscore++;
                    if (stod(c.second) == 0.00)
                        tempscore++;
                }
            }
            apps->score = tempscore / maximum;
        }
    }

    void copyLists() {
        for (int i = 0; i < allApps.size(); i++) {
            App *m = allApps[i];
            App *q = allApps[i];
            mergeList.push_back(m);
            quickList.push_back(q);
        }
    }

    void printMerge() {
        for (int i = 0; i < 10; i++) {
            cout << i + 1 << ". " << mergeList[mergeList.size() - 1 - i]->name
                 << " (Score: " << mergeList[mergeList.size() - 1 - i]->score << ")"
                 << endl;
        }
        cout << endl;
    }

    void printQuick() {
        for (int i = 0; i < 10; i++) {
            cout << i + 1 << ". " << quickList[quickList.size() - 1 - i]->name
                 << " (Score: " << quickList[quickList.size() - 1 - i]->score << ")"
                 << endl;
        }
        cout << endl;
    }

    void mergesort() { mergesorting(mergeList, 0, mergeList.size() - 1); }

    void mergesorting(vector<App *> &apps, int left, int right) {
        int mid = 0;
        if (left < right) {
            // m is the point where arr is div into 2 subs
            mid = left + (right - left) / 2;
            mergesorting(apps, left, mid);
            mergesorting(apps, mid + 1, right);
            // merge the sorted subarrays
            merge(apps, left, mid, right);
        }
    }

    void merge(vector<App *> &apps, int left, int mid, int right) {
        // create X  + arr[left..mid] & Y + arr[mid+1..right]
        int n1 = mid - left + 1;
        int n2 = right - mid;
        vector<App *> X(n1);
        vector<App *> Y(n2);

        for (int i = 0; i < n1; i++) {
            X[i] = apps[left + i];
        }
        for (int j = 0; j < n2; j++) {
            Y[j] = apps[mid + 1 + j];
        }

        // merge the arrays X and Y into arr
        int i, j, k;
        i = 0;
        j = 0;
        k = left;

        while (i < n1 && j < n2) {
            if (X[i]->score <= Y[j]->score) {
                apps[k] = X[i];
                i++;
            } else {
                apps[k] = Y[j];
                j++;
            }
            k++;
        }
        // when we run out of elem, append the remaining elements
        while (i < n1) {
            apps[k] = X[i];
            i++;
            k++;
        }
        while (j < n2) {
            apps[k] = Y[j];
            j++;
            k++;
        }
    }

    void quicksort() { quicksorting(quickList, 0, quickList.size() - 1); }

    void quicksorting(vector<App *> &apps, int low, int high) {
        if (low < high) {
            int pivot = partition(apps, low, high);
            quicksorting(apps, low, pivot - 1);
            quicksorting(apps, pivot + 1, high);
        }
    }

    int partition(vector<App *> &apps, int low, int high) {
        App *pivot = apps[low];
        int up = low;
        int down = high;

        while (up < down) {
            //select first element greater than pivot
            for (int i = up; i < high; i++) {
                if (apps[up]->score > pivot->score)
                    break;
                up++;
            }
            //select first element lesser than pivot
            for (int i = down; i > low; i--) {
                if (apps[down]->score < pivot->score)
                    break;
                down--;
            }
            if (up < down) {
                swap(apps[up], apps[down]);
            }
        }
        swap(apps[low], apps[down]);
        return down;
    }
};