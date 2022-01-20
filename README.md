# DA_GTLT
Tìm hiểu các thuật toán sắp xếp và so sánh độ phức tạp của chúng
Các giải thuật sắp xếp:(6 giai thuat sắp xếp)

1) Selection sort:
a) Ý tưởng
-	Là một thuật toán sắp xếp đơn giản, dựa trên việc so sánh tại chỗ.
-	Ta chọn phần tử nhỏ nhất trong N phần tử ban đầu, đưa phần tử này về đầu dãy hiện hành.
-	Sau đó, ta không quan tâm đến nó nữa, ta xem dãy hiện hành chỉ còn N-1 phần tử của dãy ban đầu tính từ vị trí thứ 2. Cứ vậy, cho đến khi dãy hiện hành chỉ còn 1 phần tử, ta được 1 dãy sắp tăng.
b)Độ Phức Tạp:
Tổng kết lại, ta luôn có độ phức tạp của thuật toán Selection Sort: thuộc O(n2) trong mọi trường hợp

2) Insertion sort:
a)Ý tưởng:
-	Giả sử ta có dãy a1, a2, …, an trong đó i phần tử đầu tiên a1, a2, …, ai đã có thứ tự. Ý tưởng của thuật toán là tìm vị trị thích hợp và chèn phần tử ai+1 vào dãy đã có thứ tự trên để có được một dãy mới có thứ tự. Cứ thế, làm đến cuối dãy ta sẽ được một dãy có thứ tự.
-	Với dãy ban đầu a1, a2, …, an ta có thể coi đoạn chỉ có một phần tử a1 là một đoạn đã có thứ tự, sau đó ta chèn phần tử a2 vào dãy a1 để có dãy a1a2 có thứ tự. Tiếp đó, ta lại chèn phần tử a3 vào dãy a1a2 để có dãy a1a2a3 có thứ tự. Cứ thế, đến cuối cùng ta chèn phần tử an vào dãy a1a2…an-1 ta sẽ được dãy a1a2…an có thứ tự.
b)Độ Phức Tạp:
-	Ta thấy: Các phép so sánh trong vòng lặp tìm ra vị trí thích hợp pos để chèn x. Mỗi lần so sánh, vị trí đang xét không thích hợp, ta dời phần tử a[pos] sang phải.
-	Ta cũng thấy số phép gán và số phép so sánh của thuật toán phụ thuộc vào tình trạng của dãy ban đầu. Do đó ta chỉ có thể ước lượng:
•	  Trường hợp tốt nhất: dãy ban đầu đã có thứ tự. Ta tìm được ngay vị trí thích hợp để chèn ngay lần so sánh đầu tiên mà không cần phải vô vòng lặp. Như vậy, với i chạy từ 2 đến n thì số phép so sánh tổng cộng sẽ là n-1. Còn với số phép gán, do thuật toán không chạy vào vòng lặp nên xét i bất kỳ, ta luôn chỉ phải tốn 2 phép gán(x = a[i] và a[pos] = x). Từ đây, ta tính được số phép gán tổng cộng bằng 2(n - 1).
•	  Trường hợp xấu nhất: dãy ban đầu có thứ tự ngược. Ta thấy ngay vị trí thích hợp pos luôn là vị trí đầu tiên của dãy đã có thứ tự, và do đó, để tìm ra vị trí này ta phải duyệt hết dãy đã có thứ tự. Xét i bất kỳ, ta có số phép so sánh là i-1, số phép gán là (i - 1) + 2 = i + 1. Với i chạy từ 2 đến n, ta tính được số phép so sánh tổng cộng bằng 1 + 2 + … + (n - 1) = n(n - 1)/2 và số phép gán bằng 
3 + 4 + .. + (n + 1) = (n + 4)(n - 1)/2
	Tổng kết lại, ta có độ phức tạp của Insertion Sort như sau:
•	Trường hợp tốt nhất: O(n)
•	Trường hợp xấu nhất O(n2)

