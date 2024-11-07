#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
#include <random>    

using namespace std;

class QuizGame {
private:
    // declare our variables and data types
    vector<pair<string, string>> questions; 
    stack<string> answers; 
    int score = 0;
    int limit = 0;
    int items = 10;
    int number = 0;

public:
    QuizGame() {
       // adds questions into the queue
        questions.push_back({ "TRUE or FALSE\nA Queue is a type of data structure.", "TRUE" });
        questions.push_back({ "TRUE or FALSE\nQueue follows Last-In-First-Out (LIFO) principle.", "FALSE" });
        questions.push_back({ "TRUE or FALSE\nEnqueue and dequeue are basic Queue operations.", "TRUE" });
        questions.push_back({ "TRUE or FALSE\nA Queue can be implemented using an array.", "TRUE" });
        questions.push_back({ "TRUE or FALSE\nA linked list is always better than an array for Queue implementation.", "FALSE" });
        questions.push_back({ "TRUE or FALSE\nQueues are used in print queues.", "TRUE" });
        questions.push_back({ "TRUE or FALSE\nQueues are used in job scheduling.", "TRUE" });
        questions.push_back({ "TRUE or FALSE\nQueues have fixed size.", "FALSE" });
        questions.push_back({ "TRUE or FALSE\nA Queue can be used to implement a Stack.", "FALSE" });
        questions.push_back({ "TRUE or FALSE\nQueue operations are O(1) in a linked list implementation.", "TRUE" });
        questions.push_back({ "IDENTIFICATION\nWhat is the maximum number of children a node in a Binary Tree can have?", "2" });
        questions.push_back({ "IDENTIFICATION\nWhich traversal order visits the root node first?", "Preorder" });
        questions.push_back({ "IDENTIFICATION\nWhich traversal algorithm uses a queue data structure?", "Breadth-First Search" });
        questions.push_back({ "IDENTIFICATION\nWhich Binary Tree property ensures efficient searching?", "Height balance" });
        questions.push_back({ "IDENTIFICATION\nWhat is the order of removal in a Queue?", "First-In-First-Out" });
        questions.push_back({ "IDENTIFICATION\nWhich operation adds an element to the end of a Queue?", "Enqueue" });
        questions.push_back({ "IDENTIFICATION\nWhich operation removes an element from the front of a Queue?", "Dequeue" });
        questions.push_back({ "IDENTIFICATION\nWhich Queue type follows a priority-based ordering?", "Priority Queue" });
        questions.push_back({ "IDENTIFICATION\nWhat data structure is an array?", "List" });
        questions.push_back({ "IDENTIFICATION\nWhat type of array can hold multiple dimensions?", "Multi-dimensional" });
        questions.push_back({ "IDENTIFICATION\nWhat traversal visits nodes in ascending order?", "Inorder" });
        questions.push_back({ "IDENTIFICATION\nWhat is the top node of a binary search tree called?", "Root" });
        questions.push_back({ "IDENTIFICATION\nWhat traversal visits nodes in a post-order manner?", "Postorder" });
        questions.push_back({ "IDENTIFICATION\nWhat is the worst-case time complexity for a skewed BST?", "Linear" });
        questions.push_back({ "IDENTIFICATION\nWhat is the term for the child node on the left?", "Left" }); 
        questions.push_back({ "IDENTIFICATION\nWhat type of linked list allows traversal in one direction only?", "Singly" });
        questions.push_back({ "IDENTIFICATION\nWhat type of linked list allows traversal in both directions?", "Doubly" });
        questions.push_back({ "IDENTIFICATION\nWhat is the structure that holds data and a pointer to the next node?", "Node" });
        questions.push_back({ "IDENTIFICATION\nWhat do you call a linked list with no elements?", "Empty" });
        questions.push_back({ "IDENTIFICATION\nWhat do you call a linked list where nodes are stored in non-contiguous memory?", "Dynamic" });

    }

    void start() {
        // if the user wants to restart, it will go here
   
        cout << "                           *             *  ******  *       ******  ******  *     *  ******                 \n";
        cout << "                            *     *     *   *       *       *       *    *  * * * *  *                      \n";
        cout << "                             *   * *   *    ****    *       *       *    *  *  *  *  ****                   \n";
        cout << "                              * *   * *     *       *       *       *    *  *     *  *                      \n"; 
        cout << "                               *     *      ******  ******  ******  ******  *     *  ******                 \n \n\n";
        cout << "INSTRUCTIONS: \nYou will be asked a series of questions in random order. Type your answer and press Enter. \nPlease answer in Caps Lock if the question is TRUE or FALSE\n";

        cout << "If the question is Enumeration, please start the answer with capital letters ty and Goodluck!! :)\n\n";
        ops:
      
        system("pause");
        system("cls");
       
        // generates random number and shuffles all the questions and only pick 10, so that there will no be repeated questions
  
        random_device rd;
        mt19937 g(rd());
        shuffle(questions.begin(), questions.end(), g);

        // prompts the question and asks the user to answer
        for (const auto& current : questions) {
            number++;
            
            if (limit == 10) {
           
                break;
            }
            else {
                cout <<number<<"."<< current.first << endl;
                string answer;
                getline(cin, answer); 

                answers.push(answer); 
                
               
                if (answer == current.second) {
                    cout << "Correct!\n";
                    score++;
                    system("pause");
                    system("cls");
                }
                else {
                    
                    cout << "Wrong! The correct answer is: " << current.second << endl;
                    system("pause");
                    system("cls");
                }
                cout << endl;

            }
            limit++;
        }
       
        // display the result and displays all your answers
        if (limit == 10) {
            
            displayResults();
            limit = 0;
            number = 0;
            items = 10;
            score = 0;
        }
        
        system("pause");
         // asks the user if he'd like to restart
        system("cls");
     
    }
    // a function that displays the results
    void displayResults() {
        system("cls");
        cout << "\t\t\t\t\t\tGame Over! Your score: " << score << "/10" << endl;
        cout << "\t\t\t\t\t\t     Your answers were:\n";

     // display the answers you entered from 1 to 10
        while (!answers.empty()) {
           
            cout <<"\t\t\t\t\t\t"<<items<<"." << answers.top() << endl;
            answers.pop();
            items--;
        }
    }
};

int main() {
    // implement in the main function
    QuizGame game;
    bool ano = true;
here:

    while (ano) {
        game.start();
        char c;
        cout << "Restart?\n[1]Yes\n[2]No\n->";
        cin >> c;
        switch (c) {
        case '1':
            cin.ignore();
            system("cls");
            continue;
            break;
        case '2':
            cout << "Goodbye\n";
            ano = false;
            break;
        default:
            system("cls");
            cout << "Invalid input please try again\n";
            goto here;
            break;
        }
    }
   
    
    return 0;
}