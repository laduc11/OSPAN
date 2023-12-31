# Các chức năng của phần mềm:
1. Cung cấp 3 chế độ làm bài kiểm tra
2. Lưu lại lịch sử làm bài của người dùng
3. Cho phép người dùng nhập câu trả lời thông qua file text
4. Thông báo cho người dùng biết kết quả ngay sau khi làm xong
# Các tùy chỉnh dành cho người sở hữu phần mềm
1. Thay đổi thời gian làm bài của từng loại câu hỏi  
    Đối với câu hỏi toán học, truy cập đường dẫn <Inc\main.h> thay đổi giá trị của định nghĩa "#define DELAY_TIMER_M"  
    Đối với câu hỏi ghi nhớ, truy cập đường dẫn <Inc\main.h> thay đổi giá trị của định nghĩa "#define DELAY_TIMER_L"  
    Đơn vị là mili giây (msec), 1ms = 1000s
2. Thay đổi thời gian hiển thị đáp án của câu hỏi toán học  
    Truy cập đường dẫn <Inc\main.h> thay đổi giá trị của định nghĩa "#define DELAY_TIMER_S"  
    Đơn vị là mili giây (msec), 1ms = 1000s  
3. Thay đổi tổng số lượng câu hỏi  
    Truy cập đường dẫn <Inc\main.h> thay đổi giá trị của định nghĩa "#define NUM_Q"  
    LƯU Ý: ĐỂ TRÁNH LỖI XẢY RA KHI THỰC THI, TỔNG SỐ CÂU HỎI PHẢI LÀ BỘI CỦA 4  
4. Thay đổi ngân hàng câu hỏi  
    4.1. Câu hỏi toán học  
        Truy cập đường dẫn <Input\source_equation.xlsx>  
        Thực hiện các thay đổi nhỏ (VD: thêm bớt ký tự vào các ô trống) để bộ dữ liệu cập nhật  
        Sao chép 2 cột dữ liệu trong <Sheet2> và dán, thay thế toàn bộ dữ liệu trong file <equation.txt> ở cùng thư mục  
    4.2. Câu hỏi ghi nhớ từ vựng  
        Truy cập vào đường dẫn <Input\vocab.txt>  
        Thay đổi các từ vựng hiện có trong file sao cho tổng số từ là 100 ứng với 100 dòng  
5. Thay đổi lời mở đầu  
    Truy cập đường dẫn <Input\guide.txt>  
    Thay đổi nội dung trong file <guide.txt>  
6. Thay đổi ID của người tham gia tiếp theo  
    Truy cập đường dẫn <Input\current_state.txt>  
    Thay đổi giá trị của <ID> trong file <current_state.txt>(có thể đưa về "000" để đặt lại dữ liệu người tham gia)  
7. Xóa nhanh toàn bộ dữ liệu trong thư mục <Output>  
    Biên dịch và thực thi mã nguồn trong file <remove_output.cpp>  
    LƯU Ý: KHÔNG THỂ KHÔI PHỤC LẠI DỮ LIỆU ĐÃ XÓA  
# ý nghĩa nội dung các file output
1. Thư mục math  
    Chứa các file lưu các câu hỏi toán học, câu trả lời và trạng thái tương ứng  
    Định dạng tên file: math_<ID người tham gia>.txt  
    Định dạng nội dung file:  
        "ID: <ID người tham gia>  
        
        <Các khối câu hỏi và câu trả lời cách nhau 1 dòng trống>"
    
2. Thư mục vocab  
    Chứa các file lưu lại từ đã xuất hiện theo đúng thứ tự của từng bài kiểm tra  
    Định dạng tên file: vocab_<ID người tham gia>.txt  
    Định dạng nội dung file:  
        "ID: <ID người tham gia>  
        
        <20 từ vựng được hiển thị trong bài kiểm tra theo đúng thứ tự. Mỗi từ nằm trên 1 dòng>"
3. Thư mục participant  
    Đây là thư mục chứa các file kết quả của người tham gia ở dạng đơn giản  
    Định dạng tên file: <ID người tham gia>.txt  
    Nội dung file: Tùy vào bài kiểm tra mà người tham gia chọn.  
4. File summay_report.csv  
    Chứa kết quả của tất cả người tham gia dưới dạng file csv. Định dạng này cho phép nạp file vào phần mềm SPSS và thực hiện các tính toán thống kê phân tích cần thiết.