3)Bubble sort:
a)Ý tưởng:
-	Xuất phát từ phần tử cuối danh sách ta tiến hành so sánh với phần tử bên trái của nó. Nếu phần tử đang xét có khóa nhỏ hơn phần tử bên trái của nó ta tiến đưa nó về bên trái của dãy bằng cách hoán vị với phần tử bên trái của nó. Tiếp tục thực hiện như thế đối với bài toán có n phần tử thì sau n –1 bước ta thu được danh sách tăng dần.
b)Đọ Phức Tạp:
-	Ta thấy: Số phép so sánh là luôn không đổi, tức không phụ thuộc vào tình trạng ban đầu của dãy. Với i bất kỳ, ta luôn phải so sánh V[j] với V[j-1], mà j chạy từ n đến i+1, tức ta tốn n-i phép so sánh. Thêm nữa, i chạy từ 1 đến n-1. Vậy ta tính được số phép so sánh tổng cộng: ∑(n-i) với i chạy từ 1 đến n-1 = (n-1) + (n-2) + … + 1 = n(n-1)/2.
-	Số phép hoán vị (tương đương 3 phép gán) lại phụ thuộc vào tình trạng ban đầu của dãy. Cụ thể như sau:
•	  Trường hợp tốt nhất: Dãy ban đầu đã có thứ tự. Ta thấy ngay ta không tốn một phép hoán vị nào.
•	  Trường hợp xấu nhất: Dãy ban đầu có thứ tự ngược. Xét i bất kỳ, ta thấy rằng mỗi lần so sánh a[j] với a[j-1], ta đều phải thực hiện hoán vị. Điều này có nghĩa là số phép hoán vị bằng n(n-1)/2.
=> Tổng kết lại, ta có độ phức tạp của Bubble Sort: thuộc O(n2) trong mọi trường hợp. 

4)Merge sort
a)Ý tương:
-	Cho dãy ban đầu a1, a2, …, an. Ta luôn có thể coi nó là tập hợp liên tiếp của các dãy có thứ tự. Ta gọi các dãy có thứ tự này là các dãy con.
-	Trong phương pháp Merge Sort, vấn đề là ta tìm cách phân hoạch dãy ban đầu thành các dãy con. Sau khi phân hoạch xong, dãy ban đầu sẽ được tách thành hai dãy phụ theo nguyên tắc phân phối luân phiên dãy con. Sau đó, ta trộn từng cặp dãy con của hai dãy phụ thành một dãy con của dãy ban đầu. Ta nhận thấy số dãy con của dãy ban đầu lúc này giảm đi ít nhất là một nửa. Cứ thế sau một số bước, ta sẽ nhận được dãy ban đầu với số dãy con bằng 1, có nghĩa là ta đã sắp xếp xong.
-	Trộn trực tiếp: đây là phương pháp trộn đơn giản nhất. Việc phân hoạch dãy ban đầu đơn giản như sau: Với dãy ban đầu có n phân tử, ta cứ phân hoạch thành n dãy con. Vì rằng mỗi dãy con chỉ có 1 phần tử nên nó là dãy có thứ tự. Cứ mỗi lần tách – trộn, chiều dài của dãy con sẽ được nhân đôi.
b)Độ Phức Tạp:
-	Ta thấy ngay số lần lặp của bước 2(phân phối) và bước 3(trộn) bằng log2n. Ta cũng thấy rằng chi phí thực hiện bước 2 và bước 3 tỉ lệ thuận với n. Như vậy, ta có thể ước tính chi phí thực hiện của giải thuật Merge Sort thuộc O(nlog2n).
-	Ta nhận thấy rằng giải thuật làm việc một cách cứng nhắc, không tận dụng được tính thứ tự một phần của dãy ban đầu. Do đó, trong mọi trường hợp độ phức tạp là như nhau. Đây là một nhược điểm của phương pháp trộn trực tiếp

5)Quick sort:
a)Ý tưởng:
-	Cho một dãy, chọn một phần tử ở giữa, chia đoạn thành 2 phần.
-	Chuyển các phần tử nhỏ, hoặc bằng đến trước, các phần tử lớn hơn về sau. 
-	Sẽ được nửa đầu bé hơn nửa sau.
-	Lặp lại việc chuyển đổi cho các phần tử nửa đầu, và nửa sau đến lúc số phần tử là 1
b)Độ Phức Tạp:
-	Ta nhận thấy hiệu quả của thuật toán phụ thuộc vào việc chọn giá trị mốc (hay phần tử chốt).
-	Trường hợp tốt nhất:
•	Mỗi lần phân hoạch ta đều chọn được phần tử trung gian làm mốc. Khi đó dãy được phân hoạch thành hai phần bằng nhau. 
•	Ta cần log2(n) lần phân hoạch thì sắp xếp xong. 
•	Trong mỗi lần phân hoạch ta cần duyệt qua n phần tử. 
	Vậy độ phức tạp trong trường hợp tốt nhất thuộc O(nlog2(n)).
