#ifndef MapTest_hpp
#define MapTest_hpp

#include "TestSuite/Test.h"

class MapTest: public TestSuite::Test {
public:
    void run() override;
    
    void testMoveSuccess();
    void testMoveHitBoundary();
private:
};

#endif /* MapTest_hpp */
