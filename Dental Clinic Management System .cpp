#include<iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class User {
protected:
    string username, password, firstName, lastName, email, mobileNumber;
public:
    User() {}
    void setUser(string uname, string pwd, string fName, string lName, string mail, string mobile) {
        username = uname;
        password = pwd;
        firstName = fName;
        lastName = lName;
        email = mail;
        mobileNumber = mobile;
    }
    string getUsername() { return username; }
    virtual void displayInfo() = 0;
};

class Doctor : public User {
private:
    string specialization, availableDays, availableHours;
public:
    void setDoctor(string uname, string pwd, string fName, string lName, string mail, string mobile, string spec, string days, string hours) {
        setUser(uname, pwd, fName, lName, mail, mobile);
        specialization = spec;
        availableDays = days;
        availableHours = hours;
    }
    void displayInfo() {
        cout << "Doctor: " << firstName << " " << lastName << " | Specialization: " << specialization
             <<" | Mobile: " << mobileNumber << " | Available: " << availableDays << " " << availableHours << endl;
             cout<<"---------------------------------------------"<<endl;
    }
    string toFileString() {
        return username + " " + password + " " + firstName + " " + lastName + " " + email + " " +
               mobileNumber + " " + specialization + " " + availableDays + " " + availableHours;
    }
};

class Patient : public User {
private:
    int age, weight, height;
    string gender, bloodType;
public:
    void setPatient(string uname, string pwd, string fName, string lName, string mail, string mobile, int a, int w, int h, string gen, string blood) {
        setUser(uname, pwd, fName, lName, mail, mobile);
        age = a;
        weight = w;
        height = h;
        gender = gen;
        bloodType = blood;
    }
    void displayInfo() {
        cout << "Patient: " << firstName << " " << lastName << " | Age: " << age<<" | Mobile: " << mobileNumber 
             << " | Gender: " << gender << " | Blood Type: " << bloodType << endl;
             cout<<"---------------------------------------------"<<endl;
    }
    string toFileString() {
        return username + " " + password + " " + firstName + " " + lastName + " " + email + " " +
               mobileNumber + " " + intToString(age) + " " + intToString(weight) + " " + intToString(height) +
               " " + gender + " " + bloodType;
    }

    string intToString(int value) {
        stringstream ss;
        ss << value;
        return ss.str();
    }
};

class Prescription {
private:
    string patientUsername, doctorUsername, prescriptionDetails;
public:
    void createPrescription(string patientUser, string doctorUser, string details) {
        patientUsername = patientUser;
        doctorUsername = doctorUser;
        prescriptionDetails = details;
    }

    void displayPrescription() {
        cout << "Prescription for patient: " << patientUsername << " from Doctor: " << doctorUsername << "\nDetails: " << prescriptionDetails << endl;
        cout<<"---------------------------------------------"<<endl;
    }

    string toFileString() {
        return patientUsername + " " + doctorUsername + " " + prescriptionDetails;
    }
};


class Appointment {
private:
    string patientUsername, doctorUsername, date, time;
public:
    void setAppointment(string pUser, string dUser, string d, string t) {
        patientUsername = pUser;
        doctorUsername = dUser;
        date = d;
        time = t;
    }

    void displayAppointment() {
        cout << "Appointment: " << patientUsername << " with Doctor: " << doctorUsername
             << " on " << date << " at " << time << endl;
             cout<<"---------------------------------------------"<<endl;
    }

    string toFileString() {
        return patientUsername + " " + doctorUsername + " " + date + " " + time;
    }
};

class Payment {
private:
    string patientUsername, serviceName;
    int amountPaid;
public:
    void makePayment(string patientUser, string service, int amount) {
        patientUsername = patientUser;
        serviceName = service;
        amountPaid = amount;
    }

    void displayPayment() {
        cout << "Payment made by patient: " << patientUsername << " for service: " << serviceName << " Amount: $" << amountPaid << endl;
        cout<<"---------------------------------------------"<<endl;
    }

    string toFileString() {
        return patientUsername + " " + serviceName + " " + doubleToString(amountPaid);
    }

    string doubleToString(double value) {
        stringstream ss ;
        ss << value;
        return ss.str();
    }
};

class Inventory {
private:
    string itemName;
    int stock;
public:
    void addItem(string name, int quantity) {
        itemName = name;
        stock = quantity;
    }

    void displayItem() {
        cout << "Item: " << itemName << " | Stock: " << stock << endl;
        cout<<"---------------------------------------------"<<endl;
    }

    string toFileString() {
        return itemName + " " + intToString(stock);
    }

    string intToString(int value) {
        stringstream ss;
        ss << value;
        return ss.str();
    }
};

class DentalClinic {
private:
    Doctor doctors[5];
    Patient patients[5];
    Appointment appointments[5];
    Prescription prescriptions[5];
    Payment payments[5];
    Inventory inventory[5];
    int doctorCount, patientCount, appointmentCount, prescriptionCount, paymentCount, inventoryCount;

public:
    DentalClinic() : doctorCount(0), patientCount(0), appointmentCount(0), prescriptionCount(0), paymentCount(0), inventoryCount(0) {}

