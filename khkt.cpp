#include "Inc/main.h"
#include "Src/be_Dipz.cpp"

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

    /*đảo thứ tự câu hỏi*/
    vector<int> idx_select = choose();
    /*--------------------------------------------------------------------------*/

    /*---------------------câu hỏi toán-----------------------------------------*/
    vector<pair<string, string>> source_equation = get_equation();
    /*--------------------------------------------------------------------------*/

    /*--------------------câu hỏi từ vựng---------------------------------------*/
    vector<string> source_vocab = get_vocab();
    /*--------------------------------------------------------------------------*/
#if 1
    /*Bắt đầu làm bài*/
    int correct = 0;
    for (int i = 0; i < NUM_Q; i++)
    {
        correct += math_test(source_equation, idx_select[i]);
        vocab_test(source_vocab, idx_select[i]);
    }
    cout << "Correct: " << correct << "/" << NUM_Q << endl;
    /*--------------------------------------------------------------------------*/
#endif

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

    /*--------------------câu hỏi từ vựng---------------------------------------*/
    /*--------------------------------------------------------------------------*/

    /*----------------------xuất đáp án từ vựng ra file text--------------------*/
    /*--------------------------------------------------------------------------*/
    cout << "Press any key to finish . . .";
    getchar();
    return 0;
}