//
// Created by Gbrigens on 1/11/22.
//

#ifndef LANDLORDPROJECT_LANDLORD_H
#define LANDLORDPROJECT_LANDLORD_H
#define landlord_h
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;
//////////////////////////global  methods///////////////////////
void getaLine(string& inStr);   // get line of text
char getaChar();                // get a character
///////////////////////////class Tenant/////////////////////////
class Tenant
{
private:
    string name;    // tenant’s name
    int aptNumber;  // tenant’s apartment number
    // other Tenant information (phone, etc.) could go here
public:
    Tenant(string n, int aNo);
    ~Tenant();
    int getAptNumber();
    // needed for use in ‘set’
    friend bool operator < (const Tenant&, const Tenant&);
    friend bool operator == (const Tenant&, const Tenant&);
    // for I/O
    friend ostream& operator << (ostream&, const Tenant&);
};  // end class Tenant
///////////////////////class CompareTenants/////////////////////
class CompareTenants  //function object --  compares tenants
{
public:
    bool operator () (Tenant*, Tenant*) const;
};
////////////////////////class TenantList////////////////////////
class TenantList
{
private:
    // set of pointers to tenants
    set<Tenant*, CompareTenants> setPtrsTens;
    set<Tenant*, CompareTenants>::iterator iter;
public:
    ~TenantList();               // destructor (deletes tenants)
    void insertTenant(Tenant*);  // put Tenant on list
    int getAptNo(string);        // return apartment number
    void display();              // display Tenant list
};  // end class TenantList
/////////////////////class TenantInputScreen////////////////////
class TenantInputScreen
{
private:
    TenantList* ptrTenantList;
    string tName;
    int aptNo;
public:
    TenantInputScreen(TenantList* ptrTL) : ptrTenantList(ptrTL)
    { /* empty */ }
    void getTenant();
};  //end class TenantInputScreen
//////////////////////////class RentRow/////////////////////////
// one row of the rent record: an address and 12 rent amounts
class RentRow
{
private:
    int aptNo;
    float rent[12];
public:
    RentRow(int);
    void setRent(int, float);
    float getSumOfRow();
    // needed to store in ‘set’
    friend bool operator < (const RentRow&, const RentRow&);
    friend bool operator == (const RentRow&, const RentRow&);
    // for output
    friend ostream& operator << (ostream&, const RentRow&);
};  // end class RentRow
////////////////////////////////////////////////////////////////
class CompareRows  //function object --  compares RentRows
{ public:
    bool operator () (RentRow*, RentRow*) const;
};
/////////////////////////class RentRecord///////////////////////
class RentRecord
{
private:
    // set of pointers to RentRow objects (one per Tenant)
    set<RentRow*, CompareRows> setPtrsRR;
    set<RentRow*, CompareRows>::iterator iter;
public:
    ~RentRecord();
    void insertRent(int, int, float);
    void display();
    float getSumOfRents();        // sum all rents in record
};  // end class RentRecord
/////////////////////////class RentInputScreen//////////////////
class RentInputScreen
{
private:
    TenantList* ptrTenantList;
    RentRecord* ptrRentRecord;
    string renterName;
    float rentPaid;
    int month;
    int aptNo;
public:
    RentInputScreen(TenantList* ptrTL, RentRecord* ptrRR) :
    ptrTenantList(ptrTL), ptrRentRecord(ptrRR)
    { /*empty*/ }
    void getRent();           //rent for one Tenant and one month
};  // end class RentInputScreen
////////////////////////////class Expense///////////////////////
class Expense
{
public:
    int month, day;
    string category, payee;
    float amount;
    Expense()
    {}
    Expense(int m, int d, string c, string p, float a) :
    month(m), day(d), category(c), payee(p), amount(a)
    { /*empty */ }
    // needed for use in ‘set’
    friend bool operator < (const Expense&, const Expense&);
    friend bool operator == (const Expense&, const Expense&);
    // needed for output
    friend ostream& operator << (ostream&, const Expense&);
};  // end class Expense
////////////////////////////////////////////////////////////////
class CompareDates  //function object--compares Expenses
{ public:
    bool operator () (Expense*, Expense*) const;
};
////////////////////////////////////////////////////////////////
class CompareCategories  //function object--compares Expenses
{ public:
    bool operator () (Expense*, Expense*) const;
};
////////////////////////class ExpenseRecord/////////////////////
class ExpenseRecord
{
private:
    // vector of pointers to Expenses
    vector<Expense*> vectPtrsExpenses;
    vector<Expense*>::iterator iter;
public:
    ~ExpenseRecord();
    void insertExp(Expense*);
    void display();
    float displaySummary(); // used by AnnualReport
};  // end class ExpenseRecord

/////////////////////class ExpenseInputScreen///////////////////
class ExpenseInputScreen
{
private:
    ExpenseRecord* ptrExpenseRecord;
public:
    ExpenseInputScreen(ExpenseRecord*);
    void getExpense();
};  // end class ExpenseInputScreen
///////////////////////class AnnualReport///////////////////////
class AnnualReport
{
private:
    RentRecord* ptrRR;
    ExpenseRecord* ptrER;
    float Expenses, rents;
public:
    AnnualReport(RentRecord*, ExpenseRecord*);
    void display();
};  // end class AnnualReport


///////////////////////class UserInterface//////////////////////
class UserInterface {
private:
    TenantList* ptrTenantList;
    TenantInputScreen* ptrTenantInputScreen;
    RentRecord* ptrRentRecord;
    RentInputScreen* ptrRentInputScreen;
    ExpenseRecord* ptrExpenseRecord;
    ExpenseInputScreen*  ptrExpenseInputScreen;
    AnnualReport*        ptrAnnualReport;
    char ch;
public:
    UserInterface();
    ~UserInterface();
    void interact();
};  // end class UserInterface
//////////////////////////end file landlord.h//////////////////////

#endif //LANDLORDPROJECT_LANDLORD_H