    void addDoctor(Doctor doc) {
        if (doctorCount < 5) doctors[doctorCount++] = doc;
    }

    void addPatient(Patient pat) {
        if (patientCount < 5) patients[patientCount++] = pat;
    }

    void addAppointment(Appointment app) {
        if (appointmentCount < 5) appointments[appointmentCount++] = app;
    }

    void addPrescription(Prescription pres) {
        if (prescriptionCount < 5) prescriptions[prescriptionCount++] = pres;
    }

    void addPayment(Payment pay) {
        if (paymentCount < 5) payments[paymentCount++] = pay;
    }

    void addInventoryItem(Inventory item) {
        if (inventoryCount < 5) inventory[inventoryCount++] = item;
    }

    void displayAll() {
        cout << "\n--- Doctors ---\n";
        for (int i = 0; i < doctorCount; i++) doctors[i].displayInfo();

        cout << "\n--- Patients ---\n";
        for (int i = 0; i < patientCount; i++) patients[i].displayInfo();

        cout << "\n--- Appointments ---\n";
        for (int i = 0; i < appointmentCount; i++) appointments[i].displayAppointment();

        cout << "\n--- Prescriptions ---\n";
        for (int i = 0; i < prescriptionCount; i++) prescriptions[i].displayPrescription();

        cout << "\n--- Payments ---\n";
        for (int i = 0; i < paymentCount; i++) payments[i].displayPayment();

        cout << "\n--- Inventory ---\n";
        for (int i = 0; i < inventoryCount; i++) inventory[i].displayItem();
    }

    void saveDataToFile() {
        fstream out("clinic_data.txt",ios::out);

        out << doctorCount << endl;
        for (int i = 0; i < doctorCount; i++) {
            out << doctors[i].toFileString() << endl;
        }

        out << patientCount << endl;
        for (int i = 0; i < patientCount; i++) {
            out << patients[i].toFileString() << endl;
        }

        out << appointmentCount << endl;
        for (int i = 0; i < appointmentCount; i++) {
            out << appointments[i].toFileString() << endl;
        }

        out << prescriptionCount << endl;
        for (int i = 0; i < prescriptionCount; i++) {
            out << prescriptions[i].toFileString() << endl;
        }

        out << paymentCount << endl;
        for (int i = 0; i < paymentCount; i++) {
            out << payments[i].toFileString() << endl;
        }

out << inventoryCount << endl;
        for (int i = 0; i < inventoryCount; i++) {
            out << inventory[i].toFileString() << endl;
        }

        out.close();
    }

    void loadDataFromFile() {
        fstream in("clinic_data.txt",ios::in);

        if (!in) {
            cout << "File not found. Starting with empty data.\n";
            return;
        }

        in >> doctorCount;
        in.ignore(); 
        for (int i = 0; i < doctorCount; i++) {
            string uname, pwd, fName, lName, mail, mobile, spec, days, hours;
            in >> uname >> pwd >> fName >> lName >> mail >> mobile >> spec >> days >> hours;
            doctors[i].setDoctor(uname, pwd, fName, lName, mail, mobile, spec, days, hours);
        }

        in >> patientCount;
        in.ignore();
        for (int i = 0; i < patientCount; i++) {
            string uname, pwd, fName, lName, mail, mobile, gen, blood;
            int age, weight, height;
            in >> uname >> pwd >> fName >> lName >> mail >> mobile >> age >> weight >> height >> gen >> blood;
            patients[i].setPatient(uname, pwd, fName, lName, mail, mobile, age, weight, height, gen, blood);
        }

        in >> appointmentCount;
        in.ignore();
        for (int i = 0; i < appointmentCount; i++) {
            string pUser, dUser, date, time;
            in >> pUser >> dUser >> date >> time;
            appointments[i].setAppointment(pUser, dUser, date, time);
        }

        in >> prescriptionCount;
        in.ignore();
        for (int i = 0; i < prescriptionCount; i++) {
            string pUser, dUser, details;
            in >> pUser >> dUser;
            getline(in, details);
            prescriptions[i].createPrescription(pUser, dUser, details);
        }

        in >> paymentCount;
        in.ignore();
        for (int i = 0; i < paymentCount; i++) {
            string pUser, service;
            double amount;
            in >> pUser >> service >> amount;
            payments[i].makePayment(pUser, service, amount);
        }

        in >> inventoryCount;
        in.ignore();
        for (int i = 0; i < inventoryCount; i++) {
            string itemName;
            int stock;
            in >> itemName >> stock;
            inventory[i].addItem(itemName, stock);
        }

        in.close();
    }
};

