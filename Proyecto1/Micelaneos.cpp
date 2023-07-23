#include "Micelaneos.h"

bool Micelaneos::contieneLetras(const std::string& str) {
    for (char c : str) {
        if (std::isalpha(c)) {
            return true; // Found a letter
        }
    }
    return false; // No letters found
}