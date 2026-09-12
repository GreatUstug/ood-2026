//
// Created by maxim on 12.09.2026.
//

#include "../ShapesCommandHandler.h"

#include <gtest/gtest.h>

TEST(FiguresTest, Test)
{
	EXPECT_EQ(1, 1);
}

TEST(It1, InitTest)
{
	EXPECT_NO_THROW(CommandHandler::ShapesCommandHandler commandHandler);
}