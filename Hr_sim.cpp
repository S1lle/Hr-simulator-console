#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>
#include <thread>
#include <locale.h>
#include <string>
#include <limits>

using namespace std;
using namespace std::chrono;


// змінні
bool cycle = true;
int character_choose = 0;
bool unlimited = false;
string username;
string character_list[] = { "( • ~ • )","( - - )", " ( @ - @ )", "( _ - _ )", "( ^ o ^ )", "( > _ < )", "( O _ o )", "( . _ . )", "( $ o $ )" };
string character = character_list[0] + "\n" + username + " - ";
string freaz = "(^. .^)\n Freaz - ";









// масиви

string names[50] = {
        "Andrew", "Brian", "William", "Gregory", "Dennis",
        "Eugene", "Justin", "Zachary", "Ivan", "Joseph",
        "Cyril", "Leo", "Maxim", "Nazar", "Oleg",
        "Paul", "Roman", "Sergey", "Taras", "Justin",
        "Theodore", "Christopher", "Caesar", "Chester", "Sean",
        "George", "Yaroslav", "Arsen", "Boris", "Vitaliy",
        "Dmitry", "Egor", "Zinovy", "Igor", "Constantine",
        "Luke", "Myroslav", "Nikita", "Ostap", "Peter",
        "Ruslan", "Svyatoslav", "Timothy", "Franz", "Chariton",
        "Edward", "Julian", "Jacob", "Anton", "Vladimir"
};
string surnames[50] = {
   "Smith", "Johnson", "Williams", "Brown", "Jones",
    "Garcia", "Miller", "Davis", "Rodriguez", "Martinez",
    "Hernandez", "Lopez", "Gonzalez", "Wilson", "Anderson",
    "Thomas", "Taylor", "Moore", "Jackson", "Martin",
    "Lee", "Perez", "Thompson", "White", "Harris",
    "Sanchez", "Clark", "Ramirez", "Lewis", "Robinson",
    "Walker", "Young", "Allen", "King", "Wright",
    "Scott", "Torres", "Nguyen", "Hill", "Flores",
    "Green", "Adams", "Nelson", "Baker", "Hall",
    "Rivera", "Campbell", "Mitchell", "Carter", "Roberts"
};




string vc_p_sen[5] = {
    "                     Senior Backend Developer (Java)\nOver 8 years of experience in developing high-load systems with Java and Spring. Designed and implemented a microservice architecture for an e-commerce platform serving millions of requests per day. Have deep knowledge of PostgreSQL, Kafka, and AWS. Mentored a team of 4 developers.",
    "                     Senior Frontend Developer (React)\n7 years in frontend development, expert in React, TypeScript, and Next.js. Led the UI/UX development for a SaaS product, achieving a 40% reduction in page load times through rendering optimization. Conduct technical interviews and develop company coding standards.",
    "                     Senior DevOps Engineer\n9 years of experience in infrastructure automation and support. Expert in Kubernetes, Terraform, and CI/CD with GitLab. Designed and migrated the company's infrastructure to AWS with almost zero downtime. I am engaged in optimizing cloud service costs.",
    "                     Senior Data Scientist (Python)\n6 years of experience in machine learning. Specialize in NLP and recommendation systems. Developed and implemented a content personalization model that increased user engagement by 25%. Proficient in TensorFlow, PyTorch, and MLOps tools.",
    "                     Senior iOS Developer (Swift)\nOver 7 years in mobile development for iOS. Lead developer on a project whose app has 5 million downloads in the App Store. Experienced with SwiftUI, Combine, and multi-module architecture. Responsible for technical decisions and code quality in the team." };
string vc_p_mid[5] = {
    "                     Middle Python Developer\n3 years of commercial experience with Django and Flask. Developed REST APIs for a logistics company, integrated third-party services. Confident with PostgreSQL, Redis, and Docker. Eager to deepen knowledge in asynchronous tasks with Celery.",
    "                     Middle Frontend Developer (Vue.js)\nOver 3 years of experience creating responsive interfaces with Vue.js (Vuex, Vue Router). Participated in refactoring a large monolithic frontend into a component-based architecture. Experienced with TypeScript and unit testing.",
    "                     Middle QA Automation Engineer\n2.5 years of experience in test automation. I write UI tests in Java + Selenium WebDriver and API tests using RestAssured. Configured test runs in CI/CD (Jenkins). I want to grow in the direction of load testing.",
    "                     Middle Android Developer (Kotlin)\n4 years in Android development. Worked on a retail application, implemented product catalog and shopping cart functionality. I use Coroutines, Dagger2, Retrofit, and adhere to Clean Architecture principles.",
    "                     Middle .NET Developer\n3 years of experience developing web applications on ASP.NET Core. Created microservices for the banking sector, worked with MS SQL and RabbitMQ. Familiar with Azure DevOps for setting up pipelines."
};
string vc_p_jun[5] = {
    "                     Junior Python Developer\nGraduate of a technical university with deep theoretical knowledge of Python. Developed several pet projects, including a Telegram bot and a simple web scraper. Familiar with Flask and SQL (SQLite). Highly motivated to learn and gain initial commercial experience.",
    "                     Junior Frontend Developer (React)\nCompleted 6-month Frontend courses. Proficient in HTML, CSS, JavaScript, and React. Created a portfolio of three projects, implementing routing, API interaction, and responsive design. Ready for test assignments.",
    "                     Junior QA Engineer (Manual)\nCompleted software testing courses. I understand the development life cycle, testing types, and can create clear test documentation (test cases, bug reports). I have some experience testing websites as part of educational projects.",
    "                     Junior Java Developer\nI have basic experience with Java Core and Spring Framework, gained during an internship. Participated in the development of an internal corporate portal. Familiar with Git, Maven, and the basics of working with databases. I aim to grow in backend development.",
    "                     Junior C++ Developer\nFinal-year student, passionate about C++. I have a good knowledge of STL and OOP principles. For my term paper, I developed a console game. Looking for a part-time job to combine work with studies and gain real experience." };



