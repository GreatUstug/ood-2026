#include "DuckConstructBehavior.h"
#include "DuckFunctions.h"
#include <cstdlib>

int main()
{
    Duck mallardDuck = DuckConstruct::Mallard();
    PlayWithDuck(mallardDuck);

    Duck redheadDuck = DuckConstruct::Redhead();
    PlayWithDuck(redheadDuck);

    Duck rubberDuck = DuckConstruct::Rubber();
    PlayWithDuck(rubberDuck);

    Duck decoyDuck = DuckConstruct::Decoy();
    PlayWithDuck(decoyDuck);

    Duck modelDuck = DuckConstruct::Model();
    PlayWithDuck(modelDuck);

    modelDuck.SetFlyBehavior(Fly::WithWings());
    PlayWithDuck(modelDuck);

    return EXIT_SUCCESS;
}