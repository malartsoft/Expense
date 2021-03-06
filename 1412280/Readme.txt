*Your info
	-ID: 1412280
	-Name: Trần Hoàng Lâm
	-Email: malartsoft@gmail.com

*What you have done
	-Hoàn thành app thống kê chi tiêu hằng ngày
	-Các chức năng thực hiện được
		+Chương trình đọc dữ liệu từ database và load dữ liệu lên listview
		+Cho phép nhập và lưu các thông tin gồm Loại chi tiêu, nội dung và số tiền hằng ngày, thông tin này sẽ hiện lên listview
			và tự động cập nhập thống kê và vẽ biểu đồ
		+Thông kê sẽ được cập nhật sau mỗi lần thêm gồm thống kê tất cả, ăn uống, di chuyển, nhà cửa, xe cộ, nhu yếu, dịch vụ
		+Biểu đồ hình cột và có chú thích, biểu đồ sẽ được cập nhật sau mỗi lần ấn nút thêm
		+Xử lý các lỗi khi nhập dữ liệu và đọc, ghi database
		+Chương trình sẽ lưu dữ liệu vào database khi người dùng tắt chương trình

*Link youtube guide: https://youtu.be/gWxbvVGRdLM

*Link github: https://github.com/malartsoft/GuessFlag

*Main flow
	
	1. Mở ứng dụng expense, chương trình sẽ đọc và load dữ liệu lên listview và thống kê, vẽ biểu đồ
	2. Nhập đầy đủ nội dung vào các ô textbox (Loại chi tiêu, nội dung, số tiền ($) ví dụ lần lược là Ăn uống, Ăn sáng, 15)
		Loại chi tiêu có thể nhập bằng dropdown list
	3. Nhấn nút thêm để thêm dữ liệu, chương trình sẽ xác nhận "Do you want to add a expense?", Nếu nhấn
		ok thì chương trình sẽ thêm, nếu nhấn cancel thì trở lại
	4. Lisview sẽ cập nhật thông tin ăn uống và thông tin thống kê sẽ cập nhập sau khi nhấn nút thêm ( gồm biểu đồ, các thống kê 
		tổng cộng, ăn uống, di chuyển, nhà cửa, xe cộ, nhu yếu, dịch vụ) (ví dụ: sau khi nhập ăn uống thì thống kê tất cả và 
		thống kê ăn uống sẽ được cộng thêm 15 và biểu đồ cột ăn uống sẽ được tăng lên và các cột khác sẽ giảm xuống bớt)
	5. Nhấn nút 'X' hoặc File-> exit để thoát và dữ liệu được lưu xuống database

*Additional flow
	1.1 Nếu chương trình không đọc được dữ liệu thì chương trình sẽ báo lỗi "don't read database"
	2.1 Nếu nhập không đầy đủ các ô textbox gồm "Loại chi tiêu", "Nội dung", "Số tiền" thì chương
 		trình sẽ báo lỗi "Can't be empty - Try again" (ví dụ để trống sô tiền )
	2.2 Nếu nhập số âm vào số tiền thì chương trình báo lỗi "Don't input number smaller 0 - Try again" (ví dụ nhập số tiền là -5)
	2.3 Nếu nhập số tiền có kí tự thì báo lỗi "Exist char in textbox - Try again" (ví dụ nhập số tiền là a5)
	2.4 Nếu nhập số tiền quá lớn thì báo lỗi "Overflow!!, try again" (ví dụ nhập số tiền là 555555555555)	
	5.1 Nếu chương trình không lưu được dữ liệu thì sẽ báo lỗi "Don't open database"