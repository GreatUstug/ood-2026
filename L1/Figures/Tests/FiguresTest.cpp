//
// Created by maxim on 12.09.2026.
//

#include "../ShapesCommandHandler.h"

#include <gtest/gtest.h>

TEST(It1, InitTest)
{
	EXPECT_NO_THROW(CommandHandler::ShapesCommandHandler commandHandler);
}

TEST(It2, AddShapesWithSameIdThrows) {
    Picture picture;
    ShapeParams params{ ShapeType::RECTANGLE, "#000001", "#000001", 0, 0, {"10", "20"}};

    picture.AddShape(params);
    EXPECT_THROW(picture.AddShape(params), std::exception);
}

TEST(ShapeOutputTest, RectangleInfoString)
{
	Picture picture;
	ShapeParams params{ ShapeType::RECTANGLE, "#000001", "#000001", 0, 0, {"10", "20"} };

	ASSERT_NO_THROW(picture.AddShape(params));

	std::string result = picture.ListOneShape("#000001");

	EXPECT_TRUE(result.find("Rectangle") != std::string::npos);
	EXPECT_TRUE(result.find("10") != std::string::npos); // Ширина
	EXPECT_TRUE(result.find("20") != std::string::npos); // Высота
}

TEST(ShapeOutputTest, CircleInfoString)
{
	Picture picture;
	ShapeParams params{ ShapeType::CIRCLE, "c1", "red", 10, 20, {"5.5"} };

	ASSERT_NO_THROW(picture.AddShape(params));

	std::string result = picture.ListOneShape("c1");
	EXPECT_TRUE(result.find("Circle") != std::string::npos);
	EXPECT_TRUE(result.find("5.5") != std::string::npos);
}

TEST(ShapeOutputTest, LineInfoString)
{
	Picture picture;
	ShapeParams params{ ShapeType::LINE, "l1", "black", 0, 0, {"100", "100"} };

	ASSERT_NO_THROW(picture.AddShape(params));

	std::string result = picture.ListOneShape("l1");
	EXPECT_TRUE(result.find("Line") != std::string::npos);
	EXPECT_TRUE(result.find("100") != std::string::npos);
}

TEST(ShapeOutputTest, TextInfoString)
{
	Picture picture;
	ShapeParams params{ ShapeType::TEXT, "tx1", "white", 50, 50, {"14", "Hello"} };

	ASSERT_NO_THROW(picture.AddShape(params));

	std::string result = picture.ListOneShape("tx1");
	EXPECT_TRUE(result.find("Text") != std::string::npos);
	EXPECT_TRUE(result.find("Hello") != std::string::npos);
}

TEST(ShapeOutputTest, TriangleInfoString)
{
	Picture picture;
	ShapeParams params{ ShapeType::TRIANGLE, "t1", "green", 0, 0, {"10", "0", "5", "10"} };

	ASSERT_NO_THROW(picture.AddShape(params));

	std::string result = picture.ListOneShape("t1");

	EXPECT_TRUE(result.find("Triangle") != std::string::npos);
	EXPECT_TRUE(result.find("10") != std::string::npos);
	EXPECT_TRUE(result.find("5") != std::string::npos);
}

TEST(It3, ChangeColor)
{
	Picture picture;
	ShapeParams params{ ShapeType::TRIANGLE, "t1", "green", 0, 0, {"10", "0", "5", "10"} };

	ASSERT_NO_THROW(picture.AddShape(params));
	picture.EditShapeColor("t1", "red");
	std::string result = picture.ListOneShape("t1");

	EXPECT_TRUE(result.find("red") != std::string::npos);
}

TEST(It3, DeleteObject)
{
	Picture picture;
	ShapeParams params{ ShapeType::TRIANGLE, "t1", "green", 0, 0, {"10", "0", "5", "10"} };

	picture.AddShape(params);
	EXPECT_NO_THROW(picture.DeleteShape("t1"));
	EXPECT_THROW(picture.DeleteShape("t1"), std::exception);
}

TEST(It3, MoveObject)
{
	Picture picture;
	ShapeParams params{ ShapeType::TRIANGLE, "t1", "green", 0, 0, {"10", "0", "5", "10"} };

	picture.AddShape(params);
	picture.MoveShape("t1", 2, 2);
	std::string result = picture.ListOneShape("t1");
	EXPECT_TRUE(result.find("2") != std::string::npos);
}

TEST(It3, MoveObjects)
{
	Picture picture;
	ShapeParams params{ ShapeType::TRIANGLE, "t1", "green", 0, 0, {"10", "0", "5", "10"} };
	ShapeParams params1{ ShapeType::TRIANGLE, "t2", "green", 3, 3, {"10", "0", "5", "10"} };

	picture.AddShape(params);
	picture.AddShape(params1);
	picture.MovePicture(2, 2);
	std::string result = picture.ListOneShape("t2");
	EXPECT_TRUE(result.find("5") != std::string::npos);
}
