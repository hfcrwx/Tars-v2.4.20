#include "HelloServer.h"
#include "HelloImp.h"

using namespace std;

HelloServer g_app;

/////////////////////////////////////////////////////////////////
void HelloServer::initialize() {
  // initialize application here:

  //添加Servant接口实现类HelloImp与路由Obj绑定关系
  addServant<HelloImp>(ServerConfig::Application + "." +
                       ServerConfig::ServerName + ".HelloObj");
}
/////////////////////////////////////////////////////////////////
void HelloServer::destroyApp() {
  // destroy application here:
  //...
}
/////////////////////////////////////////////////////////////////
int main(int argc, char* argv[]) {
  try {
    g_app.main(argc, argv);
    g_app.waitForShutdown();
  } catch (std::exception& e) {
    cerr << "std::exception:" << e.what() << std::endl;
  } catch (...) {
    cerr << "unknown exception." << std::endl;
  }
  return -1;
}
/////////////////////////////////////////////////////////////////
