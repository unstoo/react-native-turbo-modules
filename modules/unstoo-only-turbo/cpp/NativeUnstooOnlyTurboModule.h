#include <ReactCodegen/RNUnstooOnlyTurboSpecJSI.h>

namespace facebook::react {
class NativeUnstooOnlyTurboModule: public NativeUnstooOnlyTurboCxxSpec<NativeUnstooOnlyTurboModule> {
public:
    NativeUnstooOnlyTurboModule(std::shared_ptr<CallInvoker> jsInvoker);
    
     jsi::String reverseString(jsi::Runtime &rt, jsi::String input);
     jsi::Array getNumbers(jsi::Runtime &rt);
     jsi::Object getObject(jsi::Runtime &rt);
     jsi::Value promiseNumber(jsi::Runtime &rt, double value);
     void callbacks(jsi::Runtime &rt, jsi::Function success, jsi::Function failure);
};
}
