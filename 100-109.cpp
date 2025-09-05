#Bài 100: Viết chương trình giải phương trình bậc 2
/*
  Sưu tầm bởi @nguyenvanhieuvn
  Thực hành nhiều ##Bài tập hơn tại https://luyencode.net/
*/

// ax^2 + bx + c = 0
#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
    float a, b, c; // Khai báo.

    printf("\nNhap vao a = ");
    scanf("%f", &a);

    printf("\nNhap vao b = ");
    scanf("%f", &b);

    printf("\nNhap vao c = ");
    scanf("%f", &c);

    if (a == 0) // pt có dạng: bx + c = 0
    {
        if (b == 0) // pt có dạng: c = 0
        {
            if (c == 0)
            {
                printf("\nPhuong trinh co vo so nghiem");
            }
            else
            {
                printf("\nPhuong trinh vo nghiem");
            }
        }
        else
        {

            float x = -c / b;

            printf("\nPhuong trinh co nghiem duy nhat x = %f", x);
        }
    }
    else
    {
        float Denta = b * b - 4 * a * c;

        if (Denta < 0)
        {
            printf("\nPhuong trinh vo nghiem");
        }
        else if (Denta == 0)
        {
            float x = -b / (2 * a);

            printf("\nPhuong trinh co nghiem kep x1 = x2 = %f", x);
        }
        else // Denta > 0
        {
            float x1 = (-b + sqrt(Denta)) / (2 * a);
            float x2 = (-b - sqrt(Denta)) / (2 * a);

            printf("\nPhuong trinh co 2 nghiem phan biet:\nx1 = %f\nx2 = %f", x1, x2);

        }
    }


    getch();
    return 0;
}


#Bài 101: Viết chương trình nhập tháng, năm. Hãy cho biết tháng đó có bao nhiêu ngày
/*
  Sưu tầm bởi @nguyenvanhieuvn
  Thực hành nhiều ##Bài tập hơn tại https://luyencode.net/
*/

#include<stdio.h>
#include<conio.h>

const int minYear = 1900, maxYear = 10000;
int KiemTraNamNhuan(int nam)
{
        return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}
void TimSoNgayTrongThang(int thang, int nam)
{
    switch(thang)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        printf("\nCo 31 ngay");
        break;
    case 4: case 6: case 9 : case 11:
        printf("\nCo 30 ngay");
        break;
    case 2:
        int Check = KiemTraNamNhuan(nam);
        if(Check == 1)
        {
            printf("\nCo 29 ngay !");
        }
        else
        {
            printf("\nCo 28 ngay !");
        }
    }
}

int main()
{
    int Thang, Nam;

    do
    {
        printf("\nNhap vao thang: ");
        scanf("%d", &Thang);
        if (Thang < 1 || Thang > 12)
            printf("\nDu lieu thang khong hop le. Xin kiem tra lai!");
    }while(Thang < 1 || Thang > 12);
    do
    {
        printf("\nNhap vao nam: ");
        scanf("%d", &Nam);
        if(Nam < minYear || Nam > maxYear)
        {
            printf("\nDu lieu nam khong hop le. Xin kiem tra lai!");
        }
    }while(Nam < minYear || Nam > maxYear);
    TimSoNgayTrongThang(Thang, Nam);

    getch();
    return 0;
}


#Bài 102: Viết chương trình nhập vào 1 ngày ( ngày, tháng, năm). Tìm ngày kế ngày vừa nhập (ngày, tháng, năm)
/*
  Sưu tầm bởi @nguyenvanhieuvn
  Thực hành nhiều #Bài tập hơn tại https://luyencode.net/
*/

#include<stdio.h>
#include<conio.h>

const int minYear = 1900, maxYear = 10000;
int KiemTraNamNhuan(int nam)
{
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}
int TimSoNgayTrongThang(int thang, int nam)
{
    int NgayTrongThang;
    switch(thang)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        NgayTrongThang = 31;
        break;
    case 4: case 6: case 9 : case 11:
        NgayTrongThang = 30;
        break;
    case 2:
        int Check = KiemTraNamNhuan(nam);
        if(Check == 1)
        {
            NgayTrongThang = 29;
        }
        else
        {
            NgayTrongThang = 28;
        }
    }
    return NgayTrongThang;
}

