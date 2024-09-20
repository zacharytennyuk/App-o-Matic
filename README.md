# App-o-Matic
Welcome to App-o-Matic!

Features:

• App search out of a data set of 21,000+ apps

• Search is tailored by user-specified app preferences (price, rating, etc.)

• Merge sort and quick sort time comparison

• And more!

How to Use:

Download files and open in your IDE of choice.

Happy Apping!



Team Name: Group 22

Team Members: Zachary Tenn Yuk, Anna Chen, Jessica Leathe


Link to Video: https://youtu.be/oi8g_vjyf0g 



Problem: What problem are we trying to solve?

The problem we are trying to solve is the lack of options for users to search apps by in the Google Play Store. Our solution was to develop a specialized search engine for Google Play Store that allows users to search for apps based on specific criteria such as rating, category, minimum number of installs, price, and content rating.

Motivation: Why is this a problem?

This is a problem because current search capabilities in app stores often rely on basic keyword searches and categories, which might not provide users with the level of customization they desire when searching for apps. By creating a search engine that focuses on these specific criteria, users would be able to find apps that match their preferences more accurately and efficiently. This program would allow more users to find the apps they desire tailored to their specific preferences.
 
Features implemented

Users can choose to filter their app search by any combination of category, rating, content rating, minimum installs, and price. User selections are verified as valid. Invalid input is either addressed automatically or prompts the user to re-enter an input that is valid. App-o-Matic then assigns a score to each app based on a match to the user’s filter selection, with higher scores given to apps that match the user’s desired preferences. App-o-Matic then returns the top 10 apps with the highest scores after sorted by merge sort and also returns the top 10 apps with the highest scores after sorted by quick sort. The problem is solved when those data points are returned along with the time for each sort, showing the comparison of both merge and quick sort.

Description of data

The data set we used for our project is a collection of Google Play Store Apps. In our modified set, we took over 21,000 data points (different applications) from the two million entries of the original data set. As well, the different columns we kept are name (string), rating (double), category (string), minimum number of installs (int), price (double), and content rating (string). Since we have 21k+ data points, each with 6 different attributes, we have more than 100,000 tuples. Here, below, is the link to the public data set:
https://www.kaggle.com/datasets/gauthamp10/google-playstore-apps

Here is the data set after the data was cleaned to use for our project:

https://drive.google.com/file/d/1xBq9H7CSRu8OHmRcAZB2T4d6PAo0TWBy/view?usp=sharing

Tools/Languages/APIs/Libraries used

We used Replit to implement our project as it provides a real-time collaborative coding environment, where we could all work on the same code at the same time. We also used CLion so that we can test different things on our own, but then add back to Replit. The programming language we used for this project is C++. The headers we included are <cctype> that covers character handling functions, <chrono> that is the time library, <iostream> and <fstream> that define the input/output stream objects, <map> that covers map functions, <string> that covers string functions, <vector> that covers vector functions, and <iomanip> that covers parametric manipulators.

Algorithms implemented

Our project revolved around the usage of two main sorting algorithms: merge sort and quick sort. By implementing what we learned in class in addition to our knowledge of the sorting methods and our data structure, we curated the methods to organize and sort our database of apps based on certain criteria. In our code, we compared the time in milliseconds it took to perform merge sort on the data points with the time in milliseconds it took to perform quick sort on the data points. Our program illustrates the differences between merge sort and quick sort. Merge sort is a stable sort, meaning equivalent elements maintain their original order in relation to each other. Quick sort however, is an unstable sort, meaning that original relative order between equivalent values is not maintained, because the movement of elements is determined by a pivot. As a result, we can see that the top 10 apps for merge and quick sort are not always identical, as equivalent scores can exist within the list of apps since multiple apps could be equally desired by a user. However, both sorts always sort in ascending (or non-decreasing) order, allowing us to print apps with the highest score by accessing the last 10 elements in our vectors. Other algorithms that we implemented included functions to read data from our .csv file, to assign scores to apps based on user preferences, to copy the unsorted list so that we could implement merge sort and quick sort on an identical vector, and to print our top 10 apps based on each sort.

Additional Data Structures/Algorithms used

In our code, we have utilized various other data structures using the C++ STL. We have used ‘map’ to store the user’s filter choices, such as associating the different filters with the user’s decisions (‘Y’ or ‘N’). Another map holds each filter that is associated with a ‘Y’ with each specific filter choice from the user. We have also used ‘vectors’ in our implementation that store lists of app pointers and strings. The vector allApps is a vector of app pointers that stores all the loaded app data. The vector mergeList is a vector of app pointers that is used during merge sort. The vector quickList is a vector of app pointers that is used during quick sort.