int main() {
    DentalClinic clinic;

clinic.loadDataFromFile();
//Add Doctors
    Doctor doc1;
    doc1.setDoctor("doc1", "123", "Ahmed", "Ali", "ahmed@mail.com", "01234567890", "Orthodontics", "Mon-Fri", "9am-5pm");
    clinic.addDoctor(doc1);
    
    Doctor doc2;
    doc2.setDoctor("doc2", "1234", "Alaa", "Zaki", "alaa@mail.com", "01235566890", "Maxillofacial", "Sat-Mon", "9am-5pm");
    clinic.addDoctor(doc2);
    
    Doctor doc3;
    doc3.setDoctor("doc3", "1223", "Mahmoud", "Ali", "mahmoud@mail.com", "01234567890", "Padiatric", "Tue-Thu", "7pm-11pm");
    clinic.addDoctor(doc3);
    
    Doctor doc4;
    doc4.setDoctor("doc4", "11223", "Ahmed", "Abdulrahman", "ahmed.a@mail.com", "01234567890", "Endontics", "Fri", "1pm-9pm");
    clinic.addDoctor(doc4);
    
    Doctor doc5;
    doc5.setDoctor("doc5", "12333", "Nour", "Mohmmed", "nour@mail.com", "01234567890", "Cosmetic", "Wed", "10am-2pm");
    clinic.addDoctor(doc5);
//Add patient
    Patient pat1;
    pat1.setPatient("pat1", "456", "Lujain", "Sameh", "logen@mail.com", "01041593867", 20, 65, 165, "Female", "A+");
    clinic.addPatient(pat1);
    
    Patient pat2;
    pat2.setPatient("pat2", "4456", "Omar", "Kamal", "omar@mail.com", "01041582867", 30, 70, 165, "Male", "O+");
    clinic.addPatient(pat2);
    
    Patient pat3;
    pat3.setPatient("pat3", "4556", "Zeyad", "Saeed", "zeyad@mail.com", "01291593867", 8, 40, 125, "Male", "AB+");
    clinic.addPatient(pat3);
    
    Patient pat4;
    pat4.setPatient("pat4", "4566", "Mohmed", "Ahmed", "mo@mail.com", "01191593867", 30, 70, 185, "Male", "A-");
    clinic.addPatient(pat4);
    
    Patient pat5;
    pat5.setPatient("pat5", "44566", "Laila", "Khaled", "laila@mail.com", "0155593867", 40, 85, 170, "Female", "B+");
    clinic.addPatient(pat5);
//Add Appointment
    Appointment app1;
    app1.setAppointment("pat1", "doc4", "2024-12-18", "02:00pm");
    clinic.addAppointment(app1);
    
    Appointment app2;
    app2.setAppointment("pat2", "doc1", "2025-01-16", "10:00am");
    clinic.addAppointment(app2);
    
    Appointment app3;
    app3.setAppointment("pat3", "doc3", "2024-11-18", "08:00pm");
    clinic.addAppointment(app3);
    
    Appointment app4;
    app4.setAppointment("pat4", "doc5", "2024-12-29", "12:00pm");
    clinic.addAppointment(app4);
    
    Appointment app5;
    app5.setAppointment("pat5", "doc2", "2025-01-30", "10:00am");
    clinic.addAppointment(app5);
//Add  Prescription
    Prescription pre1;
    pre1.createPrescription("pat1 ","Doc4 ","Crown placement in 2 weeks");
    clinic.addPrescription(pre1);
    
    Prescription pre2;
    pre2.createPrescription("pat2 ","Doc1 ","Monthly adjustments");
    clinic.addPrescription(pre2);
    
    Prescription pre3;
    pre3.createPrescription("pat3 ","Doc3 ","Routine check-up in 6 months");
    clinic.addPrescription(pre3);
    
    Prescription pre4;
    pre4.createPrescription("pat4 ","Doc5 ","Avoid staining foods/drinks for 48 hours");
    clinic.addPrescription(pre4);
    
    Prescription pre5;
    pre5.createPrescription("pat5 ","Doc2 ","7 days post-surgery");
    clinic.addPrescription(pre5);
//Add Payment
    Payment pay1;
    pay1.makePayment("pat1", "Retreatment of failed root canals", 500);
    clinic.addPayment(pay1);
    
    Payment pay2;
    pay2.makePayment("pat2", "Correction of malocclusion and jaw alignment issues", 360);
    clinic.addPayment(pay2);
    
    Payment pay3;
    pay3.makePayment("pat3", "Early orthodontic assessments and space maintainers", 700);
    clinic.addPayment(pay3);
    
    Payment pay4;
    pay4.makePayment("pat4", "Smile makeovers, including gum contouring", 1500);
    clinic.addPayment(pay4);
    
    Payment pay5;
    pay5.makePayment("pat5", "Surgical correction of jaw misalignment ", 2000);
    clinic.addPayment(pay5);
//Add inventory
    Inventory inv1;
    inv1.addItem("Dental Gloves", 100);
    clinic.addInventoryItem(inv1);
    
    Inventory inv2;
    inv2.addItem("Endodontic Files", 20);
    clinic.addInventoryItem(inv2);
    
    Inventory inv3;
    inv3.addItem("Patient Bibs", 70);
    clinic.addInventoryItem(inv3);

	Inventory inv4;
    inv4.addItem("Fluoride Trays and Gel", 10);
    clinic.addInventoryItem(inv4);
    
    Inventory inv5;
    inv5.addItem("Dental Mirrors", 50);
    clinic.addInventoryItem(inv5);

    clinic.displayAll();

    clinic.saveDataToFile();
}