-	Trường hợp xấu nhất: 
•	Mỗi lần phần hoạch ta chọn phải phần tử có giá trị cực đại hoặc cực tiểu làm mốc. Khi đó dãy bị phân hoạch thành hai phần không đều: một phần chỉ có một phần tử, phần còn lại có n-1 phần tử. Do đó, ta cần tới n lần phân hoạch mới sắp xếp xong. 
	Vậy độ phức tạp trong trường hợp xấu nhất thuộc O(n2). 
	Tổng kết lại, ta có độ phức tạp của Quick Sort:
•	Trường hợp tốt nhất: O(nlog2(n))
•	Trường hợp xấu nhất: O(n2)
•	Trường hợp trung bình: O(log(n))

6)Heap sort:
a)Ý tưởng:
-	 Tổ chúc một cấu trúc dữ liệu có khả năng thể hiện được các quan hệ của các phần tử trong cây với n ôn nhớ thay vì 2n-1.
-	 Định nghĩa Heap: Heap là mảng 1 chiều chứa các phần tử từ a1, a2 … ar. Các phần tử từ a[r/2 + 1] đến a[n] là heap tự nhiên. Các phần tử còn lại thỏa a[i] >= a[2*i] và a[i] >= a[2*i+1] (i=1…n/2) (Điều kiện này là cho sắp xếp tăng dần)
-	 Tính chất: 
+ Tính chất 1: Nếu a1, a2 … ar là một heap thì khi cắt bỏ một số phần tử ở hai đầu của heap, dãy còn lại vẫn là một heap.
+ Tính chất 2: Nếu a1, a2 … ar là một heap thì phần tử a1 luôn là phần tử lớn nhất trong heap
+ Tính chất 3: Mọi dãy a1, a2 … ar với 2l>r là một heap.
-	 Như vậy ta thấy gốc của heap luôn là phần tử lớn nhất, nếu ta lần lượt rút trích phần tử gốc và xây dựng lại heap đã bị rút trích ta sẽ có một mảng có thứ tự tăng dần.
-	Giải thuật Heapsort còn được gọi là giải thuật vun đống, nó có thể được xem như bản cải tiến của Selection sort khi chia các phần tử thành 2 mảng con, 1 mảng các phần tử đã được sắp xếp và mảng còn lại các phần tử chưa được sắp xếp. Trong mảng chưa được sắp xếp, các phần tử lớn nhất sẽ được tách ra và đưa vào mảng đã được sắp xếp. Điều cải tiến ở Heapsort so với Selection sort ở việc sử dụng cấu trúc dữ liệu heap thay vì tìm kiếm tuyến tính (linear-time search) như Selection sort để tìm ra phần tử lớn nhất.
-	Heap Sort là một ứng dụng của cấu trúc dữ liệu heap.
b)Độ Phức Tạp:
-	Heapsort gọi tới buildheap và n-1 lần gọi tới heaprify suy ra đô ̣phức tạp của nó là: O(n + (n-1)logn) = O(n*log n).


==>Example:
	Với mảng có kích thước nhỏ arr[] = {14, 3, 9, 6, 2, 7, 5 ,19}, n=8

	Sắp xếp lựa chọn (Selection sort):
-	 Bước 1: i=0	2, 3, 9, 6, 14, 7, 5 ,19
-	 Bước 2: i=1 	2, 3, 9, 6, 14, 7, 5 ,19
-	 Bước 3: i=2 	2, 3, 5, 6, 14, 7, 9 ,19
-	 Bước 4: i=3 	2, 3, 5, 6, 14, 7, 9 ,19
-	 Bước 5: i=4 	2, 3, 5, 6, 7, 14, 9 ,19
-	 Bước 6: i=5 	2, 3, 5, 6, 7, 9, 14 ,19
-	 Bước 7: i=6	2, 3, 5, 6, 7, 9, 14 ,19
	Kết quả: 	2, 3, 5, 6, 7, 9, 14 ,19

	Sắp xếp chèn (Insert Sort) :
