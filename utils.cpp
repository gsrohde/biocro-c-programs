#include "../biocro-dev-pristine/src/framework/module_creator.h"
#include "../biocro-dev-pristine/src/framework/module_helper_functions.h"
#include "../biocro-dev-pristine/src/framework/state_map.h"

using std::string;
using std::vector;

void print_mods(string heading, string_vector mods) {
    printf("%s\n\n", heading.c_str());
    int i {0};
    for (string &mod : mods) {
        printf("%s\n", mod.c_str());
        if (++i >= 8) break;
    }
    printf("\n");
}




void module_info(module_creator* w, bool verbose)
{
    try {
        // Get the module's name
        string module_name = w->get_name();

        // Make maps for the module's inputs and outputs
        state_map module_inputs;
        state_map module_outputs;

        // Get the module's inputs and give them default values
        double const default_value = 1.0;
        vector<string> inputs = w->get_inputs();
        for (string param : inputs) {
            module_inputs[param] = default_value;
        }

        // Get the module's outputs and give them default values
        vector<string> outputs = w->get_outputs();
        for (string param : outputs) {
            module_outputs[param] = default_value;
        }

        // Try to create an instance of the module
        bool create_success = true;
        bool is_differential = false;
        bool requires_euler_ode_solver = false;
        string creation_error_message = "none";
        try {
            std::unique_ptr<module> module_ptr = w->create_module(
                module_inputs,
                &module_outputs);

            // Check to see if the module is a differential module
            is_differential = module_ptr->is_differential();

            // Check to see if the module requires an Euler ode_solver
            requires_euler_ode_solver = module_ptr->requires_euler_ode_solver();
        } catch (std::exception const& e) {
            create_success = false;
            creation_error_message = e.what();
        }

        // Send some messages to the user if required
        if (verbose) {
            // Module name
            printf("\n\nModule name:\n  %s\n\n", module_name.c_str());

            // Module inputs
            printf("Module input quantities:");
            if (inputs.size() == 0)
                printf(" none\n\n");
            else {
                for (string param : inputs) {
                    printf("\n  %s", param.c_str());
                }
                printf("\n\n");
            }

            // Module outputs
            printf("Module output quantities:");
            if (outputs.size() == 0)
                printf(" none\n\n");
            else {
                for (string param : outputs) {
                    printf("\n  %s", param.c_str());
                }
                printf("\n\n");
            }

            if (create_success) {
                // Module type
                printf("Module type (differential or direct):\n  ");
                if (is_differential)
                    printf("differential\n\n");
                else
                    printf("direct\n\n");

                // Euler requirement
                printf("Requires a fixed step size Euler ode_solver:\n  ");
                if (requires_euler_ode_solver)
                    printf("yes\n\n");
                else
                    printf("no\n\n");
            } else {
                printf("Error: could not create the module\n");
                printf("Additional details:\n");
                printf(creation_error_message.c_str());
                printf("\n\n");
            }
        }

        return;

    } catch (quantity_access_error const& qae) {
        printf((string("Caught quantity access error in R_module_info: ") + qae.what()).c_str());
    } catch (std::exception const& e) {
        printf((string("Caught exception in R_module_info: ") + e.what()).c_str());
    } catch (...) {
        printf("Caught unhandled exception in R_module_info.");
    }
}
