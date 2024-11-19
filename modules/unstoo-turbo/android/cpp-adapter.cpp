#include <jni.h>
#include "react-native-unstoo-turbo.h"

extern "C"
JNIEXPORT jdouble JNICALL
Java_com_unstooturbo_UnstooTurboModule_nativeMultiply(JNIEnv *env, jclass type, jdouble a, jdouble b) {
    return unstooturbo::multiply(a, b);
}
