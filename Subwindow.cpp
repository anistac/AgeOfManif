#include "Subwindow.hpp"
#include <iostream>

SubWindow::SubWindow(const std::string& name) : name_(name) {}

void SubWindow::Open() {
    std::cout << "Ouverture de la sous-fenêtre : " << name_ << std::endl;
}

void SubWindow::Close() {
    std::cout << "Fermeture de la sous-fenêtre : " << name_ << std::endl;
}



