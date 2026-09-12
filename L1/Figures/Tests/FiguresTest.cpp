//
// Created by maxim on 12.09.2026.
//

#include "../ShapesCommandHandler.h"

#include <gtest/gtest.h>

TEST(It1, InitTest)
{
	EXPECT_NO_THROW(CommandHandler::ShapesCommandHandler commandHandler);
}

TEST(It2, StartExecuteOperations)
{
	EXPECT_NO_THROW(CommandHandler::ShapesCommandHandler commandHandler;
		commandHandler.Execute());
}

TEST(It2, ShapeCreate)
{
	EXPECT_NO_THROW(Shape shape("x", "xx", 123, 456, {}));
}