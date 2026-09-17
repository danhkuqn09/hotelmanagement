#include "Hotel.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <limits>


using namespace std;


// ==========================================
// MAIN MENU
// ==========================================

void Hotel::mainMenu()
{
    int choice;

    do
    {
        cout << "\n";
        cout << "==================================================\n";
        cout << "              HOTEL RESERVATION SYSTEM\n";
        cout << "==================================================\n\n";

        cout << "1. Quan ly phong\n";
        cout << "2. Quan ly khach hang\n";
        cout << "3. Dat phong\n";
        cout << "4. Tra phong\n";
        cout << "5. Quan ly dich vu\n";
        cout << "6. Quan ly hoa don\n";
        cout << "7. Tim kiem thong tin\n";
        cout << "8. Bao cao - Thong ke\n";
        cout << "9. Luu du lieu\n";
        cout << "0. Thoat\n";

        cout << "\n==================================================\n";
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            roomMenu();
            break;

        case 2:
            customerMenu();
            break;

        case 3:
            addBooking();
            break;

        case 4:
            checkout();
            break;

        case 5:
            serviceMenu();
            break;

        case 6:
            showInvoices();
            break;

        case 7:
            searchMenu();
            break;

        case 8:
            reportMenu();
            break;

        case 9:
            saveData();
            cout << "\nDa luu du lieu thanh cong!\n";
            break;

        case 0:
            saveData();
            cout << "\nDa luu du lieu. Tam biet!\n";
            break;

        default:
            cout << "\nLua chon khong hop le!\n";
        }

    } while (choice != 0);
}

// ==========================================
// ROOM MENU
// ==========================================

void Hotel::roomMenu() {

    int choice;

    do {
        cout << "\n";
        cout << "========== ROOM MANAGEMENT ==========\n";
        cout << "1. Them phong\n";
        cout << "2. Xoa phong\n";
        cout << "3. Sua phong\n";
        cout << "4. Xem danh sach phong\n";
        cout << "0. Quay lai\n";

        cout << "Lua chon: ";
        cin >> choice;

        switch (choice) {

        case 1:
            addRoom();
            break;

        case 2:
            deleteRoom();
            break;

        case 3:
            updateRoom();
            break;

        case 4:
            showRooms();
            break;

        case 0:
            break;

        default:
            cout << "Lua chon khong hop le!\n";
        }

    } while (choice != 0);
}


// ==========================================
// CUSTOMER MENU
// ==========================================

void Hotel::customerMenu() {

    int choice;

    do {
        cout << "\n";
        cout << "======= CUSTOMER MANAGEMENT =======\n";
        cout << "1. Them khach hang\n";
        cout << "2. Xoa khach hang\n";
        cout << "3. Sua khach hang\n";
        cout << "4. Xem danh sach khach hang\n";
        cout << "0. Quay lai\n";

        cout << "Lua chon: ";
        cin >> choice;

        switch (choice) {

        case 1:
            addCustomer();
            break;

        case 2:
            deleteCustomer();
            break;

        case 3:
            updateCustomer();
            break;

        case 4:
            showCustomers();
            break;

        case 0:
            break;

        default:
            cout << "Lua chon khong hop le!\n";
        }

    } while (choice != 0);
}


// ==========================================
// ADD ROOM
// ==========================================

