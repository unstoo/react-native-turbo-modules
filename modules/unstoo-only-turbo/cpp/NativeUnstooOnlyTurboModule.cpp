#include "NativeUnstooOnlyTurboModule.h"

namespace facebook::react {
    NativeUnstooOnlyTurboModule::NativeUnstooOnlyTurboModule(std::shared_ptr<CallInvoker> jsinvoker)
        : NativeUnstooOnlyTurboCxxSpec(std::move(jsinvoker)) {
    }

    jsi::String NativeUnstooOnlyTurboModule::reverseString(jsi::Runtime& rt, jsi::String input) {
        std::string stdStr = input.utf8(rt);
        std::reverse(stdStr.begin(), stdStr.end());
        return jsi::String::createFromUtf8(rt, stdStr);
    }

    jsi::Array NativeUnstooOnlyTurboModule::getNumbers(jsi::Runtime& rt) {
        jsi::Array numbers = jsi::Array(rt, 10);
        for (std::size_t i = 0; i < 10; i++) {
            numbers.setValueAtIndex(rt, i, jsi::Value(static_cast<int>(i)));
        }
        return numbers;
    }
    jsi::Object NativeUnstooOnlyTurboModule::getObject(jsi::Runtime& rt) {
        jsi::Object obj = jsi::Object(rt);
        obj.setProperty(rt, "name", jsi::String::createFromUtf8(rt, "John"));
        return obj;
    }

    jsi::Value NativeUnstooOnlyTurboModule::promiseNumber(jsi::Runtime& rt, double number) {
        jsi::Function promiseConstructor = rt.global().getPropertyAsFunction(rt, "Promise");
        return promiseConstructor.callAsConstructor(rt,
            jsi::Function::createFromHostFunction(rt,
                jsi::PropNameID::forAscii(rt, "promiseArg"),
                2,
                [number](
                    jsi::Runtime& runtime,
                    const jsi::Value& thisValue,
                    const jsi::Value* arguments,
                    std::size_t count
                    ) -> jsi::Value {
                        jsi::Function resolve = arguments[0].asObject(runtime).asFunction(runtime);
                        resolve.call(runtime, number);
                        return jsi::Value::undefined();
                }
            )
        );
    }

    void NativeUnstooOnlyTurboModule::callbacks(jsi::Runtime& rt, jsi::Function success, jsi::Function failure) {
        bool callSuccess = std::rand() % 2 == 0;
        if (callSuccess) {
            success.call(rt);
        }
        else {
            failure.call(rt);
        }
    }
}
