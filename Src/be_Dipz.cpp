#include "..\Inc\main.h"
/*
choose index
output: 20 vị trí trong bộ dữ liệu 100 câu hỏi
*/
vector<int> choose()
{
    vector<int> select, result;
    srand(time(0));
    fstream shuffle;
    shuffle.open("Input/shuffle.txt", ios::in);
    int idx;
    for (int i = 0; i < NUM_Q / 4; i++)
    {
        select.push_back(rand() % (TOTAL_Q / 4));
        select.push_back((rand() % (TOTAL_Q / 4)) + (TOTAL_Q / 4));
        select.push_back((rand() % (TOTAL_Q / 4)) + (TOTAL_Q / 4) * 2);
        select.push_back((rand() % (TOTAL_Q / 4)) + (TOTAL_Q / 4) * 3);
    }
    for (int i = 0; i < NUM_Q; i++)
    {
        shuffle >> idx;
        result.push_back(select[idx]);
    }
    shuffle.close();
    return result;
}
/*
initial math test
input:
    database of math
    chosen index
ouput:
    Correct or Wrong
*/
int math_test(vector<pair<string, string>> source, int i, int ID)
{
    int correct = 0;
    system("cls");
    string status;
    char answer;
    fstream result;
    string file_name = "Output/math/math_" + string(3 - to_string(ID).length(), '0') + to_string(ID) + ".txt";
    result.open(file_name, ios::app);

    cout << "Nếu biểu thức đúng gõ 't', nếu sai gõ 'f'\nSau đó bấm phím Enter\n\n\n";
    cout << source[i].first << endl;
    result << source[i].first << '\n';
    auto start = chrono::steady_clock::now();
    cin >> answer;
    auto end = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    if (elapsed_seconds.count() > DELAY_TIMER_M / 1000.0)
    {
        status = "OVERTIME";
    }
    else
    {
        if (answer == 't')
            status = "TRUE";
        else if (answer == 'f')
            status = "FALSE";
        else
            status = "SYNTAX ERROR";

        if (status == source[i].second)
            correct++;
    }
    if (status == "TRUE" || status == "FALSE")
        cout << source[i].second << endl;
    else
        cout << status << '\n';
    result << "Your answer: " << answer << '\n';
    result << "Solution: " << source[i].second << '\n';
    result << "Status: " << status << "\n\n";
    result.close();
    Sleep(DELAY_TIMER_S);

    return correct;
}

/*
vocabulary test
*/
void vocab_test(vector<string> source, int i, int ID)
{
    fstream result;
    string file_name = "Output/vocab/vocab_" + string(3 - to_string(ID).length(), '0') + to_string(ID) + ".txt";
    result.open(file_name, ios::app);
    result << source[i] << '\n';
    result.close();

    system("cls");
    cout << "\n\n\n\t" << source[i];
    Sleep(DELAY_TIMER_L);
    system("cls");
}

/*
get equation source
*/
vector<pair<string, string>> get_equation()
{
    vector<pair<string, string>> source;
    fstream source_equation;
    source_equation.open("Input/equation.txt", ios::in);
    while (!source_equation.eof())
    {
        string answer, equation;
        getline(source_equation, answer, '\t');
        getline(source_equation, equation, '\n');
        source.push_back(make_pair(equation, answer));
    }
    source_equation.close();
    return source;
}
/*
get vocabulary source
*/
vector<string> get_vocab()
{
    fstream vocab_source;
    vocab_source.open("Input/vocab.txt", ios::in);
    vector<string> source;
    while (!vocab_source.eof())
    {
        string temp;
        vocab_source >> temp;
        source.push_back(temp);
    }
    vocab_source.close();
    return source;
}
/*
get ID and update current state
*/
int get_ID()
{
    fstream current_state;
    current_state.open("Input/current_state.txt", ios::in);
    string temp;
    int ID;
    current_state >> temp >> ID;
    current_state.close();
    current_state.open("Input/current_state.txt", ios::out);
    temp = "ID:\t" + string(3 - to_string(ID + 1).length(), '0') + to_string(ID + 1);
    current_state << temp;
    current_state.close();
    return ID;
}
/*
display text file on the console window
*/
void display(string path)
{
    fstream file(path, ios::in);
    while (!file.eof())
    {
        string line = "";
        getline(file, line, '\n');
        cout << line << '\n';
    }
    file.close();
}
/*
check vocabulary answer
*/
int check_vocab(string path1, string path2)
{
    int correct = 0;
    string temp = "";
    vector<string> answer;
    fstream file(path1, ios::in);
    getline(file, temp);
    getline(file, temp);
    for (int i = 0; i < NUM_Q; i++)
    {
        getline(file, temp);
        answer.push_back(temp);
        temp = "";
    }
    file.close();

    file.open(path2, ios::in);
    getline(file, temp);
    getline(file, temp);
    for (int i = 0; i < NUM_Q; i++)
    {
        getline(file, temp);
        if (answer[i] == temp)
            correct++;
        temp = "";
    }
    file.close();
    return correct;
}
/*
create summary report
*/
void create_report(string file_name)
{
    fstream report;
    report.open(file_name, ios::out);
    report << "ID,Correct equation,Correct word,Total question\n";
    report.close();
}
/*
update new runner to report
*/
void update_report(string file_name, string ID, string correct_equation, string correct_word)
{
    fstream report;
    report.open(file_name, ios::app);
    report << ID + "," + correct_equation + "," + correct_word + "," + to_string(NUM_Q) + "\n";
    report.close();
}