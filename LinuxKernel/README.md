# LinuxDrive
- Để giao tiếp với phần cứng từ user -> đọc ghi vào device file tượng trưng cho 1 phần cứng cụ thể   -> tham số đến 1 device number (Major và minor) -> Tìm trình điều khiển device driver -> Giao tiếp với phần cứng   
## Character Device Driver  
Các bước tạo ra một device driver
- Cấp phát device number
    - Major number: Là số xác định liên kết giữa driver và device. Thể hiển cho 1 loại thiết bị  
    - Minor number: Thể hiện phiên bản của 1 thiết bị  
    - Có hai cách cấp phát device number
        - static allocating
        - dynamic allocating 
- Tạo device file
    - Tạo class device
    - Tạo device file
- Register file operations: đăng kí đọc/ghi/open/đóng file cho device file
    - struct inode: chứa tất cả thông tin của 1 file
    - struct cdev là một phần tử của struct inode
        - Đại diện cho charecter device 
        - struct file_operations: định nghĩa cho các hoạt động của file  
## Linux kernel header
- Tập hợp các file thư viện để lập trình các module của linux  
- `uname -r`: check phiên bản kernel header
- `sudo apt install linux-headers-uname -r`: install header
- Sau khi cài đặt sau nằm trong thư mục /lib/modules 
- `printk`: in ra thông tin trên kernel, sử dụng `dmesg` để xem  
## Toolchain
- `apt install gcc-arm-linux-gnueabi*`
## 4 thành phần của OS
- Uboot: bộ nạp khởi động
- Kernel: trình điều khiển hệ thống
- Rootfs: Các chương trình vd ls, cd trong linux
- Toolchain: bộ biên dịch mã nguồn cho 1 hệ thống cụ thể  
## Quá trình khởi động
- 

