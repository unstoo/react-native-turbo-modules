#include <jni.h>
#include "react-native-unstoo-native.h"

extern "C"
JNIEXPORT jdouble JNICALL
Java_com_unstoonative_UnstooNativeModule_nativeMultiply(JNIEnv *env, jclass type, jdouble a, jdouble b) {
    return unstoonative::multiply(a, b);
}