string questions[14] = {


    "What does 'good code' mean to you? Is it code that's easy to read, or code that runs as fast as possible?",
    "Is programming more of a craft, a science, or an art?",
    "Which programming principle (e.g., DRY, KISS, SOLID) do you consider the most important and why?",


    "What is more important for career growth: deep knowledge of one technology or broad knowledge in many?",
    "What non-technical skill (soft skill) is most valuable for a developer?",
    "How do you keep your knowledge current in the constantly changing world of technology?",


    "If you could permanently delete one programming language, which one would it be and why?",
    "Should a developer have a thorough understanding of how 'hardware' (processor, memory) works, or is it no longer relevant?",
    "What tool or technology has most changed your approach to work in the last year?",


    "What is more important for a project's success: strong individual developers or well-established team processes?",
    "How do you find a balance between development speed and code quality?",
    "Is code review a quality control tool or a tool for learning and knowledge sharing?",

    "Will artificial intelligence (like AI assistants) replace programmers in the future, or just change their role?",
    "Which technology trend (e.g., Web3, Quantum Computing, Edge AI) do you consider most overrated, and which is underrated?" };

string good_answers[14] = {
"Good code is, first and foremost, code that is easy to read, maintain, and change. Performance is just one characteristic of quality, and its importance depends on the context. For 95% of business tasks, readability is more valuable than micro-optimizations.",
"Programming is a unique blend of all three: science (algorithms, data structures), craft (practical skills, tool selection), and art (elegance of architecture, expressiveness of code).",
"I consider KISS (Keep It Simple, Stupid) the most important. If you strive for simplicity, you automatically avoid unnecessary code repetition (DRY) and create more understandable components. Complexity is the main enemy of a developer.",


"The best strategy is the T-shaped skills model: deep expertise in one main area and broad knowledge in related fields. This makes you both a valuable specialist and a flexible team player.",
"Communication. It's the ability to clearly explain complex ideas, listen actively, and give and receive constructive feedback. Without it, even brilliant code may not solve the right problem.",
"The key to success is a systematic approach: reading documentation, watching conference talks, practicing with pet projects, following thought leaders, and sharing knowledge with colleagues.",


"If I had to choose, perhaps PHP in its older versions (< 5.3). Not because of the language itself, but because its low entry barrier generated a huge amount of low-quality and insecure code.",
"It depends on the specialization, but a basic understanding is useful for everyone. For Embedded or GameDev developers, it's essential. For a web developer, it helps to write more efficient code.",
"AI coding assistants (like GitHub Copilot). They have fundamentally changed the approach to writing routine code, freeing up time to solve more complex architectural problems.",


"Well-established processes. A team of average developers with excellent processes will achieve more success than a team of 'rock stars' where everyone works chaotically.",
"It's a constant trade-off. The key is not to sacrifice fundamental quality (e.g., tests) for immediate gain, but to consciously manage technical debt for a quick launch.",
"It's both, but knowledge sharing is more important. Code review is the best tool for training juniors, spreading best practices, and maintaining high standards within the team.",

"AI will change the role of the programmer, not replace them. It will become a powerful tool that takes over routine tasks. The developer's role will shift from writing code to designing systems and setting the right tasks for AI.",
"Overrated (at the moment): Web3/Blockchain for most everyday tasks. Underrated: Automation platforms (Low-code/No-code), which free up professional developers for truly complex tasks."





};
string mid_answers[14] = {
    "Good code is code that works without errors and performs its function.",
    "It's a science because there are algorithms.",
    "DRY (Don't Repeat Yourself), because copy-pasting is bad.",

    "It's better to be an expert in one technology because such specialists are paid more.",
    "The ability to work in a team.",
    "I read news on specialized websites.",

    "JavaScript, because it has a weird type system.",
    "Only those who write drivers need it.",
    "The new version of my favorite IDE, because they added a nice theme.",

    "Strong developers, because they can write any code.",
    "You just need to write code faster, then the quality won't suffer.",
    "It's a tool for finding errors in colleagues' code.",

    "AI will write simple code, and programmers will write complex code.",
    "Blockchain is the future, it's just that not everyone understands it yet." };
