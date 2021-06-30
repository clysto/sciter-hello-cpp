#include "sciter-x-window.hpp"
#include "sciter-x.h"

class frame : public sciter::window {
 public:
  frame()
      : window(SW_TITLEBAR | SW_RESIZEABLE | SW_CONTROLS | SW_MAIN |
               SW_ENABLE_DEBUG) {
  }

  // passport - lists native functions and properties exposed to script under
  // 'frame' interface name:
  SOM_PASSPORT_BEGIN(frame)
  SOM_FUNCS(SOM_FUNC(nativeMessage))
  SOM_PASSPORT_END

  // function expsed to script:
  sciter::string nativeMessage() {
    return WSTR("Hello C++ World");
  }
};

#include "resources.cpp"

int uimain(std::function<int()> run) {
  // 加载 resource
  sciter::archive::instance().open(aux::elements_of(resources));
  sciter::om::hasset<frame> pwin = new frame();
  pwin->load(WSTR("this://app/main.htm"));
  pwin->expand();
  return run();
}
