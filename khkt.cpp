#include "Inc\main.h"
#include "Src\be_Dipz.cpp"

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
    string file_name = "Output/participant/" + string(3 - to_string(ID).length(), '0') + to_string(ID) + ".txt";
    result.open(file_name, ios::trunc | ios::out);
    result << "ID: " << string(3 - to_string(ID).length(), '0') + to_string(ID) << "\n\n";
    result.close();
    file_name = "Output/log/result_" + string(3 - to_string(ID).length(), '0') + to_string(ID) + ".txt";
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
    int correct = 0;
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
    file_name = "Output/participant/" + string(3 - to_string(ID).length(), '0') + to_string(ID) + ".txt";
    result.open(file_name, ios::app);
    result << "\nResult: " << correct << "/" << NUM_Q << endl;
    result << "Correct: " << correct << "\tWrong: " << NUM_Q - correct << endl;
    result.close();
    /*--------------------------------------------------------------------------*/

    /*Tạo file để người dùng nhập từ vựng*/
    if (selection != 1)
    {
        result.open("vocab_answer.txt", ios::out);
        result << "ID: " << string(3 - to_string(ID).length(), '0') + to_string(ID) << "\n\n";
        result.close();
    }
    /*--------------------------------------------------------------------------*/

    /*In kết quả ra màn hình*/
    cout << "Correct: " << correct << "/" << NUM_Q << endl;
    /*--------------------------------------------------------------------------*/

    /*Lời cảm ơn*/
    cout << "Cảm ơn đã tham gia khảo sát\n";
    /*--------------------------------------------------------------------------*/

    cout << "Press any key to finish . . .";
    getchar();
    getchar();
    return 0;
}