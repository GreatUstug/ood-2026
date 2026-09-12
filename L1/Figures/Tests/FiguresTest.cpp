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
	EXPECT_NO_THROW(Circle Circle({1, 0, 0, 0.0}));
}

// TEST(It2, ExecuteParserAndCheckReading)
// {
// 	Picture picture;
// 	testing::internal::CaptureStdout();
//
// 	output = testing::internal::GetCapturedStdout();
// 	EXPECT_EQ(output, "f:20.00\n");
// 	testing::internal::GetCapturedStdout();
// }

TEST(It2, AddShapesWithSameIdToPicture)
{
	Picture picture;
	picture.AddShape({1, "rectangle", "#000001", "#000001", 0, 0, {}});
	EXPECT_THROW(picture.AddShape({1, "rectangle", "#000001", "#000001",0, 0, {}}),std::exception);
}