-	 Bước 1: i=0	2, 3, 9, 6, 14, 7, 5 ,19
-	 Bước 2: i=1 	2, 3, 9, 6, 14, 7, 5 ,19
-	 Bước 3: i=2 	2, 3, 9, 6, 14, 7, 5 ,19
-	 Bước 4: i=3 	2, 3, 6, 9 14, 7, 5 ,19
-	 Bước 5: i=4 	2, 3, 6, 9, 14, 7, 5 ,19
-	 Bước 6: i=5 	2, 3, 6, 7, 9, 14, 5 ,19
-	 Bước 7: i=6	2, 3, 5, 6, 7, 9, 14, 19
	Kết quả: 	2, 3, 5, 6, 7, 9, 14 ,19

	Sắp xếp nổi bọt (Bubble Sort):
-	Bước 1: i=0	2, 3, 9, 6, 14, 7, 5 ,19
-	 Bước 2: i=1 	2, 3, 9, 6, 14, 7, 5 ,19
-	 Bước 3: i=2 	2, 3, 9, 6, 14, 7, 5 ,19
-	 Bước 4: i=3 	2, 3, 6, 9 14, 7, 5 ,19
-	 Bước 5: i=4 	2, 3, 6, 9, 14, 7, 5 ,19
-	 Bước 6: i=5 	2, 3, 6, 7, 9, 14, 5 ,19
-	 Bước 7: i=6	2, 3, 5, 6, 7, 9, 14, 19
	Kết quả: 	2, 3, 5, 6, 7, 9, 14 ,19

	Sắp xếp nhanh (Quick Sort):
-	Phân hoạch đoạn left=0, right=7, pivot=3 ta có mảng: 
arr[] = {5, 3, 2, 6, 9, 7, 14 ,19}
-	Phân hoạch đoạn left=0, right=3, pivot=1 ta có mảng: 
arr[] = {2, 3, 5, 6, 9, 7, 14 ,19}
-	Phân hoạch đoạn left=4, right=7, pivot=5 ta có mảng: 
arr[] = {2, 3, 5, 6, 9, 7, 14 ,19}
-	Phân hoạch đoạn left=4, right=5, pivot=4 ta có mảng: 
arr[] = {2, 3, 5, 6, 9, 7, 14 ,19}
-	Phân hoạch đoạn left=4, right=5, pivot=4 ta có mảng: 
arr[] = {2, 3, 5, 6, 7, 9, 14 ,19}

	Sắp xếp trộn (Merge Sort):
-	Bắt đầu: 14, 3, 9, 6, 2, 7, 5 ,19
-	Chọn chạy: (14 3 9 6) (2 7 5 19) 
-	Chọn chạy: (14 3) (9 6) (2 7) (5 19) 
-	Chọn chạy: (14) ( 3) (9)  ( 6) (2) ( 7) (5) (19) 
-	Hợp nhất: (3 14) (6 9) (2 7) (5 19) 
-	Hợp nhất: (3 6 9 14) (2 5 7 19)
-	Hợp nhất: (2 3 5 6 7 9 14 19)
-	
	Sắp xếp vun đống (Heap Sort):
arr[] = {14, 3, 9, 6, 2, 7, 5 ,19}

           14 (0) 
        /           \ 
     3(1)          9 (2) 
    /   \           /    \ 
6 (3) 2 (4)   7(5) 5(6)
  / 
19(7)
Các số trong ngoặc đại diện cho các chỉ số trong biểu diễn mảng của dữ liệu. 
•	Build heap:
-	Bước 1:i=(n/2)-1=4-1=3
            14 (0) 
           /         \ 
     3(1)          9 (2) 
    / \              / \ 
 19 (3) 2(4)   7(5) 5(6)
  / 
6(7)
-	Bước 2:i=2
           14(0) 
        /           \ 
     3(1)          9 (2) 
    / \              / \ 
 19 (3) 2 (4)   7(5) 5(6)
 /
6(7)

-	Bước 3:i=1
            14(0) 
        /           \ 
   19(1)          9 (2) 
   / \              / \ 
 6 (3) 2 (4)   7(5) 5(6)
/
3(7)

-	Bước 4:i=0

            19(0) 
        /           \ 
   14(1)          9 (2) 
   / \              / \ 
 6 (3) 2 (4)   7(5) 5(6)
