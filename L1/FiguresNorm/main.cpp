#include "ShapesCommandHandler.h"

int main() {
	Picture picture;
	CommandHandler::ShapesCommandHandler handler(picture);
	handler.Execute();
	return 0;
}