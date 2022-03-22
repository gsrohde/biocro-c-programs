#include "../biocro-dev-pristine/src/framework/module_creator.h"
#include "../biocro-dev-pristine/src/module_library/module_graph_test.hpp" // For Module_3
#include "../example_biocro_module_library/src/module_library/Module_3.h" // For Module_3

void module_info(module_creator*, bool);

void test_module_creator_impl() {
    printf("---------------------Get Module_3 module creator pointer directly---------------------\n\n");
    
    // Get the module_creator pointer using module_creator_impl
    module_creator* mc3 = new module_creator_impl<Module_3>;
    printf("Module_3 mc3 pointer is %p\n", mc3);
    printf("Printing module info:\n\n");
    module_info(mc3, true);

    printf("---------------------Get exampleLibrary::Module_3 module creator pointer directly---------------------\n\n");

    ////////////////////////////////////////////////////////////////////////////////
    // Testing out module_creator_impl
    ////////////////////////////////////////////////////////////////////////////////
    
    // Get the module_creator pointer using module_creator_impl
    module_creator* mc4 = new module_creator_impl<exampleLibrary::Module_3>;
    printf("Module_3 mc4 pointer is %p\n", mc4);
    printf("Printing module info:\n\n");
    module_info(mc4, true);

}
