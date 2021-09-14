# Làm theo thứ tự sau để push code lên remote

Thứ tự
- nếu không dùng clone:
	- git init: tạo kho (repo) rỗng trên máy tính
	- git branch -M main: tạo 1 nhánh mới
	- git remote add origin <link tới kho github>: tạo địa chỉ để push
- nếu dùng git clone thì bỏ qua 
- **Tất cả những cái trên chỉ làm lần đầu tiên khi tạo repo, những lần sau không cần**
- git add . : lưu tất cả thay đổi trong code
- git commit -m "<tin nhắn>": gửi lên xe tải với tin nhắn
- git push -u origin main: cho xe chạy