void TimNgayKeTiep(int Ngay, int Thang, int Nam)
{
    int NgayTrongThang = TimSoNgayTrongThang(Thang, Nam);
    if (Ngay < NgayTrongThang)  // Tăng ngày lên
    {
        Ngay++;
    }
    else if (Thang < 12)     // Ngày kế tiếp là đầu tháng
    {
        Ngay = 1; Thang++;
    }
    else                      // Ngày kế là đầu năm mới tức là hiện tai đang là tháng 12
    {
        Ngay = Thang = 1;
        Nam++;
    }
    printf("\nNgay ke tiep la: %d - %d - %d ", Ngay, Thang, Nam);
}
int main()
{
    int Ngay, Thang, Nam;

    do
    {
        printf("\nNhap vao nam: ");
        scanf("%d", &Nam);
        if(Nam < minYear || Nam > maxYear)
        {
            printf("\nDu lieu nam khong hop le. Xin kiem tra lai!");
        }
    }while(Nam < minYear || Nam > maxYear);

    do
    {
        printf("\nNhap vao thang: ");
        scanf("%d", &Thang);
        if (Thang < 1 || Thang > 12)
            printf("\nDu lieu thang khong hop le. Xin kiem tra lai!");
    }while(Thang < 1 || Thang > 12);

    int NgayTrongThang = TimSoNgayTrongThang(Thang, Nam);
    do
    {
        printf("\nNhap vao ngay: ");
        scanf("%d",&Ngay);
        if(Ngay < 1 || Ngay > NgayTrongThang)
        {
            printf("\nDu lieu ngay khong hop le. Xin kiem tra lai!");
        }
    }while(Ngay < 1 || Ngay > NgayTrongThang);
    
    TimNgayKeTiep(Ngay, Thang, Nam);

    getch();
    return 0;
}


#Bài 103: Viết chương trình nhập vào 1 ngày ( ngày, tháng, năm). Tìm ngày trước ngày vừa nhập (ngày, tháng, năm)

/*
  Sưu tầm bởi @nguyenvanhieuvn
  Thực hành nhiều #Bài tập hơn tại https://luyencode.net/
*/

#include<stdio.h>
#include<conio.h>

const int minYear = 1900, maxYear = 10000;
int KiemTraNamNhuan(int nam)
{
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}
int TimSoNgayTrongThang(int thang, int nam)
{
    int NgayTrongThang;
    switch(thang)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        NgayTrongThang = 31;
        break;
    case 4: case 6: case 9 : case 11:
        NgayTrongThang = 30;
        break;
    case 2:
        int Check = KiemTraNamNhuan(nam);
        if(Check == 1)
        {
            NgayTrongThang = 29;
        }
        else
        {
            NgayTrongThang = 28;
        }
    }
    return NgayTrongThang;
}

void TimNgayTruocDo(int Ngay, int Thang, int Nam)
{
    int NgayTrongThang = TimSoNgayTrongThang(Thang, Nam);
    if(Ngay == 1)            // Nếu ngày nhập vào là 1
    {
        Ngay = NgayTrongThang;        // ngày trước đó là số ngày trong tháng trước 
        if(Thang == 1)            // Nếu tháng là 1
        {
            Thang = 12;
            Nam--;
        }
        else                     // Tháng khác 1
            Thang--;
    }
    else                // Ngày khác 1
        Ngay--;
        printf("\nNgay truoc do la: %d - %d - %d ", Ngay, Thang, Nam);
    }
    int main()
    {
        int Ngay, Thang, Nam;

        do
        {
            printf("\nNhap vao nam: ");
            scanf("%d", &Nam);
            if(Nam < minYear || Nam > maxYear)
            {
                printf("\nDu lieu nam khong hop le. Xin kiem tra lai!");
            }
        }while(Nam < minYear || Nam > maxYear);

        do
        {
            printf("\nNhap vao thang: ");
            scanf("%d", &Thang);
            if (Thang < 1 || Thang > 12)
                printf("\nDu lieu thang khong hop le. Xin kiem tra lai!");
        }while(Thang < 1 || Thang > 12);

        int NgayTrongThang = TimSoNgayTrongThang(Thang, Nam);
        do
        {
            printf("\nNhap vao ngay: ");
            scanf("%d",&Ngay);
            if(Ngay < 1 || Ngay > NgayTrongThang)
            {
                printf("\nDu lieu ngay khong hop le. Xin kiem tra lai!");
            }
        }while(Ngay < 1 || Ngay > NgayTrongThang);

        TimNgayTruocDo(Ngay, Thang, Nam);

        getch();
        return 0;
    }
	
	
#Bài 104: Viết chương trình nhập ngày, tháng, năm. Tính xem ngày đó là ngày thứ bao nhiêu trong năm
/*
  Sưu tầm bởi @nguyenvanhieuvn
  Thực hành nhiều #Bài tập hơn tại https://luyencode.net/
*/

