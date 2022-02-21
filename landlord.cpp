//
//  landlord.cpp
//  Landlord
//
//  Created by Gbrigens on 1/11/22.
//

//landlord.cpp
//models the finances for an apartment building
#include "landlord.h" //for class declarations, etc.

// Tenant Class

Tenant::Tenant(string n, int aNo) {
    name = n;
    aptNumber = aNo;
}

Tenant::~Tenant() {
    name = "";
    aptNumber = 0;
}

inline int Tenant::getAptNumber() {
    return aptNumber;
}

bool operator<(const Tenant &t1, const Tenant &t2) {
    return t1.aptNumber < t2.aptNumber;
}
bool operator==(const Tenant &t1, const Tenant &t2) {
    return t1.name == t2.name;
}

ostream& operator<<(ostream &stream, const Tenant &t) {
    stream << t.name << "\t" << t.aptNumber << "\n";
}


// CompareTenants

bool CompareTenants::operator()(Tenant *t1, Tenant *t2) const {
    return &t1 < &t2;
}


// Tenant List

TenantList::~TenantList() {
    setPtrsTens.clear();
}

void TenantList::insertTenant(Tenant *t) {
    setPtrsTens.insert(t);
}

int TenantList::getAptNo(string name) {
    auto *tmpTenant = new Tenant(std::move(name), -1);
    iter = setPtrsTens.begin();
    while (iter != setPtrsTens.end()) {
        if (*iter == tmpTenant) {
            return (*iter)->getAptNumber();
        }
    }
    return -1;
}

void TenantList::display() {
    iter = setPtrsTens.begin();
    while (iter != setPtrsTens.end()) {
        cout << *iter;
    }
}


// Tenant Input Screen

void TenantInputScreen::getTenant() {
    cout << "Enter tenant name: ";
    cin >> tName;
    cout << "Enter tenant's apt. no.";
    cin >> aptNo;
    ptrTenantList->insertTenant(new Tenant(tName, aptNo));
}


// Rent Row

RentRow::RentRow(int num) {
    aptNo = num;
}

void RentRow::setRent(int num, float sum) {
    rent[num] = sum;
}

float RentRow::getSumOfRow() {
    float sum = 0.0;
    for (int i = 0; i < 12; ++i) {
        sum += rent[i];
    }
    return sum;
}

bool operator<(const RentRow &r1, const RentRow &r2) {
    
}