void Hotel::addRoom() {

    string id;
    string type;
    double price;

    cout << "\n========== THEM PHONG ==========\n";

    cout << "Nhap ma phong: ";
    cin >> id;

    // Kiem tra trung ID
    for (const Room& room : rooms) {

        if (room.getRoomId() == id) {
            cout << "Ma phong da ton tai!\n";
            return;
        }
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Nhap loai phong: ";
    getline(cin, type);

    cout << "Nhap gia phong: ";
    cin >> price;

    Room room(
        id,
        type,
        price,
        "AVAILABLE"
    );

    rooms.push_back(room);

    saveData();

    cout << "Them phong thanh cong!\n";
}


// ==========================================
// DELETE ROOM
// ==========================================

void Hotel::deleteRoom() {

    string id;

    cout << "\n========== XOA PHONG ==========\n";

    cout << "Nhap ma phong can xoa: ";
    cin >> id;

    for (size_t i = 0; i < rooms.size(); i++) {

        if (rooms[i].getRoomId() == id) {

            rooms.erase(rooms.begin() + i);

            saveData();

            cout << "Xoa phong thanh cong!\n";

            return;
        }
    }

    cout << "Khong tim thay phong!\n";
}


// ==========================================
// UPDATE ROOM
// ==========================================

void Hotel::updateRoom() {

    string id;

    cout << "\n========== SUA PHONG ==========\n";

    cout << "Nhap ma phong can sua: ";
    cin >> id;

    for (int i = 0; i < rooms.size(); i++) {

        if (rooms[i].getRoomId() == id) {

            string type;
            double price;
            string status;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Nhap loai phong moi: ";
            getline(cin, type);

            cout << "Nhap gia phong moi: ";
            cin >> price;

            cout << "Nhap trang thai (AVAILABLE/OCCUPIED): ";
            cin >> status;

            rooms[i].setRoomType(type);
            rooms[i].setPrice(price);
            rooms[i].setStatus(status);

            saveData();

            cout << "Cap nhat phong thanh cong!\n";

            return;
        }
    }

    cout << "Khong tim thay phong!\n";
}


// ==========================================
// SHOW ROOMS
// ==========================================

void Hotel::showRooms() {

    cout << "\n";
    cout << "================ DANH SACH PHONG ================\n";

    if (rooms.empty()) {
        cout << "Chua co phong nao!\n";
        return;
    }

    cout << left
        << setw(12) << "Ma phong"
        << setw(20) << "Loai phong"
        << setw(15) << "Gia"
        << setw(15) << "Trang thai"
        << endl;

    cout << "-------------------------------------------------------------\n";

    for (const Room& room : rooms) {
        room.display();
    }
}


// ==========================================
// ADD CUSTOMER
// ==========================================

void Hotel::addCustomer() {

    string id;
    string name;
    string phone;

    cout << "\n========== THEM KHACH HANG ==========\n";

    cout << "Nhap ma khach hang: ";
    cin >> id;

    for (const Customer& customer : customers) {

        if (customer.getCustomerId() == id) {
            cout << "Ma khach hang da ton tai!\n";
            return;
        }
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Nhap ten khach hang: ";
    getline(cin, name);

    cout << "Nhap so dien thoai: ";
    getline(cin, phone);

    Customer customer(
        id,
        name,
        phone
    );

    customers.push_back(customer);

    saveData();

    cout << "Them khach hang thanh cong!\n";
}


// ==========================================
// DELETE CUSTOMER
// ==========================================

void Hotel::deleteCustomer() {

    string id;

    cout << "\n========== XOA KHACH HANG ==========\n";

    cout << "Nhap ma khach hang can xoa: ";
    cin >> id;

    for (size_t i = 0; i < customers.size(); i++) {

        if (customers[i].getCustomerId() == id) {

            customers.erase(customers.begin() + i);

            saveData();

            cout << "Xoa khach hang thanh cong!\n";

            return;
        }
    }

    cout << "Khong tim thay khach hang!\n";
}


// ==========================================
// UPDATE CUSTOMER
// ==========================================

void Hotel::updateCustomer() {

    string id;

    cout << "\n========== SUA KHACH HANG ==========\n";

    cout << "Nhap ma khach hang can sua: ";
    cin >> id;

    for (int i = 0; i < customers.size(); i++) {

        if (customers[i].getCustomerId() == id) {

            string name;
            string phone;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Nhap ten moi: ";
            getline(cin, name);

            cout << "Nhap so dien thoai moi: ";
            getline(cin, phone);

            customers[i].setName(name);
            customers[i].setPhone(phone);

            saveData();

            cout << "Cap nhat khach hang thanh cong!\n";

            return;
        }
    }

    cout << "Khong tim thay khach hang!\n";
}


// ==========================================
// SHOW CUSTOMERS
// ==========================================

void Hotel::showCustomers() {

    cout << "\n";
    cout << "=============== DANH SACH KHACH HANG ===============\n";

    if (customers.empty()) {
        cout << "Chua co khach hang nao!\n";
        return;
    }

    cout << left
        << setw(15) << "Ma KH"
        << setw(30) << "Ten khach hang"
        << setw(15) << "So dien thoai"
        << endl;

    cout << "------------------------------------------------------------\n";

    for (const Customer& customer : customers) {
        customer.display();
    }
}


// ==========================================
// SAVE DATA
// ==========================================

void Hotel::saveData() {

    ofstream file("data.txt");

    if (!file.is_open()) {
        cout << "Khong mo duoc file data.txt!\n";
        return;
    }

    // ================= ROOM =================

    file << "[ROOM]\n";

    for (const Room& room : rooms) {

        file << room.getRoomId() << "|"
            << room.getRoomType() << "|"
            << room.getPrice() << "|"
            << room.getStatus()
            << "\n";
    }


    // ================= CUSTOMER =================

    file << "[CUSTOMER]\n";

    for (const Customer& customer : customers) {

        file << customer.getCustomerId() << "|"
            << customer.getName() << "|"
            << customer.getPhone()
            << "\n";
    }


    // ================= BOOKING =================

    file << "[BOOKING]\n";
    for (const Booking& booking : bookings) {

        file << booking.getBookingId() << "|"
            << booking.getCustomerId() << "|"
            << booking.getRoomId() << "|"
            << booking.getCheckIn() << "|"
            << booking.getCheckOut() << "|"
            << booking.getStatus()
            << "\n";
    }

    file.close();
}


// ==========================================
// LOAD DATA
// ==========================================

void Hotel::loadData() {

    ifstream file("data.txt");

    if (!file.is_open()) {

        // Neu file chua ton tai thi khong sao
        return;
    }

    rooms.clear();
    customers.clear();
    bookings.clear();

    string line;
    string section = "";

    while (getline(file, line)) {

        if (line.empty()) {
            continue;
        }

        // Xac dinh section
        if (line == "[ROOM]") {
            section = "ROOM";
            continue;
        }

        if (line == "[CUSTOMER]") {
            section = "CUSTOMER";
            continue;
        }

        if (line == "[BOOKING]") {
            section = "BOOKING";
            continue;
        }


        // =====================================
        // LOAD ROOM
        // =====================================

        if (section == "ROOM") {

            stringstream ss(line);

            string id;
            string type;
            string priceString;
            string status;

            getline(ss, id, '|');
            getline(ss, type, '|');
            getline(ss, priceString, '|');
            getline(ss, status);

            double price = stod(priceString);

            rooms.push_back(
                Room(id, type, price, status)
            );
        }


        // =====================================
        // LOAD CUSTOMER
        // =====================================

        else if (section == "CUSTOMER") {

            stringstream ss(line);

            string id;
            string name;
            string phone;

            getline(ss, id, '|');
            getline(ss, name, '|');
            getline(ss, phone);

            customers.push_back(
                Customer(id, name, phone)
            );
        }


        // =====================================
        // LOAD BOOKING
        // =====================================

        else if (section == "BOOKING") {

            stringstream ss(line);

            string bookingId;
            string customerId;
            string roomId;
            string checkIn;
            string checkOut;
            string status;

            getline(ss, bookingId, '|');
            getline(ss, customerId, '|');
            getline(ss, roomId, '|');
            getline(ss, checkIn, '|');
            getline(ss, checkOut, '|');
            getline(ss, status);

            bookings.push_back(
                Booking(
                    bookingId,
                    customerId,
                    roomId,
                    checkIn,
                    checkOut,
                    status
                )
            );
        }
    }

    file.close();
}
// ==========================================
// BOOKING MANAGEMENT MENU
// ==========================================

void Hotel::bookingMenu() {

    int choice;

    do {

        cout << "\n";
        cout << "=================================================\n";
        cout << "              QUAN LY DAT PHONG\n";
        cout << "=================================================\n";
        cout << "1. Dat phong\n";
        cout << "2. Tra phong\n";
        cout << "3. Thanh toan\n";
        cout << "4. Danh sach dat phong\n";
        cout << "5. Phong dang su dung\n";
        cout << "6. Hoa don\n";
        cout << "0. Quay lai\n";
        cout << "=================================================\n";

        cout << "Lua chon: ";
        cin >> choice;

        switch (choice) {

        case 1:
            addBooking();
            break;

        case 2:
            checkout();
            break;

        case 3:
            payment();
            break;

        case 4:
            showBookings();
            break;

        case 5:
            showUsingRooms();
            break;

        case 6:
            showInvoices();
            break;

        case 0:
            break;

        default:
            cout << "Lua chon khong hop le!\n";
        }

    } while (choice != 0);
}




void Hotel::addBooking()
{
    string customerId;
    string roomId;
    string checkIn;
    string checkOut;

    cout << "\n";
    cout << "---------------- DAT PHONG ----------------\n";

    // Nhap ma khach hang
    cout << "Ma khach hang: ";
    cin >> customerId;

    // Kiem tra khach hang
    bool customerFound = false;

    for (const Customer& customer : customers)
    {
        if (customer.getCustomerId() == customerId)
        {
            customerFound = true;
            break;
        }
    }

    if (!customerFound)
    {
        cout << "\nKhong tim thay khach hang!\n";
        return;
    }

    // Nhap ma phong
    cout << "Ma phong: ";
    cin >> roomId;

    // Kiem tra phong
    bool roomFound = false;

    for (Room& room : rooms)
    {
        if (room.getRoomId() == roomId)
        {
            roomFound = true;

            if (room.getStatus() == "OCCUPIED")
            {
                cout << "\nPhong nay dang duoc su dung!\n";
                return;
            }

            break;
        }
    }

    if (!roomFound)
    {
        cout << "\nKhong tim thay phong!\n";
        return;
    }

    // Nhap ngay
    cout << "Ngay nhan phong: ";
    cin >> checkIn;

    cout << "Ngay tra phong: ";
    cin >> checkOut;

    // Tu dong tao ma dat phong
    string bookingId = "DP" + to_string(bookings.size() + 1);

    // Tao booking
    Booking newBooking(
        bookingId,
        customerId,
        roomId,
        checkIn,
        checkOut,
        "BOOKED"
    );

    bookings.push_back(newBooking);

    // Cap nhat trang thai phong
    for (Room& room : rooms)
    {
        if (room.getRoomId() == roomId)
        {
            room.setStatus("OCCUPIED");
            break;
        }
    }

    cout << "\nDat phong thanh cong!\n";
    cout << "Ma dat phong: " << bookingId << endl;
}

// ==========================================
// SHOW BOOKINGS
// ==========================================

void Hotel::showBookings() {

    cout << "\n========== DANH SACH DAT PHONG ==========\n";

    if (bookings.empty()) {
        cout << "Chua co du lieu dat phong!\n";
        return;
    }

    cout << left
        << setw(12) << "Ma DP"
        << setw(12) << "Ma KH"
        << setw(12) << "Ma phong"
        << setw(15) << "Check In"
        << setw(15) << "Check Out"
        << setw(15) << "Trang thai"
        << endl;

    for (const Booking& booking : bookings) {
        booking.display();
    }
}

// ==========================================
// CHECKOUT
// ==========================================

void Hotel::checkout()
{
    string bookingId;

    cout << "\n";
    cout << "---------------- TRA PHONG ----------------\n";
    cout << "Ma dat phong: ";
    cin >> bookingId;

    bool found = false;

    for (Booking& booking : bookings)
    {
        if (booking.getBookingId() == bookingId)
        {
            found = true;

            // Kiem tra booking da tra phong chua
            if (booking.getStatus() == "CHECKEDOUT")
            {
                cout << "\nDat phong nay da duoc tra!\n";
                return;
            }

            // Cap nhat trang thai booking
            booking.setStatus("CHECKEDOUT");

            // Lay ma phong
            string roomId = booking.getRoomId();

            // Cap nhat trang thai phong
            for (Room& room : rooms)
            {
                if (room.getRoomId() == roomId)
                {
                    room.setStatus("AVAILABLE");
                    break;
                }
            }

            cout << "\nTra phong thanh cong!\n";
            cout << "Ma dat phong: " << bookingId << endl;
            cout << "Ma phong: " << roomId << endl;

            break;
        }
    }

    if (!found)
    {
        cout << "\nKhong tim thay ma dat phong!\n";
    }
}

// ==========================================
// SHOW USING ROOMS
// ==========================================

void Hotel::showUsingRooms() {

    cout << "\n========== PHONG DANG SU DUNG ==========\n";

    bool found = false;

    for (const Booking& booking : bookings) {

        if (booking.getStatus() == "USING") {

            cout << left
                << setw(12) << booking.getBookingId()
                << setw(12) << booking.getCustomerId()
                << setw(12) << booking.getRoomId()
                << setw(15) << booking.getCheckIn()
                << setw(15) << booking.getCheckOut()
                << endl;

            found = true;
        }
    }

    if (!found) {
        cout << "Khong co phong nao dang su dung.\n";
    }
}

// ==========================================
// PAYMENT
// ==========================================

void Hotel::payment() {

    string bookingId;

    cout << "\nNhap ma dat phong: ";
    cin >> bookingId;

    for (const Booking& booking : bookings) {

        if (booking.getBookingId() == bookingId) {

            for (const Room& room : rooms) {

                if (room.getRoomId() == booking.getRoomId()) {

                    cout << "\n========== HOA DON ==========\n";

                    cout << "Ma dat phong : "
                        << booking.getBookingId()
                        << endl;

                    cout << "Ma phong     : "
                        << booking.getRoomId()
                        << endl;

                    cout << "Gia phong    : "
                        << room.getPrice()
                        << endl;

                    cout << "Tong tien    : "
                        << room.getPrice()
                        << endl;

                    return;
                }
            }
        }
    }

    cout << "Khong tim thay dat phong!\n";
}

// ==========================================
// SHOW INVOICES
// ==========================================

void Hotel::showInvoices() {

    cout << "\n========== DANH SACH HOA DON ==========\n";

    bool found = false;

    for (const Booking& booking : bookings) {

        if (booking.getStatus() == "CHECKEDOUT") {

            for (const Room& room : rooms) {

                if (room.getRoomId() == booking.getRoomId()) {

                    cout << "Ma DP: "
                        << booking.getBookingId()
                        << " | Ma phong: "
                        << booking.getRoomId()
                        << " | So tien: "
                        << room.getPrice()
                        << endl;

                    found = true;
                }
            }
        }
    }

    if (!found) {
        cout << "Chua co hoa don nao.\n";
    }
}
/// <summary>
/// //
/// </summary>
void Hotel::searchMenu()
{
    int choice;

    do
    {
        cout << "\n";
        cout << "================ TIM KIEM THONG TIN ================\n";
        cout << "1. Tim phong\n";
        cout << "2. Tim khach hang\n";
        cout << "3. Tim dat phong\n";
        cout << "0. Quay lai\n";
        cout << "=====================================================\n";
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            searchRoom();
            break;

        case 2:
            searchCustomer();
            break;

        case 3:
            searchBooking();
            break;

        case 0:
            break;

        default:
            cout << "Lua chon khong hop le!\n";
        }

    } while (choice != 0);
}
////
void Hotel::searchRoom()
{
    string id;

    cout << "\n---------------- TIM PHONG ----------------\n";
    cout << "Nhap ma phong: ";
    cin >> id;

    bool found = false;

    for (const Room& room : rooms)
    {
        if (room.getRoomId() == id)
        {
            cout << "\nTim thay phong:\n";
            room.display();
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "\nKhong tim thay phong!\n";
    }
}
///
void Hotel::searchCustomer()
{
    string id;

    cout << "\n------------- TIM KHACH HANG -------------\n";
    cout << "Nhap ma khach hang: ";
    cin >> id;

    bool found = false;

    for (const Customer& customer : customers)
    {
        if (customer.getCustomerId() == id)
        {
            cout << "\nTim thay khach hang:\n";
            customer.display();
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "\nKhong tim thay khach hang!\n";
    }
}
///
void Hotel::searchBooking()
{
    string id;

    cout << "\n-------------- TIM DAT PHONG --------------\n";
    cout << "Nhap ma dat phong: ";
    cin >> id;

    bool found = false;

    for (const Booking& booking : bookings)
    {
        if (booking.getBookingId() == id)
        {
            cout << "\nTim thay dat phong:\n";
            booking.display();
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "\nKhong tim thay dat phong!\n";
    }
}
// ==========================================
// REPORT MENU
// ==========================================
void Hotel::serviceMenu()
{
    int choice;

    do
    {
        cout << "\n";
        cout << "---------------- QUAN LY DICH VU ----------------\n";
        cout << "1. Them dich vu\n";
        cout << "2. Sua dich vu\n";
        cout << "3. Xoa dich vu\n";
        cout << "4. Xem danh sach dich vu\n";
        cout << "0. Quay lai\n";
        cout << "--------------------------------------------------\n";
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nChuc nang them dich vu se duoc lam o buoc tiep theo.\n";
            break;

        case 2:
            cout << "\nChuc nang sua dich vu se duoc lam o buoc tiep theo.\n";
            break;

        case 3:
            cout << "\nChuc nang xoa dich vu se duoc lam o buoc tiep theo.\n";
            break;

        case 4:
            showServices();
            break;

        case 0:
            break;

        default:
            cout << "\nLua chon khong hop le!\n";
        }

    } while (choice != 0);
}
void Hotel::showServices()
{
    cout << "\n";
    cout << "---------------- DANH SACH DICH VU ----------------\n";

    if (services.empty())
    {
        cout << "Chua co dich vu nao.\n";
        return;
    }

    cout << "Ma dich vu | Ten dich vu | Don gia\n";
    cout << "-----------------------------------------------\n";

    for (const Service& service : services)
    {
        service.display();
    }
}

void Hotel::reportMenu() {

    int choice;

    do {

        cout << "\n";
        cout << "=================================================\n";
        cout << "             BAO CAO - THONG KE\n";
        cout << "=================================================\n";
        cout << "1. Danh sach phong\n";
        cout << "2. Danh sach khach hang\n";
        cout << "3. Danh sach dat phong\n";
        cout << "4. Phong dang su dung\n";
        cout << "5. Hoa don\n";
        cout << "0. Quay lai\n";
        cout << "=================================================\n";

        cout << "Lua chon: ";
        cin >> choice;

        switch (choice) {

        case 1:
            showRooms();
            break;

        case 2:
            showCustomers();
            break;

        case 3:
            showBookings();
            break;

        case 4:
            showUsingRooms();
            break;

        case 5:
            serviceMenu();
            break;

        case 0:
            break;

        default:
            cout << "Lua chon khong hop le!\n";
        }

    } while (choice != 0);

}