#include "StoreTest.hpp"
#include "Store.h"
#include "CustomerException.h"

void StoreTest::run() {
    testAlreadyActiveException();
    testNoExistsException();
}

void StoreTest::testNoExistsException() {
    auto* store = new Store();
    try {
        store->selectActiveCustomer(8);
    } catch (std::out_of_range& e) {
        test_(true);
        return;
    } catch (...) {
        fail_("Unexpected exception.");
        return;
    }
    delete store;
    fail_("Exception std::out_of_range not thrown.");
}

void StoreTest::testAlreadyActiveException() {
    auto* store = new Store();
    store->addCustomer(1, 25, "Jarda", "Brno");
    store->selectActiveCustomer(1);
    try {
        store->selectActiveCustomer(2);
    } catch (CustomerException& e) {
        test_(true);
        return;
    } catch (...) {
        fail_("Unexpected exception.");
        return;
    }
    delete store;
    fail_("Exception CustomerException not thrown");
}

