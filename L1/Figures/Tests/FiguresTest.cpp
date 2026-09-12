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

TEST(It2, AddShapesWithSameIdThrows) {
    Picture picture;
    ShapeParams params{ ShapeType::RECTANGLE, "#000001", "#000001", 0, 0, {"10", "20"}};

    picture.AddShape(params);
    EXPECT_THROW(picture.AddShape(params), std::exception);
}

