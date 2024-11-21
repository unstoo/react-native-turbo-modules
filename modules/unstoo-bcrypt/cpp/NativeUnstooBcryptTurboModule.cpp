#include "NativeUnstooBcryptTurboModule.h"
#include <thread>

namespace facebook::react
{
    NativeUnstooBcryptTurboModule::NativeUnstooBcryptTurboModule(std::shared_ptr<CallInvoker> jsinvoker) : NativeUnstooBcryptCxxSpec<NativeUnstooBcryptTurboModule>(std::move(jsinvoker)) {}

    jsi::Value NativeUnstooBcryptTurboModule::generateHash(jsi::Runtime& rt, std::string password, double workload)
    {
        jsi::Function promiseConstructor = rt.global().getPropertyAsFunction(rt, "Promise");

        return promiseConstructor.callAsConstructor(rt,
            jsi::Function::createFromHostFunction(
                rt,
                jsi::PropNameID::forAscii(rt, "promiseArg"),
                2,
                [password, workload, jsInvoker = jsInvoker_](
                    jsi::Runtime& runtime,
                    const jsi::Value& thisValue,
                    const jsi::Value* arguments,
                    std::size_t count) -> jsi::Value
                {
                    auto resolverValue = std::make_shared<jsi::Value>((arguments[0].asObject(runtime)));

                    std::thread([password, workload, resolverValue = std::move(resolverValue), jsInvoker, &runtime]()
                        {
                            std::string hash = bcrypt::generateHash(password, workload);
                            // Post back to JS thread
                            jsInvoker->invokeAsync([resolverValue, hash, &runtime]() {
                                resolverValue->asObject(runtime).asFunction(runtime).call(runtime, hash);
                                }); })
                        .detach();
                    return jsi::Value::undefined();
                })

        );
    }

    jsi::Value NativeUnstooBcryptTurboModule::validatePassword(jsi::Runtime& rt, std::string password, std::string hash)
    {
        jsi::Function promiseConstructor = rt.global().getPropertyAsFunction(rt, "Promise");

        return promiseConstructor.callAsConstructor(rt,
            jsi::Function::createFromHostFunction(
                rt,
                jsi::PropNameID::forAscii(rt, "promiseArg"),
                2,
                [password, hash, jsInvoker = jsInvoker_](
                    jsi::Runtime& runtime,
                    const jsi::Value& thisValue,
                    const jsi::Value* arguments,
                    std::size_t count) -> jsi::Value
                {
                    auto resolverValue = std::make_shared<jsi::Value>((arguments[0].asObject(runtime)));

                    std::thread([password, hash, resolverValue = std::move(resolverValue), jsInvoker, &runtime]()
                        {
                            bool isValid = bcrypt::validatePassword(password, hash);
                            // Post back to JS thread
                            jsInvoker->invokeAsync([resolverValue, isValid, &runtime]() {
                                resolverValue->asObject(runtime).asFunction(runtime).call(runtime, isValid);
                                }); })
                        .detach();
                    return jsi::Value::undefined();
                })

        );
    }
    std::string NativeUnstooBcryptTurboModule::generateHashSync(jsi::Runtime& rt, std::string password, double workload)
    {
        return bcrypt::generateHash(password, workload);
    }
    bool NativeUnstooBcryptTurboModule::validatePasswordSync(jsi::Runtime& rt, std::string password, std::string hash)
    {
        return bcrypt::validatePassword(password, hash);
    }

}