Analysis

Any changes the group made after the proposal? The rationale behind the changes.

We went through multiple iterations of how we were going to implement this project. We flipped between comparing two algorithms and comparing two data structures. The original plan we thought of was to compare the time it takes between a depth-first search and breadth-first search within a Binary Search Tree to find a specific app. Another plan we had was to compare the performance of organizing our data with an adjacency list vs a minimum heap. However, we realized these were not the best data structures for the way our data set was formatted and what we wanted to do with it. Instead, we decided to compare the time of merge sort and quick sort, as it matched the context of our proposal problem the best and was the easiest for all of us to comprehend.

Big O worst case time complexity analysis of the major functions/features you implemented

void loadApps(fstream &file): O(n*f) where n is the number of lines in the file being read and f is the number of characters in the line when using functions find(), substr(), stoi(), and stod(). This function reads the file line by line, finding the substring of each line when it finds a comma, as the file was a .csv file. As substr() is used in each line, the time complexity of this function would be O(n*f).

void assignScores(map<string, string> &choices): O(n*c) where n is the number of apps and c is the number of filters the user chose. The function checks each choice in the map of chosen filters(O(c)), then for each app (n apps) it checks each choice again to calculate an app score. This is O(c + c*n), and c*n is the largest term so overall time complexity is O(n*c).

void copyLists(): O(n) where n is the number of apps in the appList. For each app, a pointer to the app is added to the list being sorted by merge sort and the list being sorted by quick sort.

void mergesort(): O(n log n) where n is the number of apps stored in our app list. This is because merge sort is a divide and conquer algorithm where it divides the vector into two halves, sorts each half, and then merges the two together. When it calls the mergesorting() function, the vector is divided into halves at each level of recursion, therefore the total number of levels in the recursion tree is log(n), n being the number of apps stored, giving it a Big O worst case time complexity of O(log n). As well, when mergesorting() calls on the merge() function, it has a Big O worst case time complexity of O(n), n being the number of apps stored, because it iterates through both vectors and merges the two together to make one. Then to get the total worst case Big-O time complexity, you would have to combine those separate time complexities giving you
O(n log n), where n is the number of apps stored in our app list.

void quicksort(): O(n2) where n is the number of apps stored in our app list. This is because quick sort is also a divide and conquer algorithm, however it choses a pivot element and moves all values less than it to the left and all values greater than it to the right. Then recursively the algorithm sorts the two subvectors. When it calls the quicksorting() function, it immediately calls on the partition() function. The partition function has a worst case big O time complexity of O(n), n being the number of apps stored, because in the worst case, each element needs to be compared with the pivot which can occur for every ‘n’ elements in the vector. The quicksorting() function also has a worst case big O time complexity of O(n), n being the number of apps stored, because it is recursively called for every ‘n’ elements in the vector. Then to get the total worst case Big-O time complexity, you would have to combine those separate time complexities giving you O(n2), where n is the number of apps stored in our app list.

void printMerge(): O(1) as this function prints only last 10 elements in our vector.


void printQuick():  O(1) as this function prints only last 10 elements in our vector.


Reflection


As a group, how was the overall experience for the project?
As a group, we all worked incredibly well together. There was an equal divide in the amount of work each one of us did and we were all there for one another when it came to solving any issues any one of us had. We communicated very well when it came to brainstorming ideas, planning to meet, scheduling time to work on our project, and keeping each other informed about what each of us were doing and what we got done. As well, everyone got their work done on time and always put in their best effort to get this task done.


Did you have any challenges? If so, describe.
One challenge we faced was correctly adapting typical merge and quick sort algorithms to fit our project’s needs. Most of the lecture information regarding these algorithms uses an array of integer values. Our project required us to sort App* variables composed of multiple variables. In order to overcome this, we designated a certain score to each App based on how well its variables matched user filter selection. Then, after working out how to compare each App within our algorithms, we could successfully conduct our sorting.


If you were to start once again as a group, any changes you would make to the project and/or workflow?
If we were to start once again as a group, some changes we would make would be to plan in advance what functions our program would include, as well as how we would implement our ideas before we start. We believe that if we had talked our plan out from beginning to end, we would have been more time efficient, with less unused work. 


References

Amanpreet Kapoor’s Lecture videos and slides 🙂

Previous labs we have completed ourselves

Project examples linked in assignment to understand video format

https://cplusplus.com/reference/
