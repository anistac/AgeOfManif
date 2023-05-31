#ifndef SUBWINDOW_HPP
#define SUBWINDOW_HPP

#include <string>

class SubWindow {
public:
    SubWindow(const std::string& name);

    void Open();
    void Close();

private:
    std::string name_;
};

#endif  // SUBWINDOW_HPP

