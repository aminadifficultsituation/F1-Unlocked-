#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;

class Driver {
protected:
    string country;
    int races;
    string name;
    int wins;
    int podiums;
    string team;

public:
    Driver() {
        races = 0;
        name = "no name";
        wins = 0;
        podiums = 0;
        team = "none";
        country = "none";
    }

    void setDriver(string n, string c, string t, int r, int w, int p) {
        name = n;
        country = c;
        team = t;
        races = r;
        wins = w;
        podiums = p;
    }

    void display() const {
        cout << "\tDriver Career Stats:" << endl;
        cout << "Driver Name: " << name << endl;
        cout << "Country: " << country << endl;
        cout << "Team: " << team << endl;
        cout << "Races: " << races << endl;
        cout << "Wins: " << wins << endl;
        cout << "Podiums: " << podiums << endl;
    }
};

class CurrentSeason : public Driver {
public:
    void setDriver(int r, int w, int p) {
        races = r;
        wins = w;
        podiums = p;
    }

    void display() const {
        cout << "\n\tStats this season(2024):" << endl;
        cout << "Races: " << races << endl;
        cout << "Wins: " << wins << endl;
        cout << "Podiums: " << podiums << endl;
    }
};

class Schedule {
    string season;
public:
    Schedule(string s) {
        season = s;
    }

    void schedule_F1() const {
        cout << "\tF1 Race Schedule 2024:" << endl;
        cout << "Bahrain GP [March 2, 2024]" << endl;
        cout << "Saudi Arabian GP [March 9, 2024]" << endl;
        cout << "Australian GP [March 24, 2024]" << endl;
        cout << "Japanese GP [April 7, 2024]" << endl;
        cout << "Emilia Romagna GP [May 19, 2024]" << endl;
        cout << "Monaco GP [May 26, 2024]" << endl;
        cout << "Canadian GP [June 9, 2024]" << endl;
        cout << "Spanish GP [June 23, 2024]" << endl;
        cout << "British GP [July 7, 2024]" << endl;
        cout << "Hungarian GP [July 21, 2024]" << endl;
        cout << "Belgian Gp [July 28, 2024]" << endl;
        cout << "Dutch GP [August 25, 2024]" << endl;
        cout << "Italian GP [September 1, 2024]" << endl;
        cout << "Azerbaijan GP [September 15, 2024]" << endl;
        cout << "Singapore GP [September 22, 2024]" << endl;
        cout << "Mexico City GP [October 27, 2024]" << endl;
        cout << "Las Vegas GP [November 23, 2024]" << endl;
        cout << "Abu Dhabi GP [December 8, 2024]" << endl;
      
    }

    void schedule_sprintRaces() const {
        cout << "\tSprint Races 2024" << endl;
        cout << "China [April 20, 2024]" << endl;
        cout << "Miami [May 4, 2024]" << endl;
        cout << "Austria [June 29, 2024]" << endl;
        cout << "Austin [October 19, 2024]" << endl;
        cout << "Brazil [November 2, 2024]" << endl;
        cout << "Qatar [November 30, 2024]" << endl;
       
    }
};

class Quiz {
private:
    struct Question {
        string question;
        string options[3];
        char correctAnswer;
    };