#include<stdio.h>
#include<conio.h>
//
//const int minYear = 1900, maxYear = 10000;
//int KiemTraNamNhuan(int nam)
//{
//    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
//}
//int TimSoNgayTrongThang(int thang, int nam)
//{
//    int NgayTrongThang;
//    switch(thang)
//    {
//    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
//        NgayTrongThang = 31;
//        break;
//    case 4: case 6: case 9 : case 11:
//        NgayTrongThang = 30;
//        break;
//    case 2:
//        int Check = KiemTraNamNhuan(nam);
//        if(Check == 1)
//        {
//            NgayTrongThang = 29;
//        }
//        else
//        {
//            NgayTrongThang = 28;
//        }
//    }
//    return NgayTrongThang;
//}
//int TimNgayThuBaoNhieuTrongNam(int Ngay, int Thang, int Nam)
//{
//    int NgayTrongThang = TimSoNgayTrongThang(Thang, Nam);
//    int S = Ngay;
//    for(int i = 1; i < Thang; i++) 
//    { 
//        S = S + NgayTrongThang;
//    }
//    return S;
//}
//
//int main()
//{
//    int Ngay, Thang, Nam;
//    do
//    {
//        printf("\nNhap vao nam: ");
//        scanf("%d", &Nam);
//        if(Nam < minYear || Nam > maxYear)
//        {
//            printf("\nDu lieu nam khong hop le. Xin kiem tra lai!");
//        }
//    }while(Nam < minYear || Nam > maxYear);
//
//    do
//    {
//        printf("\nNhap vao thang: ");
//        scanf("%d", &Thang);
//        if (Thang < 1 || Thang > 12)
//            printf("\nDu lieu thang khong hop le. Xin kiem tra lai!");
//    }while(Thang < 1 || Thang > 12);
//
//    int NgayTrongThang = TimSoNgayTrongThang(Thang, Nam);
//    do
//    {
//        printf("\nNhap vao ngay: ");
//        scanf("%d",&Ngay);
//        if(Ngay < 1 || Ngay > NgayTrongThang)
//        {
//            printf("\nDu lieu ngay khong hop le. Xin kiem tra lai!");
//        }
//    }while(Ngay < 1 || Ngay > NgayTrongThang);
//
//    int S = TimNgayThuBaoNhieuTrongNam(Ngay, Thang, Nam);
//    printf("\nNgay thu %d trong nam", S);
//    getch();
//    return 0;
//}

int main()
{
    int day, month, year, s, i;
    printf("\nNhap ngay, thang, nam: ");
    scanf("%d%d%d", &day, &month, &year);

    s = day;
    for(i = 1; i < month; i++)
    {
        switch (i)
        {
            case 4: case 6: case 9 : case 11: s+= 30; break;
            case 2: s += (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) ? 29 : 28;
                break;
        default: s += 31;
        }
    }
    printf("\nNgay thu %d trong nam", s);

    getch();
    return 0;
}

#Bài 105: Viết chương trình nhập 1 số nguyên có 2 chữ số.  Hãy in ra cách đọc của số nguyên này
/*
  Sưu tầm bởi @nguyenvanhieuvn
  Thực hành nhiều #Bài tập hơn tại https://luyencode.net/
*/

#include<stdio.h>
#include<conio.h>

int main(){
    int So;  // Khai báo
    printf("Nhap vao so = ");
        scanf_s("%d", &So);
    if (So < 10 || So > 99){
        printf("\nKhong hop le !");
        getch();
        return 0;
    }
    else  // Hợp lệ
    {  
        // Xử lý
        // 15 --> Muoi Lam
        int donvi = So % 10;
        int chuc = So / 10;

        if (chuc == 2)
        {
            printf("Hai");
        }
        else if (chuc == 3)
        {
            printf("Ba");
        }
        else if (chuc == 4)
        {
            printf("Bon");
        }
        else if (chuc == 5)
        {
            printf("Nam");
        }
        else if (chuc == 6)
        {
            printf("Sau");
        }
        else if (chuc == 7)
        {
            printf("Bay");
        }
        else if (chuc == 8)
        {
            printf("Tam");
        }
        else if (chuc == 9)
        {
            printf("Chin");
        }
        printf(" Muoi ");

        if (donvi == 1)
        {
            printf("Mot");
        }
        else if (donvi == 2)
        {
            printf("Hai");
        }
        else if (donvi == 3)
        {
            printf("Ba");
        }
        else if (donvi == 4)
        {
            printf("Bon");
        }
        else if (donvi == 5)
        {
            printf("Nam");
        }
        else if (donvi == 6)
        {
            printf("Sau");
        }
        else if (donvi == 7)
        {
            printf("Bay");
        }
        else if (donvi == 8)
        {
            printf("Tam");
        }
        else if (donvi == 9)
        {
            printf("Chin");
        }
    }
    getch();
    return 0;
}

