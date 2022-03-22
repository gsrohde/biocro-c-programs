#include <stdio.h>
#include <string>
#include "../example_biocro_module_library/src/framework/module_factory.h"
#include "../biocro-dev/src/framework/module_factory.h"

using std::string;

void print_mods(string, string_vector);
void module_info(module_creator*, bool);

void test_module_factory() {
    string name { "Module_3" };

    string_vector mods1 = BioCro::module_factory::get_all_modules();
    print_mods("---------------------First 8 modules in BioCro library---------------------", mods1);

    printf("---------------------Get Module_3 info from BioCro---------------------\n\n");

    // Get the module_creator pointer using retrieve
    module_creator* mc1 = BioCro::module_factory::retrieve(name);
    printf("Module_3 mc1 pointer is %p\n", mc1);
    printf("Printing module info:\n\n");
    module_info(mc1, true);

    string_vector mods2 = exampleLibrary::module_factory::get_all_modules();
    print_mods("---------------------First 8 modules in exampleLibrary library---------------------", mods2);

    printf("---------------------Get Module_3 info from exampleLibrary---------------------\n\n");

    // Get the module_creator pointer using retrieve
    module_creator* mc2 = exampleLibrary::module_factory::retrieve(name);
    printf("Module_3 mc2 pointer is %p\n", mc2);
    printf("Printing module info:\n\n");
    module_info(mc2, true);
}