    vector<Question> questions;

public:
    Quiz() {
        questions = {
            {"Who has won the most F1 World Championships?", {"a. Ayrton Senna", "b. Michael Schumacher", "c. Lewis Hamilton"}, 'b'},
             {"Which team has won the most constructors' championships?", {"a. Ferrari", "b. Mercedes", "c. McLaren"}, 'a'},
            {"What is the most iconic F1 circuit?", {"a. Silverstone", "b. Spa", "c. Monaco"}, 'c'},
            {"Who holds the record for most race wins?", {"a. Sebastian Vettel", "b. Lewis Hamilton", "c. Max Verstappen"}, 'b'},
            {"Which team dominated F1 in 2024?", {"a. McLaren", "b. Ferrari", "c. Red Bull"}, 'a'},
            {"Which F1 driver is nicknamed 'The Iceman'?", {"a. Kimi Räikkönen", "b. Nico Rosberg", "c. Mika Häkkinen"}, 'a'},
            {"What year was the first Formula 1 World Championship held?", {"a. 1946", "b. 1950", "c. 1954"}, 'b'},
            {"Which circuit is nicknamed 'The Temple of Speed'?", {"a. Monza", "b. Silverstone", "c. Suzuka"}, 'a'},
            {"Who is the youngest ever F1 World Champion?", {"a. Lewis Hamilton", "b. Max Verstappen", "c. Sebastian Vettel"}, 'c'},
            {"Which country hosts the Yas Marina Circuit?", {"a. Bahrain", "b. United Arab Emirates", "c. Qatar"}, 'b'}
            
        };
    }

    void game() {
        srand(time(0));
        vector<int> usedQuestions;
        char answer;

        cout << "\n\tWelcome to the F1 Quiz Challenge!" << endl;

        int correctAnswers = 0;

        for (int i = 0; i < 5; ++i) {
            int questionIndex;
            do {
                questionIndex = rand() % questions.size();
            } while (find(usedQuestions.begin(), usedQuestions.end(), questionIndex) != usedQuestions.end());

            usedQuestions.push_back(questionIndex);
            Question& q = questions[questionIndex];

            cout << "\nQ#" << (i + 1) << ") " << q.question << endl;
            for (int j = 0; j < 3; ++j) {
                cout << q.options[j] << endl;
            }

            bool answeredCorrectly = false;
            for (int attempt = 0; attempt < 2; ++attempt) {
                cout << "Your answer: ";
                cin >> answer;

                if (answer == q.correctAnswer) {
                    cout << "Correct!" << endl;
                    answeredCorrectly = true;
                    ++correctAnswers;
                    break;
                }
                else if (attempt == 0) {
                    cout << "Incorrect! Try again." << endl;
                }
                else {
                    cout << "Incorrect! Better luck next time." << endl;
                }
            }

            if (!answeredCorrectly) {
                break;
            }
        }

        if (correctAnswers == 5) {
            cout << "\t**CONGRATULATIONS**\nYou've won 2 tickets to the next F1 race! Check your email for details." << endl;
        }
        else {
            cout << "Quiz complete! You answered " << correctAnswers << " questions correctly. Better luck next time!" << endl;
        }
    }
};

class Blog {
private:
    string opinion;
public:
    Blog(string opp) {
        opinion = opp;
    }

    string getOpinion() {
        return opinion;
    }

    void display() const {
        cout << "\n\tYour Blog Post:" << endl;
        cout << opinion << endl;
    }

    void saveBlog() const {
        string fileName;
        cout << "Enter a name for your blog file (without extension): ";
        cin >> fileName;
        ofstream outFile(fileName + ".txt");
        if (outFile.is_open()) {
            outFile << opinion;
            outFile.close();
            cout << "Blog saved successfully as " << fileName << ".txt" << endl;
        }
        else {
            cout << "Failed to save the blog!" << endl;
        }
    }
};

void displayDriverList() {
    vector<string> drivers = {
        "Max Verstappen", "Lewis Hamilton", "Charles Leclerc", "Carlos Sainz",
        "Fernando Alonso", "Valtteri Bottas", "George Russell", "Esteban Ocon",
        "Pierre Gasly", "Lando Norris", "Lance Stroll", "Kevin Magnussen",
        "Sergio Perez", "Nico Hulkenberg", "Alexander Albon", "Yuki Tsunoda",
        "Zhou Guanyu", "Oscar Piastri", "Logan Sargeant", "Franco Colapinto",
        "Daniel Ricciardo", "Liam Lawson"
    };

    cout << "\nAvailable Drivers:" << endl;
    for (size_t i = 0; i < drivers.size(); i++) {
        cout << i + 1 << ". " << drivers[i] << endl;
    }
}

