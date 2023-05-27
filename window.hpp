#ifndef WINDOWMANAGER_HPP
#define WINDOWMANAGER_HPP

#include <memory>
#include <string>

class SubWindow;

class WindowManager {
public:
    void OpenSubWindow(const std::string& name);

private:
    std::shared_ptr<SubWindow> currentSubWindow_;
};

#endif  // WINDOWMANAGER_HPP