string bad_answers[14] = {
    "My code. I wrote it, so it's good.",
    "It's just a set of commands for the computer.",
    "I don't think about principles, I just write code that works.",

    "You need to know a little bit of everything to get any job.",
    "They are not important, the main thing is to be able to code.",
    "I don't do anything, they'll teach me at work if needed.",

    "Assembler, because it's too complicated.",
    "Why? Computers are fast enough now.",
    "None. Tools are not important, the programmer is important.",

    "Me. If I work well, the project will be successful.",
    "Quality is not important, the main thing is to meet the deadline.",
    "It's a formality required by the manager. I just approve everything to not waste time.",

    "Programmers will soon be unnecessary, AI will do everything.",
    "It's all marketing, I just write code with proven technologies." };
string stars[5]{
    "*","**","***","****","*****" };


// функції
int get_integer_input() {
    int choice;
    while (!(cin >> choice)) {
        cout << "Please enter a valid number\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return choice;
}

void ps(const string& text, int delay_ms) {

    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delay_ms));
    }
}
void random_cv(string idk[5], vector<string>& cvs) {
    int vc = rand() % 5;
    string text = "";
    cvs.push_back(idk[vc]);
    text = idk[vc];
    ps(text + "\n", 10);
}
void dialog(const string& text, int delay_ms, string a) {
    cout << a << " ";
    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delay_ms));
    }
}
void random_ans(string ans[14], int a, string character) {

    dialog(ans[a], 20, character);
}
void rand_prog(string names[50], string surnames[50], vector<string>& d) {
    int a = rand() % 49 + 1, b = rand() % 49 + 1;
    d.push_back(names[a] + " " + surnames[b]);
    string name = "Name: " + names[a] + " " + surnames[b] + "\n";
    cout << name;
}
void raiting(string raiting[], vector<int>& star) {
    int a = rand() % 4 + 1;
    star.push_back(a);
    cout << "Raiting: " + stars[a];




}
void questions_f() {
    int b;
    cout << "Type question number to find the answers: ";
    cin >> b;
    cout << endl << "Good answer: " + good_answers[b - 1] << endl << endl;
    cout << "Recommended answer: " + mid_answers[b - 1] << endl << endl;
    cout << "Bad answer: " + bad_answers[b - 1] << endl << endl << endl;

}
void line() { cout << " |-------------------------------------------------------------------------------------------------------------|" << endl; }
void list_of_workers(vector<string>& a, vector<int>& b) {
    for (int i = 0; i < a.size() - 1; i++) {
        cout << to_string(i + 1) + ") " << a[i] + "; Raiting:" + to_string(b[i]) << endl;
    }
}


