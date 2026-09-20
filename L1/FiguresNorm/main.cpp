#include "ShapesCommandHandler.h"

int main() {
	shapes::Picture picture;
	CommandHandler::ShapesCommandHandler handler(picture);
	handler.Execute();
	return 0;
}