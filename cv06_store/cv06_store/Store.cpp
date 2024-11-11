//
//  Store.cpp
//  CPP_cviceni6_obchod
//
//  Created by David Prochazka on 11/6/12.
//  Copyright (c) 2012 David Prochazka. All rights reserved.
//

#include "Store.h"
#include <chrono>
#include <ctime>
#include <iomanip>
#include "CustomerException.h"


Store::Store() {
    m_activeCustomer = m_customers.end();
}

void Store::addCustomer(const int memberId, const float age,
                        const std::string name, const std::string address) {
    bool noCustomerActive = m_activeCustomer == m_customers.end();
    
    Customer customer {
        .memberId = memberId,
        .age = age,
        .name = name,
        .address = address,
        .vipMember = false
    };
    
    m_customers.push_back(customer);
    
    if (noCustomerActive)
        m_activeCustomer = m_customers.end();
}

void Store::selectActiveCustomer(const int memberId) {
    if (m_activeCustomer != this->m_customers.end())
        throw CustomerException("Zákazník je již aktivní", m_activeCustomer->memberId);
    
    m_activeCustomer = std::find_if(
        this->m_customers.begin(),
        this->m_customers.end(),
        [memberId](const Customer& c) { return c.memberId == memberId; }
    );
    
    if (m_activeCustomer == this->m_customers.end())
        throw std::out_of_range("Zákazník s tímto ID neexistuje.");
}

void Store::addItemToBasket(const float price, const std::string description) {
    // TODO
}

void Store::emptyBasket() {
    // TODO
}

void Store::placeOrder() {
    // TODO
}

void Store::sortCustomersByVipStatus() {
    // TODO
}

void Store::printAllCustomers() const {
    // TODO
}

void Store::printDatesOfNewOrders() {
    // TODO
}


void Store::printBasketInfo() {
    // TODO
}

void Store::setVipStatus() {
    // TODO
}





