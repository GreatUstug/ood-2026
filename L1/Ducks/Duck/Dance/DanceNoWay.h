//
// Created by maxim on 06.09.2026.
//

#ifndef DUCKS_DANCENOWAY_H
#define DUCKS_DANCENOWAY_H

class DanceNoWay : public IDanceBehavior {
public:
    void Dance()  override {
        std::cout << "I'm not dancing!" << '\n';
    }
};

#endif //DUCKS_DANCENOWAY_H