void menu() {

    int a;
    bool d = true;
    while (d) {

        line();
        cout << "            ██╗░░██╗██████╗░  ░██████╗██╗███╗░░░███╗██╗░░░██╗██╗░░░░░░█████╗░████████╗░█████╗░██████╗░" << endl;
        cout << "            ██║░░██║██╔══██╗  ██╔════╝██║████╗░████║██║░░░██║██║░░░░░██╔══██╗╚══██╔══╝██╔══██╗██╔══██╗" << endl;
        cout << "            ███████║██████╔╝  ╚█████╗░██║██╔████╔██║██║░░░██║██║░░░░░███████║░░░██║░░░██║░░██║██████╔╝" << endl;
        cout << "            ██╔══██║██╔══██╗  ░╚═══██╗██║██║╚██╔╝██║██║░░░██║██║░░░░░██╔══██║░░░██║░░░██║░░██║██╔══██╗" << endl;
        cout << "            ██║░░██║██║░░██║  ██████╔╝██║██║░╚═╝░██║╚██████╔╝███████╗██║░░██║░░░██║░░░╚█████╔╝██║░░██║" << endl;
        cout << "            ╚═╝░░╚═╝╚═╝░░╚═╝  ╚═════╝░╚═╝╚═╝░░░░░╚═╝░╚═════╝░╚══════╝╚═╝░░╚═╝░░░╚═╝░░░░╚════╝░╚═╝░░╚═╝" << endl;
        cout << "                                                 (Hr Simulator)" << endl;
        cout << endl << endl;
        cout << "                                                     Play(1)" << endl << endl;
        cout << "                                                     Info(2)" << endl << endl;
        cout << "                                                   Settings(3)" << endl << endl;
        cout << endl;
        cout << "Release 1.0" << endl;
        line();
        cout << "                                                          ";
        a = get_integer_input();
        line();
        switch (a) {
        case 1: {
            int b;
            system("cls");
            line();
            ps("Do you want unlimited game or story mode?\n", 10);
            cout << "1 - story mode\n";
            cout << "2 - unlimited mode\n";
            b = get_integer_input();
            if (b == 2) {
                unlimited = true;
            }
            else if (b == 1) { unlimited = false; }
            else{
                string f;
                ps("There is no game mode number " + to_string(b) + "\n", 10);
                cout << "(Press Enter to exit)";
                cin.ignore();
                getline(cin, f);
                system("cls");
                continue;
            }
            system("cls");
            cout << "                                     █░░ █▀█ ▄▀█ █▀▄ █ █▄░█ █▀▀" << endl;
            cout << "                                     █▄▄ █▄█ █▀█ █▄▀ █ █░▀█ █▄█" << endl;
            cout << "                                                 (Loading)        " << endl;
            line();
            ps("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||", 30);
            system("cls");
            d = false;
            break;
        }
        case 2: {
            
                system("cls");
                string f = "asd";
                cout << endl << "For all bugs, or questions please contact - @S1llek" << endl;
                cout << "All copirights 'Sillek dev'" << endl;
                cout << "Release 1.0" << endl << endl;
                cout << "(Press Enter to exit)";
                cin.ignore();
                getline(cin, f);
                if (f == "kzn" or f == "KZN") {
                    string a;
                    cout << endl << "Is that lonely man? - KZN";
                    getline(cin, a);
                    system("cls");
                    break;
                }

                if (f.empty()) {
                    system("cls");
                    break;
                }
                line();
                break;
            



            


        }
        case 3: {
            system("cls");
            cout << endl << "Terminal color(1)\nChoose character(2)" << endl << endl;
            string f;
            cout << "(Press Enter to exit)";
            cin.ignore();
            getline(cin, f);
            line();

            

            if (f.empty()) {
                system("cls");
                break;
            }
            else if (f == "1") {
                cout << "Write num from 1 to 99" << endl << "(1 - blue, 2 - green, 3 - light blue, 4 - red, 5 - purple)" << endl;
                int c;
                cin >> c;
                system((string("color ") + to_string(c)).c_str());
                system("cls");
                continue;
            }
            else if (f == "2") {
                cout << endl;
                for (int i = 0; i <= 8; i++) {
                    cout << to_string(i+1) + ") " << character_list[i] << endl << endl;
                }
                character_choose = get_integer_input();
                
                if (character_choose > 9 || character_choose < 0) { ps("There is no option - " + to_string(character_choose) + "\n", 10); cout << endl << "(Press Enter to exit)"; cin.ignore(); getline(cin, f);  break; }
                else { character = character_list[character_choose - 1] + "\n" + username + " - "; }
                
                system("cls");
                continue;
            }
            break;

        }
        }

    }
}
void game() {

    int a;


    dialog("Hello! Welcome to the Microloft team! Would you like to go through a short tutorial?\n", 10, freaz);
    cout << "1 - Yes\n2 - No" << endl;
    a = get_integer_input();
    switch (a) {
    case 1: {
        vector<string> hzlol;
        string skip;
        system("cls");
        dialog("Let's get to the tutorial!\n", 20, freaz);
        dialog("Let's start with an introduction!\n", 20, freaz);
        dialog("My name is Freaz, and I'll help you figure out how everything works here!\n", 20, freaz);
        dialog("And what's your name?\n\n", 20, freaz);

        cout << "Enter your name: ";
        cin.ignore();
        getline(cin, username);

        dialog(username + "... interesting name! Nice to meet you!\n\n", 20, freaz);
        cout << "(Press Enter to continue)";
        character = character_list[character_choose] + "\n" + username + " - ";
        getline(cin, skip);
        system("cls");
        dialog("Well, let's get to work!\n", 20, freaz);
        dialog("Different programmers will come to you who need to be tested!\n", 20, freaz);
        dialog("You will have 5 buttons!\n", 20, freaz);
        dialog("The 1st button 'CV' (resume), where you can view a short resume of the candidate!\n", 20, freaz);
        dialog("The 2nd button 'Talk', this button is responsible for checking the candidate, you can test their programming knowledge!\n", 30, freaz);
        dialog("The 3rd button 'Notepad', here are records with answers to questions as well as general information\n", 20, freaz);
        dialog("The 4th and 5th buttons are for rejecting or hiring a person!\n", 30, freaz);
        dialog("You also have a company budget that depends on which programmers you hire, for example:\n", 20, freaz);
        int c = rand() % 5, d = rand() % 5;
        vector<string> candidats;
        rand_prog(names, surnames, candidats);
        cout << "Professionalism " + stars[c] << "(" + to_string(c + 1) + ")" << endl << endl;;
        rand_prog(names, surnames, candidats);
        cout << "Professionalism " + stars[d] << "(" + to_string(d + 1) + ")" << endl << endl;
        int ch, rating;


        if (c > d) {
            dialog("As you can see, the 1st programmer has better professionalism than the 2nd, so you should choose them!\n\n", 20, freaz);
            while (true) {
                cout << "Choose a candidate (1 or 2):\n";
                cin >> ch;
                if (ch != 1) { dialog("Think again! There is a better candidate who will bring more money to the company!\n\n", 20, freaz); }
                else {
                    candidats.pop_back();
                    rating = c;
                    break;
                }

            }

        }
        else if (d > c) {
            dialog("As you can see, the 2nd programmer has better professionalism than the 1st, so you should choose them!\n\n", 20, freaz);
            while (true) {
                cout << "Choose a candidate (1 or 2):\n";
                cin >> ch;
                if (ch != 2) { dialog("Think again! There is a better candidate who will bring more money to the company!\n\n", 20, freaz); }
                else {
                    candidats.erase(candidats.begin());
                    rating = d;
                    break;
                }
            }
        }
        else if (d == c) {
            dialog("As you can see, the programmers are equally professional, so you need to choose based on other criteria!\n\n", 20, freaz);
            cout << "Choose a candidate (1 or 2):\n";
            cin >> ch;
            if (ch == 1) {
                candidats.pop_back();
                rating = c;
            }
            else {
                candidats.erase(candidats.begin());
                rating = d;
            }

        }
        cout << "\n(Press Enter to continue)";
        cin.ignore();
        getline(cin, skip);
        system("cls");
        dialog("Well.. you chose: " + candidats[0] + "\n", 20, freaz);
        dialog("His rating: " + stars[rating] + "\n", 20, freaz);
        switch (rating + 1) {
        case 1: {
            dialog("Honestly, his rating is terrible... But let's look at his resume! \n\n", 20, freaz); break;
        }
        case 2: { dialog("Bad, but it could be worse! Let's see what he wrote about himself!\n\n ", 20, freaz); break; }
        case 3: { dialog("Not a bad rating! The golden mean, as they say, let's see what's in his resume!\n\n ", 20, freaz); break; }
        case 4: { dialog("Wow!! Pretty good, who is he? Let's go read the resume! \n\n", 20, freaz);; break; }
        case 5: { dialog("DO YOU SEE THIS?? HIS RATING IS 5, LET'S GO SEE HIS RESUME!!!! \n\n", 20, freaz); ; break; }
        }
        ps("Info: Press 1 to view the resume\n\n", 20);
        while (true) {
            cout << "1 - CV     2 - Talk      3 - Notepad\n      4 - Accept      5 - Reject\n\n              ";
            cin >> ch;
            if (ch == 1) { break; }
            else { dialog("You can't use this function yet!\n\n", 20, freaz); }
        }
        switch (rating + 1) {
        case 1:
        case 2: {
            random_cv(vc_p_jun, hzlol); cout << endl;
            break;
        }
        case 3: {
            random_cv(vc_p_mid, hzlol); cout << endl;
            break;
        }
        case 4:
        case 5: {
            random_cv(vc_p_sen, hzlol); cout << endl;
            break;
        }
        }
        dialog("Great resume! And now let's ask some questions! \n\n", 20, freaz);
        string cand_name = "\n(- o -)\n" + candidats[0] + " - ";
        ps("Info: Press 2 to interview the candidate\n\n", 20);
        while (true) {
            cout << "1 - CV      2 - Talk      3 - Notepad\n      4 - Accept      5 - Reject\n\n              ";
            cin >> ch;
            if (ch == 2) { cout << "\n\n"; break; }
            else { dialog("You can't use this function yet!\n\n", 20, freaz); }
        }
        dialog("Great! Now choose a question!\n\n", 20, freaz);
        while (true) {
            cout << "Questions:\n";
            for (size_t i = 0; i < 14; i++) {
                cout << to_string(i + 1) + ") " << questions[i] + ";" << endl;
            }

            cout << "\nYour choice: ";
            cin >> ch;

            if (cin.fail() || ch < 1 || ch > 14) {
                cout << "\n(!!!) Error: please enter a number from 1 to 14.\n\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
        }
        bool good = false, mid = false, bad = false;
        dialog(questions[ch - 1] + "\n", 20, character);
        switch (rating + 1) {
        case 1: {
            int b = rand() % 10;
            if (b > 4) { dialog(bad_answers[ch - 1], 20, cand_name); bad = true; }
            else if (b < 4 && b != 1) { dialog(mid_answers[ch - 1], 20, cand_name); mid = true; }
            else if (b == 1) { dialog(good_answers[ch - 1], 20, cand_name); good = true; }break;
        }
        case 2: {
            int b = rand() % 10;
            if (b >= 4) { dialog(bad_answers[ch - 1], 20, cand_name); bad = true; }
            else if (b < 4 && b != 1) { dialog(mid_answers[ch - 1], 20, cand_name); mid = true; }
            else if (b == 1) { dialog(good_answers[ch - 1], 20, cand_name); good = true; } break;
        }
        case 3: {
            int b = rand() % 10;
            if (b >= 8) { dialog(bad_answers[ch - 1], 20, cand_name);  bad = true; }
            else if (b < 8 && b >= 3) { dialog(mid_answers[ch - 1], 20, cand_name); mid = true; }
            else if (b < 3) { dialog(good_answers[ch - 1], 20, cand_name); good = true; }break;
        }
        case 4: {
            int b = rand() % 10;
            if (b >= 9) { dialog(bad_answers[ch - 1], 20, cand_name);  bad = true; }
            else if (b < 9 && b >= 5) { dialog(mid_answers[ch - 1], 20, cand_name); mid = true; }
            else if (b < 5) { dialog(good_answers[ch - 1], 20, cand_name); good = true; }break;
        }
        case 5: {
            int b = rand() % 10;
            if (b >= 9) { dialog(bad_answers[ch - 1], 20, cand_name);  bad = true; }
            else if (b < 9 && b >= 7) { dialog(mid_answers[ch - 1], 20, cand_name); }
            else if (b < 7) { dialog(good_answers[ch - 1], 20, cand_name); good = true; }break;
        }
        }
        cout << endl;
        int chb;
        dialog("Now let's check notes!\n", 20, freaz);
        ps("Info: Press 3 to see notes!\n\n", 20);
        while (true) {
            cout << "1 - CV      2 - Talk      3 - Notepad\n      4 - Accept      5 - Reject\n\n              ";
            cin >> chb;
            if (chb == 3) {
                cout << "\n\n";
                while (true) {
                    int b;
                    dialog("Type '" + to_string(ch) + "' to find answers to this question\n", 20, freaz);
                    cout << "Type question number to find the answers: ";
                    cin >> b;
                    if (b == ch) {
                        cout << "Good answer: " + good_answers[ch - 1] << endl << endl;
                        cout << "Recommended answer: " + mid_answers[ch - 1] << endl << endl;
                        cout << "Bad answer: " + bad_answers[ch - 1] << endl << endl << endl;
                        break;
                    }
                    else {
                        dialog("We tring to find answer to another question!\n\n", 20, freaz);
                    }
                }

                break;
            }
            else { dialog("You can't use this function yet!\n\n", 20, freaz); }
        }
        if (bad) {
            dialog("Uh... I don't think he deserves to work here, so let's reject him and try to find better workers!\n\n", 20, freaz);
            while (true) {
                cout << "1 - CV      2 - Talk      3 - Notepad\n      4 - Accept      5 - Reject\n\n              ";
                cin >> chb;
                if (chb == 5) {
                    dialog("We'll call you later!\n\n", 20, character);
                    break;
                }
                else if (chb != 5) { dialog("We don't need such workers", 20, freaz); }


            }
        }
        else if (mid) {
            dialog("So.. it depends on your opinion! Choose whatever you want!\n\n", 20, freaz);
            while (true) {
                cout << "1 - CV      2 - Talk      3 - Notepad\n      4 - Accept      5 - Reject\n\n              ";
                cin >> chb;
                if (chb == 4) {
                    dialog("We are hiring you! You can start working!\n\n", 20, character);
                    break;
                }
                else if (chb == 2) { dialog("Sorry, but you're not a good fit for us!\n", 20, character); break; }
                else { dialog("You can't use this function yet!\n\n", 20, freaz); }
            }
        }
        else if (good) {
            dialog("He is so good! We need guys like this in our team!\n\n", 20, freaz);
            while (true) {
                cout << "1 - CV      2 - Talk      3 - Notepad\n      4 - Accept      5 - Reject\n\n              ";
                cin >> chb;
                if (chb == 4) {
                    dialog("We are hiring you! You can start working!\n\n", 20, character);
                    break;
                }
                else if (chb != 4) { dialog("We need him!\n", 20, freaz); }
            }

        }
        dialog("So we end tutorial! Good luck " + username + "! Also try to type 'kzn' in the info\n\n", 20, freaz);

        cout << "\n(Press Enter to continue)";
        cin.ignore();
        getline(cin, skip);



    }



    case 2: {
        if (username.empty()) {
            system("cls");
            dialog("Hello new worker! What's your name?\n\n", 20, freaz);
            cout << "Enter your name: ";
            getline(cin, username);
            


        }
        character = character_list[character_choose] + "\n" + username + " - ";
        string skip;
        string cand_character = "( - _ - )\n";
        dialog("Hello " + username + " it's your first working day!\n\n", 20, freaz);
        dialog("So let's start!\n\n", 20, freaz);
        cout << "\n(Press Enter to continue)";
        getline(cin, skip);
        system("cls");
        vector<string> name;
        vector<int> star;
        vector<string> vc;
        int days = 1;
        int candidates = 2;
        int ch, ch_i, budget = 500, workers = 0;
        bool end=true;

        while (true) {
            switch (days) {
            case 2: {
                dialog("A new workday has begun. Review today's applicants carefully—HR is counting on you", 20, freaz);
                cout << "\n(Press Enter to continue)";
                getline(cin, skip);
                break;
            }
            case 3: {
                dialog("The office is open. Time to sort files, check resumes, and make the tough calls.", 20, freaz);
                cout << "\n(Press Enter to continue)";
                getline(cin, skip);
                break;
            }
            case 4: {
                dialog("Don’t keep the candidates waiting. Your decisions shape the company’s future!", 20, freaz);
                cout << "\n(Press Enter to continue)";
                getline(cin, skip);
                break;
            }
            case 5: {
                dialog("Another busy day ahead. Stay sharp, follow protocol, and trust your instincts.", 20, freaz);
                cout << "\n(Press Enter to continue)";
                getline(cin, skip);
                break;
            }
            }


            if (budget != 0 && days <= 5) {

                bool good = false, mid = false, bad = false;
                cout << endl;
                
                for (int i = 0; i < candidates-1; i++) {
                    /*for (int d = 0; d < vc.size(); d++) {
                        if (vc[d].empty()) { cout << "There is no cvs"; break; }
                        cout << vc[d];
                    }*/
                    cout << "               |===================================================|" << endl;
                    cout << "                                     Day " + to_string(days);
                    cout << endl << "                              Company budget: " << budget << "$" << endl;
                    cout << "                              Candidates left: " << candidates - i - 1  << endl;
                    cout << "                                   Workers: " << workers << endl << endl;
                    cout << "               |===================================================|" << endl;
                    cout << endl;
                    cout << "                              ";
                    rand_prog(names, surnames, name);
                    cout << endl;
                    cout << "                              ";
                    raiting(stars, star);
                    cout << endl;
                    cout << endl;
                    int times = 0, times_t = 0, times_cv = 0;
                    while (end) {
                        cout << "\n     |=======================================================================|";
                        cout << endl;
                        cout << "\n          ________       __________        _____________        __________\n         | 1 - CV |     | 2 - Talk |      | 3 - Notepad |      | 6 - list |\n          --------       ----------        -------------        ----------\n\n                        ____________        ____________\n                       | 4 - Accept |      | 5 - Reject | \n                        ------------        ------------\n\n";
                        cout << "     |=======================================================================|" << endl << "                                       ";

                        ch = get_integer_input();





                        switch (ch) {
                        case 0: {
                            break;
                        }
                        case 1: {

                            if (times == 0) {
                                if (star[workers] <= 2) {
                                    random_cv(vc_p_jun, vc);
                                }
                                else if (star[workers] == 3) {
                                    random_cv(vc_p_mid, vc);
                                }
                                else {
                                    random_cv(vc_p_sen, vc);
                                }times += 1; times_cv += 1;
                            }
                            else { ps(vc[workers], 20); }
                            break;
                        }
                        case 2: {
                            cout << "Questions:\n";
                            for (size_t j = 0; j < 14; j++) {
                                cout << to_string(j + 1) + ") " << questions[j] + ";" << endl << endl;
                            }
                            cout << "Choose question:"; 
                            cin >> ch_i;
                            system("cls");
                            ps("Chosen question:" + to_string(ch_i)+"\n", 10);
                            

                            dialog(questions[ch_i - 1] + "\n", 20, character);
                            
                            switch (star[workers]) {
                            case 1: {
                                int b = rand() % 10;
                                if (b > 4) { dialog(bad_answers[ch_i - 1], 20, "\n" + cand_character + name[workers] + " - "); bad = true; }
                                else if (b < 4 && b != 1) { dialog(mid_answers[ch_i - 1], 20, "\n" + cand_character + name[workers] + " - "); mid = true; }
                                else if (b == 1) { dialog(good_answers[ch_i - 1], 20, "\n" + cand_character + name[workers] + " - "); good = true; }break;
                            }
                            case 2: {
                                int b = rand() % 10;
                                if (b >= 4) { dialog(bad_answers[ch_i - 1], 20, "\n" + cand_character + name[workers] + " - "); bad = true; }
                                else if (b < 4 && b != 1) { dialog(mid_answers[ch_i - 1], 20, "\n" + cand_character + name[workers] + " - "); mid = true; }
                                else if (b == 1) { dialog(good_answers[ch_i - 1], 20, "\n" + cand_character + name[workers] + " - "); good = true; } break;
                            }
                            case 3: {
                                int b = rand() % 10;
                                if (b >= 8) { dialog(bad_answers[ch_i - 1], 20, "\n" + cand_character + name[workers] + " - ");  bad = true; }
                                else if (b < 8 && b >= 3) { dialog(mid_answers[ch_i - 1], 20, "\n" + cand_character + name[workers] + " - "); mid = true; }
                                else if (b < 3) { dialog(good_answers[ch_i - 1], 20, "\n" + cand_character + name[workers] + " - "); good = true; }break;
                            }
                            case 4: {
                                int b = rand() % 10;
                                if (b >= 9) { dialog(bad_answers[ch_i - 1], 20, "\n" + cand_character + name[workers] + " - ");  bad = true; }
                                else if (b < 9 && b >= 5) { dialog(mid_answers[ch_i - 1], 20, "\n" + cand_character + name[workers] + " - "); mid = true; }
                                else if (b < 5) { dialog(good_answers[ch_i - 1], 20, "\n" + cand_character + name[workers] + " - "); good = true; }break;
                            }
                            case 5: {
                                int b = rand() % 10;
                                if (b >= 9) { dialog(bad_answers[ch_i - 1], 20, "\n" + cand_character + name[workers] + " - ");  bad = true; }
                                else if (b < 9 && b >= 7) { dialog(mid_answers[ch_i - 1], 20, "\n" + cand_character + name[workers] + " - "); }
                                else if (b < 7) { dialog(good_answers[ch_i - 1], 20, "\n" + cand_character + name[workers] + " - "); good = true; }break;
                            }
                                  break;


                            }
                            times_t += 1;
                            break;
                        }
                        case 3: { questions_f(); break; }
                        case 4: {
                            if (times_cv != 0 && times_t != 0) {
                                if (good && star[workers] >= 3) {
                                    budget *= 1.5;
                                }
                                else if (bad && star[workers] >= 3) {
                                    budget *= 0.9;
                                }
                                else if (mid && star[workers] >= 3) {
                                    budget *= 1.1;
                                }



                                if (good && star[workers] < 3) {
                                    budget *= 1.05;
                                }
                                else if (bad && star[workers] < 3) {
                                    budget *= 0.3;
                                }
                                else if (mid && star[workers] < 3) {
                                    budget *= 1.05;
                                }
                                workers += 1;
                                
                              
                                break;
                                
                            }
                           
                            else { ps("\nYou didn't watch candidates cv or talked with him!\n", 20); system("cls"); }
                            break;

                        }
                        case 5: {
                            if (times_cv != 0 && times_t != 0) {
                                if (good && star[workers] >= 3) {
                                    budget *= 0.4;
                                }

                                else if (bad && star[workers] >= 3) {
                                    budget *= 1.1;
                                }
                                else if (mid && star[workers] >= 3) {
                                    budget *= 0.9;
                                }



                                if (good && star[workers] < 3) {
                                    budget *= 1.1;
                                }
                                else if (bad && star[workers] < 3) {
                                    budget *= 0.4;
                                }
                                else if (mid && star[workers] < 3) {
                                    budget *= 0.9;
                                }


                                
                                star.pop_back();
                                name.pop_back();
                                vc.pop_back();
                                
                                
                                break;
                            }
                            else { ps("\nYou didn't watch candidates cv or talked with him!\n", 20); break; }}
                        
                    
                            
                            
                        case 6: {
                            if (workers != 0) {
                                list_of_workers(name, star); break;
                            }
                            else { ps("It's empty!", 20); }
                        }


                              break;



                        }


                              if (ch == 5 || ch == 4) {
                                  if (times_cv != 0 && times_t != 0) {
                                      system("cls"); times_t = 0; times_cv = 0; break;
                                  }
                                  else { continue; }
                              }
                              if (budget < 0) {
                                  system("cls");
                                  string l;
                                  ps("You lost... Microloft went bankrupt", 20); cout << endl;
                                  ps("It's all your fault, you know?", 20); cout << endl;
                                  ps("Try your best next time", 20); cout << endl;

                                  cout << endl << "(Press Enter to go to menu)\n";
                                  cin.ignore();
                                  getline(cin, l);
                                  system("cls");
                                  name.clear();
                                  star.clear();
                                  vc.clear();

                                  break;
                              }
                              
                        }                   

                        
                        
                        }
                        
                    }
                    candidates += 2;
                    days += 1;
                    if (days > 5 && unlimited == false) {
                        dialog("That was good week! You done well! Waiting for you!", 20, freaz);
                        cout << endl;
                        
                        break;
                    }
                   
                }



                name.clear();
                star.clear();
                vc.clear();
                ps("Sillek - Thank you for playing! I hope you enjoyed the game, have a great day!", 20);
                cout << endl;
                string b;
                cout << "Your stats: \nWorkers: " << workers << "\nBudget: " << budget << "\nRanking: ";
                if (budget >= 300 && budget < 500) { b = "C+"; }
                else if (budget >= 500 && budget < 1000) { b = "B+"; }
                else if (budget < 300) {
                    b = "F...";
                }
                else { b = "A+"; }
                cout << b << endl;
                ps("Sillek - Well done!", 20);
                cin.ignore();
                getline(cin, b);

                cout << endl << "(Press Enter to go to menu)\n";
                system("cls");

               
            }


        }


    }
    




int main()
{
    system("chcp 65001 > nul");
    setlocale(LC_ALL, "");
    srand(time(0));


    while (true) {
       menu();
        game();

    }

    return 0;
}