/
3(7)
Rut 19 
•	Rút phần tử root và rebuild heap
-	Bước 1: 

          3(0) 
        /           \ 
   14(1)          9 (2) 
   / \              / \ 
 6 (3) 2 (4)   7(5) 5(6)
-	Bước 2:

          14(0) 
        /           \ 
   6(1)          9 (2) 
   / \              / \ 
 3 (3) 2 (4)   7(5) 5(6)
Rút 14
-	Bước 3:

          5(0) 
        /           \ 
   6(1)          9 (2) 
   / \              /  
 3 (3) 2 (4)   7(5) 


-	Bước 4: 

          9(0) 
        /           \ 
   6(1)          7 (2) 
   / \              /  
 3 (3) 2 (4)  5(5) 
-Rút 9

-	Bước 5:

          5(0) 
        /           \ 
   6(1)          7 (2) 
   / \                
 3 (3) 2 (4)   


-	Bước 6:
          7(0) 
        /           \ 
   6(1)          5 (2)        
   / \                
 3 (3) 2 (4)   
Rút 7
-	Bước 7:          
         
            2(0) 
        /           \ 
   6(1)          5 (2) 
   /                 
 3 (3)   

-	Bước 8:
            6(0) 
        /           \ 
   3(1)          5 (2) 
   /                 
 2 (3)   
-Rút 6



-	Bước 9:
          2(0) 
        /           \ 
   3(1)          5 (2)                  
-	Bước 10:

          5(0) 
        /           \ 
   3(1)          2 (2)                  

-Rút 5

	
-	Bước 11:
           2(0)
        /           
     3(1)
-	Bước 12:
           3(0)
        /           
     2(1)
-Rút 3
-	Bước 13:
           2(0)
           -Rút 2.       
    

	 Kết quả:  2, 3, 5, 6, 7, 9, 14 ,19

STT	Tên thuật toán	Trường hợp tốt nhất	Trường hợp xấu nhất
1	Sắp xếp chọn (Selection Sort)	O(n2)	O(n2)
2	Sắp xếp chèn (Insert Sort)	O(n)	O(n2)
3	Sắp xếp nổi bọt (Bubble Sort)	O(n2)	O(n2)
4	Sắp xếp nhanh (Quick Sort)	O(nlog2(n))	O(n2)
5	Sắp xếp trộn (Merge Sort)	O(nlog2(n))	O(nlog2(n))
6	Sắp xếp vun đống (Heap Sort)	O(nlog(n))	O(nlog(n))
7	Sắp xếp cơ số (Radix Sort)	O(nlog(n))	O(n2)
8	Sắp xếp cải tiến (Shell Sort)	O(n)	O(n)

Tìm hiểu các thuật toán Tìm Kiếm và so sánh độ phức tạp của chúng
Các giải thuật Tìm Kiếm:

1)linear search:
a)Ý tưởng:
Tìm kiếm tuyến tính (linear search) hay tìm kiếm tuần tự (sequential search) là thuật toán tìm kiếm bằng cách duyệt qua tất cả các phần tử của danh sách cho đến khi gặp phần tử cần tìm hoặc là đã hết danh sách.
b)Độ Phức Tạp:
Do cách tìm kiếm duyệt từ đầu đến cuối này, độ phức tạp thời gian của thuật toán này sẽ là O(n).

2)binary search:
a)Ý tưởng:
là thuật toán tìm kiếm dựa trên việc chia đôi khoảng đang xét sau mỗi lần lặp, sau đó xét tiếp trong nửa khoảng có khả năng chứa giá trị cần tìm, cứ như vậy cho đến khi không chia đôi khoảng được nữa. Thuật toán tìm kiếm nhị phân chỉ áp dụng được cho danh sách đã có thứ tự hay đã được sắp xếp.
b)Độ Phức tạp:
Do cách tìm kiếm chia đôi khoảng này, sau mỗi lần lặp, khoảng đang xét lại được chia đôi, và tiếp tục khoảng tiếp lại chia đôi khoảng đã được chia trước đó. Do đó, độ phức tạp thời gian của thuật toán này sẽ là O(log(n)), tốt hơn rất rất nhiều so với tìm kiếm tuyến tính.

==> Tổng Kết:
- linear search: O(n)
- binary search: O(logn)
