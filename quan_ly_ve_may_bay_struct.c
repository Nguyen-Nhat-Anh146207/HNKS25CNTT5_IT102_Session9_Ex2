
#include <stdio.h>
#include <string.h>

int main() {
    struct FlightTicket {
        char pnrCode[15];
        char passengerName[50];
        int ticketClass;
        float baggageWeight;
        float baggageFee;
    };

    struct FlightTicket danhSachVe[100];

    int soLuong = 0;
    int luaChon;
    int i, j;
    int viTri;
    char pnrInput[15];

    do {
        printf("\n=== HE THONG BAN VE VA CHECK-IN MAY BAY ===\n");
        printf("1. Them ve may bay moi\n");
        printf("2. Hien thi danh sach ve\n");
        printf("3. Cap nhat hanh ly theo PNR\n");
        printf("4. Xoa ve theo PNR\n");
        printf("5. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {

            case 1:
                if (soLuong >= 100) {
                    printf("Danh sach ve da day, khong the them moi!\n");
                } else {
                    printf("\nNhap ma PNR: ");
                    scanf("%14s", danhSachVe[soLuong].pnrCode);
                    while (getchar() != '\n');
                    printf("Nhap ho ten hanh khach: ");
                    fgets(danhSachVe[soLuong].passengerName, sizeof(danhSachVe[soLuong].passengerName), stdin);

                    danhSachVe[soLuong].passengerName[strcspn(danhSachVe[soLuong].passengerName, "\n")] = '\0';

                    do {
                        printf("Nhap hang ve (1-Eco, 2-Deluxe, 3-Business): ");
                        scanf("%d", &danhSachVe[soLuong].ticketClass);

                        if (danhSachVe[soLuong].ticketClass < 1 || danhSachVe[soLuong].ticketClass > 3) {
                            printf("Hang ve khong hop le! Nhap lai.\n");
                        }
                    } while (danhSachVe[soLuong].ticketClass < 1 || danhSachVe[soLuong].ticketClass > 3);

                    printf("Nhap khoi luong hanh ly (kg): ");
                    scanf("%f", &danhSachVe[soLuong].baggageWeight);

                    while (getchar() != '\n');
                    if (danhSachVe[soLuong].ticketClass == 3) {
                        danhSachVe[soLuong].baggageFee = 0;
                    } else if (danhSachVe[soLuong].baggageWeight <= 7.0) {
                        danhSachVe[soLuong].baggageFee = 0;
                    } else {
                        danhSachVe[soLuong].baggageFee =
                            (danhSachVe[soLuong].baggageWeight - 7.0) * 50000;
                    }
                    soLuong++;
                    printf("Them ve thanh cong! Cuoc phat hanh ly: %.0f VND\n",
                           danhSachVe[soLuong - 1].baggageFee);
                }
                break;
            case 2:
                if (soLuong == 0) {
                    printf("Danh sach ve dang rong!\n");
                } else {
                    printf("\n================ DANH SACH VE MAY BAY ================\n");

                    printf("-------------------------------------------------------------------------------\n");
                    printf("%-5s %-15s %-25s %-12s %-15s %-15s\n",
                           "STT", "Ma PNR", "Ho ten hanh khach",
                           "Hang ve", "Hanh ly (kg)", "Cuoc (VND)");
                    printf("-------------------------------------------------------------------------------\n");

                    for (i = 0; i < soLuong; i++) {
                        char tenHangVe[15];

                        if (danhSachVe[i].ticketClass == 1) {
                            strcpy(tenHangVe, "Eco");
                        } else if (danhSachVe[i].ticketClass == 2) {
                            strcpy(tenHangVe, "Deluxe");
                        } else {
                            strcpy(tenHangVe, "Business");
                        }

                        printf("%-5d %-15s %-25s %-12s %-15.1f %-15.0f\n", i + 1, danhSachVe[i].pnrCode, danhSachVe[i].passengerName, tenHangVe, danhSachVe[i].baggageWeight, danhSachVe[i].baggageFee);
                    }

                    printf("-------------------------------------------------------------------------------\n");
                }
                break;

            case 3:
                if (soLuong == 0) {
                    printf("Danh sach ve dang rong!\n");
                } else {
                    printf("Nhap ma PNR can cap nhat hanh ly: ");
                    scanf("%14s", pnrInput);

                    viTri = -1;
                    for (i = 0; i < soLuong; i++) {
                        if (strcmp(danhSachVe[i].pnrCode, pnrInput) == 0) {
                            viTri = i;
                            break;
                        }
                    }

                    if (viTri == -1) {
                        printf("Khong tim thay ve co ma PNR da nhap!\n");
                    } else {
                        printf("Tim thay hanh khach: %s\n",
                               danhSachVe[viTri].passengerName);

                        printf("Nhap trong luong hanh ly moi (kg): ");
                        scanf("%f", &danhSachVe[viTri].baggageWeight);

                        while (getchar() != '\n');

                        if (danhSachVe[viTri].ticketClass == 3) {
                            danhSachVe[viTri].baggageFee = 0;
                        } else if (danhSachVe[viTri].baggageWeight <= 7.0) {
                            danhSachVe[viTri].baggageFee = 0;
                        } else {
                            danhSachVe[viTri].baggageFee =
                                (danhSachVe[viTri].baggageWeight - 7.0) * 50000;
                        }

                        printf("Cap nhat thanh cong! Phi moi: %.0f VND\n",
                               danhSachVe[viTri].baggageFee);
                    }
                }
                break;

            case 4:
                if (soLuong == 0) {
                    printf("Danh sach ve dang rong!\n");
                } else {
                    printf("Nhap ma PNR can xoa: ");
                    scanf("%14s", pnrInput);

                    viTri = -1;
                    for (i = 0; i < soLuong; i++) {
                        if (strcmp(danhSachVe[i].pnrCode, pnrInput) == 0) {
                            viTri = i;
                            break;
                        }
                    }

                    if (viTri == -1) {
                        printf("Khong tim thay ve co ma PNR da nhap!\n");
                    } else {
                        strcpy(pnrInput, danhSachVe[viTri].pnrCode);

                        for (j = viTri; j < soLuong - 1; j++) {
                            danhSachVe[j] = danhSachVe[j + 1];
                        }
                        soLuong--;
                        printf("Da xoa thanh cong ve co ma PNR: %s\n",
                               pnrInput);
                    }
                }
                break;
            case 5:
                printf("Cam on ban da su dung chuong trinh!\n");
                break;

            default:
                printf("Lua chon khong hop le! Vui long chon tu 1 den 5.\n");
        }

    } while (luaChon != 5);

    return 0;
}