int main() {
    system("Color 0B");
    string name;
    char ch;
    char num = 0;
    Schedule S1("2024");
    Quiz q;

    cout << "\t Welcome to F1 Unlocked !" << endl << endl;

    do {
        cout << "\nWhat do you want to do? : " << endl;
        cout << "Enter 1 to check driver stats. \nEnter 2 to view schedule. \nEnter 3 to play quiz game. \nEnter 4 to write blog. " << endl;
        cin >> ch;

        if (ch == '1') {
            displayDriverList();
            int choice;
            cout << "\nEnter the number corresponding to the driver: ";
            cin >> choice;
            switch (choice) {
            case 1: {
                Driver D1;
                D1.setDriver("Max Verstappen", "Netherlands", "Red Bull Racing", 209, 63, 112);
                D1.display();
                CurrentSeason C1;
                C1.setDriver(24, 9, 14);
                C1.display();
                break;
            }
            case 2: {
                Driver D2;
                D2.setDriver("Lewis Hamilton", "United Kingdom", "Mercedes", 359, 105, 202);
                D2.display();
                CurrentSeason C2;
                C2.setDriver(24, 2, 5);
                C2.display();
                break;
            }
            case 3: {
                Driver D3;
                D3.setDriver("Charles Leclerc", "Monaco", "Ferrari", 149, 8, 43);
                D3.display();
                CurrentSeason C3;
                C3.setDriver(24, 3, 13);
                C3.display();
                break;
            }
            case 4: {
                Driver D4;
                D4.setDriver("Carlos Sainz", "Spain", "Ferrari", 208, 4, 27);
                D4.display();
                CurrentSeason C4;
                C4.setDriver(24, 2, 9);
                C4.display();
                break;
            }
            case 5: {
                Driver D5;
                D5.setDriver("Fernando Alonso", "Spain", "Aston Martin", 401, 32, 106);
                D5.display();
                CurrentSeason C5;
                C5.setDriver(24, 0, 0);
                C5.display();
                break;
            }
            case 6: {
                Driver D6;
                D6.setDriver("Valteri Bottas", "Finland", "Kick Sauber", 247, 10, 67);
                D6.display();
                CurrentSeason C6;
                C6.setDriver(24, 0, 6);
                C6.display();
                break;
            }
            case 7: {
                Driver D7;
                D7.setDriver("George Russell", "United Kingdom", "Mercedes", 128, 3, 15);
                D7.display();
                CurrentSeason C7;
                C7.setDriver(24, 2, 4);
                C7.display();
                break;
            }
            case 8: {
                Driver D8;
                D8.setDriver("Esteban Ocon", "France", "Alpine", 156, 1, 4);
                D8.display();
                CurrentSeason C8;
                C8.setDriver(24, 0, 1);
                C8.display();
                break;
            }
            case 9: {
                Driver D9;
                D9.setDriver("Pierre Gasly", "France", "Alpine", 154, 1, 5);
                D9.display();
                CurrentSeason C9;
                C9.setDriver(24, 0, 1);
                C9.display();
                break;
            }
            case 10: {
                Driver D10;
                D10.setDriver("Lando Norris", "United Kingdom", "Mclaren", 128, 4, 26);
                D10.display();
                CurrentSeason C10;
                C10.setDriver(24, 4, 13);
                C10.display();
                break;
            }
            case 11: {
                Driver D11;
                D11.setDriver("lance Stroll", "Canada", "Aston Martin", 169, 0, 3);
                D11.display();
                CurrentSeason C11;
                C11.setDriver(24, 0, 0);
                C11.display();
                break;
            }
            case 12: {
                Driver D12;
                D12.setDriver("Kevin Magnussen", "Denmark", "Haas", 173, 0, 1);
                D12.display();
                CurrentSeason C12;
                C12.setDriver(24, 0, 0);
                C12.display();
                break;
            }
            case 13: {
                Driver D13;
                D13.setDriver("Sergio Perez", "Mexico", "Red Bull", 285, 6, 39);
                D13.display();
                CurrentSeason C13;
                C13.setDriver(24, 0, 4);
                C13.display();
                break;
            }
            case 14: {
                Driver D14;
                D14.setDriver("Nico Hulkenberg", "Germany", "Haas", 320, 0, 0);
                D14.display();
                CurrentSeason C14;
                C14.setDriver(24, 0, 0);
                C14.display();
                break;
            }
            case 15: {
                Driver D15;
                D15.setDriver("Alex Albon", "Thailand", "Williams", 106, 0, 2);
                D15.display();
                CurrentSeason C15;
                C15.setDriver(24, 0, 0);
                C15.display();
                break;
            }
            case 16: {
                Driver D16;
                D16.setDriver("Yuki Tsunoda", "Japan", "RB", 90, 0, 0);
                D16.display();
                CurrentSeason C16;
                C16.setDriver(24, 0, 0);
                C16.display();
                break;
            }
            case 17: {
                Driver D17;
                D17.setDriver("Zhou Guanyu", "China", "Kick Sauber", 68, 0, 0);
                D17.display();
                CurrentSeason C17;
                C17.setDriver(24, 0, 0);
                C17.display();
                break;
            }
            case 18: {
                Driver D18;
                D18.setDriver("Oscar Piastri", "Australia", "Mclaren", 46, 2, 10);
                D18.display();
                CurrentSeason C18;
                C18.setDriver(24, 2, 8);
                C18.display();
                break;
            }
            case 19: {
                Driver D19;
                D19.setDriver("Logan Sargeant", "USA", "Williams", 41, 0, 0);
                D19.display();
                CurrentSeason C19;
                C19.setDriver(14, 0, 0);
                C19.display();
                break;
            }
            case 20: {
                Driver D20;
                D20.setDriver("Franco Colapinto", "Argentina", "Williams", 9, 0, 0);
                D20.display();
                CurrentSeason C20;
                C20.setDriver(9, 0, 0);
                C20.display();
                break;
            }
            case 21: {
                Driver D21;
                D21.setDriver("Daniel Ricciardo", "Australia", "RB", 258, 8, 32);
                D21.display();
                CurrentSeason C21;
                C21.setDriver(18, 0, 0);
                C21.display();
                break;
            }
            case 22: {
                Driver D22;
                D22.setDriver("George Russell", "United Kingdom", "Mercedes", 128, 3, 15);
                D22.display();
                CurrentSeason C22;
                C22.setDriver(24, 2, 4);
                C22.display();
                break;
            }
            case 23: {
                Driver D23;
                D23.setDriver("Liam Lawson", "New Zealand", "RB", 11, 0, 0);
                D23.display();
                CurrentSeason C23;
                C23.setDriver(6, 0, 0);
                C23.display();
                break;
            }
            default:
                cout << "Invalid choice!" << endl;
            }
        
        }
        else if (ch == '2') {
            int comp;
            cout << "\tF1 2024 Schedule" << endl;
            cout << "1. Main Races\n2. Sprint Races" << endl;
            cin >> comp;

            Schedule S2(S1);
            if (comp == 1) {
                S1.schedule_F1();
            }
            else if (comp == 2) {
                S2.schedule_sprintRaces();
            }
            else {
                cout << "Invalid! " << endl;
            }
        }
        else if (ch == '3') {
            q.game();
        }
        else if (ch == '4') {
            string opinion;
            cout << "\n\t   F1 FANZONE  " << endl << endl;
            cout << "Write your thoughts: ";
            cin.ignore();
            getline(cin, opinion);

            Blog blog(opinion);
            blog.display();

            char saveChoice;
            cout << "Do you want to save this blog? (y/n): ";
            cin >> saveChoice;

            if (saveChoice == 'y' || saveChoice == 'Y') {
                blog.saveBlog();
            }
            else {
                cout << "Blog not saved." << endl;
            }
        }
    } while (ch != '0');

    return 0;
}
