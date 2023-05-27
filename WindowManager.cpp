#include "WindowManager.hpp"
#include "Subwindow.hpp"

void WindowManager::OpenSubWindow(const std::string& name) {
    if (currentSubWindow_) {
        currentSubWindow_->Close();
    }

    currentSubWindow_ = std::make_shared<SubWindow>(name);
    currentSubWindow_->Open();
}

