#ifndef MapTest_hpp
#define MapTest_hpp

#include "TestSuite/Test.h"

class StoreTest: public TestSuite::Test {
public:
    void run() override;
    void testAlreadyActiveException();
    void testNoExistsException();
private:
};

#endif /* MapTest_hpp */
