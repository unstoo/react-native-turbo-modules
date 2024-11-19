#include <jni.h>
#include "react-native-unstoo-only-turbo.h"

extern "C"
JNIEXPORT jdouble JNICALL
Java_com_unstooonlyturbo_UnstooOnlyTurboModule_nativeMultiply(JNIEnv *env, jclass type, jdouble a, jdouble b) {
    return unstooonlyturbo::multiply(a, b);
}
