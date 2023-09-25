#include "Inc\main.h"
#include "Src\be_Dipz.cpp"

int main()
{
#ifdef TIENG_VIET
    SetConsoleOutputCP(65001);
#endif
    /*--------------------------Hướng dẫn---------------------------------------*/
    cout << "Chào mừng tới với chương trình của Vịt ngoo\n";
    cout << "Vịt chỉ muốn nói là tớ yêu bé Dipz nhìu lém ó\n";
    system("pause");
    /*--------------------------------------------------------------------------*/

    /*Đăng ký ID người tham gia*/
    const int ID = get_ID();
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

    /*Bắt đầu làm bài kiểm tra*/
    int correct = 0;
    for (int i = 0; i < NUM_Q; i++)
    {
        correct += math_test(source_equation, idx_select[i], ID);
        vocab_test(source_vocab, idx_select[i], ID);
    }
    cout << "Correct: " << correct << "/" << NUM_Q << endl;
    /*--------------------------------------------------------------------------*/

    /*Lời cảm ơn*/
    cout << "Cảm ơn đã tham gia khảo sát\n";
    /*--------------------------------------------------------------------------*/
#ifdef DEBUG
    cout
        << "debug choose\n";
    for (int i = 0; i < 20; i++)
    {
        cout << select_equation[i] << " ";
    }
    cout << endl;
    // cout << source[0].first << " " << source[0].second << endl;
#endif

    /*Cập nhật lại ID cho người dùng kết tiếp*/
    /*--------------------------------------------------------------------------*/

    cout << "Press any key to finish . . .";
    getchar();
    return 0;
}