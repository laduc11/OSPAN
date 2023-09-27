#include "Inc\main.h"

int main()
{
#ifdef TIENG_VIET
    SetConsoleOutputCP(65001);
#endif
    /*--------------------------Hướng dẫn---------------------------------------*/
    display("Input/guide.txt");
    system("pause");
    /*--------------------------------------------------------------------------*/

    /*Đăng ký ID người tham gia*/
    const int ID = get_ID();
    fstream result;
    string file_name;

    file_name = "Output/participant/" + string(3 - to_string(ID).length(), '0') + to_string(ID) + ".txt";
    result.open(file_name, ios::trunc | ios::out);
    result << "ID: " << string(3 - to_string(ID).length(), '0') + to_string(ID) << "\n\n";
    result.close();

    file_name = "Output/vocab/vocab_" + string(3 - to_string(ID).length(), '0') + to_string(ID) + ".txt";
    result.open(file_name, ios::trunc | ios::out);
    result << "ID: " << string(3 - to_string(ID).length(), '0') + to_string(ID) << "\n\n";
    result.close();

    file_name = "Output/math/math_" + string(3 - to_string(ID).length(), '0') + to_string(ID) + ".txt";
    result.open(file_name, ios::trunc | ios::out);
    result << "ID: " << string(3 - to_string(ID).length(), '0') + to_string(ID) << "\n\n";
    result.close();
    /*--------------------------------------------------------------------------*/

    /*đảo thứ tự câu hỏi*/
    vector<int> idx_select = choose();
    /*--------------------------------------------------------------------------*/

    /*---------------------câu hỏi toán-----------------------------------------*/
    vector<pair<string, string>> source_equation = get_equation();
    /*--------------------------------------------------------------------------*/

    /*--------------------câu hỏi từ vựng---------------------------------------*/
    vector<string> source_vocab = get_vocab();
    /*--------------------------------------------------------------------------*/

    /*Khởi tạo menu của chương trình*/
    system("cls");
    display("Input/menu.txt");
    cout << "Lựa chọn của bạn là ";
    unsigned int selection = 0;
    cin >> selection;
    selection = (selection - 1) % 3 + 1;
    /*--------------------------------------------------------------------------*/

    /*Bắt đầu làm bài kiểm tra*/
    unsigned int correct = 0;
    unsigned int correct_word = 0;
    for (int i = 0; i < NUM_Q; i++)
    {
        switch (selection)
        {
        case 1:
            correct += math_test(source_equation, idx_select[i], ID);
            break;
        case 2:
            vocab_test(source_vocab, idx_select[i], ID);
            break;
        case 3:
            correct += math_test(source_equation, idx_select[i], ID);
            vocab_test(source_vocab, idx_select[i], ID);
        }
    }

    /*--------------------------------------------------------------------------*/

    /*Tạo file để người dùng nhập từ vựng*/
    if (selection != 1)
    {
        result.open("vocab_answer.txt", ios::out);
        result << "ID: " << string(3 - to_string(ID).length(), '0') + to_string(ID) << "\n\n";
        result.close();
        system("notepad vocab_answer.txt");
    }
    /*--------------------------------------------------------------------------*/

    /*Kiểm tra kết quả ghi nhớ từ vựng*/
    if (selection != 1)
    {
        file_name = "Output/vocab/vocab_" + string(3 - to_string(ID).length(), '0') + to_string(ID) + ".txt";
        correct_word = check_vocab("vocab_answer.txt", file_name);
    }
    /*--------------------------------------------------------------------------*/

    file_name = "Output/participant/" + string(3 - to_string(ID).length(), '0') + to_string(ID) + ".txt";

    /*In kết quả toán học ra màn hình*/
    if (selection != 2)
    {
        cout << "Kết quả bài kiểm tra toán học\n";
        cout << "Correct: " << correct << "/" << NUM_Q << '\n';
        result.open(file_name, ios::app);
        result << "Kết quả bài kiểm tra toán học\n"
               << "Correct: " << correct << "/" << NUM_Q << "\n\n";
        result.close();
    }
    /*--------------------------------------------------------------------------*/

    /*In kết quả ghi nhớ từ vựng ra màn hình*/
    if (selection != 1)
    {
        cout << "Kết quả bài kiểm tra ghi nhớ\n";
        cout << "Correct: " << correct_word << "/" << NUM_Q << '\n';
        result.open(file_name, ios::app);
        result << "Kết quả bài kiểm tra ghi nhớ\n"
               << "Correct: " << correct_word << "/" << NUM_Q << '\n';
        result.close();
    }
    /*--------------------------------------------------------------------------*/

    /*Tạo báo cáo tổng kết ở định dạng file csv*/
    file_name = "Output/summary_report.csv";
    if (ID == 0)
        create_report(file_name);
    update_report(file_name, to_string(ID), to_string(correct), to_string(correct_word));
    /*--------------------------------------------------------------------------*/

    /*Lời cảm ơn*/
    cout
        << "Cảm ơn đã tham gia khảo sát\n";
    /*--------------------------------------------------------------------------*/

    cout << "Press any key to finish . . .";
    getchar();
    getchar();
    return 0;
}