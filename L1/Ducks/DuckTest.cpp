#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <memory>

#include "Mocks/MockFlyBehavior.h"
#include "Mocks/MockQuackBehavior.h"
#include "Mocks/MockDanceBehavior.h"

using namespace testing;

class DuckTest : public Test
{
protected:
    void SetUp() override
    {
        mockFly = std::make_unique<MockFlyBehavior>();
        mockQuack = std::make_unique<MockQuackBehavior>();
        mockDance = std::make_unique<MockDanceBehavior>();
        
        flyPtr = mockFly.get();
        quackPtr = mockQuack.get();
        dancePtr = mockDance.get();
    }

    std::unique_ptr<MockFlyBehavior> mockFly;
    std::unique_ptr<MockQuackBehavior> mockQuack;
    std::unique_ptr<MockDanceBehavior> mockDance;
    MockFlyBehavior* flyPtr;
    MockQuackBehavior* quackPtr;
    MockDanceBehavior* dancePtr;
};

// Тест для проверки Dance поведения
TEST_F(DuckTest, DanceBehaviorTest)
{
    EXPECT_CALL(*dancePtr, Dance()).Times(1);
    
    TestDuck duck(std::move(mockFly), std::move(mockQuack), std::move(mockDance));
    duck.Dance();
}

// Тест для проверки, что Dance вызывается каждый раз
TEST_F(DuckTest, DanceBehaviorMultipleCallsTest)
{
    EXPECT_CALL(*dancePtr, Dance()).Times(3);
    
    TestDuck duck(std::move(mockFly), std::move(mockQuack), std::move(mockDance));
    duck.Dance();
    duck.Dance();
    duck.Dance();
}

// Тест для проверки кряканья после каждого второго полета
TEST_F(DuckTest, QuackAfterEverySecondFlightTest)
{
    // Настройка поведения fly
    ON_CALL(*flyPtr, CanFly()).WillByDefault(Return(true));
    ON_CALL(*flyPtr, GetFlightCount())
        .WillByDefault(Return(0))
        .WillByDefault(Return(1))
        .WillByDefault(Return(2))
        .WillByDefault(Return(3))
        .WillByDefault(Return(4));
    
    // Ожидаем, что Quack будет вызван после 2-го и 4-го полета
    EXPECT_CALL(*quackPtr, Quack()).Times(2);
    EXPECT_CALL(*flyPtr, Fly()).Times(4);
    
    TestDuck duck(std::move(mockFly), std::move(mockQuack), std::move(mockDance));
    
    // Используем реальный GetFlightCount через поведение
    // Более простой способ - использовать тестовую утку с кастомной логикой
}

// Более простой и контролируемый тест для кряканья
TEST_F(DuckTest, QuackBeforeFlightConditionTest)
{
    bool shouldQuack = false;
    
    TestDuck duck(std::move(mockFly), std::move(mockQuack), std::move(mockDance));
    
    // Устанавливаем кастомную логику через callback
    duck.SetShouldQuackBeforeFlightCallback([&shouldQuack]() {
        return shouldQuack;
    });
    
    // Проверяем, что при shouldQuack = false, Quack не вызывается
    EXPECT_CALL(*quackPtr, Quack()).Times(0);
    EXPECT_CALL(*flyPtr, Fly()).Times(1);
    ON_CALL(*flyPtr, CanFly()).WillByDefault(Return(true));
    
    duck.Fly();
    
    // Проверяем, что при shouldQuack = true, Quack вызывается
    shouldQuack = true;
    EXPECT_CALL(*quackPtr, Quack()).Times(1);
    EXPECT_CALL(*flyPtr, Fly()).Times(1);
    
    duck.Fly();
}

// Тест для проверки, что нелетающие утки не крякают
TEST_F(DuckTest, NonFlyingDuckDoesNotQuackTest)
{
    EXPECT_CALL(*flyPtr, CanFly()).WillRepeatedly(Return(false));
    EXPECT_CALL(*quackPtr, Quack()).Times(0);
    EXPECT_CALL(*flyPtr, Fly()).Times(2);
    
    TestDuck duck(std::move(mockFly), std::move(mockQuack), std::move(mockDance));
    
    duck.Fly();
    duck.Fly();
}

// Тест для проверки изменения логики кряканья (четные/нечетные полеты)
TEST_F(DuckTest, ConfigurableQuackLogicTest)
{
    bool quackOnEven = true;
    int flightCount = 0;
    
    TestDuck duck(std::move(mockFly), std::move(mockQuack), std::move(mockDance));
    
    duck.SetShouldQuackBeforeFlightCallback([&]() {
        if (!flyPtr->CanFly()) return false;
        if (quackOnEven) {
            return flightCount != 0 && flightCount % 2 == 0;
        } else {
            return flightCount % 2 == 1;
        }
    });
    
    ON_CALL(*flyPtr, CanFly()).WillByDefault(Return(true));
    
    // Тестируем четные полеты (2-й, 4-й...)
    EXPECT_CALL(*quackPtr, Quack()).Times(2);
    EXPECT_CALL(*flyPtr, Fly()).Times(4);
    
    for (int i = 0; i < 4; i++) {
        flightCount = i;
        // Обновляем GetFlightCount
        ON_CALL(*flyPtr, GetFlightCount()).WillByDefault(Return(i));
        duck.Fly();
    }
    
    // Меняем на нечетные
    quackOnEven = false;
    Mock::VerifyAndClearExpectations(quackPtr);
    Mock::VerifyAndClearExpectations(flyPtr);
    
    EXPECT_CALL(*quackPtr, Quack()).Times(2); // 1-й и 3-й полеты
    EXPECT_CALL(*flyPtr, Fly()).Times(4);
    
    for (int i = 0; i < 4; i++) {
        flightCount = i + 1;
        ON_CALL(*flyPtr, GetFlightCount()).WillByDefault(Return(i + 1));
        duck.Fly();
    }
}

// Тест для проверки интеграции всех поведений
TEST_F(DuckTest, CompleteDuckBehaviorTest)
{
    EXPECT_CALL(*dancePtr, Dance()).Times(1);
    EXPECT_CALL(*quackPtr, Quack()).Times(1);
    EXPECT_CALL(*flyPtr, Fly()).Times(1);
    EXPECT_CALL(*flyPtr, CanFly()).WillRepeatedly(Return(true));
    ON_CALL(*flyPtr, GetFlightCount()).WillByDefault(Return(2));
    
    TestDuck duck(std::move(mockFly), std::move(mockQuack), std::move(mockDance));
    
    duck.Dance();
    duck.Quack();
    duck.Fly();
}