#Bài 106 Viết chương trình nhập 1 số nguyên có 3 chữ số.  Hãy in ra cách đọc của số nguyên này
/*
  Sưu tầm bởi @nguyenvanhieuvn
  Thực hành nhiều #Bài tập hơn tại https://luyencode.net/
*/

#include<stdio.h>
#include<conio.h>

int main(){
    int So;  // Khai báo
    printf("Nhap vao so = ");
    scanf("%d", &So);
    if (So < 100 || So > 999){
        printf("\nKhong hop le !");
        getch();
        return 0;
    }
    else  // Hợp lệ
    {
        // Xử lý
        // 123
        int donvi = So % 10;
        So /= 10;  // 12
        int chuc = So % 10;
        int tram = So / 10;

        if (tram == 1)
        {
            printf("Mot");
        }
        else if (tram == 2)
        {
            printf("Hai");
        }
        else if (tram == 3)
        {
            printf("Ba");
        }
        else if (tram == 4)
        {
            printf("Bon");
        }
        else if (tram == 5)
        {
            printf("Nam");
        }
        else if (tram == 6)
        {
            printf("Sau");
        }
        else if (tram == 7)
        {
            printf("Bay");
        }
        else if (tram == 8)
        {
            printf("Tam");
        }
        else if (tram == 9)
        {
            printf("Chin");
        }
        printf(" Tram ");

        if (chuc == 2)
        {
            printf("Hai");
        }
        else if (chuc == 3)
        {
            printf("Ba");
        }
        else if (chuc == 4)
        {
            printf("Bon");
        }
        else if (chuc == 5)
        {
            printf("Nam");
        }
        else if (chuc == 6)
        {
            printf("Sau");
        }
        else if (chuc == 7)
        {
            printf("Bay");
        }
        else if (chuc == 8)
        {
            printf("Tam");
        }
        else if (chuc == 9)
        {
            printf("Chin");
        }
        printf(" Muoi ");


        if (donvi == 1)
        {
            printf("Mot");
        }
        else if (donvi == 2)
        {
            printf("Hai");
        }
        else if (donvi == 3)
        {
            printf("Ba");
        }
        else if (donvi == 4)
        {
            printf("Bon");
        }
        else if (donvi == 5)
        {
            printf("Lam");
        }
        else if (donvi == 6)
        {
            printf("Sau");
        }
        else if (donvi == 7)
        {
            printf("Bay");
        }
        else if (donvi == 8)
        {
            printf("Tam");
        }
        else if (donvi == 9)
        {
            printf("Chin");
        }
    }
    getch();
    return 0;
}

#Bài 107: Viết hàm tính S = CanBacN(x)
/*
  Sưu tầm bởi @nguyenvanhieuvn
  Thực hành nhiều #Bài tập hơn tại https://luyencode.net/
*/

#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
    double S;
   float x, n;

    printf("\nNhap x: ");
    scanf("%f", &x);

    printf("\nNhap n: ");
    scanf("%f", &n);
    n = 1/ n;
    S = pow(x, n);

    printf("Can bac %.2f cua %.2f la %.2f",1/n, x, S);

    getch();
    return 0;
}

#Bài 108:  Viết hàm tính S = x^y
/*
  Sưu tầm bởi @nguyenvanhieuvn
  Thực hành nhiều #Bài tập hơn tại https://luyencode.net/
*/

#include<stdio.h>
#include<conio.h>


#include<stdio.h>
#include<conio.h>


double Power_n(double x, long n)
{
    // n >= 0
    double result = 1;
    while(n--)
    {
        result = result * x;
    }
    return result;
}
double qPower_n(double x, long n)
{
    // n >= 0
    double result = 1;
    while(n)
    {
        if(n % 2 == 1)
        {
            result = result * x;
        }
        x = x * x;
        n = n / 2;
    }
    return result;
}
int main()
{
    double x = 4;
    long n = 2;
    double z;
    z = qPower_n(x, n);
    printf("z = %f", z);

    getch();
    return 0;
}

#Bài 109: Viết chương trình in bảng cửu chương ra màn hình
/*
  Sưu tầm bởi @nguyenvanhieuvn
  Thực hành nhiều ##Bài tập hơn tại https://luyencode.net/
*/

#include<stdio.h>
#include<conio.h>

int main()
{
    for(int i = 1; i <= 10; ++i)
    {
        for(int j = 2; j <= 9; ++j)
        {
            printf("%c %d x %2d = %2d", 179, j, i, i * j);
        }
        printf("%c\n", 179);
    }

    getch();
    return 0;
}
