#include "Server.hpp"

// void print_error(const std::string& message) {
//     std::cerr << message << ": " << strerror(errno) << std::endl;
// }

int main(int ac, char **av) {
    if (ac == 2)
    {
        try {
            Server server(av[1]);
            std::cout << "Serveur démarré sur le port " << PORT << std::endl;
            server.loop();
        } catch (const std::exception& e) {
            std::cerr << "Erreur : " << e.what() << std::endl;
            return 1;
        }
    } else { 
        return std::cerr << "Erreur : Un seul argument a passer (mot de passe serveur)" << std::endl, 1;
    }
    return 0;
}
